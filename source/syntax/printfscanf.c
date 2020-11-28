#include <stdio.h>

int main(void) {
    // (자료형) (변수명) = (값);
    int age = 30;

    // %d : (decimal) : 10진수 : 정수
    printf("%d\n", age);

    age = 17;
    printf("%d\n", age);

    float weight = 71.0;
    printf("%f\n", weight);   // 71.000000
    printf("%.2f\n", weight); // 71.00

    double height = 166.9;
    printf("%lf\n", height);   // 166.900000
    printf("%.1lf\n", height); // 166.9

    const int YEAR = 1991;
    printf("태어난 연도 : %d\n", YEAR);

    // 상수
    // YEAR = 2020; (ERR)
    
    // printf
    // 연산
    int add = 3 + 7; // 10
    printf("3 + 7 = %d\n", add);
    printf("%d + %d = %d\n", 3, 7, 3 + 7);
    printf("%d * %d = %d\n", 31, 79, 31 * 79);

    // scanf
    // 키보드 입력을 받아서 저장
    int input;
    printf("정수를 입력하세요 : ");

    scanf("%d", &input);
    printf("입력한 값 : %d\n", input);

    int one, two, three;
    printf("3개의 정수를 입력하세요 : ");

    scanf("%d %d %d", &one, &two, &three);
    printf("첫 번째 값 : %d\n", one);
    printf("두 번째 값 : %d\n", two);
    printf("세 번째 값 : %d\n", three);

    // 문자(한 글자)
    char c = 'A';
    printf("%c\n", c);

    // 문자열(한 글자 이상의 글자)
    char str[256];
    printf("문자열을 입력하세요 : ");
    
    // 배열은 크기를 명시해야 한다.
    scanf("%s", str, sizeof(str));
    printf("%s\n", str);

    return 0;
}