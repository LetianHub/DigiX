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

#include "main/basic_unit/basic_unit.h"

int main() {
  DigiX::basic_unit::DFlipFlop Dff_1;
  std::vector<bool> clock{0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0};
  std::vector<bool> D{0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0};
  for (u_int32_t i = 0; i < clock.size(); ++i) {
    Dff_1.Run(clock[i], D[i]);
    bool Q = Dff_1.GetOutput();
    std::cout << Q << std::endl;
  }
  return 0;
}