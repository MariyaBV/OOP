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
		AND_WHEN("user enters TurnOff command")
		{
			tv.TurnOn();
			REQUIRE(tv.IsTurnedOn());
			input << "TurnOff";
			CHECK(rc.HandleCommand());
			THEN("tv turn off")
			{
				CHECK(!tv.IsTurnedOn());
				AND_THEN("user gets notification")
				{
					CHECK(output.str() == "TV is turned off\n");
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

SCENARIO("Remote control for select TV channel", "[remote]")
{
	CTVSet tv;
	std::stringstream input;
	std::ostringstream output;

	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter SelectChannel by number command")
		{
			input << "SelectChannel 2";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that TV is off")
			{
				CHECK(output.str() == "TV is turned off\n");
			}
		}
		AND_WHEN("user enter SelectChannel by name command")
		{
			input << "SelectChannel ort";
			CRemoteControl rc(tv, input, output);
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
		REQUIRE(tv.IsTurnedOn());
		WHEN("user enter SelectChannel 99 command")
		{
			input << "SelectChannel 99";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that TV is on the current channel")
			{
				CHECK(output.str() == "TV channel changed to 99\n");
			}
		}
		AND_WHEN("user enter SelectChannel 1 command")
		{
			input << "SelectChannel 1";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that TV is on the current channel")
			{
				CHECK(output.str() == "TV channel changed to 1\n");
			}
		}
		AND_WHEN("user enter SelectChannel command")
		{
			input << "SelectChannel";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that wrong channel number")
			{
				CHECK(output.str() == "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99\n");
			}
		}
		AND_WHEN("user enter SelectChannel 0 command")
		{
			input << "SelectChannel 0";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on wrong channel")
			{
				CHECK(output.str() == "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99\n");
			}
		}
		AND_WHEN("user enter SelectChannel 100 command")
		{
			input << "SelectChannel 100";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on wrong channel")
			{
				CHECK(output.str() == "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99\n");
			}
		}
		AND_WHEN("user enter SelectChannel ort command but this channel not exists")
		{
			input << "SelectChannel ort";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that not found channel")
			{
				CHECK(output.str() == "Not found channel name: ort\n");
			}
		}
		AND_WHEN("user enter SelectChannel 99 kanal command")
		{
			string kanal99 = "99 kanal";
			tv.SetChannelName(99, kanal99);
			input << "SelectChannel 99 kanal";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on 99 kanal")
			{
				CHECK(output.str() == "TV channel changed to 99 kanal\n");
			}
		}
		AND_WHEN("user enter SelectChannel v mire zhivotnih command")
		{
			string kanal15 = "v mire zhivotnih";
			tv.SetChannelName(15, kanal15);
			input << "SelectChannel v mire zhivotnih";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on 15 kanal")
			{
				CHECK(output.str() == "TV channel changed to v mire zhivotnih\n");
			}
		}
	}
}

SCENARIO("Remote control for select previous TV channel", "[remote]")
{
	CTVSet tv;
	std::stringstream input;
	std::ostringstream output;

	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter SelectPreviousChannel command")
		{
			input << "SelectPreviousChannel";
			CRemoteControl rc(tv, input, output);
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
		REQUIRE(tv.IsTurnedOn());
		WHEN("user enter SelectPreviousChannel command, first turn on")
		{
			input << "SelectPreviousChannel";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that TV is on the current channel")
			{
				CHECK(output.str() == "TV channel changed to 1\n");
			}
		}
		AND_WHEN("user enter SelectPreviousChannel command")
		{
			tv.SelectChannel(2);
			tv.SelectChannel(15);
			input << "SelectPreviousChannel";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that TV is on the current channel")
			{
				CHECK(output.str() == "TV channel changed to 2\n");
			}
		}
	}
}

SCENARIO("Remote control for set TV channel name", "[remote]")
{
	CTVSet tv;
	std::stringstream input;
	std::ostringstream output;

	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter SetChannelName 2 ORT command")
		{
			input << "SetChannelName 2 ORT";
			CRemoteControl rc(tv, input, output);
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
		REQUIRE(tv.IsTurnedOn());
		WHEN("user enter SetChannelName 1 ORT command")
		{
			input << "SetChannelName 1 ORT";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that channel name saved")
			{
				CHECK(output.str() == "TV channel 1 saved name: ORT\n");
			}
		}
		AND_WHEN("user enter SetChannelName 99 v mire zhivotnih 99 command")
		{
			input << "SetChannelName 99 v mire zhivotnih 99";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that channel name saved")
			{
				CHECK(output.str() == "TV channel 99 saved name: v mire zhivotnih 99\n");
			}
		}
		AND_WHEN("user enter SetChannelName 24 24 kanal command")
		{
			input << "SetChannelName   24   24   kanal  ";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that channel name saved")
			{
				CHECK(output.str() == "TV channel 24 saved name: 24 kanal\n");
			}
		}
		AND_WHEN("user enter SetChannelName 0 NTV command")
		{
			input << "SetChannelName 0 NTV";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on wrong channel")
			{
				CHECK(output.str() == "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99\n");
			}
		}
		AND_WHEN("user enter SetChannelName 100 NTV command")
		{
			input << "SetChannelName 100 NTV";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on wrong channel")
			{
				CHECK(output.str() == "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99\n");
			}
		}
		AND_WHEN("user enter SetChannelName NTV command")
		{
			input << "SetChannelName NTV";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on wrong channel")
			{
				CHECK(output.str() == "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99\n");
			}
		}
		AND_WHEN("user enter SetChannelName 18 command")
		{
			input << "SetChannelName 18";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that channel name saved")
			{
				CHECK(output.str() == "TV channel 18 saved name: \n");
			}
		}
	}
}

SCENARIO("Remote control for get TV channel name by number", "[remote]")
{
	CTVSet tv;
	std::stringstream input;
	std::ostringstream output;

	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter GetChannelName 2 command")
		{
			input << "GetChannelName 2";
			CRemoteControl rc(tv, input, output);
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
		REQUIRE(tv.IsTurnedOn());
		WHEN("user enter GetChannelName command, first turn on")
		{
			input << "GetChannelName 1";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that channel haven't name")
			{
				CHECK(output.str() == "TV channel: 1 has not name\n");
			}
		}
		AND_WHEN("user enter GetChannelName 1 command")
		{
			string ntv = "NTV";
			tv.SetChannelName(1, ntv);
			input << "GetChannelName 1";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that found channel name")
			{
				CHECK(output.str() == "TV channel: 1 - NTV\n");
			}
		}
		AND_WHEN("user enter GetChannelName 99 command")
		{
			string ort = "ORT";
			tv.SetChannelName(99, ort);
			input << "GetChannelName 99";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that found channel name")
			{
				CHECK(output.str() == "TV channel: 99 - ORT\n");
			}
		}
		AND_WHEN("user enter GetChannelName 0 command")
		{
			input << "GetChannelName 0";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on wrong channel")
			{
				CHECK(output.str() == "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99\n");
			}
		}
		AND_WHEN("user enter GetChannelName 100 command")
		{
			input << "GetChannelName 100";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on wrong channel")
			{
				CHECK(output.str() == "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99\n");
			}
		}
		AND_WHEN("user enter GetChannelName command")
		{
			input << "GetChannelName";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that turn on wrong channel")
			{
				CHECK(output.str() == "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99\n");
			}
		}
	}
}

SCENARIO("Remote control for get TV channel number by name", "[remote]")
{
	CTVSet tv;
	std::stringstream input;
	std::ostringstream output;

	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter GetChannelByName ORT command")
		{
			input << "GetChannelByName ORT";
			CRemoteControl rc(tv, input, output);
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
		REQUIRE(tv.IsTurnedOn());
		WHEN("user enter GetChannelByName ORT command, first turn on")
		{
			input << "GetChannelByName ORT";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that not found this channel")
			{
				CHECK(output.str() == "TV channel: ORT not found\n");
			}
		}
		AND_WHEN("user enter GetChannelByName NTV command")
		{
			string ntv = "NTV";
			tv.SetChannelName(1, ntv);
			input << "GetChannelByName NTV";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that found channel number")
			{
				CHECK(output.str() == "TV channel: 1 - NTV\n");
			}
		}
		AND_WHEN("user enter GetChannelByName 99 kanal command")
		{
			string kanal99 = "99 kanal";
			tv.SetChannelName(99, kanal99);
			input << "GetChannelByName 99 kanal";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that found channel number")
			{
				CHECK(output.str() == "TV channel: 99 - 99 kanal\n");
			}
		}
		AND_WHEN("user enter GetChannelByName command")
		{
			input << "GetChannelByName";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that not found channel number")
			{
				CHECK(output.str() == "TV channel:  not found\n");
			}
		}
	}
}

SCENARIO("Remote control for delete TV channel name by name", "[remote]")
{
	CTVSet tv;
	std::stringstream input;
	std::ostringstream output;

	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter DeleteChannelName ORT command")
		{
			input << "DeleteChannelName ORT";
			CRemoteControl rc(tv, input, output);
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
		REQUIRE(tv.IsTurnedOn());
		WHEN("user enter DeleteChannelName ORT command, first turn on")
		{
			input << "DeleteChannelName ORT";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that not found this channel")
			{
				CHECK(output.str() == "TV channel: ORT not found\n");
			}
		}
		AND_WHEN("user enter DeleteChannelName NTV command")
		{
			string ntv = "NTV";
			tv.SetChannelName(1, ntv);
			input << "DeleteChannelName NTV";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that deleted channel")
			{
				CHECK(output.str() == "Delete TV channel Name: NTV\n");
			}
		}
		AND_WHEN("user enter DeleteChannelName 99 kanal command")
		{
			string kanal99 = "99 kanal";
			tv.SetChannelName(99, kanal99);
			input << "DeleteChannelName 99 kanal";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that found channel number")
			{
				CHECK(output.str() == "Delete TV channel Name: 99 kanal\n");
			}
		}
		AND_WHEN("user enter DeleteChannelName command, first turn on")
		{
			input << "DeleteChannelName";
			CRemoteControl rc(tv, input, output);
			rc.HandleCommand();
			THEN("it is notified that not found this channel")
			{
				CHECK(output.str() == "TV channel:  not found\n");
			}
		}
	}
}