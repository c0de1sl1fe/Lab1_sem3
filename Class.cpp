#include "Class.h"
#include <math.h>
#include <iostream>
#include "Graphics.h"
#define SCALE 10

void BinaryImg::DrawDot(float x, float y) const
{
    screen->DrawSquare(x, y);
}
void BinaryImg::DrawBlankDot(float x, float y) const
{
    screen->DrawLine(x, y, x + SCALE, y);
    screen->DrawLine(x, y, x, y + SCALE);
    screen->DrawLine(x + SCALE, y, x + SCALE, y + SCALE);
    screen->DrawLine(x, y + SCALE, x + SCALE, y + SCALE);
}


BinaryImg::BinaryImg(int x, int y)
{
    screen = NULL;
    if (x <= 0 || y <= 0) { throw EClassException("invalid dimension"); }
    row = x;
    col = y;
    //screen = new Graphics(((x * SCALE) + 10), ((y * SCALE) + 50));
    array = new bool* [row];
    for (int i = 0; i < row; i++)
    {
        array[i] = new bool[col] {};
    }
    
}
BinaryImg::BinaryImg(const BinaryImg& src)
{
    screen = NULL;
    row = src.row;
    col = src.col;
    //screen = new Graphics((row * SCALE)+ 10, (col * SCALE) + 50);
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
    //delete screen;
}


int BinaryImg::GetRow() const { return row; }
int BinaryImg::GetCol() const { return col; }


void BinaryImg::Print() const
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] ? DrawDot((float)(i * SCALE), (float)(j * SCALE)) : DrawBlankDot((float)(i * SCALE), (float)(j * SCALE));
           //if (!array[i][j]) { DrawBlankDot(i, j); }
        }
        //DrawBlankDot(i+100, i*10);
    }
}

void BinaryImg::Print(int i = 1)
{
    screen = new Graphics((row * SCALE) + SCALE*12, (col * SCALE) + SCALE*12);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] ? DrawDot((float)(i * SCALE), (float)(j * SCALE)) : DrawBlankDot((float)(i * SCALE), (float)(j * SCALE));
        }
    }
    delete screen;
}





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
    if ((x >= row || y >= col) || (x < 0 || y < 0)) 
    { 
        throw EClassException("invalid index");
    }
    return array[x][y];
}

BinaryImg BinaryImg::operator+(const BinaryImg& src) const
{
    if (row != src.row || col != src.col) { throw EClassException("Invalid dimensions of imgs"); }
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
    if (row != src.row || col != src.col) { throw EClassException("Invalid dimensions of imgs"); }
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
    //delete screen;

    row = src.row;
    col = src.col;
    //screen = new Graphics(((row * SCALE) + 10), ((col * SCALE) + 50));
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

//std::ostream& operator<<(std::ostream& os, const BinaryImg& obj)
//{
//    // TODO: insert return statement here
//    //os << "(" << std::endl;
//    for (int i = 0; i < obj.row; i++)
//    {
//        for (int j = 0; j < obj.col; j++)
//        {
//            obj.array[i][j] ? os << "1" : os << ".";
//        }
//        os << std::endl;
//    }
//    //os << ")";
//    return os;
//}

//right print
std::ostream& operator<<(std::ostream& os, BinaryImg& obj)
{
    obj.screen = new Graphics((obj.row * SCALE) + SCALE * 12, (obj.col * SCALE) + SCALE * 12);
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.col; j++)
        {
            obj.array[i][j] ? obj.DrawDot((float)(i * SCALE), (float)(j * SCALE)) : obj.DrawBlankDot((float)(i * SCALE), (float)(j * SCALE));
        }
    }
    delete obj.screen;
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
//friend function
BinaryImg operator+(bool rhs, const BinaryImg& src)
{
    //BinaryImg result(src.GetRow(), src.GetCol());
    //for (int i = 0; i < src.GetRow(); i++)
    //{
    //    for (int j = 0; j < src.GetCol(); j++)
    //    {
    //        result(i,j) = src(i,j) + rhs;
    //    }
    //}
    //return result
    BinaryImg result(src.row, src.col);
    for (int i = 0; i < src.row; i++)
    {
        for (int j = 0; j < src.col; j++)
        {
            result.array[i][j] = src.array[i][j] + rhs;
        }
    }
    return result;
}

//friend functin
BinaryImg operator*(bool rhs, const BinaryImg& src)
{
    //BinaryImg result(src.GetRow(), src.GetCol());
    //for (int i = 0; i < src.GetRow(); i++)
    //{
    //    for (int j = 0; j < src.GetCol(); j++)
    //    {
    //        result(i, j) = src(i, j) * rhs;
    //    }
    //}
    //return result;
    BinaryImg result(src.row, src.col);
    for (int i = 0; i < src.row; i++)
    {
        for (int j = 0; j < src.col; j++)
        {
            result.array[i][j] = src.array[i][j] + rhs;
        }
    }
    return result;

}

EClassException::EClassException(const char* err)
{
    strncpy_s(_err, err, 255);
    _err[255] = 0;
}
void EClassException::Print()
{
    
    std::cout << _err << std::endl;
}
EClassException::~EClassException() {}