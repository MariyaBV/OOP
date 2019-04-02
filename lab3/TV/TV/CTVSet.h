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
	bool SelectChannel(std::string channelName);
	bool SelectPreviousChannel();
	bool SetChannelName(int channel, std::string channelName);
	std::vector<std::string> GetAllChannels() const;
	bool DeleteChannelName(std::string channelName);
	std::string GetChannelName(int channel);
	int GetChannelByName(std::string nameChannel);

private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
	int m_previousSelectedChannel = 1;
	std::vector<std::string> m_channelNames;
	std::string m_channelName;
};
