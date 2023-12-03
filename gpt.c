#include <stdio.h>
#include <stdlib.h>

// 스택 노드 정의
struct Node {
    int data;
    struct Node* next;
};

// 스택 구조체 정의
struct Stack {
    struct Node* top;
};

// 스택 초기화 함수
void initialize(struct Stack* stack) {
    stack->top = NULL;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// 스택에 값 삽입하는 함수
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 스택에서 값 인출하는 함수
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("queue is Empty!\n");
        return -1;  // 스택이 비어있을 때는 임의의 값(-1) 반환
    }

    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int menu, data;

    do {
        printf("Select menu [(1) push (2) pop (3) exit program] : ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("push data >> ");
                scanf("%d", &data);
                push(&stack, data);
                printf("(%d) push\n", data);
                break;

            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("(%d) pop\n", data);
                }
                break;

            case 3:
                break;

            default:
                printf("Enter the right number!\n");
                break;
        }
    } while (menu != 3);

    return 0;
}
