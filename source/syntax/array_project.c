#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    printf("\n\n == �ƺ��� ��Ӹ� ���� == \n\n");
    int answer; // ����� �Է°�;
    srand(time(NULL));
    int treatment = rand() % 4; // �߸��� ����(0-3)
    int cntShowBottle = 0; // �̹� ���ӿ� ������ �� ����
    int prevCntShowBottle = 0; // �� ���ӿ� ������ �� ����

    // 3���� ��ȸ
    for(int i = 1; i <= 3; i++) {
        int bottle[4] = {0, 0, 0, 0}; // 4���� ��
        do {
            cntShowBottle = rand() % 2 + 2; // ������ �� ����
        } while(cntShowBottle == prevCntShowBottle);
        prevCntShowBottle = cntShowBottle;

        int isIncluded = 0; // ������ �� �߿� �߸����� ���ԵǾ����� ���� [0 : ������ | 1 : ����]
        printf(" >> %d ��° �õ� : ", i);

        // ������ �� ������ ����
        for(int j = 0; j < cntShowBottle; j++) {
            int randBottle = rand() % 4; // 0-3

            if(bottle[randBottle] == 0) {
                // ���� ���õ��� ���� ���̸�, ���� ó��
                bottle[randBottle] = 1;
                if(randBottle == treatment) {
                    isIncluded = 1;
                }
            } else {
                // �̹� ���õ� ���̸�, �ߺ��̹Ƿ� �ٽ� ����
                j--;
            }
        }

        // ����ڿ��� ���� ǥ��
        for(int k = 0; k < 4; k++) {
            if(bottle[k] == 1) {
                printf("%d ", k + 1);

            }
        }
        printf("������ �Ӹ��� �ٸ��ϴ�.\n\n");

        if(isIncluded == 1) {
            printf(" >> ����!! �Ӹ��� �����!!\n");
        } else {
            printf(" >> ����!! �Ӹ��� ���� �ʾҾ��.. �Ф�\n");
        }

        printf("\n ... ��� �Ϸ��� �ƹ� Ű�� �������� ... \n");
        getchar();
    }

    printf("\n\n�߸����� �� ���ϱ��? ");
    scanf("%d", &answer);

    if(answer == treatment + 1) {
        printf("\n >> �����Դϴ�!\n");
    } else {
        printf("\n >> ��! Ʋ�Ⱦ��, ������ %d �Դϴ�\n", treatment + 1);
    }

    return 0;
}