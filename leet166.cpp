#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include <sstream>
#include<string.h>
using namespace std;
string fractionToDecimal(int numerator, int denominator) {
        if(!numerator)return "0";
        string ret;
        long long num=abs(numerator),deno=abs(denominator);
        if(numerator<0 ^ denominator<0) ret+='-';
        ret+=char(num/deno);
        if(!(num=num%deno))return ret;
        unordered_map<int,int> m;
        ret+='.';
        while(!m.count(num)){
            m[num]=ret.size();
            while((num*=10)<deno) ret+='0', m[num]=ret.size();
            ret+='0'+num/deno;
            if(!(num=num%deno))return ret;
        }
        ret.insert(m[num],1,'(');
        ret.insert(ret.size(),1,')');
        return ret;
    }
int main() {
    cout<<fractionToDecimal(108, 109)<<endl;
}
