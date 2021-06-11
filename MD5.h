//
// Created by Richmond on 9/6/2021.
//

#ifndef EXTRACLASE4_MD5_H
#define EXTRACLASE4_MD5_H

#define sizeArray 64

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

#include <iostream>
#include <cstring>
#include <vector>
#include "Files.h"

using namespace std;

class MD5 {
private:
    std::string message;

public:

    MD5(string message);
    void Push();
    void Hash(int i);
    string GetHex(unsigned int num);
    void Output();

private:

    unsigned int x[16];
    unsigned int a,b,c,d;
    vector<unsigned char> input;
    long long len;
    unsigned char n[8];
    unsigned int t[sizeArray];
    int s[sizeArray];


};


#endif //EXTRACLASE4_MD5_H
