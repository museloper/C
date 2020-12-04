#include <stdio.h>

int main(void) {
    // 포인터

    // [museloper] : 101호 >> 메모리 공간의 주소 
    // [flyingcat] : 201호
    
    // 문 앞에 '암호'가 걸려 있음
    int museloper = 1; 
    int flyingcat = 2;

    printf("museloper 주소 : %d 암호 : %d\n", &museloper, museloper);
    printf("flyingcat 주소 : %d 암호 : %d\n", &flyingcat, flyingcat);
    printf("\n");

    // 미션맨
    int *missionman; // 포인터 변수

    // 첫 번째 미션 : 아파트의 각 집에 방문하여 문에 적힌 암호 확인
    missionman = &museloper;
    printf("미션맨이 방문하는 곳의 주소 : %d, 암호 : %d\n", missionman, *missionman);

    missionman = &flyingcat;
    printf("미션맨이 방문하는 곳의 주소 : %d, 암호 : %d\n", missionman, *missionman);

    // 두 번째 미션 : 각 암호에 3을 곱해라
    missionman = &museloper;
    *missionman = *missionman * 3;
    printf("미션맨이 암호를 바꾼 곳의 주소 : %d, 암호 : %d\n", missionman, *missionman);

    missionman = &flyingcat;
    *missionman = *missionman * 3;
    printf("미션맨이 암호를 바꾼 곳의 주소 : %d, 암호 : %d\n", missionman, *missionman);

    // 스파이
    int *spy;
    printf("\n ... 스파이가 미션을 수행하는 중 ... \n\n");

    // 미션맨이 바꾼 암호에서 2를 빼라
    spy = &museloper;
    *spy = *spy - 2;
    printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", spy, *spy);

    spy = &flyingcat;
    *spy = *spy - 2;
    printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", spy, *spy);

    printf("\n");
    printf("museloper 주소 : %d 암호 : %d\n", &museloper, museloper);
    printf("flyingcat 주소 : %d 암호 : %d\n", &flyingcat, flyingcat);

    // 참고로... 미션맨(스파이)이 사는 곳의 주소는... &미션맨(스파이)으로 확인 가능
    printf("\n ... 미션맨과 스파이의 집 주소는? ... \n\n");
    printf("미션맨의 주소 : %d\n", &missionman);
    printf("스파이의 주소 : %d\n", &spy);

    return 0;
}