#include "Setting.h"
#include "Variable.h"
#include <mmsystem.h> //���
#pragma comment(lib,"winmm.lib") //���

//���� ���� �����ϴ� �Լ�
void textcolor(int r, int g, int b) 
{
    printf("\033[38;2;%d;%d;%dm", r, g, b); //RGB ������ ���ڻ� ����
}
//������ ��� ���� �����ϴ� �Լ�
void bgcolor(int r, int g, int b)
{
    printf("\033[48;2;%d;%d;%dm", r, g, b); //RGB ������ ���� ����
}
//���ڿ� ������ ������� �ǵ����� �Լ�
void removecolor()
{
    printf("\033[0m"); //Black, White �⺻�� ����
}

//���� ���� �Լ�
//https://blockdmask.tistory.com/344
//https://blog.naver.com/ifthe1201/221056588399
void Setting()
{
    //�̹��� �������� ���� ������ Ȱ���ϱ� ���� ����
    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    //�ܼ�â ũ��� ����
    system("mode con: cols=150 lines=41");
    system("title Crossy Road");

    //Ŀ�� �����Ÿ� ����
    HANDLE hConsole; CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = 0; ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);

    //�ܼ�â �ػ� ���� ����
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    //�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�//
    //ȭ�� �ػ󵵰� ���� ������ ���Ƿ� ��������
    int x = 1235; //1215
    int y = 695;  //695
    //�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�//

    //������ ������ �ػ� ����
    MoveWindow(console, r.left, r.top, x, y, TRUE);

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

//������ �����ϴ� �Լ�
void Store_color(int i)
{
    Ranking[i].color[0].r = p_rgb.r; Ranking[i].color[0].g = p_rgb.g; Ranking[i].color[0].b = p_rgb.b;
    Ranking[i].color[1].r = c_rgb.r; Ranking[i].color[1].g = c_rgb.g; Ranking[i].color[1].b = c_rgb.b;
    Ranking[i].color[2].r = m_rgb.r; Ranking[i].color[2].g = m_rgb.g; Ranking[i].color[2].b = m_rgb.b;
    Ranking[i].color[3].r = t_rgb.r; Ranking[i].color[3].g = t_rgb.g; Ranking[i].color[3].b = t_rgb.b;
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
        if (strcmp(user.name, Ranking[i].name) == 0) 
        {   //�̸��� �̹� �����ϴ� ��� ����, ���� ����
            if (user.score > Ranking[i].score) //���� ���� ������ �� Ŭ ���� ����
                Ranking[i].score = user.score;
            Ranking[i].coins = user.coins;
            Store_color(i); //���� ���� 
            found = 1;
            for (int j = 0; j < RANKING; j++)
            {
                for (int h = 0; h < RANKING - j - 1; h++)
                {
                    if (Ranking[h].score < Ranking[h + 1].score) //���� ����
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
                (user.score == Ranking[i].score && strcmp(user.name, Ranking[i].name) < 0)) 
            {   //������ ���ٸ� ���ĺ� ������ ����
                for (int j = RANKING - 1; j > i; j--) 
                    Ranking[j] = Ranking[j - 1];
                Ranking[i] = user;
                Store_color(i);
                break;
            }
        }
    }

    //��ŷ �ܺ� ���Ͽ� ����
    FILE* Rank = fopen("Ranking.txt", "w");
    for (int i = 0; i < RANKING; i++)
    {
        if (Ranking[i].score > 0)
        {   //�̸�, ����, ����
            fprintf(Rank, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
                Ranking[i].name, Ranking[i].score, Ranking[i].coins,
                Ranking[i].color[0].r, Ranking[i].color[0].g, Ranking[i].color[0].b,
                Ranking[i].color[1].r, Ranking[i].color[1].g, Ranking[i].color[1].b,
                Ranking[i].color[2].r, Ranking[i].color[2].g, Ranking[i].color[2].b,
                Ranking[i].color[3].r, Ranking[i].color[3].g, Ranking[i].color[3].b);
        }
    }
    fclose(Rank);
}

//���� ���۽� ����� ��ŷ�� �ҷ����� �Լ�
void Read_ranking()
{
    FILE* Rank = fopen("Ranking.txt", "r");
    if (!Rank) {
        printf("��ŷ ������ ã�� �� �����ϴ�. ���ο� ������ �����մϴ�.\n"); //��ŷ������ ���ٸ� �����ϰ� ����
        return;
    }

    int i = 0;
    while (fscanf(Rank, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        Ranking[i].name, &Ranking[i].score, &Ranking[i].coins,
        &Ranking[i].color[0].r, &Ranking[i].color[0].g, &Ranking[i].color[0].b,
        &Ranking[i].color[1].r, &Ranking[i].color[1].g, &Ranking[i].color[1].b,
        &Ranking[i].color[2].r, &Ranking[i].color[2].g, &Ranking[i].color[2].b,
        &Ranking[i].color[3].r, &Ranking[i].color[3].g, &Ranking[i].color[3].b) != EOF) {
        i++;
        if (i >= RANKING) break; // �迭 �ʰ� ����
    }
    fclose(Rank);
}

//����� ����ϴ� �Լ�
void Play_bgm(const char* filename, bool loop)
{
    int filenameLength = strlen(filename) + 1;
    int bufferSize = MultiByteToWideChar(CP_UTF8, 0, filename, filenameLength, NULL, 0);
    TCHAR* wideFilename = (TCHAR*)malloc(bufferSize * sizeof(TCHAR));
    MultiByteToWideChar(CP_UTF8, 0, filename, filenameLength, wideFilename, bufferSize);
    PlaySound(NULL, NULL, 0);
    if (loop == 1) //�ݺ�����ϴ� ���
        PlaySound(wideFilename, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    else //�� ���� ����ϴ� ���
        PlaySound(wideFilename, NULL, SND_FILENAME | SND_ASYNC);
    free(wideFilename);
}

//�ݺ������ ����� ������ �Լ�
void Stop_bgm()
{
    PlaySound(NULL, NULL, 0);
}

//�̹����� �о� �ҷ����� �Լ�
void ReadImage(const char* filePath, unsigned char** image)
{
    FILE* fp = fopen(filePath, "rb");
    fread(*image, 1, 256 * 256, fp);
    fclose(fp);
}

//256x256 ũ���� �̹����� �׸��� �Լ�
void Draw_image_256(const char* filePath, HDC hdc, int offsetX, int offsetY)
{
    //�� �޸𸮿� �̹��� �迭 �Ҵ�
    unsigned char* image = (unsigned char*)malloc(256 * 256 * sizeof(unsigned char));
    if (image == NULL) return;
    ReadImage(filePath, &image); //�̹��� ������ �о��
    //�̹����� �״�� ���
    for (int r = 0; r < 256; r++)
    {
        for (int c = 0; c < 256; c++)
        {
            int gray = image[r * 256 + c];
            SetPixel(hdc, c + offsetX, r + offsetY, RGB(gray, gray, gray));
        }
    }
    free(image); //�� �޸� ����
}

//256x256 ũ���� �̹����� 128x128�� ����Ͽ� �׸��� �Լ�
void Draw_image_128(const char* filePath, HDC hdc, int offsetX, int offsetY)
{
    //�� �޸𸮿� �̹��� �迭 �Ҵ�
    unsigned char* image = (unsigned char*)malloc(256 * 256 * sizeof(unsigned char));
    if (image == NULL) return;
    ReadImage(filePath, &image); //�̹��� ������ �о��
    //128x128 ũ���� ��ҵ� �̹��� �迭�� �� �޸𸮿� �Ҵ�
    unsigned char* smallImage = (unsigned char*)malloc(128 * 128 * sizeof(unsigned char));
    if (smallImage == NULL) return;
    //�̹��� ũ�� ���
    for (int r = 0; r < 128; r++)
    {
        for (int c = 0; c < 128; c++)
        {
            int sum = image[2 * r * 256 + 2 * c] +
                image[2 * r * 256 + 2 * c + 1] +
                image[(2 * r + 1) * 256 + 2 * c] +
                image[(2 * r + 1) * 256 + 2 * c + 1];
            smallImage[r * 128 + c] = sum / 4;
        }
    }
    //��ҵ� �̹����� ���
    for (int r = 0; r < 128; r++)
    {
        for (int c = 0; c < 128; c++)
        {
            int gray = smallImage[r * 128 + c];
            SetPixel(hdc, c + offsetX, r + offsetY, RGB(gray, gray, gray));
        }
    }
    free(image); //�� �޸� ����
    free(smallImage);
}