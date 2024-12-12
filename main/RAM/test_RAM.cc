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

#include <algorithm>
#include <iostream>
#include <vector>

#include "main/RAM/RAM.h"

std::vector<bool> DecimalToVector(int decimal) {
  std::vector<bool> bits;
  for (int i = 0; i < 8; ++i) {
    bits.push_back(decimal % 2);
    decimal /= 2;
  }
  return bits;
}

int VectorToDecimal(const std::vector<bool>& bits) {
  int decimal = 0;
  int base = 1;
  for (u_int32_t i = 0; i < bits.size(); ++i) {
    decimal += bits[i] * base;
    base *= 2;
  }
  return decimal;
}

int main() {
  // initialize 16 words x 8 bits RAM
  DigiX::RAM ram(16, 8);
  // genereate clock sequence
  DigiX::basic_unit::Clock clock(1, 2);
  std::vector<bool> clock_seq;
  clock.GetClock(&clock_seq);
  std::cout << "clock sequence: ";
  for (uint i = 0; i < clock_seq.size(); ++i) {
    std::cout << clock_seq[i];
  }
  std::cout << std::endl;
  // write data to each word of memory
  for (uint i = 0; i < clock_seq.size(); ++i) {
    std::cout << "clock: " << clock_seq[i] << std::endl;
    std::vector<bool> address(4);
    std::cout << "address: ";
    for (uint k = 0; k < 16; ++k) {  // 16 words
      address = DecimalToVector(k);
      for (uint j = 0; j < 4; ++j) {
        std::cout << address[j];
      }
      std::cout << std::endl;
      std::vector<bool> input(8);
      std::cout << "input: ";
      for (uint j = 0; j < 8; ++j) {
        input[j] = (rand() % 2);
        std::cout << input[j];
      }
      std::cout << std::endl;
      ram.Run(clock_seq[i], true, address, input);
    }
    // read data from memory
    std::vector<bool> address_read(4);
    std::cout << "address_read: ";
    for (uint j = 0; j < 4; ++j) {
      address_read[j] = (rand() % 2);
      std::cout << address_read[j];
    }
    std::cout << std::endl;
    std::vector<bool> output(8);
    ram.GetOutput(true, address_read, &output);
    std::cout << "output: ";
    for (uint j = 0; j < 8; ++j) {
      std::cout << output[j];
    }
    std::cout << std::endl;
  }
  return 0;
}