#include <stdio.h>

int main() {
    int data = 1;
    #ifdef DEBUG {
        data++;
    }
    #endif {
        printf("data = %d", data);
    }
    return 0;
}