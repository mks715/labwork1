#pragma once

#include <string>

class routeCipher
{
private:
    int key;

public:
    routeCipher(int k);

    std::string encrypt(const std::string& text);
    std::string decrypt(const std::string& text);
};