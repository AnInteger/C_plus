#include<iostream>
using namespace std;

#include<queue>
#include<vector>
#include<functional>

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