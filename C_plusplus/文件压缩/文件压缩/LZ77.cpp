#include "LZ77.h"
#include <iostream>

const USH MIN_LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1;
const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;


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
	USH lookAhead = fread(pWin_, 1, 2 * WSIZE, fIn);

	USH hashAddr = 0;

	//��֤��ʼʱ�������ַ����в���
	for (USH i = 0; i < MIN_MATCH - 1; i++)
	{
		ht_.HashFunc(hashAddr,pWin_[i]);
	}

	//ѹ��
	//ѹ���ļ�
	FILE* fOut = fopen("2.lzp", "wb");
	if (nullptr == fOut)
	{
		std::cout << "Open File Failed!" << std::endl;
		return;
	}

	USH start = 0;
	
	//������ƥ����ر���
	USH matchHead = 0;
	USH curMatchLength = 0;
	USH curMatchDist = 0;

	//������ر���
	UCH chFlag = 0;
	UCH bitCount = 0;
	
	//д��ǵ��ļ�
	FILE* fOutF = fopen("3.txt", "wb");

	//lookHead��ʾ���л�������ʣ���Ԫ��
	while (lookAhead)
	{
		ht_.Insert(matchHead, pWin_[start + 2], start, hashAddr);
		curMatchLength = 0;
		curMatchDist = 0;  
		if (matchHead)
		{
			curMatchLength= LongestMatch(matchHead, curMatchDist,start);
		}
		 //��ԭ�ַ�
		if (curMatchLength < MIN_MATCH)
		{
			fputc(pWin_[start], fOut);
			WriteFlag(fOutF, chFlag, bitCount, false);
			++start;
			lookAhead--;
		}

		//�ǳ��ȶ�
		else
		{
			//д����
			UCH chlen = curMatchLength - 3;
			fputc(chlen, fOut);

			//д����
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, fOut);

			//д���
			WriteFlag(fOutF, chFlag, bitCount, true);

			//�������л�����
			lookAhead -= curMatchLength;
			
			--curMatchLength;
			while (curMatchLength)
			{
				start++;
				ht_.Insert(matchHead, pWin_[start+2], start, hashAddr);
				curMatchLength--;
			}
			start++;
		}
	}
	//���λ������8bit
	if (bitCount > 0 && bitCount < 8)
	{
		chFlag <<= (8 - bitCount);
		fputc(chFlag, fOutF);
	}
	fclose(fIn);
	fclose(fOut);
	fclose(fOutF);
}

USH LZ77::LongestMatch(USH matchHead, USH& MatchDist,USH start)
{
	UCH curMathchLen = 0;//һ��ƥ�䳤��
	UCH maxMatchLen = 0;//���ƥ�䳤��
	UCH maxMatchCount = 255;//����ƥ�����
	USH curMatchStart = 0;//��ǰƥ���ڲ��һ������е���ʼλ��
	
	//��֤���ҷ�Χ�ڲ��һ�������С��
	USH limit = start > MAX_DIST ? start - MAX_DIST : 0;
	do
	{
		//ƥ�䷶Χ
		UCH* pstart = pWin_ + start;
		UCH* pend = pstart + MAX_MATCH;

		//���һ������е�ƥ�䴮��ʼ
		UCH* pMatchStart = pWin_ + matchHead;
		curMathchLen = 0;

		while (pstart < pend&&*pstart == *pMatchStart)
		{
			curMathchLen++;
			pstart++;
			pMatchStart++;
		}

		if (curMathchLen > maxMatchLen)
		{
			maxMatchLen = curMathchLen;
			curMatchStart = matchHead;
		}

	} while ((matchHead = ht_.GetNext(matchHead))> limit&&maxMatchCount--);

	MatchDist = start - curMatchStart;
	return maxMatchLen;
}

void LZ77::UnCompressFile(const std::string& strFilePath)
{
	//��ѹ���ļ��ͱ���ļ�
	FILE* unfIn = fopen("2.lzp", "rb");
	if (nullptr==unfIn)
	{
		std::cout << "Open Compare File Failed!" << std::endl;
		return;
	}

	FILE* unfInF = fopen("3.txt", "rb");
	if (nullptr == unfIn)
	{
		std::cout << "Open UnCompare File Failed!" << std::endl;
		return;
	}

	//��ѹ���ļ�
	FILE* unfOut = fopen("4.txt", "wb");
	if (nullptr == unfIn)
	{
		std::cout << "Open UnCompare File Failed!" << std::endl;
		return;
	}

	//��ԭƥ�䴮
	FILE* fR = fopen("4.txt", "rb");

	UCH bitCount = 0;
	UCH chFlag = 0;
	while (!feof(unfIn))
	{
		if (0 == bitCount)
		{
			chFlag=fgetc(unfInF);
			bitCount = 8;
		}

		if (chFlag & 0x80)
		{
			//���볤�ȶ�
			USH matchLen = fgetc(unfIn) + 3;
			USH matchDist = 0;
			fread(&matchDist, sizeof(matchDist), 1, unfIn);
			
			//��ջ�����
			fflush(unfOut);

			//��λǰ�ĵ�ƥ��λ��
			fseek(fR, 0 - matchDist, SEEK_END);
			UCH ch;
			while (matchLen)
			{
				ch = fgetc(fR);
				fputc(ch, unfOut);
				matchLen--;
			}
		}
		else
		{
			//ԭ�ַ�
			UCH ch = fgetc(unfIn);
			fputc(ch, unfOut);
		}
		chFlag <<= 1;
		bitCount--;
	}
	fclose(unfIn);
	fclose(unfInF);
	fclose(unfOut);
	fclose(fR);
}

void LZ77::WriteFlag(FILE* fOutF, UCH& chFalg, UCH& bitCount, bool isLen)
{
	chFalg <<= 1;
	if (isLen)
	{
		chFalg |= 1;
	}
	bitCount++;
	if (bitCount == 8)
	{
		fputc(chFalg, fOutF);
		chFalg = 0;
		bitCount = 0;
	}
}
