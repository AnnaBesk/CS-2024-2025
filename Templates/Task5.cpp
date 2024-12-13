#include <iostream>
#include <cstdint>
#include <algorithm> 

template <typename T>
void swapEndianness(T& value) {
  std::uint8_t bytes[sizeof(T)];
  std::memcpy(bytes, &value, sizeof(T));
  std::reverse(bytes, bytes + sizeof(T));
  std::memcpy(&value, bytes, sizeof(T));
}

int main() {
    std::cout << std::hex;
    
    int a = 0x1a2b3c4d; 
    std::cout << a << std::endl; // 1a2b3c4d
    swapEndianness(a);             
    std::cout << a << std::endl; // 4d3c2b1a
    swapEndianness(a);             
    std::cout << a << std::endl; // 1a2b3c4d
    
    short b = 0x1a2b;   
    std::cout << b << std::endl; // 1a2b
    swapEndianness(b);
    std::cout << b << std::endl; // 2b1a
}
