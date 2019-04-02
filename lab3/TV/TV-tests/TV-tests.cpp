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

	//переключение на предыдущий канал
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
	CHECK(tv.GetChannelName(1) == "");
	CHECK(tv.GetChannelByName("ORT") == 0);
	CHECK(tv.DeleteChannelName("ORT") == false);
	CHECK(tv.SelectChannel("ORT") == false);

	//вкл ТВ
	tv.TurnOn();
	CHECK(tv.IsTurnedOn() == true);
	CHECK(tv.SetChannelName(1, "ORT") == true);
	CHECK(tv.SetChannelName(2, "NTV") == true);

	//Смотрим запись в массиве
	vector<string> allChannels = tv.GetAllChannels();
	CHECK(allChannels[0] == "ORT");
	CHECK(allChannels[1] == "NTV");
	CHECK(allChannels[2] == "");
	CHECK(allChannels[98] == "");

	//название канала
	CHECK(tv.GetChannelName(1) == "ORT");
	CHECK(tv.GetChannelName(2) == "NTV");
	CHECK(tv.GetChannelName(10) == "");
	CHECK(tv.GetChannelName(100) == "");
	CHECK(tv.GetChannelName(0) == "");

	//переключаем канал по названию
	CHECK(tv.SelectChannel("ORT") == true);
	CHECK(tv.GetChannelNumber() == 1);
	CHECK(tv.SelectChannel("NTV") == true);
	CHECK(tv.GetChannelNumber() == 2);

	//номер канала по названию
	CHECK(tv.GetChannelByName("ORT") == 1);
	CHECK(tv.GetChannelByName("NTV") == 2);
	CHECK(tv.GetChannelByName("") == 0);
	CHECK(tv.GetChannelByName("TNT") == 0);

	//удаляем название канала
	CHECK(tv.DeleteChannelName("ORT") == true);
	vector<string> allChannels2 = tv.GetAllChannels();
	CHECK(allChannels2[0] == "");
	CHECK(allChannels2[1] == "NTV");

	CHECK(tv.DeleteChannelName("NTV") == true);
	vector<string> allChannels3 = tv.GetAllChannels();
	CHECK(allChannels3[0] == "");
	CHECK(allChannels3[1] == "");
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