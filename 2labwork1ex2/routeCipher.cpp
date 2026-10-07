#include <locale>
#include <codecvt>
#include <vector>
#include "routeCipher.h"

routeCipher::routeCipher(int k)
{
    key = k;
}

std::string routeCipher::encrypt(const std::string& text)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wideText = converter.from_bytes(text);

    int rows = (wideText.size() + key - 1) / key;

    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(key, L' '));

    int index = 0;

    // Заполняем таблицу слева направо, сверху вниз
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < key; j++)
        {
            if (index < wideText.size())
            {
                table[i][j] = wideText[index];
                index++;
            }
        }
    }

    std::wstring result;

    // Считываем таблицу сверху вниз, справа налево
    for (int j = key - 1; j >= 0; j--)
    {
        for (int i = 0; i < rows; i++)
        {
            if (table[i][j] != L' ')
            {
                result += table[i][j];
            }
        }
    }

    return converter.to_bytes(result);
}

std::string routeCipher::decrypt(const std::string& text)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wideText = converter.from_bytes(text);

    int rows = (wideText.size() + key - 1) / key;
    int remainder = wideText.size() % key;

    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(key, L' '));

    int index = 0;

    // Заполняем таблицу по маршруту считывания шифртекста
    for (int j = key - 1; j >= 0; j--)
    {
        for (int i = 0; i < rows; i++)
        {
            // В последней строке существуют только первые remainder столбцов
            if (i == rows - 1 && remainder != 0 && j >= remainder)
            {
                continue;
            }

            if (index < wideText.size())
            {
                table[i][j] = wideText[index];
                index++;
            }
        }
    }

    std::wstring result;

    // Считываем таблицу слева направо, сверху вниз
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < key; j++)
        {
            if (table[i][j] != L' ')
            {
                result += table[i][j];
            }
        }
    }

    return converter.to_bytes(result);
}