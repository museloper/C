#include <stdio.h>

int main(void) {
    // ++
    int pp = 20;
    printf("pp는 %d\n", ++pp);
    printf("pp는 %d\n", pp++);
    printf("pp는 %d\n", pp);

    // 반복문
    // for, while, do while
    
    // for(선언; 조건; 증감)
    for(int i = 1; i <= 10; i++) {
        printf("Hello, world! %d\n", i);
    }

    // while(조건) { }
    int i = 1;
    while(i <= 10) {
        printf("Hello, world! %d\n", i++);
    }

    // do { } while (조건);
    do {
        printf("Hello, world! %d\n", i++);
    } while(i <= 10);

    // 2중 반복문
    for(int i = 1; i <= 3; i++) {
        printf("-첫 번째 반복문 : %d\n", i);

        for(int j = 1; j <= 5; j++) {
            printf("--두 번째 반복문 : %d\n", j);
        }
    }

    // 구구단
    for(int i = 2; i <= 9; i++) {
        printf("%d단 \n", i);
        for(int j = 1; j <= 9; j++) {
            printf("%d * %d = %d\n", i, j, i * j);
        }
    }

    // *
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++) {
        for(int j = i; j < 5 - 1; j++) {
            printf(" ");
        }
        for(int k = 0; k < i + 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}