#pragma once

#include "TimeUtils.h"
#include <iostream>
#include <type_traits>
#include <filesystem>
#include <fstream>

namespace DebugUtils {
    template <typename T>
    static inline void Log(T& msg, const char* additional, bool toFile)
    {
        //final message that will appear
        std::string fmsg;

        //construct final message
        fmsg.append("-");
        TimeUtils::GetDateToStr(fmsg);
        fmsg.append(additional);

        if constexpr (std::is_arithmetic_v<T> || std::is_same_v<T, std::string> || std::is_same_v<T, const char*> || std::is_same_v<T, char*> ||
            std::is_array_v<T> && std::is_same_v<std::remove_extent_t<T>, const char> || std::is_array_v<T> && std::is_same_v<std::remove_extent_t<T>, char>)
        {
            fmsg.append(msg);
        }
        else if constexpr (std::is_same_v<T, std::string*>)
        {
            fmsg.append(msg->c_str());
        }
        else
        {
            fmsg.append("Non printable variable variable not log variable");
        }

        if (toFile)
        {
            std::fstream f;
            std::string fileName = "Logs\\Log-";

            TimeUtils::GetDateToStr(fileName);

            for (char& c : fileName)
            {
                if (c == ' ' || c == ':')
                {
                    c = '-';
                }
            }

            fileName.append(".txt");

            if (!std::filesystem::is_directory("Logs"))
            {
                std::filesystem::create_directory("Logs");
            }

            f.open(fileName.c_str(), std::ios::app | std::ios::binary);
            f << fmsg;
            f.close();
        }

        std::cout << fmsg << std::endl;

    }
}

//Print to console only
#define DEBUG_INFO(MSG) DebugUtils::Log(MSG, "-Info:", false);
#define DEBUG_WARN(MSG) DebugUtils::Log(MSG, "-Warning:", false);
#define DEBUG_CRIT(MSG) DebugUtils::Log(MSG, "-Critical:", false);
#define DEBUG_ERROR(MSG) DebugUtils::Log(MSG, "-Error:", false);\
__debugbreak();
#define DEBUG_TODO(MSG) DebugUtils::Log(MSG, "-TODO:", false);

//Print to console and write to file
#define DEBUG_FILE_INFO(MSG) DebugUtils::Log(MSG, "-Info:", true);
#define DEBUG_FILE_WARN(MSG) DebugUtils::Log(MSG, "-Warning:", true);
#define DEBUG_FILE_CRIT(MSG) DebugUtils::Log(MSG, "-Critical:", true);
#define DEBUG_FILE_ERROR(MSG) DebugUtils::Log(MSG, "-Error:", true);\
__debugbreak();
#define DEBUG_FILE_TODO(MSG) DebugUtils::Log(MSG, "-TODO:", true);