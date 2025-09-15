#include <iostream>

struct  Point
{
    int x;
    int y;

    Point(int new_x, int new_y) : x(new_x), y(new_y){}
//  here this would nullify the copy constructor entirley
//  Point(const Point &p) = delete;
    //here we are calling the copy constructor
    Point(const Point &p)
    {
        std::cout << "running our copy constructor!\n";
        x = p.x;
        y = p.y;
    }
    void print()
    {
        std::cout << "x = " << x << '\n';
        std::cout << "y = " << y << '\n';
    }
};

int main()
{
    Point p1(10, 20);
    p1.print();

    Point p2 = p1;
    p2.print();
    return (0);
}
