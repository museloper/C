#include <stdio.h>

int main(void) {
    // ++
    int pp = 20;
    printf("pp�� %d\n", ++pp);
    printf("pp�� %d\n", pp++);
    printf("pp�� %d\n", pp);

    // �ݺ���
    // for, while, do while
    
    // for(����; ����; ����)
    for(int i = 1; i <= 10; i++) {
        printf("Hello, world! %d\n", i);
    }

    // while(����) { }
    int i = 1;
    while(i <= 10) {
        printf("Hello, world! %d\n", i++);
    }

    // do { } while (����);
    do {
        printf("Hello, world! %d\n", i++);
    } while(i <= 10);

    // 2�� �ݺ���
    for(int i = 1; i <= 3; i++) {
        printf("-ù ��° �ݺ��� : %d\n", i);

        for(int j = 1; j <= 5; j++) {
            printf("--�� ��° �ݺ��� : %d\n", j);
        }
    }

    // ������
    for(int i = 2; i <= 9; i++) {
        printf("%d�� \n", i);
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