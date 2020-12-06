#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

// 물고기가 6마리가 있다.
// 물고기는 어항에 살고, 어항은 사막에 있다.
// 사막이 너무 뜨거워서 물이 아주 빨리 증발을 한다. 
// 물이 다 증발하기 전에 부지런히 어항에 물을 부어서 물고기를 살려야 한다.

int level;
int arrayFish[6];
int *cursor;

int main(void) {
    long startTime = 0; // 게임 시작 시간
    long totalElapsedTime = 0; // 총 경과 시간
    long prevElapsedTime = 0; // 직전 경과 시간(최근에 물을 준 시간 간격)

    int num; // 몇 번 어항에 물을 줄 것인지, 사용자 입력
    initData();

    cursor = arrayFish;

    startTime = clock(); // 현재 시간을 millisecond(1000분의 1초)

    while(1) {
        printfFishes();
        printf("몇 번 어항에 물을 주시겠어요? ");
        scanf("%d", &num);

        // 입력값 체크
        if(num < 1 || num > 6) {
            printf("입력값이 잘못되었습니다.\n");
            continue;
        }

        // 총 경과시간
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
        printf("총 경과 시간 : %ld초\n", totalElapsedTime);

        // 직전 물 준 시간(마지막으로 물 준 시간) 이후로 흐른 시간
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간 : %ld초\n", prevElapsedTime);

        // 어항의 물을 감소(증발)
        decreaseWater(prevElapsedTime);

        // 사용자가 입력한 어항에 물을 준다.
        // 1. 어항의 물이 0이면? 물을 줄 수 없다.
        if(cursor[num - 1] <= 0) {
            printf("%d번 물고기는 이미 죽었습니다. 물을 주지 않습니다.\n", num);
        }
        
        // 2. 어항의 물이 0이 아닌 경우? 물을 준다! 100을 넘지 않는지 체크
        else if(cursor[num - 1] + 1 <= 100) {
            // 물을 준다.
            printf("%d번 어항에 물을 줍니다.\n\n", num);
            cursor[num - 1]++;
        }

        // 레벨업을 할 것인지 확인(레벨업은 20초마다 한 번씩 수행)
        if(totalElapsedTime / 20 > level - 1) {
            // 레벨 UP!
            level++;
            printf(" *** 축 레벨업! 기존 %d레벨에서 %d레벨로 업그레이드 ***\n\n", level - 1, level);

            // 최종 레벨 : 5
            if(level == 5) {
                printf("\n\n축하합니다. 최고 레벨을 달성하였습니다. 게임을 종료합니다.\n\n");
                exit(0);
            }
        }

        // 모든 물고기가 죽었는지 확인
        if(checkFishAlive() == 0) {
            // 물고기가 모두 죽었다. 
            printf("모든 물고기가.. 흑흑 ㅠㅜ..\n");
            exit(0);
        } else {
            //최소 한 마리 이상의 물고기가 살아있다.
            printf("물고기가 아직 살아있어요!\n"); 
        }
        prevElapsedTime = totalElapsedTime;
    }

    return 0;
}

void initData() {
    level = 1; // 게임 레벨(1~5)

    for(int i = 0; i < 6; i++) {
        arrayFish[i] = 100; // 어항의 물 높이(0~100)
    }
}

void printfFishes() {
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
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