#include <stdio.h>
#include "Variable.h"

const char car_down[5][7] = { //�ڵ��� DOWN
    {"n_ww_ "},
    {"@l   l"},
    {" l   l"},
    {"@l___l"},
    {" l__l "}
};
const char car_up[5][7] = { //�ڵ��� UP
    {" l--l "},
    {"@l- -l"},
    {" l   l"},
    {"@l   l"},
    {"u-mm- "}
};

const char monster1[3][6] = { //����
    {" @ @ "},
    {"( o )"},
    {" / ��"}
};

char Name[30];  //���� ���� �� �̸��� �Է¹޴� ��

Cars cars[CARS]; //�ڵ��� ��ü �迭
Coin coins[COINS]; //���� ��ü �迭
River rivers[RIVERS]; //�� ��ü �迭
Monster monsters[MONSTERS]; //���� ��ü �迭

Cars help_screen_car = { 10, 3, 0, 0 }; //���� ���� ȭ�鿡�� �� �ڵ��� ��ü
Coin help_screen_coin = { 30, 20, 0 }; //���� ���� ȭ�鿡�� �� ���� ��ü
River help_screen_river = { 50, {10, 17, 24, 31, 38}, 0 }; //���� ���� ȭ�鿡�� �� �� ��ü
Monster help_screen_monster = { 91, 3, 0, 0 }; //���� ���� ȭ�鿡�� �� ���� ��ü

User Ranking[RANKING]; //��ŷ�� ������ �迭

unsigned int Score = 0; //�÷��̾��� ������ ������ ��
unsigned int Coins = 0; //�÷��̾��� ���� ������ ������ ��

long extra_display = 0; //ȭ�� �÷���

short start_x = 77, start_y = 29; // x, y�� �ʱⰪ

//�̹��� ��� ���� ���� �ڵ�
HWND hwnd; //���� ���׶��� �������� �ڵ��� ������
HDC hdc; //�������� Ŭ���̾�Ʈ ������ ���� ����̽� ���ؽ�Ʈ�� ������

//�̹��� ���ϵ��� �ּҸ� ���� ����
const char* Adrenaline = "Images\\Adrenaline.raw"; //����