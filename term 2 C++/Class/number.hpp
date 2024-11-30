/*
    Класс Number - класс положительных больших чисел

    Большое число будет храниться в массиве в сегменте куча.
    В самом объекте будем хранить указатель на данные в куче.
    Также, в самом объекте будут храниться размер и вместимость массива.

        data - указатель, на элементы, хранящиеся в куче.
        capacity - размер массива data.
        size - сколько ячеек занимет число в массиве data, size <= capacity.

    По условию задачи класс Number должен поддерживать только положительные числа.
    Это сделано для того, чтобы задача не была слишком сложной.

    Каждый элемент массива должен содержать разряд числа в 100-ричной системе счисления (так как base = 100).
    По сути, каждый элемент массива должен хранить две цифры числа в десятичной записи.

    Значение 100 для системы счисления выбрано для того, чтобы задача была не такой сложной.
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа, размером 1 байт),
    то алгоритм печати на экран усложнится. Наиболее эффективный вариант - использование 64 битных чисел
    (то есть uint64_t вместо char) и базы 2^64, но это бы ещё сильнее усложнило эту задачу.

    Для удобства разряды числа хранятся в обратном порядке (это упрощает многие алгоритмы с такими числами). 
    Например, число 12345678 соответствует массиву:
    
        {78, 56, 34, 12}
    
    Для выделения/освобождения памяти в куче были использованы операторы new[] и delete[].
    Хотя можно было бы и использовать функции malloc и free из библиотеки cstdlib.

    Выделение/освобождения с использованием malloc/free:

        data = static_cast<char*>(std::malloc(capacity * sizeof(char)));
        ...
        std::free(data);

    То же самое с использованием new[]/delete[]:

        data = new char[capacity];
        ...
        delete[] data;

*/


#pragma once

#include <iostream>
#include <iomanip>
#include <string> 
using namespace std::string_literals;


class Number 
{
private:
    static const int base = 100;

    char* data;
    std::size_t size;
    std::size_t capacity;

    void copyData(const Number& other) {
        delete[] data; // Освобождаем старую память
        capacity = other.capacity;
        size = other.size;
        data = new char[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

public:
    Number()
    {
        this->capacity = 1;
        this->size = 1;
        data = new char[capacity];
        data[0] = 0;
    }

    Number(const Number& n)
    {
        this->capacity = n.capacity;
        this->size = n.size;
        data = new char[capacity];
        for (int i = 0; i < capacity; i++){
            data[i] = n.data[i];
        }
    }

    Number(int a) 
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0) 
            capacity = 1;

        // Выделяем память в куче и записывем число a в массив data
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }

    Number(const std::string& str){
        //std::cout << "here" << std::endl;
        int dl = str.size();
        //std::cout << dl << "lenght" << std::endl;
        int cap = dl / 2;
        if (dl % 2 == 0){
            capacity = cap;
            size = cap;
        }
        else{
            capacity = cap + 1;
            size = cap + 1;
        }
        data = new char[capacity];
        int t = 0;
        for(int i = dl - 2; i >= 0; i -= 2) 
        {
            std::string sa = str.substr(i, 2);
            int a = std::stoi(sa);
            a = static_cast<char>(a);
            data[t] = a;
            t += 1;
         }
         
         if (dl % 2 != 0){
            std::string s = str.substr(0, 1);
            int a0 = std::stoi(s);
            a0 = static_cast<char>(a0);
            data[t] = a0;
         }
    }

    Number& operator=(const Number& other) {
        if (this != &other) { // Проверка самоприсваивания
            copyData(other);
        }
        return *this;
    }

    ~Number() 
    {
        delete [] data;
    }

    
    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
    friend Number operator+(const Number& a, const Number& b);
    friend void razr(const Number& a);
    friend bool isEven(const Number& a);

};


std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.data[num.size - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw используются для того, чтобы замостить ноликом, элемент будет меньше чем 10.
    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);

    return stream;
}


Number operator+(const Number& a, const Number& b) {
    Number result(std::max(a.capacity, b.capacity) + 1);
    int carry = 0;
    int i = 0;

    while (i < a.size || i < b.size || carry) {
        int digitA = 0;
        int digitB = 0;

        if (i < a.size){
            digitA = a.data[i];
        }

        if (i < b.size){
            digitB = b.data[i];
        }

        int sum = digitA + digitB + carry;
        result.data[i] = sum % 100;
        carry = sum / 100;
        i++;
    }
    result.size = i; 
    return result;
}

Number& operator+=(Number& a, const Number& b) {
    a = a + b;
    return a;
}

void razr(const Number& a){
    int i = 0;
    while(i < a.size){
        std::cout << static_cast<int>(a.data[i]) << std::endl;
        i++;
    }
}

Number fib(int n){
    Number a = 0;
    Number b = 1;
    if(n == 0){
        return a;
    }
    else if(n == 1){
        return b;
    }
    else{
        for(int i = 2; i <= n; i++){
            Number c = a + b;
            if (i == n - 1){
            }
            a = b;
            b = c;
        }
        return b;
    }
}

bool isEven(const Number& a){
    int s = static_cast<int>(a.data[0]);
    if (s % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}