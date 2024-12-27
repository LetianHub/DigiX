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

#include "main/program_counter/program_counter.h"

int main() {
  DigiX::basic_unit::Clock clock(1, 20);
  std::vector<bool> clock_seq;
  clock.GetClock(&clock_seq);
  DigiX::ProgramCounter pc(4);
  std::vector<bool> output(4);
  for (uint i = 0; i < clock_seq.size(); ++i) {
    std::cout << "clock: " << clock_seq[i] << std::endl;
    // for the first 10 clocks, run the PC
    bool enable;
    bool load = true;
    if (i < 10 || i > 17) {
      enable = true;
      std::cout << "enable: " << enable << std::endl;
      std::vector<bool> input(4, false);
      pc.Run(clock_seq[i], enable, load, input);
    } else {
      enable = false;
      std::vector<bool> input(4);
      std::cout << "input: ";
      for (uint j = 0; j < 4; ++j) {
        input[j] = (rand() % 2);
        std::cout << input[j];
      }
      std::cout << std::endl;
      pc.Run(clock_seq[i], enable, load, input);
    }
    pc.GetOutput(true, &output);
    std::cout << "output: ";
    for (uint j = 0; j < 4; ++j) {
      std::cout << output[j];
    }
    std::cout << std::endl;
  }

  return 0;
}