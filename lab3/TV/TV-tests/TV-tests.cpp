#include "pch.h"
#include "../TV/CTVSe.h"

using namespace std;


TEST_CASE("class CTVSet tests")
{
	CHECK("" == "");

	CTVSet tv, result;

	//начальное состояние выкл ТВ
	CHECK(tv.SelectChannel(2) == false);
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetChannelNumber() == 0);

	//вкл ТВ
	const bool tvStatus2 = true;

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

	tv.TurnOff();
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetChannelNumber() == 0);
	CHECK(tv.SelectChannel(2) == false);
}