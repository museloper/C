#include <stdio.h>

struct GameInfo {
    char *name;
    int year;
    int price;
    char *company;

    struct GameInfo *friendGame; // ���� ��ü ����
};

int main(void) {
    
    // ����ü ���
    struct GameInfo gameInfo1;
    gameInfo1.name = "";
    gameInfo1.year = 2020;
    gameInfo1.price = 50;
    gameInfo1.company = "";

    // ����ü ���
    printf("-- ����1 ��� ���� --\n");
    printf("  name    : %s\n", gameInfo1.name);
    printf("  year    : %d\n", gameInfo1.year);
    printf("  price   : %d\n", gameInfo1.price);
    printf("  company : %s\n", gameInfo1.company);

    // ����ü�� �迭ó�� �ʱ�ȭ
    struct GameInfo gameInfo2 = { "", 2040, 100, "" };

    // ����ü ���
    printf("\n-- ����2 ��� ���� --\n");
    printf("  name    : %s\n", gameInfo2.name);
    printf("  year    : %d\n", gameInfo2.year);
    printf("  price   : %d\n", gameInfo2.price);
    printf("  company : %s\n", gameInfo2.company);

    // ����ü �迭
    struct GameInfo gameArray[2] = {
        { "", 2020, 50, "" },
        { "", 2040, 100, "" }
    };

    // ����ü ������
    struct GameInfo *gamePrt;

    gamePrt = &gameInfo1; 

    // ����ü ���
    printf("\n-- �̼Ǹ��� ���� ��� ���� --\n");
    // printf("  name    : %s\n", (*gamePrt).name);
    // printf("  year    : %d\n", (*gamePrt).year);
    // printf("  price   : %d\n", (*gamePrt).price);
    // printf("  company : %s\n", (*gamePrt).company);
    printf("  name    : %s\n", gamePrt->name);
    printf("  year    : %d\n", gamePrt->year);
    printf("  price   : %d\n", gamePrt->price);
    printf("  company : %s\n", gamePrt->company);

    // ���� ��ü ���� �Ұ�
    gameInfo1.friendGame = &gameInfo2;

    // ����ü ���
    printf("\n-- ���� ��ü�� ���� ��� ���� --\n");
    printf("  name    : %s\n", gameInfo1.friendGame->name);
    printf("  year    : %d\n", gameInfo1.friendGame->year);
    printf("  price   : %d\n", gameInfo1.friendGame->price);
    printf("  company : %s\n", gameInfo1.friendGame->company);

    return 0;
}