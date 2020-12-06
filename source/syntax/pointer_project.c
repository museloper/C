#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

// ����Ⱑ 6������ �ִ�.
// ������ ���׿� ���, ������ �縷�� �ִ�.
// �縷�� �ʹ� �߰ſ��� ���� ���� ���� ������ �Ѵ�. 
// ���� �� �����ϱ� ���� �������� ���׿� ���� �ξ ����⸦ ����� �Ѵ�.

int level;
int arrayFish[6];
int *cursor;

int main(void) {
    long startTime = 0; // ���� ���� �ð�
    long totalElapsedTime = 0; // �� ��� �ð�
    long prevElapsedTime = 0; // ���� ��� �ð�(�ֱٿ� ���� �� �ð� ����)

    int num; // �� �� ���׿� ���� �� ������, ����� �Է�
    initData();

    cursor = arrayFish;

    startTime = clock(); // ���� �ð��� millisecond(1000���� 1��)

    while(1) {
        printfFishes();
        printf("�� �� ���׿� ���� �ֽðھ��? ");
        scanf("%d", &num);

        // �Է°� üũ
        if(num < 1 || num > 6) {
            printf("�Է°��� �߸��Ǿ����ϴ�.\n");
            continue;
        }

        // �� ����ð�
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
        printf("�� ��� �ð� : %ld��\n", totalElapsedTime);

        // ���� �� �� �ð�(���������� �� �� �ð�) ���ķ� �帥 �ð�
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("�ֱ� ��� �ð� : %ld��\n", prevElapsedTime);

        // ������ ���� ����(����)
        decreaseWater(prevElapsedTime);

        // ����ڰ� �Է��� ���׿� ���� �ش�.
        // 1. ������ ���� 0�̸�? ���� �� �� ����.
        if(cursor[num - 1] <= 0) {
            printf("%d�� ������ �̹� �׾����ϴ�. ���� ���� �ʽ��ϴ�.\n", num);
        }
        
        // 2. ������ ���� 0�� �ƴ� ���? ���� �ش�! 100�� ���� �ʴ��� üũ
        else if(cursor[num - 1] + 1 <= 100) {
            // ���� �ش�.
            printf("%d�� ���׿� ���� �ݴϴ�.\n\n", num);
            cursor[num - 1]++;
        }

        // �������� �� ������ Ȯ��(�������� 20�ʸ��� �� ���� ����)
        if(totalElapsedTime / 20 > level - 1) {
            // ���� UP!
            level++;
            printf(" *** �� ������! ���� %d�������� %d������ ���׷��̵� ***\n\n", level - 1, level);

            // ���� ���� : 5
            if(level == 5) {
                printf("\n\n�����մϴ�. �ְ� ������ �޼��Ͽ����ϴ�. ������ �����մϴ�.\n\n");
                exit(0);
            }
        }

        // ��� ����Ⱑ �׾����� Ȯ��
        if(checkFishAlive() == 0) {
            // ����Ⱑ ��� �׾���. 
            printf("��� ����Ⱑ.. ���� �Ф�..\n");
            exit(0);
        } else {
            //�ּ� �� ���� �̻��� ����Ⱑ ����ִ�.
            printf("����Ⱑ ���� ����־��!\n"); 
        }
        prevElapsedTime = totalElapsedTime;
    }

    return 0;
}

void initData() {
    level = 1; // ���� ����(1~5)

    for(int i = 0; i < 6; i++) {
        arrayFish[i] = 100; // ������ �� ����(0~100)
    }
}

void printfFishes() {
    printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
    for(int i = 0; i < 6; i++) {
        printf(" %4d ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime) {
    for(int i = 0; i < 6; i++) {
        arrayFish[i] -= (level * 3 * (int)elapsedTime);
        if(arrayFish[i] < 0) {
            arrayFish[i] = 0;
        }
    }
}

int checkFishAlive() {
    for(int i = 0; i < 6; i++) {
        if(arrayFish[i] > 0) {
            return 1;
        } else {}
    }
    return 0;
}