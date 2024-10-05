#ifndef OBJECT_H  // 헤더 가드
#define OBJECT_H

#include <stdio.h>
#include <stdbool.h>
#include "Variable.h"

//객체를 단순히 그리고 지우는 함수들
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

//객체와 플레이어의 충돌 감지 함수들
bool Check_car(short x, short y);
bool Check_coin(short x, short y);
bool Check_river(short x, short y);
bool Check_monster(short x, short y);

//객체를 추가하고 제거하고 좌표를 움직이는 함수들
//자동차
void Add_car(short x, short y, int num, bool up);
void Delete_car(int num);
void Move_car(int num);
void Floating_car(bool direction);

//코인
void Add_coin(short x, short y, int num);
void Delete_coin(int num);
void Floating_coin(bool direction);

//강
void Add_river(short x, int num);
void Delete_river(int num);
void Floating_river(bool direction);

//몬스터
void Add_monster(short x, short y, int num, bool up);
void Delete_monster(int num);
void Move_monster(int num);
void Floating_monster(bool direction);

//비어있는 객체를 찾는 함수들
short Find_car();
short Find_coin();
short Find_river();

//플로팅시 나올 객체를 선택하는 함수
unsigned short Choose_object();

#endif