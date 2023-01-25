#include "pch.h"
#include "core/utils.h"
#include "core/lexer.h"

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

    std::vector<token> tokens = lexer::tokenize(source);
}