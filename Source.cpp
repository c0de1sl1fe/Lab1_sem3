
#include <iostream>
#include "Graphics.h"
#include "Class.h"
Graphics g;

void DrawRectangle(int x1, int y1, int x2, int y2)
{

}

int main()
{
    BinaryImg a(100, 100);
    std::cout << a;
    g.DrawRectangle(1, 1, 13, 111);
    system("pause");
    return 1;
}