#include "Class.h"
#include <math.h>
#include <iostream>

BinaryImg::BinaryImg(int x, int y)
{
    if (x <= 0 || y <= 0) { throw("invalid dimension"); }
    row = x;
    col = y;
    array = new bool* [row];
    for (int i = 0; i < row; i++)
    {
        array[i] = new bool[col] {};
    }
}
BinaryImg::BinaryImg(const BinaryImg& src)
{
    row = src.row;
    col = src.col;
    array = new bool* [row];
    for (int i = 0; i < row; i++)
    {
        array[i] = new bool[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] = src.array[i][j];
        }
    }
}
BinaryImg::~BinaryImg()
{
    for (int i = 0; i < row; i++)
    {
        delete[]array[i];
    }
    delete[]array;
}
void Print()
{

}