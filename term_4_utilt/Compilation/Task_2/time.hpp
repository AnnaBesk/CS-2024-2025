#pragma once

class Time
{
private:
    int hours {};
    int minutes {};

public:
    Time(int,int);
    void reset();
    Time& operator+=(const Time&);
    Time operator+(const Time&) const;
    friend std::ostream& operator<<(std::ostream&, Time);
};