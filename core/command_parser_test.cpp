#include <string>
#include <stdexcept>

#include "../include/catch.hpp"
#include "command_parser.h"

TEST_CASE( "splits on ':'" ) {
    const char *command = "some:thing";

    core::CommandParser parser(strdup(command));

    REQUIRE( parser.next() == "some" );
    REQUIRE( parser.next() == "thing" );
}

TEST_CASE( "throws exception if no match" ) {
    const char *command = "";

    core::CommandParser parser(strdup(command));

    REQUIRE_THROWS_AS( parser.next(), std::invalid_argument );
}

TEST_CASE( "throws exception if incomplete" ) {
    const char *command = "some:";

    core::CommandParser parser(strdup(command));

    REQUIRE( parser.next() == "some" );
    REQUIRE_THROWS_AS( parser.next(), std::invalid_argument );
}

TEST_CASE( "matches complex expressions" ) {
    const char *command = "some:thing(a, b, c):else";

    core::CommandParser parser(strdup(command));

    REQUIRE( parser.next() == "some" );
    REQUIRE( parser.next() == "thing(a, b, c)" );
    REQUIRE( parser.next() == "else" );
}
