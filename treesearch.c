#include<stdio.h>

typedef struct {
    String data;
}
int main()
{

}
public class Singleton {
    private static Singleton uniqueInstance; //静态变量

    private Singleton() {} //私有构造函数

    public static Singleton getInstance() { //静态方法
        if (uniqueInstance == null)
            uniqueInstance = new Singleton();
        return uniqueInstance;
    }

}
