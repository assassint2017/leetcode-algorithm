// 典型的深度优先搜索，其实并没啥
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
// Memory Usage: 8.9 MB, less than 84.31% of C++ online submissions for Decode String.

class Solution
{
public:
	string decodeString(string input)
	{
		if (input.length() == 0)
			return "";
		else
		{
			int index = 0;
			return getstring(input, index);
		}
	}
private:
	string getstring(const string& input, int& i)
	{
		bool flag = false;
		if (input[i] == '[')
		{
			++i;
			flag = true;
		}

		string res = "";
		while (i < input.length() && ((flag && input[i] != ']') || (flag == false)))
		{
			if (input[i] >= '0' && input[i] <= '9')
			{
				int times = 0;
				while (input[i] >= '0' && input[i] <= '9')
				{
					times *= 10;
					times += input[i++] - '0';
				}
				string temp = getstring(input, i);
				++i;
			
				for (int j = 0; j < times; ++j)
					res += temp;
			}
			else
				res += input[i++];
		}
		return res;
	}
};