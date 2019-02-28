#include <bits/stdc++.h>

using namespace std;

bool pp(string &s) {
    unordered_map<char, int> m;

    for (char &c : s) {
        if (c != ' '){
            m[tolower(c)]++;
        }
    }

    bool centerFound = false;
    for (auto e : m) {
        if (e.second % 2) {
            if (centerFound) {
                return false;
            }
            else {
                centerFound = true;
            }
        }
    }
    return true;
}

bool pp2(string &s) {
    unordered_map<char, int> m;

    int oddCount = 0;
    for (char &c : s) {
        if (c != ' ') {
            m[tolower(c)]++;
            if (m[tolower(c)] % 2 == 1) {
                oddCount += 1;
            } else {
                oddCount -= 1;
            }
        }
    }
    return oddCount <= 1;

}

int main() {
    string s = "Tact Cooa";
    cout << pp2(s) << endl;
}