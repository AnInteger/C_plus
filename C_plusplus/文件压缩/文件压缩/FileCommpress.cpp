#include "FileCompress.h"
#include "HuffmanTree.hpp"
#include <assert.h>

FileCompress::FileCompress()
{
	_fileInfo.resize(256);

	for (int i = 0; i < 256; i++)
	{
		_fileInfo[i]._ch = i;
		_fileInfo[i]._count = 0;
	}

}

void FileCompress::CompressFile(const string& path)
{
	//1��ͳ��Դ�ļ���ÿ���ַ����ֵĴ���
	FILE* fIn = fopen(path.c_str(), "r");
		if (nullptr == fIn)
		{
			assert(false);
			return;
		}

		char *pReadBuff = new char[1024];
		int rdSize = 0;
		while (true)
		{
			rdSize=fread(pReadBuff, 1, 1024, fIn);
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
		HuffManTree<CharInfo> t(_fileInfo,CharInfo());

	//3����ȡ����
		//GenerateHuffManCode(t);

	//4��ʹ�ñ����д
		delete[] pReadBuff;
		fclose(fIn);
}

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
		string strCode;
		Node *pCur = pRoot;
		Node* pParent = pCur->_pParent;
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
		_fileInfo[pRoot->_weight._ch] = strCode;
	}
}