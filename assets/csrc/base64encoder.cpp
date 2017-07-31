/*= compile: g++ -std=c++11 -Wall $src -o $exe =*/
/*= run: $exe =*/

#include <iostream>
#include <stdint.h>
#include <string>

std::string base64Encoder(const std::string &str) {
  static const char base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "abcdefghijklmnopqrstuvwxyz"
                                    "0123456789+/";
  uint8_t r[4], s[3], j, k;
  size_t i;
  std::string result = "";

  for (i = 0; i < str.length(); i += 3) {
    for (j = 0; j < 3 && i + j < str.length(); ++j)
      s[j] = str[i + j]; // Copying the source bytes

    // padding 0s if the number of bytes is not divisible by 3
    for (k = j; k < 3; ++k)
      s[k] = 0;

    // Calculating the result bytes
    r[0] = s[0] >> 2;
    r[1] = ((s[0] << 4) & 0x30) + (s[1] >> 4);
    r[2] = ((s[1] << 2) & 0x3c) + (s[2] >> 6);
    r[3] = s[2] & 0x3f;

    // Generating the result
    if (j < 3)
      for (k = 0; k <= j; ++k)
        result += base64Chars[r[k]];
    else
      for (k = 0; k < 4; ++k)
        result += base64Chars[r[k]];
  }
  // Padding '=' if the number of bytes is not divisible by 3
  while (k++ < 4)
    result += "=";

  return result;
}

int main() { std::cout << base64Encoder("abhi") << std::endl; }
