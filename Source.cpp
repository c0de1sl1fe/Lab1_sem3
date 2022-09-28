
#include <iostream>
#include "Graphics.h"
#include "Class.h"
#include <stdio.h>
//Graphics g;
int Max(int x, int y);
int Min(int x, int y);

//BinaryImg DrawRectangle(int x1, int y1, int x2, int y2)
//{
//    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) { throw EClassException("working with numbers greater than zero"); }
//
//    int firstX = Min(x1, x2), secondX = Max(x1, x2), firstY = Min(y1, y2), secondY = Max(x1, x2);
//    BinaryImg res(secondX + 1, secondY + 1);
//    //res.Print();
//    for (int i = firstX; i <= secondX; i++)
//    {
//        res(i, firstY) = true;
//        res(i, secondY) = true;
//    }
//    //res.Print();
//    for (int i = firstY; i <= secondY; i++)
//    {
//        res(firstX, i) = true;
//        res(secondX, i) = true;
//    }
//
//    return res;
//
//
//}
//
//void DrawRectangle(int x1, int y1, int x2, int y2, BinaryImg& src)
//{
//    x1--;
//    x2--;
//    y1--;
//    y2--;
//
//    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) { throw EClassException("working with numbers greater than zero"); }
//
//    if (x1 >= src.GetRow() || x2 >= src.GetRow() || y1 >= src.GetCol() || y2 >= src.GetCol())
//    {
//        src = DrawRectangle(x1, y1, x2, y2);
//        return;
//    }
//
//
//    int firstX = Min(x1, x2), secondX = Max(x1, x2), firstY = Min(y1, y2), secondY = Max(x1, x2);
//    //BinaryImg res(secondX + 1, secondY + 1);
//    
//    for (int i = firstX; i <= secondX; i++)
//    {
//        src(i, firstY) = true;
//        src(i, secondY) = true;
//    }
//    //res.Print();
//    for (int i = firstY; i <= secondY; i++)
//    {
//        src(firstX, i) = true;
//        src(secondX, i) = true;
//    }
//}

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
        BinaryImg a(10, 10);
        //std::cout << a;
        DrawRectangle(2, 2, 7, 5, a);
        //a = DrawRectangle(3, 13, 17, 8);
        std::cout << a;

    }
    catch (EClassException &err)
    {
        err.Print();
    }

    
    system("pause");
    return 1;
}