#include <iostream>
#include <cmath>
using namespace std;
class MyClass {
public:
static int class_var;  // 类作用域变量
};
int MyClass::class_var = 30;
int main() {
cout<<"类变量: " << MyClass::class_var<<endl;
float a=123e-5;
cout<<a<<endl;
const int NUM = 10; // 定义常量 NUM，其值不可修改
const int* ptr = &NUM; // 定义指向常量的指针，指针所指的值不可修改
cout<<ptr<<'\n';
int const* ptr2 = &NUM; // 和上面一行等价
int m=100;
using f=double;
ptr=&m;
cout<<ptr;
f pp;
pp=round(123.112345679545);
printf("%lf",pp);
return 0;
}
/*
#include <iostream>
int main() {
    std::cout << "C++ 标准版本: " << __cplusplus << std::endl;
    return 0;
}
*/