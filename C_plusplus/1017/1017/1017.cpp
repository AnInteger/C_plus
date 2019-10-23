#include<iostream>
using namespace std;



#include<queue>
#include<vector>
#include<functional>

#if 0
/*
template<class T,class Container=vector<T>,class Compare=less<typename Container::value_type>>
class priority_queue;
T: �������ȼ������д洢Ԫ�ص�����
Container: ���ȼ�������Ԫ�صĵײ�洢�ṹ��Ĭ��Ϊvector
Compare: ���ȼ���Ԫ�صıȽϹ���Ĭ�ϰ���Less(С��)--->���
*/

int main()
{
	//���ȼ�����Ĭ��������Ǵ��
	priority_queue<int> q1;
	q1.push(4);
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(5);
	cout << q1.size() << endl;
	cout << q1.top() << endl;

	//С��
	//��ʵ����ʱ�����뽫���е�Ԫ�ذ��մ��ڷ�ʽ�Ƚ�----С��

	vector<int> v{ 5, 4, 3, 9, 6, 7, 2, 8, 1, 0 };
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.size() << endl;
	cout << q2.top() << endl;
	q2.pop();
	cout << q2.top() << endl;
	return 0;
}
#endif

#if 0
class Date
{
	friend class Compare;
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)

	{}

private:
	int _year;
	int _month;
	int _day;
};

class Compare
{
public:
	bool operator()(Date* pLeft, Date* pRight)
	{
		if (pLeft->_day < pRight->_day)
		{
			return true;
		}
		return false;
	}
};

#include<queue>

int main()
{
	Date d1(2019, 10, 18);
	Date d2(2019, 10, 16);
	Date d3(2019, 10, 17);
	
#if 0
	//�ȽϷ�ʽ��Ĭ�ϵ�less
	priority_queue<Date> q1;

	//������ȼ������в����Զ������͵�Ԫ�أ�
	//�ڲ���Ԫ���ڼ䣬���ȼ����б������Ԫ�صıȽϣ�less: <  greater: > )
	//�൱����Ҫ�Դ洢���Զ�������Ԫ�ؽ��д��ڻ���С�ڵıȽ�
	//���У� ��������> ���� <�ķ���
	q1.push(d1);
	q1.push(d2);
	q1.push(d3);
#endif
	priority_queue<Date*, vector<Date*>, Compare> q2;
	q2.push(&d1);
	q2.push(&d2);
	q2.push(&d3);
	return 0;
}
#endif