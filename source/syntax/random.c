#include <time.h>
#include <stdlib.h> // ���� ���̺귯���� �� ������ ���� �ʴ� ��쿡 ���
#include <stdio.h>

int main(void) {
    // rand() % ���� ����
    int num = rand() % 3; // 0, 1, 2
    
    // ���� �ʱ�ȭ ��
    for(int i = 0; i < 10; i++) {
        printf("%d ", rand() % 10);
    }
    printf("\n");

    // ���� �ʱ�ȭ
    srand(time(NULL));

    // ���� �ʱ�ȭ ��
    for(int i = 0; i < 10; i++) {
        printf("%d ", rand() % 10);
    }
    printf("\n");

    return 0;
}