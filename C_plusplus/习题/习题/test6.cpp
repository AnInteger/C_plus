//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
//��������������0��


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		int length = numbers.size() / 2;
		int tmp = 1;
		sort(numbers.begin(), numbers.end());
		auto it = numbers.begin();
		while (it!=numbers.end())
		{
			if (*it == *(it + 1))
			{
				tmp++;
			}
			else
			{
				tmp = 1;
			}
			if (tmp > length)
			{
				return *it;
			}
			it++;
		}
		return 0;
	}
};