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
    int summa = 0;
    int maxi = 0;
    int current;
    for (int i = 0; i < n; ++i) {
        fin >> current;
        summa += current;
        maxi = max(maxi, current);
    }

    fout << min(summa / 2, summa - maxi);

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

