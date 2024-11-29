#include "Screen.h"

//테두리를 그리는 함수
void Draw_square()
{
    for (int i = 0; i < 149; i++) { gotoxy(i, 0); printf("■"); gotoxy(i, 40); printf("■"); }
    for (int i = 1; i < 40; i++) { gotoxy(0, i); printf("■"); gotoxy(148, i); printf("■"); }
}

//메인 화면
void Main_screen_letter()
{
    gotoxy(29, 6);  printf("■■■■");  gotoxy(44, 6);  printf("■■■■");
    gotoxy(29, 7);  printf("■      ");  gotoxy(44, 7);  printf("■    ■");
    gotoxy(29, 8);  printf("■      ");  gotoxy(44, 8);  printf("■■■■");
    gotoxy(29, 9);  printf("■      ");  gotoxy(44, 9);  printf("■  ■  ");
    gotoxy(29, 10); printf("■■■■");  gotoxy(44, 10); printf("■    ■");

    gotoxy(59, 6);  printf("■■■■");  gotoxy(74, 6);  printf("■■■■");
    gotoxy(59, 7);  printf("■    ■");  gotoxy(74, 7);  printf("■      ");
    gotoxy(59, 8);  printf("■    ■");  gotoxy(74, 8);  printf("■■■■");
    gotoxy(59, 9);  printf("■    ■");  gotoxy(74, 9);  printf("      ■");
    gotoxy(59, 10); printf("■■■■");  gotoxy(74, 10); printf("■■■■");

    gotoxy(89, 6);  printf("■■■■");  gotoxy(104, 6);  printf("■      ■");
    gotoxy(89, 7);  printf("■      ");  gotoxy(104, 7);  printf(" ■    ■ ");
    gotoxy(89, 8);  printf("■■■■");  gotoxy(104, 8);  printf("  ■■■  ");
    gotoxy(89, 9);  printf("      ■");  gotoxy(104, 9);  printf("    ■    ");
    gotoxy(89, 10); printf("■■■■");  gotoxy(104, 10); printf("    ■    ");

    gotoxy(64, 12);  printf("■■■■");  gotoxy(79, 12);  printf("■■■■");
    gotoxy(64, 13);  printf("■    ■");  gotoxy(79, 13);  printf("■    ■");
    gotoxy(64, 14);  printf("■■■■");  gotoxy(79, 14);  printf("■    ■");
    gotoxy(64, 15);  printf("■  ■  ");  gotoxy(79, 15);  printf("■    ■");
    gotoxy(64, 16);  printf("■    ■");  gotoxy(79, 16);  printf("■■■■");

    gotoxy(94, 12);  printf("  ■■  ");  gotoxy(109, 12);  printf("■■■  ");
    gotoxy(94, 13);  printf(" ■  ■ ");  gotoxy(109, 13);  printf("■    ■");
    gotoxy(94, 14);  printf("■■■■");  gotoxy(109, 14);  printf("■    ■");
    gotoxy(94, 15);  printf("■    ■");  gotoxy(109, 15);  printf("■    ■");
    gotoxy(94, 16);  printf("■    ■");  gotoxy(109, 16);  printf("■■■  ");
}
void Main_screen_cloud()
{
    gotoxy(120, 7);  printf("    .-~~~-.");      gotoxy(28, 13);  printf("    .-~~~-.    .-~~~-.");
    gotoxy(120, 8);  printf(" .-~~     ~~~-.");  gotoxy(28, 14);  printf(" .-~~      .-~~     ~~~-.");
    gotoxy(120, 9);  printf("(              )"); gotoxy(28, 15);  printf("(         (              )");
    gotoxy(120, 10); printf(" `.__________.'");  gotoxy(28, 16);  printf(" `.________`.__________.'");
}
void Main_screen_car()
{
    gotoxy(10, 5); printf("  ______");       gotoxy(125, 13); printf("    ______");
    gotoxy(10, 6); printf(" /|_||_\\`.__");  gotoxy(125, 14); printf(" __.'/_||_|\\");
    gotoxy(10, 7); printf("(   _    _ _\\"); gotoxy(125, 15); printf("I_ I_    _   )");
    gotoxy(10, 8); printf("=`-(_)--(_)-'");  gotoxy(125, 16); printf("'-(_)--(_)-`=");
}
void Main_screen()
{
    system("cls");
    Draw_square(); //초기화면 구성
    if (bgm_on == true) Play_bgm(Main_bgm, 1);
    textcolor(135, 206, 235);
    Main_screen_letter();
    textcolor(0, 0, 255);
    Main_screen_car();
    removecolor();
    Main_screen_cloud();

    gotoxy(17, 25); printf("새로하기 : 1");
    gotoxy(43, 25); printf("이어하기 : 2");
    gotoxy(69, 25); printf("색상변경 : 3");
    gotoxy(95, 25); printf("게임설명 : 4");
    gotoxy(121, 25); printf("랭킹보기 : 5");

    clock_t letter = clock(); //텍스트 점멸을 위한 시간 저장

    while (1) //사용자가 올바른 입력을 할 때까지 반복
    {
        char input;
        if (_kbhit()) //키보드가 눌리면
        {
            input = _getch(); //키 입력받음
            if (input == '1') // 1을 누르면 새로시작
            {
                Play_bgm(Click_sound, 0); bgm_on = 1;
                Start_screen(); //게임시작
                break;
            }
            else if (input == '2') // 2를 누르면 이어하기
            {
                Play_bgm(Click_sound, 0); bgm_on = 1;
                Continue_screen(); //이어하기
                break;
            }
            else if (input == '3') // 3을 누르면 색상 커스텀화면
            {
                bgm_on = 0;
                Into_color_screen(); //색상커스텀화면
                break;
            }
            else if (input == '4') // 4를 누르면 게임설명화면
            {
                bgm_on = 0;
                Help_screen(); //게임설명화면
                break;
            }
            else if (input == '5') // 5를 누르면 랭킹화면
            {
                bgm_on = 0;
                Ranking_screen(); //랭킹화면
                break;
            }
        }

        //텍스트 색깔을 주기에 맞춰 변경하게 하여 점멸하는 효과를 내는 부분
        if (clock() > letter + 500) //500ms마다 발동
        {
            textcolor(0, 0, 255);
            Main_screen_letter();
            textcolor(135, 206, 235);
            Main_screen_car();
            removecolor();
            Main_screen_cloud();
        }
        if (clock() > letter + 1000) //1000ms마다 발동
        {
            textcolor(135, 206, 235);
            Main_screen_letter();
            textcolor(0, 0, 255);
            Main_screen_car();
            removecolor();
            Main_screen_cloud();
            letter = clock(); //시간 초기화
        }
    }
    Stop_bgm();
}
//새로하기 화면
void Start_screen()
{
    system("cls"); Draw_square();
    gotoxy(132, 39); printf("뒤로가기 : [ Q ]");
    gotoxy(10, 20); printf("이름 입력 : ");

    Score = 0; // 점수 초기화

    unsigned short found = 0; //중복 검사 변수
    //short car_x = 125, car_y = 2; //자동차의 초기 좌표
    //clock_t car_timer = clock(); //자동차 이동 시간 초기화
    //help_car.on = true; //자동차 객체 선언

    Draw_image_256(Chicken, hdc, 500, 300);

    //이름 입력 루프
    while (1)
    {
        ////자동차 움직임
        //if (clock() > car_timer + 100)
        //{
        //    Remove_car(car_x, car_y++); //자동차 지우고 y좌표 증가
        //    if (car_y >= 40) car_y = 2; //콘솔창 아래로 벗어나면 위로 리셋
        //    Draw_car(car_x, car_y, 0); //새 위치에 자동차 출력
        //    car_timer = clock(); //타이머 초기화
        //}

        //사용자 입력 처리
        if (_kbhit())
        {
            gotoxy(22, 20); for (int i = 0; i < 15; i++) printf("  "); //기존 입력 지우기
            gotoxy(22, 20); scanf("%s", Name); //이름 입력 (최대 15자)

            if (strcmp(Name, "Q") == 0 || strcmp(Name, "q") == 0) //뒤로가기
            {
                Play_bgm(Main_bgm, 1);
                Main_screen(); return;
            }

            //중복 검사
            found = 0;
            for (int i = 0; i < RANKING; i++)
            {
                if (strcmp(Name, Ranking[i].name) == 0)
                {
                    found = 1;
                    gotoxy(10, 22); printf("이미 존재하는 이름입니다.");
                    break;
                }
            }

            if (found == 0) //이름 중복 없으면 루프 탈출
                break;
        }
    }

    //이름 입력 성공 시 게임 시작
    bgm_on = 1; Game();
}

//이어하기 화면
bool Check_continue()
{
    for (int i = 0; i < RANKING; i++)
    {
        if (strcmp(Name, Ranking[i].name) == 0)
        {
            strcpy(Name, Ranking[i].name); //이름을 집어넣어 이어하기
            Coins = Ranking[i].coins; //코인 갯수도 불러온 후 색상값도 불러오기
            p_rgb.r = Ranking[i].color[0].r; p_rgb.g = Ranking[i].color[0].g; p_rgb.b = Ranking[i].color[0].b;
            c_rgb.r = Ranking[i].color[1].r; c_rgb.g = Ranking[i].color[1].g; c_rgb.b = Ranking[i].color[1].b;
            m_rgb.r = Ranking[i].color[2].r; m_rgb.g = Ranking[i].color[2].g; m_rgb.b = Ranking[i].color[2].b;
            t_rgb.r = Ranking[i].color[3].r; t_rgb.g = Ranking[i].color[3].g; t_rgb.b = Ranking[i].color[3].b;
            return 1;
        }
    }
    return 0;
}
void Continue_screen()
{
    system("cls"); Draw_square();
    gotoxy(132, 39); printf("뒤로가기 : [ Q ]");
    gotoxy(10, 20); printf("이름 입력 : ");
    Draw_image_256(Chicken2, hdc, 500, 300);

    while (1)
    {
        gotoxy(22, 20); for (int i = 0; i < 15; i++) printf("  ");
        gotoxy(22, 20); scanf("%s", Name); //이름 입력
        if (Check_continue() == 1)
        {
            bgm_on = 1; Game(); break;
        }
        else
        {
            gotoxy(10, 22); printf("존재하지 않는 이름입니다.");
        }
        if (strcmp(Name, "Q") == 0 || strcmp(Name, "q") == 0)
        {
            Play_bgm(Main_bgm, 1);
            Main_screen(); break;
        }
    }
}

void Into_color_screen()
{
    system("cls"); Draw_square();
    gotoxy(10, 20); printf("이름 입력 : ");
    gotoxy(132, 39); printf("뒤로가기 : [ Q ]");

    while (1)
    {
        gotoxy(22, 20); for (int i = 0; i < 15; i++) printf("  ");
        gotoxy(22, 20); scanf("%s", Name); //이름 입력
        if (Check_continue() == 1)
        {
            Color_screen(); return;
        }
        else
        {
            gotoxy(10, 22); printf("존재하지 않는 이름입니다.");
        }
        if (strcmp(Name, "Q") == 0 || strcmp(Name, "q") == 0)
        {
            Main_screen(); return;
        }
    }
}
//색상 커스텀 화면
void Color_screen()
{
    system("cls"); Draw_square();
    gotoxy(132, 39); printf("뒤로가기 : [ Q ]");
    gotoxy(16, 5); printf("## 캐릭터를 움직여 선택하세요! ##");

    Draw_car(27, 28, 1);
    gotoxy(26, 34); printf("색상 변경");
    Draw_monster(57, 29);
    gotoxy(56, 34); printf("색상 변경");
    Draw_train(87, 27);
    gotoxy(86, 34); printf("색상 변경");
    Draw_player(120, 30);
    gotoxy(116, 34); printf("색상 변경");
    gotoxy(116, 5); printf("색상변경 : 5코인");

    gotoxy(116, 7); printf("현재코인 : %d", Coins);

    //Draw_image_256(Genie, hdc, 180, 150);

    short x = 75, y = 7;
    Draw_player(x, y);

    while (1)
    {
        char input;
        if (_kbhit())
        {
            input = _getch();
            if (input == RIGHT && x < 147) //우측 이동
            {
                Remove_player(x++, y); //공 지우면서 좌표 이동
                Draw_player(x, y);
                Sleep(11);
            }
            if (input == LEFT && x > 2) //좌측 이동
            {
                Remove_player(x--, y);
                Draw_player(x, y);
                Sleep(11);
            }
            if (input == UP && y > 12) //위로 이동
            {
                Remove_player(x, y--);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == DOWN && y < 39) //아래로 이동
            {
                Remove_player(x, y++);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == 'q' || input == 'Q') //Q를 누르면 뒤로가기
            {
                Main_screen();
                break;
            }
        }

        if (29 <= y && y <= 35) {
            if (26 <= x && x <= 39) {
                Color_set_screen(1); return;
            }
            else if (56 <= x && x <= 69) {
                Color_set_screen(2); return;
            }
            else if (86 <= x && x <= 99) {
                Color_set_screen(3); return;
            }
            else if (116 <= x && x <= 129) {
                Color_set_screen(0); return;
            }
        }
    }
}
//색상의 값을 입력받는 함수
void Color_set_screen(int obj)
{
    int r = 0, g = 0, b = 0;
    char input;

    while (1) {
        system("cls"); Draw_square();

        gotoxy(62, 4); printf("원하는 색 조합을 정하세요");
        gotoxy(54, 6); printf("예시처럼 너무 어두운 색은 사용할 수 없습니다");
        gotoxy(58, 8); printf("EX) red : 10, green : 20, blue : 40");

        textcolor(255, 0, 0);  // 빨강
        gotoxy(20, 15); printf("RED :    ");
        textcolor(0, 255, 0);  // 초록
        gotoxy(65, 15); printf("GREEN :    ");
        textcolor(0, 0, 255);  // 파랑
        gotoxy(110, 15); printf("BLUE :    ");
        removecolor();
        gotoxy(26, 15); scanf("%d", &r);
        gotoxy(73, 15); scanf("%d", &g);
        gotoxy(117, 15); scanf("%d", &b);
        if (r + g + b < 100 || (r < 50 && g < 50 && b < 50)) continue;


        switch (obj)
        {
        case 0:
            p_rgb.r = r; p_rgb.g = g; p_rgb.b = b; //플레이어 색상 조정
            Draw_player(75, 25); break;
        case 1:
            c_rgb.r = r; c_rgb.g = g; c_rgb.b = b; //자동차 색상 조정
            Draw_car(72, 25, 1); break;
        case 2:
            m_rgb.r = r; m_rgb.g = g; m_rgb.b = b; //몬스터 색상 조정
            Draw_monster(72, 25); break;
        case 3:
            t_rgb.r = r; t_rgb.g = g; t_rgb.b = b; //기차 색상 조정
            Draw_train(72, 25); break;
        }

        gotoxy(64, 33); printf("이 색으로 바꾸시겠습니까? (y/n) : ");
        scanf(" %c", &input);
        if (input == 'y' || input == 'Y') break;
    }
    //색상 저장
    for (int i = 0; i < RANKING; i++)
    {
        if (strcmp(Name, Ranking[i].name) == 0)
        {
            Store_color(i); break;
        }
    }
    Coins -= 5;
    Ranking_sort(); //코인 갯수 변동 저장

    Color_screen(); return;
}

//설명 화면
void Help_screen()
{
    init_object();
    Recycle();
    system("cls"); Draw_square();
    gotoxy(132, 39); printf("뒤로가기 : [ Q ]");

    gotoxy(68, 5); printf("            ↑");
    gotoxy(68, 6); printf("이동  :  ←    →");
    gotoxy(68, 7); printf("            ↓");

    gotoxy(9, 1); printf("피하세요!");

    gotoxy(28, 1); printf("코인을");
    gotoxy(26, 2); printf("획득하세요");

    short coin = 0;
    gotoxy(26, 4); printf("코인 : %d", coin);

    gotoxy(49, 1); printf("연꽃잎을 밟아");
    gotoxy(49, 2); printf("강을 건너세요");

    gotoxy(89, 1); printf("피하세요!");

    gotoxy(110, 1); printf("피하세요!");

    short x = 2, y = 20; //플레이어의 초기 좌표 선언과 함께 초기화
    help_car.on = true; //자동차 객체 선언
    help_coin.on = true; //코인 객체 선언
    help_river.on = true; //강 객체 선언
    help_monster.on = true; //몬스터 객체 선언

    Draw_player(x, y);
    Draw_car(help_car.x, help_car.y, 0); //객체 출력
    Draw_coin(help_coin.x, help_coin.y);
    Draw_monster(help_monster.x, help_monster.y);

    //강 배경 그리기
    bgcolor(0, 0, 255);
    for (int i = 5; i < 40; i++)
    {
        gotoxy(50, i); printf("          ");
    }
    //연꽃 다리 그리기
    bgcolor(0, 255, 0);
    for (int i = 0; i < RIVERS; i++) 
    {
        if (help_river.bridge[i] != 0 && help_river.bridge[i] != 40)
        { //연꽃 다리의 y좌표가 0과 40이 아닐때만
            gotoxy(help_river.x, help_river.bridge[i]);
            for (int j = 0; j < 10; j++) printf(" ");
        }
    }
    removecolor();

    for (int i = 0; i < 2; i++) Add_train(111, 6, Find_train());

    bool train_spawn = true; //기차의 출발 여부
    clock_t car = clock(); //시간 저장
    clock_t monster = clock();
    clock_t train = clock();
    clock_t train_charge = clock();

    while (1)
    {
        char input;
        if (_kbhit())
        {
            input = _getch();
            if (input == RIGHT && x < 147) //우측 이동
            {
                Remove_player(x++, y); //공 지우면서 좌표 이동
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == LEFT && x > 2) //좌측 이동
            {
                Remove_player(x--, y);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == UP && y > 9) //위로 이동
            {
                Remove_player(x, y--);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == DOWN && y < 39) //아래로 이동
            {
                Remove_player(x, y++);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == 'q' || input == 'Q') //Q를 누르면 뒤로가기
            {
                Main_screen();
                break;
            }
        }

        if (clock() > car + 100)
        {
            Remove_car(help_car.x, help_car.y++); //자동차를 지움과 동시에 y좌표 수정
            if (help_car.y >= 35) help_car.y = 2; //만약 콘솔창을 벗어나면 다시 위로 보냄
            Draw_car(help_car.x, help_car.y, 0); //그렇게 좌표 수정이 모두 완료되면 자동차를 그려 움직임 표현
            car = clock(); //시간 초기화
        }
        if (clock() > monster + 200)
        {
            Remove_monster(help_monster.x, help_monster.y++);
            if (help_monster.y >= 37) help_monster.y = 2;
            Draw_monster(help_monster.x, help_monster.y);
            monster = clock();
        }
        if (train_spawn && clock() > train_charge + 3000)
        {
            if (clock() > train + 10 && trains[0].on) //10ms마다 발동
            {
                static short train_y = 6; //y값을 저장할 정적 변수
                train_y++; //1칸씩 증가
                if (train_y % 6 == 0 && train_y <= 30) //일정 범위 내에서 6칸 마다
                    Add_train(trains[0].x, train_y, Find_train()); //기차를 줄지어서 소환
                else if (train_y > 30) //범위를 벗어나면
                {
                    train_y = 6; trains[0].on = false; //첫 기차는 삭제
                }
                train = clock();
            }
            if (trains[0].on == false) //0번 더미 객체가 사라지면
            {
                train_spawn = false; train_charge = clock(); //다음 시퀀스로 넘어감
            }
        }
        if (!train_spawn && clock() > train_charge + 1000) //기차가 줄지어 나온 후
        {
            if (clock() > train + 50)
            {
                static int index = 1;
                Delete_train(index++); //기차를 위에서부터 하나씩 지움
                train = clock();
                if (index >= 6) //정적 변수가 6이상이 되면
                {
                    index = 1; train_spawn = 1; train_charge = clock(); //다시 처음으로 모두 초기화
                    for (int i = 0; i < 2; i++) Add_train(111, 6, Find_train()); //다시 기차 소환
                }
            }
        }

        if (help_coin.on == true) //객체가 활성화되어 있다면
        {
            if (help_coin.x <= x && x <= help_coin.x + 1 && help_coin.y == y)   
            {   //코인 객체의 좌표와 겹치면
                Remove_coin(help_coin.x, help_coin.y); //코인 지우고
                Draw_player(x, y); coin++;
                textcolor(0, 255, 0);
                gotoxy(26, 4); printf("코인 : %d", coin); //코인 갯수 최신화
                removecolor();
                help_coin.on = false; //코인 객체 제거
            }
        }
        if (Check_help_car(x, y) == 1) //충돌감지 함수가 1을 반환하면 게임오버
        {
            Help_screen(); break;
        }
        if (Check_help_river(x, y) == 1)
        {
            Help_screen(); break;
        }
        if (Check_help_monster(x, y) == 1)
        {
            Help_screen(); break;
        }
        if (Check_train(x, y) == 1)
        {
            Help_screen(); break;
        }
    }
    Stop_bgm();
    free_object();
    help_car.on = false; //자동차 객체 제거
    help_coin.on = false; //코인 객체 제거
    help_river.on = false;
    help_monster.on = false;
}

//랭킹 화면
void Ranking_screen()
{
    system("cls");
    Draw_square();
    gotoxy(132, 39);
    printf("뒤로가기 : [ Q ]");

    // 타이틀 출력
    gotoxy(20, 3);
    printf("랭킹\t\t이름\t\t\t점수\t\t\t코인");
    gotoxy(111, 5); printf("**********");
    gotoxy(111, 6); printf("*         *");
    gotoxy(110, 7); printf("*           *");
    gotoxy(110, 8); printf("*     1     *");
    gotoxy(110, 9); printf("*           *");
    gotoxy(111, 10); printf("*         *");
    gotoxy(111, 11); printf("**********");
    for (int i = 5; i < 28; i++) 
    {
        gotoxy(110, i); printf("*");
    }

    gotoxy(111, 20); printf(".. /￣|");
    gotoxy(111, 21); printf("　｜ ｜");
    gotoxy(111, 22); printf(",―′|. ∧  ∧");
    gotoxy(111, 23); printf("| ＿_）(＾ω＾)");
    gotoxy(111, 24); printf("| ＿_）|⊂)");
    gotoxy(111, 25); printf("| ＿_）|-Ｊ");
    gotoxy(111, 26); printf("ヽ＿)ノ");

    clock_t blink_time = clock();  // 깜빡임 효과를 위한 시간 저장 변수
    int blink_state = 0;           // 0일 때 빨강, 1일 때 분홍

    while (1) {
        for (int i = 0; i < RANKING; i++) {
            if (Ranking[i].score > 0) // 점수가 있어야만 출력
            {
                gotoxy(20, 5 + i * 3);

                // 1위 깜빡임 효과
                if (i == 0) {
                    if (blink_state == 0) {
                        textcolor(255, 0, 0);  // 빨강
                    }
                    else {
                        textcolor(255, 192, 203);  // 분홍
                    }
                    gotoxy(22, 5 + i * 3);
                    printf("★");  // 1위에 별 출력
                }
                // 2위 및 3위는 색상 고정
                else if (i == 1) {
                    textcolor(255, 165, 0);
                    gotoxy(22, 5 + i * 3);
                    printf("★");
                }
                else if (i == 2) {
                    textcolor(255, 255, 0);
                    gotoxy(22, 5 + i * 3);
                    printf("★");
                }
                else
                    removecolor();

                //이름이 길어지면 한칸씩 밀리길래 하나씩 좌표찍음
                gotoxy(20, 5 + i * 3); printf("%d", i + 1);
                gotoxy(40, 5 + i * 3); printf("%s", Ranking[i].name);
                gotoxy(64, 5 + i * 3); printf("%d", Ranking[i].score);
                gotoxy(88, 5 + i * 3); printf("%d", Ranking[i].coins);
            }
        }

        // 깜빡임 주기 설정 (500ms마다 색상 변경)
        if (clock() > blink_time + 500) 
        {
            blink_state = !blink_state;  // 빨강과 분홍으로 깜빡임 전환
            blink_time = clock();  // 시간 초기화
        }

        // 사용자가 Q를 누르면 랭킹 화면 종료
        if (_kbhit()) {
            char input = _getch();
            if (input == 'q' || input == 'Q') {
                removecolor();
                Main_screen(); return;
            }
        }
    }
}