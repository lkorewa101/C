#include <stdio.h>
#include <math.h>
#define PI 3.141592 // PI ���� ����� ����

int main() {
    int i = 0;
    int graph = 0;
    double s = 0;

    // sin �׷��� ���
    for (i = 0; i <= 360; i += 30) {
        s = sin((PI * i) / 180.0);
        printf("sin(%3d) %+0.4f", i, s);

        // �׷��� ����� ���� �����Ӱ� 10ĭ �̵��Ͽ� ���
        for (graph = -10; graph < s * 10; graph++) {
            printf(" ");
        }
        printf("*\n");
    }

    printf("\n"); // sin, cos �׷��� ������ ����

    // cos �׷��� ���
    for (i = 0; i <= 360; i += 30) {
        s = cos((PI * i) / 180.0);
        printf("cos(%3d) %+0.4f", i, s);

        // �׷��� ����� ���� �����Ӱ� 10ĭ �̵��Ͽ� ���
        for (graph = -10; graph < s * 10; graph++) {
            printf(" ");
        }
        printf("*\n");
    }

    return 0;
}