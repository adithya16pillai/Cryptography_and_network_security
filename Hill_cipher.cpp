#include <iostream>
#include <vector>
using namespace std;

vector<int> multiplyMatrix(vector<vector<int>> mat, vector<int> vec, int mod) {
    vector<int> result(vec.size(), 0);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            result[i] += mat[i][j] * vec[j];
        }
        result[i] %= mod;
    }
    return result;
}

vector<int> charToNum(string text) {
    vector<int> num(text.length());
    for (int i = 0; i < text.length(); i++) {
        num[i] = text[i] - 'A';
    }
    return num;
}

string numToChar(vector<int> num) {
    string text(num.size(), 'A');
    for (int i = 0; i < num.size(); i++) {
        text[i] = num[i] + 'A';
    }
    return text;
}

int main() {
    string plaintext;
    int size;
    cin >> plaintext; // Enter plaintext (in uppercase)
    size = plaintext.length();
    vector<vector<int>> keyMatrix(size, vector<int>(size));
    vector<vector<int>> inverseKeyMatrix(size, vector<int>(size));
    for (int i = 0; i < size; i++) { // Enter key matrix
        for (int j = 0; j < size; j++) {
            cin >> keyMatrix[i][j];
        }
    }
    for (int i = 0; i < size; i++) { // Enter inverse key matrix
        for (int j = 0; j < size; j++) {
            cin >> inverseKeyMatrix[i][j];
        }
    }
    vector<int> ptNumbers = charToNum(plaintext);

    vector<int> ctNumbers = multiplyMatrix(keyMatrix, ptNumbers, 26);
    string ciphertext = numToChar(ctNumbers);
    cout << "Encrypted text: " << ciphertext << endl;

    vector<int> decryptedNumbers = multiplyMatrix(inverseKeyMatrix, ctNumbers, 26);
    string decryptedText = numToChar(decryptedNumbers);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
