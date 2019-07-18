#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ˳���Ķ�̬�洢
typedef int SLDataType;

typedef struct SeqList
{

	SLDataType* array; // ָ��̬���ٵ�����

	size_t size; // ��Ч���ݸ���

	size_t capacity; // �����ռ�Ĵ�С
}SeqList;
// ������ɾ��Ľӿ�
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);
void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListRemoveAll(SeqList* psl, SLDataType x);
void SeqListRemoveAllN(SeqList* psl, SLDataType x);
void SeqListBubbleSort(SeqList* psl);
int SeqListDiscFind(SeqList* psl, SLDataType x, SLDataType left, SLDataType right);
void SeqListPrint(SeqList* psl);


#endif