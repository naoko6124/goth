#pragma once
#include "pch.h"

std::string read_file(std::string path)
{
    std::ifstream file(path);
    std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer += '\0';
    return buffer;
}