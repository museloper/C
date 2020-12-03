#include <stdio.h>

int main(void) {
    // 배열(여러 개의 변수를 동시에 생성)
    int subway_array[3];

    subway_array[0] = 10;
    subway_array[1] = 20;
    subway_array[2] = 30;

    for(int i = 0; i < 3; i++) {
        printf("지하철 %d호차에 %d명이 타고 있습니다.\n", i+1, subway_array[i]);
    }

    // 값 설정 방법
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // 만약에 배열을 선언만 하고 값을 초기화 하지 않으면?
    int arr_dummy[10];
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr_dummy[i]);
    }

    printf("\n");

    // 배열의 일부만 초기화 한다면?
    int arr_part[10] = {1, 2, 3};
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr_part[i]);
    }

    int arr_blank[] = {1, 2, 3, 4, 5}; // arr[5]

    printf("\n");

    // 문자 vs 문자열
    char c = 'A';
    printf("%c\n", c);

    // 문자열 끝에는 '끝'을 의미하는 NULL 문자 '\0'이 포함되어야 한다.
    char str[7] = "coding"; // [c][o][d][i][n][g][\0]
    printf("%s\n", str);

    char str_blank[] = "coding";
    printf("%s\n", str_blank);
    printf("%d\n", sizeof(str_blank));

    for(int i = 0; i < sizeof(str_blank); i++) {
        printf("%c\n", str_blank[i]);
    }

    // 영어는 한 글자 : 1 byte
    // 한글은 한 글자 : 2 byte
    char kor[] = "뮤젤로퍼";
    printf("%s\n", kor);
    printf("%d\n", sizeof(kor)); // 9

    // ASCII 코드
    printf("아스키코드\n");
    for(int i = 0; i < sizeof(str_blank); i++) {
        printf("%d\n", str_blank[i]);
    }

    // ASCII 코드란? ANSI(미국표준협회)에서 제시한 표준 코드 체계
    // 7bit, 총 128개 코드(0-127)
    // a : 97
    // A : 65
    // 0 : 48

    printf("아스키코드\n");
    printf("%c\n", 'a');
    printf("%d\n", 'a');

    printf("%c\n", 'A');
    printf("%d\n", 'A');

    printf("%c\n", '0');
    printf("%d\n", '0');

    // 0-127 사이의 아스키코드 정수값에 해당하는 문자 확인
    for(int i = 0; i < 128; i++) {
        printf("아스키코드 정수 %d : %c\n", i, i);
    }

    return 0;
}