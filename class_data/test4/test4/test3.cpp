#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int Status;
//���Ͷ���
typedef struct
{
	char name[20];//����
	char sex;//�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
}Person;

typedef struct
{
	Person *base;
	int fronter;
	int rear;
}SqQueue;

Status InitQueue(SqQueue & Q)
{
	Q.base = new Person[MAXQSIZE];
	if (!Q.base)
	{
		exit(OVERFLOW);
	}
	Q.fronter = Q.rear = 0;
	return OK;
}

//���
Status EnQueue(SqQueue& Q, Person e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.fronter)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

//����
Status DeQueue(SqQueue& Q, Person& e)
{
	if ((Q.rear + 1) % MAXQSIZE==Q.fronter)
		return ERROR;
	e = Q.base[Q.fronter];
	Q.fronter=(Q.fronter+1)%MAXQSIZE;
	return OK;
}
//�п�
int QueueEmpty(SqQueue Q)
{
	if (Q.rear==Q.fronter)
		return 1;
	else
		return 0;
}

//ȡ��ͷԪ��
Person GetHead(SqQueue Q)
{
	if (Q.fronter != Q.rear)
		return Q.base[Q.fronter];
}

//�������
void DancePartner(Person dancer[], int num)
{
	SqQueue Mdancers, Fdancers;//�ֱ�����ʿ��Ůʿ����߶���
	Person p;
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	for (int i = 0; i < num; i++)
	{
		p = dancer[i];
		if (p.sex == 'F')
			EnQueue(Fdancers, p);//����Ů��
		else
		{
			EnQueue(Mdancers, p);//�����ж�
		}
	}
	cout << "The Dancing partner are:";
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers))
	{
		//���������Ů��������
		DeQueue(Fdancers, p);
		cout << p.name << "  ";
		DeQueue(Mdancers, p);
		cout << p.name << endl;
	}
	if (!QueueEmpty(Fdancers))
	{
		p = GetHead(Fdancers);
		cout << "The first woman to get a partner is:" << p.name << endl;

	}
	else if (!QueueEmpty(Mdancers))
	{
		p = GetHead(Mdancers);
		cout << "The first man to get a partner is:" << p.name << endl;
	}
}
//main����
int main()
{
	Person dancer[5] = { { "a", 'F' }, { "b", 'M' }, { "c", 'M' }, { "d", 'F' }, { "e", 'M' } };
	DancePartner(dancer, 5);
	return 0;
}
