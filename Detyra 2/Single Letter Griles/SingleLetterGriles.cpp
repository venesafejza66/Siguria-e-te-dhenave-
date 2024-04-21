#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encryptText(const string& text, const string& grille) {
    vector<vector<char>> grid(4, vector<char>(4, ' '));

    int index = 0;
    // Place the characters from the text into the grid using the grille pattern
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grille[index] == 'X') {
                grid[i][j] = text[index];
            }
            index++;
        }
    }

    string encryptedText;
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            encryptedText += grid[i][j];
        }
    }

    return encryptedText;
}

string generateRandomGrillePattern() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1); // 0 for 'X', 1 for 'O'

    string grillePattern;
    for (int i = 0; i < 16; ++i) {
        if (dis(gen) == 0) {
            grillePattern += 'X';
        } else {
            grillePattern += 'O';
        }
    }
    return grillePattern;
}

int main() {
    string text;
    cout << "Enter the text to encrypt: ";
    getline(cin, text);

    string grillePattern = generateRandomGrillePattern();
    cout << "Generated grille pattern: " << grillePattern << endl;

    string encryptedText = encryptText(text, grillePattern);
    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}
