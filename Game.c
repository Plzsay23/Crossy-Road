#include "Game.h"

//게임오버
void Game_over(short x, short y)
{
    Remove_player(x, y);
    Sleep(1500);
}

//게임 시작전 초기화
void Recycle()
{
    for (int i = 0; i < CARS; i++)
    {
        cars[i].x = 0; cars[i].y = 0;
        cars[i].on = false; cars[i].up = false;
    }
    for (int i = 0; i < COINS; i++)
    {
        coins[i].x = 0; coins[i].y = 0;
        coins[i].on = false;
    }
    for (int i = 0; i < RIVER; i++)
    {
        rivers[i].x = 0; rivers[i].on = false;
        for (int j = 0; j < RIVER; j++)
            rivers[i].bridge[j] = 0;
    }
}

//인게임
void Game()
{
    system("cls"); srand((unsigned int)time(NULL)); //난수 생성을 위해 시드 고정
    Recycle(); //객체 속성값 초기화

    clock_t cars_time = clock();  //자동차가 움직일 시간 저장
    clock_t cars_speed = clock(); //자동차 속도를 조정할 시간 저장

    short x = start_x, y = start_y; //공의 초기 좌표 선언과 함께 초기화
    unsigned short choose = 0; //객체를 선택할 변수
    long floating_x; //x좌표를 저장할 변수
    bool is_spawn = 0; //강이 소환됐는지 아닌지를 판단할 변수

    Draw_player(x, y);


    for (int i = 10; i < 150; i += 10) //초기 화면을 덮을만큼만 자동차 객체 활성화 & 소환
    {
        Add_car(i, rand() % 39 + 1, Find_car(), rand() % 2); //각 인자는 Add_car 함수 참고
    }

    //Add_river(146, 0);

    while (1) //행동 선택
    {
        char input;
        if (_kbhit()) //키보드가 눌렸을때
        {
            input = _getch();
            if (input == RIGHT && x < 148) //오른쪽 이동
            {
                if (Check_river(x, y) == 0) continue; //강 위로 지나갈 수 없다면 돌아감

                if (extra_display < 1000 && x >= start_x) //우측으로 1000칸만 플로팅 되도록 설정
                { //현재 임시로 1000칸, 이후 늘릴지 말지 결정
                    Floating_car(0); //자동차들이 왼쪽으로 밀려나며 이동을 표현
                    Floating_coin(0); //코인들이 왼쪽으로 밀려나며 이동을 표현
                    Floating_river(0); //강 플로팅
                    extra_display++; //플로팅 이동을 변수에 저장

                    if (choose == 0)
                    {
                        choose = Choose_object(); //어떤 객체를 생성할지 선택
                        floating_x = extra_display; //시작하는 x좌표 저장
                    }

                    switch (choose)
                    {
                    case 1: //자동차
                        if (extra_display - floating_x <= 80)
                        {
                            if (extra_display % 10 == 0) //10칸마다 소환
                            {
                                Add_car(148, rand() % 37, Find_car(), rand() % 2);
                                Score += 30; //그럴때마다 30점 추가
                                if (rand() % 100 > 15) //확률은 15%
                                        Add_coin(145, rand() % 41, Find_coin()); //코인 객체 생성
                            }
                        }
                        else choose = 0;
                        break;
                    case 2: //강
                        if (extra_display - floating_x < 40)
                        {
                            if (is_spawn == false && extra_display - floating_x > 10)
                            {
                                Add_river(148, Find_river());
                                Score += 100; is_spawn = 1;
                            }
                        }
                        else
                        {
                            choose = 0; is_spawn = 0;
                        }
                        break;
                    }

                    /*
                    //화면이 움직이며 비는 공간에 주기적으로 자동차 객체 활성화 & 소환
                    if (extra_display < 1000 && (extra_display + x - 79) % 5 == 0)
                    {   //플로팅시 x축은 79로 고정, 이후 플로팅한 칸수가 5칸만큼 늘때마다 객체 생성
                        //즉, 자동차와 자동차 사이의 주기가 5인 셈
                        //■■■■■■■■■■■ x - 79가 항상 0이라 의미가 있는지 살펴볼 필요 있음■■■
                        Add_car(148, rand() % 39 + 1, Find_car(), rand() % 2);
                        Score += 30; //그럴때마다 30점 추가
                        coin_cycle++;
                        if (coin_cycle % 3 == 0) //코인의 등장은 자동차 세개가 지나갈때마다 랜덤
                        {
                            if (rand() % 100 > 50) //확률은 2분의 1
                                Add_coin(145, rand() % 41, Find_coin()); //코인 객체 생성
                            coin_cycle = 0; //현재 확률 총 6분의 1
                        }
                    }
                    */

                    Draw_player(x, y);
                }
                else //플로팅이 아니면
                {
                    Remove_player(x++, y); //공 지우면서 좌표 이동
                    Draw_player(x, y);
                }
                Sleep(10); //약간의 딜레이
            }
            if (input == LEFT && x > 0) //왼쪽 이동
            {
                if (Check_river(x, y) == 0) continue; //강 위를 지나갈 수 없다면 돌아감
                Remove_player(x--, y);
                Draw_player(x, y);
                Sleep(10); //약간의 딜레이
            }
            if (input == UP && y > 0) //위쪽 이동
            {
                Remove_player(x, y--);
                Draw_player(x, y);
                Sleep(10);
            }
            if (input == DOWN && y < 40) //아래쪽 이동
            {
                Remove_player(x, y++);
                Draw_player(x, y);
                Sleep(10);
            }
        }

        if (clock() > cars_time + 100) //100ms마다 발동
        {
            for (int i = 0; i < CARS; i++) Move_car(i); //모든 자동차 객체의 y값을 변경
            cars_time = clock(); //시간 초기화
            Score++; //0.1초마다 1점 추가
        }
        /*
        if (clock() > cars_speed + 5) //랜덤한 객체를 선정해 속도 순간적으로 가속
        {
            int car = rand() % CARS; //아무거나 선정
            Move_car(car); //하나의 자동차만 가속
            cars_speed = clock(); //시간 초기화
        }
        */
        if (Check_over(x, y) == 1) //충돌감지 함수가 1을 반환하면 게임오버
        {
            Game_over(x, y); break;
        }
        if (Check_coin(x, y) == 1) //코인과 부딪혔다면
        {

            Draw_player(x, y);
        }
    }

    Ranking_sort(); //랭킹 정렬
    Ranking_screen(); //랭킹 화면
}
