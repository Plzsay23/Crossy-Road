#ifndef VARIABLE_H  // ��� ����
#define VARIABLE_H

#include <stdbool.h>

#define IMAGE_SIZE (256 * 256)
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define RANKING 10
#define CARS 30 // x ���� 150�� �ܼ�â���� �� 30���� �Ѱ�
#define COINS 30 //���� �ִ� ���� �� 30��
#define RIVER 5 //��

//���� ����ü, ex) Textcolor(black, white) �̷��� ����� ����, ���ڴ� ������� ������
//https://makerejoicegames.tistory.com/115
enum {
    black, blue, green, skyblue, red, pink, orange, white, gray, lightblue,
    brightgreen, sky, brightred, brightpink, brightyellow, brightwhite
};

//�ڵ��� ��ü ����ü
typedef struct Cars {
    short x;    // x ��ǥ
    short y;    // y ��ǥ
    bool on;    //��ü�� Ȱ��ȭ ����
    bool up;    //��ü�� ���� ���� �Ʒ��� ���� (1�̸� ����, 0�̸� �Ʒ���)
} Cars;

//���� ����ü
typedef struct Coin {
    short x;    // x ��ǥ
    short y;    // y ��ǥ
    bool on;    // ��ü�� Ȱ��ȭ ����
} Coin;

//�� ����ü
typedef struct River {
    short x;             //����� ���۵� x��ǥ
    short bridge[RIVER]; //���� �ٸ��� ������ y��ǥ, �ִ� 5��
    bool on;             //��ü�� Ȱ��ȭ ����
} River;

//��ŷ ����ü
typedef struct User {
    int score;           //����
    char name[30];      //����� �̸�
    unsigned int coins;  //���� ����
} User;

//���� ���� ���� ���� ����
extern char Name[30];            //���� ���� �� �̸��� �Է¹޴� ��

extern Cars cars[CARS];          //�ڵ��� ��ü �迭
extern Coin coins[COINS];        //���� ��ü �迭
extern River rivers[RIVER];       //�� ��ü �迭

extern Cars help_screen_car;     //���� ���� ȭ�鿡�� �� �ڵ��� ��ü
extern Coin help_screen_coin;    //���� ���� ȭ�鿡�� �� ���� ��ü

extern User Ranking[RANKING];    //��ŷ�� ������ �迭

extern unsigned int Score;       //�÷��̾��� ������ ������ ��
extern unsigned int Coins;       //�÷��̾��� ���� ������ ������ ��

extern long extra_display;       //ȭ�� �÷���, �󸶳� ������������ ������ ����

extern short start_x, start_y;   // x, y�� �ʱⰪ

#endif