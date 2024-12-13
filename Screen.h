#ifndef SCREEN_H  // ��� ����
#define SCREEN_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "Variable.h"
#include "Setting.h"
#include "Screen.h"
#include "Object.h"
#include "Queue.h"
#include "Game.h"

//�׸� �׸��� �Լ���
void Draw_square();
void Main_screen_letter();
void Main_screen_cloud();
void Main_screen_car();

//���ν�ũ��
void Main_screen();

//�����ϱ�
void Start_screen();

//�̸� �ߺ� �˻� - �α���
bool Check_continue();
//�̾��ϱ�
void Continue_screen();

//�̸� �ߺ� �˻� - �α���
void Into_color_screen();
//����ȭ��
void Color_screen();
//������ �ٲٴ� ȭ��
void Color_set_screen(int obj);
//������ �ٲٴ� ȭ��
void Player_set_screen();

//����ȭ��
void Help_screen();

//��ŷȭ��
void Ranking_screen();

#endif