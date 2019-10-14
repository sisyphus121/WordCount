#include "pch.h"
#include "CppUnitTest.h"
#include "../wordcount-UnitTest1/word-count.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace wordcountUnitTest1
{
	TEST_CLASS(wordcountUnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int x;
			fstream wordfll("input.txt");
			stringstream sts;
			sts << wordfll.rdbuf();
			word_count text1;
			text1.getinstr(sts);
			x = text1.countzifu();
			Assert::AreEqual(x, text1.countzifu());
		}
	};
}
