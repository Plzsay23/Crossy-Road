#ifndef GAME_H  // ��� ����
#define GAME_H

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "Variable.h"
#include "Setting.h"
#include "Screen.h"
#include "Object.h"
#include "Game.h"

//���� ���� �� ��� ���� �̺�Ʈ
void Game_over(short x, short y);

//��ü�� ����ü ���� ������ �ʱ�ȭ�ϴ� �Լ�
void Recycle();

//�ΰ��� �Լ�
void Game();

#endif