//
// Created by Richmond on 8/6/2021.
//

#ifndef EXTRACLASE4_SHA1_H
#define EXTRACLASE4_SHA1_H

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Sha1 {

private:

    vector<int> X;//8*64=512, each subscript stores 8 bits
    int W[80];//32 bits as a group
    int A, B, C, D, E;
    int A1, B1, C1, D1, E1;
    int Turn;

public:

    int S(unsigned int x, int n);
    void append(string m);
    void setW(vector<int> m, int n);
    int ft(int t);
    int Kt(int t);
    void AlgSha1(string text);

};


#endif //EXTRACLASE4_SHA1_H
