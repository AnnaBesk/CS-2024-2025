#include <iostream>
#include <string>

std::string repeat(int n) {
  std::string result;
  if (n > 0) {
    for (int i = 0; i < n; ++i) {
      result += std::to_string(n);
    }
  }
  return result;
}
int main() {
  std::cout << repeat(5) << std::endl; // Должно напечатать 55555
  std::cout << repeat(10) << std::endl; // Должно напечатать 10101010101010101010
  std::cout << repeat(-1) << std::endl; // Не должно ничего печатать
  return 0;
}