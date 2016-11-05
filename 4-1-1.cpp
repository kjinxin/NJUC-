#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("11.txt");
char s[1005];
int f[1005][1005];


int main(){
    int T;
    fin>>T;
    while (T --){
        fin>>s;
        int length = strlen(s);
        for (int i = 0; i < length; i ++) f[i][i] = 1;
        for (int k = 1; k < length; k ++)
        {
            for (int i = 0; i < length - k; i ++){
                f[i][i+k] = f[i][i+k-1] + 1;
                for (int j = i; j < i+k; j ++){
                    if (s[j] == s[i+k]){
                        if (j < i+k-1) {f[i][i+k] += f[j+1][i+k-1]+1; f[i][i+k] %= 10007;}
                        else f[i][i+k] ++;
                    }
                }
            }
        }
        printf("%d\n",f[0][length-1]%10007);
    }
    return 0;
}
