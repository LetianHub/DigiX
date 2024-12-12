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

#ifndef REGISTER_H_
#define REGISTER_H_

#include <vector>

#include "main/basic_unit/basic_unit.h"

namespace DigiX {

class Register {
 public:
  Register(const char bits)
      : bits_(bits), D_flip_flops_(std::vector<basic_unit::DFlipFlop>(bits)), Q_(std::vector<bool>(bits)) {}
  void Run(const bool clock, const bool load, const std::vector<bool>& input);
  bool GetOutput(const bool enable, std::vector<bool>* output) const;

 private:
  char bits_;
  std::vector<basic_unit::DFlipFlop> D_flip_flops_;
  std::vector<bool> Q_;
};

}  // namespace DigiX

#endif  // REGISTER_H_