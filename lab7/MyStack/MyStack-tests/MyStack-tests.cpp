#include "pch.h"
#include "../MyStack/CMyStack.h"

using namespace std;

SCENARIO("my stack")
{
	GIVEN("empty stack of int")
	{
		CMyStack<int> stack;
		CHECK(stack.IsEmpty());
		CHECK_THROWS_WITH(stack.GetTop(), "Error. Empty stack.\n");


		WHEN("push element")
		{
			stack.Push(1);
			CHECK_FALSE(stack.IsEmpty());

			THEN("get top element")
			{
				CHECK(stack.GetTop() == 1);
			}
			AND_THEN("pop element")
			{
				CHECK(stack.Pop() == 1);
				CHECK_THROWS_WITH(stack.GetTop(), "Error. Empty stack.\n");
				CHECK(stack.IsEmpty());
			}
		}

		WHEN("push some elements")
		{
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);
			CHECK_FALSE(stack.IsEmpty());

			THEN("get top element")
			{
				CHECK(stack.GetTop() == 3);
			}
			AND_THEN("pop element")
			{
				CHECK(stack.Pop() == 3);
				CHECK(stack.GetTop() == 2);
			}
		}
	}

	GIVEN("empty stack of string")
	{
		CMyStack<string> stack;
		CHECK(stack.IsEmpty());
		CHECK_THROWS_WITH(stack.GetTop(), "Error. Empty stack.\n");

		WHEN("push element")
		{
			stack.Push("hello");
			CHECK_FALSE(stack.IsEmpty());

			THEN("get top element")
			{
				CHECK(stack.GetTop() == "hello");
			}
			AND_THEN("pop element")
			{
				CHECK(stack.Pop() == "hello");
				CHECK_THROWS_WITH(stack.GetTop(), "Error. Empty stack.\n");
				CHECK(stack.IsEmpty());
			}
		}

		WHEN("push some elements")
		{
			stack.Push("hello");
			stack.Push("my");
			stack.Push("world");
			CHECK_FALSE(stack.IsEmpty());

			THEN("get top element")
			{
				CHECK(stack.GetTop() == "world");
			}
			AND_THEN("pop element")
			{
				CHECK(stack.Pop() == "world");
				CHECK(stack.GetTop() == "my");
			}
		}
	}
}
