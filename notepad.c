#include <stdio.h>

// �Լ� ���� ����
int getsum(int n);

int main(void) {
    int max = 0;

    // ���� ���� �Է� �ޱ�
    printf("1���� n������ ���� ���� n�� �Է��Ͻÿ�. >>");
    scanf("%d", &max);

    // getsum �Լ� ȣ���Ͽ� �� ���ϰ� ���
    printf("1���� %d������ ��: %d\n", max, getsum(max));

    return 0;
}

// getsum �Լ� ����
int getsum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
