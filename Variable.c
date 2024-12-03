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
    {" / \\"}
};

const char train1[6][8] = { //����
    {" _____ "},
    {"|     |"},
    {"|[]   |"},
    {"|_____|"},
    {" |   | "},
    {" o   o "}
};

char Name[30];  //���� ���� �� �̸��� �Է¹޴� ��

bool bgm_on = 1; //����ȭ�鿡�� ����� Ʋ�� ���� �����ϴ� ����

Car* cars;          //�ڵ��� ��ü �迭
Coin* coins;        //���� ��ü �迭
River* rivers;      //�� ��ü �迭
Monster* monsters;  //���� ��ü �迭
Train* trains;      //���� ��ü �迭
Item* items;        //������ ��ü �迭
short train_x;      //�׻� ������ x��ǥ�� ������ ����
int index;          //��ü���� ������ ���� �ֱ⸦ �����ϴ� �ε���

Car help_car = { 10, 3, 0, 0 }; //���� ���� ȭ�鿡�� �� �ڵ��� ��ü
Coin help_coin = { 30, 20, 0 }; //���� ���� ȭ�鿡�� �� ���� ��ü
River help_river = { 50, {10, 17, 24, 31, 38}, 0 }; //���� ���� ȭ�鿡�� �� �� ��ü
Monster help_monster = { 91, 3, 0, 0 }; //���� ���� ȭ�鿡�� �� ���� ��ü

User Ranking[RANKING]; //��ŷ�� ������ �迭

char player = 'G';               //�÷��̾� ����
Color p_rgb = { 255, 255, 255 }; //�÷��̾� Ŀ���� ����
Color c_rgb = { 0, 255, 0 };     //�ڵ���
Color m_rgb = { 255, 0, 0 };     //����
Color t_rgb = { 255, 165, 0 };   //����

unsigned int Score = 0; //�÷��̾��� ������ ������ ��
unsigned int Coins = 0; //�÷��̾��� ���� ������ ������ ��

long extra_display = 0; //ȭ�� �÷���

short start_x = 77, start_y = 29; // x, y�� �ʱⰪ

bool varrier_on = 0;            //�踮�� ���� ����
bool point_on = 0;              //����Ʈ ���� ����
int point_duration = 0;         //����Ʈ ���� ���ӽð�
bool invincible_on = 0;         //���� ���� ����
int invincible_duration = 0;    //���� ���� ���ӽð�
bool fever_on = 0;              //�ǹ� ���� ���ӽð�
int fever_duration = 0;         //�ǹ� ���� ���ӽð�
bool time_on = 0;               //Ÿ�� ���� ����
int time_duration = 0;          //Ÿ�� ���� ���ӽð�

//�̹��� ��� ���� ���� �ڵ�
HWND hwnd; //���� ���׶��� �������� �ڵ��� ������
HDC hdc;   //�������� Ŭ���̾�Ʈ ������ ���� ����̽� ���ؽ�Ʈ�� ������

//�̹��� ���ϵ��� �ּҸ� ���� ����
const char* Chicken = "Images\\Chicken.raw";
const char* Chicken2 = "Images\\Chicken2.raw";
const char* Genie = "Images\\Genie.raw";

//���� ���ϵ��� �ּҸ� ���� ����
const char* Main_bgm = "Sounds\\Main_bgm.wav";
const char* Game_bgm = "Sounds\\Game_bgm.wav";
const char* Click_sound = "Sounds\\Click_sound.wav";
const char* Gameover_sound = "Sounds\\Gameover_sound.wav";
const char* Gamestart_sound = "Sounds\\Gamestart_sound.wav";
const char* Ranking_sound = "Sounds\\Ranking_sound.wav";
const char* Pick_sound = "Sounds\\Pick_sound.wav";