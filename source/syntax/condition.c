#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    // if(����) { } else { }
    // if(����) { } else if(����) { } else { }

    // break
    // continue

    // &&
    // ||

    // ���� 0 ���� 1 �� 2
    srand(time(NULL));
    int i = rand() % 3;
    if(i == 0) {
        printf("����\n");
    } else if(i == 1) {
        printf("����\n");
    } else if(i == 2) {
        printf("��\n");
    } else {
        printf("?\n");
    }

    // switch-case
    switch(i) {
        case 0:
            printf("����\n"); break;
        case 1:
            printf("����\n"); break;
        case 2:
            printf("��\n"); break;
        default:
            printf("?\n");
    }

    return 0;
}