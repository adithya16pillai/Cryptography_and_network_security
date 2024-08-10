#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string encrypt_transposition_cipher(const string &plaintext, const string &key) {
    int key_length = key.length();
    int num_rows = (plaintext.length() + key_length - 1) / key_length;  
    string padded_plaintext = plaintext;
    while (padded_plaintext.length() < static_cast<string::size_type>(num_rows * key_length)) {
        padded_plaintext += ' ';  
    }
    vector<string> grid;
    for (int i = 0; i < num_rows; ++i) {
        grid.push_back(padded_plaintext.substr(i * key_length, key_length));
    } 
    vector<int> sorted_key_indices(key_length);
    for (int i = 0; i < key_length; ++i) {
        sorted_key_indices[i] = i;
    }    
    sort(sorted_key_indices.begin(), sorted_key_indices.end(),
         [&key](int i, int j) { return key[i] < key[j]; });
    
    string ciphertext;
    for (int col : sorted_key_indices) {
        for (int row = 0; row < num_rows; ++row) {
            ciphertext += grid[row][col];
        }
    }
    return ciphertext;
}

string decrypt_transposition_cipher(const string &ciphertext, const string &key) {
    int key_length = key.length();
    int num_rows = ciphertext.length() / key_length;
    vector<int> sorted_key_indices(key_length);
    for (int i = 0; i < key_length; ++i) {
        sorted_key_indices[i] = i;
    }
    sort(sorted_key_indices.begin(), sorted_key_indices.end(),
         [&key](int i, int j) { return key[i] < key[j]; });
    
    vector<string> grid(num_rows, string(key_length, '_'));
    int idx = 0;
    for (int col : sorted_key_indices) {
        for (int row = 0; row < num_rows; ++row) {
            grid[row][col] = ciphertext[idx++];
        }
    }
    string plaintext;
    for (const string &row : grid) {
        plaintext += row;
    }
    plaintext.erase(remove(plaintext.begin(), plaintext.end(), '_'), plaintext.end()); 
    return plaintext;
}

int main() {
    string plaintext, key;
    getline(cin, plaintext); // Enter the plaintext
    getline(cin, key); // Enter the key
    string encrypted_text = encrypt_transposition_cipher(plaintext, key); // Encrypt the plaintext
    string decrypted_text = decrypt_transposition_cipher(encrypted_text, key); // Decrypt the ciphertext
    cout << "Encrypted text: " << encrypted_text << endl;
    cout << "Decrypted text: " << decrypted_text << endl;
    
    return 0;
}
