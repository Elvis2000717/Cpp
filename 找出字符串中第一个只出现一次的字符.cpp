#include <iostream>
#include <vector>

using namespace std;
int main()
{
	string st;

	while (getline(cin, st))
	{
		int i;
		for (i = 0; i < st.size(); i++)
		{
			if (st.find(st[i]) == st.rfind(st[i]))
			{
				cout << st[i] << endl;
				break;
			}
		}
		if (i == st.size())
		{
			cout << -1 << endl;
		}
	}
	return 0;
}