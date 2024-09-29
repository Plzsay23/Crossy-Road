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
}

//�ΰ���
void Game()
{
    system("cls"); srand((unsigned int)time(NULL)); //���� ������ ���� �õ� ����
    Recycle(); //��ü �Ӽ��� �ʱ�ȭ

    clock_t cars_time = clock();  //�ڵ����� ������ �ð� ����
    clock_t cars_speed = clock(); //�ڵ��� �ӵ��� ������ �ð� ����

    short x = start_x, y = start_y; //���� �ʱ� ��ǥ ����� �Բ� �ʱ�ȭ
    short coin_cycle = 0;

    Draw_player(x, y);

    for (int i = 5; i < 150; i += 5) //�ʱ� ȭ���� ������ŭ�� �ڵ��� ��ü Ȱ��ȭ & ��ȯ
    {
        Add_car(i, rand() % 39 + 1, Find_car(), rand() % 2); //�� ���ڴ� Add_car �Լ� ����
    }

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
                    //���� �ӽ÷� 1000ĭ, ���� �ø��� ���� ����
                {
                    Floating_car(0); //�ڵ������� �������� �з����� �̵��� ǥ��
                    Floating_coin(0); //���ε��� �������� �з����� �̵��� ǥ��
                    extra_display++; //�÷��� �̵��� ������ ����

                    //Floating_river(0); //�� �÷���

                    //ȭ���� �����̸� ��� ������ �ֱ������� �ڵ��� ��ü Ȱ��ȭ & ��ȯ
                    if (extra_display < 1000 && (extra_display + x - 79) % 5 == 0)
                    {   //�÷��ý� x���� 79�� ����, ���� �÷����� ĭ���� 5ĭ��ŭ �ö����� ��ü ����
                        //��, �ڵ����� �ڵ��� ������ �ֱⰡ 5�� ��
                        //������������ x - 79�� �׻� 0�̶� �ǹ̰� �ִ��� ���캼 �ʿ� ���������
                        //if(����) == continue
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
                    Draw_player(x, y);
                }
                else //�÷����� �ƴϸ�
                {
                    Remove_player(x++, y); //�� ����鼭 ��ǥ �̵�
                         //�� �׸���    
                }
                Sleep(33); //�ణ�� ������
            }
            if (input == LEFT && x > 0) //���� �̵�
            {
                if (extra_display > -1000 && x < start_x) //���� ����, ���⸸ �ݴ�
                { //���������������� �÷����� �������� ����ߡ�����������
                    Floating_car(1);
                    Floating_coin(1);
                    extra_display--;
                    if (extra_display > -1000 && abs(extra_display + x - 76) % 5 == 0)
                        Add_car(1, rand() % 39 + 1, Find_car(), rand() % 2);
                }
                else
                {
                    Remove_player(x--, y);
                    Draw_player(x, y);
                }
                Sleep(33); //�ణ�� ������
            }
            if (input == UP && y > 0) //���� �̵�
            {
                Remove_player(x, y--);
                Draw_player(x, y);
                Sleep(33); //���Ʒ��� �¿�� ������ 2:1�̶� 66���� ����
            }
            if (input == DOWN && y < 40) //�Ʒ��� �̵�
            {
                Remove_player(x, y++);
                Draw_player(x, y);
                Sleep(33);
            }
        }

        if (clock() > cars_time + 100) //100ms���� �ߵ�
        {
            for (int i = 0; i < CARS; i++) Move_car(i); //��� �ڵ��� ��ü�� y���� ����
            cars_time = clock(); //�ð� �ʱ�ȭ
            Score++; //0.1�ʸ��� 1�� �߰�
        }
        if (clock() > cars_speed + 5) //������ ��ü�� ������ �ӵ� ���������� ����
        {
            int car = rand() % CARS; //�ƹ��ų� ����
            Move_car(car); //�ϳ��� �ڵ����� ����
            cars_speed = clock(); //�ð� �ʱ�ȭ
        }

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