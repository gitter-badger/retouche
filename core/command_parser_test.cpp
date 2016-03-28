#include <string>
#include <cstring>
#include <stdexcept>

#include "../include/catch.hpp"
#include "command_parser.h"

char* command(const char *text) {
    char *cmd = new char[strlen(text)];
    strcpy(cmd, text);
    return cmd;
}

TEST_CASE( "throws exception if nullptr" ) {
    core::CommandParser parser(nullptr);

    REQUIRE_THROWS_AS( parser.next(), std::invalid_argument );
}

TEST_CASE( "splits on ':'" ) {
    core::CommandParser parser(command("some:thing"));

    REQUIRE( parser.next() == "some" );
    REQUIRE( parser.next() == "thing" );
}

TEST_CASE( "throws exception if no match" ) {
    core::CommandParser parser(command(""));

    REQUIRE_THROWS_AS( parser.next(), std::invalid_argument );
}

TEST_CASE( "throws exception if incomplete" ) {
    core::CommandParser parser(command("some:"));

    REQUIRE( parser.next() == "some" );
    REQUIRE_THROWS_AS( parser.next(), std::invalid_argument );
}

TEST_CASE( "matches complex expressions" ) {
    core::CommandParser parser(command("some:thing(a, b, c):else"));

    REQUIRE( parser.next() == "some" );
    REQUIRE( parser.next() == "thing(a, b, c)" );
    REQUIRE( parser.next() == "else" );
}
