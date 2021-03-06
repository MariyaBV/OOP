#include "pch.h"
#include "../MyArray/CMyArray.h"

using namespace std;

SCENARIO("my array")
{
	GIVEN("empty array of int")
	{
		CMyArray<int> myArray;

		WHEN("empty array")
		{
			CHECK(myArray.GetSize() == 0);
			CHECK(myArray.GetCapacity() == 0);
		}
		AND_WHEN("append 1 element")
		{
			myArray.Append(2);
			CHECK(myArray.GetSize() == 1);
			CHECK(myArray.GetCapacity() == 1);
		}
		AND_WHEN("append some elements")
		{
			myArray.Append(1);
			myArray.Append(8);
			CHECK(myArray.GetSize() == 2);
			CHECK(myArray.GetCapacity() == 2);
		}
	}

	GIVEN("empty array of double")
	{
		CMyArray<double> myArray;

		WHEN("empty array")
		{
			CHECK(myArray.GetSize() == 0);
			CHECK(myArray.GetCapacity() == 0);
		}
		AND_WHEN("append 1 element")
		{
			myArray.Append(2.58);
			CHECK(myArray.GetSize() == 1);
			CHECK(myArray.GetCapacity() == 1);
		}
		AND_WHEN("append some elements")
		{
			myArray.Append(1.47);
			myArray.Append(8.15);
			CHECK(myArray.GetSize() == 2);
			CHECK(myArray.GetCapacity() == 2);
		}
	}

	GIVEN("empty array of string")
	{
		CMyArray<string> myArray;

		WHEN("empty array")
		{
			CHECK(myArray.GetSize() == 0);
			CHECK(myArray.GetCapacity() == 0);
		}
		AND_WHEN("append 1 element")
		{
			myArray.Append("hello");
			CHECK(myArray.GetSize() == 1);
			CHECK(myArray.GetCapacity() == 1);
		}
		AND_WHEN("append some elements")
		{
			myArray.Append("hello");
			myArray.Append("world");
			CHECK(myArray.GetSize() == 2);
			CHECK(myArray.GetCapacity() == 2);
		}
	}
}