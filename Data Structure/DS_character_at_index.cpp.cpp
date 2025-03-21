 #include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "HIS FATHER IS THE PROFESSOR";
    int index = 7;

    if (index >= 0 && index < str.length()) {
        //char element = str[index];
        cout << "The character at index " << index << " is: " << str[index] << endl;
    } else {
        cout << "Index out of range." << endl;
    }

    return 0;
}
