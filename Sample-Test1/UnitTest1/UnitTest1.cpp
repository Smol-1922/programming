#include "pch.h"
#include "CppUnitTest.h"
#include "../../Tutu1Lab/Tutu1Lab/list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(push_back_front_test)
		{
			List<int>* list = new List<int>();
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->push_front(4);
			Assert::IsTrue(list->at(4) == 8);
			Assert::IsTrue(list->at(0) == 4);
		}



		TEST_METHOD(pop_back_front_test)
		{
			List<int>* list = new List<int>();
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->push_front(4);
			list->pop_back();
			list->pop_front();
			Assert::IsTrue(list->at(2) == 7);
			Assert::IsTrue(list->at(0) == 5);
		}



		TEST_METHOD(insert_test)
		{
			List<int>* list = new List<int>();
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->insert(9, 2);
			Assert::IsTrue(list->at(2) == 9);
		}



		TEST_METHOD(remove_test)
		{
			List<int>* list = new List<int>();
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->remove(2);
			Assert::IsTrue(list->at(2) == 8);
		}



		TEST_METHOD(clear_test)
		{
			List<int>* list = new List<int>();
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->clear();
			Assert::IsTrue(list->get_size() == 0);
			Assert::IsTrue(list->getHead() == nullptr);
		}



		TEST_METHOD(set_test)
		{
			List<int>* list = new List<int>();
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->set(9, 1);
			Assert::IsTrue(list->at(1) == 9);
		}



		TEST_METHOD(isEmpty_test)
		{
			List<int>* list = new List<int>();
			Assert::IsTrue(list->isEmpty());
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			Assert::IsTrue(!list->isEmpty());
		}



		TEST_METHOD(find_first_test)
		{
			List<int>* list = new List<int>();
			List<int>* list2 = new List<int>();
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);

			list2->push_back(6);
			list2->push_back(7);

			Assert::IsTrue(list->find_first(*list2) == 1);
		}
	};
}
