
#include "pch.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class word_count
{
private:
	string str;

public:
	//输出原文
	void output()
	{
		cout << "原文：" << endl;
		cout << str << endl;
	}
	//统计字符数
	int countzifu()
	{
		int i = 0;
		int sum = 0;
		while (str[i] != '\0')
		{
			if (str[i] <= 126 && str[i] >= 32 || str[i] == 10 || str[i] == 13)
				sum++;
			i++;
		}
		return sum;
		cout << endl << "字符个数：" << sum << endl;
		//tongji << "字符个数：" << sum << '\n';
	}
	//将文件中的字符存入一个string字符串
	void getinstr(stringstream& s)
	{
		str = s.str();
	}

	//判断是不是有效单词
	int judgeword(string a)
	{
		int i = a.size(), n;
		if (i < 4)
		{
			return 0;
		}
		for (n = 0; n < 4; n++)
		{
			if (a[n] < 65 || 91 <= a[n] && a[n] < 96 || a[n]>123 && a[n] < 127)
				return 0;
		}
		return 1;
	}

	//把大写字母转化为小写字母
	void turn(string& a)
	{
		int n = 0;
		while (a[n] != '\0')
		{
			if ('A' <= a[n] && a[n] <= 'Z')
				a[n] = a[n] + 32;
			n++;
		}
	}

	//输出前十个高频词汇
	void tenword(string a[500], int n)
	{
		int j, k, p = 0, t = 0, i;
		string b[500];
		int count[500];
		int count1[500];
		int count3[500];
		for (k = 0; k < n; k++)
		{
			count[k] = 1;
			for (j = 0; j < n; j++)
			{
				if (b[j] == a[k])
				{
					count[j]++;
					break;
				}
			}
			if (j == n)
			{
				b[p] = a[k];
				p++;
			}
		}
		for (k = 0; k < n; k++)
		{
			count1[k] = count[k];
			count3[k] = k;
		}

		for (i = 0; i < n - 1; ++i)
		{ // 二重循环完成选择排序
			k = i;
			for (j = i + 1; j < n; ++j) {
				if (count1[k] < count1[j]) k = j;
			}
			if (k != i) {
				t = count1[k];
				count1[k] = count1[i];
				count1[i] = t;
				t = count3[i]; // 辅助数组同步操作
				count3[i] = count3[k];
				count3[k] = t;
			}
		}
		for (k = 0; k < 10; k++) {
			cout << '<' << b[count3[k]] << ">: " << count[count3[k]] << endl;
			//tongji << '<' << b[count3[k]] << ">: " << count[count3[k]] << '\n';
		}
	}


	//把string a转化为单词
	int readword()
	{
		int n = 0;
		int i = 0;
		int j = 0;
		int count = 0;
		string b[500];
		string c[500];
		while (str[i] != '\0')
		{
			if (str[i] != 32 && str[i] != 44 && str[i] != 46)
			{
				b[n] = b[n] + str[i];
				i++;
			}
			else
			{
				n++;
				i++;
			}
		}

		for (j = 0; j < n; j++)
		{
			if (judgeword(b[j]) == 1)
			{
				turn(b[j]);
				c[count] = b[j];
				count++;
			}
		}
		tenword(c, count);
		return  count;
	}

};