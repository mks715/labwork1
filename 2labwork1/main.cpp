#include <iostream>
#include "modAlphaCipher.h"

using namespace std;

void check(const string& Text, const string& key)
{
    string cipherText;
    string decryptedText;

    modAlphaCipher cipher(key);

    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);

    cout << "key=" << key << endl;
    cout << Text << endl;
    cout << cipherText << endl;
    cout << decryptedText << endl;

    if (Text == decryptedText)
        cout << "Ok\n";
    else
        cout << "Err\n";
}

int main(int argc, char** argv)
{
    check("ПРИВЕТ", "ЭХОЭХО");

    return 0;
}