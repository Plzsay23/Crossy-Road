#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

//���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ť �ʱ�ȭ �Լ�
void init_queue(Queue* q)
{
	q->front = q->rear = 0;
}

//ť�� ����á���� Ȯ���ϴ� �Լ�
int is_full(Queue* q)
{
	return ((q->rear + 1) % INITIAL_SIZE == q->front);
}

//ť�� ����ִ��� Ȯ���ϴ� �Լ�
int is_empty(Queue* q)
{
	return (q->front == q->rear);
}

//ť�� ���� ����ִ� �Լ�
void enqueue(Queue* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % INITIAL_SIZE;
	q->data[q->rear] = item;
}

//ť�� ���� ������ �Լ�
element dequeue(Queue* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % INITIAL_SIZE;
	return q->data[q->front];
}
