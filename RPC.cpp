#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> v;
    int point = 1, data;
    while (cin >> data) {
        if (data >= v.size()) v.resize(data + 1);
        v[data] = data;
        if (v[point] == point) {
            cout << point;
            point ++;
            while (point < v.size() && v[point] == point) cout << ',' <<point ++;
            cout << endl;
        }
    }
    return 0;
}
