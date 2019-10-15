#include<iostream>
using namespace std;

// list: ��ͷ���˫��ѭ������

// 1��ʹ��
// 2���˽�ײ�ṹ
// 3��ģ��ʵ��

#include<list>
#include<vector>

void TestList1()
{
	list<int> L1;
	list<int> L2(10, 5);

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> L3(v.begin(), v.end());
	list<int> L4(L3);

	cout << L1.size() << endl;

	// ���õ�������ʽ
	// C++98
	//list<int>::iterator it = L2.begin();
	auto it = L2.begin();
	while (it!=L2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : L3)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << L3.front() << endl;
	cout << L3.back() << endl;

	auto rit = L4.rbegin();
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

}

void TestList2()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	cout << L.size() << endl;

	L.push_front(0);
	cout << L.front() << endl;

	L.pop_front();
	cout << L.front() << endl;

	L.pop_back();
	cout << L.back() << endl;

	auto it = find(L.begin(), L.end(), 2);
	if (it != L.end())
	{
		L.insert(it, 5);
	}

	L.erase(it);

}

bool IsOdd(int data)
{
	if (0 == data % 2)
	{
		return true;
	}
	return false;
}

void TestList3()
{
	list<int> L{ 9, 1, 2, 2, 3, 4, 2 };
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	//ɾ������2
	//L.remove(2);

	//ɾ��L�����е�ż��
	//remove_if:ɾ���������������Ľ��
	//���������Ǹú����Ĳ���
	//�ú�����ʵ��ԭ����ÿ������е�ֵ���ò���������֤�����������ɾ������������㣬ʲô������
	L.remove_if(IsOdd);

}

//ע�⣺ʹ��uniqueʱ���뱣֤�����������
void TestList4()
{
	list<int> L{ 9, 1, 2, 2, 3, 4, 2 };
	L.sort();
	L.unique();
}

//list�еĵ�����ʧЧ-----������ָ��Ľ�㲻����
void TestListIterator()
{
	list<int> L{ 1, 2, 3, 4 };
	auto it = L.begin();

	//erase֮��it��ָ��Ľ���Ѿ���ɾ������
	//it������ʧЧ
	L.erase(it);
	it = L.begin();
	while (it!=L.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	//TestList4();
	TestListIterator();
	return 0;
}

