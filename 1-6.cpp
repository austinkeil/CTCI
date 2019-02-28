#include <bits/stdc++.h>

using namespace std;

int compressedSize(const string &s) {
    int lastCount = 0, compressedSize = 0;
    for (int i = 0; i < s.length(); i++) {
        lastCount++;

        if (i+1 >= s.length() || s[i] != s[i+1]){
            compressedSize += 1 + to_string(lastCount).length();
            lastCount = 0;
        }
    }
    return compressedSize;
}

string compress(const string &s) {
    if (compressedSize(s) > s.length()) return s;

    string returnString = "";
    int lastCount = 0;
    for (int i = 0; i < s.length(); i++) {
        lastCount++;

        if (i+1 >= s.length() || s[i] != s[i+1]){
            returnString.append(s[i] + to_string(lastCount));
            lastCount = 0;
        }
    }

    return returnString.length() < s.length() ? returnString : s;
}

int main() {
    cout << compress("aabcccccaaa");};