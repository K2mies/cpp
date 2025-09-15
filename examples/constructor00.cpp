#include <iostream>

struct Point
{
    int x;
    int y;

//    Point()
//    {
//        x = 20;
//        y = 10;
//        std::cout << "constructor!\n";
//    }
//    Point() : x(10), y(20) {}
    Point() = default;
    Point(int new_x, int new_y) : x(new_x), y(new_y) {}
//    Point(int new_x, int new_y)
//    {
//        x = new_x;
//        y = new_y;
//    }
    void print()
    {
        std::cout << "x = " << x << '\n';
        std::cout << "y = " << y << '\n';
    }
};

int main()
{
    Point p;
//    Point p(5, 7);
    p.print();
}
