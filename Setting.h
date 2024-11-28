#ifndef SETTING_H  // 헤더 가드
#define SETTING_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>

//글씨, 배경 색상 변경 함수들
void textcolor(int r, int g, int b);
void bgcolor(int r, int g, int b);
void removecolor();

//게임 시작 전 변수값들을 세팅하는 함수
void Setting();

//커서의 위치를 이동하는 함수
void gotoxy(int x, int y);

//랭킹을 정렬하여 저장하고 읽어오는 함수들
void Ranking_sort();
void Read_ranking();

//브금 재생 관련 함수들
void Play_bgm(const char* filename, bool loop);
void Stop_bgm();

//이미지 출력 관련 함수들
void ReadImage(const char* filePath, unsigned char** image);
void Draw_image_256(const char* filePath, HDC hdc, int offsetX, int offsetY);
void Draw_image_128(const char* filePath, HDC hdc, int offsetX, int offsetY);

#endif