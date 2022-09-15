#pragma once

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
    int operator==(const BinaryImg& src);
    int operator!=(const BinaryImg& src);
    bool& operator()(int x, int y);
    BinaryImg operator+(const BinaryImg& src);
    BinaryImg operator*(const BinaryImg& src);
    BinaryImg operator+(bool rhs); // maybe need to realize this function inside class, to reach "коммутативность"
    BinaryImg operator!();
    int AccumulationFactor() const;

};