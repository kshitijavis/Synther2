#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "note.h"

using synther::logic::Note;

TEST_CASE("Constrcutor correctly sets midi index", "[constructor]") {
  int midi_index = GENERATE(-5, -1, 1, 5);
  Note note(midi_index);
  REQUIRE(note.GetMidiIndex() == midi_index);
}

TEST_CASE("Get Octave returns the correct octave", "[constructor][getoctave]") {
  SECTION("Midi index 0 is C_-1") {
    Note note(0);
    REQUIRE(note.GetOctave() == -1);
  }

  SECTION("Midi index 1 is C#_-1") {
    Note note(1);
    REQUIRE(note.GetOctave() == -1);
  }

  SECTION("Midi index 5 is A_-1") {
    Note note(5);
    REQUIRE(note.GetOctave() == -1);
  }

  SECTION("Midi index 11 is B_-1") {
    Note note(11);
    REQUIRE(note.GetOctave() == -1);
  }

  SECTION("Midi index 12 is C0") {
    Note note(12);
    REQUIRE(note.GetOctave() == 0);
  }

  SECTION("Midi index 21 is A0") {
    Note note(21);
    REQUIRE(note.GetOctave() == 0);
  }

  SECTION("Midi index 30 is G#1") {
    Note note(30);
    REQUIRE(note.GetOctave() == 1);
  }

  SECTION("Midi index 41 is F2") {
    Note note(41);
    REQUIRE(note.GetOctave() == 2);
  }

  SECTION("Midi index 108 is C8") {
    Note note(108);
    REQUIRE(note.GetOctave() == 8);
  }

  SECTION("Midi index 127 is G9") {
    Note note(127);
    REQUIRE(note.GetOctave() == 9);
  }
}