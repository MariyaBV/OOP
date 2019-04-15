#include "pch.h"
#include "CTVSet.h"
#include <algorithm>

CTVSet::CTVSet()
{
	m_channelNames.resize(99);
}

CTVSet::~CTVSet()
{
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
				m_selectedChannel = i + 1;

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
		m_channelNames[channel - 1] = channelName;

		return true;
	}

	return false;
}

std::map<int, std::string> CTVSet::GetAllChannels() const
{
	std::map<int, std::string> allChannelWithName;

	for (size_t i = 0; i < m_channelNames.size(); i++)
	{
		if (!m_channelNames[i].empty())
		{
			allChannelWithName[i + 1] = m_channelNames[i];
		}
	}

	return allChannelWithName;
}

bool CTVSet::DeleteChannelName(const std::string& channelName)
{
	if (!channelName.empty())
	{
		std::vector<std::string>::const_iterator it;
		it = find(m_channelNames.begin(), m_channelNames.end(), channelName);
		if (it != m_channelNames.end())
		{
			int channelNumber = it - m_channelNames.begin();
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
		return m_channelNames[channel - 1];
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
			return std::distance(m_channelNames.begin(), it) + 1;
	}

	return 0;
}
