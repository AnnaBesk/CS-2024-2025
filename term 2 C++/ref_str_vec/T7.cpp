#include <cstdio>
#include <iostream>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits) {
  numLetters = 0;
  numDigits = 0;
  int len = str.length();
  for (int i = 0; i < len; i++){
    if (isalpha(str[i])) {
      numLetters++;
    } else if (isdigit(str[i])) {
      numDigits++;
    }
  }
}
int main(){
    std::string str = "Hello123World!";
    int numLetters = 0;
    int numDigits = 0;
    countLetters(str, numLetters, numDigits);
    std::cout << "Количество букв: " << numLetters << std::endl;
    std::cout << "Количество цифр: " << numDigits << std::endl;

}