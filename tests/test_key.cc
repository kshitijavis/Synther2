#include <catch2/catch_test_macros.hpp>

#include "logic/key.h"

using synther::logic::Accidental;
using synther::logic::Note;
using synther::logic::NoteLetter;
using synther::logic::Key;
using synther::logic::KeyColor;

TEST_CASE("Test key color set correctly", "[constructor][keycolor]") {
  SECTION("Simple White keys") {
    Key key(Note(-1, NoteLetter::C, Accidental::Natural));
    REQUIRE(key.GetKeyColor() == KeyColor::White);

    Key key1(Note(4, NoteLetter::A, Accidental::Natural));
    REQUIRE(key1.GetKeyColor() == KeyColor::White);
  }

  SECTION("Simple black keys") {
    Key key(Note(-1, NoteLetter::C, Accidental::Sharp));
    REQUIRE(key.GetKeyColor() == KeyColor::Black);

    Key key1(Note(4, NoteLetter::A, Accidental::Sharp));
    REQUIRE(key1.GetKeyColor() == KeyColor::Black);

    Key key2(Note(4, NoteLetter::A, Accidental::Flat));
    REQUIRE(key2.GetKeyColor() == KeyColor::Black);

    Key key3(Note(4, NoteLetter::B, Accidental::Flat));
    REQUIRE(key3.GetKeyColor() == KeyColor::Black);
  }

  SECTION("White key edge cases") {
    Key key(Note(5, NoteLetter::C, Accidental::Flat));
    REQUIRE(key.GetKeyColor() == KeyColor::White);

    Key key1(Note(4, NoteLetter::B, Accidental::Sharp));
    REQUIRE(key1.GetKeyColor() == KeyColor::White);

    Key key2(Note(8, NoteLetter::E, Accidental::Sharp));
    REQUIRE(key2.GetKeyColor() == KeyColor::White);

    Key key3(Note(3, NoteLetter::F, Accidental::Flat));
    REQUIRE(key3.GetKeyColor() == KeyColor::White);
  }
}