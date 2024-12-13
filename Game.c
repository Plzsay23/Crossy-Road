#include "Game.h"

//���ӿ���
void Game_over(short x, short y)
{
    Play_bgm(Gameover_sound, 0);
    Remove_player(x, y);
    Sleep(2000);
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
        items[i].on = false; items[i].type = 0;
    }
    extra_display = 0;
}

//�ΰ���
void Game()
{
    system("cls"); srand((unsigned int)time(NULL)); //���� ������ ���� �õ� ����
    init_object(); //��ü ���� �޸� �Ҵ�
    Recycle(); //��ü �Ӽ��� �ʱ�ȭ

    clock_t cars_time = clock();        //�ڵ����� ������ �ð� ����
    clock_t cars_speed = clock();       //�ڵ��� �ӵ��� ������ �ð� ����
    clock_t monsters_time = clock();    //���Ͱ� ������ �ð� ����
    clock_t trains_time = clock();      //������ ������ �ð� ����
    clock_t trains_charge = clock();    //������ �������� �ð� ����
    clock_t point_time = clock();       //����Ʈ ���ӽð� ����
    clock_t invincible_time = clock();  //���� ���ӽð� ����
    clock_t fever_time = clock();       //�ǹ� ���ӽð� ����
    clock_t time_time = clock();        //Ÿ�� ���ӽð� ����

    index = 0;                              //�ε��� �ʱ�ȭ
    short x = start_x + 1, y = start_y;     //���� �ʱ� ��ǥ ����� �Բ� �ʱ�ȭ
    unsigned short choose = 0;              //��ü�� ������ ����
    long floating_x, floating_display = 0;  //x��ǥ�� ������ ����
    bool is_spawn = 0;                      //��ü�� ��ȯ�ƴ��� �ƴ����� �Ǵ��� ����
    int train_spawn = 0;                    //������ ��ȯ�Ǿ����� �˸��� ����
    bool is_varrier = 0;                    //�踮�� ���¸� �Ǻ��ϴ� ����
    bool is_point = 0;                      //����Ʈ ���¸� �Ǻ��ϴ� ����
    bool is_invincible = 0;                 //���� ���¸� �Ǻ��ϴ� ����
    bool is_fever = 0;                      //�ǹ� ���¸� �Ǻ��ϴ� ����
    bool is_time = 0;                       //Ÿ�� ���¸� �Ǻ��ϴ� ����
    Itemcheck result;                       //�����۰� �浹������ ������ �޾ƿ� ����

    Queue object;                           //������Ʈ�� ���� ������ ���ϴ� ť
    init_queue(&object);                    //ť �ʱ�ȭ
    element object_index = 1;               //������Ʈ�� ������ ����
    for(int i=0; i<5; i++) 
        enqueue(&object, object_index++);   //ť�� �ʱⰪ ��ť
    gotoxy(0, 0); printf("%d", object.data[object.front + 1]);

    Draw_player(x, y);

    for (int i = 79; i < 149; i += 8) //�ʱ� ȭ���� ������ŭ�� �ڵ��� ��ü Ȱ��ȭ & ��ȯ
        Add_car(i, rand() % 41, Find_car(), rand() % 2);

    Play_bgm(Game_bgm, 1);

    while (1) //�ൿ ����
    {
        char input;
        if (_kbhit()) //Ű���尡 ��������
        {
            input = _getch();
            if (input == RIGHT && x < 148) //������ �̵�
            {
                floating_display++;
                if (x >= start_x) //���� x��ǥ�� �߾Ӻ��� ũ�ٸ�
                {
                    Floating_car();     //�ڵ������� �������� �з����� �̵��� ǥ�� = �÷���
                    Floating_coin();    //���� �÷���
                    Floating_river();   //�� �÷���
                    Floating_monster(); //���� �÷���
                    Floating_train();   //���� �÷���
                    Floating_item();    //���� �÷���
                    extra_display++;    //�÷��� �̵��� ������ ����

                    if (choose == 0)    //������ 0���� �ʱ�ȭ�Ǿ��ٸ�
                    {
                        choose = Choose_object(&object); //� ��ü�� �������� ����
                        floating_x = extra_display; //�����ϴ� x��ǥ ����
                        floating_display = 0; //��ü ���� �� �� ĭ�� �̵��ߴ����� �����ϴ� ����
                    }

                    switch (choose)
                    {
                    case 1: //�ڵ���
                        if (extra_display - floating_x < 46) //41ĭ ���� �� ���� ����
                        {
                            if (floating_display % 8 == 0) //7ĭ���� ��ȯ
                            {
                                Add_car(149, rand() % 41, Find_car(), rand() % 2);
                                if (is_point) Score += 60; else Score += 30; //�׷������� 30�� �߰�                            
                            }
                            if ((floating_display + 1) % 8 == 0) //�ڵ����� �ڵ��� ���̿� ��ȯ�ǵ��� ����
                            {
                                int i = rand() % 100;
                                if (i <= 70) //Ȯ���� 70%
                                    Add_coin(149, rand() % 41, Find_coin()); //���� ��ü ����
                                else if (i <= 80) //Ȯ���� 10%
                                    Add_item(148, rand() % 41, Find_item(), rand() % 6); //������ ���� ��ȯ
                            }
                        }
                        else
                        {
                            choose = 0; //0���� �ʱ�ȭ
                            enqueue(&object, object_index++); //���� ������Ʈ ��ť
                        }
                        break;
                    case 2: //��
                        if (extra_display - floating_x < 10) //10ĭ ���� �� ���� ����
                        {
                            if (is_spawn == false) //��ȯ���� �ʾҴٸ�
                            {
                                Add_river(149, Find_river()); //�� ��ü ��ȯ
                                if (is_point) Score += 200; else Score += 100; is_spawn = 1;
                            }
                        }
                        else 
                        { 
                            choose = 0; is_spawn = 0; //0���� �ʱ�ȭ
                            enqueue(&object, object_index++); //���� ������Ʈ ��ť
                        } 
                        break;
                    case 3: //����
                        if (extra_display - floating_x < 33) //33ĭ ���� �� ���� ����
                        {
                            if (floating_display % 7 == 0) //7ĭ���� ��ȯ
                            {
                                bool up = rand() % 2;
                                int mon_y = rand() % 41;
                                int mon_y2 = (mon_y + 20) % 41; //2���� ��ȯ�ϱ� ����
                                Add_monster(149, mon_y, Find_monster(), up);
                                Add_monster(149, mon_y2, Find_monster(), up);
                                if (is_point) Score += 60; else Score += 30; //�׷������� 30�� �߰�                            
                            }
                        }
                        else
                        {
                            choose = 0; //0���� �ʱ�ȭ
                            enqueue(&object, object_index++); //���� ������Ʈ ��ť
                        }
                        break;
                    case 4: //����
                        if (extra_display - floating_x < 7) //7ĭ ���� �� ���� ���� - �����ؾ� ��
                        {
                            if (is_spawn == false) //��ȯ���� �ʾҴٸ�
                            {   //ù ��ġ�� ���� �ϳ��� ��¥ ��ü �ϳ��� ��ȯ
                                for (int i = 0; i < 2; i++) Add_train(149, 0, Find_train());
                                train_x = 149; //������ x��ǥ ���� ����
                                if (is_point) Score += 400; else Score += 200; //�׷������� ���� �߰�
                                is_spawn = 1; train_spawn = 1; trains_charge = clock(); //���� ��ȯ ����
                            }
                        }
                        else 
                        { 
                            choose = 0; is_spawn = 0; //0���� �ʱ�ȭ
                            enqueue(&object, object_index++); //���� ������Ʈ ��ť
                        } 
                        break;
                    }
                    Draw_player(x, y); //�׸��� �÷��̾� �̵�
                }
                else //�÷����� �ƴϸ�
                {
                    Remove_player(x, y); x += 2; //�� ����鼭 ��ǥ �̵�
                    Draw_player(x, y);
                }
                Sleep(5); //�ణ�� ������
            }
            else if (input == LEFT && x > 0) //���� �̵�
            {
                Remove_player(x--, y);
                Draw_player(x, y);
                Sleep(5); //�ణ�� ������
            }
            else if (input == UP && y > 0) //���� �̵�
            {
                Remove_player(x, y--);
                Draw_player(x, y);
                Sleep(5);
            }
            else if (input == DOWN && y < 40) //�Ʒ��� �̵�
            {
                Remove_player(x, y++);
                Draw_player(x, y);
                Sleep(5);
            }
        }

        if (!is_time && clock() > cars_time + 50) //50ms���� �ߵ�
        {
            for (int i = 0; i < CARS; i++) Move_car(i); //��� �ڵ��� ��ü�� y���� ����
            cars_time = clock(); //�ð� �ʱ�ȭ
            if (is_point) Score += 2; else Score++; //0.05�ʸ��� 1�� �߰�
        }
        if (!is_time && clock() > monsters_time + 25) //250ms���� �ߵ�
        {
            for (int i = 0; i < MONSTERS; i++) Move_monster(i); //��� ���� ��ü�� y���� ����
            monsters_time = clock();
        }
        if (!is_time && train_spawn == 1 && clock() > trains_charge + 3000) //������ ��ȯ�Ǹ�
        {
            if (clock() > train + 10 && trains[0].on) //10ms���� �ߵ�
            {
                static short train_y = 0; //y���� ������ ���� ����
                train_y++; //1ĭ�� ����
                if (train_y % 6 == 0 && train_y <= 36) //���� ���� ������ 6ĭ ����
                    Add_train(trains[0].x, train_y, Find_train()); //������ ����� ��ȯ
                else if (train_y > 36) //������ �����
                {
                    train_y = 0; trains[0].on = false; //ù ������ ����
                }
                trains_time = clock();
            }
            if (trains[0].on == false) //0�� ���� ��ü�� �������
            {
                train_spawn = 2; trains_charge = clock(); //���� �������� �Ѿ
            }
        }
        if (!is_time && train_spawn == 2 && clock() > trains_charge + 1000) //������ ������ ���� ��
        {
            if (clock() > trains_time + 50)
            {
                static int index = 1;
                Delete_train(index++); //������ ���������� �ϳ��� ����
                trains_time = clock();
                if (index >= 8) //���� ������ 8�̻��� �Ǹ�
                {
                    index = 1; train_spawn = 1; trains_charge = clock(); //�ٽ� ó������ ��� �ʱ�ȭ
                    for (int i = 0; i < 2; i++) Add_train(train_x, 0, Find_train());
                }
            }
        }

        //�踮� Ȱ��ȭ�Ǿ��ٸ�
        if (varrier_on && !is_varrier)
            is_varrier = 1; //�踮������ �˸�

        //����Ʈ�� Ȱ��ȭ�Ǿ��ٸ�
        if (point_on && !is_point)
            is_point = 1; //����Ʈ���� �˸�
        //���ӽð��� ������
        if (clock() > point_time + point_duration * 1000)
        {   //����Ʈ ����
            is_point = 0; point_on = 0;
        }
        
        //������ Ȱ��ȭ�Ǿ��ٸ�
        if (invincible_on && !is_invincible) 
            is_invincible = 1; //�������� �˸�
        //���ӽð��� ������
        if (clock() > invincible_time + invincible_duration * 1000)
        {   //���� ����
            is_invincible = 0; invincible_on = 0;
        }

        //�ǹ��� Ȱ��ȭ�Ǿ��ٸ�
        if (fever_on && !is_fever)
            is_fever = 1; //�ǹ����� �˸�
        //���ӽð��� ������
        if (clock() > fever_time + fever_duration * 1000)
        {   //�ǹ� ����
            is_fever = 0; fever_on = 0;
        }

        //Ÿ���� Ȱ��ȭ�Ǿ��ٸ�
        if (time_on && !is_time)
            is_time = 1; //Ÿ������ �˸�
        //���ӽð��� ������
        if (clock() > time_time + time_duration * 1000)
        {   //Ÿ������
            is_time = 0; time_on = 0;
        }

        ////�浹���� �Լ��� 1�� ��ȯ�ϸ� ���ӿ���
        //if (!is_invincible && Check_car(x, y) == 1) //�ڵ����� ��Ҵٸ� ���ӿ���
        //{
        //    if (is_varrier) //�踮�� ���¶��
        //    {   //�踮� �����ϰ� ª�� �����ο�
        //        is_varrier = 0; varrier_on = 0; invincible_on = 1;
        //        invincible_duration = 1; invincible_time = clock();
        //    }
        //    else
        //    {
        //        Game_over(x, y); break;
        //    }
        //}
        //else if (!is_invincible && Check_river(x, y) == 1) //���� �����ٸ� ���ӿ���
        //{
        //    if (is_varrier) //�踮�� ���¶��
        //    {   //�踮� �����ϰ� ª�� �����ο�
        //        is_varrier = 0; varrier_on = 0; invincible_on = 1;
        //        invincible_duration = 1; invincible_time = clock();
        //    }
        //    else
        //    {
        //        Game_over(x, y); break;
        //    }
        //}
        //else if (!is_invincible && Check_monster(x, y) == 1) //���Ϳ� ��Ҵٸ� ���ӿ���
        //{
        //    if (is_varrier) //�踮�� ���¶��
        //    {   //�踮� �����ϰ� ª�� �����ο�
        //        is_varrier = 0; varrier_on = 0; invincible_on = 1;
        //        invincible_duration = 1; invincible_time = clock();
        //    }
        //    else
        //    {
        //        Game_over(x, y); break;
        //    }
        //}
        //else if (!is_invincible && Check_train(x, y) == 1) //������ ��Ҵٸ� ���ӿ���
        //{
        //    if (is_varrier) //�踮�� ���¶��
        //    {   //�踮� �����ϰ� ª�� �����ο�
        //        is_varrier = 0; varrier_on = 0; invincible_on = 1;
        //        invincible_duration = 1; invincible_time = clock();
        //    }
        //    else
        //    {
        //        Game_over(x, y); break;
        //    }
        //}

        if (Check_coin(x, y) == 1) //���ΰ� �ε����ٸ�
        {
            if (is_point) Score += 100; else Score += 50;
            Draw_player(x, y); //������ �÷��̾� �ٽ� �׸�
        }

        result = Check_item(x, y); //������ �浹
        if (result.found == 1) //�����۰� �ε����ٸ�
        {
            switch (result.type) //������ ������ �޾Ƽ�
            {
            case point:
                point_time = clock(); break; //���ӽð� �ʱ�ȭ
            case invincible:
                invincible_time = clock(); break; //���ӽð� �ʱ�ȭ
            case fever:
                point_time = clock(); invincible_time = clock(); 
                fever_time = clock(); break; //���ӽð� �ʱ�ȭ
            case _time:
                time_time = clock(); break; //���ӽð� �ʱ�ȭ
            case star: //��Ÿ�� ��� �߰� ����
                if (is_point) Score += 2000; else Score += 1000;
            }
            Draw_player(x, y); //������ �÷��̾� �ٽ� �׸�
            if (is_point) Score += 200; else Score += 100;
        }
    }

    free_object(); //��ü ���� �޸� ����

    Ranking_sort(); //��ŷ ����
    Ranking_screen(); //��ŷ ȭ��
}

