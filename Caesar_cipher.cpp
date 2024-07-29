#include <iostream>
using namespace std;

string encrypt(string inputtxt, int key) {
    string ciphertxt = "";
    int size = inputtxt.size();
    for(int i = 0; i < size; i++) {
        if(isupper(inputtxt[i])) {
            ciphertxt += char(int(inputtxt[i] + key - 65)%26+65);
        } else if(islower(inputtxt[i])){
            ciphertxt += char(int(inputtxt[i] + key - 97)%26+97);
        } else if(inputtxt[i] == ' ') {
            ciphertxt += inputtxt[i];
        } else {
            ciphertxt += char(int(inputtxt[i] + key - 48)%10+48);
        }
    }
    return ciphertxt;
}

string decrypt(string ciphertxt, int key) {
    string inputtxt = "";
    int size = ciphertxt.size();
    for(int i = 0; i < size; i++) {
        if(isupper(ciphertxt[i])) {
            inputtxt += char(int(ciphertxt[i] - key - 65)%26+65);
        } else if(islower(ciphertxt[i])) {
            inputtxt += char(int(ciphertxt[i] - key - 97)%26+97);
        } else if(ciphertxt[i] == ' '){
            inputtxt += ciphertxt[i];
        } else {
            inputtxt += char(int(ciphertxt[i] - key - 48)%10+48);
        }
    }
    return inputtxt;
}

int main() {
    string inputtxt;
    int key;
    getline(cin, inputtxt);
    cin >> key;
    string ciphertxt = encrypt(inputtxt, key);
    string decryp = decrypt(ciphertxt, key);
    cout << "Encrypted text: " << ciphertxt << endl;
    cout << "Decrypted text: " << decryp;
    return 0;
}