#include <stdio.h>
#include <stdlib.h>

// ���� ��� ����
struct Node {
    int data;
    struct Node* next;
};

// ���� ����ü ����
struct Stack {
    struct Node* top;
};

// ���� �ʱ�ȭ �Լ�
void initialize(struct Stack* stack) {
    stack->top = NULL;
}

// ������ ����ִ��� Ȯ���ϴ� �Լ�
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// ���ÿ� �� �����ϴ� �Լ�
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// ���ÿ��� �� �����ϴ� �Լ�
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("queue is Empty!\n");
        return -1;  // ������ ������� ���� ������ ��(-1) ��ȯ
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
