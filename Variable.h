#ifndef VARIABLE_H  // ��� ����
#define VARIABLE_H

#include <stdbool.h>
#include <Windows.h>

#define IMAGE_SIZE (256 * 256)
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define RANKING 10  //��ŷ�迭 ũ�� 10
#define CARS 40     //���� �ִ� �ڵ��� ���� 40��
#define COINS 20    //����    20��
#define RIVERS 5    //��      5��
#define MONSTERS 40 //����  40��
#define TRAINS 8    //����    8��
#define ITEMS 20    //������  20��
#define COLOR 4     //����(��ü ����)�迭 ũ�� 4

enum objects { car = 0, coin, river, monster, train }; //��ü�� ��ȣ
enum items { varrier = 0, point, invincible, fever, _time, star }; //�������� ��ȣ

//������ �浹 �Լ��� ��ȯ ��
typedef struct Itemcheck {
    bool found; //�����۰� �ε��������� ��ȯ�ϴ� ��
    int type;   //�������� ������ ��ȯ�ϴ� ��
} Itemcheck;

//�ڵ��� ��ü ����ü
typedef struct Car {
    short x;    // x ��ǥ
    short y;    // y ��ǥ
    bool on;    //��ü�� Ȱ��ȭ ����
    bool up;    //��ü�� ���� ���� �Ʒ��� ���� (1�̸� ����, 0�̸� �Ʒ���)
} Car;

//���� ����ü
typedef struct Coin {
    short x;    // x ��ǥ
    short y;    // y ��ǥ
    bool on;    // ��ü�� Ȱ��ȭ ����
} Coin;

//�� ����ü
typedef struct River {
    short x;             //����� ���۵� x��ǥ
    short bridge[RIVERS]; //���� �ٸ��� ������ y��ǥ, �ִ� 5��
    bool on;             //��ü�� Ȱ��ȭ ����
} River;

//���� ����ü
typedef struct Monster {
    short x;    // x ��ǥ
    short y;    // y ��ǥ
    bool on;    //��ü�� Ȱ��ȭ ����
    bool up;    //��ü�� ���� ���� �Ʒ��� ���� (1�̸� ����, 0�̸� �Ʒ���)
} Monster;

//���� ����ü
typedef struct Train {
    short x;    // x ��ǥ
    short y;    // y ��ǥ
    bool on;    //��ü�� Ȱ��ȭ ����
} Train;

//������ ����ü
typedef struct Item {
    short x;    // x ��ǥ
    short y;    // y ��ǥ
    bool on;    //��ü�� Ȱ��ȭ ����
    int type;   //������ ����
} Item;

//���� ����ü
typedef struct Color {
    int r;  //Red
    int g;  //Green
    int b;  //Blue
} Color;

//��ŷ ����ü
typedef struct User {
    int score;           //����
    char name[30];       //����� �̸�
    unsigned int coins;  //���� ����
    Color color[COLOR];  //���� ���� ������ �迭
} User;

/*o���� ���� ���� ���� ����o*/

extern const char player[3][4];

//�ڵ��� ������
extern const char car_down[5][7];
extern const char car_up[5][7];

//���� ������
extern const char monster1[3][6];

//���� ������
extern const char train1[6][8];

extern char Name[30];          //���� ���� �� �̸��� �Է¹޴� ��

extern bool bgm_on;            //����ȭ�鿡�� ����� Ʋ�� ���� �����ϴ� ����

extern Car* cars;              //�ڵ��� ��ü �迭
extern Coin* coins;            //���� ��ü �迭
extern River* rivers;          //�� ��ü �迭
extern Monster* monsters;      //���� ��ü �迭
extern Train* trains;          //���� ��ü �迭
extern Item* items;            //������ ��ü �迭
extern short train_x;          //�׻� ������ x��ǥ�� ������ ����
extern int index;              //��ü���� ������ ���� �ֱ⸦ �����ϴ� �ε���

extern Car help_car;           //���� ���� ȭ�鿡�� �� �ڵ��� ��ü
extern Coin help_coin;         //���� ���� ȭ�鿡�� �� ���� ��ü
extern River help_river;       //���� ���� ȭ�鿡�� �� �� ��ü
extern Monster help_monster;   //���� ���� ȭ�鿡�� �� ���� ��ü

extern User Ranking[RANKING];  //��ŷ�� ������ �迭

extern Color p_rgb;            //�÷��̾� Ŀ���� ����
extern Color c_rgb;            //�ڵ���
extern Color m_rgb;            //����
extern Color t_rgb;            //����

extern unsigned int Score;     //�÷��̾��� ������ ������ ��
extern unsigned int Coins;     //�÷��̾��� ���� ������ ������ ��

extern long extra_display;     //ȭ�� �÷���, �󸶳� ������������ ������ ����

extern short start_x, start_y; // x, y�� �ʱⰪ

extern bool varrier_on;         //�踮�� ���� ����
extern bool point_on;           //����Ʈ ���� ����
extern int point_duration;      //����Ʈ ���� ���ӽð�
extern bool invincible_on;      //���� ���� ����
extern int invincible_duration; //���� ���� ���ӽð�
extern bool time_on;            //Ÿ�� ���� ����
extern int time_duration;       //Ÿ�� ���� ���ӽð�

extern HWND hwnd;              //���� ���׶��� �������� �ڵ��� ������
extern HDC hdc;                //�������� Ŭ���̾�Ʈ ������ ���� ����̽� ���ؽ�Ʈ�� ������

//�̹��� ���ϵ��� �ּҸ� ���� ����
extern const char* Chicken;
extern const char* Chicken2;
extern const char* Genie;

//���� ���ϵ��� �ּҸ� ���� ����
extern const char* Main_bgm;
extern const char* Game_bgm;
extern const char* Coin_sound;
extern const char* Click_sound;
extern const char* Gamestart_sound;
extern const char* Ranking_sound;
extern const char* Pick_sound;
extern const char* Gameover_sound;

#endif