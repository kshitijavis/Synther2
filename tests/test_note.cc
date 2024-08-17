#include <catch2/catch_test_macros.hpp>

#include "logic/note.h"

#include <iostream>
using synther::logic::Accidental;
using synther::logic::Note;
using synther::logic::NoteLetter;


TEST_CASE("Midi index constrcutor correctly generates octave numbers",
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

  SECTION("Midi index 5 is F_-1") {
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

TEST_CASE("Midi index constrcutor correctly generates note letters",
          "[constructor][noteletter]") {
  SECTION("Midi index 60 is C4") {
    Note note(60, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 61 is C#4") {
    Note note(61, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note.GetAccidental() == Accidental::Sharp);
  }

  SECTION("Midi index 62 is D4") {
    Note note(62, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::D);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 63 is D#4") {
    Note note(63, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::D);
    REQUIRE(note.GetAccidental() == Accidental::Sharp);
  }

  SECTION("Midi index 64 is E4") {
    Note note(64, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::E);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 65 is E4") {
    Note note(65, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::F);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 66 is F#4") {
    Note note(66, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::F);
    REQUIRE(note.GetAccidental() == Accidental::Sharp);
  }

  SECTION("Midi index 67 is G4") {
    Note note(67, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::G);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 68 is G#4") {
    Note note(68, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::G);
    REQUIRE(note.GetAccidental() == Accidental::Sharp);
  }

  SECTION("Midi index 69 is A") {
    Note note(69, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::A);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }

  SECTION("Midi index 70 is A#4") {
    Note note(70, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::A);
    REQUIRE(note.GetAccidental() == Accidental::Sharp);
  }

  SECTION("Midi index 71 is B4") {
    Note note(71, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 4);
    REQUIRE(note.GetNoteLetter() == NoteLetter::B);
    REQUIRE(note.GetAccidental() == Accidental::Natural);
  }
}

TEST_CASE("Midi index constrcutor correctly generates accidentals",
          "[constructor][accidental]") {
  SECTION("If note is natural, priority is ignored") {
    Note note(72, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 5);
    REQUIRE(note.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note.GetAccidental() == Accidental::Natural);

    Note note2(72, Accidental::Natural);
    REQUIRE(note2.GetOctave() == 5);
    REQUIRE(note2.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note2.GetAccidental() == Accidental::Natural);

    Note note3(72, Accidental::Flat);
    REQUIRE(note3.GetOctave() == 5);
    REQUIRE(note3.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note3.GetAccidental() == Accidental::Natural);
  }

  SECTION("If note has accidental, can take flat and sharp form") {
    Note note(97, Accidental::Sharp);
    REQUIRE(note.GetOctave() == 7);
    REQUIRE(note.GetNoteLetter() == NoteLetter::C);
    REQUIRE(note.GetAccidental() == Accidental::Sharp);

    Note note2(97, Accidental::Flat);
    REQUIRE(note2.GetOctave() == 7);
    REQUIRE(note2.GetNoteLetter() == NoteLetter::D);
    REQUIRE(note2.GetAccidental() == Accidental::Flat);
  }

  SECTION("If note has accidental, but Natural priority provided, throw exception") {
    REQUIRE_THROWS(Note(97, Accidental::Natural));
  }
}

TEST_CASE("English Name constructor correctly computes midi index", "[constructor]") {
  SECTION("Midi index 0 is C_-1") {
    Note note(-1, NoteLetter::C, Accidental::Natural);
    REQUIRE(note.GetMidiIndex() == 0);
  }

  SECTION("Midi index 1 is C#_-1") {
    Note note(-1, NoteLetter::C, Accidental::Sharp);
    REQUIRE(note.GetMidiIndex() == 1);
  }

  SECTION("Midi index 5 is A_-1") {
    Note note(-1, NoteLetter::F, Accidental::Natural);
    REQUIRE(note.GetMidiIndex() == 5);
  }

  SECTION("Midi index 11 is B_-1") {
    Note note(-1, NoteLetter::B, Accidental::Natural);
    REQUIRE(note.GetMidiIndex() == 11);
  }

  SECTION("Midi index 12 is C0") {
    Note note(0, NoteLetter::C, Accidental::Natural);
    REQUIRE(note.GetMidiIndex() == 12);
  }

  SECTION("Midi index 21 is A0") {
    Note note(0, NoteLetter::A, Accidental::Natural);
    REQUIRE(note.GetMidiIndex() == 21);
  }

  SECTION("Midi index 30 is F#1") {
    Note note(1, NoteLetter::F, Accidental::Sharp);
    REQUIRE(note.GetMidiIndex() == 30);
  }

  SECTION("Midi index 41 is F2") {
    Note note(2, NoteLetter::F, Accidental::Natural);
    REQUIRE(note.GetMidiIndex() == 41);
  }

  SECTION("Midi index 108 is C8") {
    Note note(8, NoteLetter::C, Accidental::Natural);
    REQUIRE(note.GetMidiIndex() == 108);
  }

  SECTION("Midi index 127 is G9") {
    Note note(9, NoteLetter::G, Accidental::Natural);
    REQUIRE(note.GetMidiIndex() == 127);
  }

  SECTION("Notes too small throw exception") {
    REQUIRE_NOTHROW(Note(-1, NoteLetter::B, Accidental::Flat));
    REQUIRE_NOTHROW(Note(-1, NoteLetter::C, Accidental::Sharp));
    REQUIRE_THROWS(Note(-1, NoteLetter::C, Accidental::Flat));
    REQUIRE_THROWS(Note(-2, NoteLetter::B, Accidental::Natural));
    REQUIRE_THROWS(Note(-2, NoteLetter::B, Accidental::Flat));
  }
}

TEST_CASE("Operators behave as expected", "[constructor][accidental]") {
  SECTION("Two equal notes are equal") {
    Note note1{5, Accidental::Sharp};
    Note note2{5, Accidental::Sharp};

    REQUIRE(note1 == note2);
  }

  SECTION("Two notes with different midi_index are not equal") {
    Note note1{5, Accidental::Sharp};
    Note note2{6, Accidental::Sharp};

    REQUIRE_FALSE(note1 == note2);
  }

  SECTION("Two notes with same midi_index but different letters are not equal") {
    Note note1{5, NoteLetter::C, Accidental::Natural};
    Note note2{5, NoteLetter::B, Accidental::Sharp};

    REQUIRE_FALSE(note1 == note2);
  }

  SECTION("Two equal notes return true for EqualsMidiIndex") {
    Note note1{5, Accidental::Sharp};
    Note note2{5, Accidental::Sharp};

    REQUIRE(note1.EqualsMidiIndex(note2));
  }

  SECTION("Two notes with different midi_index return false for EqualsMidiIndex") {
    Note note1{5, Accidental::Sharp};
    Note note2{6, Accidental::Sharp};

    REQUIRE_FALSE(note1.EqualsMidiIndex(note2));
  }

  SECTION("Two notes with same midi_index but different letters return true for EqualsMidiIndex") {
    Note note1{5, NoteLetter::D, Accidental::Sharp};
    Note note2{5, NoteLetter::E, Accidental::Flat};

    REQUIRE(note1.EqualsMidiIndex(note2));
  }
}