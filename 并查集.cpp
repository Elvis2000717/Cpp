#include <iostream>
#include <vector>
using namespace std;

class UnionFindSet
{
	UnionFindSet(int n)
	{
		//���ռ仹���ʼ��
		_v.resize(n, -1);
	}

	int FindRoot(int x)
	{
		while (_v[x] >= 0)
		{
			x = _v[x];
		}
		return x;
	}

	bool Union(int x1, int x2)
	{
		int index1 = FindRoot(x1);
		int index2 = FindRoot(x2);

		//�������ͬ�ĸ�
		if (index1 != index2)
		{
			return false;
		}
		_v[index1] += _v[index2];
		_v[index2] = index1;
		return true;
	}
private:
	vector<int> _v;
};

int main()
{
	return 0;
}