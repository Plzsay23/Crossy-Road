#ifndef VARIABLE_H  // 헤더 가드
#define VARIABLE_H

#include <stdbool.h>
#include <Windows.h>

#define IMAGE_SIZE (256 * 256)
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define RANKING 10
#define CARS 30 // x 길이 150의 콘솔창에선 딱 30개가 한계
#define COINS 30 //현재 최대 코인 값 30개
#define RIVER 5 //강

//색깔 구조체, ex) Textcolor(black, white) 이러면 배경은 검정, 글자는 흰색으로 지정됨
//https://makerejoicegames.tistory.com/115
enum {
    black, blue, green, skyblue, red, pink, orange, white, gray, lightblue,
    brightgreen, sky, brightred, brightpink, brightyellow, brightwhite
};

//자동차 객체 구조체
typedef struct Cars {
    short x;    // x 좌표
    short y;    // y 좌표
    bool on;    //객체의 활성화 유무
    bool up;    //객체가 위로 갈지 아래로 갈지 (1이면 위로, 0이면 아래로)
} Cars;

//코인 구조체
typedef struct Coin {
    short x;    // x 좌표
    short y;    // y 좌표
    bool on;    // 객체의 활성화 유무
} Coin;

//강 구조체
typedef struct River {
    short x;             //배경이 시작될 x좌표
    short bridge[RIVER]; //연꽃 다리가 생성될 y좌표, 최대 5개
    bool on;             //객체의 활성화 유무
} River;

//랭킹 구조체
typedef struct User {
    int score;           //점수
    char name[30];       //사용자 이름
    unsigned int coins;  //코인 개수
} User;

//게임 관련 전역 변수 선언

//자동차 디자인
extern char car_down[5][7];
extern char car_up[5][7];

extern char Name[30];            //게임 시작 시 이름을 입력받는 곳

extern Cars cars[CARS];          //자동차 객체 배열
extern Coin coins[COINS];        //코인 객체 배열
extern River rivers[RIVER];      //강 객체 배열

extern Cars help_screen_car;     //게임 설명 화면에서 쓸 자동차 객체
extern Coin help_screen_coin;    //게임 설명 화면에서 쓸 코인 객체
extern River help_screen_river;  //게임 설명 화면에서 쓸 강 객체

extern User Ranking[RANKING];    //랭킹을 저장할 배열

extern unsigned int Score;       //플레이어의 점수를 저장할 곳
extern unsigned int Coins;       //플레이어의 코인 개수를 저장할 곳

extern long extra_display;       //화면 플로팅, 얼마나 움직였는지를 저장할 변수

extern short start_x, start_y;   // x, y의 초기값

extern HWND hwnd;                //현재 포그라운드 윈도우의 핸들을 가져옴
extern HDC hdc;                  //윈도우의 클라이언트 영역에 대한 디바이스 컨텍스트를 가져옴

//이미지 파일들의 주소를 담을 변수
extern const char* Adrenaline;   //예시

#endif