//58539-��������
//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3

#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (int i = 0; i < size; i++)
	{
		cin >> nums[i];
	}
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2>result)
		{
			result = sum2;
		}
		if (sum2 < 0)
		{
			sum2 = 0;
		}
		sum1 = sum2;
	}
	cout << result << endl;
	return 0;
}
