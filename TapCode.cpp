#include <iostream>
#include <string>
#include <map>

using namespace std;
//Enkodimi
map<char, string> tapCodeMap {
    {'A', "11"}, {'B', "12"}, {'C', "13"}, {'D', "14"}, {'E', "15"},
    {'F', "21"}, {'G', "22"}, {'H', "23"}, {'I', "24"}, {'J', "25"},
    {'K', "31"}, {'L', "32"}, {'M', "33"}, {'N', "34"}, {'O', "35"},
    {'P', "41"}, {'Q', "42"}, {'R', "43"}, {'S', "44"}, {'T', "45"},
    {'U', "51"}, {'V', "52"}, {'W', "53"}, {'X', "54"}, {'Y', "55"},
    {'Z', "41"}, {' ', " "} 
};


string encodeTapCode(const string& message) {
    string encodedMessage = "";
    
    for (char c : message) {
   
        if (tapCodeMap.find(toupper(c)) != tapCodeMap.end()) {
            encodedMessage += tapCodeMap[toupper(c)] + " ";
        }
    }
    
    return encodedMessage;
}

//Dekodimi
string decodeTapCode(const string& encodedMessage) {

    map<string, char> tapCodeReverseMap;
    for (auto& pair : tapCodeMap) {
        tapCodeReverseMap[pair.second] = pair.first;
    }

    string decodedMessage = "";
    string tapCodeSegment = "";
    
    for (char c : encodedMessage) {
        if (c == ' ') {
           
            if (!tapCodeSegment.empty()) {
                if (tapCodeReverseMap.find(tapCodeSegment) != tapCodeReverseMap.end()) {
                    decodedMessage += tapCodeReverseMap[tapCodeSegment];
                }
                tapCodeSegment = ""; 
            } else {
    
                decodedMessage += ' ';
            }
        } else {
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
