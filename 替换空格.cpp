class Solution {
public:
	string replaceSpace(string s) {
		//存储结果
		string array;

		//遍历字符数组
		for (auto &c : s)
		{
			if (c == ' ')
			{
				//找到空格就插入对应的字符串
				array.push_back('%');
				array.push_back('2');
				array.push_back('0');
			}
			else
			{
				//否则就插入原本的字符
				array.push_back(c);
			}
		}
		return array;
	}
};