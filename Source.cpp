
#include <iostream>
#include "Graphics.h"
#include "Class.h"
#include <stdio.h>
//Graphics g;
int Max(int x, int y);
int Min(int x, int y);

BinaryImg DrawRectangle(int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) { throw EClassException("working with numbers greater than zero"); }

    int firstX = Min(x1, x2), secondX = Max(x1, x2), firstY = Min(y1, y2), secondY = Max(x1, x2);
    BinaryImg res(secondX + 1, secondY + 1);
    //res.Print();
    for (int i = firstX; i <= secondX; i++)
    {
        res(i, firstY) = true;
        res(i, secondY) = true;
    }
    //res.Print();
    for (int i = firstY; i <= secondY; i++)
    {
        res(firstX, i) = true;
        res(secondX, i) = true;
    }

    return res;


}
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

//BinaryImg DrawRectangle(int x1, int y1, int x2, int y2, const BinaryImg &src)
//{
//    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) { throw EClassException("working with numbers greater than zero"); }
//
//    int firstX = Min(x1, x2), secondX = Max(x1, x2), firstY = Min(y1, y2), secondY = Max(x1, x2);
//    BinaryImg res(secondX + 1, secondY + 1);
//
//    
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
//    BinaryImg tmp(Max(src.GetRow(), res.GetRow()), Max(src.GetCol(), res.GetCol()));
//    tmp = tmp + res;
//    tmp = tmp + src;
//        
//    return tmp;
//
//
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
    
    //Graphics* screen = new Graphics(320, 50);
    //int x = 10, y = 10;

    //for (int i = 0; i < 30; i++)
    //{
    //    for (int j = 0; j < 30; j++)
    //    {
    //        x = i * 10;
    //        y = j * 10;
    //        screen->DrawLine((float)x, (float)y, (float)(x + 10), (float)y);
    //        screen->DrawLine((float)x, (float)y, (float)x, (float)(y + 10));
    //        screen->DrawLine((float)(x + 10), (float)y, (float)(x + 10), (float)(y + 10));
    //        screen->DrawLine((float)x, (float)(y + 10), (float)(x + 10), (float)(y + 10));
    //    }
    //}
    //delete screen;
    //std::cout << Max(2, 3) << std::endl;
    //std::cout << Min(23, 11) << std::endl;
    std::cout << "Enter dimenstion of your rectangle:" << std::endl;

    //int a;
    //std::cout << "Enter x1:";
    //std::cin >> a;
    //int b;
    //std::cout << "Enter y1:";
    //std::cin >> b;
    //int a1;
    //std::cout << "Enter x2:";
    //std::cin >> a1;
    //int b1;
    //std::cout << "Enter y2:";
    //std::cin >> b1;
    try
    {
        BinaryImg a(10, 10);
        std::cout << a;
        
        a = DrawRectangle(3, 13, 17, 18);
        a.Print(1);
        //BinaryImg B = DrawRectangle(2, 2, 4, 4);
        //BinaryImg A = DrawRectangle(a, b, a1, b1, B);
        //A.Print();
        //std::cout << A;
    }
    catch (EClassException &err)
    {
        err.Print();
    }

    
    system("pause");
    return 1;
}