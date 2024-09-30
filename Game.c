#include "Game.h"

//���ӿ���
void Game_over(short x, short y)
{
    Remove_player(x, y);
    Sleep(1500);
}

//���� ������ �ʱ�ȭ
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

//�ΰ���
void Game()
{
    system("cls"); srand((unsigned int)time(NULL)); //���� ������ ���� �õ� ����
    Recycle(); //��ü �Ӽ��� �ʱ�ȭ

    clock_t cars_time = clock();  //�ڵ����� ������ �ð� ����
    clock_t cars_speed = clock(); //�ڵ��� �ӵ��� ������ �ð� ����

    short x = start_x, y = start_y; //���� �ʱ� ��ǥ ����� �Բ� �ʱ�ȭ
    unsigned short choose = 0; //��ü�� ������ ����
    long floating_x; //x��ǥ�� ������ ����
    bool is_spawn = 0; //���� ��ȯ�ƴ��� �ƴ����� �Ǵ��� ����

    Draw_player(x, y);


    for (int i = 10; i < 150; i += 10) //�ʱ� ȭ���� ������ŭ�� �ڵ��� ��ü Ȱ��ȭ & ��ȯ
    {
        Add_car(i, rand() % 39 + 1, Find_car(), rand() % 2); //�� ���ڴ� Add_car �Լ� ����
    }

    //Add_river(146, 0);

    while (1) //�ൿ ����
    {
        char input;
        if (_kbhit()) //Ű���尡 ��������
        {
            input = _getch();
            if (input == RIGHT && x < 148) //������ �̵�
            {
                if (Check_river(x, y) == 0) continue; //�� ���� ������ �� ���ٸ� ���ư�

                if (extra_display < 1000 && x >= start_x) //�������� 1000ĭ�� �÷��� �ǵ��� ����
                { //���� �ӽ÷� 1000ĭ, ���� �ø��� ���� ����
                    Floating_car(0); //�ڵ������� �������� �з����� �̵��� ǥ��
                    Floating_coin(0); //���ε��� �������� �з����� �̵��� ǥ��
                    Floating_river(0); //�� �÷���
                    extra_display++; //�÷��� �̵��� ������ ����

                    if (choose == 0)
                    {
                        choose = Choose_object(); //� ��ü�� �������� ����
                        floating_x = extra_display; //�����ϴ� x��ǥ ����
                    }

                    switch (choose)
                    {
                    case 1: //�ڵ���
                        if (extra_display - floating_x <= 80)
                        {
                            if (extra_display % 10 == 0) //10ĭ���� ��ȯ
                            {
                                Add_car(148, rand() % 37, Find_car(), rand() % 2);
                                Score += 30; //�׷������� 30�� �߰�
                                if (rand() % 100 > 15) //Ȯ���� 15%
                                        Add_coin(145, rand() % 41, Find_coin()); //���� ��ü ����
                            }
                        }
                        else choose = 0;
                        break;
                    case 2: //��
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
                    //ȭ���� �����̸� ��� ������ �ֱ������� �ڵ��� ��ü Ȱ��ȭ & ��ȯ
                    if (extra_display < 1000 && (extra_display + x - 79) % 5 == 0)
                    {   //�÷��ý� x���� 79�� ����, ���� �÷����� ĭ���� 5ĭ��ŭ �ö����� ��ü ����
                        //��, �ڵ����� �ڵ��� ������ �ֱⰡ 5�� ��
                        //������������ x - 79�� �׻� 0�̶� �ǹ̰� �ִ��� ���캼 �ʿ� ��������
                        Add_car(148, rand() % 39 + 1, Find_car(), rand() % 2);
                        Score += 30; //�׷������� 30�� �߰�
                        coin_cycle++;
                        if (coin_cycle % 3 == 0) //������ ������ �ڵ��� ������ ������������ ����
                        {
                            if (rand() % 100 > 50) //Ȯ���� 2���� 1
                                Add_coin(145, rand() % 41, Find_coin()); //���� ��ü ����
                            coin_cycle = 0; //���� Ȯ�� �� 6���� 1
                        }
                    }
                    */

                    Draw_player(x, y);
                }
                else //�÷����� �ƴϸ�
                {
                    Remove_player(x++, y); //�� ����鼭 ��ǥ �̵�
                    Draw_player(x, y);
                }
                Sleep(10); //�ణ�� ������
            }
            if (input == LEFT && x > 0) //���� �̵�
            {
                Remove_player(x--, y);
                Draw_player(x, y);
                Sleep(10); //�ణ�� ������
            }
            if (input == UP && y > 0) //���� �̵�
            {
                Remove_player(x, y--);
                Draw_player(x, y);
                Sleep(10);
            }
            if (input == DOWN && y < 40) //�Ʒ��� �̵�
            {
                Remove_player(x, y++);
                Draw_player(x, y);
                Sleep(10);
            }
        }

        if (clock() > cars_time + 100) //100ms���� �ߵ�
        {
            for (int i = 0; i < CARS; i++) Move_car(i); //��� �ڵ��� ��ü�� y���� ����
            cars_time = clock(); //�ð� �ʱ�ȭ
            Score++; //0.1�ʸ��� 1�� �߰�
        }
        /*
        if (clock() > cars_speed + 5) //������ ��ü�� ������ �ӵ� ���������� ����
        {
            int car = rand() % CARS; //�ƹ��ų� ����
            Move_car(car); //�ϳ��� �ڵ����� ����
            cars_speed = clock(); //�ð� �ʱ�ȭ
        }
        */
        if (Check_over(x, y) == 1) //�浹���� �Լ��� 1�� ��ȯ�ϸ� ���ӿ���
        {
            Game_over(x, y); break;
        }
        if (Check_coin(x, y) == 1) //���ΰ� �ε����ٸ�
        {

            Draw_player(x, y);
        }
    }

    Ranking_sort(); //��ŷ ����
    Ranking_screen(); //��ŷ ȭ��
}
