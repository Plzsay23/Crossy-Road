#include "Setting.h"
#include "Variable.h"
#include <mmsystem.h> //브금
#pragma comment(lib,"winmm.lib") //브금

//이미지 주소를 담을 포인터 변수 선언
typedef const char* Image; //별칭 생성
Image Beer = "Images\\Beer.raw";

//글자의 배경과 글자 색을 지정하는 함수
void Textcolor(int bgcolor, int txcolor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (bgcolor << 4) + txcolor);
}

//각종 세팅 함수
//https://blockdmask.tistory.com/344
//https://blog.naver.com/ifthe1201/221056588399
void Setting()
{
    //이미지 변수들을 전역 변수로 활용하기 위한 셋팅
    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    //콘솔창 크기와 제목
    system("mode con: cols=150 lines=41");
    system("title Welcome");

    //커서 깜빡거림 제거
    HANDLE hConsole; CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = 0; ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);

    //콘솔창 해상도 임의 변경
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    //화면 해상도가 맞지 않으면 임의로 조정가능
    int x = 1215;
    int y = 695;
    MoveWindow(console, r.left, r.top, x, y, TRUE);

    //외부 파일에 저장된 랭킹 불러오기
    Read_ranking();
}

//커서 위치 이동
//https://blog.naver.com/ifthe1201/221056588399
void gotoxy(int x, int y)
{
    COORD pos = { x,y }; //windows 헤더파일에 선언된 x,y 좌표를 저장하는 구조체
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//랭킹 정렬
void Ranking_sort()
{
    User user; //게임 종료 후 이름과 점수를 저장할 구조체 선언
    user.score = Score; //그 구조체에 점수 인풋
    user.coins = Coins; //코인 인풋
    strcpy(user.name, Name); //이름 인풋

    int found = 0; //중복된 이름이 있는지 여부를 저장하는 변수

    //중복된 이름을 찾아서 점수 갱신
    for (int i = 0; i < RANKING; i++) {
        if (strcmp(user.name, Ranking[i].name) == 0) {
            //이름이 이미 존재하는 경우 점수, 코인 갱신
            if(user.score > Ranking[i].score) //새로 얻은 점수가 더 클 때만 갱신
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

    //중복된 이름이 없었던 경우, 랭킹 배열에 새로운 사용자 추가
    if (!found) {
        for (int i = 0; i < RANKING; i++) {
            if (user.score > Ranking[i].score ||
                (user.score == Ranking[i].score && strcmp(user.name, Ranking[i].name) < 0)) {
                // 점수가 같다면 알파벳 순으로 정렬
                for (int j = RANKING - 1; j > i; j--) {
                    Ranking[j] = Ranking[j - 1];
                }
                Ranking[i] = user;
                break;
            }
        }
    }

    //랭킹 외부 파일에 저장
    FILE* Rank = fopen("Ranking.txt", "w");

    for (int i = 0; i < RANKING; i++)
    {
        if (Ranking[i].score > 0)
        {
            fprintf(Rank, "%s %d %d\n", Ranking[i].name, Ranking[i].score, Ranking[i].coins);
        }
    }
    fclose(Rank);
}

//게임 시작시 저장된 랭킹을 불러오는 함수
void Read_ranking()
{
    FILE* Rank = fopen("Ranking.txt", "r");
    if (Rank == NULL) return; //처음 시작이어서 저장된 파일이 없다면 무시하고 진행
    int i = 0;
    while (fscanf(Rank, "%s %d %d", Ranking[i].name, &Ranking[i].score, &Ranking[i].coins) != EOF) i++;
    fclose(Rank);
}

//브금을 재생하는 함수
void Play_bgm(const char* filename, bool loop)
{
    int filenameLength = strlen(filename) + 1;
    int bufferSize = MultiByteToWideChar(CP_UTF8, 0, filename, filenameLength, NULL, 0);
    TCHAR* wideFilename = (TCHAR*)malloc(bufferSize * sizeof(TCHAR));
    MultiByteToWideChar(CP_UTF8, 0, filename, filenameLength, wideFilename, bufferSize);
    PlaySound(NULL, NULL, 0);
    if (loop == 1) //반복재생하는 경우
        PlaySound(wideFilename, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    else //한 번만 재생하는 경우
        PlaySound(wideFilename, NULL, SND_FILENAME | SND_ASYNC);
    free(wideFilename);
}

//반복재생된 브금을 끝내는 함수
void Stop_bgm()
{
    PlaySound(NULL, NULL, 0);
}

//이미지를 읽어 불러오는 함수
void ReadImage(const char* filePath, unsigned char** image)
{
    FILE* fp = fopen(filePath, "rb");
    fread(*image, 1, 256 * 256, fp);
    fclose(fp);
}

//256x256 크기의 이미지를 그리는 함수
void Draw_image_256(const char* filePath, HDC hdc, int offsetX, int offsetY)
{
    //힙 메모리에 이미지 배열 할당
    unsigned char* image = (unsigned char*)malloc(256 * 256 * sizeof(unsigned char));
    if (image == NULL) return;
    ReadImage(filePath, &image); //이미지 파일을 읽어옴
    //이미지를 그대로 출력
    for (int r = 0; r < 256; r++)
    {
        for (int c = 0; c < 256; c++)
        {
            int gray = image[r * 256 + c];
            SetPixel(hdc, c + offsetX, r + offsetY, RGB(gray, gray, gray));
        }
    }
    free(image); //힙 메모리 해제
}

//256x256 크기의 이미지를 128x128로 축소하여 그리는 함수
void Draw_image_128(const char* filePath, HDC hdc, int offsetX, int offsetY)
{
    //힙 메모리에 이미지 배열 할당
    unsigned char* image = (unsigned char*)malloc(256 * 256 * sizeof(unsigned char));
    if (image == NULL) return;
    ReadImage(filePath, &image); //이미지 파일을 읽어옴
    //128x128 크기의 축소된 이미지 배열을 힙 메모리에 할당
    unsigned char* smallImage = (unsigned char*)malloc(128 * 128 * sizeof(unsigned char));
    if (smallImage == NULL) return;
    //이미지 크기 축소
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
    //축소된 이미지를 출력
    for (int r = 0; r < 128; r++)
    {
        for (int c = 0; c < 128; c++)
        {
            int gray = smallImage[r * 128 + c];
            SetPixel(hdc, c + offsetX, r + offsetY, RGB(gray, gray, gray));
        }
    }
    free(image); //힙 메모리 해제
    free(smallImage);
}
