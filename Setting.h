#ifndef SETTING_H  // 헤더 가드
#define SETTING_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>

void Textcolor(int bgcolor, int txcolor);
void Setting();
void gotoxy(int x, int y);
void Ranking_sort();
void Read_ranking();
void Play_bgm(const char* filename, bool loop);
void Stop_bgm();
void ReadImage(const char* filePath, unsigned char** image);
void Draw_image_256(const char* filePath, HDC hdc, int offsetX, int offsetY);
void Draw_image_128(const char* filePath, HDC hdc, int offsetX, int offsetY);

#endif