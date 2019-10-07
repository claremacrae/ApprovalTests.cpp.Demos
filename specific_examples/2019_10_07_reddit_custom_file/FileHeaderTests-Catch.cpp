#include "Catch.hpp"
#include "FakeCustomFile.h"

// Initial test  code from
// https://old.reddit.com/r/cpp_questions/comments/de5ojy/how_should_i_perform_a_setup_in_catch2/
TEST_CASE( "header fields are correct - pure catch", "[header]" ){
    custom_file big_file{"filename"};
    REQUIRE(big_file.size() == "100MB");

    SECTION("header1 should be 42") {
        REQUIRE(big_file.header1 == 42);
    }

    SECTION("header2 should be FOO") {
        REQUIRE(big_file.header2 == "FOO");
    }
}
