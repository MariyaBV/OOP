#include "pch.h"

#include "../TV/CTVSet.h"
#include "../TV/RemoteControl.h"

#include <sstream>

SCENARIO("Remote control can turn on a TV", "[remote]")
{
	GIVEN("A remote control connected to the TV which is turned off")
	{
		CTVSet tv;
		std::stringstream input, output;
		CRemoteControl rc(tv, input, output);

		REQUIRE(!tv.IsTurnedOn());

		WHEN("user enters TurnOn command")
		{
			input << "TurnOn";
			CHECK(rc.HandleCommand());
			THEN("tv switches on")
			{
				CHECK(tv.IsTurnedOn());
				AND_THEN("user gets notification")
				{
					CHECK(output.str() == "TV is turned on\n");
				}
			}
		}
	}
}

SCENARIO("Remote control provides information about TV", "[remote]")
{
	CTVSet tv;
	std::stringstream input;
	std::ostringstream output;
	input << "Info";
	CRemoteControl rc(tv, input, output);
	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter Info command")
		{
			rc.HandleCommand();
			THEN("it is notified that TV is off")
			{
				CHECK(output.str() == "TV is turned off\n");
			}
		}
	}

	GIVEN("A turned on TV")
	{
		tv.TurnOn();
		tv.SelectChannel(17);
		REQUIRE(tv.IsTurnedOn());
		WHEN("user enter Info command")
		{
			rc.HandleCommand();
			THEN("it is notified that TV is on the current channel")
			{
				CHECK(output.str() == "TV is turned on\nChannel is: 17\n");
			}
		}

		string ort = "ORT";
		string kanal24 = "24 kanal";
		tv.SetChannelName(1, ort);
		tv.SetChannelName(24, kanal24);
		WHEN("user saved names of channels")
		{
			rc.HandleCommand();
			THEN("it is notified that TV is on the current channel and all numbers of channel with name")
			{
				CHECK(output.str() == "TV is turned on\nChannel is: 17\n1 - ORT\n24 - 24 kanal\n");
			}
		}

		tv.SetChannelName(30, ort);
		WHEN("user saved name if the specified name has already been assigned to another channel")
		{
			rc.HandleCommand();
			THEN("it is notified that TV is on the current channel and all numbers of channel with name")
			{
				CHECK(output.str() == "TV is turned on\nChannel is: 17\n24 - 24 kanal\n30 - ORT\n");
			}
		}

		tv.DeleteChannelName(kanal24);
		WHEN("delete channel")
		{
			rc.HandleCommand();
			THEN("it is notified that TV is on the current channel and all numbers of channel with name")
			{
				CHECK(output.str() == "TV is turned on\nChannel is: 17\n30 - ORT\n");
			}
		}
	}
}
