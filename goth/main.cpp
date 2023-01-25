#include <iostream>
#include <fstream>
#include <string>

std::string read_file(std::string path)
{
    std::ifstream file(path);
    std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return buffer;
}

// goth tests/test1.gt
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("too few arguments\n");
        return 1;
    }
    
    std::string source = read_file(argv[1]);
    if (source.empty())
    {
        printf("file not found\n");
        return 1;
    }
    printf("%s\n", source.c_str());
}