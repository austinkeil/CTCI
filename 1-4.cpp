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

int main() {
    string s = "Tact Coa";
    cout << pp(s) << endl;
}