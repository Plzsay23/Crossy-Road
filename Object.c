#define _CRT_SECURE_NO_WARNINGS
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
    items = (Item*)malloc(sizeof(Item) * ITEMS);
    if (items == NULL) return 0;
}
//프로그램 종료 전 동적 메모리 할당 해제
void free_object()
{
    free(cars); free(coins); free(rivers);
    free(monsters); free(trains); free(items);
}

//좌표를 받아 객체를 그려주는 함수
void Draw_object(int object, short x, short y, int x_range, int y_range, bool up)
{
    for (int i = 0; i < y_range; i++) //y축 길이
    {
        for (int j = 0; j < x_range; j++) //x축 길이
        {   //x,y가 화면 밖을 벗어날 때, 범위 재지정
            int x_coord, y_coord, row_index, col_index;
            x_coord = (x >= 0) ? x + j : j;
            y_coord = (y >= 0) ? y + i : i;
            row_index = (y >= 0) ? i : i - y;
            col_index = (x >= 0) ? j : j - x;
            gotoxy(x_coord, y_coord); //재지정된 좌표로 이동

            if (object == car) //객체가 자동차면
            {
                if (up == true) //위로 올라가는 객체면
                    printf("%c", car_up[row_index][col_index]); //car_up
                else            //아래로 내려가면 객체면
                    printf("%c", car_down[row_index][col_index]); //car_down
            }
            else if(object == monster) //객체가 몬스터면
                printf("%c", monster1[row_index][col_index]);
            else if(object == train)   //객체가 기차면
                printf("%c", train1[row_index][col_index]);
        }
    }
}
//좌표를 받아 객체를 지워주는 함수
void Remove_object(short x, short y, int x_range, int y_range)
{
    for (int i = 0; i < y_range; i++) //y축 길이
    {
        for (int j = 0; j < x_range; j++) //x축 길이
        {   //x,y가 화면 밖을 벗어날 때, 범위 재지정
            int x_coord, y_coord;
            x_coord = (x >= 0) ? x + j : j;
            y_coord = (y >= 0) ? y + i : i;
            gotoxy(x_coord, y_coord); printf(" "); //재지정된 좌표로 이동 후 빈칸 그림
        }
    }
}

//좌표를 받아 플레이어 그리기
void Draw_player(short x, short y)
{
    if (varrier_on) textcolor(152, 255, 152);       //배리어 색상 지정
    else if (point_on) textcolor(122, 201, 88);     //포인트 색상 지정
    else if (invincible_on) textcolor(255, 215, 0); //무적 색상 지정
    else textcolor(p_rgb.r, p_rgb.g, p_rgb.b);      //평소 색상 지정
    gotoxy(x, y); printf("G");            //좌표 이동 후 그림
    removecolor();                        //색상 삭제
}
//좌표를 받아 플레이어 지우기
void Remove_player(short x, short y)
{
    gotoxy(x, y); printf(" ");
}


/*자동차 객체 관련 함수*/


//좌표를 받아 자동차 그리기
void Draw_car(short x, short y, bool up)
{
    textcolor(c_rgb.r, c_rgb.g, c_rgb.b); //색상 지정
    short x_range = 6;              //자동차의 x 길이 6
    if (x > 144) x_range = 149 - x; //범위를 넘어가면 잘리도록 구현
    else if (x < 0) x_range += x;   //범위를 넘어가면 앞부터 잘리도록 구현
    short y_range = 5;              //자동차의 y 길이 5
    if (y > 36) y_range = 41 - y;   //범위를 넘어가면 잘리도록 구현
    else if (y < 0)  y_range += y;  //범위를 넘어가면 위부터 잘리도록 구현
    Draw_object(car, x, y, x_range, y_range, up); //지정된 좌표에 그리기
    removecolor();
}
//좌표를 받아 자동차 지우기
void Remove_car(short x, short y)
{
    short x_range = 6;              //자동차의 x 길이 6
    if (x > 144) x_range = 149 - x; //범위를 넘어가면 잘리도록 구현
    else if (x < 0) x_range += x;   //범위를 넘어가면 앞부터 잘리도록 구현
    short y_range = 5;              //자동차의 y 길이 5
    if (y > 36) y_range = 41 - y;   //범위를 넘어가면 잘리도록 구현
    else if (y < 0)  y_range += y;  //범위를 넘어가면 위부터 잘리도록 구현
    Remove_object(x, y, x_range, y_range);
}
//자동차를 그리고 객체 하나의 좌표를 설정하는 함수
void Add_car(short x, short y, int num, bool up)
{
    Draw_car(x, y, up);                         //해당 위치에 자동차를 먼저 그리고
    cars[num].x = x;     cars[num].y = y;       //x, y값을 객체에 집어넣고
    cars[num].on = true; cars[num].up = up;     //해당 객체를 활성화 함과 동시에 기본설정은 위로 전진
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
        bool up;
        if (cars[num].up == true) //해당 객체가 위로 전진이라면
        {
            up = true;
            Remove_car(cars[num].x, cars[num].y--); //자동차를 지움과 동시에 y좌표 수정
            if (cars[num].y < -4) cars[num].y = 40; //만약 콘솔창을 벗어나면 다시 밑으로 보냄
        }
        else                      //해당 객체가 아래로 전진이라면
        {
            up = false;
            Remove_car(cars[num].x, cars[num].y++); //자동차를 지움과 동시에 y좌표 수정
            if (cars[num].y > 40) cars[num].y = -4; //만약 콘솔창을 벗어나면 다시 위로 보냄
        }
        Draw_car(cars[num].x, cars[num].y, up); //그렇게 좌표 수정이 모두 완료되면 자동차를 그려 움직임 표현
    }
}
//화면이 움직임에 따라 자동차 객체를 이동하는 함수
void Floating_car()
{
    for (int i = 0; i < CARS; i++) //모든 자동차 객체를 검사
    {
        if (cars[i].on == true) //해당 객체가 활성화되어 있다면
        {
            Remove_car(cars[i].x--, cars[i].y); //자동차를 먼저 지우고
            if (cars[i].x < -5) //좌표를 벗어나면 삭제
                Delete_car(i);
            else
            {
                if (cars[i].up == true)
                    Draw_car(cars[i].x, cars[i].y, true); //정상이라면 자동차를 그리며 움직임 표현
                else
                    Draw_car(cars[i].x, cars[i].y, false);
            }

        }
    }
}


/*코인 객체 관련 함수*/


//좌표를 받아 코인 그리기
void Draw_coin(short x, short y)
{
    textcolor(255, 255, 102);  //코인은 색상 고정
    gotoxy(x, y); printf("o");
    removecolor();
}
//좌표를 받아 코인 지우기
void Remove_coin(short x, short y)
{
    gotoxy(x, y); printf(" ");
}
//코인을 그리고 객체 하나의 좌표를 설정하는 함수
void Add_coin(short x, short y, int num)
{
    Draw_coin(x, y);                        //해당 위치에 코인을 먼저 그리고
    coins[num].x = x;     coins[num].y = y; //x,y 값을 객체에 집어넣고
    coins[num].on = true;                   //해당 객체를 활성화
}
//코인 객체를 삭제하는 함수
void Delete_coin(int num)
{
    Remove_coin(coins[num].x, coins[num].y); //코인을 지운다음
    coins[num].on = false;                   //해당 객체 비활성화
}
//화면이 움직임에 따라 코인 객체를 이동하는 함수
void Floating_coin()
{
    for (int i = 0; i < COINS; i++) //구조 위와 동일
    {
        if (coins[i].on == true)
        {
            Remove_coin(coins[i].x--, coins[i].y);
            if (coins[i].x < 0 || coins[i].x > 149)
                Delete_coin(i);
            else
                Draw_coin(coins[i].x, coins[i].y);
        }
    }
}


/*강 객체 관련 함수*/


//좌표를 받아 강 그리기
void Draw_river(short x, int num)
{
    srand((unsigned int)time(NULL));
    short range = 10;               //강의 최대길이 10
    if (x > 140) range = 150 - x;   //범위를 넘어가면 잘리도록 구현
    short x_range = x;              //x좌표가 0이하로 넘어가는 경우를 지정하기 위한 변수
    if (x < 0)                      //0좌표보다 내려가면
    {
        x_range = 0; range += x;    //시작좌표를 0으로 고정하고 강의 길이를 줄임
        if (x <= -9)                //강이 벽에 닿아 사라지려하면
        {
            Delete_river(num); return; //객체 제거
        }
    }
    bgcolor(0, 0, 255);             //배경색 Blue
    for (int i = 0; i <= 40; i++)    //y축 길이
    {
        for (int j = 0; j < range; j++) //x축 길이
        {
            gotoxy(x_range + j, i); printf(" ");
        }
    }
    bgcolor(0, 255, 0);              //배경색 Green
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
    short range = 10;                   //강의 최대길이 10
    if (x < 0) range = 11 + x;          //범위를 넘어가면 잘리도록 구현
    else if (x > 140) range = 150 - x;  //범위를 넘어가면 잘리도록 구현
    for (int i = 1; i < 40; i++)        //y축 길이
    {
        for (int j = 0; j < range; j++) //x축 길이
        {
            if (x < 0) gotoxy(j, i);    //x가 0보다 작으면 x는 0으로 고정
            else gotoxy(x + j, i);      
            printf(" ");
        }
    }
}
//강을 그리고 객체 하나의 좌표를 설정하는 함수
void Add_river(short x, int num)
{
    srand((unsigned int)time(NULL));
    rivers[num].x = x;      // x좌표 설정
    rivers[num].on = true;  //객체 활성화
    for (int i = 0; i < rand() % 5 + 1; i++) //연꽃 다리 2~5개 랜덤
    {
        short bridge_y;
    overlap: //조건 루프
        bridge_y = rand() % 39 + 1; //1~39의 랜덤한 y축 선택
        for (int j = 0; j < i; j++)
        {
            if (rivers[num].bridge[j] - 1 <= bridge_y &&
                rivers[num].bridge[j] + 1 >= bridge_y) goto overlap; //중복 값이 나오면 다시 goto
        }
        rivers[num].bridge[i] = bridge_y; //연꽃 다리 y축 지정
    }
    Draw_river(x, num); //모두 확인 후 강 그리기
}
//강 객체를 삭제하는 함수
void Delete_river(int num)
{
    Remove_river(rivers[num].x); //강 지우고
    rivers[num].on = false; //객체 비활성화
    for (int i = 0; i < RIVERS; i++)
        rivers[num].bridge[i] = 0; //모든 다리의 좌표를 0으로 설정하여 초기화
}
//화면이 움직임에 따라 강 객체를 이동하는 함수
void Floating_river()
{
    for (int i = 0; i < RIVERS; i++) //모든 강 객체를 검사
    {
        if (rivers[i].on == true) //해당 객체가 활성화되어 있다면
        {
            if (--rivers[i].x <= -10) Delete_river(i); //범위를 벗어나면 객체 삭제
            else
            {
                for (int j = 0; j <= 40; j++)
                {
                    bgcolor(0, 0, 255);
                    if (rivers[i].x >= 0) //x좌표가 0이상이면 좌측으로 1칸 이동 표현
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
                        if (rivers[i].x >= 0) //x좌표가 0이상일 때만 좌측에 출력
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


/*몬스터 객체 관련 함수*/


//좌표를 받아 몬스터 그리기
void Draw_monster(short x, short y)
{
    textcolor(m_rgb.r, m_rgb.g, m_rgb.b);   //색상 지정
    short x_range = 6;                      //몬스터의 x길이 5
    if (x > 144) x_range = 149 - x;         //범위를 넘어가면 잘리도록 구현
    else if (x < 0) x_range += x;           //범위를 넘어가면 앞부터 잘리도록 구현
    short y_range = 3;                      //몬스터의 y길이 3
    if (y > 38) y_range = 41 - y;           //범위를 넘어가면 잘리도록 구현
    else if (y < 0) y_range += y;           //범위를 넘어가면 위부터 잘리도록 구현
    Draw_object(monster, x, y, x_range, y_range, 1); //지정된 좌표에 그리기
    removecolor();
}
//좌표를 받아 몬스터 지우기
void Remove_monster(short x, short y)
{
    short x_range = 6;                      //몬스터의 x길이 5
    if (x > 144) x_range = 149 - x;         //범위를 넘어가면 잘리도록 구현
    else if (x < 0) x_range += x;           //범위를 넘어가면 앞부터 잘리도록 구현
    short y_range = 3;                      //몬스터의 y길이 3
    if (y > 38) y_range = 41 - y;           //범위를 넘어가면 잘리도록 구현
    else if (y < 0) y_range += y;           //범위를 넘어가면 위부터 잘리도록 구현
    Remove_object(x, y, x_range, y_range);
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
            if (monsters[num].y < -2) monsters[num].y = 40; //만약 콘솔창을 벗어나면 다시 밑으로 보냄
        }
        else                      //해당 객체가 아래로 전진이라면
        {
            Remove_monster(monsters[num].x, monsters[num].y++); //몬스터를 지움과 동시에 y좌표 수정
            if (monsters[num].y > 40) monsters[num].y = -2; //만약 콘솔창을 벗어나면 다시 위로 보냄
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
            Remove_monster(monsters[i].x--, monsters[i].y); //몬스터를 먼저 지우고
            if (monsters[i].x < -5) Delete_monster(i); //좌표를 벗어나면 삭제
            else
            {
                Draw_monster(monsters[i].x, monsters[i].y);   //정상이라면 몬스터를 그리며 움직임 표현
            }
        }
    }
}


/*기차 객체 관련 함수*/


//좌표를 받아 기차 그리기
void Draw_train(short x, short y)
{
    textcolor(t_rgb.r, t_rgb.g, t_rgb.b);   //색상 지정
    short x_range = 7;                      //기차의 x길이 7
    if (x > 143) x_range = 149 - x;         //범위를 넘어가면 잘리도록 구현
    else if (x < 0) x_range += x;           //범위를 넘어가면 앞부터 잘리도록 구현
    short y_range = 6;                      //기차의 y길이 6
    if (y > 35) y_range = 41 - y;           //범위를 넘어가면 잘리도록 구현
    Draw_object(train, x, y, x_range, y_range, 1); //지정된 좌표에 그리기
    removecolor();
}
//좌표를 받아 기차 지우기
void Remove_train(short x, short y)
{
    short x_range = 7;                      //기차의 x길이 7
    if (x > 143) x_range = 149 - x;         //범위를 넘어가면 잘리도록 구현
    else if (x < 0) x_range += x;           //범위를 넘어가면 앞부터 잘리도록 구현
    short y_range = 6;                      //기차의 y길이 6
    if (y > 35) y_range = 41 - y;           //범위를 넘어가면 잘리도록 구현
    Remove_object(x, y, x_range, y_range);
}
//기차를 그리고 객체 하나의 좌표를 설정하는 함수
void Add_train(short x, short y, int num)
{
    Draw_train(x, y);                       //해당 위치에 기차를 먼저 그리고
    trains[num].x = x; trains[num].y = y;   //x, y값을 객체에 집어넣고
    trains[num].on = true;                  //해당 객체를 활성화
}
//기차 객체를 삭제하는 함수
void Delete_train(int num)
{
    Remove_train(trains[num].x, trains[num].y); //기차를 지운다음
    trains[num].on = false;                     //객체 비활성화
}
//기차 객체를 아래로 한 칸 이동하는 함수
void Move_train(int num)
{
    if (trains[0].on == true) //객체가 활성화되어 있어야만 함수 전문 발동
    {
        static short train_y = 0; //y값을 저장할 정적 변수
        train_y++; //1칸씩 증가
        if (train_y % 6 == 0 && train_y <= 36) //일정 범위 내에서 6칸 마다
            Add_train(trains[0].x, train_y, Find_train()); //기차를 줄지어서 소환
        else if (train_y > 36) //범위를 벗어나면
        {
            train_y = 0; trains[0].on = false; //첫 기차는 삭제
        }
    }
}
//화면이 움직임에 따라 기차 객체를 이동하는 함수
void Floating_train()
{
    train_x--; //기차의 절대적인 x좌표를 항상 이동
    for (int i = 0; i < TRAINS; i++) //모든 기차 객체를 검사
    {
        if (trains[i].on == true) //객체가 활성화되어 있다면
        {
            Remove_train(trains[i].x--, trains[i].y); //기차를 먼저 지우고
            if (trains[i].x < -6) Delete_train(i); //좌표를 벗어나면 삭제
            else
                Draw_train(trains[i].x, trains[i].y); //정상이라면 기차를 그리며 움직임 표현
        }
    }
}


/*아이템 객체 관련 함수*/


//좌표를 받아 아이템 그리기
void Draw_item(short x, short y, int type)
{
    int r = 0, g = 0, b = 0; char item[3] = " "; gotoxy(x, y);
    switch (type)
    {
    case varrier:
        r = 100; g = 100; b = 100;
        strcpy(item, "ⓥ"); break;
    case point:
        r = 150, g = 50, b = 255;
        strcpy(item, "ⓟ"); break;
    case invincible:
        r = 50, g = 255, b = 150;
        strcpy(item, "ⓘ"); break;
    case fever:
        r = 100, g = 0, b = 255;
        strcpy(item, "ⓕ"); break;
    case _time:
        r = 75, g = 175, b = 255;
        strcpy(item, "ⓣ"); break;
    case star:
        r = 255; g = 215; b = 0;
        strcpy(item, "★"); break;
    default: break;
    }
    textcolor(r, g, b); 
    printf("%s", item);
    removecolor();
}
//좌표를 받아 아이템 지우기
void Remove_item(short x, short y)
{
    gotoxy(x, y); printf("  ");
}
//아이템을 그리고 객체 하나의 좌표를 설정하는 함수
void Add_item(short x, short y, int num, int type)
{
    Draw_item(x, y, type);                        //해당 위치에 아이템을 먼저 그리고
    items[num].x = x;     items[num].y = y;       //x,y 값을 객체에 집어넣고
    items[num].on = true; items[num].type = type; //해당 객체를 활성화
}
//아이템 객체를 삭제하는 함수
void Delete_item(int num)
{
    Remove_item(items[num].x, items[num].y); //아이템을 지운다음
    items[num].on = false;                   //해당 객체 비활성화
}
//화면이 움직임에 따라 아이템 객체를 이동하는 함수
void Floating_item()
{
    for (int i = 0; i < ITEMS; i++) //구조 위와 동일
    {
        if (items[i].on == true)
        {
            Remove_item(items[i].x--, items[i].y);
            if (items[i].x < 0 || items[i].x > 148)
                Delete_item(i);
            else
                Draw_item(items[i].x, items[i].y, items[i].type);
        }
    }
}
//배리어 아이템 사용 함수 & 버릴 수도
void Item_varrier()
{
    varrier_on = true; //배리어 온
}
//점수 두배 아이템 사용 함수
void Item_point(int time)
{
    point_on = true; //포인트 온
    point_duration = time; //지속시간 설정
}
//피버 아이템 사용 함수
void Item_fever(int time)
{
    point_on = true; //포인트 온
    point_duration = time; //지속시간 설정
    invincible_on = true; //무적 온
    invincible_duration = time; //지속시간 설정
}
//무적 아이템 사용 함수
void Item_invincible(int time)
{
    invincible_on = true; //무적 온
    invincible_duration = time; //지속시간 설정
}
//타임 아이템 사용 함수
void Item_time(int time)
{
    time_on = true; //타임 온
    time_duration = time; //지속시간 설정
}


/*충돌 감지 함수들*/


//자동차 객체와 닿았는지를 판별하는 함수
bool Check_car(short x, short y)
{
    for (int i = 0; i < CARS; i++) //모든 자동차 객체를 검사
    {
        if (cars[i].on == true) //객체가 활성화되어 있다면
        {
            if (cars[i].x <= x && x <= cars[i].x + 5 &&
                cars[i].y <= y && y <= cars[i].y + 4)
            {
                if (varrier_on) //배리어가 있다면
                {
                    varrier_on = 0; Item_invincible(1); //배리어 해제 후 1초 무적
                    return 0; //충돌 1회 방어
                }
                else return 1; //자동차 객체의 범위와 겹치면 1을 반환
            }
        }
    }
    return 0; //안겹치면 0을 반환
}
bool Check_help_car(short x, short y)
{
    if (help_car.on == true) //게임설명화면의 자동차 객체
    {
        if (help_car.x <= x && x <= help_car.x + 5 &&
            help_car.y <= y && y <= help_car.y + 4)
        {
            if (varrier_on) //배리어가 있다면
            {
                varrier_on = 0; Item_invincible(1); //배리어 해제 후 1초 무적
                return 0; //충돌 1회 방어
            }
            else return 1; //자동차 객체의 범위와 겹치면 1을 반환
        }
    }
    return 0;
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
//강 객체 위를 지나갈 수 있는지를 판별하는 함수 + 구조를 좀 바꿀 수 있다면 좋을 듯
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
                if (is_over == true) 
                {
                    if (varrier_on)
                    {
                        varrier_on = 0; Item_invincible(1); //배리어 해제 후 1초 무적
                        return 0; //충돌 1회 방어
                    }
                    else return 1; //하나라도 겹치면 1을 반환
                }
            }
        }
    }
    return 0;
}
bool Check_help_river(short x, short y)
{
    if (help_river.on == true) //강 객체가 활성화되어 있다면
    {
        if (help_river.x <= x && x <= help_river.x + 9) //x좌표가 강 위라면
        {
            bool is_over = true;
            for (int j = 0; j < RIVERS; j++) //모든 연꽃 다리 검사
            {
                if (1 <= help_river.bridge[j] && help_river.bridge[j] <= 39
                    && y == help_river.bridge[j]) //하나라도 연꽃다리와 y축이 겹치면
                {
                    is_over = false; break; //문제 없음 is_over = false
                }
            }
            if (is_over == true) 
            {
                if (varrier_on)
                {
                    varrier_on = 0; Item_invincible(1); //배리어 해제 후 1초 무적
                    return 0; //충돌 1회 방어
                }
                else return 1; //하나라도 겹치면 1을 반환
            }
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
                cars[i].y <= y && y <= cars[i].y + 2)
            {
                if (varrier_on) //배리어가 있다면
                {
                    varrier_on = 0; Item_invincible(1); //배리어 해제 후 1초 무적
                    return 0; //충돌 1회 방어
                }
                else return 1; //몬스터 객체의 범위와 겹치면 1을 반환
            }
        }
    }
    return 0; //안겹치면 0을 반환
}
bool Check_help_monster(short x, short y)
{
    if (help_car.on == true) //게임설명화면의 몬스터 객체
    {
        if (help_monster.x <= x && x <= help_monster.x + 4 &&
            help_monster.y <= y && y <= help_monster.y + 2)
        {
            if (varrier_on) //배리어가 있다면
            {
                varrier_on = 0; Item_invincible(1); //배리어 해제 후 1초 무적
                return 0; //충돌 1회 방어
            }
            else return 1; //몬스터 객체의 범위와 겹치면 1을 반환
        }
    }
    return 0;
}
//기차 객체와 닿았는지를 판별하는 함수
bool Check_train(short x, short y)
{
    for (int i = 0; i < TRAINS; i++) //모든 기차 객체를 검사
    {
        if (trains[i].on == true) //객체가 활성화되어 있다면
        {
            if (trains[i].x <= x && x <= trains[i].x + 6 &&
                trains[i].y <= y && y <= trains[i].y + 5)
            {
                if (varrier_on) //배리어가 있다면
                {
                    varrier_on = 0; Item_invincible(1); //배리어 해제 후 1초 무적
                    return 0; //충돌 1회 방어
                }
                else return 1; //기차 객체의 범위와 겹치면 1을 반환
            }
        }
    }
}
//아이템 객체와 닿았는지를 판별하는 함수
Itemcheck Check_item(short x, short y)
{
    for (int i = 0; i < ITEMS; i++) //모든 아이템 객체를 검사
    {
        if (items[i].on == true) //객체가 활성화되어 있다면
        {
            if (items[i].x <= x && x <= items[i].x + 1 && 
                items[i].y == y) //아이템 객체의 좌표와 겹치면  
            {
                Delete_item(i);
                switch (items[i].type)
                {
                case varrier:
                    Item_varrier(); break;
                case point:
                    Item_point(3); break;
                case fever:
                    Item_fever(2); break;
                case invincible:
                    Item_invincible(3); break;
                case _time:
                    Item_time(2); break;
                }
                Itemcheck result = { 1, items[i].type };
                return result; //아이템을 지우고 사용 후 1을 반환   
            }
        }
    }
    Itemcheck result = { 0, 0 };
    return result;
}


/*활성화되지 않은 객체 번호를 찾는 함수*/


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
    exit(1);
}
short Find_item() //아이템
{
    for (int i = 0; i < ITEMS; i++)
        if (items[i].on == false) return i;
    exit(1);
}

//플로팅시 나올 객체를 선택하는 함수
unsigned short Choose_object()
{
    int arr[] = {1,1,2,1,1,3,1,1,4}; //정해진 객체의 등장 배열
    static int index = 0;
    if(index == 9) index = 0;
    return arr[index++];
}