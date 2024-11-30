#pragma once

#include <cmath>
#include <iostream>

struct Vector2f 
{
    float x;
    float y;
};


Vector2f& operator+(const Vector2f& a, const Vector2f& b) 
{
    Vector2f result = {a.x + b.x, a.y + b.y};
    return result;
}

Vector2f& operator-(const Vector2f& a, const Vector2f& b)
{
    Vector2f result = {a.x - b.x, a.y - b.y};
    return result;
}

Vector2f& operator*(const Vector2f& a, float b) 
{
    Vector2f result = {a.x * b, a.y * b};
    return result;
}

Vector2f& operator*(float b, const Vector2f& a) 
{
    return a * b;
}

float operator*(const Vector2f& a, const Vector2f& b) 
{
    return (a.x * b.x + a.y * b.y);
}

Vector2f operator-(const Vector2f& a) 
{
    Vector2f result = {-a.x, -a.y};
    return result;
}

Vector2f operator+(const Vector2f& a) 
{
    Vector2f result = {a.x, a.y};
    return result;
}

bool operator==(Vector2f a, Vector2f b) 
{
    if(a.x == b.x && a.y == b.y){
        return true;
    }
    else{
        return false;
    }
}

bool operator!=(const Vector2f& a, const Vector2f& b) 
{
    if(a.x != b.x || a.y != b.y){
        return true;
    }
    else{
        return false;
    }
}

Vector2f& operator+=(Vector2f& a, const Vector2f& p)
{
    a.x += p.x;
    a.y += p.y;
    return a;
}

Vector2f& operator-=(Vector2f& a, const Vector2f& p)
{
    a.x -= p.x;
    a.y -= p.y;
    return a;
}

Vector2f& operator*=(Vector2f& a, float b) 
{
    a.x *= b;
    a.y *= b;
    return a;
}


std::ostream& operator<<(std::ostream& out, Vector2f a) 
{
    out << "(" << a.x << "," << a.y << ")" << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Vector2f& a) 
{
    in >> a.x >> a.y;
    return in;
}