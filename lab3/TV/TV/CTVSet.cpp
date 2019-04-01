#include "pch.h"
#include "CTVSet.h"

CTVSet::CTVSet()
{
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

int CTVSet::GetChannelNumber() const
{
	return m_isOn ? m_selectedChannel : 0;
}

bool CTVSet::SelectChannel(int channel)
{
	if ((channel >= 1) && (channel <= 99) && m_isOn)
	{
		m_selectedChannel = channel;

		return true;
	}

	return false;
}
