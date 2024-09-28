#include "Setting.h"
#include "Variable.h"

//�̹��� �ּҸ� ���� ������ ���� ����
typedef const char* Image; //��Ī ����
Image Beer = "Images\\Beer.raw";

//������ ���� ���� ���� �����ϴ� �Լ�
void Textcolor(int bgcolor, int txcolor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (bgcolor << 4) + txcolor);
}

//�̹��� ��� ���� ���� �ڵ�, GPT ���
HWND hwnd; //���� ���׶��� �������� �ڵ��� ������
HDC hdc; //�������� Ŭ���̾�Ʈ ������ ���� ����̽� ���ؽ�Ʈ�� ������

//���� ���� �Լ�
//https://blockdmask.tistory.com/344
//https://blog.naver.com/ifthe1201/221056588399
void Setting()
{
    //�̹��� �������� ���� ������ Ȱ���ϱ� ���� ����
    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    //�ܼ�â ũ��� ����
    system("mode con:cols=150 lines=41");
    system("title Welcome");

    //Ŀ�� �����Ÿ� ����
    HANDLE hConsole; CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = 0; ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);

    //�ܺ� ���Ͽ� ����� ��ŷ �ҷ�����
    Read_ranking();
}

//Ŀ�� ��ġ �̵�
//https://blog.naver.com/ifthe1201/221056588399
void gotoxy(int x, int y)
{
    COORD pos = { x,y }; //windows ������Ͽ� ����� x,y ��ǥ�� �����ϴ� ����ü
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//��ŷ ����
void Ranking_sort()
{
    User user; //���� ���� �� �̸��� ������ ������ ����ü ����
    user.score = Score; //�� ����ü�� ���� ��ǲ
    user.coins = Coins; //���� ��ǲ
    strcpy(user.name, Name); //�̸� ��ǲ

    int found = 0; //�ߺ��� �̸��� �ִ��� ���θ� �����ϴ� ����

    //�ߺ��� �̸��� ã�Ƽ� ���� ����
    for (int i = 0; i < RANKING; i++) {
        if (strcmp(user.name, Ranking[i].name) == 0) {
            //�̸��� �̹� �����ϴ� ��� ����, ���� ����
            if(user.score > Ranking[i].score) //���� ���� ������ �� Ŭ ���� ����
                Ranking[i].score = user.score;
            Ranking[i].coins = user.coins;
            found = 1;
            for (int j = 0; j < RANKING; j++)
            {
                for (int h = 0; h < RANKING - j; h++)
                {
                    if (Ranking[h].score < Ranking[h + 1].score)
                    {
                        User tmp = Ranking[h];
                        Ranking[h] = Ranking[h + 1];
                        Ranking[h + 1] = tmp;
                    }
                }
            }
            break;
        }
    }

    //�ߺ��� �̸��� ������ ���, ��ŷ �迭�� ���ο� ����� �߰�
    if (!found) {
        for (int i = 0; i < RANKING; i++) {
            if (user.score > Ranking[i].score ||
                (user.score == Ranking[i].score && strcmp(user.name, Ranking[i].name) < 0)) {
                // ������ ���ٸ� ���ĺ� ������ ����
                for (int j = RANKING - 1; j > i; j--) {
                    Ranking[j] = Ranking[j - 1];
                }
                Ranking[i] = user;
                break;
            }
        }
    }

    //��ŷ �ܺ� ���Ͽ� ����
    FILE* Rank = fopen("Ranking.txt", "w");

    for (int i = 0; i < RANKING; i++)
    {
        if (Ranking[i].score > 0)
        {
            fprintf(Rank, "%s %d\n", Ranking[i].name, Ranking[i].score);
        }
    }
    fclose(Rank);
}

//���� ���۽� ����� ��ŷ�� �ҷ����� �Լ�
void Read_ranking()
{
    FILE* Rank = fopen("Ranking.txt", "r");
    if (Rank == NULL) return; //ó�� �����̾ ����� ������ ���ٸ� �����ϰ� ����
    int rank = 0;
    while (fscanf(Rank, "%s %d", Ranking[rank].name, &Ranking[rank].score) != EOF)
    {
        rank++;
    }
    fclose(Rank);
}

//�̹����� ���� �迭�� �о���� �Լ�
void ReadImage(const char* filePath, unsigned char* image)
{
    FILE* fp = fopen(filePath, "rb"); //���������� ���� ����
    if (fp == NULL) { return; } //������ ������ ������ �浹�� ���� ���� �Լ� ����
    fread(image, 1, IMAGE_SIZE, fp); //�̹��� �����͸� ����
    fclose(fp);
}

//�̹��� ��� �Լ� ��� ����
