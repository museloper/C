#include <stdio.h>

// 선언
void printAge(int age);
void function_without_return();
char function_with_return();
void function_without_params();
void function_with_params(char);
int apple(int total, int ate);

int main(void) {

    int age = 30;
    printAge(age);
    
    // return void
    function_without_return();
    
    // return char
    char L = function_with_return();
    printf("%c\n", L);

    // params(void)
    function_without_params();

    // params(char)
    function_with_params(L);

    // int fn(int)
    int ret = apple(5, 2);
    printf("사과 5개 중에 2개를 먹으면 %d개가 남아요.\n", ret);

    return 0;
}

/**
 *  반환형 함수이름(전달값) {
 *
 *  }
 */

// 정의
void printAge(int age) {
    printf("나이는 %d 입니다\n", age);
}

void function_without_return() {
    printf("반환값이 없는 함수입니다.\n");
}

char function_with_return() {
    printf("반환값이 있는 함수입니다.\n");

    return 'L';
}

void function_without_params() {
    printf("전달값이 없는 함수입니다.\n");
}

void function_with_params(char L) {
    printf("전달값이 있는 함수이며, 전달받은 값은 %c 입니다.\n", L);
}

int apple(int total, int ate) {
    printf("전달값과 반환값이 있는 함수입니다.\n");
    return total - ate;
}