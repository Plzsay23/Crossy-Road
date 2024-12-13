#ifndef QUEUE_H  // ��� ����
#define QUEUE_H

#include "Variable.h"
#include "Setting.h"
#include "Screen.h"
#include "Object.h"
#include "Game.h"

#define INITIAL_SIZE 10 //ť�� �ʱ� ũ��

//ť�� �� �� int�� ����
typedef int element;

//ť ����ü ����
typedef struct {
	int front;		//ť�� �Ա�
	int rear;		//ť�� �ⱸ
	element data[INITIAL_SIZE];	//�� ������
} Queue;

//���� �Լ�
void error(char* message); 

//ť �ʱ�ȭ �Լ�
void init_queue(Queue* q);

//ť�� ����á���� Ȯ���ϴ� �Լ�
int is_full(Queue* q);

//ť�� ����ִ��� Ȯ���ϴ� �Լ�
int is_empty(Queue* q);

//ť�� ���� ����ִ� �Լ�
void enqueue(Queue* q, element item);

//ť�� ���� ������ �Լ�
element dequeue(Queue* q);

#endif