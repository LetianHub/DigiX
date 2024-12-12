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

#include "main/ALU/ALU.h"

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
  DigiX::ALU alu(8);
  int A = 92;
  int B = 23;
  std::cout << "A: " << A << std::endl;
  std::cout << "B: " << B << std::endl;
  std::vector<bool> A_bits = DecimalToVector(A);
  std::vector<bool> B_bits = DecimalToVector(B);
  alu.Run(false, A_bits, B_bits);
  std::vector<bool> output;
  alu.GetOutput(true, &output);
  std::cout << "addition of two numbers: " << std::endl;
  int ouput_decimal = VectorToDecimal(output);
  std::cout << ouput_decimal << std::endl;
  alu.Run(true, A_bits, B_bits);
  alu.GetOutput(true, &output);
  std::cout << "subtraction of two numbers: " << std::endl;
  ouput_decimal = VectorToDecimal(output);
  std::cout << ouput_decimal << std::endl;
  return 0;
}