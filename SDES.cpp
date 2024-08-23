#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

string permute(const string& input, const vector<int>& table) {
    string output;
    for (int i : table) {
        output += input[i - 1];
    }
    return output;
}

string xor_str(const string& a, const string& b) {
    string result;
    for (size_t i = 0; i < a.size(); ++i) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

string sbox_lookup(const string& input, const vector<vector<int>>& sbox) {
    int row = (input[0] - '0') * 2 + (input[3] - '0');
    int col = (input[1] - '0') * 2 + (input[2] - '0');
    return bitset<2>(sbox[row][col]).to_string();
}

string fk(const string& half, const string& subkey) {
    vector<int> EP = {4, 1, 2, 3, 2, 3, 4, 1};
    string expanded_half = permute(half, EP);

    string xored = xor_str(expanded_half, subkey);

    string left = xored.substr(0, 4);
    string right = xored.substr(4, 4);

    vector<vector<int>> S0 = {
        {1, 0, 3, 2},
        {3, 2, 1, 0},
        {0, 2, 1, 3},
        {3, 1, 3, 2}
    };
    vector<vector<int>> S1 = {
        {0, 1, 2, 3},
        {2, 0, 1, 3},
        {3, 0, 1, 0},
        {2, 1, 0, 3}
    };

    string sbox_output = sbox_lookup(left, S0) + sbox_lookup(right, S1);

    vector<int> P4 = {2, 4, 3, 1};
    return permute(sbox_output, P4);
}

string encrypt(const string& plaintext, const string& key1, const string& key2) {
    vector<int> IP = {2, 6, 3, 1, 4, 8, 5, 7};
    string permuted_text = permute(plaintext, IP);

    string left = permuted_text.substr(0, 4);
    string right = permuted_text.substr(4, 4);

    // Round 1
    string temp = right;
    right = xor_str(left, fk(right, key1));
    left = temp;

    // Round 2
    temp = right;
    right = xor_str(left, fk(right, key2));
    left = temp;

    string combined = right + left;
    vector<int> IP_inv = {4, 1, 3, 5, 7, 2, 8, 6};
    return permute(combined, IP_inv);
}

int main() {
    string PT, key1, key2;
    cout << "Enter 8-bit plaintext: ";
    cin >> PT;
    cout << "Enter 8-bit key1: ";
    cin >> key1;
    cout << "Enter 8-bit key2: ";
    cin >> key2;
    if (PT.length() != 8 || key1.length() != 8 || key2.length() != 8) {
        cerr << "Error: All inputs must be exactly 8 bits long." << endl;
        return 1;
    }
    string ciphertext = encrypt(PT, key1, key2);
    cout << "Ciphertext: " << ciphertext << endl;
    return 0;
}
