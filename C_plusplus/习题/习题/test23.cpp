//24951 - �����Ʋ���
//������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ, ���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
//
//����������int n��int m��ͬʱ����int j��int i�����������������뷵�ز������������֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i - j + 1��


class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		vector<int> vi;
		int ret = 0;
		for (int k = n; k; k /= 2)
		{
			vi.push_back(k % 2);
		}
		for (int k = m; k&&j <= i; k /= 2)
		{
			vi[j] = k % 2;
			j++;
		}
		for (int k = 0; k<vi.size(); k++)
		{
			ret += vi[k] * pow(2, k);
		}
		return ret;
	}
};