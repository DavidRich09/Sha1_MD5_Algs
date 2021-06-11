/**
 * @file SHA1.h contiene las declaraciones de los métodos y atributos de SHA1.
 */

#include<iostream>
#include<vector>
#include<string>
#include <iomanip>
#include <sstream>
#include "Files.h"

class SHA1 {
private:
    std::vector<int> xVector;           // 8*64=512, cada elemento almacena 8 bits (int)
    int W[80];                          // grupo de 32 bits
    int pA, pB, pC, pD, pE;             // paquetes
    int buffa1, buffb1, buffc1, buffd1, buffe1; // registros del búffer
    int packets;                        // cantidad de paquetes encriptados

    int LShift(unsigned int x, int n);

    void Add(std::string m);

    void array(std::vector<int> m, int n);

    int ft(int t);

    int Kt(int t);

    std::string getHashStr();


public:
    void Run(std::string text);
};
