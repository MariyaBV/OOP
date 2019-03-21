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
private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
};
