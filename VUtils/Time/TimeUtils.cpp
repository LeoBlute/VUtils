#include "TimeUtils.h"
#include <ctime>

const std::string TimeUtils::GetDate()
{
	time_t t0 = time(0);
	char str[26];
	ctime_s(str, sizeof(str), &t0);
	std::string res = std::string(str);
	res.pop_back();
	return (res);
}

void TimeUtils::GetDate(std::string& str)
{
	time_t t0 = time(0);
	char cstr[26];
	ctime_s(cstr, sizeof(cstr), &t0);
	//str.append(std::string(cstr));
	str.append(cstr);
	str.pop_back();
}

const int TimeUtils::GetYear()
{
	time_t tNow = time(0);

	tm tmNow;
		localtime_s(&tmNow, &tNow);

	return tmNow.tm_year + 1900;
}

const int TimeUtils::GetMonth()
{
	time_t tNow = time(0);

	tm tmNow;
	localtime_s(&tmNow, &tNow);

	return tmNow.tm_mon + 1;
}

const int TimeUtils::GetHour()
{
	time_t tNow = time(0);

	tm tmNow;
	localtime_s(&tmNow, &tNow);

	return tmNow.tm_hour;
}

const int TimeUtils::GetMonthDay()
{
	time_t tNow = time(0);

	tm tmNow;
	localtime_s(&tmNow, &tNow);

	return tmNow.tm_mday;
}

const int TimeUtils::GetYearDay()
{
	time_t tNow = time(0);

	tm tmNow;
	localtime_s(&tmNow, &tNow);

	return tmNow.tm_yday;
}

const int TimeUtils::GetMinutes()
{
	time_t tNow = time(0);

	tm tmNow;
	localtime_s(&tmNow, &tNow);

	return tmNow.tm_min;
}

const int TimeUtils::GetSeconds()
{
	time_t tNow = time(0);

	tm tmNow;
	localtime_s(&tmNow, &tNow);

	return tmNow.tm_sec;
}