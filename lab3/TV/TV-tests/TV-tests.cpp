#include "pch.h"
#include "../TV/CTVSet.h"

using namespace std;

SCENARIO("Turn on and turn off TV", "[tvset]")
{
	GIVEN("Turn off TV")
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

SCENARIO("get channel number TV, first turn on", "[tvset]")
{
	CTVSet tv;

	GIVEN("Turn off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK(tv.GetChannelNumber() == 0);
		}
	}
		
	GIVEN("Turn on TV")
	{
		tv.TurnOn();

		WHEN("first turn on")
		{
			CHECK(tv.GetChannelNumber() == 1);
		}
	}
}

SCENARIO("select channel by number channel TV", "[tvset]")
{
	CTVSet tv;

	GIVEN("Turn off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.SelectChannel(10));
		}
	}

	GIVEN("Turn on TV")
	{
		tv.TurnOn();

		WHEN("1 <= cnannel <= 99")
		{
			CHECK(tv.SelectChannel(10));
			CHECK(tv.SelectChannel(1));
			CHECK(tv.SelectChannel(99));
		}
		AND_WHEN("cnannel > 99, cnannel < 1")
		{
			CHECK_FALSE(tv.SelectChannel(0));
			CHECK_FALSE(tv.SelectChannel(100));
		}
	}
}

SCENARIO("select previous channel TV", "[tvset]")
{
	CTVSet tv;

	GIVEN("Turn off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.SelectPreviousChannel());
		}
	}

	GIVEN("Turn on TV")
	{
		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());
		WHEN("first turn on TV")
		{
				CHECK(tv.SelectPreviousChannel());
				CHECK(tv.GetChannelNumber() == 1);
		}
		AND_WHEN("select previous channel twice")
		{
			THEN("turning on 99, then on 10")
			{
				tv.SelectChannel(99);
				tv.SelectChannel(10);

				AND_THEN("select previous on 99")
				{
					CHECK(tv.SelectPreviousChannel());
					CHECK(tv.GetChannelNumber() == 99);

					AND_THEN("select previous on 10")
					{
						CHECK(tv.SelectPreviousChannel());
						CHECK(tv.GetChannelNumber() == 10);
					}
				}
			}
		}
	}
}

SCENARIO("set channel name TV", "[tvset]")
{
	CTVSet tv;
	string ChannelOrt = "ORT";
	string Channel24Kanal = "24 kanal o zhizni";
	map<int, string> allChannels;

	GIVEN("Turn off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.SetChannelName(1, ChannelOrt));
		}
	}

	GIVEN("Turn on TV")
	{
		tv.TurnOn();

		WHEN("set channel name")
		{
			CHECK(tv.SetChannelName(1, ChannelOrt));
			allChannels = tv.GetAllChannels();
			CHECK(allChannels[1] == ChannelOrt);
		}
		AND_WHEN("set channel name with a number and a few words")
		{
			CHECK(tv.SetChannelName(2, Channel24Kanal));
			allChannels = tv.GetAllChannels();
			CHECK(allChannels[2] == Channel24Kanal);
		}
		AND_WHEN("set the same channel name")
		{
			CHECK(tv.SetChannelName(11, ChannelOrt));
			allChannels = tv.GetAllChannels();
			CHECK(allChannels[1].empty());
			CHECK(allChannels[11] == ChannelOrt);
		}
		AND_WHEN("set 0 and 100 channel")
		{
			CHECK_FALSE(tv.SetChannelName(0, ChannelOrt));
			CHECK_FALSE(tv.SetChannelName(100, ChannelOrt));
		}
	}
}

SCENARIO("get channel name TV by number of channel and by name of channel", "[tvset]")
{
	CTVSet tv;
	string ChannelOrt = "ORT";
	string Channel24Kanal = "24 kanal o zhizni";

	GIVEN("Turn off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK(tv.GetChannelName(2) == "");
			CHECK(tv.GetChannelByName(ChannelOrt) == 0);
		}
	}

	GIVEN("Turn on TV")
	{
		tv.TurnOn();

		WHEN("all TV channels without names")
		{
			CHECK(tv.GetChannelName(2) == "");
			CHECK(tv.GetChannelByName(ChannelOrt) == 0);
		}
		AND_WHEN("get channel by name and by number of channel")
		{
			THEN("set channel name")
			{
				CHECK(tv.SetChannelName(11, ChannelOrt));

				AND_THEN("get channel by number of channel")
				{
					CHECK(tv.GetChannelName(11) == ChannelOrt);
				}
				AND_THEN("get channel by name of channel")
				{
					CHECK(tv.GetChannelByName(ChannelOrt) == 11);
				}
			}
		}
		AND_WHEN("get channel name with a number and a few words ")
		{
			THEN("set channel name")
			{
				CHECK(tv.SetChannelName(21, Channel24Kanal));

				AND_THEN("get channel by number of channel")
				{
					CHECK(tv.GetChannelName(21) == Channel24Kanal);
				}
				AND_THEN("get channel by name of channel")
				{
					CHECK(tv.GetChannelByName(Channel24Kanal) == 21);
				}
			}
		}
		AND_WHEN("get on 0 and 100 channel")
		{
			CHECK(tv.GetChannelName(0) == "");
			CHECK(tv.GetChannelName(100) == "");
		}
	}
}

SCENARIO("select channel by name channel TV", "[tvset]")
{
	CTVSet tv;
	string ChannelOrt = "ORT";

	GIVEN("Turn off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.SelectChannel(ChannelOrt));
		}
	}

	GIVEN("Turn on TV")
	{
		tv.TurnOn();

		WHEN("no name of channel")
		{
			CHECK_FALSE(tv.SelectChannel(ChannelOrt));
		}
		AND_WHEN("select channel by name")
		{
			THEN("set channel name")
			{
				CHECK(tv.SetChannelName(11, ChannelOrt));

				AND_THEN("select channel by name of channel")
				{
					CHECK(tv.SelectChannel(ChannelOrt));
					CHECK(tv.GetChannelNumber() == 11);
				}
			}
		}
	}
}

SCENARIO("delete channel name", "[tvset]")
{
	CTVSet tv;
	string ChannelOrt = "ORT";
	map<int, string> allChannels;

	GIVEN("Turn off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("turn off TV")
		{
			CHECK_FALSE(tv.DeleteChannelName(ChannelOrt));
		}
	}

	GIVEN("Turn on TV")
	{
		tv.TurnOn();

		WHEN("no name of channel")
		{
			CHECK_FALSE(tv.DeleteChannelName(ChannelOrt));
		}
		AND_WHEN("delete channel name")
		{
			THEN("save channel name")
			{
				CHECK(tv.SetChannelName(11, ChannelOrt));
				allChannels = tv.GetAllChannels();
				CHECK(allChannels[11] == ChannelOrt);

				AND_THEN("delete channel name") 
				{
					CHECK(tv.DeleteChannelName(ChannelOrt));
					allChannels = tv.GetAllChannels();
					CHECK(allChannels[11].empty());
				}
			}
		}
	}
}
