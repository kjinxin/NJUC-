#include<stdio.h>

int* restrict(int* factor, int dim, int* nele, int variable, int value)
{
    int *num = malloc(sizeof(int) * dim);
    int n = 1;
    int nv = 0;
    for (int i = 0; i < dim; i ++)
    {
        n *= *(nele + i);
        *(num + i) = n;
    }
    int * nfactor = malloc(sizeof(int) * (n / nv));
    for (int i = 0; i < n; i ++)
    {
        if ()
    }
    return nfactor;
}
int main()
{
    return 0;
}
