class Solution {
public:
	string replaceSpace(string s) {
		//�洢���
		string array;

		//�����ַ�����
		for (auto &c : s)
		{
			if (c == ' ')
			{
				//�ҵ��ո�Ͳ����Ӧ���ַ���
				array.push_back('%');
				array.push_back('2');
				array.push_back('0');
			}
			else
			{
				//����Ͳ���ԭ�����ַ�
				array.push_back(c);
			}
		}
		return array;
	}
};