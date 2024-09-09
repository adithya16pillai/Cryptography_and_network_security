#include <iostream>

using namespace std;

int P10[] = {3,5,2,7,4,10,1,9,8,6};
int P8[] = {6,3,7,4,8,5,10,9};

void leftShift(int* key,int shifts) {
    int tempLeft[5], tempRight[5];
    for(int i = 0; i < 5; i++) {
        tempLeft[i] = key[i];
        tempRight[i] = key[i+5];
    }
    for(int i = 0; i < 5; i++) {
        key[i] = tempLeft[(i+shifts) % 5];
    }
    for(int i = 0; i < 5; i++) {
        key[i + 5] = tempRight[(i+shifts) % 5];
    }
}

void permute(int* inputKey, int* permutedKey, int* permTable, int tableSize) {
    for(int i = 0; i < tableSize; i++) {
        permutedKey[i] = inputKey[permTable[i] - 1];
    }
}

void generateKeys(string keyStr, int* key1, int* key2) {
    int key[10];
    for(int i = 0; i < 10; i++) {
        key[i] = keyStr[i] - '0';
    }
    int permutedKey[10];
    permute(key, permutedKey, P10, 10);
    leftShift(permutedKey, 1);
    permute(permutedKey, key1, P8, 8);
    leftShift(permutedKey, 2);
    permute(permutedKey, key2, P8, 8);
}

int main() {
    string keyInput; 
    cin >> keyInput;
    if(keyInput.length() != 10) {
        return 1;
    }
    for(char c : keyInput) {
        if(c != '0' && c != '1') {
            return 1;
        }
    }
    int key1[8], key2[8];
    generateKeys(keyInput, key1, key2);
    for(int i = 0; i < 8; i++) {
        cout << key1[i];
    }
    cout << endl;
    for(int i = 0; i < 8; i++) {
        cout << key2[i];
    }
    return 0;
}