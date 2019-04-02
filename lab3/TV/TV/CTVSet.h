#pragma once
#include <vector>

class CTVSet
{
public:
	CTVSet();
	~CTVSet();
	void TurnOff();
	void TurnOn();
	bool IsTurnedOn() const;
	int GetChannelNumber() const;
	bool SelectChannel(int channel);
	bool SelectPreviousChannel();
	bool SetChannelName(int channel, std::string channelName);

private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
	int m_previousSelectedChannel = 1;
	std::string m_channelNames[99];
	//std::vector<std::string> m_channelNames[99];
};
