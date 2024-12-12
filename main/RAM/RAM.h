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

#ifndef RAM_H_
#define RAM_H_

#include <vector>

#include "main/register/register.h"

namespace DigiX {

class RAM {
 public:
  RAM(const char words, const char bits)
      : bits_(bits), words_(words), registers_(std::vector<Register>(words, Register(bits))) {}
  void Run(const bool clock, const bool WR, const std::vector<bool>& address, const std::vector<bool>& input);
  bool GetOutput(const bool EN, const std::vector<bool>& address, std::vector<bool>* output) const;

 private:
  char bits_;
  char words_;
  std::vector<Register> registers_;
};

}  // namespace DigiX

#endif  // RAM_H_