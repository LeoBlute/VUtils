#pragma once
#include "TimeUtils.hpp"
#include "ANSICode.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <ostream>



namespace DebugUtils {
    template<typename T>
    constexpr static inline void AddToStream
    (std::ostream& stream, const T& arg)
    {
        stream << arg;
    }

    template<typename T, typename ...Args>
    constexpr static inline void AddToStream
    (std::ostream& stream, const T& arg, const Args&... args)
    {
        stream << arg;
        AddToStream(stream, args...);
    }

    template <typename... Args>
    static void Log(bool toFile, ANSICode ansiCode, Args... msg)
    {
        //final message that will appear
        std::string fmsg;
        //construct final message beginning text
        fmsg.append("-");
        TimeUtils::GetDateToStr(fmsg); //date
        std::ostringstream stream;
        AddToStream(stream, msg...);
        fmsg.append(stream.str());

        //if toFile is true it will write the log to a new file
        if (toFile)
        {
            std::fstream f; //file

            //Path + file name
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

            //if directory Logs doesn't exists,it creates
            if (!std::filesystem::is_directory("Logs"))
            {
                std::filesystem::create_directory("Logs");
            }

            //Write to file
            f.open(fileName.c_str(), std::ios::app | std::ios::binary); //open
            f << fmsg; //send log to file
            f.close(); //close
        }

        //Log final message to console
        std::cout << ANSICodeToCStr(ansiCode) << fmsg << ANSICodeToCStr(ANSICode::Reset) << std::endl;
    }
}

#ifdef DEBUG
    //Log to console only
    #define DEBUG_INFO(...) DebugUtils::Log(false, ANSICode::Reset, "-Info:", __VA_ARGS__);
    #define DEBUG_WARN(...) DebugUtils::Log(false, ANSICode::BrightYellow,"-Warning:", __VA_ARGS__);
    #define DEBUG_ERROR(...) DebugUtils::Log(false, ANSICode::BrightRed, "-Error:", __VA_ARGS__);\
    __debugbreak();
    #define DEBUG_TODO(...) DebugUtils::Log(false, ANSICode::Reset, "-TODO:", __VA_ARGS__);
    
    //Log to console and write to file
    #define DEBUG_FILE_INFO(...) DebugUtils::Log(true, ANSICode::Reset, "-Info:", __VA_ARGS__);
    #define DEBUG_FILE_WARN(...) DebugUtils::Log(true, ANSICode::BrightYellow, "-Warning:", __VA_ARGS__);
    #define DEBUG_FILE_ERROR(...) DebugUtils::Log(true, ANSICode::BrightRed, "-Erro:", __VA_ARGS__);\
    __debugbreak();
    #define DEBUG_FILE_TODO(...) DebugUtils::Log(true, ANSICode::Reset, "-TODO:", __VA_ARGS__);

#else
//Log to console only
    #define DEBUG_INFO(...)
    #define DEBUG_WARN(...)
    #define DEBUG_CRIT(...)
    #define DEBUG_ERROR(...)
    #define DEBUG_TODO(...)

//Log to console and write to file
    #define DEBUG_FILE_INFO(...) 
    #define DEBUG_FILE_WARN(...) 
    #define DEBUG_FILE_CRIT(...)
    #define DEBUG_FILE_ERROR(...)
    #define DEBUG_FILE_TODO(...)
#endif // DEBUG