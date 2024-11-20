#ifndef OBJECT_H  // ��� ����
#define OBJECT_H

#include <stdio.h>
#include <stdbool.h>
#include "Variable.h"
#include "Setting.h"

//��ü�� ���� �Ҵ� �Լ���
void init_object();
void free_object();

//��ü�� �ܼ��� �׸��� ����� �Լ���
void Draw_object(int object, short x, short y, int x_range, int y_range, bool up);
void Remove_object(short x, short y, int x_range, int y_range);

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

void Draw_train(short x, short y);
void Remove_train(short x, short y);

//��ü�� �÷��̾��� �浹 ���� �Լ���
bool Check_car(short x, short y);
bool Check_coin(short x, short y);
bool Check_river(short x, short y);
bool Check_monster(short x, short y);
bool Check_train(short x, short y);

/*o��ü�� �߰��ϰ� �����ϰ� ��ǥ�� �����̴� �Լ���o*/

//�ڵ���
void Add_car(short x, short y, int num, bool up);
void Delete_car(int num);
void Move_car(int num);
void Floating_car();

//����
void Add_coin(short x, short y, int num);
void Delete_coin(int num);
void Floating_coin();

//��
void Add_river(short x, int num);
void Delete_river(int num);
void Floating_river();

//����
void Add_monster(short x, short y, int num, bool up);
void Delete_monster(int num);
void Move_monster(int num);
void Floating_monster();

//����
void Add_train(short x, short y, int num);
void Delete_train(int num);
void Move_train(int num);
void Floating_train();

//����ִ� ��ü�� ã�� �Լ���
short Find_car();
short Find_coin();
short Find_river();
short Find_train();

//�÷��ý� ���� ��ü�� �����ϴ� �Լ�
unsigned short Choose_object();

#endif