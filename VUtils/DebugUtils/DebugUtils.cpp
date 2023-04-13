#include "DebugUtils/DebugUtils.h"
#include "Time/TimeUtils.h"
#include <iostream>

#ifdef DEBUG

void DebugUtils::Info(const std::string& msg)
{
	Log(msg, "Info", false);
}

void DebugUtils::Warn(const std::string& msg)
{
	Log(msg, "Warning!", false);
}

void DebugUtils::Crit(const std::string& msg)
{
	Log(msg, "Critical!", false);
}

void DebugUtils::Error(const std::string& msg)
{
	Log(msg, "Error!", false);
}

void DebugUtils::Todo(const std::string& msg)
{
	Log(msg, "TODO", false);
}

#else

void DebugUtils::Info(const std::string& msg) {}

void DebugUtils::Warn(const std::string& msg) {}

void DebugUtils::Crit(const std::string& msg) {}

void DebugUtils::Error(const std::string& msg) {}

void DebugUtils::Todo(const std::string& msg) {}

#endif // DEBUG

void DebugUtils::Log(const std::string msg, const char* additional, bool shouldWrite)
{
	//final message that will appear
	std::string fmsg;

	//construct final message
	fmsg.append("-");
	TimeUtils::GetDate(fmsg);
	fmsg.append("-");
	fmsg.append(additional);
	fmsg.append(":");
	fmsg.append(msg);

	if (shouldWrite)
	{

	}

	std::cout << fmsg << std::endl;
}