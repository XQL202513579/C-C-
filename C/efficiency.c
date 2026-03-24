#include <stdio.h>
#include <stdlib.h>
// 存储操作的结构体
typedef struct {
    int p; // 操作类型 0:前缀降序 1:后缀升序
    int q; // 操作参数
} Op;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    // 栈存储有效操作
    Op* stk = (Op*)malloc((m + 10) * sizeof(Op));
    int top = 0;
    for (int i = 0; i < m; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        if (p == 0) {
            // 处理前缀降序操作
            while (top > 0 && stk[top-1].p == 0) {
                // 连续的前缀操作，保留最大的q
                q = q > stk[top-1].q ? q : stk[top-1].q;
                top--;
            }
            // 如果当前操作覆盖了之前的两次操作，直接丢弃
            while (top >= 2 && stk[top-2].q <= q) {
                top -= 2;
            }
            stk[top].p = 0;
            stk[top].q = q;
            top++;
        } else {
            // 处理后缀升序操作，初始序列是升序，空栈时p=1操作无效
            if (top == 0) continue;
            while (top > 0 && stk[top-1].p == 1) {
                // 连续的后缀操作，保留最小的q
                q = q < stk[top-1].q ? q : stk[top-1].q;
                top--;
            }
            // 如果当前操作覆盖了之前的两次操作，直接丢弃
            while (top >= 2 && stk[top-2].q >= q) {
                top -= 2;
            }
            stk[top].p = 1;
            stk[top].q = q;
            top++;
        }
    }
    int* ans = (int*)malloc((n + 10) * sizeof(int));
    int left = 1, right = n;
    int k = n; // 当前要填充的最大数字
    // 遍历有效操作，固定两端的数字
    for (int i = 0; i < top; i++) {
        int p = stk[i].p;
        int q = stk[i].q;
        if (p == 0) {
            // 前缀降序：填充右侧超出q的位置
            while (right > q && left <= right) {
                ans[right--] = k--;
            }
        } else {
            // 后缀升序：填充左侧小于q的位置
            while (left < q && left <= right) {
                ans[left++] = k--;
            }
        }
        if (left > right) break;
    }
    // 处理剩余的中间区间
    if (top % 2 == 1) {
        // 最后一次是前缀降序，从左到右填充
        while (left <= right) {
            ans[left++] = k--;
        }
    } else {
        // 最后一次是后缀升序，从右到左填充
        while (left <= right) {
            ans[right--] = k--;
        }
    }
    // 输出结果
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    free(stk);
    free(ans);
    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
int upper_int(const void *a, const void *b){
return (*(int*)a - *(int*)b);}
int lower_int(const void *a, const void *b){
return (*(int*)b - *(int*)a);}
int main() {
int n,m;
scanf("%d%d",&n,&m);
int* a=(int*)malloc((n+1)*sizeof(int));
a[0]=-1;
for(int i=1;i<n+1;i++){a[i]=i;}
int b,c;
for(int j=1;j<m+1;j++){
scanf("%d%d",&b,&c);
if(b==0){qsort(&a[1], c, sizeof(int), lower_int);}
else if (b==1){qsort(&a[c],n+1-c, sizeof(int), upper_int);}}
for (int i = 1; i < n+1; i++) {printf("%d ", a[i]);}
return 0;}

豆包的讲解：
问题分析与超时原因
你的代码超时的核心原因是暴力排序的时间复杂度过高：每次操作都调用qsort，时间复杂度为O(m * n log n)。当n和m达到1e5级别时，总操作量会达到1e10级别，远远超过1分钟的时间限制（约1e8次操作/秒）。
同时，大量操作是无效的：连续的同类型操作、被后续操作完全覆盖的操作，都可以提前过滤掉，无需执行排序。
正确解法（AC级，时间复杂度O(n+m)）
这个题是蓝桥杯经典真题「双向排序」，核心优化分为两步：过滤无效操作 + 双指针直接构造最终序列，无需任何排序操作。
步骤1：过滤无效操作
连续的前缀降序（p=0）操作，只保留q最大的那个（大范围会覆盖小范围）。
连续的后缀升序（p=1）操作，只保留q最小的那个（更长的后缀会覆盖短后缀）。
如果当前操作的范围比上一次同类型操作更大，中间的两次操作会被完全覆盖，直接丢弃。
过滤后得到交替的前缀/后缀操作序列，操作数量大幅减少。
步骤2：双指针构造序列
我们发现，每次操作本质是从数组两端向中间固定大数字：
用left/right表示当前未固定的区间边界，k表示当前要填充的最大数字（从n开始递减）。
前缀降序操作：从右往左填充大于q的位置，固定大数字。
后缀升序操作：从左往右填充小于q的位置，固定大数字。
最后处理剩余的中间区间，根据最后一次操作的类型决定填充顺序。

代码说明
过滤操作：用栈存储有效操作，剔除无效操作，保证操作序列是交替的前缀/后缀操作。
双指针构造：无需排序，直接从两端向中间填充数字，时间复杂度O(n + m)，可以轻松处理1e5级别的数据，完全不会超时。
边界处理：初始序列是升序，空栈时后缀升序操作无效，直接跳过。
这个代码可以通过所有测试用例，包括极限数据，完全满足时间限制要求。
*/