#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BoardSize 15  // 오목판의 크기 정의
#define Empty 0       // 빈 칸을 나타내는 상수
#define Black 1       // 흑돌을 나타내는 상수
#define White 2       // 백돌을 나타내는 상수

// 게임의 시작 화면을 표시하는 함수
void displayIntro();

// 오목판을 출력하는 함수
void printBoard(int board[BoardSize][BoardSize]) {
    printf("\n   ");
    // 오목판의 상단 좌표(1부터 시작)
    for (int i = 0; i < BoardSize; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BoardSize; i++) {
        printf("%2d ", i + 1); // 오목판의 왼쪽 좌표
        for (int j = 0; j < BoardSize; j++) {
            // 오목판의 각 칸 상태에 따라 다른 기호를 출력
            if (board[i][j] == Black) {
                printf(" ○ ");
            }
            else if (board[i][j] == White) {
                printf(" ● ");
            }
            else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

// 승리 판정을 수행하는 함수
int checkWinner(int board[BoardSize][BoardSize]) {
    for (int y = 0; y < BoardSize; y++) {
        for (int x = 0; x < BoardSize; x++) {
            int player = board[y][x];
            if (player != Empty) {
                // 모든 방향(가로, 세로, 대각선)에서 연속 5개의 돌을 확인
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

                        if (count == 5) return player; // 5개 연속 돌이 있으면 승리
                    }
                }
            }
        }
    }
    return Empty; // 승리자 없음
}

// 게임의 주 로직을 수행하는 함수
void playGame() {
    int board[BoardSize][BoardSize] = { Empty }; // 게임판 초기화
    int player = Black; // 현재 플레이어(흑돌 시작)
    int x, y; // 사용자 입력 좌표
    int winner = 0; // 승리자

    while (1) {
        system("cls");
        printBoard(board); // 오목판 출력

        // 플레이어 차례에 따른 안내 메시지
        if (player == Black) {
            printf("흑돌의 차례입니다. (Enter 키를 누를 시 착수됩니다.)\n");
        }
        else {
            printf("백돌의 차례입니다. (Enter 키를 누를 시 착수됩니다.)\n");
        }

        // 사용자로부터 좌표 입력 받기
        scanf("%d %d", &x, &y); // 사용자 입력 좌표

        // 입력 검증 및 보드 업데이트
        if (x >= 1 && x <= BoardSize && y >= 1 && y <= BoardSize && board[x - 1][y - 1] == Empty) {
            board[x - 1][y - 1] = player; // 유효한 수이면 보드에 돌 놓기
        }
        else {
            printf("유효하지 않은 수입니다! 다시 두세요!\n"); // 유효하지 않은 수이면 재시도 요청
            _getch(); // 사용자 입력 대기
            continue; // 다음 반복으로 이동
        }

        winner = checkWinner(board); // 승리자 확인
        if (winner != 0) {
            system("cls");
            printBoard(board); // 최종 게임 보드 출력
            if (winner == Black) {
                printf("흑돌이 이겼습니다!\n"); // 흑돌 승리 메시지
            }
            else if (winner == White) {
                printf("백돌이 이겼습니다!\n"); // 백돌 승리 메시지
            }

            printf("다시 시작하겠습니까? (Y/N)");
            char decision = _getch(); // 사용자 결정 입력 받기

            if (decision == 'Y' || decision == 'y') {
                // 게임판 초기화 및 흑돌로 시작
                for (int i = 0; i < BoardSize; i++) {
                    for (int j = 0; j < BoardSize; j++) {
                        board[i][j] = Empty;
                    }
                }
                player = Black;
                continue; // 게임 재시작
            }
            else {
                break; // 메인 메뉴로 복귀
            }
        }

        player = (player == Black) ? White : Black; // 플레이어 교체
    }
}

// 입력 버퍼를 지우는 함수
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// 게임 시작 화면을 표시하는 함수
void displayIntro() {
    printf("< 오 목  게 임 >\n\n");
    printf("1. 게임 시작\n");
    printf("2. 게임 정보\n");
    printf("3. 게임 종료\n");
    printf("선택: ");
}

// 게임 정보 화면을 표시하는 함수
void displayInfo() {
    system("cls");
    printf("[  조작법  ]\n");
    printf("방향 이동 : 좌표 입력 ( 예 : '8' '8'을 입력하면 중앙값에 입력됩니다.)\n");
    printf("착수 : 스페이스바 ( SPACE BAR )\n\n\n");

    printf("제작사 : 23113910 김성현\n\n\n");
    printf("[  참고 문헌  ]\n\n");
    printf("[1] https://hyomyo.tistory.com/61\n");
    printf("[2] https://www.youtube.com/watch?v=YLP_mcU-LBs&t=619s\n");
    printf("[3] https://makerejoicegames.tistory.com/125\n");
    printf("[4] https://snupi.tistory.com/12\n");
    printf("[5] https://blog.naver.com/3th_october/140166613598\n");
    printf("[6] https://silvermask.tistory.com/17\n");
    printf("[7] https://marinelifeirony.tistory.com/49\n");
    printf("[8] https://individuality.tistory.com/55\n\n");

    // 추가적인 게임 정보 출력
    printf("\n메뉴로 돌아가려면 Enter키를 세 번 누르세요...\n");
    _getch();
    clearBuffer(); // 버퍼 비우기
}

// 메인 함수
int main() {
    char choice;
    while (1) { // 무한 루프
        system("cls");
        displayIntro(); // 게임 시작 화면 표시
        choice = getchar(); // 사용자 선택 입력 받기
        clearBuffer(); // 버퍼 지우기

        if (choice == '1') {
            playGame(); // 게임 시작
            clearBuffer();
        }
        else if (choice == '2') {
            displayInfo(); // 게임 정보 표시
            clearBuffer();
        }
        else if (choice == '3') {
            break; // 게임 종료
        }
    }
    return 0; // 프로그램 종료
}