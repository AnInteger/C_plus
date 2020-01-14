#include "FileCompress.h"
#include "HuffmanTree.hpp"
#include <assert.h>

//������ʼ��256��
FileCompress::FileCompress()
{
	_fileInfo.resize(256);

	for (int i = 0; i < 256; i++)
	{
		_fileInfo[i]._ch = i;
		_fileInfo[i]._count = 0;
	}

}

//ѹ���ļ�
void FileCompress::CompressFile(const string& path)
{
	//1��ͳ��Դ�ļ���ÿ���ַ����ֵĴ���
	
	FILE* fIn = fopen(path.c_str(), "r");
	//if (GetFilePostFix(path) == ".txt")
	//{
	//	fIn = fopen(path.c_str(), "r");
	//}
	//else
	//{
	//	fIn = fopen(path.c_str(), "rb");
	//}

	if (nullptr == fIn)
	{
		assert(false);
		return;
	}

	unsigned char* pReadBuff = new unsigned char[1024];
	int rdSize = 0;
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (rdSize == 0)
		{
			break;
		}

		for (int i = 0; i < rdSize; i++)
		{
			_fileInfo[pReadBuff[i]]._count++;
		}
	}

	//2�����ַ����ֵĴ���ΪȨֵ������������
	HuffManTree<CharInfo> t(_fileInfo, CharInfo());


	//3����ȡ����
	GenerateHuffManCode(t.GetProot());

	//4��ʹ�ñ����д
	FILE* fOut = fopen("2.txt", "wb");
	if (nullptr == fOut)
	{
		assert(false);
		return;
	}
	
	//д���ļ�ͷ��Ϣ�����ڽ�ѹ��
	WriteHead(fOut, path);

	fseek(fIn, 0, SEEK_SET);
	char ch = 0;
	int bitcount = 0;
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (rdSize == 0)
		{
			break;
		}

		//�����ֽڱ���Զ�ȡ�������ݽ�����д
		for (size_t i = 0; i < rdSize; i++)
		{
			string strCode = _fileInfo[pReadBuff[i]]._strcode;

			for (size_t j = 0; j < strCode.size(); j++)
			{
				ch <<= 1;
				if ('1' == strCode[j])
				{
					ch |= 1;
				}
				bitcount++;
				if (8 == bitcount)
				{
					fputc(ch, fOut);
					bitcount = 0;
					ch = 0;
				}
			}
		}
	}

	//���һ��ch�п��ܲ���8��bitλ
	if (bitcount < 8)
	{
		ch <<= (8 - bitcount);
		fputc(ch, fOut);
	}

	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

//��ȡ�ļ���׺
string FileCompress::GetFilePostFix(const string& fileName)
{
	return fileName.substr(fileName.rfind('.'));
}

void FileCompress::ReadLine(FILE* fIn, string& strInfo)
{
	assert(fIn);

	while (!feof(fIn))
	{
		char ch = fgetc(fIn);
		if (ch == '\n')
			break;
		strInfo += ch;
	}
}

//��ȡ����������
void FileCompress::GenerateHuffManCode(HuffManTreeNode<CharInfo>* pRoot)
{
	if (nullptr == pRoot)
	{
		return;
	}

	GenerateHuffManCode(pRoot->_pLeft);
	GenerateHuffManCode(pRoot->_pRight);

	if (nullptr == pRoot->_pLeft&&nullptr == pRoot->_pRight)
	{
		string& strCode = _fileInfo[pRoot->_weight._ch]._strcode;
		HuffManTreeNode<CharInfo>* pCur = pRoot;
		HuffManTreeNode<CharInfo>* pParent = pCur->_pParent;

		while (pParent)
		{
			if (pCur == pParent->_pLeft)
			{
				strCode += '0';
			}
			else
			{
				strCode += '1';
			}
			pCur = pParent;
			pParent = pCur->_pParent;
		}
		reverse(strCode.begin(), strCode.end());
		//_fileInfo[pRoot->_weight._ch]._strcode = strCode;
	}
}

//д��ͷ��Ϣ
void FileCompress::WriteHead(FILE* fOut, const string& fileName)
{
	assert(fOut);
	//д�ļ��ĺ�׺
	string strHead;
	strHead += GetFilePostFix(fileName);
	strHead += '\n';

	//д����
	size_t lineCount = 0;
	string strChCount;
	char szValue[32] = { 0 };

	for (int i = 0; i <_fileInfo.size(); i++)
	{
		CharInfo& charInfo = _fileInfo[i];
		if (charInfo._count)
		{
			lineCount++;
			strChCount += charInfo._ch;
			strChCount += ':';
			_itoa(charInfo._count, szValue, 10);
			strChCount += szValue;
			strChCount += '\n';
		}
	}
	
	_itoa(lineCount, szValue, 10);
	strHead += szValue;
	strHead += '\n';
	strHead += strChCount;
	fwrite(strHead.c_str(),1,strHead.size(),fOut);
}


//��ѹ��

void FileCompress::UnCompressFile(const string& path)
{
	FILE* fIn = fopen(path.c_str(), "rb");
	if (fIn == nullptr)
	{
		assert(false);
		return;
	}
	
	//�ļ���׺
	string strFilePostFix;
	ReadLine(fIn, strFilePostFix);

	//�ַ���Ϣ��������

	string strCount;
	ReadLine(fIn, strCount);
	int lineCount = atoi(strCount.c_str());

	//�ַ���Ϣ
	for (int i = 0; i < lineCount; i++)
	{
		string strchCount;
		ReadLine(fIn, strchCount);
		//�����ȡ������\n
		if (strchCount.empty())
		{
			strchCount += '\n';
			ReadLine(fIn, strchCount);
		}
		_fileInfo[(unsigned char)strchCount[0]]._count = atoi(strchCount.c_str() + 2);
	}

	//��ԭHuffman��
	HuffManTree<CharInfo> t(_fileInfo, CharInfo());

	FILE* fOut = fopen("3.txt", "w");

	//��ѹ��
	char* pReadBuff = new char[1024];
	char ch = 0;

	//ѹ������
	HuffManTreeNode<CharInfo>* pCur = t.GetProot();
	size_t fileSize = pCur->_weight._count;
	size_t unCount = 0;

	while (true)
	{
		size_t rdSize = fread(pReadBuff,1,1024,fIn);

		if (rdSize == 0)
			break;
		unsigned char tmp = 0x80;
		for (size_t i = 0; i < rdSize; i++)
		{
			if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight)
			{
				//unCount++;
				//fputc(pCur->_weight._ch, fOut);

				if (unCount == fileSize)
					break;

				pCur = t.GetProot();
			}
			//ֻ��Ҫ��һ���ֽ���8��bitλ��������
			ch = pReadBuff[i];
			for (int pos = 0; pos < 8; pos++)
			{
				if (ch&0x80)
				{
					pCur = pCur->_pRight;
				}
				else
				{
					pCur = pCur->_pLeft;
				}
				
				ch <<= 1;

				if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight)
				{
					unCount++;
					fputc(pCur->_weight._ch, fOut);

					if (unCount == fileSize)
						break;

					pCur = t.GetProot();
				}
			}
		}
	}
	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}
