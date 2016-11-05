 #include<iostream>

 using namespace std;

 int calculate(int A, int B, int C, int D) {
     //pay attention to equal
        if (B <= C) return 0;
        if (A >= D) return 0;
        if (A >= C && B <= D) return B - A;
        if (A <= C && B >= D) return D - C;

        if (A < C)
            return (B > C) ? B - C : C - B;
        else
            return (A > D) ? A - D : D - A;
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l1 = calculate(A, C, E, G);
        int l2 = calculate(B, D, F, H);
        cout<<l1<<endl;
        cout<<l2<<endl;
        return (C - A) * (D - B) + (G - E) * (H - F) - l1 * l2;
    }

int main() {
    cout<<computeArea(-5, -3, 0, 0, -3, -3, 3, 3)<<endl;
}
