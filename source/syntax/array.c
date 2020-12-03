#include <stdio.h>

int main(void) {
    // �迭(���� ���� ������ ���ÿ� ����)
    int subway_array[3];

    subway_array[0] = 10;
    subway_array[1] = 20;
    subway_array[2] = 30;

    for(int i = 0; i < 3; i++) {
        printf("����ö %dȣ���� %d���� Ÿ�� �ֽ��ϴ�.\n", i+1, subway_array[i]);
    }

    // �� ���� ���
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // ���࿡ �迭�� ���� �ϰ� ���� �ʱ�ȭ ���� ������?
    int arr_dummy[10];
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr_dummy[i]);
    }

    printf("\n");

    // �迭�� �Ϻθ� �ʱ�ȭ �Ѵٸ�?
    int arr_part[10] = {1, 2, 3};
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr_part[i]);
    }

    int arr_blank[] = {1, 2, 3, 4, 5}; // arr[5]

    printf("\n");

    // ���� vs ���ڿ�
    char c = 'A';
    printf("%c\n", c);

    // ���ڿ� ������ '��'�� �ǹ��ϴ� NULL ���� '\0'�� ���ԵǾ�� �Ѵ�.
    char str[7] = "coding"; // [c][o][d][i][n][g][\0]
    printf("%s\n", str);

    char str_blank[] = "coding";
    printf("%s\n", str_blank);
    printf("%d\n", sizeof(str_blank));

    for(int i = 0; i < sizeof(str_blank); i++) {
        printf("%c\n", str_blank[i]);
    }

    // ����� �� ���� : 1 byte
    // �ѱ��� �� ���� : 2 byte
    char kor[] = "��������";
    printf("%s\n", kor);
    printf("%d\n", sizeof(kor)); // 9

    // ASCII �ڵ�
    printf("�ƽ�Ű�ڵ�\n");
    for(int i = 0; i < sizeof(str_blank); i++) {
        printf("%d\n", str_blank[i]);
    }

    // ASCII �ڵ��? ANSI(�̱�ǥ����ȸ)���� ������ ǥ�� �ڵ� ü��
    // 7bit, �� 128�� �ڵ�(0-127)
    // a : 97
    // A : 65
    // 0 : 48

    printf("�ƽ�Ű�ڵ�\n");
    printf("%c\n", 'a');
    printf("%d\n", 'a');

    printf("%c\n", 'A');
    printf("%d\n", 'A');

    printf("%c\n", '0');
    printf("%d\n", '0');

    // 0-127 ������ �ƽ�Ű�ڵ� �������� �ش��ϴ� ���� Ȯ��
    for(int i = 0; i < 128; i++) {
        printf("�ƽ�Ű�ڵ� ���� %d : %c\n", i, i);
    }

    return 0;
}