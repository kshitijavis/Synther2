#pragma once

namespace synther {

namespace logic {

enum class NoteLetter { A, B, C, D, E, F, G };

/**
 * Represents a music note. Uses the MIDI standard to index notes based on their
 * distance from C_-1. Allows notes to take on various other forms, such as
 * English standard (A#, Bb, ...)
 */
class Note {
 public:
  static const NoteLetter kBaseNote = NoteLetter::C;
  static constexpr int kBaseOctave = -1;
  static constexpr int kOctaveLength = 12;

  Note(int midi_index);

  int GetMidiIndex();
  int GetOctave();

 private:
  // Number of notes away from C_-1
  const int midi_index_;
};

}  // namespace logic

}  // namespace synther