#include <iostream>
#include <stdexcept> 

template <typename T>
class Manager {
private:
    void* data;

public:
    Manager() : data(nullptr) {}

    void allocate() {
        data = std::malloc(sizeof(T));
        if (data == nullptr) {
            throw std::bad_alloc();
        }
    }

    void construct(const T& t) {
        if (data == nullptr) {
            throw std::runtime_error("Memory not allocated");
        }
        new (data) T(t);
    }

    void destruct() {
        if (data != nullptr) {
            ((T*)data)->~T();
        }
    }

    void deallocate() {
        if (data != nullptr) {
            std::free(data);
            data = nullptr;
        }
    }

    T& get() {
        if (data == nullptr) {
            throw std::runtime_error("Memory not allocated or object not constructed");
        }
        return *(static_cast<T*>(data));
    }

    ~Manager() {
        deallocate();
    }
};

int main() {
   Manager<std::string> a;
   a.allocate();
   a.construct("Cats and dogs");
   a.get() += " and elephant";
   std::cout << a.get() << std::endl;  // Должен напечатать Cats and dogs and elephant
   a.destruct();
   
   a.construct("Sapere Aude");
   std::cout << a.get() << std::endl;  // Должен напечатать Sapere Aude
   a.destruct();
   
   a.deallocate(); 
}
