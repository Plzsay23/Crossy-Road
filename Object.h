#ifndef OBJECT_H  // ��� ����
#define OBJECT_H

#include <stdio.h>
#include <stdbool.h>
#include "Variable.h"
#include "Setting.h"

//��ü�� ���� �Ҵ� �Լ���
void init_object();
void free_object();

//��ü ��ǥ���� �޾� �׸��� ����� �Լ���
void Draw_object(int object, short x, short y, int x_range, int y_range, bool up);
void Remove_object(short x, short y, int x_range, int y_range);

//�÷��̾ �׸��� ����� �Լ���
void Draw_player(short x, short y);
void Remove_player(short x, short y);

//�ڵ��� ��ü�� �߰��ϰ� �����ϰ� ��ǥ�� �����̴� �Լ���
void Draw_car(short x, short y, bool up);
void Remove_car(short x, short y);
void Add_car(short x, short y, int num, bool up);
void Delete_car(int num);
void Move_car(int num);
void Floating_car();

//���� ��ü�� �߰��ϰ� �����ϰ� ��ǥ�� �����̴� �Լ���
void Draw_coin(short x, short y);
void Remove_coin(short x, short y);
void Add_coin(short x, short y, int num);
void Delete_coin(int num);
void Floating_coin();

//�� ��ü�� �߰��ϰ� �����ϰ� ��ǥ�� �����̴� �Լ���
void Draw_river(short x, int num);
void Remove_river(short x);
void Add_river(short x, int num);
void Delete_river(int num);
void Floating_river();

//���� ��ü�� �߰��ϰ� �����ϰ� ��ǥ�� �����̴� �Լ���
void Draw_monster(short x, short y);
void Remove_monster(short x, short y);
void Add_monster(short x, short y, int num, bool up);
void Delete_monster(int num);
void Move_monster(int num);
void Floating_monster();

//���� ��ü�� �߰��ϰ� �����ϰ� ��ǥ�� �����̴� �Լ���
void Draw_train(short x, short y);
void Remove_train(short x, short y);
void Add_train(short x, short y, int num);
void Delete_train(int num);
void Move_train(int num);
void Floating_train();

//������ ��ü�� �߰��ϰ� �����ϰ� ��ǥ�� �����̴� �Լ���
void Draw_item(short x, short y, int items);
void Remove_item(short x, short y);
void Add_item(short x, short y, int num, int kind);
void Delete_item(int num);
void Floating_item();
void Item_varrier();
void Item_speed(int time);
void Item_invincible(int time);

//��ü�� �÷��̾��� �浹 ���� �Լ���
bool Check_car(short x, short y);
bool Check_help_car(short x, short y);
bool Check_coin(short x, short y);
bool Check_river(short x, short y);
bool Check_help_river(short x, short y);
bool Check_monster(short x, short y);
bool Check_help_monster(short x, short y);
bool Check_train(short x, short y);
bool Check_item(short x, short y);

//����ִ� ��ü�� ã�� �Լ���
short Find_car();
short Find_coin();
short Find_river();
short Find_train();
short Find_item();

//�÷��ý� ���� ��ü�� �����ϴ� �Լ�
unsigned short Choose_object();

#endif