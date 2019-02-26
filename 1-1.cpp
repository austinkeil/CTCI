#include <bits/stdc++.h>

using namespace std;

bool IsUnique1(string &s) {
    set<char> set1;
    for (char &c : s) {
        if (set1.count(c) > 0) {
            return false;
        }
        set1.insert(c);
    }
    return true;
}

bool IsUnique2(string &s) {
    int arr[256];
    for (int &i : arr) {
        i = 0;
    }
    for (char &c: s) {
        arr[c]++;
    }
    for (int &i : arr) {
        if (i > 1) {
            return false;
        }
    }
    return true;
}

bool IsUnique3(string &s) {
    if (s.length() > 128) return false;

    bool arr[256] = {false};
    for (char &c: s) {
        if (arr[c]) {
            return false;
        }
        else {
            arr[c] = true;
        }
    }
    return true;
}

bool IsUnique4(string &s) {
    if (s.length() > 128) return false;

    int checker = 0;
    for (char &c : s) {
        int val = c;
        if ((checker & (1 << val))) {
            return false;
        }
        checker |= (1 << val);
    }
    return true;
}

bool IsUnique5(string &s) {
    if (s.length() > 128) return false;

    bitset<128> checker;
    for (char &c : s) {
        int val = c;
        if (checker.test(val))
            return false;
        checker.set(val);
    }
    return true;
}

// no additional DS
bool IsUnique6(string &s) {
    if (s.length() > 128) return false;

    sort(s.begin(), s.end());
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == s[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "supercali";
    string s2 = "supercaliuu";
    cout << IsUnique6(s1) << endl;
    cout << IsUnique6(s2) << endl;

}