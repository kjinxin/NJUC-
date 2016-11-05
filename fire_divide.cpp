#include<iostream>
using namespace std;
class Boat {
   public:
   void set();
   void inverse_pair();
   void print();
   long long inverse_divide(int *, int);
   private:
   int * fire_num;
   int n;
   long long ans;
};
int main()
{
    Boat A;
    A.set();
    A.inverse_pair();
    A.print();
    return 0;
}

void Boat::set(){
    cin >> n;
    fire_num = new int[n]();
    for (int i = 0; i < n; i ++)
        cin >> fire_num[i];
}

long long Boat::inverse_divide(int * fire, int n){
    if (n == 1) return 0;
    int mid = n / 2;
    int* fire1 = new int[mid]();
    int* fire2 = new int[n - mid]();
    for (int i = 0; i < mid; i ++)
        fire1[i] = fire[i];
    for (int i = mid; i < n; i ++)
        fire2[i - mid] = fire[i];
    long long num1 = inverse_divide(fire1, mid);
    long long num2 = inverse_divide(fire2, n - mid);
    long long num = num1 + num2;
    int pointer1 = 0, pointer2 = 0, pointer = 0;
    for (; pointer1 < mid && pointer2 < n - mid; pointer ++){
        if (fire1[pointer1] <= fire2[pointer2]){
            fire[pointer] = fire1[pointer1 ++];
        }
        else{
            fire[pointer] = fire2[pointer2 ++];
            num += mid - pointer1;
        }
    }
    for (; pointer1 < mid;){
        fire[pointer ++] = fire1[pointer1 ++];
    }
    for (; pointer2 < n - mid;){
        fire[pointer ++] = fire2[pointer2 ++];
    }
    delete [] fire1;
    delete [] fire2;
    return num;
}
void Boat::inverse_pair(){
    ans = inverse_divide(fire_num, n);
}

void Boat::print(){
    cout << ans <<endl;
}
