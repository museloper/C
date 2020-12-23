#include <stdio.h>

struct GameInfo {
    char *name;
    int year;
    int price;
    char *company;

    struct GameInfo *friendGame; // 연관 업체 게임
};

int main(void) {
    
    // 구조체 사용
    struct GameInfo gameInfo1;
    gameInfo1.name = "";
    gameInfo1.year = 2020;
    gameInfo1.price = 50;
    gameInfo1.company = "";

    // 구조체 출력
    printf("-- 게임1 출시 정보 --\n");
    printf("  name    : %s\n", gameInfo1.name);
    printf("  year    : %d\n", gameInfo1.year);
    printf("  price   : %d\n", gameInfo1.price);
    printf("  company : %s\n", gameInfo1.company);

    // 구조체를 배열처럼 초기화
    struct GameInfo gameInfo2 = { "", 2040, 100, "" };

    // 구조체 출력
    printf("\n-- 게임2 출시 정보 --\n");
    printf("  name    : %s\n", gameInfo2.name);
    printf("  year    : %d\n", gameInfo2.year);
    printf("  price   : %d\n", gameInfo2.price);
    printf("  company : %s\n", gameInfo2.company);

    // 구조체 배열
    struct GameInfo gameArray[2] = {
        { "", 2020, 50, "" },
        { "", 2040, 100, "" }
    };

    // 구조체 포인터
    struct GameInfo *gamePrt;

    gamePrt = &gameInfo1; 

    // 구조체 출력
    printf("\n-- 미션맨의 게임 출시 정보 --\n");
    // printf("  name    : %s\n", (*gamePrt).name);
    // printf("  year    : %d\n", (*gamePrt).year);
    // printf("  price   : %d\n", (*gamePrt).price);
    // printf("  company : %s\n", (*gamePrt).company);
    printf("  name    : %s\n", gamePrt->name);
    printf("  year    : %d\n", gamePrt->year);
    printf("  price   : %d\n", gamePrt->price);
    printf("  company : %s\n", gamePrt->company);

    // 연관 업체 게임 소개
    gameInfo1.friendGame = &gameInfo2;

    // 구조체 출력
    printf("\n-- 연관 업체의 게임 출시 정보 --\n");
    printf("  name    : %s\n", gameInfo1.friendGame->name);
    printf("  year    : %d\n", gameInfo1.friendGame->year);
    printf("  price   : %d\n", gameInfo1.friendGame->price);
    printf("  company : %s\n", gameInfo1.friendGame->company);

    return 0;
}