#pragma once
#include <string>
#include <ctime>

namespace TimeUtils {
	//Complete date
	const std::string GetDate()
	{
		time_t t0 = time(0);
		char str[26];
		ctime_s(str, sizeof(str), &t0);
		std::string res = std::string(str);
		res.pop_back();
		return (res);
	}

	//Complete date directly appended to a std::string for performance purposes
	void GetDateToStr(std::string& str)
	{
		time_t t0 = time(0);
		char cstr[26];
		ctime_s(cstr, sizeof(cstr), &t0);
		str.append(cstr);
		str.pop_back();
	}

	//Year
	const int GetYear()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_year + 1900;
	}

	//Month
	const int GetMonth()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_mon + 1;
	}

	//Hour
	const int GetHour()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_hour;
	}

	//Day of the month
	const int GetMonthDay()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_mday;
	}

	//Day of the year
	const int GetYearDay()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_yday;
	}

	//Current minutes of the hour
	const int GetMinutes()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_min;
	}

	//Current seconds of the minute
	const int GetSeconds()
	{
		time_t tNow = time(0);

		tm tmNow;
		localtime_s(&tmNow, &tNow);

		return tmNow.tm_sec;
	}
}
