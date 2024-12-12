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

#include "main/register/register.h"

namespace DigiX {

void Register::Run(const bool clock, const bool load, const std::vector<bool>& input) {
  if (load) {
    for (char i = 0; i < bits_; ++i) {
      bool Q_i = D_flip_flops_[i].GetOutput();
      bool D_i = basic_unit::TwoWaySelector(Q_i, input[i], load);
      D_flip_flops_[i].Run(clock, D_i);
      Q_[i] = D_flip_flops_[i].GetOutput();
    }
  }
}
bool Register::GetOutput(const bool enable, std::vector<bool>* output) const {
  if (enable) {
    *output = Q_;
  } else {
    output->clear();
  }
  return enable;
}

}  // namespace DigiX