#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "note.h"

using synther::logic::Note;

TEST_CASE("Constrcutor correctly sets fields", "[constructor]") {
    int midi_index = GENERATE(-5, -1, 1, 5);
    Note note(midi_index);
    REQUIRE(note.GetMidiIndex() == midi_index);
}