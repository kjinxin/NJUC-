#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
struct pp{
    char a[12],b[12];
}p[100010];

int cmp(void const *c,void const *d){
    return strcmp(((pp *)c)->b,((pp *)d)->b);
}

int binarysearch(char s[],int k) {
int low=0,hight=k+1,mid;
    while(low<=hight){
        mid=(low+hight)/2;
        if(strcmp(p[mid].b,s)==0) return mid;
        else if(strcmp(p[mid].b,s)<0) low=mid+1;
        else hight=mid-1;
    }
    return -1;
}



int main() {
char ch,s[12];
int i,k,j,t;
    ch=getchar();i=0;p[0].a[0]=ch;k=-1;
    while(1) {
        k++;
        while(ch!=' ') { p[k].a[i++]=ch; ch=getchar(); }
        p[k].a[++i]='\0';i=0;
        ch=getchar();j=0;
        while(ch!='\n') { p[k].b[j++]=ch;ch=getchar(); }
        p[k].b[j]='\0';j=0;
        ch=getchar();
        if(ch=='\n')break;
    }
    qsort(p,k+1,sizeof(p[0]),cmp);
    while(scanf("%s",s)!=EOF) {
        t=binarysearch(s,k);
        if(t>=0) printf("%s\n",p[t].a);
        else printf("eh\n");
    }
    return 0;
}
