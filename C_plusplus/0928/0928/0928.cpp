#include<iostream>
using namespace std;
#include<vector>


#if 0
//vector�ײ�ṹ����̬���͵�˳���
//vector<char>  string

void TestVector1()
{
	//(constructor)

	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(v2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	
	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	//��������ַ�ʽ
	//˳�����
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	//����for
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	//������

	//C++98
	//vector<int>::iterator it = v4.begin();
	auto it1 = v4.begin();
	while (it1 != v4.begin())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	auto it2 = v5.rbegin();
	while (it2!=v5.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}
void TestVector2()
{
	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.erase(v5.begin());
	v5.erase(v5.end() - 1);


	//InputIterator find (InputIterator first, InputIterator last, const T& val);
	auto pos = find(v5.begin(), v5.end(), 5);
	if (pos != v5.end())
	{
		v5.erase(pos);
	}

	v5.clear();
}

void TestVector3()
{
	//��ά
	vector<vector<int>> vv;
	//10*10---->6
	vv.resize(10);
	for (size_t i = 0; i < 10; i++)
	{
		vv[i].resize(10, 6);
	}
}

int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	return 0;
}
#endif


#if 0
//���ݼ��
int main()
{
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; i++)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
	//����ԼΪ1.5*capacity
	return 0;
}
#endif


#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//��������������ָ���һ�����ͣ����Խ�����������Ķ��󵱳���ָ��ķ�ʽ����Ӧ��
	//���ã������û�͸����(�û����Բ���֪���������ĵײ����ݽṹ)���������е�Ԫ��
	
	//void assign(size_type n, const value_type& val);
	//v.assign(20,8);//���¸������и�ֵ
	
	auto it = v.begin();

	v.push_back(1);//���ܻᵼ�µ���ʧЧ
	//ԭ�������ǰ��ЧԪ�ظ���������������β��ʱ��Ҫ����
	//�Ӷ��������·���ռ䣬ԭ�ռ��ͷţ��ʵ�����ʧЧ
	//����ǣ�����ݣ������·���ռ�Ĳ������п���ʹ������ʧЧ

	//�����ʽ��
	//1��������֮�����õ�����
	//2���������¶��������

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}

	cout << endl;
	return 0;
}

#endif

#if 0
//��vector�����е�Ԫ�������
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	
	//��ʽ1
	//v.resize(0);

	//��ʽ2
	//v.clear();

	//��ʽ3
	//v.erase(v.begin(), v.end());

	//��ʽ4
	auto it = v.begin();
	while (it!=v.end())
	{
		it = v.erase(it);
		//eraser�ķ���ֵΪɾ��λ�õĺ�һ��λ��
	}
	cout << v.size() << endl;
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int& ra = v[0];
	ra = 10;
	v.push_back(1);
	//���û�ʧЧ
	//ԭ�����ݣ�ԭ�ռ��ͷţ����Ե�ǰ����ָ����Ѿ�����v
	ra = 100;
	return 0;
}
#endif



