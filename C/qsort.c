//标准库stdlib.h的函数qsort
#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);//升序
}
int main() {
    int arr[] = {9, 3, 7, 1, 5, 8, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), compare_int);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
//函数原型：
//#include <stdlib.h>
//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
//指向要排序数组的第一个元素的指针,void *（通用指针，可以指向任何类型的数据）,可以排序任何类型的数组
//数组中元素的数量（不是字节数）,size_t（无符号整数类型，通常用于表示大小）,通常用 sizeof(arr)/sizeof(arr[0]) 计算
//数组中每个元素的大小（以字节为单位）,size_t,使用 sizeof(元素类型) 或 sizeof(arr[0])
//指向比较函数的指针,int (*compar)：compar是一个函数指针
//(const void *, const void *)：这个函数接受两个const void*参数,返回int：比较结果（负数、0、正数）
//实际上不用常亮可以不加const
#include <stdio.h>
#include <stdlib.h>
// 比较函数
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);//升序
}
int main() {
    int arr[] = {9, 3, 7, 1, 5, 8, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);  // nitems = 9
    // 调用qsort
    qsort(
        arr,          // base: 数组首地址
        n,            // nitems: 元素个数 = 9
        sizeof(int),  // size: 每个元素大小 = sizeof(int)
        compare_int   // compar: 比较函数
    );
    // 输出结果
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
//浮点数：
int compare_float(const void *a, const void *b) {
    float diff = *(float*)a - *(float*)b;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}
//compare函数返回值应该是正负，a-b代表升序，qsort函数设计时使用compare函数，因为要考虑不同类型的数组，
//compare函数使用的是通用指针void*，接着比较或加减时再用类型强转，因为void通用函数只接受不同类型指针，
//但是不告诉编译器读取多少字节，必须要用强转