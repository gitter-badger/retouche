#ifndef CONCURRENCY_H
#define CONCURRENCY_H

template<typename F>
void parallelFor(int start, int end, int step, F operation) {
    unsigned poolSize = std::thread::hardware_concurrency();
    std::thread *pool = new std::thread[poolSize];

    unsigned pieceWidth = (end - start) / step / poolSize;
    for (int i = start; i < poolSize; i += step) {
        int localStart = i * pieceWidth;
        int localEnd = localStart + pieceWidth;
        if (i == poolSize - 1) {
            localEnd = end;
        }

        pool[i] = std::thread([&operation](int start, int end) -> void {
            for (int x = start; x < end; x++) {
                operation(x);
            }
        }, localStart, localEnd);
    }

    for (unsigned i = 0; i < poolSize; i++) {
        pool[i].join();
    }
}

#endif
