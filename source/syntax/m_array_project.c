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


// 10마리의 서로 다른 동물(각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기

int arrayAnimal[4][5]; // 카드 지도(20장)
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인
char *strAnimal[10];

int main(void) {
    srand(time(NULL));

    initAnimalArray();
    initAnimalName();

    shuffleAnimal();

    int failCount = 0;

    while(1) {
        // 사용자가 선택한 수
        int select1 = 0;
        int select2 = 0;

        printAnimals();  // 동물 위치 출력
        printQuestion(); // 문제 출력(카드 지도)
        printf("\n뒤집을 카드를 2개 고르세요 : \n");
        scanf("%d %d", &select1, &select2);

        if(select1 == select2) continue;

        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        // 좌표에 해당하는 카드를 뒤집어보고 같은지 같지 않은지 확인
        if((checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0) && arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]) {
            printf("\n\n빙고! : %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y] = 1;
            checkAnimal[secondSelect_x][secondSelect_y] = 1;
        }
        else {
            printf("\n\n땡! : (틀렸거나, 이미 뒤집힌 카드입니다!)\n");
            printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            failCount++;
        }

        // 모든 동물을 찾았는지 여부, 1:참 | 0:거짓
        if(foundAllAnimals() == 1) {
            printf("\n\n 축하합니다! 모든 동물을 다 찾았네요!\n");
            printf("지금까지 총 %d번 실수하셨습니다!\n", failCount);
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
    strAnimal[0] = "원숭이";
    strAnimal[1] = "여우";
    strAnimal[2] = "치타";
    strAnimal[3] = "펭귄";
    strAnimal[4] = "사슴";

    strAnimal[5] = "판다";
    strAnimal[6] = "늑대";
    strAnimal[7] = "사자";
    strAnimal[8] = "노루";
    strAnimal[9] = "사막여우";
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

// 좌표에서 빈 공간 찾기
int getEmptyPosition() {
    // □ □ □ □ □    0  1  2  3  4
    // □ □ □ □ □    5  6  7  8  9
    // □ □ □ □ □   10 11 12 13 14
    // □ □ □ □ □   15 16 17 18 19
    while(1) {
        int randPos = rand() % 20; // 0 ~ 19 사이의 숫자 반환
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
    // □ □ □ □ □    0  1  2  3  4
    // □ □ □ □ □    5  6  7  8  9
    // □ □ □ □ □   10 11 12 13 14
    // □ □ □ □ □   15 16 17 18 19
    printf("\n======= 이건 비밀인데.. 몰래 보여드립니다! =======\n\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%10s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n==================================================\n");
}

void printQuestion() {
    printf("\n(문제)\n");
    int seq = 0;

    // □ □ □ □ □    0  1  2  3  4
    // □ □ □ □ □    5  6  7  8  9
    // □ □ □ □ □   10 11 12 13 14
    // □ □ □ □ □   15 16 17 18 19

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            // 카드를 뒤집어서 정답을 맞혔으면 '동물 이름'
            if(checkAnimal[i][j] != 0) {
                printf("%10s", strAnimal[arrayAnimal[i][j]]);
            }

            // 정답을 못맞혔으면 뒷면
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
    return 1; // 모두 다 찾음
}