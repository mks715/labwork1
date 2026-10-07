#include <locale>
#include <codecvt>
#include "modAlphaCipher.h"
#include <iostream>

modAlphaCipher::modAlphaCipher(const std::string& skey)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    for(unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(converter.from_bytes(skey));
}

std::string modAlphaCipher::encrypt(const std::string& open_text)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	std::vector<int> work = convert(converter.from_bytes(open_text));
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return converter.to_bytes(convert(work));
}
std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::vector<int> work = convert(converter.from_bytes(cipher_text));
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return converter.to_bytes(convert(work));
}
inline std::vector<int> modAlphaCipher::convert(const std::wstring& s)
{
    std::vector<int> result;
    for(auto c : s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline std::wstring modAlphaCipher::convert(const std::vector<int>& v)
{
    std::wstring result;
    for(auto i : v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}