#include "Class.h"
#include <math.h>
#include <iostream>
#include "Graphics.h"

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
//void BinaryImg::Print() const
//{
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            array[i][j] ? std::cout << "1" : std::cout << ".";
//        }
//    }
//}
int BinaryImg::operator==(const BinaryImg& src) const
{
    if (row != src.row || col != src.col) { return 0; } // probably more fair to trow exception 
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (array[i][j] != src.array[i][j]) { return 0; }
        }
    }
    return true;
}
int BinaryImg::operator!=(const BinaryImg& src) const
{
    return !(*this == src);
}

bool& BinaryImg::operator()(int x, int y)
{
    if ((x >= row || y >= col) || (x < 0 || y < 0)) { throw("invalid index"); }
    return array[x][y];
}
BinaryImg BinaryImg::operator+(const BinaryImg& src) const
{
    if (row != src.row || col != src.col) { throw("Invalid dimensions of imgs"); }
    BinaryImg result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result.array[i][j] = array[i][j] + src.array[i][j];
        }
    }
    return result;
}

BinaryImg BinaryImg::operator*(const BinaryImg& src) const
{
    if (row != src.row || col != src.col) { throw("Invalid dimensions of imgs"); }
    BinaryImg result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result.array[i][j] = array[i][j] * src.array[i][j];
        }
    }
    return result;
}

BinaryImg BinaryImg::operator+(bool rhs) const
{
    BinaryImg result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result.array[i][j] = array[i][j] + rhs;
        }
    }
    return result;
}

BinaryImg BinaryImg::operator*(bool rhs) const
{
    BinaryImg result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result.array[i][j] = array[i][j] * rhs;
        }
    }
    return result;
}
BinaryImg BinaryImg::operator!()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] = !array[i][j];
        }
    }
    return *this;
}

BinaryImg& BinaryImg::operator= (const BinaryImg& src)
{
    if (this == (&src)) { return *this; }
    if (row == src.row && col == src.col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                array[i][j] = src.array[i][j];
            }
        }
        return *this;
    }

    for (int i = 0; i < row; i++)
    {
        delete[]array[i];
    }
    delete[]array;

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
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BinaryImg& obj)
{
    // TODO: insert return statement here
    //os << "(" << std::endl;
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.col; j++)
        {
            obj.array[i][j] ? os << "1" : os << ".";
        }
        os << std::endl;
    }
    //os << ")";
    return os;
}


double BinaryImg::AccumulationFactor() const
{
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (array[i][j]) { k++; }
        }
    }
    return k / (row * col);
}
