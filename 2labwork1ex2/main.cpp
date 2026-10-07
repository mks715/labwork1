#include <iostream>
#include <string>
#include "routeCipher.h"

int main()
{
    int choice;

    std::cout << "1. Зашифровать текст" << std::endl;
    std::cout << "2. Расшифровать текст" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите действие: ";
    std::cin >> choice;

    if (choice == 1)
    {
        std::string text;
        int key;

        std::cout << "Введите текст: ";
        std::cin >> text;

        std::cout << "Введите ключ: ";
        std::cin >> key;

        routeCipher cipher(key);

        std::string encrypted = cipher.encrypt(text);

        std::cout << "Зашифрованный текст: "
                  << encrypted << std::endl;
    }
    else if (choice == 2)
    {
        std::string text;
        int key;

        std::cout << "Введите зашифрованный текст: ";
        std::cin >> text;

        std::cout << "Введите ключ: ";
        std::cin >> key;

        routeCipher cipher(key);

        std::string decrypted = cipher.decrypt(text);

        std::cout << "Расшифрованный текст: "
                  << decrypted << std::endl;
    }
    else if (choice == 0)
    {
        std::cout << "Выход из программы." << std::endl;
    }

    return 0;
}