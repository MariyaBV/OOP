#include "pch.h"
#include "CTVSet.h"
#include <algorithm>

CTVSet::CTVSet()
{
	m_channelNames.resize(100);
}

void CTVSet::TurnOff()
{
	m_isOn = false;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}

bool CTVSet::IsTurnedOn() const
{
	return m_isOn;
}

size_t CTVSet::GetChannelNumber() const
{
	return m_isOn ? m_selectedChannel : 0;
}

bool CTVSet::SelectChannel(int channel)
{
	if ((channel >= 1) && (channel <= 99) && m_isOn)
	{
		m_previousSelectedChannel = m_selectedChannel;
		m_selectedChannel = channel;

		return true;
	}

	return false;
}

bool CTVSet::SelectChannel(const std::string& channelName)
{
	if (m_isOn)
	{
		for (size_t i = 0; i < m_channelNames.size(); i++)
		{
			if (m_channelNames[i] == channelName)
			{
				m_previousSelectedChannel = m_selectedChannel;
				m_selectedChannel = i;

				return true;
			}
		}
	}

	return false;
}

bool CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		std::swap(m_selectedChannel, m_previousSelectedChannel);

		return true;
	}

	return false;
}

bool CTVSet::SetChannelName(int channel, const std::string& channelName)
{
	if ((channel >= 1) && (channel <= 99) && m_isOn)
	{
		DeleteChannelName(channelName);
		m_channelNames[channel] = channelName;

		return true;
	}

	return false;
}

std::map<int, std::string> CTVSet::GetAllChannels() const
{
	std::map<int, std::string> allChannelsWithName;

	for (size_t i = 0; i < m_channelNames.size(); i++)
	{
		if (!m_channelNames[i].empty())
		{
			allChannelsWithName[static_cast<int>(i)] = m_channelNames[static_cast<int> (i)];
		}
	}

	return allChannelsWithName;
}

bool CTVSet::DeleteChannelName(const std::string& channelName)
{
	if (!channelName.empty())
	{
		if (auto it = find(m_channelNames.begin(), m_channelNames.end(), channelName);
			it != m_channelNames.end())
		{
			int channelNumber = static_cast<int>(it - m_channelNames.begin());
			m_channelNames[channelNumber].clear();

			return true;

		}
	}

	return false;
}

std::string CTVSet::GetChannelName(int channel) const
{
	if ((channel >= 1) && (channel <= 99) && m_isOn)
	{
		return m_channelNames[channel];
	}

	return "";
}

size_t CTVSet::GetChannelByName(const std::string& channelName) const
{
	if (!channelName.empty())
	{
		std::vector<std::string>::const_iterator it;
		it = std::find(m_channelNames.begin(), m_channelNames.end(), channelName);
		if (it != m_channelNames.end())
			return std::distance(m_channelNames.begin(), it);
	}

	return 0;
}
