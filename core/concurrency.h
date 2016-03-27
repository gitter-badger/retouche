#ifndef CORE_CONCURRENCY_H
#define CORE_CONCURRENCY_H

#include <thread>

namespace core {

// Computes the branches of a for-loop in parallel.
template<typename F>
void parallelFor(int start, int end, int step, F operation) {
    // Dedicate a pool of size equal to the number of processors.
    unsigned poolSize = std::thread::hardware_concurrency();
    std::thread *pool = new std::thread[poolSize];

    // Split the range into pool size number of buckets.
    unsigned groupSize = (end - start) / step / poolSize;
    for (int i = start; i < poolSize; i += step) {
        int localStart = i * groupSize;
        int localEnd = localStart + groupSize;
        if (i == poolSize - 1) {
            localEnd = end;
        }

        // Start a computation for the specific for-loop branch.
        pool[i] = std::thread([&operation](int start, int end) -> void {
            for (int x = start; x < end; x++) {
                operation(x);
            }
        }, localStart, localEnd);
    }

    // Await all computations to finish.
    for (unsigned i = 0; i < poolSize; i++) {
        pool[i].join();
    }
}

// Computes the branches of a for-loop in parallel.
template<typename F>
void parallelFor(int start, int end, F operation) {
    parallelFor(start, end, 1, operation);
}
}

#endif
