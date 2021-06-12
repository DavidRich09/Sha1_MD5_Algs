#ifndef EXTRACLASE4_FILES_H
#define EXTRACLASE4_FILES_H

#include <fstream>
#include <string>

#define NOT_STRING_POS_OR_LENGHT (-00100000)

class Files {
private:
    static bool ContainsStr(const std::string &text, const std::string& fragment, int &position, int &lenght);

public:
    static std::string SearchSHA1Hash(const std::string& hash);
    static void AddSHA1Hash(const std::string& word, const std::string& hash);

    static std::string SearchMD5Hash(const std::string& hash);
    static void AddMD5Hash(const std::string& word, const std::string& hash);
};


#endif //EXTRACLASE4_FILES_H
