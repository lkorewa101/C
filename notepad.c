#include <stdio.h>
#include <math.h>
#define PI 3.141592 // PI 값을 상수로 지정

int main() {
    int i = 0;
    int graph = 0;
    double s = 0;

    // sin 그래프 출력
    for (i = 0; i <= 360; i += 30) {
        s = sin((PI * i) / 180.0);
        printf("sin(%3d) %+0.4f", i, s);

        // 그래프 출력을 위해 여유롭게 10칸 이동하여 출력
        for (graph = -10; graph < s * 10; graph++) {
            printf(" ");
        }
        printf("*\n");
    }

    printf("\n"); // sin, cos 그래프 사이의 구분

    // cos 그래프 출력
    for (i = 0; i <= 360; i += 30) {
        s = cos((PI * i) / 180.0);
        printf("cos(%3d) %+0.4f", i, s);

        // 그래프 출력을 위해 여유롭게 10칸 이동하여 출력
        for (graph = -10; graph < s * 10; graph++) {
            printf(" ");
        }
        printf("*\n");
    }

    return 0;
}