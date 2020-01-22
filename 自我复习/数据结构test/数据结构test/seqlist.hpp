#pragma once
#include<stdio.h>
#include<stdlib.h>
// ˳���Ķ�̬�洢
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _array; // ָ��̬���ٵ�����
	size_t _size; // ��Ч���ݸ���
	size_t _capicity; // �����ռ�Ĵ�С
}SeqList;

// ������ɾ��Ľӿ�
void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->_array = (SLDataType*)calloc(capacity,sizeof(SLDataType));
	psl->_capicity = capacity;
	psl->_size = 0;
}

void SeqListDestory(SeqList* psl)
{
	if (psl->_capicity==0)
	{
		delete(psl->_array);
		psl->_capicity = NULL;
		psl->_size = 0;
	}
}

void CheckCapacity(SeqList* psl)
{
	if (psl->_size >= psl->_capicity)
	{
		psl->_capicity *= 2;
	}
	psl->_array = (SLDataType*)realloc(psl->_array, psl->_capicity * sizeof(SLDataType));
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);
	psl->_array[psl->_size] = x;
	psl->_size++;
}

void SeqListPopBack(SeqList* psl)
{
	psl->_size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);
	int i;
	for (i = psl->_size - 1; i >= 0; i--)
	{
		psl->_array[i + 1] = psl->_array[i];
	}
	psl->_array[0] = x;
	psl->_size++;
}

void SeqListPopFront(SeqList* psl)
{
	for (int i = 0; i < psl->_size; i++)
	{
		if (psl->_array[i] = psl->_array[i + 1]);
	}
	psl->_size--;
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	for (int i = 0; i < psl->_size; i++)
	{
		if (psl->_array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	CheckCapacity(psl);
	for (int i = psl->_size - 1; i >= pos; i--)
	{
		psl->_array[i + 1] = psl->_array[i];
	}
	psl->_array[pos]=x;
	psl->_size++;
}

void SeqListErase(SeqList* psl, size_t pos)
{
	for (int i = pos; i < psl->_size; i++)
	{
		psl->_array[i] = psl->_array[i + 1];
	}
	psl->_size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)
{
	int i = 0;
	for (i = SeqListFind(psl, x);i < psl->_size; i++)
	{
		psl->_array[i] = psl->_array[i + 1];
	}
	psl->_size--;
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	psl->_array[pos] = x;
}

void SeqListPrint(SeqList* psl)
{
	for (int i = 0; i < psl->_size; i++)
	{
		printf("%d ", psl->_array[i]);
	}
	printf("\n");
}

// ��չ������ʵ��
void SeqListBubbleSort(SeqList* psl)
{
	int tmp = 0;
	for (int i = 0; i < psl->_size - 1; i++)
	{
		for (int j = 0; j < psl->_size -i - 1; j++)
		{
			if (psl->_array[j] > psl->_array[j + 1])
			{
				tmp = psl->_array[j];
				psl->_array[j] = psl->_array[j + 1];
				psl->_array[j + 1] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	int mid = 0;
	int left = 0, right = psl->_size - 1;
	while (left <= right)
	{
		int mid = left + (left + right) / 2;
		if (psl->_array[mid] < x)
		{
			left = mid + 1;
		}
		else if(psl->_array[mid]>x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	int i = 0, gap = 0;
	for (i = 0; i < psl->_size; i++)
	{
		if (psl->_array[i] == x)
		{
			gap++;
		}
		else
		{
			psl->_array[i - gap] = psl->_array[i];
		}
	}
	psl->_size -= gap;
}