#include <iostream>
#include <iomanip>
#include <numbers>
#include <cmath>  // 用于标准数学函数 sin, cos, log 等
using namespace std;
using namespace numbers;
int main()
{
    // 使用默认的 double 类型常数
    cout <<scientific << setprecision(15); // 设置所有输出为 15 位小数
    // 打印圆周率 π 的值
    cout << "圆周率 pi 的值是: " << numbers::pi << endl;
    // 打印自然对数的底数 e 的值
    cout << "自然常数 e 的值是: " << numbers::e << endl;
    // 打印根号2 (sqrt2) 的值
    cout << "根号2 (sqrt2) 的值是: " << numbers::sqrt2 << endl;
    // 打印根号3 (sqrt3) 的值
    cout << "根号3 (sqrt3) 的值是: " << numbers::sqrt3 << endl;
    // 打印黄金比例 phi 的值
    cout << "黄金比例 phi 的值是: " << numbers::phi << endl;
    // 打印欧拉-马歇罗尼常数 egamma 的值
    cout << "欧拉-马歇罗尼常数 egamma 的值是: " << numbers::egamma << endl;
    // 打印 1/π (inv_pi) 的值
    cout << "1/π (inv_pi) 的值是: " << numbers::inv_pi << endl;
    // 打印 1/√π (inv_sqrtpi) 的值
    cout << "1/√π (inv_sqrtpi) 的值是: " << numbers::inv_sqrtpi << endl;
    // 打印以 2 为底的 e 的对数 log2e 的值
    cout << "以 2 为底的 e 的对数 log2e 的值是: " << numbers::log2e << endl;
    // 打印以 10 为底的 e 的对数 log10e 的值
    cout << "以 10 为底的 e 的对数 log10e 的值是: " << numbers::log10e << endl;
    // 打印 sin(π/2) 的值
    cout << "sin(π/2) 的值是: " << sin(numbers::pi / 2) << endl;
    // 打印 cos(π) 的值
    cout << "cos(π) 的值是: " << cos(numbers::pi) << endl;
    // 打印 ln(e) 的值
    cout << "ln(e) 的值是: " << log(numbers::e) << endl;
    // 演示使用不同的数据类型
    float pi_f = numbers::pi_v<float>;  // 使用 float 类型的 pi
    cout << "\n使用 float 类型的 pi: " << setprecision(7) << pi_f << endl; // 输出 7 位小数
    long double pi_ld = numbers::pi_v<long double>;  // 使用 long double 类型的 pi
    cout << "使用 long double 类型的 pi: " << setprecision(21) << pi_ld << endl; // 输出 21 位小数
    // 计算不同精度的值
    cout << "\nsin(π/2) 使用 double: " << sin(numbers::pi / 2) << endl;
    cout << "sin(π/2) 使用 float: " << sin(static_cast<float>(numbers::pi) / 2) << endl;
    cout << "sin(π/2) 使用 long double: " << sin(static_cast<long double>(numbers::pi) / 2) << endl;
    return 0;
}