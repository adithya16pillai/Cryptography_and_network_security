#include <iostream>
using namespace std;

string keygen(const string& str, const string& key) {
    string new_key = key;
    for(int i = 0; new_key.size() < str.size(); i++) {
        new_key.push_back(key[i % key.size()]);
    }
    return new_key;
}

string encrypt(const string& str, const string& key) {
    string cipher_text;
    int a = str.size();
    for(int i = 0; i < a; i++) {
        char x = (str[i] - 'a' + key[i] - 'a') % 26 + 'a';
        cipher_text.push_back(x);
    }
    return cipher_text;
}

string decrypt(const string& cipher_text, const string& key) {
    string orig_text;
    int b = cipher_text.size();
    for(int i = 0; i < b; i++) {
        char x = (cipher_text[i] - key[i] + 26) % 26 + 'a';
        orig_text.push_back(x);
    }
    return orig_text;
}

int main() {
    string str, keyw;
    getline(cin, str);
    getline(cin, keyw);
    for(char &c : str) {
        c = tolower(c);
    }
    for(char &c : keyw) {
        c = tolower(c);
    }
    string key = keygen(str, keyw);
    string cipher_text = encrypt(str, key);
    cout << "New key generated: " << key << endl;
    cout << "Encrypted text: " << cipher_text << endl;
    cout << "Decrypted text: " << decrypt(cipher_text, key) << endl;
    return 0;
}