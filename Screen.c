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
    Textcolor(black, skyblue);
    Main_screen_letter();
    Textcolor(black, blue);
    Main_screen_car();
    Textcolor(black, white);
    Main_screen_cloud();

    gotoxy(21, 25); printf("새로하기 : 1");
    gotoxy(53, 25); printf("이어하기 : 2");
    gotoxy(85, 25); printf("게임설명 : 3");
    gotoxy(117, 25); printf("랭킹보기 : 4");

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
                Continue_screen(); //게임설명화면
                break;
            }
            else if (input == '3') // 3를 누르면 게임설명을 보여줌
            {
                Help_screen(); //게임설명화면
                break;
            }
            else if (input == '4') // 4을 누르면 랭킹화면을 보여줌
            {
                Ranking_screen(); //랭킹화면
                break;
            }
        }

        //텍스트 색깔을 주기에 맞춰 변경하게 하여 점멸하는 효과를 내는 부분
        if (clock() > letter + 500) //500ms마다 발동
        {
            Textcolor(black, skyblue);
            Main_screen_letter();
            Textcolor(black, blue);
            Main_screen_car();
            Textcolor(black, brightwhite);
            Main_screen_cloud();
        }
        if (clock() > letter + 1000) //1000ms마다 발동
        {
            Textcolor(black, blue);
            Main_screen_letter();
            Textcolor(black, skyblue);
            Main_screen_car();
            Textcolor(black, white);
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
            Coins = Ranking[i].coins; //코인 갯수도 불러오기
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

//설명 화면
void Help_screen()
{
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

    gotoxy(89, 1); printf("피하세요!");

    short x = 2, y = 20; //플레이어의 초기 좌표 선언과 함께 초기화
    help_screen_car.on = true; //자동차 객체 선언
    help_screen_coin.on = true; //코인 객체 선언
    help_screen_river.on = true; //강 객체 선언
    help_screen_monster.on = true; //몬스터 객체 선언

    Draw_player(x, y); 
    Draw_car(help_screen_car.x, help_screen_car.y, 0); //객체 출력
    Draw_coin(help_screen_coin.x, help_screen_coin.y);
    Draw_river(help_screen_river.x, 0);
    Draw_monster(help_screen_monster.x, help_screen_monster.y);

    for (int i = 0; i < 10; i++) { //강 윗 부분 자르기
        for (int j = 0; j < 4; j++) {
            gotoxy(50 + i, 1 + j); printf(" "); } }
    gotoxy(49, 1); printf("연꽃잎을 밟아");
    gotoxy(49, 2); printf("강을 건너세요");

    Textcolor(green, green);
    for (int i = 0; i < RIVERS; i++) //연꽃 다리 그리기
    {
        if (help_screen_river.bridge[i] != 0 && help_screen_river.bridge[i] != 40)
        { //연꽃 다리의 y좌표가 0과 40이 아닐때만
            gotoxy(help_screen_river.x, help_screen_river.bridge[i]);
            for (int j = 0; j < 10; j++) printf(" ");
        }
    } Textcolor(black, white);

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
            Remove_car(help_screen_car.x, help_screen_car.y++); //자동차를 지움과 동시에 y좌표 수정
            if (help_screen_car.y >= 35) help_screen_car.y = 2; //만약 콘솔창을 벗어나면 다시 위로 보냄
            Draw_car(help_screen_car.x, help_screen_car.y, 0); //그렇게 좌표 수정이 모두 완료되면 자동차를 그려 움직임 표현
            car = clock(); //시간 초기화
        }
        if (clock() > monster + 200)
        {
            Remove_monster(help_screen_monster.x, help_screen_monster.y++);
            if (help_screen_monster.y >= 37) help_screen_monster.y = 2;
            Draw_monster(help_screen_monster.x, help_screen_monster.y);
            monster = clock();
        }

        if (help_screen_coin.on == true) //객체가 활성화되어 있다면
        {
            if (help_screen_coin.x <= x && x <= help_screen_coin.x + 1 &&
                help_screen_coin.y == y) //코인 객체의 좌표와 겹치면  
            {
                Remove_coin(help_screen_coin.x, help_screen_coin.y); //코인 지우고
                Draw_player(x, y); coin++;
                Textcolor(black, green);
                gotoxy(26, 4); printf("코인 : %d", coin); //코인 갯수 최신화
                Textcolor(black, white);
                help_screen_coin.on = false; //코인 객체 제거
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

    help_screen_car.on = false; //자동차 객체 제거
    help_screen_coin.on = false; //코인 객체 제거
    help_screen_river.on = false;
    help_screen_monster.on = false;
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
                        Textcolor(black, red);  // 빨강
                    }
                    else {
                        Textcolor(black, PINK);  // 분홍
                    }
                    gotoxy(22, 5 + i * 3);
                    printf("★");  // 1위에 별 출력
                }
                // 2위 및 3위는 색상 고정
                else if (i == 1) {
                    Textcolor(black, orange);
                    gotoxy(22, 5 + i * 3);
                    printf("★");
                }
                else if (i == 2) {
                    Textcolor(black, YELLOW);
                    gotoxy(22, 5 + i * 3);
                    printf("★");
                }
                else {
                    Textcolor(black, white); // 나머지 순위는 흰색 텍스트
                }

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
                break;
            }
        }
    }
}