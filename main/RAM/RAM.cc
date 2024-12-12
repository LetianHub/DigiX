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

#include "main/RAM/RAM.h"

namespace DigiX {

void RAM::Run(const bool clock, const bool WR, const std::vector<bool>& address, const std::vector<bool>& input) {
  // decode the address to decimal index
  int addr_decimal = 0;
  int base = 1;
  for (unsigned int i = 0; i < address.size(); ++i) {
    addr_decimal += address[i] * base;
    base *= 2;
  }
  // write data to memory
  if (WR && (addr_decimal < words_)) {
    registers_[addr_decimal].Run(clock, true, input);
  }
}
bool RAM::GetOutput(const bool EN, const std::vector<bool>& address, std::vector<bool>* output) const {
  // decode the address to decimal index
  int addr_decimal = 0;
  int base = 1;
  for (unsigned int i = 0; i < address.size(); ++i) {
    addr_decimal += address[i] * base;
    base *= 2;
  }
  // get data from memory
  if (EN && (addr_decimal < words_)) {
    registers_[addr_decimal].GetOutput(true, output);
  } else {
    output->clear();
  }
  return EN && (addr_decimal < words_);
}

}  // namespace DigiX