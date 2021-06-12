//
// Created by lujim on 11/6/2021.
//

#include "Files.h"

bool Files::ContainsStr(const std::string &text, const std::string &fragment, int &position, int &lenght) {
    int fragIter = 0;                        // initializes fragment iterator
    lenght = fragment.length();             // asigns length to fragment lenght
    for (int i = 0; i < text.length(); i++){

        if (text.at(i) == fragment.at(fragIter)){

            if (fragIter == 0) position = i;

            fragIter++;

        } else { position = NOT_STRING_POS_OR_LENGHT; fragIter = 0; }

        if (fragIter == lenght) return true;
    }

    lenght = NOT_STRING_POS_OR_LENGHT;
    return false;
}

std::string Files::SearchSHA1Hash(const std::string &hash) {
    int position = NOT_STRING_POS_OR_LENGHT;
    int length = NOT_STRING_POS_OR_LENGHT;

    std::string line;
    std::ifstream file ("../sha1.txt");
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (ContainsStr(line, hash, position, length)) {
                file.close();
                return line.substr(0,position);
            }
        }
    } else {} // couldn't open file

    return std::string();
}

void Files::AddSHA1Hash(const std::string &word, const std::string &hash) {
    std::ifstream rfile ("../sha1.txt");
    std::string ftext;

    std::string line;
    if (rfile.is_open()) {
        while (std::getline(rfile, line)) {
            ftext += line + "\n";
        }
    } else {} // couldn't open file

    std::ofstream file ("../sha1.txt");

    if (file.is_open()){
        ftext += word + hash;
        file << ftext << "\n";
        file.close();

    } else {} // couldn't open file
}

std::string Files::SearchMD5Hash(const std::string& hash) {
    int position = NOT_STRING_POS_OR_LENGHT;
    int length = NOT_STRING_POS_OR_LENGHT;

    std::string line;
    std::ifstream file ("../md5.txt");
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (ContainsStr(line, hash, position, length)) {
                file.close();
                return line.substr(0,position);
            }
        }
    } else {} // couldn't open file

    return std::string();
}

void Files::AddMD5Hash(const std::string &word, const std::string &hash) {
    std::ifstream rfile ("../md5.txt");
    std::string ftext;

    std::string line;
    if (rfile.is_open()) {
        while (std::getline(rfile, line)) {
            ftext += line + "\n";
        }
    } else {} // couldn't open file

    std::ofstream file ("../md5.txt");

    if (file.is_open()){
        ftext += word + hash;
        file << ftext << "\n";
        file.close();

    } else {} // couldn't open file
}
