#ifndef SETTING_H  // ��� ����
#define SETTING_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>

//�۾�, ��� ���� ���� �Լ���
void textcolor(int r, int g, int b);
void bgcolor(int r, int g, int b);
void removecolor();

//���� ���� �� ���������� �����ϴ� �Լ�
void Setting();

//Ŀ���� ��ġ�� �̵��ϴ� �Լ�
void gotoxy(int x, int y);

//��ŷ�� �����Ͽ� �����ϰ� �о���� �Լ���
void Ranking_sort();
void Read_ranking();

//��� ��� ���� �Լ���
void Play_bgm(const char* filename, bool loop);
void Stop_bgm();

//�̹��� ��� ���� �Լ���
void ReadImage(const char* filePath, unsigned char** image);
void Draw_image_256(const char* filePath, HDC hdc, int offsetX, int offsetY);
void Draw_image_128(const char* filePath, HDC hdc, int offsetX, int offsetY);

#endif