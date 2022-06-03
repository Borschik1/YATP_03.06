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
    
    string s1, s2;
    fin >> s1 >> s2;
    int mini = (int)s1.size() + (int)s2.size(), position;
    for (position = -(int)s2.size(); position <= (int)s1.size(); position++) {
        int prov = 1;
        int left = min(position, 0);
        int rigth = max((int)s1.size() - 1, position + (int)s2.size() - 1);

        for (int i = left; i <= rigth; i++) {
            int s1_Temp;
            if (0 <= i && i < (int)s1.size()) {
                s1_Temp = s1[i] - '0';
            }
            else {
                s1_Temp = 1;
            }
            int s2_Temp;
            if (position <= i && i < position + (int)s2.size()) {
                s2_Temp = s2[i - position] - '0';
            }
            else {
                s2_Temp = 1;
            }

            if (s1_Temp + s2_Temp > 3)
            {
                prov = 0;
                break;
            }
        }

        if (prov == 1) {
            int len = rigth - left + 1;
            if (len < mini)
                mini = len;
        }
    }

    fout << mini;

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

