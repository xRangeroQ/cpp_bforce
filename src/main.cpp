#include <iostream>
#include <string>

using namespace std;

int main() {
    const string password = "passhere";
    const string char_set = "01234569qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    
    int length = password.length();
    unsigned long long counter = 0;

    string attempt(length, char_set[0]);

    while (true) {
        if (attempt == password) {
            cout << "Found! " << attempt << endl;
            break;
        }

        counter+=1;

        if (counter%1000000==0) {
            cout << attempt << " - " << counter << endl;
        }

        bool carry = true;
        for (int i = length - 1; i >= 0 && carry; --i) {
            size_t index = char_set.find(attempt[i]);
            if (index+1 < char_set.size()) {
                attempt[i]=char_set[index + 1];
                carry = false;
            } else {
                attempt[i]=char_set[0];
            }
        }
    }
}
