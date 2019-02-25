#include <bits/stdc++.h>

using namespace std;

bool OneEdit(string s1, string s2) {
    if (abs(int(s1.length()) - int(s2.length())) > 1)
        return false;

    bool edited = false;
    if (s1.length() == s2.length()) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                if (edited) {
                    return false;
                }
                else {
                    edited = true;
                }
            }
        }
    }
    else if (s1.length() > s2.length()) {
        for (int i = 0, j = 0; i < s1.length(); i++, j++) {
            if (s1[i] != s2[j]) {
                if (edited) {
                    return false;
                } else {
                    edited = true;
                    j--;
                }
            }
        }
    } else {
        for (int i = 0, j = 0; i < s2.length(); i++, j++) {
            if (s2[i] != s1[j]) {
                if (edited) {
                    return false;
                } else {
                    edited = true;
                    j--;
                }
            }
        }
    }
    return true;
}

int main() {
    cout << OneEdit("pale", "ple") << endl;
    cout << OneEdit("pales", "pale") << endl;
    cout << OneEdit("pale", "bale") << endl;
    cout << OneEdit("pale", "bake") << endl;

}