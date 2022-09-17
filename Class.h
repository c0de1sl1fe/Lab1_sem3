#pragma once
#include <iostream>

class BinaryImg
{
private:
    bool** array;
    int row;
    int col;
public:
    BinaryImg(int x, int y);
    BinaryImg(const BinaryImg& src);
    ~BinaryImg();

    void Print() const;
    friend std::ostream& operator<<(std::ostream& os, const BinaryImg& obj);
    int operator==(const BinaryImg& src) const;
    int operator!=(const BinaryImg& src) const;
    bool& operator()(int x, int y);
    BinaryImg operator+(const BinaryImg& src) const;
    BinaryImg operator*(const BinaryImg& src) const;
    BinaryImg operator+(bool rhs) const; // maybe need to realize this function inside class, to reach "коммутативность"
    BinaryImg operator*(bool rhs) const;
    BinaryImg operator!();
    BinaryImg& operator= (const BinaryImg & src);
    double AccumulationFactor() const;

};