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

struct Point {
	int x;
	int y;
};

int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int n, m;
    fin >> n >> m;
    int x, y;
    fin >> x >> y;
    vector <vector <int>> bool_sp;
    for (int i = 0; i < n; i++) {
        vector <int> bool_prov(m);
        for (int j = 0; j < m; j++) {
            bool_prov[j] = 0;
        }
        bool_sp.push_back(bool_prov);
    }
    bool_sp[0][0] = 1;
    int x0 = 0;
    int y0 = 0;
    int flag = 0;
    int flag2 = 0;
    while (true) {
        if (flag == 0) {
            while (y0 < m - 1) {
                if (x0 == x - 1 && y0 == y - 1) {
                    flag2 = 1;
                    break;
                }
                if (bool_sp[x0][y0 + 1] == 0) {
                    bool_sp[x0][y0 + 1] = 1;
                    y0++;
                }
                else {
                    break;
                }
            }
            flag = (flag + 1) % 4;
        }
        //cout << x0 << " " << y0 << endl;
        if (flag == 1) {
            while (x0 < n - 1) {
                if (x0 == x - 1 && y0 == y - 1) {
                    flag2 = 1;
                    break;
                }
                if (bool_sp[x0 + 1][y0] == 0) {
                    bool_sp[x0 + 1][y0] = 1;
                    x0++;
                }
                else {
                    break;
                }
            }
            flag = (flag + 1) % 4;
        }
        //cout << x0 << " " << y0 << endl;
        if (flag == 2) {
            while (y0 > 0) {
                if (x0 == x - 1 && y0 == y - 1) {
                    flag2 = 1;
                    break;
                }
                if (bool_sp[x0][y0 - 1] == 0) {
                    bool_sp[x0][y0 - 1] = 1;
                    y0--;
                }
                else {
                    break;
                }
            }
            flag = (flag + 1) % 4;
        }
        //cout << x0 << " " << y0 << endl;
        if (flag == 3) {
            while (x0 > 0) {
                if (x0 == x - 1 && y0 == y - 1) {
                    flag2 = 1;
                    break;
                }
                if (bool_sp[x0 - 1][y0] == 0) {
                    bool_sp[x0 - 1][y0] = 1;
                    x0--;
                }
                else {
                    break;
                }
            }
            flag = (flag + 1) % 4;
        }
        //cout << x0 << " " << y0 << endl;
        if (flag2 == 1) {
            break;
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bool_sp[i][j] == 1) {
                answer++;
            }
        }
    }
    fout << answer;

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

