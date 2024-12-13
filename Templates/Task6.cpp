#include <iostream>

template<typename T, T Mod>
class Modular{
    private:
        T value;

    public:
        Modular(T val) : value(val % Mod) {
            if (value < 0) value += Mod; // Обеспечиваем неотрицательное значение
            }

        Modular(const Modular& other){
            value = other.value;
        }

        //с числами
        Modular operator+(T val) const { return Modular(value + val); }
        Modular operator-(T val) const { return Modular(value - val); }
        Modular operator*(T val) const { return Modular(value * val); }

        // с другими объектами того же типа
        Modular operator+(const Modular& other) const { return Modular(value + other.value); }
        Modular operator-(const Modular& other) const { return Modular(value - other.value); }
        Modular operator*(const Modular& other) const { return Modular(value * other.value); }

        //Унарный минус
        Modular operator-() const { return Modular(-value); }

        friend std::ostream& operator<<(std::ostream& out, const Modular& mod) {
            out << mod.value;<< std::endl;
            return out;
        }

        template <typename U, U Mod2>
        Modular(const Modular<U, Mod2>& other) : value(other.value % Mod) {
            if (value < 0) value += Mod;}
        
};

int main(){
}