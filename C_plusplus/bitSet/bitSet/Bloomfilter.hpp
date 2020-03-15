#pragma once
#include "BitSet.hpp"
#include "Comman.h"
template <class K, size_t N, class HF1=StrToInt1
										   , class HF2=StrToInt2
										   , class HF3=StrToInt3
										   , class HF4=StrToInt4
										   , class HF5=StrToInt5>
class BloomFilter
{
public:
	BloomFilter()
		:bst_()
	{}

	void insert(const K& val)
	{
		size_t tmp[5] = { 0 };
		size_t totalBits = N * 5;
		tmp[0] = HF1()(val) % totalBits;
		tmp[1] = HF2()(val) % totalBits;
		tmp[2] = HF3()(val) % totalBits;
		tmp[3] = HF4()(val) % totalBits;
		tmp[4] = HF5()(val) % totalBits;

		for (int i = 0; i < 5; i++)
		{
			bst_.set(tmp[i]);
		}
		size_++;
	}

	bool find(const K& val)
	{
		size_t tmp[5] = { 0 };
		size_t totalBits = N * 5;
		tmp[0] = HF1()(val) % totalBits;
		if (!bst_.test(tmp[0]))
			return false;

		tmp[1] = HF2()(val) % totalBits;
		if (!bst_.test(tmp[0]))
			return false;

		tmp[2] = HF3()(val) % totalBits;
		if (!bst_.test(tmp[0]))
			return false;

		tmp[3] = HF4()(val) % totalBits;
		if (!bst_.test(tmp[0]))
			return false;

		tmp[4] = HF5()(val) % totalBits;
		if (!bst_.test(tmp[0]))
			return false;

		return true;
	}

	size_t size()const
	{
		return size_;
	}

private:
	MBitSet::bitset<N * 5> bst_;
	size_t size_;
};



void TestBloomFilter()
{
	BloomFilter<std::string, 100> bf;
	bf.insert("С��");
	bf.insert("С��");
	bf.insert("С��");
	bf.insert("����");
	bf.insert("ëë");

	cout << bf.size() << endl;
	if (bf.find("����"))
	{
		cout << "���˴���" << endl;
	}
	else
	{
		cout << "���˲�����" << endl;
	}

	if (bf.find("ëë"))
	{
		cout << "ëë����" << endl;
	}
	else
	{
		cout << "ëë������" << endl;
	}
}