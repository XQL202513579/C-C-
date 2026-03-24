//车轮筛实际运行速度通常比欧拉筛快
int is_prime(long long n){
if(n<2)
return 0;
if(n==2||n==3)
return 1;
if(n%2==0||n%3==0)
return 0;
long long b=(long long)sqrt(n);
for(long long a=5;a<=b;a+=6){
if(n%a==0||n%(a+2)==0)
return 0;
}
return 1;
}
int is_prime_pro(long long n){
if(n<2)
return 0;
if(n==2||n==3||n==5)
return 1;
if(n%2==0||n%3==0||n%5==0)
return 0;
const int increments[8]={4,2,4,2,4,6,2,6};
long long sqrt_n=(long long)sqrt((double)n);
long long p=7;
int idx=0;
while(p<=sqrt_n){
if(n%p==0)
return 0;
p+=increments[idx];
idx=(idx+1)&7;
}
return 1;
}
int is_prime_mini(int n){
if(n<2)
return 0;
if(n==2||n==3)
return 1;
if(n%2==0||n%3==0)
return 0;
int a=sqrt(n);
for(int i=5;i<=a;i+=6){
if(n%i==0||n%(i+2)==0)
return 0;
}
return 1;
}
#include <stdio.h>
#include <math.h>
#define MAX 10000
int main() {
    int a, b;
    int is_prime[MAX + 1] = {0};
    scanf("%d %d", &a, &b);
    // 优化筛法：欧拉筛（线性筛）
    int primes[MAX], prime_count = 0;
    for (int i = 2; i <= b; i++) {
        if (!is_prime[i]) {
            primes[prime_count++] = i;
        }
        for (int j = 0; j < prime_count && i * primes[j] <= b; j++) {
            is_prime[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    // 对每个数进行分解
    for (int num = a; num <= b; num++) {
        printf("%d=", num);
        int temp = num;
        int first = 1;
        // 分解质因数
        for (int i = 0; i < prime_count && primes[i] * primes[i] <= temp; i++) {
            if (temp % primes[i] == 0) {
                while (temp % primes[i] == 0) {
                    if (!first) {
                        printf("*");
                    }
                    printf("%d", primes[i]);
                    first = 0;
                    temp /= primes[i];
                }
            }
        }
        // 处理最后一个质因子
        if (temp > 1) {
            if (!first) {
                printf("*");
            }
            printf("%d", temp);
        }
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
int main(){
int a,b,c,k;
scanf("%d%d",&a,&b);
if(a==1){
printf("1=1\n");
a++;}
for (int i = a; i <= b; i++)
{
c=i;
printf("%d=",i);
for(int j=2;c!=1;j++){
for(k=2;k<j;k++){
if(j%k==0)
break;
}
if(k<j)
continue;
while(c%j==0){
c=c/j;
printf("%d",j);
if(c!=1)
printf("*");
else
printf("\n");
}
}
}
return 0;
}
#include <stdio.h>
int main() {
    int a, b, i, j;
    scanf("%d %d", &a, &b);
    for (i = a; i <= b; i++) {
        printf("%d=", i);
        int n = i;
        for (j = 2; j <= n; j++) {
            // 当j能整除n时，j一定是质数
            // 因为如果j是合数，它的质因子在前面已经除尽了
            while (n % j == 0) {
                printf("%d", j);
                n /= j;
                if (n != 1) {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
    return 0;
}