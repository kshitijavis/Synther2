#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "logic/note.h"

using synther::logic::Accidental;
using synther::logic::NoteLetter;
using synther::logic::Note;

TEST_CASE(
    "Midi index constrcutor correctly generates octave numbers",
    "[constructor][octave]") {
  SECTION("Midi index 0 is C_-1") {
    Note note(0, Accidental::Sharp);
    REQUIRE(note.GetOctave() == -1);
    REQUIRE(note.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 1 is C#_-1") {
    Note note(1, Accidental::Sharp);
    REQUIRE(note.GetOctave() == -1);
    REQUIRE(note.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note.GetAccidental() == Accidental::Sharp);
  }

  SECTION("Midi index 5 is A_-1") {
    Note note(5, Accidental::Sharp);
    REQUIRE(note.GetOctave() == -1);
    REQUIRE(note.GetNoteLetter() == NoteLetter::F);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 11 is B_-1") {
    Note note(11, Accidental::Sharp);
    REQUIRE(note.GetOctave() == -1);
    REQUIRE(note.GetNoteLetter() == NoteLetter::B);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 12 is C0") {
    Note note(12, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 0);
    REQUIRE(note.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 21 is A0") {
    Note note(21, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 0);
    REQUIRE(note.GetNoteLetter() == NoteLetter::A);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 30 is F#1") {
    Note note(30, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 1);
    REQUIRE(note.GetNoteLetter() == NoteLetter::F);
    REQUIRE(note.GetAccidental() == Accidental::Sharp);
  }

  SECTION("Midi index 41 is F2") {
    Note note(41, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 2);
    REQUIRE(note.GetNoteLetter() == NoteLetter::F);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 108 is C8") {
    Note note(108, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 8);
    REQUIRE(note.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 127 is G9") {
    Note note(127, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 9);
    REQUIRE(note.GetNoteLetter() == NoteLetter::G);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }
}