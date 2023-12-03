#include <stdio.h>

// 함수 원형 선언
int getsum(int n);

int main(void) {
    int max = 0;

    // 양의 정수 입력 받기
    printf("1에서 n까지의 합을 구할 n을 입력하시오. >>");
    scanf("%d", &max);

    // getsum 함수 호출하여 합 구하고 출력
    printf("1에서 %d까지의 합: %d\n", max, getsum(max));

    return 0;
}

// getsum 함수 정의
int getsum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
