#include <iostream>
#include <cmath>
#include "point.hpp"
using std::cout, std::endl;

const double PI = 3.141592653589793;

class Circle
{
private:
	Point center;
	float radius;

public:
    Circle(const Point& center, float radius){
        this->center = center;
        this->radius = radius;
    }
    Circle(){
        this->center = Point(0, 0);
        this->radius = 1;
    }
    Circle(const Circle& circle){
        this->center = circle.center;
        this->radius = circle.radius; 
    }

    void setCenter(const Point& point){this->center = point;}
    void setRadius(float rad){
        if (rad < 0){
            this->radius = 0;
        }
        else{
            this->radius = rad;
        }
        }

    Point getCenter() const{return this->center;}
    float getRadius() const{return this->radius;}

    float area() const{return PI * this->radius * this->radius;}

    float distance(const Point& point) const{
        float d = this->center.distance(point);
        return fabs(d - this->radius);
    }

    bool isColliding(const Circle& c) const{
        if (this->center.distance(c.center) < (this->radius + c.radius)){
            return true;
        }
        else{
            return false;
        }
    }

    void move(const Point& p){
        this->center = center + p;
    }
};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;


	Circle a({4, 1}, 3);
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.area() << endl;
	cout << "Distance from point p to circle a = " << a.distance(p) << endl;


	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;


	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;
}