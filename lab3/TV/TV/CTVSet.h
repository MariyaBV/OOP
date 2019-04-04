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
	size_t GetChannelNumber() const;
	bool SelectChannel(int channel);
	bool SelectChannel(std::string& channelName);
	bool SelectPreviousChannel();
	bool SetChannelName(int channel, std::string& channelName);
	std::vector<std::string> GetAllChannels() const;
	bool DeleteChannelName(std::string& channelName);
	std::string GetChannelName(int channel) const;
	size_t GetChannelByName(std::string& nameChannel) const;

private:
	bool m_isOn = false;
	size_t m_selectedChannel = 1;
	size_t m_previousSelectedChannel = 1;
	std::vector<std::string> m_channelNames;
	std::string m_channelName;
};
