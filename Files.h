#include <fstream>

#define NOT_STRING_POS_OR_LENGHT (-00100000)

class Files {
private:
    static bool ContainsChar(const std::string& fragment, const char& character, int &position);

    static bool ContainsStr(const std::string &text, const std::string& fragment, int &position, int &lenght);

public:
    static std::string SearchSHA1Hash(std::string hash);
    static void AddSHA1Hash(const std::string& word, const std::string& hash);

    static std::string SearchMD5Hash(std::string hash);
    static void AddMD5Hash(const std::string& word, const std::string& hash);
};
