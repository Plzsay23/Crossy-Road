#ifndef OBJECT_H  // ��� ����
#define OBJECT_H

#include <stdio.h>
#include <stdbool.h>
#include "Variable.h"

//��ü�� �ܼ��� �׸��� ����� �Լ���
void Draw_player(short x, short y);
void Remove_player(short x, short y);
void Draw_coin(short x, short y);
void Remove_coin(short x, short y);
void Draw_car(short x, short y, bool up);
void Remove_car(short x, short y);
void Draw_river(short x, int num);
void Remove_river(short x);
void Draw_monster(short x, short y);
void Remove_monster(short x, short y);

//��ü�� �÷��̾��� �浹 ���� �Լ���
bool Check_car(short x, short y);
bool Check_coin(short x, short y);
bool Check_river(short x, short y);
bool Check_monster(short x, short y);

//��ü�� �߰��ϰ� �����ϰ� ��ǥ�� �����̴� �Լ���
//�ڵ���
void Add_car(short x, short y, int num, bool up);
void Delete_car(int num);
void Move_car(int num);
void Floating_car(bool direction);

//����
void Add_coin(short x, short y, int num);
void Delete_coin(int num);
void Floating_coin(bool direction);

//��
void Add_river(short x, int num);
void Delete_river(int num);
void Floating_river(bool direction);

//����
void Add_monster(short x, short y, int num, bool up);
void Delete_monster(int num);
void Move_monster(int num);
void Floating_monster(bool direction);

//����ִ� ��ü�� ã�� �Լ���
short Find_car();
short Find_coin();
short Find_river();

//�÷��ý� ���� ��ü�� �����ϴ� �Լ�
unsigned short Choose_object();

#endif