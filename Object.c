#include "Object.h"

//좌표를 받아 플레이어 그리기
void Draw_player(short x, short y)
{
    gotoxy(x, y); printf("○");
}
//좌표를 받아 플레이어 지우기
void Remove_player(short x, short y)
{
    gotoxy(x, y); printf("  ");
}
//좌표를 받아 코인 그리기
void Draw_coin(short x, short y)
{
    Textcolor(black, brightyellow);
    gotoxy(x, y); printf("○");
    Textcolor(black, white);
}
//좌표를 받아 코인 지우기
//현재 코인과 플레이어 디자인이 같음, 지금만 같은 뿐임
void Remove_coin(short x, short y)
{
    gotoxy(x, y); printf("  ");
}
//좌표를 받아 자동차 그리기
void Draw_car(short x, short y)
{
    Textcolor(black, green);
    if (x == 0) //좌측 화면에 붙으면
    {
        gotoxy(x, y - 1); printf("^|");
        gotoxy(x, y);     printf(" |");
        gotoxy(x, y + 1); printf("~|");
    }
    else if (x == 149) //우측 화면에 붙으면
    {
        gotoxy(x - 1, y - 1); printf("|^");
        gotoxy(x - 1, y);     printf("| ");
        gotoxy(x - 1, y + 1); printf("|~");
    }
    else
    {
        gotoxy(x - 1, y - 1); printf("|^|");
        gotoxy(x - 1, y);     printf("| |");
        gotoxy(x - 1, y + 1); printf("|~|");
    }
    Textcolor(black, white);
}
//좌표를 받아 자동차 지우기
void Remove_car(short x, short y)
{
    if (x == 0) //좌측 화면에 붙으면
    {
        gotoxy(x, y - 1); printf("  ");
        gotoxy(x, y);     printf("  ");
        gotoxy(x, y + 1); printf("  ");
    }
    else if (x == 149) //우측 화면에 붙으면
    {
        gotoxy(x - 1, y - 1); printf("  ");
        gotoxy(x - 1, y);     printf("  ");
        gotoxy(x - 1, y + 1); printf("  ");
    }
    else
    {
        gotoxy(x - 1, y - 1); printf("   ");
        gotoxy(x - 1, y);     printf("   ");
        gotoxy(x - 1, y + 1); printf("   ");
    }
}

//자동차 객체와 닿았는지를 판별하는 함수
bool Check_over(short x, short y)
{
    for (int i = 0; i < CARS; i++) //모든 자동차 객체를 검사
    {
        if (cars[i].on == true) //객체가 활성화되어 있다면
        {
            if (cars[i].x - 1 <= x && x <= cars[i].x + 1 &&
                cars[i].y - 1 <= y && y <= cars[i].y + 1)
                return 1; //자동차 객체의 범위와 겹치면 1을 반환
        }
    }

    if (help_screen_car.on == true) //게임설명화면의 자동차 객체
    {
        if (help_screen_car.x - 1 <= x && x <= help_screen_car.x + 1 &&
            help_screen_car.y - 1 <= y && y <= help_screen_car.y + 1)
            return 1; //자동차 객체의 범위와 겹치면 1을 반환
    }

    return 0; //안겹치면 0을 반환
}
//코인 객체와 닿았는지를 판별하는 함수
bool Check_coin(short x, short y)
{
    for (int i = 0; i < COINS; i++) //모든 자동차 객체를 검사
    {
        if (coins[i].on == true) //객체가 활성화되어 있다면
        {
            if (coins[i].x <= x && x <= coins[i].x + 1 &&
                coins[i].y == y) //코인 객체의 좌표와 겹치면  
            {
                Delete_coin(i); Score += 50;
                Coins++; //코인 획득
                return 1; //코인을 지우고 1을 반환   
            }
        }
    }
}

//자동차를 그리고 객체 하나의 좌표를 설정하는 함수
void Add_car(short x, short y, int num, bool up)
{
    Draw_car(x, y);                         //해당 위치에 자동차를 먼저 그리고
    cars[num].x = x;     cars[num].y = y;   //x, y값을 객체에 집어넣고
    cars[num].on = true; cars[num].up = up; //해당 객체를 활성화 함과 동시에 기본설정은 위로 전진
}
//자동차 객체를 삭제하는 함수
void Delete_car(int num)
{
    Remove_car(cars[num].x, cars[num].y); //자동차를 지운다음
    cars[num].on = false;                 //해당 객체 비활성화
}
//자동차 객체를 한 칸 이동하는 함수
void Move_car(int num)
{
    if (cars[num].on == true) //해당 객체가 활성화되어 있어야만 함수 전문 발동
    {
        if (cars[num].up == true) //해당 객체가 위로 전진이라면
        {
            Remove_car(cars[num].x, cars[num].y--); //자동차를 지움과 동시에 y좌표 수정
            if (cars[num].y <= 1) cars[num].y = 39; //만약 콘솔창을 벗어나면 다시 밑으로 보냄
        }
        else                      //해당 객체가 아래로 전진이라면
        {
            Remove_car(cars[num].x, cars[num].y++); //자동차를 지움과 동시에 y좌표 수정
            if (cars[num].y >= 40) cars[num].y = 1; //만약 콘솔창을 벗어나면 다시 위로 보냄
        }
        Draw_car(cars[num].x, cars[num].y); //그렇게 좌표 수정이 모두 완료되면 자동차를 그려 움직임 표현
    }
}
//화면이 움직임에 따라 자동차 객체를 이동하는 함수
void Floating_car(bool direction)
{ //direction이 0 이면 좌측, direction이 1 이면 우측
    for (int i = 0; i < CARS; i++) //모든 자동차 객체를 검사
    {
        if (cars[i].on == true) //해당 객체가 활성화되어 있다면
        {
            Remove_car(cars[i].x, cars[i].y); //자동차를 먼저 지우고
            if (direction == 0) cars[i].x--;  //왼쪽 오른쪽 방향을 읽어 x좌표 수정
            else cars[i].x++;
            if (cars[i].x < 0 || cars[i].x > 149) //만약 좌우 콘솔창을 벗어난다면
                Delete_car(i);                    //객체 삭제
            else
                Draw_car(cars[i].x, cars[i].y);   //정상이라면 자동차를 그리며 움직임 표현
        }
    }
}

//코인을 그리고 객체 하나의 좌표를 설정하는 함수
void Add_coin(short x, short y, int num)
{
    Draw_coin(x, y);
    coins[num].x = x;     coins[num].y = y; //구조 위와 동일
    coins[num].on = true;
}
//코인 객체를 삭제하는 함수
void Delete_coin(int num)
{
    Remove_coin(coins[num].x, coins[num].y); //코인을 지운다음
    coins[num].on = false;                   //해당 객체 비활성화
}
//화면이 움직임에 따라 코인 객체를 이동하는 함수
void Floating_coin(bool direction)
{ //direction이 0 이면 좌측, direction이 1 이면 우측
    for (int i = 0; i < COINS; i++) //구조 위와 동일
    {
        if (coins[i].on == true)
        {
            Remove_coin(coins[i].x, coins[i].y);
            if (direction == 0) coins[i].x--;
            else coins[i].x++;
            if (coins[i].x < 0 || coins[i].x > 148)
                Delete_coin(i);
            else
                Draw_coin(coins[i].x, coins[i].y);
        }
    }
}

//활성화되지 않은 객체 번호를 찾는 함수
short Find_car() //자동차
{
    for (int i = 0; i < CARS; i++) //모든 객체를 검사
        if (cars[i].on == false) return i;
    //만약 활성화되지 않은 객체의 번호를 찾으면 번호를 반환하며 곧바로 함수 종료
}
short Find_coin() //코인
{
    for (int i = 0; i < COINS; i++)
        if (coins[i].on == false) return i;
}