#include <iostream>
#include <iomanip>

using namespace std;

unsigned char SBox[256] = {
    0x80, 0x68, 0x2D, 0xE0
};

void RotWord(unsigned char* word) {
    unsigned char temp = word[0];
    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = temp;
}

void SubWord(unsigned char* word) {
    for (int i = 0; i < 4; ++i) {
        if (word[i] == 0x3A) word[i] = SBox[0];
        else if (word[i] == 0xF7) word[i] = SBox[1];
        else if (word[i] == 0xFA) word[i] = SBox[2];
        else if (word[i] == 0xA0) word[i] = SBox[3];
    }
}

void XORWords(unsigned char* word1, unsigned char* word2, unsigned char* result) {
    for (int i = 0; i < 4; ++i) {
        result[i] = word1[i] ^ word2[i];
    }
}

void PrintKey(unsigned char key[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << "0x" << hex << setw(2) << setfill('0') << (int)key[i][j];
            if (j != 3) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned char secondRoundKey[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            unsigned int temp;
            cin >> hex >> temp;
            secondRoundKey[j][i] = static_cast<unsigned char>(temp);
        }
    }

    unsigned char Rcon[4] = {0x04, 0x00, 0x00, 0x00};

    unsigned char thirdRoundKey[4][4];

    unsigned char tempWord[4];
    for (int i = 0; i < 4; ++i) {
        tempWord[i] = secondRoundKey[i][3];
    }
    
    RotWord(tempWord);
    SubWord(tempWord);
    tempWord[0] ^= Rcon[0];

    XORWords(tempWord, secondRoundKey[0], thirdRoundKey[0]);

    for (int i = 1; i < 4; ++i) {
        XORWords(thirdRoundKey[i - 1], secondRoundKey[i], thirdRoundKey[i]);
    }
    PrintKey(thirdRoundKey);  // Print the third-round key 

    return 0;
}
