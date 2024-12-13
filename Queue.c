#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

//오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//큐 초기화 함수
void init_queue(Queue* q)
{
	q->front = q->rear = 0;
}

//큐가 가득찼는지 확인하는 함수
int is_full(Queue* q)
{
	return ((q->rear + 1) % INITIAL_SIZE == q->front);
}

//큐가 비어있는지 확인하는 함수
int is_empty(Queue* q)
{
	return (q->front == q->rear);
}

//큐에 값을 집어넣는 함수
void enqueue(Queue* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % INITIAL_SIZE;
	q->data[q->rear] = item;
}

//큐의 값을 빼오는 함수
element dequeue(Queue* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % INITIAL_SIZE;
	return q->data[q->front];
}
