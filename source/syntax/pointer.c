#include <stdio.h>

void swap(int a, int b);
void swap_addr(int *a, int *b);
void changeArray(int *prt);

int main(void) {
    // &는 주소이며, *는 그 주소의 값을 의미한다. 

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

    printf("\n");

    // 배열과 포인터
    int arr[3] = {5, 10, 15};
    int *ptr = arr;
    for(int i = 0; i < 3; i++) {
        printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
    }

    for(int i = 0; i < 3; i++) {
        printf("포인터 ptr[%d]의 값 : %d\n", i, ptr[i]);
    }

    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;
    for(int i = 0; i < 3; i++) {
        printf("배열 arr[%d]의 값 : %d\n", i, arr[i]); // arr[i] == *(arr + i)
    }

    for(int i = 0; i < 3; i++) {
        printf("포인터 ptr[%d]의 값 : %d\n", i, *(ptr + i)); // ptr[i] == *(ptr + i)
    }

    // swap
    int a = 10;
    int b = 20;
    printf("a의 주소 : %d\n", &a);
    printf("a의 주소 : %d\n", &b);

    // Call By Value
    // a와 b의 값을 바꾼다. 
    printf("swap 함수 전 >> a : %d, b : %d\n", a, b);
    swap(a, b);
    printf("swap 함수 후 >> a : %d, b : %d\n", a, b);

    // Call By Reference
    printf("(주소값 전달) swap 함수 전 >> a : %d, b : %d\n", a, b);
    swap_addr(&a, &b);
    printf("(주소값 전달) swap 함수 후 >> a : %d, b : %d\n", a, b);
    
    int arr_prt[3] = {10, 20, 30};
    changeArray(arr_prt);
    for(int i = 0; i < 3; i++) {
        printf("%d\n", arr_prt[i]);
    }

    return 0;
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("swap 함수 내 >> a : %d, b : %d\n", a, b);
}

void swap_addr(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
    printf("(주소값 전달) swap 함수 내 >> a : %d, b : %d\n", *a, *b);
}

void changeArray(int *prt) {
    prt[2] = 40;
}