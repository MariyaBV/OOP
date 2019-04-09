#include "pch.h"
#include "../TV/AdditionalFunction.h"
#include "../TV/CTVSet.h"

using namespace std;

TEST_CASE("function ParsingNumberAndString tests")
{
	//пустой входной файл
	string inputString1;
	pair<int, string> outputPair1;

	outputPair1 = ParsingNumberAndString(inputString1);
	CHECK(outputPair1.first == 0);
	CHECK(outputPair1.second == "");

	//номер канала присутствует в названии канала
	string inputString2 = " 2  24  vokrug sveta   ";
	pair<int, string> outputPair2;

	outputPair2 = ParsingNumberAndString(inputString2);
	CHECK(outputPair2.first == 2);
	CHECK(outputPair2.second == "24 vokrug sveta");

	//подается только номер канала
	string inputString3 = "10";
	pair<int, string> outputPair3;

	outputPair3 = ParsingNumberAndString(inputString3);
	CHECK(outputPair3.first == 10);
	CHECK(outputPair3.second == "");

	//подается только название канала
	string inputString4 = "  vokrug    sveta   ";
	pair<int, string> outputPair4;

	outputPair4 = ParsingNumberAndString(inputString4);
	CHECK(outputPair4.first == 0);
	CHECK(outputPair4.second == "vokrug sveta");

	string inputString5 = "  vokrug    sveta  125 ";
	pair<int, string> outputPair5;

	outputPair5 = ParsingNumberAndString(inputString5);
	CHECK(outputPair5.first == 0);
	CHECK(outputPair5.second == "vokrug sveta 125");
}

SCENARIO("Turn on and turn off TV", "[tvset]")
{
	GIVEN("Turn on and turn off TV")
	{
		CTVSet tv;

		REQUIRE(!tv.IsTurnedOn());

		WHEN("user enters TurnOn command to TurnOff tv")
		{
			tv.TurnOn();
			CHECK(tv.IsTurnedOn());
		}

		tv.TurnOn();
		AND_WHEN("user enters TurnOff command to TurnOn tv")
		{
			tv.TurnOff();
			CHECK_FALSE(tv.IsTurnedOn());
		}
	}
}

SCENARIO("get channel number TV", "[tvset]")
{
	GIVEN("Turn off and turn on TV")
	{
		CTVSet tv;

		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK(tv.GetChannelNumber() == 0);
		}

		tv.TurnOn();

		WHEN("turn on TV")
		{
			CHECK(tv.GetChannelNumber() == 1);
		}
	}
}

SCENARIO("select channel by number channel TV", "[tvset]")
{
	GIVEN("Turn off TV")
	{
		CTVSet tv;

		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.SelectChannel(10));
		}

		tv.TurnOn();

		WHEN("turn on TV")
		{
			THEN("1 <= cnannel <= 99")
			{
				CHECK(tv.SelectChannel(10));
			}
			AND_THEN("cnannel > 99, cnannel < 1")
			{
				CHECK_FALSE(tv.SelectChannel(0));
				CHECK_FALSE(tv.SelectChannel(100));
			}
		}
	}
}

SCENARIO("select previous channel TV", "[tvset]")
{
	GIVEN("Turn off TV")
	{
		CTVSet tv;

		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.SelectPreviousChannel());
		}

		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());
		WHEN("turn on TV")
		{
			THEN("1 turning on")
			{
				CHECK(tv.SelectPreviousChannel());
				CHECK(tv.GetChannelNumber() == 1);
			}
			AND_THEN("turning on 10, then on 15, select previous on 10, select previous on 15")
			{
				tv.SelectChannel(10);
				tv.SelectChannel(15);
				CHECK(tv.SelectPreviousChannel());
				CHECK(tv.GetChannelNumber() == 10);
				CHECK(tv.SelectPreviousChannel());
				CHECK(tv.GetChannelNumber() == 15);
			}
		}
	}
}

SCENARIO("set channel name TV", "[tvset]")
{
	GIVEN("Turn off TV")
	{
		CTVSet tv;
		string ChannelOrt = "ORT";
		string Channel24Kanal = "24 kanal o zhizni";
		vector<string> allChannels;

		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.SetChannelName(1, ChannelOrt));
		}

		tv.TurnOn();

		WHEN("turn on TV")
		{
			THEN("set channel name")
			{
				CHECK(tv.SetChannelName(1, ChannelOrt));
				allChannels = tv.GetAllChannels();
				CHECK(allChannels[0] == ChannelOrt);
			}
			AND_THEN("set channel name with a number and a few words")
			{
				CHECK(tv.SetChannelName(2, Channel24Kanal));
				allChannels = tv.GetAllChannels();
				CHECK(allChannels[1] == Channel24Kanal);
			}
			AND_THEN("set the same channel name")
			{
				CHECK(tv.SetChannelName(11, ChannelOrt));
				allChannels = tv.GetAllChannels();
				CHECK(allChannels[0].empty());
				CHECK(allChannels[10] == ChannelOrt);
			}
			AND_THEN("set 0 and 100 channel")
			{
				CHECK_FALSE(tv.SetChannelName(0, ChannelOrt));
				CHECK_FALSE(tv.SetChannelName(100, ChannelOrt));
			}
		}
	}
}

SCENARIO("get channel name TV by number of channel and by name of channel", "[tvset]")
{
	GIVEN("Turn off TV")
	{
		CTVSet tv;
		string ChannelOrt = "ORT";
		string Channel24Kanal = "24 kanal o zhizni";

		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK(tv.GetChannelName(2) == "");
			CHECK(tv.GetChannelByName(ChannelOrt) == 0);
		}

		tv.TurnOn();

		WHEN("turn on TV")
		{
			THEN("all TV channels without names")
			{
				CHECK(tv.GetChannelName(2) == "");
				CHECK(tv.GetChannelByName(ChannelOrt) == 0);
			}
			AND_THEN("get channel by name and by number of channel")
			{
				CHECK(tv.SetChannelName(11, ChannelOrt));
				CHECK(tv.GetChannelName(11) == ChannelOrt);
				CHECK(tv.GetChannelByName(ChannelOrt) == 11);
			}
			AND_THEN("get channel name with a number and a few words ")
			{
				CHECK(tv.SetChannelName(21, Channel24Kanal));
				CHECK(tv.GetChannelName(21) == Channel24Kanal);
				CHECK(tv.GetChannelByName(Channel24Kanal) == 21);
			}
			AND_THEN("get on 0 and 100 channel")
			{
				CHECK(tv.GetChannelName(0) == "");
				CHECK(tv.GetChannelName(100) == "");
			}
		}
	}
}

SCENARIO("select channel by name channel TV", "[tvset]")
{
	GIVEN("Turn off TV")
	{
		CTVSet tv;
		string ChannelOrt = "ORT";

		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.SelectChannel(ChannelOrt));
		}

		tv.TurnOn();

		WHEN("turn on TV")
		{
			THEN("no name of channel")
			{
				CHECK_FALSE(tv.SelectChannel(ChannelOrt));
			}
			AND_THEN("select channel by name")
			{
				CHECK(tv.SetChannelName(11, ChannelOrt));
				CHECK(tv.SelectChannel(ChannelOrt));
				CHECK(tv.GetChannelNumber() == 11);
			}
		}
	}
}

SCENARIO("delete channel name", "[tvset]")
{
	GIVEN("Turn off TV")
	{
		CTVSet tv;
		string ChannelOrt = "ORT";
		vector<string> allChannels;

		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.DeleteChannelName(ChannelOrt));
		}

		tv.TurnOn();

		WHEN("turn on TV")
		{
			THEN("no name of channel")
			{
				CHECK_FALSE(tv.DeleteChannelName(ChannelOrt));
			}
			AND_THEN("delete channel name")
			{
				CHECK(tv.SetChannelName(11, ChannelOrt));
				allChannels = tv.GetAllChannels();
				CHECK(allChannels[10] == ChannelOrt);
				CHECK(tv.DeleteChannelName(ChannelOrt));
				allChannels = tv.GetAllChannels();
				CHECK(allChannels[10].empty());
			}
		}
	}
}
