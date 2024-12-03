#ifndef GAME_H  // 헤더 가드
#define GAME_H

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "Variable.h"
#include "Setting.h"
#include "Screen.h"
#include "Object.h"
#include "Game.h"

//게임 오버 시 잠깐 나올 이벤트
void Game_over(short x, short y);

//객체의 구조체 변수 값들을 초기화하는 함수
void Recycle();

//인게임 함수
void Game();

#endif