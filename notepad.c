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
LINK createNode(char* name) {
    LINK curr;
    curr = (LINK)malloc(sizeof(NODE));
    if(curr == NULL) {
        printf("Memory allocation problem!\n");
        return NULL;
    }
    curr->name = (char*)malloc(sizeof(char) * (strlen(name) +1));
    strcpy(curr->name, name);
    curr->next = NULL;
    return curr;
}
LINK append(LINK head, LINK curr) {
    LINK nextNode = head;
    if(head == NULL) {
        head = curr;
        return head;
    }
    while(nextNode->next != NULL) {
        nextNode = nextNode->next;
    }
    nextNode->next = curr;
    return head;
}
int printList(LINK head) {
    int cnt = 0;
    LINK nextNode = head;
    while(nextNode != NULL) {
        printf("Node #%d is %s\n", ++cnt, nextNode->name);
        nextNode = nextNode->next;
    }
    return cnt;
}
int main(void) {
    char name[30];
    LINK head = NULL;
    LINK curr;
    printf("Input data >> ");
    while(scanf("%s", name) != NULL) {
        curr = createNode(name);
        if(curr == NULL) {
            printf("Memory allocation problem!");
            return -1;
        }
        head = append(head, curr);
        printList(head);
        printf("Input data >> ");
    }
    return 0;
}
