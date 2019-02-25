#include <bits/stdc++.h>

using namespace std;

bool IsUnique1(const string &s) {
    set<char> set1;
    for (auto &c : s) {
        if (set1.count(c) > 0) {
            return false;
        }
        set1.insert(c);
    }
    return true;
}

bool IsUnique2(const string &s) {
    int arr[256];
    for (int &i : arr) {
        i = 0;
    }
    for (auto &c: s) {
        arr[c]++;
    }
    for (int &i : arr) {
        if (i > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "supercali";
    string s2 = "supercaliuu";
    cout << IsUnique2(s1) << endl;
    cout << IsUnique2(s2) << endl;

}