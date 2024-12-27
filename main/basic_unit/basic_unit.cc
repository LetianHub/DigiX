// Copyright 2023 Letian Lin <lin_letian@126.com>. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.storytotell.cn/wordpress/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "main/basic_unit/basic_unit.h"

namespace DigiX {
namespace basic_unit {

void DFlipFlop::Run(const bool clock, const bool D) {
  if (clock_prev_ == false && clock == true) {
    Q_ = D;
  }
  clock_prev_ = clock;
}
const bool DFlipFlop::GetOutput() const { return Q_; }

void JKFlipFlop::Run(const bool clock, const bool J, const bool K) {
  if (clock_prev_ == false && clock == true) {
    if (J == true && K == true) {
      Q_ = !Q_;
    } else if (J == true && K == false) {
      Q_ = true;
    } else if (J == false && K == true) {
      Q_ = false;
    } else if (J == false && K == false) {
      Q_ = Q_;
    }
  }
  clock_prev_ = clock;
}
const bool JKFlipFlop::GetOutput() const { return Q_; }

Clock::Clock(const unsigned int half_period, const unsigned int num_period) {
  if (half_period > 0) {
    for (unsigned int step = 0; step < half_period; ++step) {
      clock_squence_.push_back(false);
    }
    for (unsigned int i = 0; i < num_period; ++i) {
      for (unsigned int step = 0; step < half_period; ++step) {
        clock_squence_.push_back(true);
      }
      for (unsigned int step = 0; step < half_period; ++step) {
        clock_squence_.push_back(false);
      }
    }
  }
};
bool Clock::GetClock(std::vector<bool>* clock_sequence) const {
  if (clock_squence_.empty()) {
    return false;
  }
  *clock_sequence = clock_squence_;
  return true;
};

}  // namespace basic_unit
}  // namespace DigiX