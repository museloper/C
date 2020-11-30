#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    // if(조건) { } else { }
    // if(조건) { } else if(조건) { } else { }

    // break
    // continue

    // &&
    // ||

    // 가위 0 바위 1 보 2
    srand(time(NULL));
    int i = rand() % 3;
    if(i == 0) {
        printf("가위\n");
    } else if(i == 1) {
        printf("바위\n");
    } else if(i == 2) {
        printf("보\n");
    } else {
        printf("?\n");
    }

    // switch-case
    switch(i) {
        case 0:
            printf("가위\n"); break;
        case 1:
            printf("바위\n"); break;
        case 2:
            printf("보\n"); break;
        default:
            printf("?\n");
    }

    return 0;
}