#pragma once
#include <boost/noncopyable.hpp>

using namespace std;
class CTVSet;

// ������������ �� boost::noncopyable - ����� ������ ��������� ����������� � ������������ ����������� ������
class CRemoteControl : boost::noncopyable
{
public:
	CRemoteControl(CTVSet& tv, istream& input, ostream& output);
	bool HandleCommand();

private:
	bool TurnOn(istream& args);
	bool TurnOff(istream& args);
	bool Info(istream& args);
	bool SelectChannel(istream& args);
	bool SelectPreviousChannel(istream& args);
	bool SetChannelName(istream& args);
	bool DeleteChannelName(istream& args);
	bool GetChannelName(istream& args);
	bool GetChannelByName(istream& args);

private:
	using HandleUserCommand = function<bool(istream& args)>;
	using ActionMap = map<string, HandleUserCommand>;

	CTVSet& m_tv;
	istream& m_input;
	int channel;
	ostream& m_output;

	const ActionMap m_actionMap;
};
