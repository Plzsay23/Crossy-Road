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
    Textcolor(black, skyblue);
    Main_screen_letter();
    Textcolor(black, blue);
    Main_screen_car();
    Textcolor(black, white);
    Main_screen_cloud();

    gotoxy(21, 25); printf("�����ϱ� : 1");
    gotoxy(53, 25); printf("�̾��ϱ� : 2");
    gotoxy(85, 25); printf("���Ӽ��� : 3");
    gotoxy(117, 25); printf("��ŷ���� : 4");

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
                Continue_screen(); //���Ӽ���ȭ��
                break;
            }
            else if (input == '3') // 3�� ������ ���Ӽ����� ������
            {
                Help_screen(); //���Ӽ���ȭ��
                break;
            }
            else if (input == '4') // 4�� ������ ��ŷȭ���� ������
            {
                Ranking_screen(); //��ŷȭ��
                break;
            }
        }

        //�ؽ�Ʈ ������ �ֱ⿡ ���� �����ϰ� �Ͽ� �����ϴ� ȿ���� ���� �κ�
        if (clock() > letter + 500) //500ms���� �ߵ�
        {
            Textcolor(black, skyblue);
            Main_screen_letter();
            Textcolor(black, blue);
            Main_screen_car();
            Textcolor(black, brightwhite);
            Main_screen_cloud();
        }
        if (clock() > letter + 1000) //1000ms���� �ߵ�
        {
            Textcolor(black, blue);
            Main_screen_letter();
            Textcolor(black, skyblue);
            Main_screen_car();
            Textcolor(black, white);
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

//���� ȭ��
void Help_screen()
{
    system("cls"); Draw_square();
    gotoxy(136, 39); printf("�ڷΰ��� : Q");

    gotoxy(68, 5); printf("            ��");
    gotoxy(68, 6); printf("�̵�  :  ��    ��");
    gotoxy(68, 7); printf("            ��");

    gotoxy(6, 1); printf("���ϼ���!");

    gotoxy(27, 1); printf("������");
    gotoxy(25, 2); printf("ȹ���ϼ���");

    short coin = 0;
    gotoxy(140, 1); printf("���� : %d", coin);

    short x = 2, y = 20; //���� �ʱ� ��ǥ ����� �Բ� �ʱ�ȭ
    help_screen_car.on = true; //�ڵ��� ��ü ����
    help_screen_coin.on = true;

    Draw_player(x, y); Draw_car(help_screen_car.x, help_screen_car.y); //��ü ���
    Draw_coin(help_screen_coin.x, help_screen_coin.y);

    clock_t car = clock(); //�ð� ����

    while (1)
    {
        char input;
        if (_kbhit())
        {
            input = _getch();
            if (input == RIGHT && x < 146) //���� �̵�
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
            Remove_car(help_screen_car.x, help_screen_car.y++); //�ڵ����� ����� ���ÿ� y��ǥ ����
            if (help_screen_car.y >= 39) help_screen_car.y = 4; //���� �ܼ�â�� ����� �ٽ� ���� ����
            Draw_car(help_screen_car.x, help_screen_car.y); //�׷��� ��ǥ ������ ��� �Ϸ�Ǹ� �ڵ����� �׷� ������ ǥ��
            car = clock(); //�ð� �ʱ�ȭ
        }

        if (help_screen_coin.on == true) //��ü�� Ȱ��ȭ�Ǿ� �ִٸ�
        {
            if (help_screen_coin.x <= x && x <= help_screen_coin.x + 1 &&
                help_screen_coin.y == y) //���� ��ü�� ��ǥ�� ��ġ��  
            {
                Remove_coin(help_screen_coin.x, help_screen_coin.y); //���� �����
                Draw_player(x, y); coin++;
                gotoxy(140, 1); printf("���� : %d", coin); //���� ���� �ֽ�ȭ
                help_screen_coin.on = false; //���� ��ü ����
            }
        }

        if (Check_over(x, y) == 1) //�浹���� �Լ��� 1�� ��ȯ�ϸ� ���ӿ���
        {
            Help_screen(); break;
        }
    }

    help_screen_car.on = false; //�ڵ��� ��ü ����
    help_screen_coin.on = false; //���� ��ü ����
}

//��ŷ ȭ��
void Ranking_screen()
{
    system("cls"); Draw_square();

    gotoxy(136, 39); printf("�ڷΰ��� : Q");

    for (int i = 0; i < RANKING; i++)
    {
        if (Ranking[i].score > 0) //������ �־�߸� ���
        {
            gotoxy(20, 5 + i * 3); printf("%s", Ranking[i].name);
            gotoxy(80, 5 + i * 3); printf("%d", Ranking[i].score);
            gotoxy(140, 5 + i * 3); printf("%d", Ranking[i].coins);
        }
    }

    while (1)
    {
        char input;
        if (_kbhit())
        {
            input = _getch();
            if (input == 'q' || input == 'Q') // Q�� ������
            {
                Main_screen(); //����ȭ������ ���ư�
                break;
            }
        }
    }
}