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

SCENARIO("get channel number off TV", "[tvset]")
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

SCENARIO("select channel off TV", "[tvset]")
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


//TEST_CASE("SelectPreviousChannel tests")
//{
//	CTVSet tv;
//
//	//начальное состояние выкл ТВ
//	CHECK(tv.SelectPreviousChannel() == false);
//	CHECK(tv.IsTurnedOn() == false);
//	CHECK(tv.GetChannelNumber() == 0);
//
//	//вкл ТВ
//	tv.TurnOn();
//	CHECK(tv.IsTurnedOn() == true);
//	CHECK(tv.SelectChannel(100) == false);
//	CHECK(tv.GetChannelNumber() == 1);
//	CHECK(tv.SelectChannel(0) == false);
//	CHECK(tv.SelectPreviousChannel() == true);
//	CHECK(tv.GetChannelNumber() == 1);
//
//	//переключили канал
//	CHECK(tv.SelectChannel(2) == true);
//	CHECK(tv.GetChannelNumber() == 2);
//	CHECK(tv.SelectPreviousChannel() == true);
//	CHECK(tv.GetChannelNumber() == 1);
//
//	//переключение на предыдущий канал
//	CHECK(tv.SelectChannel(15) == true);
//	CHECK(tv.GetChannelNumber() == 15);
//	CHECK(tv.SelectChannel(10) == true);
//	CHECK(tv.GetChannelNumber() == 10);
//	CHECK(tv.SelectPreviousChannel() == true);
//	CHECK(tv.GetChannelNumber() == 15);
//	CHECK(tv.SelectPreviousChannel() == true);
//	CHECK(tv.GetChannelNumber() == 10);
//	CHECK(tv.SelectChannel(10) == true);
//	CHECK(tv.GetChannelNumber() == 10);
//	CHECK(tv.SelectPreviousChannel() == true);
//	CHECK(tv.GetChannelNumber() == 10);
//
//	//выкл тв
//	tv.TurnOff();
//	CHECK(tv.IsTurnedOn() == false);
//	CHECK(tv.GetChannelNumber() == 0);
//	CHECK(tv.SelectChannel(2) == false);
//	CHECK(tv.SelectPreviousChannel() == false);
//}
//
//TEST_CASE("SetChannelName, GetChannelName, GetChannelByName, DeleteChannelName tests")
//{
//	CTVSet tv;
//
//	//начальное состояние выкл ТВ
//	string ChannelOrt = "ORT";
//
//	CHECK(tv.SetChannelName(1, ChannelOrt) == false);
//	CHECK(tv.IsTurnedOn() == false);
//	CHECK(tv.GetChannelName(1) == "");
//	CHECK(tv.GetChannelByName(ChannelOrt) == 0);
//	CHECK(tv.DeleteChannelName(ChannelOrt) == false);
//	CHECK(tv.SelectChannel(ChannelOrt) == false);
//
//	//вкл ТВ
//	tv.TurnOn();
//	CHECK(tv.IsTurnedOn() == true);
//	CHECK(tv.SetChannelName(1, ChannelOrt) == true);
//	CHECK(tv.SetChannelName(2, "NTV") == true);
//	CHECK(tv.SetChannelName(3, "v mire zhivotnih") == true);
//
//	//Смотрим запись в массиве
//	vector<string> allChannels = tv.GetAllChannels();
//	CHECK(allChannels[0] == ChannelOrt);
//	CHECK(allChannels[1] == "NTV");
//	CHECK(allChannels[2] == "v mire zhivotnih");
//	CHECK(allChannels[10] == "");
//	CHECK(allChannels[98] == "");
//
//	//название канала
//	CHECK(tv.GetChannelName(1) == ChannelOrt);
//	CHECK(tv.GetChannelName(2) == "NTV");
//	CHECK(tv.GetChannelName(10) == "");
//	CHECK(tv.GetChannelName(100) == "");
//	CHECK(tv.GetChannelName(0) == "");
//
//	//переключаем канал по названию
//	CHECK(tv.SelectChannel(ChannelOrt) == true);
//	CHECK(tv.GetChannelNumber() == 1);
//	CHECK(tv.SelectChannel("NTV") == true);
//	CHECK(tv.GetChannelNumber() == 2);
//	CHECK(tv.SelectChannel("v mire zhivotnih") == true);
//	CHECK(tv.GetChannelNumber() == 3);
//
//	//номер канала по названию
//	CHECK(tv.GetChannelByName(ChannelOrt) == 1);
//	CHECK(tv.GetChannelByName("NTV") == 2);
//	CHECK(tv.GetChannelByName("") == 0);
//	CHECK(tv.GetChannelByName("TNT") == 0);//не существующее имя канала
//
//	//удаляем название канала
//	CHECK(tv.DeleteChannelName(ChannelOrt) == true);
//	vector<string> allChannels2 = tv.GetAllChannels();
//	CHECK(allChannels2[0] == "");
//	CHECK(allChannels2[1] == "NTV");
//
//	CHECK(tv.DeleteChannelName("NTV") == true);
//	vector<string> allChannels3 = tv.GetAllChannels();
//	CHECK(allChannels3[0] == "");
//	CHECK(allChannels3[1] == "");
//}
