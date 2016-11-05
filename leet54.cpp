#include<iostream>
#include<vector>

using namespace std;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) return result;
        vector<vector<bool>> hash(matrix.size(), vector<bool>(matrix.size(), true));
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int dir = 0, x = 0, y = 0;
        bool o = true;
        while (o) {
            o = false;
            result.push_back(matrix[x][y]);
            cout<<matrix[x][y]<<endl;
            hash[x][y] = false;
            int x_n, y_n, dir_n;
            for (int i = 0; i < 4; i ++) {
               dir_n = (dir + i) % 4;
               x_n = x + dx[dir_n];
               y_n = y + dy[dir_n];
               if (x_n >= 0 && x_n < matrix.size() && y_n >= 0 && y_n <matrix.size() && hash[x_n][y_n]) {
                   x = x_n; y = y_n; dir = dir_n; o = true; break;
               }
            }
        }
        return result;
    }
int main() {
    vector<vector<int>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    spiralOrder(vec);
    return 0;
}
