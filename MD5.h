//
// Created by Richmond on 9/6/2021.
//

#ifndef EXTRACLASE4_MD5_H
#define EXTRACLASE4_MD5_H

#include <iostream>
#include <cstring>
#include <vector>
#include "math.h"

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

//#include "Files.h"

using namespace std;



class MD5 {
public:
    MD5(string inputString);
    void Push();
    void Hash(int N);
    string GetHexadecimal(unsigned int num_str);
    void Output();
    ~MD5();
private:
    std::string message;
    unsigned int X[16];
    unsigned int A, B, C, D;
    vector<unsigned char> input;
    long long len;
    unsigned char n[8];
};


#endif //EXTRACLASE4_MD5_H
