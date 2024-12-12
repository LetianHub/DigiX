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

#include "main/ALU/ALU.h"

namespace DigiX {

void ALU::Run(const bool SU, const std::vector<bool>& A, const std::vector<bool>& B) {
  bool cin = SU;
  bool sum = false;
  bool cout = false;
  for (char i = 0; i < bits_; ++i) {
    basic_unit::FullAdder(A[i], basic_unit::XOR(B[i], SU), cin, &sum, &cout);
    Q_[i] = sum;
    cin = cout;
  }
}
bool ALU::GetOutput(const bool EO, std::vector<bool>* output) const {
  if (EO) {
    *output = Q_;
  } else {
    output->clear();
  }
  return EO;
}

}  // namespace DigiX