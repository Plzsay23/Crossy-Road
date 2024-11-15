#include "Object.h"

//객체들을 동적으로 할당해주는 함수
void init_object() 
{
    cars = (Car*)malloc(sizeof(Car) * CARS);
    if (cars == NULL) return 0;
    coins = (Coin*)malloc(sizeof(Coin) * COINS);
    if (coins == NULL) return 0;
    rivers = (River*)malloc(sizeof(River) * RIVERS);
    if (rivers == NULL) return 0;
    monsters = (Monster*)malloc(sizeof(Monster) * MONSTERS);
    if (monsters == NULL) return 0;
    trains = (Train*)malloc(sizeof(Train) * TRAINS);
    if (trains == NULL) return 0;
}
//프로그램 종료 전 동적 메모리 할당 해제
void free_object()
{
    free(cars); free(coins); free(rivers);
    free(monsters); free(trains);
}

//좌표를 받아 플레이어 그리기
void Draw_player(short x, short y)
{
    textcolor(p_rgb.r, p_rgb.g, p_rgb.b);
    gotoxy(x, y); printf("G");
    removecolor();
}
//좌표를 받아 플레이어 지우기
void Remove_player(short x, short y)
{
    gotoxy(x, y); printf(" ");
}
//좌표를 받아 코인 그리기
void Draw_coin(short x, short y)
{
    textcolor(255, 255, 102);
    gotoxy(x, y); printf("o");
    removecolor();
}
//좌표를 받아 코인 지우기
//현재 코인과 플레이어 디자인이 같음, 지금만 같은 뿐임
void Remove_coin(short x, short y)
{
    gotoxy(x, y); printf(" ");
}
//좌표를 받아 자동차 그리기
void Draw_car(short x, short y, bool up)
{
    textcolor(c_rgb.r, c_rgb.g, c_rgb.b);
    short range = 6; //자동차의 최대길이 6
    if (x > 144) range = 149 - x; //범위가 넘어가면 잘리도록 구현
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < range; j++)
        {
            gotoxy(x + j, y + i);
            if (up == true)
                printf("%c", car_up[i][j]);
            else
                printf("%c", car_down[i][j]);
        }
    }
    removecolor();
}
//좌표를 받아 자동차 지우기
void Remove_car(short x, short y)
{
    short range = 7;
    if (x > 143) range = 150 - x; //범위가 넘어가면 잘리도록 구현
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < range; j++)
        {
            gotoxy(x + j, y + i);
            printf(" ");
        }
    }
}
//좌표를 받아 강 그리기
void Draw_river(short x, int num)
{
    srand((unsigned int)time(NULL));
    short range = 10; //강의 최대길이 10
    if (x > 140) range = 150 - x; //범위가 넘어가면 잘리도록 구현
    short x_range = x; //x좌표가 0이하로 넘어가는 경우를 지정하기 위한 변수
    if (x < 0) //0좌표로 내려가면
    {
        x_range = 0; range += x; //0으로 고정하고 강의 길이를 줄임
        if (x <= -9) //강이 벽에 닿아 사라지려하면
        {
            Delete_river(num); return; //객체 제거
        }
    }
    bgcolor(0, 0, 255);
    for (int i = 1; i < 40; i++) //강 배경 그리기
    {
        for (int j = 0; j < range; j++)
        {
            gotoxy(x_range + j, i); printf(" ");
        }
    }
    bgcolor(0, 255, 0);
    for (int i = 0; i < RIVERS; i++) //연꽃 다리 그리기
    {
        if (rivers[num].bridge[i] != 0 && rivers[num].bridge[i] != 40) 
        { //연꽃 다리의 y좌표가 0과 40이 아닐때만
            gotoxy(x_range, rivers[num].bridge[i]);
            for (int j = 0; j < range; j++) printf(" ");
        }
    }
    removecolor();
}
//좌표를 받아 강 지우기
void Remove_river(short x)
{
    short range = 10; //강의 최대길이 10
    if (x < 0) range = 11 + x;
    else if (x > 140) range = 150 - x; //범위가 넘어가면 잘리도록 구현
    for (int i = 1; i < 40; i++)
    {
        for (int j = 0; j < range; j++)
        {
            if (x < 0) gotoxy(j, i); 
            else gotoxy(x + j, i); 
            printf(" ");
        }
    }
}
//좌표를 받아 몬스터 그리기
void Draw_monster(short x, short y)
{
    textcolor(m_rgb.r, m_rgb.g, m_rgb.b);
    short range = 5; //몬스터의 최대길이 5
    if (x > 145) range = 149 - x; //범위가 넘어가면 잘리도록 구현
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < range; j++)
        {
            gotoxy(x + j, y + i);
            printf("%c", monster1[i][j]);
        }
    }
    removecolor();
}
//좌표를 받아 몬스터 지우기
void Remove_monster(short x, short y)
{
    short range = 6; //몬스터의 최대길이 5
    if (x > 145) range = 149 - x; //범위가 넘어가면 잘리도록 구현
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < range; j++)
        {
            gotoxy(x + j, y + i);
            printf(" ");
        }
    }
}
//좌표를 받아 기차 그리기
void Draw_train(short x, short y)
{
    textcolor(t_rgb.r, t_rgb.g, t_rgb.b);
    short range = 7; //기차의 너비 최대길이 7
    if (x > 143) range = 149 - x; //범위가 넘어가면 잘리도록 구현
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < range; j++)
        {
            gotoxy(x + j, y + i);
            printf("%c", train[i][j]);
        }
    }
    removecolor();
}
//좌표를 받아 기차 지우기
void Remove_train(short x, short y)
{
    short range = 7; //기차의 최대길이 7
    if (x > 143) range = 149 - x; //범위가 넘어가면 잘리도록 구현
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < range; j++)
        {
            gotoxy(x + j, y + i);
            printf(" ");
        }
    }
}

//자동차 객체와 닿았는지를 판별하는 함수
bool Check_car(short x, short y)
{
    for (int i = 0; i < CARS; i++) //모든 자동차 객체를 검사
    {
        if (cars[i].on == true) //객체가 활성화되어 있다면
        {
            if (cars[i].x <= x && x <= cars[i].x + 5 &&
                cars[i].y <= y && y <= cars[i].y + 4)
                return 1; //자동차 객체의 범위와 겹치면 1을 반환
        }
    }
    if (help_car.on == true) //게임설명화면의 자동차 객체
    {
        if (help_car.x <= x && x <= help_car.x + 5 &&
            help_car.y <= y && y <= help_car.y + 4)
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
            if (coins[i].x == x && coins[i].y == y) //코인 객체의 좌표와 겹치면  
            {
                Delete_coin(i); Score += 50;
                Coins++; //코인 획득
                return 1; //코인을 지우고 1을 반환   
            }
        }
    }
}
//강 객체 위를 지나갈 수 있는지를 판별하는 함수
bool Check_river(short x, short y)
{
    for (int i = 0; i < RIVERS; i++) //모든 강 객체 검사
    {
        if (rivers[i].on == true) //강 객체가 활성화되어있다면
        {
            if (rivers[i].x <= x && x <= rivers[i].x + 9) //x좌표가 강의 위라면
            {
                bool is_over = true;
                for (int j = 0; j < RIVERS; j++) //모든 연꽃 다리 검사
                {
                    if (1 <= rivers[i].bridge[j] && rivers[i].bridge[j] <= 39 
                        && y == rivers[i].bridge[j]) //하나라도 연꽃다리와 y축이 겹치면
                    {
                        is_over = false; break; //문제 없음 is_over = false
                    }
                }
                if (is_over == true) return 1; //하나라도 겹치면 1을 반환
            }
        }
    }
    if (help_river.on == true) //위와 동일
    {
        if (help_river.x <= x && x <= help_river.x + 9)
        {
            bool is_over = true;
            for (int j = 0; j < RIVERS; j++)
            {
                if (1 <= help_river.bridge[j] && help_river.bridge[j] <= 39 
                    && y == help_river.bridge[j])
                {
                    is_over = false; break;
                }
            }
            if (is_over == true) return 1;
        }
    }
    return 0;
}
//몬스터 객체와 닿았는지를 판별하는 함수
bool Check_monster(short x, short y)
{
    for (int i = 0; i < CARS; i++) //모든 몬스터 객체를 검사
    {
        if (cars[i].on == true) //객체가 활성화되어 있다면
        {
            if (cars[i].x <= x && x <= cars[i].x + 4 &&
                cars[i].y <= y && y <= cars[i].y + 3)
                return 1; //몬스터 객체의 범위와 겹치면 1을 반환
        }
    }
    if (help_car.on == true) //게임설명화면의 몬스터 객체
    {
        if (help_monster.x <= x && x <= help_monster.x + 4 &&
            help_monster.y <= y && y <= help_monster.y + 3)
            return 1; //몬스터 객체의 범위와 겹치면 1을 반환
    }

    return 0; //안겹치면 0을 반환
}

//자동차를 그리고 객체 하나의 좌표를 설정하는 함수
void Add_car(short x, short y, int num, bool up)
{
    Draw_car(x, y, up);                         //해당 위치에 자동차를 먼저 그리고
    cars[num].x = x;     cars[num].y = y;   //x, y값을 객체에 집어넣고
    cars[num].on = true; cars[num].up = up; //해당 객체를 활성화 함과 동시에 기본설정은 위로 전진
}
//자동차 객체를 삭제하는 함수
void Delete_car(int num)
{
    Remove_car(cars[num].x, cars[num].y); //자동차를 지운다음
    cars[num].on = false;                 //해당 객체 비활성화
}
//자동차 객체를 "위 아래로" 한 칸 이동하는 함수
void Move_car(int num)
{
    if (cars[num].on == true) //해당 객체가 활성화되어 있어야만 함수 전문 발동
    {
        bool up = true;
        if (cars[num].up == true) //해당 객체가 위로 전진이라면
        {
            up = true;
            Remove_car(cars[num].x, cars[num].y--); //자동차를 지움과 동시에 y좌표 수정
            if (cars[num].y < 0) cars[num].y = 36; //만약 콘솔창을 벗어나면 다시 밑으로 보냄
        }
        else                      //해당 객체가 아래로 전진이라면
        {
            up = false;
            Remove_car(cars[num].x, cars[num].y++); //자동차를 지움과 동시에 y좌표 수정
            if (cars[num].y > 36) cars[num].y = 0; //만약 콘솔창을 벗어나면 다시 위로 보냄
        }
        Draw_car(cars[num].x, cars[num].y, up); //그렇게 좌표 수정이 모두 완료되면 자동차를 그려 움직임 표현
    }
}
//화면이 움직임에 따라 자동차 객체를 이동하는 함수
void Floating_car()
{ //direction이 0 이면 좌측, direction이 1 이면 우측
    for (int i = 0; i < CARS; i++) //모든 자동차 객체를 검사
    {
        if (cars[i].on == true) //해당 객체가 활성화되어 있다면
        {
            Remove_car(cars[i].x, cars[i].y); //자동차를 먼저 지우고
            cars[i].x--;
            if (cars[i].x < 2)
                Delete_car(i);
            else
            {
                if(cars[i].up == true)
                    Draw_car(cars[i].x, cars[i].y, true);   //정상이라면 자동차를 그리며 움직임 표현
                else
                    Draw_car(cars[i].x, cars[i].y, false);
            }
                
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
void Floating_coin()
{ //direction이 0 이면 좌측, direction이 1 이면 우측
    for (int i = 0; i < COINS; i++) //구조 위와 동일
    {
        if (coins[i].on == true)
        {
            Remove_coin(coins[i].x, coins[i].y);
            coins[i].x--;
            if (coins[i].x < 0 || coins[i].x > 148)
                Delete_coin(i);
            else
                Draw_coin(coins[i].x, coins[i].y);
        }
    }
}

//강을 그리고 객체 하나의 좌표를 설정하는 함수
void Add_river(short x, int num)
{
    srand((unsigned int)time(NULL));
    rivers[num].x = x;      // x좌표 설정
    rivers[num].on = true;  //객체 활성화
    int j;
    for (int i = 0; i < rand() % 5 + 1; i++) //연꽃 다리 2~5개 랜덤
    {
        short bridge_y;
    overlap: //조건 루프
        bridge_y = rand() % 39 + 1; //1~39의 랜덤한 y축 선택
        for (j = 0; j < i; j++)
        {
            if (rivers[num].bridge[j] - 1 <= bridge_y &&
                rivers[num].bridge[j] + 1 >= bridge_y) goto overlap; //중복 값이 나오면 다시 goto
        }
        rivers[num].bridge[i] = bridge_y; //연꽃 다리 y축 지정
    }
    Draw_river(x, num);
}
//강 객체를 삭제하는 함수
void Delete_river(int num)
{
    Remove_river(rivers[num].x);
    rivers[num].on = false; //객체 비활성화
    for (int i = 0; i < RIVERS; i++)
    {
        rivers[num].bridge[i] = 0; //모든 다리의 좌표를 0으로 설정하여 초기화
    }
}
//화면이 움직임에 따라 강 객체를 이동하는 함수
/*
void Floating_river()
{ //direction이 0 이면 좌측, direction이 1 이면 우측
    for (int i = 0; i < RIVERS; i++) //모든 강 객체를 검사
    {
        if (rivers[i].on == true) //해당 객체가 활성화되어 있다면
        {
            Remove_river(rivers[i].x); //강을 먼저 지우고
            rivers[i].x--;
            Draw_river(rivers[i].x, i);
        }
    }
}
*/
void Floating_river()
{
    for (int i = 0; i < RIVERS; i++) //모든 강 객체를 검사
    {
        if (rivers[i].on == true) //해당 객체가 활성화되어 있다면
        {
            if (--rivers[i].x <= -10) Delete_river(i); //범위를 벗어나면 객체 삭제
            else
            {
                for (int j = 1; j < 40; j++)
                {
                    bgcolor(0, 0, 255);
                    if (rivers[i].x > 0) //x좌표가 0보다 크면 좌측으로 1칸 이동 표현
                    {
                        gotoxy(rivers[i].x, j); printf(" ");
                    }
                    removecolor();
                    if (rivers[i].x < 140) //우측의 한 줄 삭제
                    { 
                        gotoxy(rivers[i].x + 10, j); printf(" ");
                    }
                }
                bgcolor(0, 255, 0);
                for (int j = 0; j < RIVERS; j++) //연꽃 다리 그리기
                {
                    if (rivers[i].bridge[j] != 0 && rivers[i].bridge[j] != 40)
                    {
                        if (rivers[i].x > 0) //x좌표가 0보다 클때만 좌측에 출력
                        {
                            gotoxy(rivers[i].x, rivers[i].bridge[j]); printf(" ");
                        }
                    }
                }
                removecolor();
            }
        }
    }
}

//몬스터를 그리고 객체 하나의 좌표를 설정하는 함수
void Add_monster(short x, short y, int num, bool up)
{
    Draw_monster(x, y);                             //해당 위치에 몬스터를 먼저 그리고
    monsters[num].x = x;     monsters[num].y = y;   //x, y값을 객체에 집어넣고
    monsters[num].on = true; monsters[num].up = up; //해당 객체를 활성화 함과 동시에 기본설정은 위로 전진
}
//몬스터 객체를 삭제하는 함수
void Delete_monster(int num)
{
    Remove_monster(monsters[num].x, monsters[num].y); //몬스터를 지운다음
    monsters[num].on = false;                         //해당 객체 비활성화
}
//몬스터 객체를 "위 아래로" 한 칸 이동하는 함수
void Move_monster(int num)
{
    if (monsters[num].on == true) //해당 객체가 활성화되어 있어야만 함수 전문 발동
    {
        if (monsters[num].up == true) //해당 객체가 위로 전진이라면
        {
            Remove_monster(monsters[num].x, monsters[num].y--); //몬스터를 지움과 동시에 y좌표 수정
            if (monsters[num].y < 0) monsters[num].y = 37; //만약 콘솔창을 벗어나면 다시 밑으로 보냄
        }
        else                      //해당 객체가 아래로 전진이라면
        {
            Remove_monster(monsters[num].x, monsters[num].y++); //몬스터를 지움과 동시에 y좌표 수정
            if (monsters[num].y > 37) monsters[num].y = 0; //만약 콘솔창을 벗어나면 다시 위로 보냄
        }
        Draw_monster(monsters[num].x, monsters[num].y); //그렇게 좌표 수정이 모두 완료되면 몬스터를 그려 움직임 표현
    }
}
//화면이 움직임에 따라 몬스터 객체를 이동하는 함수
void Floating_monster()
{
    for (int i = 0; i < MONSTERS; i++) //모든 몬스터 객체를 검사
    {
        if (monsters[i].on == true) //해당 객체가 활성화되어 있다면
        {
            Remove_monster(monsters[i].x, monsters[i].y); //몬스터를 먼저 지우고
            monsters[i].x--;
            if (monsters[i].x < 3)
                Delete_monster(i);
            else
            {
                Draw_monster(monsters[i].x, monsters[i].y);   //정상이라면 몬스터를 그리며 움직임 표현
            }
        }
    }
}

//기차를 그리고 객체 하나의 좌표를 설정하는 함수
void Add_train(short x, short y, int num)
{
    Draw_train(x, y);           //해당 위치에 기차를 먼저 그리고
    trains[num].x = x; trains[num].y = y; //x, y값을 객체에 집어넣고
    trains[num].on = true;           //객체를 활성화
}
//기차 객체를 삭제하는 함수
void Delete_train(int num)
{
    Remove_train(trains[num].x, trains[num].y); //기차를 지운다음
    trains[num].on = false;                //객체 비활성화
}
//기차 객체를 아래로 한 칸 이동하는 함수
void Move_train(int num)
{
    if (trains[num].on == true) //객체가 활성화되어 있어야만 함수 전문 발동
    {
        Remove_train(trains[num].x, trains[num].y++); //기차를 지움
        if (trains[num].y > 34) Delete_train(num); //만약 콘솔창을 벗어나면 객체 삭제
        else Draw_train(trains[num].x, trains[num].y); //좌표 수정 후 기차를 그려 움직임 표현
    }
    if (trains[0].on == true)
    {
        trains[0].cpy++;
        if(trains[0].cpy % 6 == 0)
            Add_train(trains[0].x, 1, Find_train());
    }
}
//화면이 움직임에 따라 기차 객체를 이동하는 함수
void Floating_train()
{ 
    for (int i = 0; i < TRAINS; i++) //모든 기차 객체를 검사
    {
        if (trains[i].on == true) //객체가 활성화되어 있다면
        {
            Remove_train(trains[i].x, trains[i].y); //기차를 먼저 지우고
            trains[i].x--;
            if (trains[i].x < 2)
                Delete_train(i);
            else
            {
                Draw_train(trains[i].x, trains[i].y); //정상이라면 기차를 그리며 움직임 표현
            }
        }
    }
}

//활성화되지 않은 객체 번호를 찾는 함수
short Find_car() //자동차
{
    for (int i = 0; i < CARS; i++) //모든 객체를 검사
        if (cars[i].on == false) return i;
    //만약 활성화되지 않은 객체의 번호를 찾으면 번호를 반환하며 곧바로 함수 종료
    exit(1); //객체가 가득차있으면 강제종료, 그럴 일이 없도록 설계되어있으므로 치명적인 오류로 간주
}
short Find_coin() //코인
{
    for (int i = 0; i < COINS; i++)
        if (coins[i].on == false) return i;
    exit(1);
}
short Find_river() //강
{
    for (int i = 0; i < RIVERS; i++)
        if (rivers[i].on == false) return i;
    exit(1);
}
short Find_monster() //몬스터
{
    for (int i = 0; i < MONSTERS; i++)
        if (monsters[i].on == false) return i;
    exit(1);
}
short Find_train() //기차
{
    for (int i = 0; i < TRAINS; i++)
        if (trains[i].on == false) return i;
    //exit(1);
}

//플로팅시 나올 객체를 선택하는 함수
unsigned short Choose_object()
{
    static unsigned short choose = 0;
    choose++; if (choose >= 65532) choose = 0; //unsigned short의 최댓값을 넘어가면 0으로 초기화
    return choose % 4 + 1;

    /*
    int arr[] = {1,1,1,2,1,1,1,3,1,1,1,4};
    static int index = 0;
    return arr[index++];
    */
}