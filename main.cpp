#include <array>
#include <cstdint>
#include <iostream>
#include "Sha1.h"
#include "MD5.h"
using namespace std;



int main(){

    std::string data = "Hello World";


    std::string data_hex_digest;

    MD5 *hash = new MD5;
    hash->update(data.begin(), data.end());
    hash->hex_digest(data_hex_digest);

    std::cout << data_hex_digest << std::endl;


    return 0;

}