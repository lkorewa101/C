#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
    char* name;
    struct LinkedList* next;
};

typedef struct LinkedList NODE;
typedef NODE* LINK;

LINK createNode(char* name);
LINK append(LINK head, LINK curr);
int printList(LINK head);
LINK insertNode(LINK head, LINK newNode, int position);
LINK deleteNode(LINK head, int position);

LINK createNode(char* name) {
    LINK curr;
    curr = (LINK)malloc(sizeof(NODE));
    if (curr == NULL) {
        printf("Memory allocation problem!\n");
        return NULL;
    }
    curr->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(curr->name, name);
    curr->next = NULL;
    return curr;
}

LINK append(LINK head, LINK curr) {
    LINK nextNode = head;
    if (head == NULL) {
        head = curr;
        return head;
    }
    while (nextNode->next != NULL) {
        nextNode = nextNode->next;
    }
    nextNode->next = curr;
    return head;
}

LINK insertNode(LINK head, LINK newNode, int position) {
    if (position < 1) {
        printf("Enter a valid position (1 or higher)!\n");
        return head;
    }

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    LINK current = head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position exceeds the number of elements in the list!\n");
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

LINK deleteNode(LINK head, int position) {
    if (head == NULL) {
        printf("List is Empty!\n");
        return NULL;
    }

    if (position < 1) {
        printf("Enter a valid position (1 or higher)!\n");
        return head;
    }

    LINK temp, current = head;

    if (position == 1) {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp);
        return head;
    }

    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position exceeds the number of elements in the list!\n");
        return head;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp->name);
    free(temp);
    return head;
}

int main(void) {
    char name[30];
    LINK head = NULL;
    LINK curr;
    int position;

    int menu;
    do {
        printf("Select menu [(1) append (2) delete (3) exit program] : ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Input data >> ");
                scanf("%s", name);
                printf("Input location (1 ~ %d) >> ", printList(head) + 1);
                scanf("%d", &position);
                curr = createNode(name);
                head = insertNode(head, curr, position);
                printList(head);
                break;

            case 2:
                if (head == NULL) {
                    printf("List is Empty!\n");
                    break;
                }
                printf("Delete location (1 ~ %d) >> ", printList(head));
                scanf("%d", &position);
                head = deleteNode(head, position);
                printList(head);
                break;

            case 3:
                break;

            default:
                printf("Enter the right number!\n");
        }
    } while (menu != 3);

    return 0;
}

int printList(LINK head) {
    int cnt = 0;
    LINK nextNode = head;
    while (nextNode != NULL) {
        printf("Node #%d is %s\n", ++cnt, nextNode->name);
        nextNode = nextNode->next;
    }
    return cnt;
}
