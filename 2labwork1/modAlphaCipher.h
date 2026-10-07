#pragma once
#include <map>
#include <string>
#include <vector>
class modAlphaCipher
{
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
    std::map<wchar_t, int> alphaNum;                        //ассоциативный массив "номер посимволу "
	std::vector<int>key;                                    //
    std::vector<int> convert(const std::wstring& s); //преобразование строка-вектор
    std::wstring convert(const std::vector<int>& v); //преобразование вектор-строка
public:
    modAlphaCipher() = delete; //запретим конструктор без параметров
    modAlphaCipher(const std::string& skey);             //конструктор для установки ключа
    std::string encrypt(const std::string& open_text);   //зашифрование
    std::string decrypt(const std::string& cipher_text); //расшифрование
};