#include "pch.h"
#include "../TV/CTVSet.h"
#include "../TV/AdditionalFunction.h"

using namespace std;


TEST_CASE("class CTVSet tests")
{
	CHECK("" == "");

	CTVSet tv;

	//начальное состояние выкл ТВ
	CHECK(tv.SelectChannel(2) == false);
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetChannelNumber() == 0);

	//вкл ТВ
	tv.TurnOn();
	CHECK(tv.IsTurnedOn() == true);
	CHECK(tv.SelectChannel(100) == false);
	CHECK(tv.SelectChannel(0) == false);
	CHECK(tv.GetChannelNumber() == 1);

	//переключили канал
	CHECK(tv.SelectChannel(2) == true);
	CHECK(tv.GetChannelNumber() == 2);

	CHECK(tv.SelectChannel(100) == false);
	CHECK(tv.GetChannelNumber() == 2);

	CHECK(tv.SelectChannel(0) == false);
	CHECK(tv.GetChannelNumber() == 2);

	CHECK(tv.SelectChannel(15) == true);
	CHECK(tv.GetChannelNumber() == 15);

	//выкл тв 
	tv.TurnOff();
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetChannelNumber() == 0);
	CHECK(tv.SelectChannel(2) == false);
}

TEST_CASE("SelectPreviousChannel tests")
{
	CTVSet tv;

	//начальное состояние выкл ТВ
	CHECK(tv.SelectPreviousChannel() == false);
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetChannelNumber() == 0);

	//вкл ТВ
	tv.TurnOn();
	CHECK(tv.IsTurnedOn() == true);
	CHECK(tv.SelectChannel(100) == false);
	CHECK(tv.SelectPreviousChannel() == true);
	CHECK(tv.GetChannelNumber() == 1);
	CHECK(tv.SelectChannel(0) == false);
	CHECK(tv.SelectPreviousChannel() == true);
	CHECK(tv.GetChannelNumber() == 1);

	//переключили канал
	CHECK(tv.SelectChannel(2) == true);
	CHECK(tv.GetChannelNumber() == 2);
	CHECK(tv.SelectPreviousChannel() == true);
	CHECK(tv.GetChannelNumber() == 1);

	CHECK(tv.SelectChannel(15) == true);
	CHECK(tv.GetChannelNumber() == 15);
	CHECK(tv.SelectChannel(10) == true);
	CHECK(tv.GetChannelNumber() == 10);
	CHECK(tv.SelectPreviousChannel() == true);
	CHECK(tv.GetChannelNumber() == 15);
	CHECK(tv.SelectPreviousChannel() == true);
	CHECK(tv.GetChannelNumber() == 10);
	CHECK(tv.SelectChannel(10) == true);
	CHECK(tv.GetChannelNumber() == 10);
	CHECK(tv.SelectPreviousChannel() == true);
	CHECK(tv.GetChannelNumber() == 10);

	//выкл тв
	tv.TurnOff();
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetChannelNumber() == 0);
	CHECK(tv.SelectChannel(2) == false);
	CHECK(tv.SelectPreviousChannel() == false);
}

TEST_CASE("SetChannelName tests")
{
	CTVSet tv;

	//начальное состояние выкл ТВ
	CHECK(tv.SetChannelName(1, "ORT") == false);
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetChannelNumber() == 0);

	//вкл ТВ
	tv.TurnOn();
	CHECK(tv.IsTurnedOn() == true);
	CHECK(tv.SetChannelName(1, "ORT") == true);
}

TEST_CASE("ParsingNumberAndString")
{
	string inputString1 = "";
	pair<int, string> outputPair1;

	outputPair1 = ParsingNumberAndString(inputString1);
	CHECK(outputPair1.first == 0);
	CHECK(outputPair1.second == "");

	string inputString2 = "12 155 vokrug sveta   ";
	pair<int, string> outputPair2;

	outputPair2 = ParsingNumberAndString(inputString2);
	CHECK(outputPair2.first == 12);
	CHECK(outputPair2.second == "155 vokrug sveta");

	string inputString3 = "10";
	pair<int, string> outputPair3;

	outputPair3 = ParsingNumberAndString(inputString3);
	CHECK(outputPair3.first == 10);
	CHECK(outputPair3.second == "");

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