#include<string>
#include<iostream>

using namespace std;
string convert(string s, int numRows) {
        string result = s;
        if (numRows == 1) return s;
        int x, y, z, base = 2 * numRows - 2, pos;
        int tx = (s.size() - 1) / base, ty = (s.size() - 1) % base;
        for (int i = 0; i < s.size(); i ++) {
            pos = 0;
            x = i / base;
            y = i % base;
            z = y + 1;
            if (z > numRows) {
                z = 2 * numRows - z;
            }
            if (z > 2) pos += 2 * (z - 2) * tx;
            if (z == 1) {
                pos += x;
            } else {
                pos += tx + x;
                if (z != numRows) pos += x;
            }
            if (x == tx) {
                pos += z;
                if (y + 1 > numRows) pos ++;
                if (ty + 1 > numRows && ty + 1 - 2 * numRows + z > 0) pos +=  ty + 1 - 2 * numRows + z;
            } else {
                if (y + 1 > numRows) pos += 2; else pos ++;
                if (ty + 1 >= z) pos += z - 1; else pos += (ty + 1) % numRows;
                if (ty + 1 > numRows && ty + 1 - 2 * numRows + z > 0) pos +=  ty + 1 - 2 * numRows + z;
            }
            cout<<pos<<endl;
            result[pos - 1] = s[i];
        }
        return result;
    }

int main() {
    string str = "ABCD";
    cout<<convert(str, 3);
}
