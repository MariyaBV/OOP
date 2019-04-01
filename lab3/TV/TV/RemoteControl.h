#pragma once
#include <boost/noncopyable.hpp>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <regex>
#include <type_traits>


using namespace std;
class CTVSet;

// Наследование от boost::noncopyable - явный способ запретить копирование и присваивание экземпляров класса
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

private:
	using HandleUserCommand = function<bool(istream& args)>;
	using ActionMap = map<string, HandleUserCommand>;

	CTVSet& m_tv;
	istream& m_input;
	int channel;
	ostream& m_output;

	const ActionMap m_actionMap;
};
