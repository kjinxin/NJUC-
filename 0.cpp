#include <cstdio>
#include <cstring>
#include <complex>
#include <cstdlib>
using namespace std;

typedef complex<double> comp;
const int Maxn = 3000;
const double eps = 1e-8;
const comp im(0, -1);
const double pi = acos(-1);

comp a1[Maxn], a2[Maxn], b[Maxn];
int n1, n2, n;

void brp(comp *a, int n)
{
    for (int i = 1, j = n>>1; i < n-1; ++i) {
        if (i < j)
            swap(a[i], a[j]);
        int k = n>>1;
        while (j >= k) {
            j -= k;
            k >>= 1;
        }
        if (j < k)
            j += k;
    }
}

void fft(comp *a, int n, int rev=1)
{
    if (n==1)
        return ;
    brp(a, n);
    for (int s = 2; s <= n; s<<=1) {
        int m = s>>1;
        double tht = rev*2.0*pi/s;
        comp omg(cos(tht), sin(tht));
        for (int k = 0; k < n; k+=s) {
            comp rec(1, 0);
            for (int j = k; j < k+m; ++j) {
                comp t = rec * a[j+m];
                comp u = a[j];
                a[j] = u + t;
                a[j+m] = u - t;
                rec = rec * omg;
            }
        }
    }
}

void ifft(comp *a, int n)
{
    fft(a, n, -1);
    for (int i = 0; i < n; ++i)
        a[i] = a[i] / comp(n, 0);
}

void print(comp *a, int n)
{
    while (n>1 && abs(a[n-1].real()) < eps)
        --n;
    for (int i = 0; i < n; ++i)
        printf("%.6lf ", b[i].real()+1e-8);
    putchar('\n');
}

int main()
{
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    scanf("%d%d", &n1, &n2);
    for (n = 1; n < n1+n2; n<<=1)
        ;
    for (int i = 0; i < n1; ++i) {
        double v;
        scanf("%lf", &v);
        a1[i] = comp(v, 0);
    }
    fft(a1, n);
    for (int i = 0; i < n2; ++i) {
        double v;
        scanf("%lf", &v);
        a2[i] = comp(v, 0);
    }
    fft(a2, n);
    for (int i = 0; i < n; ++i)
        b[i] = a1[i] * a2[i];
    ifft(b, n);

    print(b, n);

    return 0;
}
