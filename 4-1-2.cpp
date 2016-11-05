#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

char s[1005];
long long f[1005][1005];
ifstream fin("11.txt");

int main(){
    int T;
    fin>>T;
    while (T --){
        fin>>s;
        int length = strlen(s);
        for (int i = 0; i < length; i ++) f[i][i] = 1;
        for (int i = 0; i < length - 1; i ++){
            if (s[i] == s[i+1]) f[i][i+1] = 3;
            else f[i][i+1] = 2;
        }
        for (int k = 2; k < length; k ++)
        {
            for (int i = 0; i < length - k; i ++){
                if (s[i] == s[i+k]) f[i][i+k] = (f[i][i+k-1] + f[i+1][i+k] + 1) % 10007;
                else    {
                            f[i][i+k] = (f[i][i+k-1] + f[i+1][i+k] - f[i+1][i+k-1]) % 10007;
                            if (f[i][i+k]<0)
                                    {
                                        cout<<f[i][i+k]<<' '<<i<<' '<<k<<endl;
                                        cout<<f[i][i+k-1]<<' '<<f[i+1][i+k]<<' '<<f[i+1][i+k-1]<<endl;
                                    }
                }
            }
        }
        cout<<f[0][length-1]<<endl;
        printf("%d\n",f[0][length-1]%10007);
    }
    return 0;
}
