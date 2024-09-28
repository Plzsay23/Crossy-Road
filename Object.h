#ifndef OBJECT_H  // 헤더 가드
#define OBJECT_H

#include <stdio.h>
#include <stdbool.h>
#include "Variable.h"

void Draw_player(short x, short y);
void Remove_player(short x, short y);
void Draw_coin(short x, short y);
void Remove_coin(short x, short y);
void Draw_car(short x, short y);
void Remove_car(short x, short y);
bool Check_over(short x, short y);
bool Check_coin(short x, short y);
void Add_car(short x, short y, int num, bool up);
void Delete_car(int num);
void Move_car(int num);
void Floating_car(bool direction);
void Add_coin(short x, short y, int num);
void Delete_coin(int num);
void Floating_coin(bool direction);
short Find_car();
short Find_coin();

#endif