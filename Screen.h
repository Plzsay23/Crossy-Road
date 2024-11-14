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

void Draw_square();
void Main_screen_letter();
void Main_screen_cloud();
void Main_screen_car();
void Main_screen();
void Start_screen();
bool Check_continue();
void Continue_screen();
void Color_screen();
void Color_set_screen(int obj);
void Help_screen();
void Ranking_screen();

#endif