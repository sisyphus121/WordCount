
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
	//���ԭ��
	void output()
	{
		cout << "ԭ�ģ�" << endl;
		cout << str << endl;
	}
	//ͳ���ַ���
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
		cout << endl << "�ַ�������" << sum << endl;
		//tongji << "�ַ�������" << sum << '\n';
	}
	//���ļ��е��ַ�����һ��string�ַ���
	void getinstr(stringstream& s)
	{
		str = s.str();
	}

	//�ж��ǲ�����Ч����
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

	//�Ѵ�д��ĸת��ΪСд��ĸ
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

	//���ǰʮ����Ƶ�ʻ�
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
		{ // ����ѭ�����ѡ������
			k = i;
			for (j = i + 1; j < n; ++j) {
				if (count1[k] < count1[j]) k = j;
			}
			if (k != i) {
				t = count1[k];
				count1[k] = count1[i];
				count1[i] = t;
				t = count3[i]; // ��������ͬ������
				count3[i] = count3[k];
				count3[k] = t;
			}
		}
		for (k = 0; k < 10; k++) {
			cout << '<' << b[count3[k]] << ">: " << count[count3[k]] << endl;
			//tongji << '<' << b[count3[k]] << ">: " << count[count3[k]] << '\n';
		}
	}


	//��string aת��Ϊ����
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