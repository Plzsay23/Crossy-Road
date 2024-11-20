#include <stdio.h>
#include "Variable.h"

const char car_down[5][7] = { //자동차 DOWN
    {"n_ww_ "},
    {"@l   l"},
    {" l   l"},
    {"@l___l"},
    {" l__l "}
};
const char car_up[5][7] = { //자동차 UP
    {" l--l "},
    {"@l- -l"},
    {" l   l"},
    {"@l   l"},
    {"u-mm- "}
};

const char monster1[3][7] = { //몬스터
    {" @ @ "},
    {"( o )"},
    {" / \\"}
};

const char train1[6][8] = { //기차
    {" _____ "},
    {"|     |"},
    {"|[]   |"},
    {"|_____|"},
    {" |   | "},
    {" o   o "}
};

char Name[30];  //게임 시작 시 이름을 입력받는 곳

Car* cars; //자동차 객체 배열
Coin* coins; //코인 객체 배열
River* rivers; //강 객체 배열
Monster* monsters; //몬스터 객체 배열
Train* trains; //기차 객체 배열

Car help_car = { 10, 3, 0, 0 }; //게임 설명 화면에서 쓸 자동차 객체
Coin help_coin = { 30, 20, 0 }; //게임 설명 화면에서 쓸 코인 객체
River help_river = { 50, {10, 17, 24, 31, 38}, 0 }; //게임 설명 화면에서 쓸 강 객체
Monster help_monster = { 91, 3, 0, 0 }; //게임 설명 화면에서 쓸 몬스터 객체
Train help_train = { 111, 3, 0}; //게임 설명 화면에서 쓸 기차 객체

User Ranking[RANKING]; //랭킹을 저장할 배열

Color p_rgb = { 255, 255, 255 }; //플레이어 커스텀 색상
Color c_rgb = { 0, 255, 0 }; //자동차
Color m_rgb = { 255, 0, 0 }; //몬스터
Color t_rgb = { 255, 165, 0 }; //기차

unsigned int Score = 0; //플레이어의 점수를 저장할 곳
unsigned int Coins = 0; //플레이어의 코인 개수를 저장할 곳

long extra_display = 0; //화면 플로팅

short start_x = 77, start_y = 29; // x, y의 초기값

//이미지 출력 관련 설정 코드
HWND hwnd; //현재 포그라운드 윈도우의 핸들을 가져옴
HDC hdc; //윈도우의 클라이언트 영역에 대한 디바이스 컨텍스트를 가져옴

//이미지 파일들의 주소를 담을 변수
const char* Chicken = "Images\\Chicken.raw";