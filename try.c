#include<stdio.h>

int main()
{
    struct dd {
        enum {var, tvar, cons, func, label} kind;
    };

    struct dd t;
    t.kind = func;
    printf("%d", t.kind);
}
