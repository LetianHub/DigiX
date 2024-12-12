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

#include <iostream>
#include <vector>

#include "main/register/register.h"

int main() {
  DigiX::basic_unit::Clock clock(1, 10);
  std::vector<bool> clock_seq;
  clock.GetClock(&clock_seq);
  DigiX::Register reg(8);
  for (uint i = 0; i < clock_seq.size(); ++i) {
    std::cout << "clock: " << clock_seq[i] << std::endl;
    bool load = (i < 5);
    std::cout << "load: " << load << std::endl;
    std::vector<bool> input(8);
    std::cout << "input: ";
    for (uint j = 0; j < 8; ++j) {
      input[j] = (rand() % 2);
      std::cout << input[j];
    }
    std::cout << std::endl;
    reg.Run(clock_seq[i], load, input);
    bool enable = true;
    std::cout << "enable: " << enable << std::endl;
    std::vector<bool> output(8);
    bool valid = reg.GetOutput(enable, &output);
    if (valid) {
      std::cout << "output: ";
      for (uint j = 0; j < 8; ++j) {
        std::cout << output[j];
      }
      std::cout << std::endl;
    } else {
      std::cout << "output: empty" << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
  }

  // DigiX::basic_unit::DFlipFlop Dff_1;
  // std::vector<bool> clock{0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0};
  // std::vector<bool> D{0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0};
  // for (u_int32_t i = 0; i < clock.size(); ++i) {
  //   Dff_1.Run(clock[i], D[i]);
  //   bool Q = Dff_1.GetOutput();
  //   std::cout << Q << std::endl;
  // }
  return 0;
}