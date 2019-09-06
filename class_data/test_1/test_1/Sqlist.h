#ifndef _SQLIST_C_

#define _SQLIST_C_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

typedef int SLDataType;

typedef struct SeqList{
	SLDataType *array;
	SLDataType length;
}SeqList;

void InitList(SeqList *psl);//��ʼ�����Ա�
void ShowList(SeqList *psl);//������Ա�
SLDataType ListEmpty(SeqList psl);//�ж����Ա��Ƿ�Ϊ��
SLDataType GetELem(SeqList psl, SLDataType i);//��ȡ���Ա��еĵ�i��Ԫ��
SLDataType LocateElem(SeqList psl, SLDataType e);//������ֵΪe��Ԫ��
void ListInsert(SeqList *psl, SLDataType i, SLDataType e);//�ڵ�i��Ԫ�غ������ֵΪe��Ԫ��
void ListDelete(SeqList *psl, SLDataType i);//ɾ�����Ա��еĵ�i��Ԫ��
void MergeList(SeqList *psl, SeqList *psl2);//�ϲ������������Ա�Ϊ��������
#endif /*_SQLIST_C_*/
