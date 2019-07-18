#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 顺序表的动态存储
typedef int SLDataType;

typedef struct SeqList
{

	SLDataType* array; // 指向动态开辟的数组

	size_t size; // 有效数据个数

	size_t capacity; // 容量空间的大小
}SeqList;
// 基本增删查改接口
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