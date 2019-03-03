#include <bits/stdc++.h>

using namespace std;

bool is_rot(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    if (n1 != n2) return false;

    string s3 = s2.append(s2);
    return s3.find(s2) != string::npos;
}

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout << is_rot(s1, s2);
}