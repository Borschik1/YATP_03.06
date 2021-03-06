#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int n;
    fin >> n;
    vector <vector<int>> sp(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        string s, s1, s2, s3;
        fin >> s;
        if (s[1] == ':') {
            s1 = s.substr(0, 1);
            s2 = s.substr(2, 2);
            s3 = s.substr(5, 2);
        }
        if (s[1] != ':') {
            s1 = s.substr(0, 2);
            s2 = s.substr(3, 2);
            s3 = s.substr(6, 2);
        }
        int hh = stoi(s1);
        int mm = stoi(s2);
        int ss = stoi(s3);
        sp[i][0] = hh;
        sp[i][1] = mm;
        sp[i][2] = ss;
    }
    sort(sp.begin(), sp.end());
    fout << sp[n / 2 - 1][0] << ":";
    if (sp[n / 2 - 1][1] < 10) {
        fout << 0 << sp[n / 2 - 1][1] << ":";
    }
    else {
        fout << sp[n / 2 - 1][1] << ":";
    }
    if (sp[n / 2 - 1][2] < 10) {
        fout << 0 << sp[n / 2 - 1][2];
    }
    else {
        fout << sp[n / 2 - 1][2];
    }

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

