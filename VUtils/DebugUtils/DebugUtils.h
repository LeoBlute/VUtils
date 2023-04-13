#pragma once
#include <string>

class DebugUtils
{
public:
	DebugUtils() = delete;
	static void Info(const std::string& msg);
	static void Warn(const std::string& msg);
	static void Crit(const std::string& msg);
	static void Error(const std::string& msg);
	static void Todo(const std::string& msg);
private:
	static void Log(const std::string msg, const char* additional, bool shouldWrite);
};

#define DEBUG_INFO(MSG) DebugUtils::Info(MSG);
#define DEBUG_WARN(MSG) DebugUtils::Warn(MSG);
#define DEBUG_CRIT(MSG) DebugUtils::Crit(MSG);
#define DEBUG_ERROR(MSG) DebugUtils::Error(MSG);\
__debugbreak();
#define DEBUG_TODO(MSG) DebugUtils::Todo(MSG);