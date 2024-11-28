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
    for (int i = 0; i < RIVERS; i++)
    {
        rivers[i].x = 0; rivers[i].on = false;
        for (int j = 0; j < RIVERS; j++)
            rivers[i].bridge[j] = 0;
    }
    for (int i = 0; i < MONSTERS; i++)
    {
        monsters[i].x = 0; monsters[i].y = 0;
        monsters[i].on = false; monsters[i].up = false;
    }
    for (int i = 0; i < TRAINS; i++)
    {
        trains[i].x = 0; trains[i].y = 0;
        trains[i].on = false;
    }
    for (int i = 0; i < ITEMS; i++)
    {
        items[i].x = 0; items[i].y = 0;
        items[i].on = false; items[i].kind = 0;
    }
    extra_display = 0;
}

//인게임
void Game()
{
    system("cls"); srand((unsigned int)time(NULL)); //난수 생성을 위해 시드 고정
    init_object(); //객체 동적 메모리 할당
    Recycle(); //객체 속성값 초기화

    clock_t cars_time = clock();        //자동차가 움직일 시간 저장
    clock_t cars_speed = clock();       //자동차 속도를 조정할 시간 저장
    clock_t monsters_time = clock();    //몬스터가 움직일 시간 저장
    clock_t trains_time = clock();      //기차가 움직일 시간 저장
    clock_t trains_charge = clock();    //기차가 멈춰있을 시간 저장
    clock_t invincible_time = clock();  //무적 지속시간 저장
    clock_t speed_time = clock();       //질주 지속시간 저장

    short x = start_x + 1, y = start_y;     //공의 초기 좌표 선언과 함께 초기화
    unsigned short choose = 0;              //객체를 선택할 변수
    long floating_x, floating_display = 0;  //x좌표를 저장할 변수
    bool is_spawn = 0;                      //객체가 소환됐는지 아닌지를 판단할 변수
    int train_spawn = 0;                    //기차가 소환되었음을 알리는 변수
    bool is_invincible = 0;                 //무적 상태를 판별하는 변수
    bool is_speed = 0;                      //질주 상태를 판별하는 변수

    Draw_player(x, y);

    for (int i = 79; i < 149; i += 8) //초기 화면을 덮을만큼만 자동차 객체 활성화 & 소환
        Add_car(i, rand() % 41, Find_car(), rand() % 2);

    while (1) //행동 선택
    {
        char input;
        if (_kbhit()) //키보드가 눌렸을때
        {
            input = _getch();
            if (input == RIGHT && x < 148) //오른쪽 이동
            {
                floating_display++;
                if (x >= start_x) //현재 x좌표가 중앙보다 크다면
                {
                    for (int i = 0; i < is_speed + 1; i++)
                    {
                        Floating_car();     //자동차들이 왼쪽으로 밀려나며 이동을 표현 = 플로팅
                        Floating_coin();    //코인 플로팅
                        Floating_river();   //강 플로팅
                        Floating_monster(); //몬스터 플로팅
                        Floating_train();   //기차 플로팅
                        Floating_item();    //몬스터 플로팅
                        extra_display++;    //플로팅 이동을 변수에 저장
                    }

                    if (choose == 0)    //변수가 0으로 초기화되었다면
                    {
                        choose = Choose_object(); //어떤 객체를 생성할지 선택
                        floating_x = extra_display; //시작하는 x좌표 저장
                        floating_display = 0; //객체 생성 후 몇 칸을 이동했는지를 저장하는 변수
                    }

                    switch (choose)
                    {
                    case 1: //자동차
                        if (extra_display - floating_x < 46) //41칸 동안 이 상태 유지
                        {
                            if (floating_display % 8 == 0) //7칸마다 소환
                            {
                                Add_car(149, rand() % 41, Find_car(), rand() % 2);
                                Score += 30; //그럴때마다 30점 추가                            
                            }
                            if ((floating_display + 1) % 8 == 0) //자동차와 자동차 사이에 소환되도록 조정
                            {
                                int i = rand() % 100;
                                if (i <= 70) //확률은 70%
                                    Add_coin(149, rand() % 41, Find_coin()); //코인 객체 생성
                                else if (i <= 80) //확률은 10%
                                    Add_item(148, rand() % 41, Find_item(), rand() % 6); //아이템 랜덤 소환
                            }
                        }
                        else choose = 0; //0으로 초기화
                        break;
                    case 2: //강
                        if (extra_display - floating_x < 10) //10칸 동안 이 상태 유지
                        {
                            if (is_spawn == false) //소환되지 않았다면
                            {
                                Add_river(149, Find_river()); //강 객체 소환
                                Score += 100; is_spawn = 1;
                            }
                        }
                        else { choose = 0; is_spawn = 0; } //0으로 초기화
                        break;
                    case 3: //몬스터
                        if (extra_display - floating_x < 33) //33칸 동안 이 상태 유지
                        {
                            if (floating_display % 7 == 0) //7칸마다 소환
                            {
                                bool up = rand() % 2;
                                int mon_y = rand() % 41;
                                int mon_y2 = (mon_y + 20) % 41; //2개를 소환하기 위함
                                Add_monster(149, mon_y, Find_monster(), up);
                                Add_monster(149, mon_y2, Find_monster(), up);
                                Score += 30; //그럴때마다 30점 추가                            
                            }
                        }
                        else choose = 0; //0으로 초기화
                        break;
                    case 4: //기차
                        if (extra_display - floating_x < 7) //7칸 동안 이 상태 유지 - 수정해야 함
                        {
                            if (is_spawn == false) //소환되지 않았다면
                            {   //첫 위치에 더미 하나와 진짜 객체 하나씩 소환
                                for (int i = 0; i < 2; i++) Add_train(149, 0, Find_train());
                                train_x = 149; //기차의 x좌표 값을 지정
                                Score += 200; is_spawn = 1; //그럴때마다 점수 추가
                                train_spawn = 1; trains_charge = clock(); //기차 소환 선언
                            }
                        }
                        else { choose = 0; is_spawn = 0; } //0으로 초기화
                        break;
                    }
                    Draw_player(x, y); //그리고 플레이어 이동
                }
                else //플로팅이 아니면
                {
                    Remove_player(x, y); x += 2; //공 지우면서 좌표 이동
                    Draw_player(x, y);
                }
                Sleep(5); //약간의 딜레이
            }
            else if (input == LEFT && x > 0) //왼쪽 이동
            {
                Remove_player(x--, y);
                Draw_player(x, y);
                Sleep(5); //약간의 딜레이
            }
            else if (input == UP && y > 0) //위쪽 이동
            {
                Remove_player(x, y--);
                Draw_player(x, y);
                Sleep(5);
            }
            else if (input == DOWN && y < 40) //아래쪽 이동
            {
                Remove_player(x, y++);
                Draw_player(x, y);
                Sleep(5);
            }
        }

        if (clock() > cars_time + 50) //50ms마다 발동
        {
            for (int i = 0; i < CARS; i++) Move_car(i); //모든 자동차 객체의 y값을 변경
            cars_time = clock(); //시간 초기화
            Score++; //0.05초마다 1점 추가
        }
        if (clock() > monsters_time + 25) //250ms마다 발동
        {
            for (int i = 0; i < MONSTERS; i++) Move_monster(i); //모든 몬스터 객체의 y값을 변경
            monsters_time = clock();
        }
        if (train_spawn == 1 && clock() > trains_charge + 3000) //기차가 소환되면
        {
            if (clock() > train + 10 && trains[0].on) //10ms마다 발동
            {
                static short train_y = 0; //y값을 저장할 정적 변수
                train_y++; //1칸씩 증가
                if (train_y % 6 == 0 && train_y <= 36) //일정 범위 내에서 6칸 마다
                    Add_train(trains[0].x, train_y, Find_train()); //기차를 줄지어서 소환
                else if (train_y > 36) //범위를 벗어나면
                {
                    train_y = 0; trains[0].on = false; //첫 기차는 삭제
                }
                trains_time = clock();
            }
            if (trains[0].on == false) //0번 더미 객체가 사라지면
            {
                train_spawn = 2; trains_charge = clock(); //다음 시퀀스로 넘어감
            }
        }
        if (train_spawn == 2 && clock() > trains_charge + 1000) //기차가 줄지어 나온 후
        {
            if (clock() > trains_time + 50)
            {
                static int index = 1;
                Delete_train(index++); //기차를 위에서부터 하나씩 지움
                trains_time = clock();
                if (index >= 8) //정적 변수가 8이상이 되면
                {
                    index = 1; train_spawn = 1; trains_charge = clock(); //다시 처음으로 모두 초기화
                    for (int i = 0; i < 2; i++) Add_train(train_x, 0, Find_train());
                }
            }
        }
        
        //무적이 활성화되었다면
        if (invincible_on && !is_invincible)
        {   //무적임을 알리고 시간 저장
            is_invincible = 1; invincible_time = clock();
        }
        //지속시간이 지나면
        if (clock() > invincible_time + invincible_duration * 1000)
        {   //무적 종료
            is_invincible = 0; invincible_on = 0;
        }
        //질주가 활성화되었다면
        if (speed_on && !is_speed)
        {   //질주임을 알리고 시간 저장
            is_speed = 1; speed_time = clock();
        }
        if (clock() > speed_time + speed_duration * 1000)
        {   //질주 종료
            is_speed = 0; speed_on = 0;
        }

        ////충돌감지 함수가 1을 반환하면 게임오버
        //if (!is_invincible && Check_car(x, y) == 1) //자동차와 닿았다면 게임오버
        //{
        //    Game_over(x, y); break;
        //}
        //if (!is_invincible && Check_river(x, y) == 1) //강에 빠졌다면 게임오버
        //{
        //    Game_over(x, y); break;
        //}
        //if (!is_invincible && Check_monster(x, y) == 1) //몬스터와 닿았다면 게임오버
        //{
        //    Game_over(x, y); break;
        //}
        //if (!is_invincible && Check_train(x, y) == 1) //기차와 닿았다면 게임오버
        //{
        //    Game_over(x, y); break;
        //}

        if (Check_coin(x, y) == 1) //코인과 부딪혔다면
            Draw_player(x, y); //지워진 플레이어 다시 그림
        if (Check_item(x, y) == 1) //아이템과 부딪혔다면
            Draw_player(x, y); //지워진 플레이어 다시 그림
    }

    free_object(); //객체 동적 메모리 해제

    Ranking_sort(); //랭킹 정렬
    Ranking_screen(); //랭킹 화면
}

