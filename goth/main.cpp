#include <stdio.h>

char* read_file(const char* path)
{
    FILE* file;
    fopen_s(&file, path, "rb");
    if (!file)
    {
        printf("could not open file '%s'\n", path);
        return 0;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buf = new char[size + 1];
    fread(buf, 1, size, file);
    buf[size] = '\0';

    fclose(file);
    return buf;
}

// goth tests/test1.gt
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("too few arguments\n");
        return 1;
    }
    
    char* source = read_file(argv[1]);
    printf("%s\n", source);
    delete source;
}