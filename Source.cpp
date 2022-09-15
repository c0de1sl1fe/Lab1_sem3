
#include <iostream>
#include "Graphics.h"
#include "Class.h"
Graphics g;

void DrawRectangle(int x1, int y1, int x2, int y2)
{

}

int main()
{
    //g.DrawLine(1, 1, 100, 1);
    //g.DrawLine(100, 1 ,100, 100);
    g.DrawRectangle(100, 100, 100, 100);
    std::cout << "Hello World!\n";
    system("pause");
}