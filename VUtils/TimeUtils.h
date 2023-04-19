#pragma once
#include <string>
#include <ctime>

namespace TimeUtils {
	const std::string GetDate()
	{
		time_t t0 = time(0);
		char str[26];
		ctime_s(str, sizeof(str), &t0);
		std::string res = std::string(str);
		res.pop_back();
		return (res);
	}

	void GetDateToStr(std::string& str)
	{
		time_t t0 = time(0);
		char cstr[26];
		ctime_s(cstr, sizeof(cstr), &t0);
		str.append(cstr);
		str.pop_back();
	}

	const int GetYear()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_year + 1900;
	}

	const int GetMonth()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_mon + 1;
	}

	const int GetHour()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_hour;
	}

	const int GetMonthDay()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_mday;
	}

	const int GetYearDay()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_yday;
	}

	const int GetMinutes()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_min;
	}

	const int GetSeconds()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_sec;
	}
}
