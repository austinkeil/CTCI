#include <bits/stdc++.h>

using namespace std;

bool IsPermutation(const string &s1, const string &s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    int arr[256];
    for (int &i : arr) {
        i = 0;
    }

    for (int i = 0; i < s1.length(); i++) {
        arr[s1[i]]++;
        arr[s2[i]]--;
    }

    for (int &i: arr) {
        if (i > 0) return false;
    }
    return true;

}

int main() {
    cout << IsPermutation("hello","olleh") << endl;
    cout << IsPermutation("hi", "hil") << endl;
    cout << IsPermutation("yo", "no") << endl;
}