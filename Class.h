#pragma once
#include <iostream>
#include "Graphics.h"
class BinaryImg
{
private:
    bool** array;
    int row;
    int col;
    void DrawDot(float x, float y) const;
    void DrawBlankDot(float x, float y) const;
    Graphics* screen;

public:
    BinaryImg(int x, int y);
    BinaryImg(const BinaryImg& src);
    ~BinaryImg();
    int GetRow() const;
    int GetCol() const;

    //test prints 
    void Print() const;
    void Print(int i);

    friend std::ostream& operator<<(std::ostream& os, BinaryImg& obj);
    int operator==(const BinaryImg& src) const;
    int operator!=(const BinaryImg& src) const;
    bool& operator()(int x, int y);
    bool operator()(int x, int y) const;
    BinaryImg operator+(const BinaryImg& src) const;
    BinaryImg operator*(const BinaryImg& src) const;
    BinaryImg operator+(bool rhs) const; 
    BinaryImg operator*(bool rhs) const;
    BinaryImg operator!();
    BinaryImg& operator= (const BinaryImg & src);
    double AccumulationFactor() const;
    friend BinaryImg operator*(bool rhs, const BinaryImg& src);
    friend BinaryImg operator+(bool rhs, const BinaryImg& src);
};


class EClassException
{
protected:
    char _err[256];
public:
    EClassException(const char* err);
    virtual void Print();
    virtual ~EClassException();
};
