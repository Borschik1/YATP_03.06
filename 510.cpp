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
    vector <int> answer = { 1, 0, 3, 0 };
    for (int i = 4; i <= n; i++) {
        answer.push_back(4 * answer[i - 2] - answer[i - 4]);
    }
    fout << answer[n];

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

