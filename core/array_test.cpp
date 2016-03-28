#include <stdexcept>

#include "../include/catch.hpp"
#include "array.h"

TEST_CASE( "returns correct size" ) {
    core::Array<int> numbers(10);

    REQUIRE( numbers.size() == 10 );
}

TEST_CASE( "copies array" ) {
    core::Array<int> numbers(4);
    for (unsigned i = 0; i < 4; i++) {
        numbers[i] = 2 * i + 2;
    }

    core::Array<int> copied(numbers);
    REQUIRE( copied.size() == 4);
    for (unsigned i = 0; i < 4; i++) {
        REQUIRE( copied[i] == (2 * i + 2));
    }
}

TEST_CASE( "moves array" ) {
    auto producer = []() -> core::Array<int> {
        core::Array<int> numbers(4);
        for (unsigned i = 0; i < 4; i++) {
            numbers[i] = 2 * i + 2;
        }
        return numbers;
    };

    core::Array<int> copied(producer());
    REQUIRE( copied.size() == 4);
    for (unsigned i = 0; i < 4; i++) {
        REQUIRE( copied[i] == (2 * i + 2));
    }
}
