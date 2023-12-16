#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BoardSize 15  // �������� ũ�� ����
#define Empty 0       // �� ĭ�� ��Ÿ���� ���
#define Black 1       // �浹�� ��Ÿ���� ���
#define White 2       // �鵹�� ��Ÿ���� ���

// ������ ���� ȭ���� ǥ���ϴ� �Լ�
void displayIntro();

// �������� ����ϴ� �Լ�
void printBoard(int board[BoardSize][BoardSize]) {
    printf("\n   ");
    // �������� ��� ��ǥ(1���� ����)
    for (int i = 0; i < BoardSize; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BoardSize; i++) {
        printf("%2d ", i + 1); // �������� ���� ��ǥ
        for (int j = 0; j < BoardSize; j++) {
            // �������� �� ĭ ���¿� ���� �ٸ� ��ȣ�� ���
            if (board[i][j] == Black) {
                printf(" �� ");
            }
            else if (board[i][j] == White) {
                printf(" �� ");
            }
            else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

// �¸� ������ �����ϴ� �Լ�
int checkWinner(int board[BoardSize][BoardSize]) {
    for (int y = 0; y < BoardSize; y++) {
        for (int x = 0; x < BoardSize; x++) {
            int player = board[y][x];
            if (player != Empty) {
                // ��� ����(����, ����, �밢��)���� ���� 5���� ���� Ȯ��
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;

                        int nx = x;
                        int ny = y;
                        int count = 0;

                        for (int i = 0; i < 5; i++) {
                            if (nx >= 0 && nx < BoardSize && ny >= 0 && ny < BoardSize && board[ny][nx] == player) {
                                count++;
                                nx += dx;
                                ny += dy;
                            }
                            else {
                                break;
                            }
                        }

                        if (count == 5) return player; // 5�� ���� ���� ������ �¸�
                    }
                }
            }
        }
    }
    return Empty; // �¸��� ����
}

// ������ �� ������ �����ϴ� �Լ�
void playGame() {
    int board[BoardSize][BoardSize] = { Empty }; // ������ �ʱ�ȭ
    int player = Black; // ���� �÷��̾�(�浹 ����)
    int x, y; // ����� �Է� ��ǥ
    int winner = 0; // �¸���

    while (1) {
        system("cls");
        printBoard(board); // ������ ���

        // �÷��̾� ���ʿ� ���� �ȳ� �޽���
        if (player == Black) {
            printf("�浹�� �����Դϴ�. (Enter Ű�� ���� �� �����˴ϴ�.)\n");
        }
        else {
            printf("�鵹�� �����Դϴ�. (Enter Ű�� ���� �� �����˴ϴ�.)\n");
        }

        // ����ڷκ��� ��ǥ �Է� �ޱ�
        scanf("%d %d", &x, &y); // ����� �Է� ��ǥ

        // �Է� ���� �� ���� ������Ʈ
        if (x >= 1 && x <= BoardSize && y >= 1 && y <= BoardSize && board[x - 1][y - 1] == Empty) {
            board[x - 1][y - 1] = player; // ��ȿ�� ���̸� ���忡 �� ����
        }
        else {
            printf("��ȿ���� ���� ���Դϴ�! �ٽ� �μ���!\n"); // ��ȿ���� ���� ���̸� ��õ� ��û
            _getch(); // ����� �Է� ���
            continue; // ���� �ݺ����� �̵�
        }

        winner = checkWinner(board); // �¸��� Ȯ��
        if (winner != 0) {
            system("cls");
            printBoard(board); // ���� ���� ���� ���
            if (winner == Black) {
                printf("�浹�� �̰���ϴ�!\n"); // �浹 �¸� �޽���
            }
            else if (winner == White) {
                printf("�鵹�� �̰���ϴ�!\n"); // �鵹 �¸� �޽���
            }

            printf("�ٽ� �����ϰڽ��ϱ�? (Y/N)");
            char decision = _getch(); // ����� ���� �Է� �ޱ�

            if (decision == 'Y' || decision == 'y') {
                // ������ �ʱ�ȭ �� �浹�� ����
                for (int i = 0; i < BoardSize; i++) {
                    for (int j = 0; j < BoardSize; j++) {
                        board[i][j] = Empty;
                    }
                }
                player = Black;
                continue; // ���� �����
            }
            else {
                break; // ���� �޴��� ����
            }
        }

        player = (player == Black) ? White : Black; // �÷��̾� ��ü
    }
}

// �Է� ���۸� ����� �Լ�
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// ���� ���� ȭ���� ǥ���ϴ� �Լ�
void displayIntro() {
    printf("< �� ��  �� �� >\n\n");
    printf("1. ���� ����\n");
    printf("2. ���� ����\n");
    printf("3. ���� ����\n");
    printf("����: ");
}

// ���� ���� ȭ���� ǥ���ϴ� �Լ�
void displayInfo() {
    system("cls");
    printf("[  ���۹�  ]\n");
    printf("���� �̵� : ��ǥ �Է� ( �� : '8' '8'�� �Է��ϸ� �߾Ӱ��� �Էµ˴ϴ�.)\n");
    printf("���� : �����̽��� ( SPACE BAR )\n\n\n");

    printf("���ۻ� : 23113910 �輺��\n\n\n");
    printf("[  ���� ����  ]\n\n");
    printf("[1] https://hyomyo.tistory.com/61\n");
    printf("[2] https://www.youtube.com/watch?v=YLP_mcU-LBs&t=619s\n");
    printf("[3] https://makerejoicegames.tistory.com/125\n");
    printf("[4] https://snupi.tistory.com/12\n");
    printf("[5] https://blog.naver.com/3th_october/140166613598\n");
    printf("[6] https://silvermask.tistory.com/17\n");
    printf("[7] https://marinelifeirony.tistory.com/49\n");
    printf("[8] https://individuality.tistory.com/55\n\n");

    // �߰����� ���� ���� ���
    printf("\n�޴��� ���ư����� EnterŰ�� �� �� ��������...\n");
    _getch();
    clearBuffer(); // ���� ����
}

// ���� �Լ�
int main() {
    char choice;
    while (1) { // ���� ����
        system("cls");
        displayIntro(); // ���� ���� ȭ�� ǥ��
        choice = getchar(); // ����� ���� �Է� �ޱ�
        clearBuffer(); // ���� �����

        if (choice == '1') {
            playGame(); // ���� ����
            clearBuffer();
        }
        else if (choice == '2') {
            displayInfo(); // ���� ���� ǥ��
            clearBuffer();
        }
        else if (choice == '3') {
            break; // ���� ����
        }
    }
    return 0; // ���α׷� ����
}