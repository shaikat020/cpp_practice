#include <iostream>
#include <string>

using namespace std;

void replacePattern(string& text, const string& patternP, const string& patternQ) {
    int pos = 0;
    while ((pos = text.find(patternP, pos)) != string::npos) {
        text.replace(pos, patternP.length(), patternQ);
        pos += patternQ.length();
    }
}

int main() {
    string text = "The quick brown fox jumps over the lazy dog.The fox is quick";
    string patternP = "quick";
    string patternQ = "C";

    cout << "Original text: " << text << endl;
    replacePattern(text, patternP, patternQ);
    cout << "Text after replacement: " << text << endl;

    return 0;
}
