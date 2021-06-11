#include "SHA1.h"

using namespace std;

void Test(){

}

int main() {

//    Test();

    string text = "3";
    auto* sha1 = new SHA1;


    while (text != "0") {

        cout << "En cualquier momento puede tocar 0 para salir.\n¿Desea encriptar o desencriptar?\n";
        cout << "1. Encriptar\n2.Desencriptar\n";

        cin >> text;
        if (text == "1") {

            cout << "1. SHA1\n2. MD5\n";
            cin >> text;
            if (text == "1") {
                cout << "Escriba la palabra que desea encriptar: \n";
                cin >> text;
                sha1->Run(text);
            }
        } else if (text == "2") {
            cout << "1. SHA1\n2. MD5\n";
            cin >> text;
            if (text == "1") {
                cout << "Introduzca el hash que desea desencriptar:\n";
                cin >> text;

                std::string word = Files::SearchSHA1Hash(text);
                if (word.empty()) {
                    cout << "El hash no se pudo desencriptar, lo siento.\n";

                } else {
                    cout << "La palabra es: \"" << word << "\".";
                }
            } else if (text == "2") {
                cout << "Introduzca el hash que desea desencriptar:\n";
                cin >> text;

                std::string word = Files::SearchMD5Hash(text);
                if (word.empty()) {
                    cout << "El hash no se pudo desencriptar, lo siento.\n";

                } else {
                    cout << "La palabra es: \"" << word << "\".";
                }
            }
        }
    }
    return 0;
}