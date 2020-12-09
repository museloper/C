#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();


// 10������ ���� �ٸ� ����(�� ī�� 2�徿)
// ����ڷκ��� 2���� �Է°��� �޾Ƽ� ���� ���� ã���� ī�� ������
// ��� ���� ���� ã���� ���� ����
// �� ���� Ƚ�� �˷��ֱ�

int arrayAnimal[4][5]; // ī�� ����(20��)
int checkAnimal[4][5]; // ���������� ���� Ȯ��
char *strAnimal[10];

int main(void) {
    srand(time(NULL));

    initAnimalArray();
    initAnimalName();

    shuffleAnimal();

    int failCount = 0;

    while(1) {
        // ����ڰ� ������ ��
        int select1 = 0;
        int select2 = 0;

        printAnimals();  // ���� ��ġ ���
        printQuestion(); // ���� ���(ī�� ����)
        printf("\n������ ī�带 2�� ������ : \n");
        scanf("%d %d", &select1, &select2);

        if(select1 == select2) continue;

        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        // ��ǥ�� �ش��ϴ� ī�带 ������� ������ ���� ������ Ȯ��
        if((checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0) && arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]) {
            printf("\n\n����! : %s �߰�\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y] = 1;
            checkAnimal[secondSelect_x][secondSelect_y] = 1;
        }
        else {
            printf("\n\n��! : (Ʋ�Ȱų�, �̹� ������ ī���Դϴ�!)\n");
            printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            failCount++;
        }

        // ��� ������ ã�Ҵ��� ����, 1:�� | 0:����
        if(foundAllAnimals() == 1) {
            printf("\n\n �����մϴ�! ��� ������ �� ã�ҳ׿�!\n");
            printf("���ݱ��� �� %d�� �Ǽ��ϼ̽��ϴ�!\n", failCount);
            break;
        }
    }

    return 0;
}

void initAnimalArray() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalName() {
    strAnimal[0] = "������";
    strAnimal[1] = "����";
    strAnimal[2] = "ġŸ";
    strAnimal[3] = "���";
    strAnimal[4] = "�罿";

    strAnimal[5] = "�Ǵ�";
    strAnimal[6] = "����";
    strAnimal[7] = "����";
    strAnimal[8] = "���";
    strAnimal[9] = "�縷����";
}

void shuffleAnimal() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 2; j++) {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i;
        }
    }
}

// ��ǥ���� �� ���� ã��
int getEmptyPosition() {
    // �� �� �� �� ��    0  1  2  3  4
    // �� �� �� �� ��    5  6  7  8  9
    // �� �� �� �� ��   10 11 12 13 14
    // �� �� �� �� ��   15 16 17 18 19
    while(1) {
        int randPos = rand() % 20; // 0 ~ 19 ������ ���� ��ȯ
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if(arrayAnimal[x][y] == -1) {
            return randPos;
        }
    }
    return 0;
}

int conv_pos_x(int x) {
    x /= 5;
    return x;
}

int conv_pos_y(int y) {
    y %= 5;
    return y;
}

void printAnimals() {
    // �� �� �� �� ��    0  1  2  3  4
    // �� �� �� �� ��    5  6  7  8  9
    // �� �� �� �� ��   10 11 12 13 14
    // �� �� �� �� ��   15 16 17 18 19
    printf("\n======= �̰� ����ε�.. ���� �����帳�ϴ�! =======\n\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%10s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n==================================================\n");
}

void printQuestion() {
    printf("\n(����)\n");
    int seq = 0;

    // �� �� �� �� ��    0  1  2  3  4
    // �� �� �� �� ��    5  6  7  8  9
    // �� �� �� �� ��   10 11 12 13 14
    // �� �� �� �� ��   15 16 17 18 19

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            // ī�带 ����� ������ �������� '���� �̸�'
            if(checkAnimal[i][j] != 0) {
                printf("%10s", strAnimal[arrayAnimal[i][j]]);
            }

            // ������ ���������� �޸�
            else {
                printf("%10d", seq);
            }

            seq++;
        }
        printf("\n");
    }
}

int foundAllAnimals() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            if(checkAnimal[i][j] == 0) return 0;
        }
    }
    return 1; // ��� �� ã��
}