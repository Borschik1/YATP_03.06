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
	vector <char> alph = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	string s = "a";
	int ind = 1;
	for (int i = 0; i < 25; i++) {
		s = alph[ind] + s + s;
		ind++;
	}
	fout << s[n - 1];

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

