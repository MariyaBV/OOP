#include "pch.h"
#include "../TV/CTVSet.h"

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