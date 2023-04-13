#pragma once
#include <string>
class TimeUtils
{
public:
	TimeUtils() = delete;
	static const std::string GetDate();
	static void GetDate(std::string& str);

	static const int GetYear();
	static const int GetMonth();
	static const int GetHour();
	static const int GetMonthDay();
	static const int GetYearDay();
	static const int GetMinutes();
	static const int GetSeconds();
};