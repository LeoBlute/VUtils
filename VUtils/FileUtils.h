#pragma once

#include "DebugUtils.h"
#include <fstream>

namespace FileUtils {
    //Load content of a file to a char* and returns it
    char* CPReadFile(const char* path)
    {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            DEBUG_CRIT("Unable to open file");
        }

        //Get the size of the file
        file.seekg(0, std::ios::end);
        std::streampos fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        //Allocate a char* to hold the file data
        std::size_t size = static_cast<std::size_t>(fileSize) + 1;
        char* buffer = new char[size];

        //Read the file into the buffer
        file.read(buffer, fileSize);
        buffer[fileSize] = '\0';

        //Close file
        file.close();

        return buffer;
    }

    //Load content of a file to a std::string and returns it
    std::string StrReadFile(const char* path)
    {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            DEBUG_CRIT("Unable to open file");
        }

        //get the size of the file
        file.seekg(0, std::ios::end);
        std::streampos fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        //makes a std::string to hold the file data
        std::string data;
        data.resize(static_cast<std::size_t>(fileSize));

        //Read the file into the string
        file.read(&data[0], fileSize);

        //Close file
        file.close();

        return data;
    }
}