#include <stdio.h>

int main(void) {
    // (�ڷ���) (������) = (��);
    int age = 30;

    // %d : (decimal) : 10���� : ����
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
    printf("�¾ ���� : %d\n", YEAR);

    // ���
    // YEAR = 2020; (ERR)
    
    // printf
    // ����
    int add = 3 + 7; // 10
    printf("3 + 7 = %d\n", add);
    printf("%d + %d = %d\n", 3, 7, 3 + 7);
    printf("%d * %d = %d\n", 31, 79, 31 * 79);

    // scanf
    // Ű���� �Է��� �޾Ƽ� ����
    int input;
    printf("������ �Է��ϼ��� : ");

    scanf("%d", &input);
    printf("�Է��� �� : %d\n", input);

    int one, two, three;
    printf("3���� ������ �Է��ϼ��� : ");

    scanf("%d %d %d", &one, &two, &three);
    printf("ù ��° �� : %d\n", one);
    printf("�� ��° �� : %d\n", two);
    printf("�� ��° �� : %d\n", three);

    // ����(�� ����)
    char c = 'A';
    printf("%c\n", c);

    // ���ڿ�(�� ���� �̻��� ����)
    char str[256];
    printf("���ڿ��� �Է��ϼ��� : ");
    
    // �迭�� ũ�⸦ ����ؾ� �Ѵ�.
    scanf("%s", str, sizeof(str));
    printf("%s\n", str);

    return 0;
}