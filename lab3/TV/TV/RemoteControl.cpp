#include "pch.h"
#include "RemoteControl.h"
#include "CTVSet.h"
#include "AdditionalFunction.h"

using namespace std;

CRemoteControl::CRemoteControl(CTVSet& tv, istream& input, ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "TurnOn", bind(&CRemoteControl::TurnOn, this, placeholders::_1) },
		  { "TurnOff", bind(&CRemoteControl::TurnOff, this, placeholders::_1) },
		  { "Info", bind(&CRemoteControl::Info, this, placeholders::_1) },
		  { "SelectChannel", bind(&CRemoteControl::SelectChannel, this, placeholders::_1) },
		  { "SelectPreviousChannel", bind(&CRemoteControl::SelectPreviousChannel, this, placeholders::_1) },
		  { "SetChannelName", bind(&CRemoteControl::SetChannelName, this, placeholders::_1) },
	  })
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

	return true;
}

bool CRemoteControl::SelectChannel(istream& args)
{
	string inputString;
	args >> inputString;
	int channel = atoi(inputString.c_str());
	bool selectedChannel = m_tv.SelectChannel(channel);
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
