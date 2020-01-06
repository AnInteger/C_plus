#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "HuffmanTree.hpp"
using namespace std;

//�ַ���Ϣ
struct CharInfo
{
	
	unsigned char _ch;//�����ַ���unsigned���ڽ�������ַ�
	size_t _count;		//�ַ�����
	string _strcode;	//�ַ�����

	CharInfo(size_t count = 0)
		:_count(count)
	{}

	CharInfo operator +(const CharInfo& c)
	{
		return CharInfo(_count + c._count);
	}

	bool operator > (const CharInfo& c)const
	{
		return _count > c._count;
	}

	bool operator == (const CharInfo& c)
	{
		return _count == c._count;
	}
};

class FileCompress
{
public:
	FileCompress();
	//ѹ��
	void CompressFile(const string& path);
	//��ѹ��
	void UnCompressFile(const string& path);

private:
	//����������
	void GenerateHuffManCode(HuffManTreeNode<CharInfo>* pRoot);

	//ͷ�ļ���Ϣ
	void WriteHead(FILE* fOut, const string& fileName);

	//��ȡѹ���ļ���׺
	string GetFilePostFix(const string& filename);

	//��ȡһ����Ϣ
	void ReadLine(FILE* fIn, string& strInfo);
private:
	vector<CharInfo> _fileInfo;
};




