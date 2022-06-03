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

bool Prime(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

bool TriplePrime(vector<int> sp)
{
    bool prov = false;
    for (int i = 0; i < sp.size() - 2; ++i)
    {
        string s = "";
        s += to_string(sp[i]);
        s += to_string(sp[i + 1]);
        s += to_string(sp[i + 2]);

        int tempNumber = stoi(s);
        if (tempNumber >= 100 && Prime(tempNumber)) {
            prov = true;
        }
        else {
            return false;
        }
    }
    return prov;
}

int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int n;
    fin >> n;
    int count = 0;
    for (int i = pow(10, n - 1); i < pow(10, n); i++)
    {
        int number = i;
        int k = n;
        vector<int> sp(k);
        for (int j = k - 1; j >= 0 && number > 0; --j, number /= 10)
        {
            sp[j] = number % 10;
        }
        if (TriplePrime(sp))
            count++;
    }

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

