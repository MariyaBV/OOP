#include "pch.h"
#include "../TV/AdditionalFunction.h"

using namespace std;

SCENARIO("function ParsingNumberAndString tests")
{
	GIVEN("empty string")
	{
		string inputString1;
		pair<int, string> outputPair1;

		outputPair1 = ParsingNumberAndString(inputString1);
		CHECK(outputPair1.first == 0);
		CHECK(outputPair1.second == "");
	}

	GIVEN("not empty string")
	{
		WHEN("channel number is present in the channel name")
		{
			string inputString2 = " 24  24  vokrug sveta   ";
			pair<int, string> outputPair2;

			outputPair2 = ParsingNumberAndString(inputString2);
			CHECK(outputPair2.first == 24);
			CHECK(outputPair2.second == "24 vokrug sveta");
		}

		WHEN("empty channel name")
		{
			string inputString3 = "10";
			pair<int, string> outputPair3;

			outputPair3 = ParsingNumberAndString(inputString3);
			CHECK(outputPair3.first == 10);
			CHECK(outputPair3.second == "");
		}
		
		WHEN("empty channel number")
		{
			THEN("only chars")
			{
				string inputString4 = "  vokrug    sveta   ";
				pair<int, string> outputPair4;

				outputPair4 = ParsingNumberAndString(inputString4);
				CHECK(outputPair4.first == 0);
				CHECK(outputPair4.second == "vokrug sveta");
			}
			AND_THEN("number is present in the channel name")
			{
				string inputString5 = "  vokrug    sveta  125 ";
				pair<int, string> outputPair5;

				outputPair5 = ParsingNumberAndString(inputString5);
				CHECK(outputPair5.first == 0);
				CHECK(outputPair5.second == "vokrug sveta 125");
			}
		}
	}
}