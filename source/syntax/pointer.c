#include <stdio.h>

void swap(int a, int b);
void swap_addr(int *a, int *b);
void changeArray(int *prt);

int main(void) {
    // &�� �ּ��̸�, *�� �� �ּ��� ���� �ǹ��Ѵ�. 

    // ������

    // [museloper] : 101ȣ >> �޸� ������ �ּ� 
    // [flyingcat] : 201ȣ
    
    // �� �տ� '��ȣ'�� �ɷ� ����
    int museloper = 1; 
    int flyingcat = 2;

    printf("museloper �ּ� : %d ��ȣ : %d\n", &museloper, museloper);
    printf("flyingcat �ּ� : %d ��ȣ : %d\n", &flyingcat, flyingcat);
    printf("\n");

    // �̼Ǹ�
    int *missionman; // ������ ����

    // ù ��° �̼� : ����Ʈ�� �� ���� �湮�Ͽ� ���� ���� ��ȣ Ȯ��
    missionman = &museloper;
    printf("�̼Ǹ��� �湮�ϴ� ���� �ּ� : %d, ��ȣ : %d\n", missionman, *missionman);

    missionman = &flyingcat;
    printf("�̼Ǹ��� �湮�ϴ� ���� �ּ� : %d, ��ȣ : %d\n", missionman, *missionman);

    // �� ��° �̼� : �� ��ȣ�� 3�� ���ض�
    missionman = &museloper;
    *missionman = *missionman * 3;
    printf("�̼Ǹ��� ��ȣ�� �ٲ� ���� �ּ� : %d, ��ȣ : %d\n", missionman, *missionman);

    missionman = &flyingcat;
    *missionman = *missionman * 3;
    printf("�̼Ǹ��� ��ȣ�� �ٲ� ���� �ּ� : %d, ��ȣ : %d\n", missionman, *missionman);

    // ������
    int *spy;
    printf("\n ... �����̰� �̼��� �����ϴ� �� ... \n\n");

    // �̼Ǹ��� �ٲ� ��ȣ���� 2�� ����
    spy = &museloper;
    *spy = *spy - 2;
    printf("�����̰� �湮�ϴ� �� �ּ� : %d, ��ȣ : %d\n", spy, *spy);

    spy = &flyingcat;
    *spy = *spy - 2;
    printf("�����̰� �湮�ϴ� �� �ּ� : %d, ��ȣ : %d\n", spy, *spy);

    printf("\n");
    printf("museloper �ּ� : %d ��ȣ : %d\n", &museloper, museloper);
    printf("flyingcat �ּ� : %d ��ȣ : %d\n", &flyingcat, flyingcat);

    // �����... �̼Ǹ�(������)�� ��� ���� �ּҴ�... &�̼Ǹ�(������)���� Ȯ�� ����
    printf("\n ... �̼Ǹǰ� �������� �� �ּҴ�? ... \n\n");
    printf("�̼Ǹ��� �ּ� : %d\n", &missionman);
    printf("�������� �ּ� : %d\n", &spy);

    printf("\n");

    // �迭�� ������
    int arr[3] = {5, 10, 15};
    int *ptr = arr;
    for(int i = 0; i < 3; i++) {
        printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]);
    }

    for(int i = 0; i < 3; i++) {
        printf("������ ptr[%d]�� �� : %d\n", i, ptr[i]);
    }

    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;
    for(int i = 0; i < 3; i++) {
        printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]); // arr[i] == *(arr + i)
    }

    for(int i = 0; i < 3; i++) {
        printf("������ ptr[%d]�� �� : %d\n", i, *(ptr + i)); // ptr[i] == *(ptr + i)
    }

    // swap
    int a = 10;
    int b = 20;
    printf("a�� �ּ� : %d\n", &a);
    printf("a�� �ּ� : %d\n", &b);

    // Call By Value
    // a�� b�� ���� �ٲ۴�. 
    printf("swap �Լ� �� >> a : %d, b : %d\n", a, b);
    swap(a, b);
    printf("swap �Լ� �� >> a : %d, b : %d\n", a, b);

    // Call By Reference
    printf("(�ּҰ� ����) swap �Լ� �� >> a : %d, b : %d\n", a, b);
    swap_addr(&a, &b);
    printf("(�ּҰ� ����) swap �Լ� �� >> a : %d, b : %d\n", a, b);
    
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
    printf("swap �Լ� �� >> a : %d, b : %d\n", a, b);
}

void swap_addr(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
    printf("(�ּҰ� ����) swap �Լ� �� >> a : %d, b : %d\n", *a, *b);
}

void changeArray(int *prt) {
    prt[2] = 40;
}