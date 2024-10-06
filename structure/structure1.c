#include <stdio.h>
#include <math.h>

struct point
{
    double x;
    double y;
};

typedef struct point Point;

struct triangle
{
    Point a;
    Point b;
    Point c;
};
typedef struct triangle Triangle;

// Тут нужно написать все необходимые функции
void print_point(Point point)
{
    printf("(%.2f, %.2f) \n", point.x, point.y);
}

void print_triangle(Triangle* tr)
{
    printf("{(%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)} \n", (*tr).a.x, (*tr).a.y, (*tr).b.x, (*tr).b.y, (*tr).c.x, (*tr).c.y);
}

double distance(Point a, Point b)
{
    double dx = fabs(a.x - b.x);
    double dy = fabs(a.y - b.y);
    double dist = sqrt(dx * dx + dy * dy);
    return dist;
}

double get_triangle_perimeter(Triangle* tr)
{
    double ab = distance(tr->a, tr->b);
    double bc = distance(tr->c, tr->b);
    double ac = distance(tr->a, tr->c);
    return (ab + bc + ac);
}

Triangle moved_triangle(const Triangle* tr, Point s)
{
    Triangle ntr;

    ntr.a.x = (*tr).a.x + s.x;
    ntr.a.y = (*tr).a.y + s.y;

    ntr.b.x = (*tr).b.x + s.x;
    ntr.b.y = (*tr).b.y + s.y;

    ntr.c.x = (*tr).c.x + s.x;
    ntr.c.y = (*tr).c.y + s.y;

    return ntr;
}

void move_triangle(Triangle* tr, Point s)
{
    (*tr).a.x = (*tr).a.x + s.x;
    (*tr).a.y = (*tr).a.y + s.y;

    (*tr).b.x = (*tr).b.x + s.x;
    (*tr).b.y = (*tr).b.y + s.y;

    (*tr).c.x = (*tr).c.x + s.x;
    (*tr).c.y = (*tr).c.y + s.y;
}

int main()
{
    Triangle t = {{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}};
    printf("Perimeter = %.2f\n", get_triangle_perimeter(&t));

    Point d = {1.0, 1.0};
    print_point(d);

    print_triangle(&t);

    move_triangle(&t, d);
    print_triangle(&t);
}