#include <iostream>
#include <string>

using namespace std;

int main() {
    string inputString;
    cin >> inputString;
    
    int lowercaseMask = 0;
    int uppercaseMask = 0;
    int digitMask = 0;
    
    for(int i = 0; i < inputString.length(); i++) {
        if(inputString[i] >= 'a' && inputString[i] <= 'z') {
            lowercaseMask = lowercaseMask | (1 << (inputString[i] - 'a'));
        }
        else if(inputString[i] >= 'A' && inputString[i] <= 'Z') {
            uppercaseMask = uppercaseMask | (1 << (inputString[i] - 'A'));
        }
        else if(inputString[i] >= '0' && inputString[i] <= '9') {
            digitMask = digitMask | (1 << (inputString[i] - '0'));
        }
    }
    
    if(lowercaseMask == (1 << 26) - 1 && uppercaseMask == (1 << 26) - 1 && digitMask == (1 << 10) - 1) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    return 0;
}
