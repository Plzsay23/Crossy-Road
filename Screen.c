#include "Screen.h"

//�׵θ��� �׸��� �Լ�
void Draw_square()
{
    for (int i = 0; i < 149; i++) { gotoxy(i, 0); printf("��"); gotoxy(i, 40); printf("��"); }
    for (int i = 1; i < 40; i++) { gotoxy(0, i); printf("��"); gotoxy(148, i); printf("��"); }
}

//���� ȭ��
void Main_screen_letter()
{
    gotoxy(29, 6);  printf("�����");  gotoxy(44, 6);  printf("�����");
    gotoxy(29, 7);  printf("��      ");  gotoxy(44, 7);  printf("��    ��");
    gotoxy(29, 8);  printf("��      ");  gotoxy(44, 8);  printf("�����");
    gotoxy(29, 9);  printf("��      ");  gotoxy(44, 9);  printf("��  ��  ");
    gotoxy(29, 10); printf("�����");  gotoxy(44, 10); printf("��    ��");

    gotoxy(59, 6);  printf("�����");  gotoxy(74, 6);  printf("�����");
    gotoxy(59, 7);  printf("��    ��");  gotoxy(74, 7);  printf("��      ");
    gotoxy(59, 8);  printf("��    ��");  gotoxy(74, 8);  printf("�����");
    gotoxy(59, 9);  printf("��    ��");  gotoxy(74, 9);  printf("      ��");
    gotoxy(59, 10); printf("�����");  gotoxy(74, 10); printf("�����");

    gotoxy(89, 6);  printf("�����");  gotoxy(104, 6);  printf("��      ��");
    gotoxy(89, 7);  printf("��      ");  gotoxy(104, 7);  printf(" ��    �� ");
    gotoxy(89, 8);  printf("�����");  gotoxy(104, 8);  printf("  ����  ");
    gotoxy(89, 9);  printf("      ��");  gotoxy(104, 9);  printf("    ��    ");
    gotoxy(89, 10); printf("�����");  gotoxy(104, 10); printf("    ��    ");

    gotoxy(64, 12);  printf("�����");  gotoxy(79, 12);  printf("�����");
    gotoxy(64, 13);  printf("��    ��");  gotoxy(79, 13);  printf("��    ��");
    gotoxy(64, 14);  printf("�����");  gotoxy(79, 14);  printf("��    ��");
    gotoxy(64, 15);  printf("��  ��  ");  gotoxy(79, 15);  printf("��    ��");
    gotoxy(64, 16);  printf("��    ��");  gotoxy(79, 16);  printf("�����");

    gotoxy(94, 12);  printf("  ���  ");  gotoxy(109, 12);  printf("����  ");
    gotoxy(94, 13);  printf(" ��  �� ");  gotoxy(109, 13);  printf("��    ��");
    gotoxy(94, 14);  printf("�����");  gotoxy(109, 14);  printf("��    ��");
    gotoxy(94, 15);  printf("��    ��");  gotoxy(109, 15);  printf("��    ��");
    gotoxy(94, 16);  printf("��    ��");  gotoxy(109, 16);  printf("����  ");
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
    Draw_square(); //�ʱ�ȭ�� ����
    textcolor(135, 206, 235);
    Main_screen_letter();
    textcolor(0, 0, 255);
    Main_screen_car();
    removecolor();
    Main_screen_cloud();

    gotoxy(17, 25); printf("�����ϱ� : 1");
    gotoxy(43, 25); printf("�̾��ϱ� : 2");
    gotoxy(69, 25); printf("���󺯰� : 3");
    gotoxy(95, 25); printf("���Ӽ��� : 4");
    gotoxy(121, 25); printf("��ŷ���� : 5");

    clock_t letter = clock(); //�ؽ�Ʈ ������ ���� �ð� ����

    while (1) //����ڰ� �ùٸ� �Է��� �� ������ �ݺ�
    {
        char input;
        if (_kbhit()) //Ű���尡 ������
        {
            input = _getch(); //Ű �Է¹���
            if (input == '1') // 1�� ������ ���ν���
            {
                Start_screen(); //���ӽ���
                break;
            }
            else if (input == '2') // 2�� ������ �̾��ϱ�
            {
                Continue_screen(); //�̾��ϱ�
                break;
            }
            else if (input == '3') // 3�� ������ ���� Ŀ����ȭ��
            {
                Color_screen(); //����Ŀ����ȭ��
                break;
            }
            else if (input == '4') // 4�� ������ ���Ӽ���ȭ��
            {
                Help_screen(); //���Ӽ���ȭ��
                break;
            }
            else if (input == '5') // 5�� ������ ��ŷȭ��
            {
                Ranking_screen(); //��ŷȭ��
                break;
            }
        }

        //�ؽ�Ʈ ������ �ֱ⿡ ���� �����ϰ� �Ͽ� �����ϴ� ȿ���� ���� �κ�
        if (clock() > letter + 500) //500ms���� �ߵ�
        {
            textcolor(0, 0, 255);
            Main_screen_letter();
            textcolor(135, 206, 235);
            Main_screen_car();
            removecolor();
            Main_screen_cloud();
        }
        if (clock() > letter + 1000) //1000ms���� �ߵ�
        {
            textcolor(135, 206, 235);
            Main_screen_letter();
            textcolor(0, 0, 255);
            Main_screen_car();
            removecolor();
            Main_screen_cloud();
            letter = clock(); //�ð� �ʱ�ȭ
        }
    }
}

//�����ϱ� ȭ��
void Start_screen()
{
    system("cls"); Draw_square();
    gotoxy(136, 39); printf("�ڷΰ��� : Q");
    gotoxy(30, 20); printf("�̸� �Է� : ");
    Score = 0; //�����ʱ�ȭ
    unsigned short found = 0; //�ߺ��˻� ����

    do
    {
        found = 0;
        gotoxy(42, 20); for (int i = 0; i < 15; i++) printf("  ");
        gotoxy(42, 20); scanf("%s", Name); //�̸� �Է�
        for (int i = 0; i < RANKING; i++)
        {
            if (strcmp(Name, Ranking[i].name) == 0)  //�ϳ��� �ߺ��� �ִٸ�
            {
                found++; break; //�ߺ� ������ ����
            }
        }

        if (found != 0)
        {
            gotoxy(30, 22); printf("�̹� �����ϴ� �̸��Դϴ�.");
        }
        if (strcmp(Name, "Q") == 0 || strcmp(Name, "q") == 0) //�ڷΰ��� : Q
            break;
    } while (found != 0);

    if (strcmp(Name, "Q") == 0 || strcmp(Name, "q") == 0)
        Main_screen();
    else if (found == 0)
        Game();
}

//�̾��ϱ� ȭ��
bool Check_continue()
{
    for (int i = 0; i < RANKING; i++)
    {
        if (strcmp(Name, Ranking[i].name) == 0)
        {
            strcpy(Name, Ranking[i].name); //�̸��� ����־� �̾��ϱ�
            Coins = Ranking[i].coins; //���� ������ �ҷ�����
            return 1;
        }
    }
    return 0;
}
void Continue_screen()
{
    system("cls"); Draw_square();
    gotoxy(136, 39); printf("�ڷΰ��� : Q");
    gotoxy(30, 20); printf("�̸� �Է� : ");
    Draw_image_256(Chicken, hdc, 680, 250);

    while (1)
    {
        gotoxy(42, 20); for (int i = 0; i < 15; i++) printf("  ");
        gotoxy(42, 20); scanf("%s", Name); //�̸� �Է�
        if (Check_continue() == 1)
        {
            Game(); break;
        }
        else
        {
            gotoxy(30, 22); printf("�������� �ʴ� �̸��Դϴ�.");
        }
        if (strcmp(Name, "Q") == 0 || strcmp(Name, "q") == 0)
        {
            Main_screen(); break;
        }
    }
}

//���� Ŀ���� ȭ��
void Color_screen()
{
    system("cls"); Draw_square();
    gotoxy(136, 39); printf("�ڷΰ��� : Q");

    Draw_car(30, 5, 1);
    gotoxy(29, 11); printf("���� ����");
    Draw_monster(60, 6);
    gotoxy(59, 11); printf("���� ����");
    Draw_train(90, 4);
    gotoxy(89, 11); printf("���� ����");
    Draw_player(123, 7);
    gotoxy(119, 11); printf("���� ����");

    short x = 75, y = 20;
    Draw_player(x, y);

    while (1)
    {
        char input;
        if (_kbhit())
        {
            input = _getch();
            if (input == RIGHT && x < 147) //���� �̵�
            {
                Remove_player(x++, y); //�� ����鼭 ��ǥ �̵�
                Draw_player(x, y);
                Sleep(11);
            }
            if (input == LEFT && x > 2) //���� �̵�
            {
                Remove_player(x--, y);
                Draw_player(x, y);
                Sleep(11);
            }
            if (input == UP && y > 12) //���� �̵�
            {
                Remove_player(x, y--);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == DOWN && y < 39) //�Ʒ��� �̵�
            {
                Remove_player(x, y++);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == 'q' || input == 'Q') //Q�� ������ �ڷΰ���
            {
                Main_screen();
                break;
            }
        }

        if (y == 12) {
            if (29 <= x && x <= 42) {
                Color_set_screen(1); return;
            }
            else if (59 <= x && x <= 72) {
                Color_set_screen(2); return;
            }
            else if (89 <= x && x <= 102) {
                Color_set_screen(3); return;
            }
            else if (119 <= x && x <= 132) {
                Color_set_screen(0); return;
            }
        }
    }
}
//������ ���� �Է¹޴� �Լ�
void Color_set_screen(int obj)
{
    system("cls"); Draw_square();

    int r, g, b;

    gotoxy(20, 15); printf("RED : ");
    gotoxy(65, 15); printf("GREEN : ");
    gotoxy(110, 15); printf("BLUE : ");
    gotoxy(26, 15); scanf("%d", &r);
    gotoxy(73, 15); scanf("%d", &g);
    gotoxy(117, 15); scanf("%d", &b);

    switch (obj)
    {
    case 0: p_rgb.r = r; p_rgb.g = g; p_rgb.b = b; break; //�÷��̾� ���� ����
    case 1: c_rgb.r = r; c_rgb.g = g; c_rgb.b = b; break; //�ڵ��� ���� ����
    case 2: m_rgb.r = r; m_rgb.g = g; m_rgb.b = b; break; //���� ���� ����
    case 3: t_rgb.r = r; t_rgb.g = g; t_rgb.b = b; break; //���� ���� ����
    }

    //���� �ܺ� ���Ͽ� ����
    FILE* color = fopen("Color.txt", "w");
    fprintf(color, "%d %d %d\n", p_rgb.r, p_rgb.g, p_rgb.b);
    fprintf(color, "%d %d %d\n", c_rgb.r, c_rgb.g, c_rgb.b);
    fprintf(color, "%d %d %d\n", m_rgb.r, m_rgb.g, m_rgb.b);
    fprintf(color, "%d %d %d\n", t_rgb.r, t_rgb.g, t_rgb.b);
    fclose(color);

    Color_screen(); return;
}

//���� ȭ��
void Help_screen()
{
    system("cls"); Draw_square();
    gotoxy(136, 39); printf("�ڷΰ��� : Q");

    gotoxy(68, 5); printf("            ��");
    gotoxy(68, 6); printf("�̵�  :  ��    ��");
    gotoxy(68, 7); printf("            ��");

    gotoxy(9, 1); printf("���ϼ���!");

    gotoxy(28, 1); printf("������");
    gotoxy(26, 2); printf("ȹ���ϼ���");

    short coin = 0;
    gotoxy(26, 4); printf("���� : %d", coin);

    gotoxy(89, 1); printf("���ϼ���!");

    short x = 2, y = 20; //�÷��̾��� �ʱ� ��ǥ ����� �Բ� �ʱ�ȭ
    help_car.on = true; //�ڵ��� ��ü ����
    help_coin.on = true; //���� ��ü ����
    help_river.on = true; //�� ��ü ����
    help_monster.on = true; //���� ��ü ����

    Draw_player(x, y); 
    Draw_car(help_car.x, help_car.y, 0); //��ü ���
    Draw_coin(help_coin.x, help_coin.y);
    Draw_river(help_river.x, 0);
    Draw_monster(help_monster.x, help_monster.y);

    for (int i = 0; i < 10; i++) { //�� �� �κ� �ڸ���
        for (int j = 0; j < 4; j++) {
            gotoxy(50 + i, 1 + j); printf(" "); } }
    gotoxy(49, 1); printf("�������� ���");
    gotoxy(49, 2); printf("���� �ǳʼ���");

    textcolor(0, 255, 0);
    bgcolor(0, 255, 0);
    for (int i = 0; i < RIVERS; i++) //���� �ٸ� �׸���
    {
        if (help_river.bridge[i] != 0 && help_river.bridge[i] != 40)
        { //���� �ٸ��� y��ǥ�� 0�� 40�� �ƴҶ���
            gotoxy(help_river.x, help_river.bridge[i]);
            for (int j = 0; j < 10; j++) printf(" ");
        }
    } removecolor();

    clock_t car = clock(); //�ð� ����
    clock_t monster = clock();

    while (1)
    {
        char input;
        if (_kbhit())
        {
            input = _getch();
            if (input == RIGHT && x < 147) //���� �̵�
            {
                Remove_player(x++, y); //�� ����鼭 ��ǥ �̵�
                Draw_player(x, y); 
                Sleep(33);
            }
            if (input == LEFT && x > 2) //���� �̵�
            {
                Remove_player(x--, y);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == UP && y > 9) //���� �̵�
            {
                Remove_player(x, y--);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == DOWN && y < 39) //�Ʒ��� �̵�
            {
                Remove_player(x, y++);
                Draw_player(x, y);
                Sleep(33);
            }
            if (input == 'q' || input == 'Q') //Q�� ������ �ڷΰ���
            {
                Main_screen();
                break;
            }
        }

        if (clock() > car + 100)
        {
            Remove_car(help_car.x, help_car.y++); //�ڵ����� ����� ���ÿ� y��ǥ ����
            if (help_car.y >= 35) help_car.y = 2; //���� �ܼ�â�� ����� �ٽ� ���� ����
            Draw_car(help_car.x, help_car.y, 0); //�׷��� ��ǥ ������ ��� �Ϸ�Ǹ� �ڵ����� �׷� ������ ǥ��
            car = clock(); //�ð� �ʱ�ȭ
        }
        if (clock() > monster + 200)
        {
            Remove_monster(help_monster.x, help_monster.y++);
            if (help_monster.y >= 37) help_monster.y = 2;
            Draw_monster(help_monster.x, help_monster.y);
            monster = clock();
        }

        if (help_coin.on == true) //��ü�� Ȱ��ȭ�Ǿ� �ִٸ�
        {
            if (help_coin.x <= x && x <= help_coin.x + 1 &&
                help_coin.y == y) //���� ��ü�� ��ǥ�� ��ġ��  
            {
                Remove_coin(help_coin.x, help_coin.y); //���� �����
                Draw_player(x, y); coin++;
                textcolor(0, 255, 0);
                gotoxy(26, 4); printf("���� : %d", coin); //���� ���� �ֽ�ȭ
                removecolor();
                help_coin.on = false; //���� ��ü ����
            }
        }

        if (Check_car(x, y) == 1) //�浹���� �Լ��� 1�� ��ȯ�ϸ� ���ӿ���
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

    help_car.on = false; //�ڵ��� ��ü ����
    help_coin.on = false; //���� ��ü ����
    help_river.on = false;
    help_monster.on = false;
}

//��ŷ ȭ��
void Ranking_screen()
{
    system("cls");
    Draw_square();
    gotoxy(136, 39);
    printf("�ڷΰ��� : Q");

    // Ÿ��Ʋ ���
    gotoxy(20, 3);
    printf("��ŷ\t\t�̸�\t\t\t����\t\t\t����");

    clock_t blink_time = clock();  // ������ ȿ���� ���� �ð� ���� ����
    int blink_state = 0;           // 0�� �� ����, 1�� �� ��ȫ

    while (1) {
        for (int i = 0; i < RANKING; i++) {
            if (Ranking[i].score > 0) // ������ �־�߸� ���
            {
                gotoxy(20, 5 + i * 3);

                // 1�� ������ ȿ��
                if (i == 0) {
                    if (blink_state == 0) {
                        textcolor(255, 0, 0);  // ����
                    }
                    else {
                        textcolor(255, 192, 203);  // ��ȫ
                    }
                    gotoxy(22, 5 + i * 3);
                    printf("��");  // 1���� �� ���
                }
                // 2�� �� 3���� ���� ����
                else if (i == 1) {
                    textcolor(255, 165, 0);
                    gotoxy(22, 5 + i * 3);
                    printf("��");
                }
                else if (i == 2) {
                    textcolor(255, 255, 0);
                    gotoxy(22, 5 + i * 3);
                    printf("��");
                }
                else 
                    removecolor();

                //�̸��� ������� ��ĭ�� �и��淡 �ϳ��� ��ǥ����
                gotoxy(20, 5 + i * 3); printf("%d", i + 1);
                gotoxy(40, 5 + i * 3); printf("%s", Ranking[i].name);
                gotoxy(64, 5 + i * 3); printf("%d", Ranking[i].score);
                gotoxy(88, 5 + i * 3); printf("%d", Ranking[i].coins);
            }
        }

        // ������ �ֱ� ���� (500ms���� ���� ����)
        if (clock() > blink_time + 500) {
            blink_state = !blink_state;  // ������ ��ȫ���� ������ ��ȯ
            blink_time = clock();  // �ð� �ʱ�ȭ
        }

        // ����ڰ� Q�� ������ ��ŷ ȭ�� ����
        if (_kbhit()) {
            char input = _getch();
            if (input == 'q' || input == 'Q') {
                Main_screen(); return;
            }
        }
    }
}