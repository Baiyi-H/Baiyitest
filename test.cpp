#include "pch.h"
#include "CppUnitTest.h"
#include"D:\VS2017创建库\ConsoleApplication1\ConsoleApplication1\mytest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int n = 6;
			int num[] = { -2,11,-4,13,-5,-2 };
			Assert::AreEqual(MAX(n, num), 20);
		}
		TEST_METHOD(TestMethod2)
		{
			int n = 6;
			int num[] = { -2,-11,-4,-13,-5,-2 };
			Assert::AreEqual(MAX(n, num), 0);
		}
		TEST_METHOD(TestMethod3)
		{
			int n = -1;
			int num[] = { -2,11,-4,13,-5,-2 };
			Assert::AreEqual(MAX(n, num), 0);
		}

	};
}
