#pragma once
#include <iostream>
#include "Graphics.h"
class BinaryImg
{
private:
    bool** array;
    int row;
    int col;
    Graphics* screen;

    void DrawDot(float x, float y) const;
    void DrawBlankDot(float x, float y) const;

public:
    BinaryImg(int x, int y);
    BinaryImg(const BinaryImg& src);
    ~BinaryImg();
    int GetRow() const;
    int GetCol() const;
    void Print() const;
    friend std::ostream& operator<<(std::ostream& os, const BinaryImg& obj);
    int operator==(const BinaryImg& src) const;
    int operator!=(const BinaryImg& src) const;
    bool& operator()(int x, int y);

    bool operator()(int x, int y) const;

    BinaryImg operator+(const BinaryImg& src) const;
    BinaryImg operator*(const BinaryImg& src) const;
    BinaryImg operator+(bool rhs) const; // maybe need to realize this function inside class, to reach "коммутативность"
    BinaryImg operator*(bool rhs) const;
    BinaryImg operator!();
    BinaryImg& operator= (const BinaryImg & src);
    double AccumulationFactor() const;


    friend BinaryImg operator*(bool rhs, const BinaryImg& src);
    friend BinaryImg operator+(bool rhs, const BinaryImg& src);
};
//BinaryImg operator*(bool rhs, const BinaryImg& src);
//BinaryImg operator+(bool rhs, const BinaryImg& src);

class EClassException
{
protected:
    char _err[256];
public:
    EClassException(const char* err);
    virtual void Print();
    virtual ~EClassException();
};
