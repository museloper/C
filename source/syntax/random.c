#include <time.h>
#include <stdlib.h> // 위의 라이브러리가 잘 적용이 되지 않는 경우에 사용
#include <stdio.h>

int main(void) {
    // rand() % 난수 범위
    int num = rand() % 3; // 0, 1, 2
    
    // 난수 초기화 전
    for(int i = 0; i < 10; i++) {
        printf("%d ", rand() % 10);
    }
    printf("\n");

    // 난수 초기화
    srand(time(NULL));

    // 난수 초기화 후
    for(int i = 0; i < 10; i++) {
        printf("%d ", rand() % 10);
    }
    printf("\n");

    return 0;
}