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

int main() {
    string text, grille;
    cout << "Enter the text to encrypt: ";
    getline(cin, text);

    cout << "Enter the grille pattern (16 characters with 'X' for the holes): ";
    getline(cin, grille);

    // Check if the grille pattern is valid
    if (grille.length() != 16) {
        cout << "Invalid grille pattern. It should have exactly 16 characters." << endl;
        return 0;
    }

    string encryptedText = encryptText(text, grille);
    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}
