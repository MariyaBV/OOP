#include "pch.h"
#include "RemoteControl.h"
#include "CTVSet.h"

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
	string SelectChannel = "SelectChannel";
	string::size_type pos = inputString.find(SelectChannel);

	while (pos != string::npos)
	{
		inputString.erase(pos, SelectChannel.size());
		pos = inputString.find(SelectChannel, pos + 1);
	}
	inputString = regex_replace(inputString, regex("^ +| +$|( ) +"), "$1");
	int channel = atoi(inputString.c_str());

	m_tv.SelectChannel(channel);
	string info;

	if ((m_tv.IsTurnedOn()) && (m_tv.SelectChannel(channel)))
	{
		info = "TV channel changed to " + to_string(channel);
	}
	else if ((m_tv.IsTurnedOn()) && (!m_tv.SelectChannel(channel)))
	{
		info = "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99";
	}
	else if (!m_tv.IsTurnedOn())
	{
		info = "TV is turned off";
	}

	m_output << info << endl;

	return true;
}
