#include "Setting.h"
#include "Variable.h"

//이미지 주소를 담을 포인터 변수 선언
typedef const char* Image; //별칭 생성
Image Beer = "Images\\Beer.raw";

//글자의 배경과 글자 색을 지정하는 함수
void Textcolor(int bgcolor, int txcolor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (bgcolor << 4) + txcolor);
}

//이미지 출력 관련 설정 코드, GPT 사용
HWND hwnd; //현재 포그라운드 윈도우의 핸들을 가져옴
HDC hdc; //윈도우의 클라이언트 영역에 대한 디바이스 컨텍스트를 가져옴

//각종 세팅 함수
//https://blockdmask.tistory.com/344
//https://blog.naver.com/ifthe1201/221056588399
void Setting()
{
    //이미지 변수들을 전역 변수로 활용하기 위한 셋팅
    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    //콘솔창 크기와 제목
    system("mode con:cols=150 lines=41");
    system("title Welcome");

    //커서 깜빡거림 제거
    HANDLE hConsole; CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = 0; ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);

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
            fprintf(Rank, "%s %d\n", Ranking[i].name, Ranking[i].score);
        }
    }
    fclose(Rank);
}

//게임 시작시 저장된 랭킹을 불러오는 함수
void Read_ranking()
{
    FILE* Rank = fopen("Ranking.txt", "r");
    if (Rank == NULL) return; //처음 시작이어서 저장된 파일이 없다면 무시하고 진행
    int rank = 0;
    while (fscanf(Rank, "%s %d", Ranking[rank].name, &Ranking[rank].score) != EOF)
    {
        rank++;
    }
    fclose(Rank);
}

//이미지를 정적 배열에 읽어오는 함수
void ReadImage(const char* filePath, unsigned char* image)
{
    FILE* fp = fopen(filePath, "rb"); //이진법으로 파일 오픈
    if (fp == NULL) { return; } //파일이 읽히지 않으면 충돌을 막기 위해 함수 종료
    fread(image, 1, IMAGE_SIZE, fp); //이미지 데이터를 읽음
    fclose(fp);
}

//이미지 출력 함수 잠시 제거
