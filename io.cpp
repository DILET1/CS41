#include <bits/stdc++.h>
using namespace std;
int main() {
    string sentence;
    cout << "Enter a sentence";
    getline(cin, sentence);

    stringstream stream(sentence);
    string word;
    while (stream >> word) {
        stringstream conversion(word);
        double value;
        if (conversion >> value) {
            value *= 2;
            cout << value << '\n';
        } else {
            cout << word << '\n';
        }
    }

    return 0;
}
