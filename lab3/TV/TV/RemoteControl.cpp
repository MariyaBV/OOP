#include "pch.h"
#include "RemoteControl.h"
#include "AdditionalFunction.h"
#include "CTVSet.h"

using namespace std;

CRemoteControl::CRemoteControl(CTVSet& tv, istream& input, ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "TurnOn", bind(&CRemoteControl::TurnOn, this, placeholders::_1) },
		  { "TurnOff", bind(&CRemoteControl::TurnOff, this, placeholders::_1) },
		  { "Info", bind(&CRemoteControl::Info, this, placeholders::_1) },
		  { "SelectChannel", bind(&CRemoteControl::SelectChannel, this, placeholders::_1) },
		  { "SelectPreviousChannel", bind(&CRemoteControl::SelectPreviousChannel, this, placeholders::_1) },
		  { "SetChannelName", bind(&CRemoteControl::SetChannelName, this, placeholders::_1) },
		  { "DeleteChannelName", bind(&CRemoteControl::DeleteChannelName, this, placeholders::_1) },
		  { "GetChannelName", bind(&CRemoteControl::GetChannelName, this, placeholders::_1) },
		  { "GetChannelByName", bind(&CRemoteControl::GetChannelByName, this, placeholders::_1) } })
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CRemoteControl::TurnOn(istream& args)
{
	m_tv.TurnOn();
	m_output << "TV is turned on" << endl;
	return true;
}

bool CRemoteControl::TurnOff(istream& args)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
	return true;
}

bool CRemoteControl::Info(istream& args)
{
	string info = (m_tv.IsTurnedOn())
		? ("TV is turned on\nChannel is: " + to_string(m_tv.GetChannelNumber()) + "\n")
		: "TV is turned off\n";

	m_output << info;

	if (m_tv.IsTurnedOn())
	{
		for (size_t i = 0; i < (m_tv.GetAllChannels()).size(); i++)
		{
			if (!m_tv.GetAllChannels()[i].empty())
			{
				m_output << i + 1 << " - " << m_tv.GetAllChannels()[i] << endl;
			}
		}
	}

	return true;
}

bool CRemoteControl::SelectChannel(istream& args)
{
	string inputString;
	getline(args, inputString);
	int channel = atoi(inputString.c_str());
	string channelName = regex_replace(inputString, regex("^ +| +$|( ) +"), "$1");
	bool selectedChannel;

	if (!channelName.empty())
	{
		selectedChannel = m_tv.SelectChannel(channelName);
	}
	else
	{
		selectedChannel = m_tv.SelectChannel(channel);
	}

	string info;

	if ((m_tv.IsTurnedOn()) && (selectedChannel))
	{
		info = "TV channel changed to " + to_string(channel);
	}
	else
	{
		info = ErrorInfo(m_tv, selectedChannel);
	}

	m_output << info << endl;

	return true;
}

bool CRemoteControl::SelectPreviousChannel(istream& args)
{
	m_tv.SelectPreviousChannel();

	string info = (m_tv.IsTurnedOn())
		? ("TV channel changed to " + to_string(m_tv.GetChannelNumber()) + "\n")
		: "TV is turned off\n";

	m_output << info;

	return true;
}

bool CRemoteControl::SetChannelName(istream& args)
{
	string inputString;
	getline(args, inputString);
	pair<int, string> channelNumberAndName = ParsingNumberAndString(inputString);
	int channel = channelNumberAndName.first;
	string channelName = channelNumberAndName.second;
	bool setChannelName = m_tv.SetChannelName(channel, channelName);
	string info;

	if ((m_tv.IsTurnedOn()) && (setChannelName))
	{
		info = "TV channel " + to_string(channel) + " saved name: " + channelName;
	}
	else
	{
		info = ErrorInfo(m_tv, setChannelName);
	}

	m_output << info << endl;

	return true;
}

bool CRemoteControl::DeleteChannelName(istream& args)
{
	string inputString;
	getline(args, inputString);
	string channelName = regex_replace(inputString, regex("^ +| +$|( ) +"), "$1");
	bool deletedChannelName = m_tv.DeleteChannelName(channelName);

	string info;

	if ((m_tv.IsTurnedOn()) && (deletedChannelName))
	{
		info = "Delete Name: " + channelName + " from TV channel: " + to_string(channel);
	}
	else
	{
		info = ErrorInfo(m_tv, deletedChannelName);
	}

	m_output << info << endl;

	return true;
}

bool CRemoteControl::GetChannelName(istream& args)
{
	string inputString;
	getline(args, inputString);
	int channel = atoi(inputString.c_str());

	string channelName = m_tv.GetChannelName(channel);
	string info;

	if ((m_tv.IsTurnedOn()) && (!channelName.empty()))
	{
		info = "TV channel: " + to_string(channel) + " - " + channelName;
	}
	else if ((m_tv.IsTurnedOn()) && (channelName.empty()) && (channel >= 1) && (channel <= 99))
	{
		info = "TV channel: " + to_string(channel) + " has not name";
	}
	else if (!(m_tv.IsTurnedOn()))
	{
		info = "TV is turned off";
	}
	else
	{
		info = "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99";
	}

	m_output << info << endl;

	return true;
}

bool CRemoteControl::GetChannelByName(istream& args)
{
	string inputString;
	getline(args, inputString);
	string channelName = regex_replace(inputString, regex("^ +| +$|( ) +"), "$1");
	size_t channel = m_tv.GetChannelByName(channelName);
	string info;

	if ((m_tv.IsTurnedOn()) && (channel != 0))
	{
		info = "TV channel: " + to_string(channel) + " - " + channelName;
	}
	else if ((m_tv.IsTurnedOn()) && (channel == 0))
	{
		info = "TV channel: " + channelName + " not found";
	}
	else if (!(m_tv.IsTurnedOn()))
	{
		info = "TV is turned off";
	}

	m_output << info << endl;

	return true;
}
