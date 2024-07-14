#pragma once

#include <map>

namespace synther {

namespace logic {

enum class NoteLetter { A, B, C, D, E, F, G };
enum class Accidental { Sharp, Flat, Natural };

/**
 * Represents a music note. Uses the MIDI standard to index notes based on their
 * distance from C_-1. Allows notes to take on various other forms, such as
 * English standard (A#, Bb, ...)
 */
class Note {
 public:
  static const NoteLetter kBaseNote = NoteLetter::C;
  static constexpr int kBaseOctave = -1;
  static constexpr size_t kOctaveLength = 12;

  /**
   * Construct note given a midi index, as an offset from the base note C_-1
   * @param midi_index the index of the note from C_-1
   * @param priority if the note requires an accidental, this param specifies
   * which type of accidental takes priority. If the note requires an
   * accidental, but priority is passes as Natural, then an exception is thrown.
   * If the note does not require an accidental, then priority is ignored
   */
  Note(unsigned midi_index, Accidental priority);

  /**
   * Construct note given English name components. The smallest possible note is
   * C_-1
   * @param note_letter an English note letter
   * @param accidental sharp, flat or natural
   * @param octave the octave of the note. Smallest possible value is -1
   */
  Note(int octave, NoteLetter note_letter, Accidental accidental);

  int GetMidiIndex() const;
  int GetOctave() const;
  Accidental GetAccidental() const;
  NoteLetter GetNoteLetter() const;

 private:
  static const std::map<NoteLetter, int> kWholetoneIndices;

  struct EnglishName {
    NoteLetter note_letter;
    Accidental accidental;
    int octave;
  };

  const unsigned midi_index_;
  const EnglishName english_name_;

  EnglishName ComputeEnglishName(int midi_index, Accidental priority);
  unsigned ComputeMidiIndex(int octave, NoteLetter note_letter, Accidental accidental);
};

}  // namespace logic

}  // namespace synther