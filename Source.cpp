
#include <iostream>
#include "Graphics.h"
#include "Class.h"
#include <stdio.h>
//Graphics g;
int Max(int x, int y);
int Min(int x, int y);

BinaryImg DrawRectangle(int x1, int y1, int x2, int y2)
{
    x1--;
    x2--;
    y1--;
    y2--;
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) { throw EClassException("working with numbers greater than zero"); }

    int firstX = x1, secondX = x2, firstY = y1, secondY = y2;
    BinaryImg res(secondX + 1, secondY + 1);

    for (int i = firstX; i <= secondX; i++)
    {
        res(i, firstY) = true;
        res(i, secondY) = true;
    }

    for (int i = firstY; i <= secondY; i++)
    {
        res(firstX, i) = true;
        res(secondX, i) = true;
    }

    return res;


}

void DrawRectangle(int x1, int y1, int x2, int y2, BinaryImg& src)
{
    x1--;
    x2--;
    y1--;
    y2--;

    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) { throw EClassException("working with numbers greater than zero"); }

    if (x1 >= src.GetRow() || x2 >= src.GetRow() || y1 >= src.GetCol() || y2 >= src.GetCol())
    {
        src = DrawRectangle(x1, y1, x2, y2);
        return;
    }
    
    int firstX = x1, secondX = x2, firstY = y1, secondY = y2;

    for (int i = firstX; i <= secondX; i++)
    {
        src(i, firstY) = true;
        src(i, secondY) = true;
    }

    for (int i = firstY; i <= secondY; i++)
    {
        src(firstX, i) = true;
        src(secondX, i) = true;
    }
}

int Max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}
int Min(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    return x;
}


int main()
{

    std::cout << "Enter dimenstion of your rectangle:" << std::endl;

    try
    {
        int test = 14;
        BinaryImg a(test, test);
        //std::cout << a;
        int one = 3, two = test - 3;
        while (one <= two)
        {
            DrawRectangle(one, one, two, two, a);
            one += 2;
            two -= 2;
        }
        std::cout << a;
    }
    catch (EClassException &err)
    {
        err.Print();
    }

    
    system("pause");
    return 1;
}