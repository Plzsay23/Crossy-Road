﻿/* 
+ 현재 이미지 함수 너무 길어서 방해되서 지워놨음, 쓸거면 벅샷룰렛에서 알아서 가져오셈
Draw_image_ 함수만 가져오면 되도록 세팅되어 있음
ㄴ 그래서 이미지 함수나 세팅함수나 다 분리해서 헤더파일로 만들어보려고 하는데 생각이 어떠신지
   작업이 매우 편해지는 대신 코드를 주고받는 과정이 조금 불편해짐

메인화면 디자인 - 이미지를 여기다가 써보자
ㄴ 게임 시작 버튼 (마우스로 누르는 버튼을 만들라는게 아님) 0
ㄴ 상점으로 가는 버튼 (나중에 커스터마이징 구현한다면)
ㄴ 게임 설명을 간단하게 들을 수 있는 화면으로 가는 버튼 0
ㄴ 랭킹 화면으로 가는 버튼 0

커스터마이징 & 상점 구현 결정 시 (여유되면)
ㄴ 게임 진행시 코인을 획득하여 수집 후 구매

상점 화면 (결정 된다면)
ㄴ 내 생각은 여러 디자인을 띄워놓고 캐릭터를 상하좌우로 이동하면서 디자인을 고를 수 있도록
   그냥 메이플의 상점 같은게 아니라 RPG의 상점처럼 구현하고 싶음

랭킹 화면 디자인

캐릭터 디자인

자동차 디자인 (현재 위아래 구분없이 막 가는데 위 아래 구분이 되도록)


     __n
    ㅏ ㅓ
    ㅏ-ㅓ
     oYo


    n_m_
    @l  l
    @l__l           
    l/__/


    n_ww_
    @ㅣ ㅣ
    @ㅣ ㅣ
    I/__/



    n_ww_
    @ㅣ ㅣ
     ㅣ ㅣ
     ㅣ ㅣ
    @ㅣ_ㅣ
     I__I


    n_ww_
    @ㅣ ㅣ
     ㅣ ㅣ
    @ㅣ_ㅣ              
     l__l

    n_ww_
    @l   l
     l   l
    @l_ _l
     l__l


     l--l
    @l- -l

     |‾‾|
    @ㅣ‾ㅣ
     ㅣ ㅣ
    @ㅣ ㅣ
    u‾mm‾









몬스터 디자인 (말이 몬스터지 그냥 속도 느린 자동차임)

       mwmwm
      wwmmmww
       wmwwm
       ㅣ ㅣ
       ㅣ ㅣ



        ____
       ㅣ  ㅣ
       ㅣ__ㅣ
        I  I
        I__I

  @ @
 ( o )
  / ＼






+ 캐릭터 & 자동차 디자인은 지금 처럼 3x3 고정인건 아니고 얘네 크기가 커지면 콘솔창 크기를 키우면 되니까 걱정 ㄴ
  대신 너무 크면 안됨

배경 디자인 (국도, 고속도로)
ㄴ 현재 차선도 없이 막 해놓은 상태인데, 차선도 그려넣고 그런 식으로
   꼭 모든 화면을 차선으로만 꽉 채울 필요는 없고 실제 길건너 친구들처럼
   중앙 화단에서 쉬어갈 수 있고 그런 느낌으로
   ㄴ 이 부분은 플로팅과 연관되기 때문에 나중에 같이 ㄱㄱ, 일단 중앙 화단 없이 ㄱㄱ
   ㄴ 배경의 경우 Textcolor( "배경색", "글씨색" ) 으로 색깔 지정이 가능함
      예를 들어 화단을 그릴땐 Textcolor(green, blue) 이런 식으로
      Textcolor함수 색깔 종류는 짬나면 찾아서 추가하겠음

   ++++ 일단 최후의 최후로 미루기

        8차선 도로가 하나 지나가고 중앙 화단 나오고, 4차선 도로가 하나 지나가고 강 나오고
        이런 식으로 도로도 여러개를 만들어서 배경을 여러개의 객체로 만들어서 해보자
        안되면 그냥 그딴거 없이 자동차만 지나다니게 ㄱㄱ

게임오버 구현

점수를 따면 점수를 모아 캐릭터를 커스터마이징 할 수 있게 하는 기능 (여유되면)
ㄴ 유저가 직접 키보드로 디자인 할 수 있게 ex) 3x3 크기로 영역을 고정을 해놓는다든지

자동차도 마찬가지로 커스터마이징 할 수 있으면 좋을 듯

차랑 부딪히면 게임오버 구현 o
ㄴ 좀 더 부드러워야 함 - 현재 캐릭터가 x+1 까지 더미값이 출력되는 상태
ㄴ 캐릭터 디자인을 바꾸면 해결할 수 있음

각 자동차 객체들마다 속도를 달리하고 싶음 - 시발 어케 함 이거
ㄴ 객체 클래스(구조체)에 속도 변수를 추가해보자

헤더파일 분리 o

게임 설명 화면 - 진행중

배경 플로팅
ㄴ 배경 객체 생성 도전 o
ㄴ 자동차가 지나다니는 좌표나 그 간격을 저장해놓고 거기에만 소환해야 할 것 같음 o
ㄴ Add_car 함수에 배경 객체가 생성된 불 함수를 인식해서 진행해야 함

스테이지 고르지 않고 무한으로 이동하도록 구현 - 일단 x좌표 1000까지 확장
ㄴ 플로팅 관련 좌표를 extra_display에 저장하고 있는데 무한으로 간다고 했을때 좌표가 너무 커지는 경우를 조심
ㄴ 배경에서 화단이 일정 주기를 두고 등장하도록 설정 
ㄴ extra_display 값이 커지면 커질 수록 자동차들의 속도를 증가시키고 싶은데 이 부분이 감이 안옴
   ㄴ 페이즈를 여러개로 나눠서 여러개의 함수로 나누고 함수를 자연스럽게 연결시켜보자
ㄴ 좌측으로 역주행시 플로팅이 없도록 해볼까? o

커스터마이징 구현 시
ㄴ 각 캐릭터마다 디자인을 하나의 3차원 배열로 문자열을 저장해서 Draw 함수를 호출할때 캐릭터 넘버를 인자로 받아서
   if문으로 엮어 배열을 출력하는 형태로 변환해야 함 + 더 좋은 방법은 없을까?
   ㄴ 2차원 char 배열과 int 형을 포함하는 구조체로 사용하는게 더 나을 듯 함

아이템 구현 할 거임?
코인은 구현해야 할 듯 o

강 구현 o
ㄴ 강 위의 연꽃잎을 밟아야만 지나갈 수 있는 기믹 ( Y축의 이동을 강제하기 위함)
ㄴ 중앙 화단 등장처럼 플로팅시 랜덤하게 등장하게 구현할 수만 있다면 좋을 듯

랭킹화면에 획득한 커스터마이징 캐릭터들과 코인들도 표현하면 좋을듯
방향키로 순위를 움직이며
ㄴ 구조체로 어떤 캐릭터를 쓰는지, 어떤 캐릭터를 획득했는지, 코인이 몇개인지 저장할 수 있으면 좋을듯
ㄴ 캐릭터 획득은 배열로 저장하고 어떤 캐릭터를 쓰는지는 캐릭터 고유번호로 저장하면 될 듯



할일 : 중앙 화단(?)
       메인화면 이미지 추가, 브금 추가

       헤더파일 주석 추가

       기차 줄지어 나오는 것 까진 구현했으니
       일정 주기를 두고 멈춰있다 지나가고 몇 초 뒤 쫘라락 지워지는 거 구현

       위아래로 움직이는 객체들이 뿅하고 사라지기보단 쑤욱 하고 화면밖으로 나가면서 사라지도록 구현
       Draw_ 함수, Remove_ 함수, Move_ 함수 좌표값 수정해야함
       ㄴ 아래로 들어가는 건 구현함 o
       ㄴ 위로 들어가는 것 구현 필요
       ㄴ 구현 완료 후 생성 좌표 수정

       객체들이 소환되는 주기 사이에 빈 공간을 좀 줄였으면 좋겠다

<구현 목록>

09/11 자동차 객체지향 흉내 성공
09/12 화면 플로팅 구현
09/16 메인화면 구현
09/19 새로하기&이어하기 구현
09/20 코인 구현
09/28 랭킹 완벽 구현
09/29 강 객체 구현
09/29 강 플로팅 완벽 구현
10/04 몬스터 구현
11/11 색상관련 함수 최신화, 업그레이드
11/11 색상커스텀 완벽 구현
11/14 강 플로팅 방식 변경
11/15 색상변경 조건 추가, 5코인 차감 추가
11/18 색상이 코인과 동일하게 유저 이름에 종속되도록 변경
11/20 자동차, 몬스터 객체 상하좌우 화면밖으로 자연스럽게 사라지는 플로팅 구현

<게임 진행 방식>
         -> 1.새로하기 -> 이름 입력(중복 방지) -> 인 게임  -> 랭킹화면 -> 메인화면
         -> 2.이어하기 -> 이름 입력(이름 찾기) -> 인 게임  -> 랭킹화면 -> 메인화면
메인화면 -> 3.색상화면 -> 이름 입력(이름 찾기) -> 색상변경 -> 메인화면
         -> 4.게임설명 -> 메인화면 (사이에 여러 기믹을 소개하는 단계를 추가할 예정, 배경 객체를 완성해야 함)
         -> 5.랭킹화면 -> 메인화면
         
{{{{{{{{{{{{{{{{{{{{   오    류    }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

↓↓↓ (09/12 해결) ↓↓↓
지금 종종 화면이 y가 위로 땡겨지며 잔상이 머무르는 증상이 나타남
y 변수값이 바뀐다기보다는 그냥 콘솔 화면이 한 칸 위로 땡겨지는 것 같음
ㄴ 조금 치명적인 오류인게 gotoxy(0,1); 로 좌표를 변수값이 아닌 고정해놓은 printf도 위로 밀리는걸 보아
   뭔가 콘솔적인 오류인 것 같음
   + 한 번에 너무 많은 객체를 움직이려해서 스택에 과부하가 간 걸 수도 (09/12 이거 아님)
   + extra_display가 움직일때, 즉 좌우 floating 할때만 나타남
   ㄴ 콘솔 화면을 넘어가는 y좌표값에 출력을 해서 화면이 한칸씩 위로 밀린거였음
      ㄴ 이걸 오히려 이용할 수 있는 상황이 생길 수도 있음
ㄴ stage_1에서 Add_car를 할때 객체 번호를 임의로 지정하지 않고 Find_out() 을 쓰도록 바꾸니
   빈도가 눈에 띄게 줄어들었지만 여전히 동일 증상이 나타남
ㄴ (09/12 해결) 별건 아니었고 자동차 객체가 위아래로 움직일때 y의 최대값을 40이 아닌 39로 바꾸어
                콘솔창 밖을 넘어가지 않게 설정함

↓↓↓ (09/19 해결) ↓↓↓
이어하기 과정에서 입력받은 이름과 랭킹에 있는 이름을 비교할때 항상 1의 값이 나옴.
일치해도 0이 아닌 1의 값을 반환함. 구조체의 속성개체와 전역변수 비교가 안되나?
fgets로 입력받은 값을 새로운 변수에 1.for문으로 인덱스 복사를 해도, 2.strcpy를 써서 복사를 해도
뭐가됐든 fgets로 입력받은 값이면 기존의 문자열과 다른 개체로 취급이 됨
ㄴ (09/19 해결) fgets를 쓰면 이유는 모르겠지만 같은 개체가 될 수 없나봄, scanf 사용으로 해결

↓↓↓ (09/24 해결) ↓↓↓
새로하기 & 이어하기 구현은 했지만, 새로하기에서 이름 입력을 두번 받는 상황
+ Start_screen 최적화좀 해야할 것 같음, 너무 복잡함
ㄴ (09/24 해결) 그냥 scanf가 코드상에서 두 번 나오고 있었음

↓↓↓ (09/24 해결) ↓↓↓
코인 객체 생성과정에서 충돌시 획득을 구현하려 하는중, Check_coin 함수에 Delete_coin(i); 을 넣으니
코인이 아예 생성이 안되는 상황이 발생하는 중
Delete_coin()이 없으면 충돌해도 코인이 사라지지 않는 상황
ㄴ (09/24 해결) 아무것도 안건드렸는데 갑자기 존나 잘됨 뭐임

↓↓↓ (09/27 해결) ↓↓↓
랭킹 점수별로 정렬이 안되는 상황
ㄴ (09/27 해결) 동일한 이름이 존재할때 점수를 갱신하고 정렬하는 구문이 없었음

↓↓↓ (09/27 해결) ↓↓↓
화면 가장 아래까지 플레이어가 내려가지를 않는 상황
ㄴ (09/27 해결) y축 한계까지 내려가도록 수정함

↓↓↓ (09/28 해결) ↓↓↓
코인 갯수가 저장이 안 됨
ㄴ (09/28 해결) Read_ranking 함수에서 코인 저장을 안하고 있었음

↓↓↓ (09/30 해결) ↓↓↓
강이 여러개가 소환이 안됨
ㄴ (09/30 해결) 단순 실수, 0을 1로 썼음

↓↓↓ (09/30 해결) ↓↓↓
강과 자동차가 바뀌는 주기가 이상함, rand()값이 고정인가?
ㄴ (09/30 해결) 0~100 비중이 아닌 1~2로 바꿈

↓↓↓ (09/30 해결) ↓↓↓
강과 자동차가 겹치네, 범위 문제인듯
ㄴ (09/30 해결) 강의 소환을 지연시켜 해결함

↓↓↓ (09/30 해결) ↓↓↓
사용자마자 화면이 잘리는 경우가 있음
ㄴ (09/30 해결) 화면 해상도를 임의로 조정하는 부분을 추가함

↓↓↓ (09/30 해결) ↓↓↓
코인이 생성되니 화면이 이상해짐, 일단 코인 생성 주석처리함
ㄴ 이 오류는 아래 오류를 해결함과 동시에 사라짐

↓↓↓ (09/30 해결) ↓↓↓
화면이 위로 들리는 오류가 있음, 이거 보통 150x41의 화면 밖을 벗어나 printf 하려하면 나타나는 오류인데
이거는 내가 확실히 다 잡아놨다 생각했는데 오류가 나는 중
ㄴ (09/30 해결) 자동차 디자인을 바꾸며 크기가 커졌고, 기존의 Remove 코드에서 y축 범위가 벗어나고 있었음

새로하기 이후 한 번더 새로하기를 누르면 간헐적으로 그냥 넘어가지는 경우가 있음

↓↓↓ (10/04 해결) ↓↓↓
객체 랜덤 생성시 객체들(자동차, 코인, 강)끼리 겹침
+ 객체의 생성 좌표와 주기를 손봐야 함
ㄴ 조건문에 몇번마다 반복할지 부분에서 extra_display 변수를 받고 있었음, 이 문제는
   객체 생성시에 extra_display가 10의 배수가 아니면 매번 소환하는 객체의 갯수가 달라지는 상황이 발생함
ㄴ (10/04 해결) 객체 생성시 마다 따로 좌표를 저장하는 변수를 새로 만들어 해결함
ㄴ 코인이 강에 겹치는 문제는 여전함 - 코인의 생성좌표가 자동차와 겹치는걸 고려하여 자동차의 x좌표 -3임
   이 때문에 강과 겹치는 현상이 발생함 (객체 생성 범위 조정으로 해결)

↓↓↓ (11/14 해결) ↓↓↓
게임설명화면에서 강 객체를 그린뒤 잔상이 남음
ㄴ Draw_river 함수 자체의 오류로 판명
ㄴ 인게임에서는 같은 오류가 발생하지 않음, 단순히 설명화면만의 오류
ㄴ 색상 함수를 바꾸기 전에는 나지 않았던 오류임
ㄴ (11/14 해결) 오류 원인못참음, Draw_river 사용하지 않고 직접 그려서 해결

↓↓↓ (11/14 해결) ↓↓↓
강이 소환이 안됨 - 진짜 나를 미치게 만드는구나 tlqkf
ㄴ Game()함수의 switch-case 문에서 1이 들어가는 경우는 되는데 2가 들어가면 강 뿐이 아니라 다 작동을 안함
ㄴ (11/14 해결) switch-case 문 안의 case 4: 를 주석처리해놨더니 작동을 안했음 이유는 모름

↓↓↓ (11/15 해결) ↓↓↓
강 플로팅이 메모리를 많이 먹어 느려지기 때문에 강의 끝쪽만 잘라서 이어붙이는 느낌으로 플로팅해도 될 듯
ㄴ 강 소환시에 줄이 지나가는 문제 (x = 141)
    ㄴ (11/15 해결) 강의 우측 한 줄을 지울때 범위를 넘어가고 있었음
ㄴ 객체 제거시에 잔상이 남는 문제
    ㄴ (11/14 해결) 범위를 넘어가면 강 객체를 지우는 if문 뒤로 플로팅 부분을 else로 엮어 해결

↓↓↓ (11/18 해결) ↓↓↓
몬스터의 잔상이 남는 오류가 있음
ㄴ (11/18 해결) 몬스터를 그리고 지우는 함수에서 범위를 재조정하여 해결

↓↓↓ (11/18 해결) ↓↓↓
강 객체의 플로팅을 건드린 이후로 다시 화면이 위로 들리는 오류가 간간히 발생
어딘가에서 150x41 의 범위를 넘어가 printf를 하는 듯 함
ㄴ (????) 위에 강 소환시 줄이 지나가는 문제를 해결하며 범위를 벗어나는 것을 해결한 것으로 추정
ㄴ (11/18 해결) Game()함수에서 처음 화면을 채우기 위해 자동차를 소환하는 범위가 y축을 넘어가고 있었음
    ㄴ y축 범위를 rand() % 39 + 1 에서 rand() % 36 + 1로 변경하여 범위를 벗어나지 않게 함

색상 커스텀에서 색상변경 후 다시 색상변경을 시도하면 RED에 값이 남아있음
기존의 모든 값이 남아서 방향키로 바꿔지는데 뭐임
ㄴ r,g,b 지역변수의 초깃값을 0으로 바꿔 잔상이 남는 것은 해결하였으나
   방향키를 누르면 이전의 값이 다시 출력이 되는 상황 (알 수 없음)

↓↓↓ (11/18 해결) ↓↓↓
기차 관련 오류
ㄴ 기차 배열의 크기를 아무리 크게 해도 exit(1)에 걸리는 상황 발생
    ㄴ 아무래도 기차가 움직이면서 객체가 수없이 많이 생성되고 있는 듯 함
    ㄴ (11/18 해결) 이는 구조를 바꿔서 해결함
ㄴ 기차를 범위를 벗어나지 않는 선에서 그려도 자꾸만 화면이 들리는 오류가 있음
   범위를 벗어나는건지, 그렇지 않고 다른 이유에서 오류가 나는건지 파악이 안되는 중
    ㄴ (11/18 해결) 기차 이미지를 지우는 함수의 범위가 화면을 벗어나고 있었음
                    x_range, y_range 변수를 추가해 해결

플로팅 관련 오류
ㄴ 자동차의 좌우 부드러운 플로팅 구현중 x 124~125, y 13 과 x 124~125 15 와 x 125 y 16~17 부분이 비어지는 상황
    ㄴ (11/20 해결) Remove 함수에서 좌우 플로팅 구현을 안해놨었음
ㄴ 몬스터의 좌우 부드러운 플로팅 구현중 좌측으로 사라질때 잔상이 새로 그려지는 중
   위의 비는 부분이 다시 생기는 중
   ㄴ (11/20 해결) x좌표가 0보다 작을 때 else if (x < 0) x_range += x; 이 구문을 추가하지 않았었음

Draw 함수들의 구조를 통일해서 따로 함수로 빼고 싶은데 자동차의 경우 up 변수를 받아야 하는것이 걸림돌
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //이미지 관련
#include <conio.h> //콘솔 관련
#include <time.h> //시간 관련
#include <stdbool.h> //2비트 불 변수

//헤더파일 선언
#include "Variable.h"
#include "Setting.h"
#include "Screen.h"
#include "Object.h"
#include "Game.h"

int main()
{
    Setting(); //세팅함수 호출
    Read_ranking(); //랭킹 불러오기

    Main_screen(); //메인 스크린

    return 0;
}