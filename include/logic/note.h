#pragma once

namespace synther {

namespace logic {

/**
 * Represents a music note. Uses the MIDI standard to index notes based on their distance from
 * C_-1. Allows notes to take on various other forms, such as English standard (A#, Bb, ...)
 */
class Note {
 public:
  Note(int midi_index);

  int GetMidiIndex();

 private:
  // Number of notes away from C_-1
  int midi_index_;
};

}  // namespace logic

}  // namespace synther