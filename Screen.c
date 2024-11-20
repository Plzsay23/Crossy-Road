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
                Start_screen(); //게임시작
                break;
            }
            else if (input == '2') // 2를 누르면 이어하기
            {
                Continue_screen(); //이어하기
                break;
            }
            else if (input == '3') // 3을 누르면 색상 커스텀화면
            {
                Into_color_screen(); //색상커스텀화면
                break;
            }
            else if (input == '4') // 4를 누르면 게임설명화면
            {
                Help_screen(); //게임설명화면
                break;
            }
            else if (input == '5') // 5를 누르면 랭킹화면
            {
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
}

//새로하기 화면
void Start_screen()
{
    system("cls"); Draw_square();
    gotoxy(136, 39); printf("뒤로가기 : Q");
    gotoxy(30, 20); printf("이름 입력 : ");
    Score = 0; //점수초기화
    unsigned short found = 0; //중복검사 변수

    do
    {
        found = 0;
        gotoxy(42, 20); for (int i = 0; i < 15; i++) printf("  ");
        gotoxy(42, 20); scanf("%s", Name); //이름 입력
        for (int i = 0; i < RANKING; i++)
        {
            if (strcmp(Name, Ranking[i].name) == 0)  //하나라도 중복이 있다면
            {
                found++; break; //중복 변수값 변동
            }
        }

        if (found != 0)
        {
            gotoxy(30, 22); printf("이미 존재하는 이름입니다.");
        }
        if (strcmp(Name, "Q") == 0 || strcmp(Name, "q") == 0) //뒤로가기 : Q
            break;
    } while (found != 0);

    if (strcmp(Name, "Q") == 0 || strcmp(Name, "q") == 0)
        Main_screen();
    else if (found == 0)
        Game();
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
    gotoxy(136, 39); printf("뒤로가기 : Q");
    gotoxy(30, 20); printf("이름 입력 : ");
    Draw_image_256(Chicken, hdc, 680, 250);

    while (1)
    {
        gotoxy(42, 20); for (int i = 0; i < 15; i++) printf("  ");
        gotoxy(42, 20); scanf("%s", Name); //이름 입력
        if (Check_continue() == 1)
        {
            Game(); break;
        }
        else
        {
            gotoxy(30, 22); printf("존재하지 않는 이름입니다.");
        }
        if (strcmp(Name, "Q") == 0 || strcmp(Name, "q") == 0)
        {
            Main_screen(); break;
        }
    }
}

void Into_color_screen()
{
    system("cls"); Draw_square();
    gotoxy(30, 20); printf("이름 입력 : ");
    gotoxy(136, 39); printf("뒤로가기 : Q");

    while (1)
    {
        gotoxy(42, 20); for (int i = 0; i < 15; i++) printf("  ");
        gotoxy(42, 20); scanf("%s", Name); //이름 입력
        if (Check_continue() == 1)
        {
            Color_screen(); return;
        }
        else
        {
            gotoxy(30, 22); printf("존재하지 않는 이름입니다.");
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
    gotoxy(136, 39); printf("뒤로가기 : Q");

    Draw_car(27, 5, 1);
    gotoxy(26, 11); printf("색상 변경");
    Draw_monster(57, 6);
    gotoxy(56, 11); printf("색상 변경");
    Draw_train(87, 4);
    gotoxy(86, 11); printf("색상 변경");
    Draw_player(120, 7);
    gotoxy(116, 11); printf("색상 변경");
    gotoxy(67, 3); printf("색상변경 : 5코인");

    gotoxy(67, 5); printf("현재코인 : %d", Coins);

    short x = 75, y = 20;
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

        if (y == 12) {
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
recolor:
    system("cls"); Draw_square();

    int r = 0, g = 0, b = 0;

    gotoxy(58, 8); printf("너무 어두운 색은 사용할 수 없습니다");

    gotoxy(20, 15); printf("RED :    ");
    gotoxy(65, 15); printf("GREEN :    ");
    gotoxy(110, 15); printf("BLUE :    ");
    gotoxy(26, 15); scanf("%d", &r);
    gotoxy(73, 15); scanf("%d", &g);
    gotoxy(117, 15); scanf("%d", &b);
    if (r + g + b < 100 || (r < 50 && g < 50 && b < 50))
        goto recolor;

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

    gotoxy(64, 33); printf("다시하시겠습니까? (y/n)");
    while (1)
    {
        char input;
        if (_kbhit())
        {
            input = _getch();
            if (input == 'y' || input == 'Y')
            {
                goto recolor; break;
            }
            else if (input == 'n' || input == 'N')
                break;
        }
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
    system("cls"); Draw_square();
    gotoxy(136, 39); printf("뒤로가기 : Q");

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

    short x = 2, y = 20; //플레이어의 초기 좌표 선언과 함께 초기화
    help_car.on = true; //자동차 객체 선언
    help_coin.on = true; //코인 객체 선언
    help_river.on = true; //강 객체 선언
    help_monster.on = true; //몬스터 객체 선언

    Draw_player(x, y); 
    Draw_car(help_car.x, help_car.y, 0); //객체 출력
    Draw_coin(help_coin.x, help_coin.y);
    Draw_monster(help_monster.x, help_monster.y);
    
    bgcolor(0, 0, 255);
    for (int i = 5; i < 40; i++)
    { gotoxy(50, i); printf("          "); }
    
    bgcolor(0, 255, 0);
    for (int i = 0; i < RIVERS; i++) //연꽃 다리 그리기
    {
        if (help_river.bridge[i] != 0 && help_river.bridge[i] != 40)
        { //연꽃 다리의 y좌표가 0과 40이 아닐때만
            gotoxy(help_river.x, help_river.bridge[i]);
            for (int j = 0; j < 10; j++) printf(" ");
        }
    } 
    removecolor();

    clock_t car = clock(); //시간 저장
    clock_t monster = clock();

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

        if (help_coin.on == true) //객체가 활성화되어 있다면
        {
            if (help_coin.x <= x && x <= help_coin.x + 1 &&
                help_coin.y == y) //코인 객체의 좌표와 겹치면  
            {
                Remove_coin(help_coin.x, help_coin.y); //코인 지우고
                Draw_player(x, y); coin++;
                textcolor(0, 255, 0);
                gotoxy(26, 4); printf("코인 : %d", coin); //코인 갯수 최신화
                removecolor();
                help_coin.on = false; //코인 객체 제거
            }
        }

        if (Check_car(x, y) == 1) //충돌감지 함수가 1을 반환하면 게임오버
        {
            Help_screen(); break;
        }
        if (Check_river(x, y) == 1)
        {
            Help_screen(); break;
        }
        if (Check_monster(x, y) == 1)
        {
            Help_screen(); break;
        }
    }
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
    gotoxy(136, 39);
    printf("뒤로가기 : Q");

    // 타이틀 출력
    gotoxy(20, 3);
    printf("랭킹\t\t이름\t\t\t점수\t\t\t코인");

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
        if (clock() > blink_time + 500) {
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