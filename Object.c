#include "Object.h"

//��ǥ�� �޾� �÷��̾� �׸���
void Draw_player(short x, short y)
{
    gotoxy(x, y); printf("��");
}
//��ǥ�� �޾� �÷��̾� �����
void Remove_player(short x, short y)
{
    gotoxy(x, y); printf("  ");
}
//��ǥ�� �޾� ���� �׸���
void Draw_coin(short x, short y)
{
    Textcolor(black, brightyellow);
    gotoxy(x, y); printf("��");
    Textcolor(black, white);
}
//��ǥ�� �޾� ���� �����
//���� ���ΰ� �÷��̾� �������� ����, ���ݸ� ���� ����
void Remove_coin(short x, short y)
{
    gotoxy(x, y); printf("  ");
}
//��ǥ�� �޾� �ڵ��� �׸���
void Draw_car(short x, short y)
{
    Textcolor(black, green);
    if (x == 0) //���� ȭ�鿡 ������
    {
        gotoxy(x, y - 1); printf("^|");
        gotoxy(x, y);     printf(" |");
        gotoxy(x, y + 1); printf("~|");
    }
    else if (x == 149) //���� ȭ�鿡 ������
    {
        gotoxy(x - 1, y - 1); printf("|^");
        gotoxy(x - 1, y);     printf("| ");
        gotoxy(x - 1, y + 1); printf("|~");
    }
    else
    {
        gotoxy(x - 1, y - 1); printf("|^|");
        gotoxy(x - 1, y);     printf("| |");
        gotoxy(x - 1, y + 1); printf("|~|");
    }
    Textcolor(black, white);
}
//��ǥ�� �޾� �ڵ��� �����
void Remove_car(short x, short y)
{
    if (x == 0) //���� ȭ�鿡 ������
    {
        gotoxy(x, y - 1); printf("  ");
        gotoxy(x, y);     printf("  ");
        gotoxy(x, y + 1); printf("  ");
    }
    else if (x == 149) //���� ȭ�鿡 ������
    {
        gotoxy(x - 1, y - 1); printf("  ");
        gotoxy(x - 1, y);     printf("  ");
        gotoxy(x - 1, y + 1); printf("  ");
    }
    else
    {
        gotoxy(x - 1, y - 1); printf("   ");
        gotoxy(x - 1, y);     printf("   ");
        gotoxy(x - 1, y + 1); printf("   ");
    }
}
//��ǥ�� �޾� �� �׸���
void Draw_river(short x, int num)
{
    srand((unsigned int)time(NULL));
    Textcolor(blue, black);
    for (int i = 0; i < 40; i++) //�� ��� �׸���
    {
        for (int j = 0; j < 10; j++)
        {
            gotoxy(x + j, i); printf(" ");
        }
    }

    Textcolor(green, green);
    for (int i = 0; i < RIVER; i++) //���� �ٸ� �׸���
    {
        if (rivers[num].bridge[i] != 0 && rivers[num].bridge[i] != 40) 
        { //���� �ٸ��� y��ǥ�� 0�� 40�� �ƴҶ���
            gotoxy(x, rivers[num].bridge[i]);
            for (int j = 0; j < 10; j++) printf(" ");
        }
    }
    Textcolor(black, white);
}
//��ǥ�� �޾� �� �����
void Remove_river(short x)
{
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            gotoxy(x + j, i); printf(" ");
        }
    }
}

//�ڵ��� ��ü�� ��Ҵ����� �Ǻ��ϴ� �Լ�
bool Check_over(short x, short y)
{
    for (int i = 0; i < CARS; i++) //��� �ڵ��� ��ü�� �˻�
    {
        if (cars[i].on == true) //��ü�� Ȱ��ȭ�Ǿ� �ִٸ�
        {
            if (cars[i].x - 1 <= x && x <= cars[i].x + 1 &&
                cars[i].y - 1 <= y && y <= cars[i].y + 1)
                return 1; //�ڵ��� ��ü�� ������ ��ġ�� 1�� ��ȯ
        }
    }

    if (help_screen_car.on == true) //���Ӽ���ȭ���� �ڵ��� ��ü
    {
        if (help_screen_car.x - 1 <= x && x <= help_screen_car.x + 1 &&
            help_screen_car.y - 1 <= y && y <= help_screen_car.y + 1)
            return 1; //�ڵ��� ��ü�� ������ ��ġ�� 1�� ��ȯ
    }

    return 0; //�Ȱ�ġ�� 0�� ��ȯ
}
//���� ��ü�� ��Ҵ����� �Ǻ��ϴ� �Լ�
bool Check_coin(short x, short y)
{
    for (int i = 0; i < COINS; i++) //��� �ڵ��� ��ü�� �˻�
    {
        if (coins[i].on == true) //��ü�� Ȱ��ȭ�Ǿ� �ִٸ�
        {
            if (coins[i].x <= x && x <= coins[i].x + 1 &&
                coins[i].y == y) //���� ��ü�� ��ǥ�� ��ġ��  
            {
                Delete_coin(i); Score += 50;
                Coins++; //���� ȹ��
                return 1; //������ ����� 1�� ��ȯ   
            }
        }
    }
}
//�� ��ü ���� ������ �� �ִ����� �Ǻ��ϴ� �Լ�
bool Check_river(short x, short y)
{
    for (int i = 0; i < RIVER; i++)
    {
        if (rivers[i].on == true)
        {
            if (rivers[i].x - 2 <= x && x < rivers[i].x + 10)
            {
                int found = 0;
                for (int j = 0; j < RIVER; j++)
                {
                    if (rivers[i].bridge[j] == y)
                    {
                        found++; return 1;
                    }
                }
                if (found == 0)
                    return 0;
            }
        }
    }
    return 1;
}

//�ڵ����� �׸��� ��ü �ϳ��� ��ǥ�� �����ϴ� �Լ�
void Add_car(short x, short y, int num, bool up)
{
    Draw_car(x, y);                         //�ش� ��ġ�� �ڵ����� ���� �׸���
    cars[num].x = x;     cars[num].y = y;   //x, y���� ��ü�� ����ְ�
    cars[num].on = true; cars[num].up = up; //�ش� ��ü�� Ȱ��ȭ �԰� ���ÿ� �⺻������ ���� ����
}
//�ڵ��� ��ü�� �����ϴ� �Լ�
void Delete_car(int num)
{
    Remove_car(cars[num].x, cars[num].y); //�ڵ����� �������
    cars[num].on = false;                 //�ش� ��ü ��Ȱ��ȭ
}
//�ڵ��� ��ü�� "�� �Ʒ���" �� ĭ �̵��ϴ� �Լ�
void Move_car(int num)
{
    if (cars[num].on == true) //�ش� ��ü�� Ȱ��ȭ�Ǿ� �־�߸� �Լ� ���� �ߵ�
    {
        if (cars[num].up == true) //�ش� ��ü�� ���� �����̶��
        {
            Remove_car(cars[num].x, cars[num].y--); //�ڵ����� ����� ���ÿ� y��ǥ ����
            if (cars[num].y <= 1) cars[num].y = 39; //���� �ܼ�â�� ����� �ٽ� ������ ����
        }
        else                      //�ش� ��ü�� �Ʒ��� �����̶��
        {
            Remove_car(cars[num].x, cars[num].y++); //�ڵ����� ����� ���ÿ� y��ǥ ����
            if (cars[num].y >= 40) cars[num].y = 1; //���� �ܼ�â�� ����� �ٽ� ���� ����
        }
        Draw_car(cars[num].x, cars[num].y); //�׷��� ��ǥ ������ ��� �Ϸ�Ǹ� �ڵ����� �׷� ������ ǥ��
    }
}
//ȭ���� �����ӿ� ���� �ڵ��� ��ü�� �̵��ϴ� �Լ�
void Floating_car(bool direction)
{ //direction�� 0 �̸� ����, direction�� 1 �̸� ����
    for (int i = 0; i < CARS; i++) //��� �ڵ��� ��ü�� �˻�
    {
        if (cars[i].on == true) //�ش� ��ü�� Ȱ��ȭ�Ǿ� �ִٸ�
        {
            Remove_car(cars[i].x, cars[i].y); //�ڵ����� ���� �����
            if (direction == 0) cars[i].x--;  //���� ������ ������ �о� x��ǥ ����
            else cars[i].x++;
            if (cars[i].x < 0 || cars[i].x > 149) //���� �¿� �ܼ�â�� ����ٸ�
                Delete_car(i);                    //��ü ����
            else
                Draw_car(cars[i].x, cars[i].y);   //�����̶�� �ڵ����� �׸��� ������ ǥ��
        }
    }
}

//������ �׸��� ��ü �ϳ��� ��ǥ�� �����ϴ� �Լ�
void Add_coin(short x, short y, int num)
{
    Draw_coin(x, y);
    coins[num].x = x;     coins[num].y = y; //���� ���� ����
    coins[num].on = true;
}
//���� ��ü�� �����ϴ� �Լ�
void Delete_coin(int num)
{
    Remove_coin(coins[num].x, coins[num].y); //������ �������
    coins[num].on = false;                   //�ش� ��ü ��Ȱ��ȭ
}
//ȭ���� �����ӿ� ���� ���� ��ü�� �̵��ϴ� �Լ�
void Floating_coin(bool direction)
{ //direction�� 0 �̸� ����, direction�� 1 �̸� ����
    for (int i = 0; i < COINS; i++) //���� ���� ����
    {
        if (coins[i].on == true)
        {
            Remove_coin(coins[i].x, coins[i].y);
            if (direction == 0) coins[i].x--;
            else coins[i].x++;
            if (coins[i].x < 0 || coins[i].x > 148)
                Delete_coin(i);
            else
                Draw_coin(coins[i].x, coins[i].y);
        }
    }
}

//���� �׸��� ��ü �ϳ��� ��ǥ�� �����ϴ� �Լ�
void Add_river(short x, int num)
{
    srand((unsigned int)time(NULL));
    rivers[num].x = x;      // x��ǥ ����
    rivers[num].on = true;  //��ü Ȱ��ȭ
    for (int i = 0; i < rand() % 5 + 1; i++)
    {
        short bridge_y = rand() % 40; //���� �ٸ��� y�� ���� ����
        //�ߺ����� �߰����, 0�� 40�� �ȵ�
        rivers[num].bridge[i] = bridge_y; //���� �ٸ� y�� ����
    }
    Draw_river(x, num);
}
//�� ��ü�� �����ϴ� �Լ�
void Delete_river(int num)
{
    Remove_river(rivers[num].x);
    rivers[num].on = false; //��ü ��Ȱ��ȭ
    for (int i = 0; i < RIVER; i++)
    {
        rivers[num].bridge[i] = 0; //��� �ٸ��� ��ǥ�� 0���� �����Ͽ� �ʱ�ȭ
    }
}
//ȭ���� �����ӿ� ���� �� ��ü�� �̵��ϴ� �Լ�
void Floating_river(bool direction)
{ //direction�� 0 �̸� ����, direction�� 1 �̸� ����
    for (int i = 0; i < RIVER; i++) //��� �� ��ü�� �˻�
    {
        if (rivers[i].on == true) //�ش� ��ü�� Ȱ��ȭ�Ǿ� �ִٸ�
        {
            Remove_river(rivers[i].x); //���� ���� �����

            if (direction == 0) rivers[i].x--;  //���� ������ ������ �о� x��ǥ ����
            else rivers[i].x++;
            if (rivers[i].x < 0 || rivers[i].x > 149) //���� �¿� �ܼ�â�� ����ٸ�
                Delete_river(i);      //�������                //��ü ����
            else
                Draw_river(rivers[i].x, i);
        }
    }
}

//Ȱ��ȭ���� ���� ��ü ��ȣ�� ã�� �Լ�
short Find_car() //�ڵ���
{
    for (int i = 0; i < CARS; i++) //��� ��ü�� �˻�
        if (cars[i].on == false) return i;
    //���� Ȱ��ȭ���� ���� ��ü�� ��ȣ�� ã���� ��ȣ�� ��ȯ�ϸ� ��ٷ� �Լ� ����
}
short Find_coin() //����
{
    for (int i = 0; i < COINS; i++)
        if (coins[i].on == false) return i;
}