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

#ifndef BASIC_UNIT_H_
#define BASIC_UNIT_H_

#include <vector>

namespace DigiX {
namespace basic_unit {

// Logical operators
inline bool AND(const bool in1, const bool in2) { return in1 && in2; };
inline bool OR(const bool in1, const bool in2) { return in1 || in2; };
inline bool XOR(const bool in1, const bool in2) { return in1 ^ in2; };

// Units
class DFlipFlop {
 public:
  DFlipFlop() {};
  void Run(const bool clock, const bool D);
  const bool GetOutput() const;

 private:
  bool Q_ = false;
  bool clock_prev_ = false;
};

class JKFlipFlop {
 public:
  JKFlipFlop() {};
  void Run(const bool clock, const bool J, const bool K);
  const bool GetOutput() const;

 private:
  bool Q_ = false;
  bool clock_prev_ = false;
};

class Clock {
 public:
  Clock(const unsigned int half_period, const unsigned int num_period);
  bool GetClock(std::vector<bool>* clock_sequence) const;

 private:
  std::vector<bool> clock_squence_;
};

inline void FullAdder(const bool in1, const bool in2, const bool cin, bool* sum, bool* cout) {
  *sum = XOR(XOR(in1, in2), cin);
  *cout = OR(AND(XOR(in1, in2), cin), AND(in1, in2));
}

inline bool TwoWaySelector(const bool in1, const bool in2, const bool channel) {
  return (in1 && !channel) || (in2 && channel);
};

}  // namespace basic_unit
}  // namespace DigiX

#endif  // BASIC_UNIT_H_