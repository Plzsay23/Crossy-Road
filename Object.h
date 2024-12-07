#ifndef OBJECT_H  // 헤더 가드
#define OBJECT_H

#include <stdio.h>
#include <stdbool.h>
#include "Variable.h"
#include "Setting.h"
#include "Screen.h"
#include "Object.h"
#include "Game.h"

//객체의 동적 할당 함수들
void init_object();
void free_object();

//객체 좌표값을 받아 그리고 지우는 함수들
void Draw_object(int object, short x, short y, int x_range, int y_range, bool up);
void Remove_object(short x, short y, int x_range, int y_range);

//플레이어를 그리고 지우는 함수들
void Draw_player(short x, short y);
void Remove_player(short x, short y);

//자동차 객체를 추가하고 제거하고 좌표를 움직이는 함수들
void Draw_car(short x, short y, bool up);
void Remove_car(short x, short y);
void Add_car(short x, short y, int num, bool up);
void Delete_car(int num);
void Move_car(int num);
void Floating_car();

//코인 객체를 추가하고 제거하고 좌표를 움직이는 함수들
void Draw_coin(short x, short y);
void Remove_coin(short x, short y);
void Add_coin(short x, short y, int num);
void Delete_coin(int num);
void Floating_coin();

//강 객체를 추가하고 제거하고 좌표를 움직이는 함수들
void Draw_river(short x, int num);
void Remove_river(short x);
void Add_river(short x, int num);
void Delete_river(int num);
void Floating_river();

//몬스터 객체를 추가하고 제거하고 좌표를 움직이는 함수들
void Draw_monster(short x, short y);
void Remove_monster(short x, short y);
void Add_monster(short x, short y, int num, bool up);
void Delete_monster(int num);
void Move_monster(int num);
void Floating_monster();

//기차 객체를 추가하고 제거하고 좌표를 움직이는 함수들
void Draw_train(short x, short y);
void Remove_train(short x, short y);
void Add_train(short x, short y, int num);
void Delete_train(int num);
void Move_train(int num);
void Floating_train();

//아이템 객체를 추가하고 제거하고 좌표를 움직이는 함수들
void Draw_item(short x, short y, int items);
void Remove_item(short x, short y);
void Add_item(short x, short y, int num, int kind);
void Delete_item(int num);
void Floating_item();
void Item_varrier();
void Item_point(int time);
void Item_fever(int time);
void Item_invincible(int time);

//객체와 플레이어의 충돌 감지 함수들
bool Check_car(short x, short y);
bool Check_coin(short x, short y);
bool Check_river(short x, short y);
bool Check_help_river(short x, short y);
bool Check_monster(short x, short y);
bool Check_train(short x, short y);
Itemcheck Check_item(short x, short y);

//비어있는 객체를 찾는 함수들
short Find_car();
short Find_coin();
short Find_river();
short Find_train();
short Find_item();

//플로팅시 나올 객체를 선택하는 함수
unsigned short Choose_object();

#endif