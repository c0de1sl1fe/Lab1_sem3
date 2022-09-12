
#include <iostream>
#include "Graphics.h"

Graphics g;

int main()
{
    g.DrawSquare(5, 5);
    g.DrawSquare(7, 7);
    g.DrawSquare(10, 10, 5);
    g.DrawLine(100, 50, 150, 40);
    std::cout << "Hello World!\n";
    system("pause");
}