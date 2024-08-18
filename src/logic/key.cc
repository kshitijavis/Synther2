#include "logic/key.h"

#include <iostream>

#include "logic/key.h"

namespace synther {
namespace logic {
Key::Key(const Note& note)
    : note_(note), key_color_{ComputeKeyColor(note.GetMidiIndex())}, is_pressed_{false} {}

bool Key::IsPressed() const { return is_pressed_; }

KeyColor Key::GetKeyColor() const { return key_color_; }

const Note& Key::GetNote() const { return note_; }

void Key::Press() { is_pressed_ = true; }

void Key::Release() { is_pressed_ = false; }

KeyColor Key::ComputeKeyColor(unsigned midi_index) {
  unsigned octave_index = midi_index % 12;
  return std::set<unsigned>{1, 3, 6, 8, 10}.contains(octave_index) ? KeyColor::Black
                                                                   : KeyColor::White;
}

}  // namespace logic
// namespace logic
}  // namespace synther