#ifndef QUEUE_H  // 헤더 가드
#define QUEUE_H

#include "Variable.h"
#include "Setting.h"
#include "Screen.h"
#include "Object.h"
#include "Game.h"

#define INITIAL_SIZE 10 //큐의 초기 크기

//큐에 들어갈 값 int로 선언
typedef int element;

//큐 구조체 선언
typedef struct {
	int front;		//큐의 입구
	int rear;		//큐의 출구
	element data[INITIAL_SIZE];	//들어갈 데이터
} Queue;

//오류 함수
void error(char* message); 

//큐 초기화 함수
void init_queue(Queue* q);

//큐가 가득찼는지 확인하는 함수
int is_full(Queue* q);

//큐가 비어있는지 확인하는 함수
int is_empty(Queue* q);

//큐에 값을 집어넣는 함수
void enqueue(Queue* q, element item);

//큐의 값을 빼오는 함수
element dequeue(Queue* q);

#endif