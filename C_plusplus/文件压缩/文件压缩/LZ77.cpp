#include "LZ77.h"
#include <iostream>
LZ77::LZ77()
	:pWin_(new UCH[WSIZE*2])
	,ht_(WSIZE)
{}

LZ77::~LZ77()
{
	delete[] pWin_;
	pWin_ = nullptr;
}

void LZ77::CompressFile(const std::string& strFilePath)
{
	//�򿪴�ѹ���ļ�
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		std::cout << "Open File Failed!" << std::endl;
		return;
	}

	//��ȡ�ļ���С
	fseek(fIn, 0, SEEK_END);
	ULL fileSize = ftell(fIn);

	//��ѹ���ļ���С����ѹ��
	if (fileSize <= MIN_MATCH)
	{
		std::cout << "FileSize Is Too Little!" << std::endl;
		return;
	}

	//�����ļ�ָ��
	fseek(fIn, 0, SEEK_SET);
	
	//��ȡ������������
	USH lookHead = fread(pWin_, 1, 2 * WSIZE, fIn);

	USH hashAddr = 0;

	//��֤��ʼʱ�������ַ����в���
	for (USH i = 0; i < MIN_MATCH - 1; i++)
	{
		ht_.HashFunc(hashAddr,pWin_[i]);
	}

	//ѹ��
	FILE* fOUT = fopen("2.lzp", "wr");
	if (nullptr == fOUT)
	{
		std::cout << "Open File Failed!" << std::endl;
		return;
	}

	USH start = 0;
	USH matchHead = 0;
	UCH curMatchLength = 0;
	USH curMatchDist = 0;

	//lookHead��ʾ���л�������ʣ���Ԫ��
	while (lookHead)
	{
		ht_.Insert(matchHead, pWin_[start + 2], start, hashAddr);
		if (matchHead)
		{
			curMatchLength= LongestMatch(matchHead, curMatchDist);
		}
		if (curMatchLength < MIN_MATCH)
		{
			++start;
			lookHead--;
		}
		else
		{
			fputc(curMatchLength, fOUT);
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, fOUT);
			//�������л�����
			lookHead -= curMatchLength;
			
			--curMatchLength;
			while (curMatchLength)
			{
				start++;
				ht_.Insert(matchHead, pWin_[start], start, hashAddr);
				curMatchLength--;
			}
		}
	}

}

UCH LZ77::LongestMatch(USH matchHead, USH& curMatchDist)
{
	return 0;
}

void LZ77::UnCompressFile(const std::string& strFilePath)
{
}