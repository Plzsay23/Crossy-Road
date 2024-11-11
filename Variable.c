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

const char monster1[3][7] = { //����
    {" @ @ "},
    {"( o )"},
    {" / ��"}
};

const char train[6][8] = { //����
    {" _____ "},
    {"|     |"},
    {"|[]   |"},
    {"|_____|"},
    {" |   | "},
    {" o   o "}
};

char Name[30];  //���� ���� �� �̸��� �Է¹޴� ��

Car* cars; //�ڵ��� ��ü �迭
Coin* coins; //���� ��ü �迭
River* rivers; //�� ��ü �迭
Monster* monsters; //���� ��ü �迭
Train* trains; //���� ��ü �迭

Car help_car = { 10, 3, 0, 0 }; //���� ���� ȭ�鿡�� �� �ڵ��� ��ü
Coin help_coin = { 30, 20, 0 }; //���� ���� ȭ�鿡�� �� ���� ��ü
River help_river = { 50, {10, 17, 24, 31, 38}, 0 }; //���� ���� ȭ�鿡�� �� �� ��ü
Monster help_monster = { 91, 3, 0, 0 }; //���� ���� ȭ�鿡�� �� ���� ��ü
Train help_train = { 111, 3, 0, 0 }; //���� ���� ȭ�鿡�� �� ���� ��ü

User Ranking[RANKING]; //��ŷ�� ������ �迭

Color p_rgb = { 255, 255, 255 }; //�÷��̾� Ŀ���� ����
Color c_rgb = { 0, 255, 0 }; //�ڵ���
Color m_rgb = { 255, 0, 0 }; //����
Color t_rgb = { 255, 165, 0 }; //����

unsigned int Score = 0; //�÷��̾��� ������ ������ ��
unsigned int Coins = 0; //�÷��̾��� ���� ������ ������ ��

long extra_display = 0; //ȭ�� �÷���

short start_x = 77, start_y = 29; // x, y�� �ʱⰪ

//�̹��� ��� ���� ���� �ڵ�
HWND hwnd; //���� ���׶��� �������� �ڵ��� ������
HDC hdc; //�������� Ŭ���̾�Ʈ ������ ���� ����̽� ���ؽ�Ʈ�� ������

//�̹��� ���ϵ��� �ּҸ� ���� ����
const char* Chicken = "Images\\Chicken.raw";