/*************************************************************************
	> File Name: EP43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 15时52分45秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
int prime[100] = {7, 2, 3, 5, 7, 11, 13, 17};
int is_pandigital(int64_t x) {
    int vis[10] = {0};
    while (x) {
        vis[x % 10] = 1;
        x /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (vis[i] == 0) return 0;
    }
    return 1;
}
int divisible(int64_t x) {
    int num[11] = {0};
    int count = 10;
    while (x) {
        num[count--] = x % 10;
        x /= 10;
    } 
    for (int i = 2; i <= 8; i++) {
        int temp = num[i] * 100 + num[i + 1] * 10 + num[i + 2];
        if(temp % prime[i - 1] != 0) return 0;
    }
    return 1;
}
int main() {
    int64_t  ans = 0;
    for (int64_t i = 1234567890; i <= 9876543210; i++) {
        if (is_pandigital(i) && divisible(i)) {
            printf("%"PRId64"\n", i);
            ans += i;
        }
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
