#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int> st;
	int T;//������
	int n;//��2n����
	int k;//ϴ���ٴ�
	int num;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> num;
			st.push_back(num);
		}
		vector<int> tmp;
		while (k--)
		{
			for (int j = 0; j < n; j++)
			{
				tmp.push_back(st[j]);
				tmp.push_back(st[j + n]);
			}
			for (int j = 0; j < 2 * n; j++)
			{
				st[j] = tmp[j];
			}
			tmp.clear();
		}
		for (auto e : st)
			cout << e << ' ';
		st.clear();
	}
	return 0;
}