#include <cstring>
#include <cstdio>
#include <vector>
#include <fstream>
using namespace std;
ifstream fin("test3.in");
ofstream fout("test3.out");
struct Matrix {
    int n;
    vector<vector<int> > a;
    Matrix(int n):n(n) {
        a = vector<vector<int> >(n);
        for (int i = 0;i < n;i++) a[i] = vector<int>(n);
    }
    Matrix(const Matrix& A,int x,int y,int n):n(n) {
        a = vector<vector<int> >(n);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                a[i].push_back(A[i+x][j+y]);
    }
    vector<int>& operator[](int i) {return a[i];}
    const vector<int>& operator[](int i) const {return a[i];}
    void print() const {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n-1;j++)
                fout<<a[i][j]<<" ";
            fout<<a[i][n-1]<<endl;
        }
    }
};
Matrix operator-(const Matrix &A,const Matrix &B) {
    Matrix ans = A;
    for (int i = 0;i < A.n;i++)
        for (int j = 0;j < A.n;j++)
            ans[i][j] -= B[i][j];
    return ans;
}
Matrix operator+(const Matrix &A,const Matrix &B) {
    Matrix ans = A;
    for (int i = 0;i < A.n;i++)
        for (int j = 0;j < A.n;j++)
            ans[i][j] += B[i][j];
    return ans;
}
Matrix operator*(const Matrix &A,const Matrix &B) {
    Matrix ans(A.n);
    if (A.n == 1) {
        ans[0][0] = A[0][0]*B[0][0];
        return ans;
    }
    int m = A.n>>1;
    Matrix A11(A,0,0,m);
    Matrix A12(A,0,m,m);
    Matrix A21(A,m,0,m);
    Matrix A22(A,m,m,m);
    Matrix B11(B,0,0,m);
    Matrix B12(B,0,m,m);
    Matrix B21(B,m,0,m);
    Matrix B22(B,m,m,m);
    Matrix M1 = (A11+A22)*(B11+B22);
    Matrix M2 = (A21+A22)*B11;
    Matrix M3 = A11*(B12-B22);
    Matrix M4 = A22*(B21-B11);
    Matrix M5 = (A11+A12)*B22;
    Matrix M6 = (A21-A11)*(B11+B12);
    Matrix M7 = (A12-A22)*(B21+B22);
    Matrix C11 = M1+M4-M5+M7;
    Matrix C12 = M3+M5;
    Matrix C21 = M2+M4;
    Matrix C22 = M1-M2+M3+M6;
    for (int i = 0;i < m;i++)
        for (int j = 0;j < m;j++) ans[i][j] = C11[i][j];
    for (int i = 0;i < m;i++)
        for (int j = 0;j < m;j++) ans[i][j+m] = C12[i][j];
    for (int i = 0;i < m;i++)
        for (int j = 0;j < m;j++) ans[i+m][j] = C21[i][j];
    for (int i = 0;i < m;i++)
        for (int j = 0;j < m;j++) ans[i+m][j+m] = C22[i][j];
    return ans;
}
int n;
int main() {
    fin>>n;
    Matrix A(n),B(n);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
          fin>>A[i][j];
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            fin>>B[i][j];
    (A*B).print();
    (B*A).print();
    return 0;
}
