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
		CHECK_THROWS_WITH(stack.Pop(), "Error. Empty stack.\n");

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
				stack.Pop();
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

			WHEN("use constructors and operators")
			{
				THEN("use copy constructor")
				{
					CMyStack<int> copy(stack);
					
					while (!stack.IsEmpty())
					{
						CHECK(stack.GetTop() == copy.GetTop());
						stack.Pop();
						copy.Pop();
					}
				}
				AND_THEN("use assignment operator =")
				{
					CMyStack<int> copy = stack;

					CHECK_FALSE(stack.IsEmpty());

					while (!stack.IsEmpty())
					{
						CHECK(stack.GetTop() == copy.GetTop());
						stack.Pop();
						copy.Pop();
					}
				}
				AND_THEN("use move constructor")
				{
					CMyStack<int> copy = stack;
					CMyStack<int> other(move(stack));

					CHECK(stack.IsEmpty());

					while (!copy.IsEmpty())
					{
						CHECK(other.GetTop() == copy.GetTop());
						other.Pop();
						copy.Pop();
					}
				}
				AND_THEN("use move operator =")
				{
					CMyStack<int> copy = stack;
					CMyStack<int> other = move(stack);
					
					CHECK(stack.IsEmpty());

					while (!copy.IsEmpty())
					{
						CHECK(other.GetTop() == copy.GetTop());
						other.Pop();
						copy.Pop();
					}
				}
			}
			AND_WHEN("use methods")
			{
				THEN("get top element")
				{
					CHECK(stack.GetTop() == 3);
				}
				AND_THEN("pop element")
				{
					stack.Pop();
					CHECK(stack.GetTop() == 2);
				}
				AND_THEN("clear not empty stack")
				{
					CHECK_FALSE(stack.IsEmpty());
					stack.Clear();
					CHECK(stack.IsEmpty());
				}
			}
		}
	}

	GIVEN("empty stack of string")
	{
		CMyStack<string> stack;
		CHECK(stack.IsEmpty());
		CHECK_THROWS_WITH(stack.GetTop(), "Error. Empty stack.\n");
		CHECK_THROWS_WITH(stack.Pop(), "Error. Empty stack.\n");

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
				stack.Pop();
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

			WHEN("use constructors and operators")
			{
				THEN("use copy constructor")
				{
					CMyStack<string> copy(stack);

					while (!stack.IsEmpty())
					{
						CHECK(stack.GetTop() == copy.GetTop());
						stack.Pop();
						copy.Pop();
					}
				}
				AND_THEN("use assignment operator =")
				{
					CMyStack<string> copy = stack;

					while (!stack.IsEmpty())
					{
						CHECK(stack.GetTop() == copy.GetTop());
						stack.Pop();
						copy.Pop();
					}
				}
				AND_THEN("use move constructor")
				{
					CMyStack<string> copy = stack;
					CMyStack<string> other(move(stack));

					CHECK(stack.IsEmpty());

					while (!copy.IsEmpty())
					{
						CHECK(other.GetTop() == copy.GetTop());
						other.Pop();
						copy.Pop();
					}
				}
				AND_THEN("use move operator =")
				{
					CHECK_FALSE(stack.IsEmpty());
					CMyStack<string> copy = stack;
					CMyStack<string> other = move(stack);

					CHECK(stack.IsEmpty());					

					while (!copy.IsEmpty())
					{
						CHECK(other.GetTop() == copy.GetTop());
						other.Pop();
						copy.Pop();
					}
				}
			}
			AND_WHEN("use methods")
			{
				THEN("get top element")
				{
					CHECK(stack.GetTop() == "world");
				}
				AND_THEN("pop element")
				{
					stack.Pop();
					CHECK(stack.GetTop() == "my");
				}
				AND_THEN("clear not empty stack")
				{
					CHECK_FALSE(stack.IsEmpty());
					stack.Clear();
					CHECK(stack.IsEmpty());
				}
			}
		}
	}
}
