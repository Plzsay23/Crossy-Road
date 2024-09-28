#ifndef SETTING_H  // 헤더 가드
#define SETTING_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

void Textcolor(int bgcolor, int txcolor);
void Setting();
void gotoxy(int x, int y);
void Ranking_sort();
void Read_ranking();
void ReadImage(const char* filePath, unsigned char* image);

#endif