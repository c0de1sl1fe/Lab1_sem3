
#include <iostream>
#include "Graphics.h"

Graphics g;

int main()
{
    //g.DrawLine(1, 1, 100, 1);
    //g.DrawLine(100, 1 ,100, 100);
    g.DrawRectangle(100, 100, 100, 100);
    std::cout << "Hello World!\n";
    system("pause");
}