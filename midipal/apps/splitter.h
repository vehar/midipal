// Copyright 2011 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// -----------------------------------------------------------------------------
//
// Splitter app.

#ifndef MIDIPAL_PLUGINS_SPLITTER_H_
#define MIDIPAL_PLUGINS_SPLITTER_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class Splitter : public App {
 public:
  Splitter() { }

  void OnInit();
  void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);
 
  uint8_t settings_size() { return 4; }
  uint8_t settings_offset() { return SETTINGS_SPLITTER; }
  uint8_t* settings_data() { return &input_channel_; }

 private:
  uint8_t input_channel_;
  uint8_t split_point_;
  uint8_t lower_channel_;
  uint8_t upper_channel_;
  
  DISALLOW_COPY_AND_ASSIGN(Splitter);
};

} }  // namespace midipal::plugins

#endif // MIDIPAL_PLUGINS_SPLITTER_H_
