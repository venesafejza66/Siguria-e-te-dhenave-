#include <iostream>
#include <string>
#include <map>

using namespace std;

// Funksioni për të koduar një mesazh duke përdorur Tap Code
string encodeTapCode(const string& message) {
    // Hartoj një hartë për të konvertuar çdo shkronjë në kodin e Tap Code përkatës
    map<char, string> tapCodeMap {
        {'A', "11"}, {'B', "12"}, {'C', "13"}, {'D', "14"}, {'E', "15"},
        {'F', "21"}, {'G', "22"}, {'H', "23"}, {'I', "24"}, {'J', "25"},
        {'K', "31"}, {'L', "32"}, {'M', "33"}, {'N', "34"}, {'O', "35"},
        {'P', "41"}, {'Q', "42"}, {'R', "43"}, {'S', "44"}, {'T', "45"},
        {'U', "51"}, {'V', "52"}, {'W', "53"}, {'X', "54"}, {'Y', "55"},
        {'Z', "41"}, {' ', " "} // Për hapësirat
    };

    string encodedMessage = "";
    
    for (char c : message) {
        // Përsëriteni karakteret në shenjat e tapit dhe shtojini një hapësirë mes tyre
        if (tapCodeMap.find(toupper(c)) != tapCodeMap.end()) {
            encodedMessage += tapCodeMap[toupper(c)] + " ";
        }
    }
    
    return encodedMessage;
}

// Funksioni për të dekoduar një mesazh duke përdorur Tap Code
string decodeTapCode(const string& encodedMessage) {
    // Hartoj një hartë për të konvertuar kodin e Tap Code në karaktere përkatëse
    map<string, char> tapCodeReverseMap;
    for (auto& pair : tapCodeMap) {
        tapCodeReverseMap[pair.second] = pair.first;
    }

    string decodedMessage = "";
    string tapCodeSegment = "";
    
    for (char c : encodedMessage) {
        if (c == ' ') {
            // Kur takohet një hapësirë, kërkoni kodin e Tap Code të shenjës së takuar dhe dekodoni atë
            if (!tapCodeSegment.empty()) {
                if (tapCodeReverseMap.find(tapCodeSegment) != tapCodeReverseMap.end()) {
                    decodedMessage += tapCodeReverseMap[tapCodeSegment];
                }
                tapCodeSegment = ""; // Rikthehet segmenti i tapit
            } else {
                // Nëse gjej hapësirë, shtoni një hapësirë në mes të dekodimit
                decodedMessage += ' ';
            }
        } else {
            // Nëse nuk është një hapësirë, shtoni karakterin në segmentin e tapit
            tapCodeSegment += c;
        }
    }
    
    return decodedMessage;
}

int main() {
    string message;
    cout << "Shkruani mesazhin për të koduar: ";
    getline(cin, message);

    string encodedMessage = encodeTapCode(message);
    cout << "Mesazhi i koduar me Tap Code: " << encodedMessage << endl;

    string decodedMessage = decodeTapCode(encodedMessage);
    cout << "Mesazhi i dekoduar: " << decodedMessage << endl;

    return 0;
}
