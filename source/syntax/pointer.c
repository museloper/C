#include <stdio.h>

int main(void) {
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

    return 0;
}