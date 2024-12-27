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

#include "main/program_counter/program_counter.h"

namespace DigiX {

bool ProgramCounter::Run(const bool clock, const bool enable, const bool load, const std::vector<bool>& input) {
  if (input.size() != bits_) {
    return false;
  }
  std::vector<bool> Q_prev = Q_;
  for (unsigned char i = 0; i < bits_; ++i) {
    bool J_i = enable;
    for (unsigned char j = 0; j < i; ++j) {
      J_i = J_i && Q_prev[j];
    }
    J_i = (input[i] && load && !enable) || (J_i && !Q_prev[i]);
    bool K_i = enable;
    for (unsigned char j = 0; j <= i; ++j) {
      K_i = K_i && Q_prev[j];
    }
    K_i = K_i || (!J_i && load && !enable);
    JK_flip_flops_[i].Run(clock, J_i, K_i);
    Q_[i] = JK_flip_flops_[i].GetOutput();
  }
  return true;
}
bool ProgramCounter::GetOutput(const bool enable_out, std::vector<bool>* output) const {
  if (enable_out) {
    *output = Q_;
  } else {
    output->clear();
  }
  return enable_out;
}

}  // namespace DigiX