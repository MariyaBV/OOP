#pragma once
#include "pch.h"
#include "AdditionalFunction.h"
#include "CTVSet.h"

using namespace std;

string ErrorInfo(CTVSet& m_tv, bool setChannelName)
{
	string info;

	if ((m_tv.IsTurnedOn()) && (!setChannelName))
	{
		info = "Error, wrong channel.\nUsage: channel >= 1 && channel <= 99";
	}
	else if (!m_tv.IsTurnedOn())
	{
		info = "TV is turned off";
	}

	return info;
}

pair<int, string> ParsingNumberAndString(string inputString)
{
	int channel = atoi(inputString.c_str());
	size_t channelLength = to_string(channel).length();
	inputString = regex_replace(inputString, regex("^ +| +$|( ) +"), "$1");
	string::size_type pos = inputString.find(to_string(channel));
	if (pos != string::npos)
	{
		inputString.erase(pos, channelLength);
	}

	string channelName = regex_replace(inputString, regex("^ +| +$|( ) +"), "$1");

	pair<int, string> channelNumberAndName;
	channelNumberAndName.first = channel;
	channelNumberAndName.second = channelName;

	return channelNumberAndName;
}
