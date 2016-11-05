#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

ifstream fin("1127_4.in");
ofstream fout("1127_4.out");
int main() {
    vector<int> v;
    int point = 1, data;
    while (fin >> data) {
        if (data >= v.size()) v.resize(data + 1);
        v[data] = data;
        if (v[point] == point) {
            fout << point;
            point ++;
            while (point < v.size() && v[point] == point) fout << ',' <<point ++;
            fout << endl;
        }
    }
    return 0;
}
