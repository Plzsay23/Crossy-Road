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
//�ڵ��� ��ü�� �� ĭ �̵��ϴ� �Լ�
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