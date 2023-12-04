#include <stdio.h>
#include <math.h>

#define PI 3.141592

void printGraph(const char *func, double angle, double value) {
    int graph = 15 + (int)(value * 10);

    printf("%s(%3.0f) %+9.4f", func, angle, value);

    for (int i = 0; i < graph; i++) {
        printf(" ");
    }
    printf("*\n");
}

int main() {
    double angle, sin_val, cos_val;

    // sin 그래프 출력

    for (angle = 0; angle <= 360; angle += 30) {
        sin_val = sin((PI * angle) / 180.0);
        printGraph("sin", angle, sin_val);
    }

    // cos 그래프 출력
    printf("\n");

    for (angle = 0; angle <= 360; angle += 30) {
        cos_val = cos((PI * angle) / 180.0);
        printGraph("cos", angle, cos_val);
    }

    return 0;
}
