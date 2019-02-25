#include <bits/stdc++.h>

using namespace std;

void URLify(string &s, int length) {
    int shorterNdx = length- 1;
    int longerNdx = static_cast<int>(s.length() - 1);
    while (shorterNdx >= 0) {
        if (s[shorterNdx] == ' ') {
            s[longerNdx--] = '0';
            s[longerNdx--] = '2';
            s[longerNdx] = '%';
        } else {
            s[longerNdx] = s[shorterNdx];
        }
        longerNdx--;
        shorterNdx--;
    }
}

int main() {
    string s = "Mr John Smith    ";
    cout << s << endl;
    URLify(s, 13);
    cout << s << endl;

}