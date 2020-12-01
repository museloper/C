#include <stdio.h>

// ����
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
    printf("��� 5�� �߿� 2���� ������ %d���� ���ƿ�.\n", ret);

    return 0;
}

/**
 *  ��ȯ�� �Լ��̸�(���ް�) {
 *
 *  }
 */

// ����
void printAge(int age) {
    printf("���̴� %d �Դϴ�\n", age);
}

void function_without_return() {
    printf("��ȯ���� ���� �Լ��Դϴ�.\n");
}

char function_with_return() {
    printf("��ȯ���� �ִ� �Լ��Դϴ�.\n");

    return 'L';
}

void function_without_params() {
    printf("���ް��� ���� �Լ��Դϴ�.\n");
}

void function_with_params(char L) {
    printf("���ް��� �ִ� �Լ��̸�, ���޹��� ���� %c �Դϴ�.\n", L);
}

int apple(int total, int ate) {
    printf("���ް��� ��ȯ���� �ִ� �Լ��Դϴ�.\n");
    return total - ate;
}