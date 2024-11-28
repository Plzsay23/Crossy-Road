#ifndef SCREEN_H  // 헤더 가드
#define SCREEN_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "Setting.h"
#include "Variable.h"
#include "Object.h"
#include "Game.h"

//그림 그리는 함수들
void Draw_square();
void Main_screen_letter();
void Main_screen_cloud();
void Main_screen_car();

//메인스크린
void Main_screen();

//새로하기
void Start_screen();

//이름 중복 검사 - 로그인
bool Check_continue();
//이어하기
void Continue_screen();

//이름 중복 검사 - 로그인
void Into_color_screen();
//색상화면
void Color_screen();
//색상을 바꾸는 화면
void Color_set_screen(int obj);

//설명화면
void Help_screen();

//랭킹화면
void Ranking_screen();

#endif