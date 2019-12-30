#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct CharInfo
{
	
	char _ch;			//�����ַ�
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
	void CompressFile(const string& path);
	void UnCompressFile(const string& path);

private:
	void GenerateHuffManCode(HuffManTreeNode<CharInfo>* pRoot);
private:
	vector<CharInfo> _fileInfo;
};




