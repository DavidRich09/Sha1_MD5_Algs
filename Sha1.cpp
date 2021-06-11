/**
 * @file SHA1.cpp contiene el código de los métodos de SHA1.
 */

#include "Sha1.h"

using namespace std;

int SHA1::LShift(unsigned int x, int n) {
    return x >> (32 - n) | (x << n);
}

void SHA1::Add(std::string m) {     // creacón del texto
    packets = (m.size() + 8) / 64 + 1;
    xVector.resize(packets * 64);
    int i = 0;
    for (; i < m.size(); i++) {
        xVector[i] = m[i];
    }
    xVector[i++] = 0x80;
    while (i < xVector.size() - 8) {
        xVector[i] = 0;
        i++;
    }
    long long int a = m.size() * 8;
    for (i = xVector.size() - 1; i >= xVector.size() - 8; i--) {
        xVector[i] = a % 256;
        a /= 256;
    }
}

void SHA1::array(std::vector<int> m, int n) {
    n *= 64;
    for (int i = 0; i < 16; i++) {
        W[i] = (m[n + 4 * i] << 24) + (m[n + 4 * i + 1] << 16) + (m[n + 4 * i + 2] << 8) + m[n + 4 * i + 3];
    }
    for (int i = 16; i < 80; i++) {
        W[i] = LShift(W[i - 16] ^ W[i - 14] ^ W[i - 8] ^ W[i - 3], 1);
    }
}

int SHA1::ft(int t) {//ft(pB,pC,pD) function
    if (t < 20)
        return (pB & pC) | ((~pB) & pD);
    else if (t < 40)
        return pB ^ pC ^ pD;
    else if (t < 60)
        return (pB & pC) | (pB & pD) | (pC & pD);
    else
        return pB ^ pC ^ pD;
}

int SHA1::Kt(int t) { //constant K
    if (t < 20)
        return 0x5a827999;
    else if (t < 40)
        return 0x6ed9eba1;
    else if (t < 60)
        return 0x8f1bbcdc;
    else
        return 0xca62c1d6;
}

void SHA1::Run(std::string text) {
    buffa1 = pA = 0x67452301;
    buffb1 = pB = 0xefcdab89;
    buffc1 = pC = 0x98badcfe;
    buffd1 = pD = 0x10325476;
    buffe1 = pE = 0xc3d2e1f0;
    Add(text);

    for (int i = 0; i < packets; i++) {
        array(xVector, i);
        for (int t = 0; t < 80; t++) {
            int temp = pE + ft(t) + LShift(pA, 5) + W[t] + Kt(t);
            pE = pD;
            pD = pC;
            pC = LShift(pB, 30);
            pB = pA;
            pA = temp;
        }
        buffa1 = pA = pA + buffa1;
        buffb1 = pB = pB + buffb1;
        buffc1 = pC = pC + buffc1;
        buffd1 = pD = pD + buffd1;
        buffe1 = pE = pE + buffe1;
    }
    Files::AddSHA1Hash(text, getHashStr());
    cout << "El hash de \"" << text << "\" es " << getHashStr() << std::endl;
}

std::string SHA1::getHashStr() {
    std::stringstream buff1;
    std::stringstream buff2;
    std::stringstream buff3;
    std::stringstream buff4;
    std::stringstream buff5;

    buff1 << std::hex << this->buffa1;
    buff2 << std::hex << this->buffb1;
    buff3 << std::hex << this->buffc1;
    buff4 << std::hex << this->buffd1;
    buff5 << std::hex << this->buffe1;

    return buff1.str() + buff2.str() + buff3.str() + buff4.str() + buff5.str();
}