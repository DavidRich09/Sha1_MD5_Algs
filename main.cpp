#include "MD5.h"
#include "Sha1.h"

using namespace std;


int main(){

    Sha1 *sha1 = new Sha1;
    cout << "Algoritmo sha1 con un Hola mundo";
    sha1->AlgSha1("hola mundo");

    cout << "Algoritmo md5 con un Hola mundo";
    MD5 *md5 = new MD5("hola mundo");



    return 0;
}