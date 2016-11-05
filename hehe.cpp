#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SWAP(x,y,T) {T t=x;x=y;y=t;}
typedef long long int64;
const int MAX_INT = 0x7fffffff;
using namespace std;
ifstream fin("1156_1.in");
int n;
char type;
char str[1000001];

char stack1[1000001], top = -1;

bool match(char a, char b) {
    switch (a) {
    case '(':
        return b == ')';
    case '[':
        return b == ']';
    case '{':
        return b == '}';
    }
    return false;
}

int main() {
    fin>>str;
    for (char* p = str; *p; p++) {
        if ((*p == '(' )|| (*p == '[') || (*p == '{')) {
            stack1[++top] = *p;
        } else {
            if (!match(stack1[top], *p)) {
                printf("0\n");
                return 0;
            }
            n++;
            top--;
            cout<<top<<endl;
        }
    }
    if (top != -1) {
        printf("0\n");
        return 0;
    }
    printf("%d\n", n);
    return 0;
}
