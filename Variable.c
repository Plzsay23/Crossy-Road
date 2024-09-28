#include <stdio.h>
#include "Variable.h"

char Name[30];  //게임 시작 시 이름을 입력받는 곳

Cars cars[CARS]; //자동차 객체 배열
Coin coins[COINS]; //코인 객체 배열

Cars help_screen_car = { 10, 3, 0, 0 }; //게임 설명 화면에서 쓸 자동차 객체
Coin help_screen_coin = { 30, 20, 0 }; //게임 설명 화면에서 쓸 코인 객체

User Ranking[RANKING]; //랭킹을 저장할 배열

unsigned int Score = 0; //플레이어의 점수를 저장할 곳
unsigned int Coins = 0; //플레이어의 코인 개수를 저장할 곳

long extra_display = 0; //화면 플로팅

short start_x = 77, start_y = 29; // x, y의 초기값