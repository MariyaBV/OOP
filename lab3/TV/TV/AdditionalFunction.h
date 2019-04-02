#include "pch.h"
#include "CTVSet.h"
#include <regex>
#include <type_traits>

using namespace std;

string ErrorInfo(CTVSet& m_tv, bool setChannelName);
pair<int, string> ParsingNumberAndString(string inputString);