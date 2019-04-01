#pragma once

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

private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
	int m_previousSelectedChannel = 1;
};
