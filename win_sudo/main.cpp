#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        system("cmd");
    }
    else
    {
        const char* PREFIX = "cmd /c";
        const char* SUFFIX = " & pause";
        int length = strlen(PREFIX) + strlen(SUFFIX);
        for (int i = 1; i < argc; i++)
        {
            length += 1 + strlen(argv[i]);
        }

        char* cmd = (char*)malloc(sizeof(char) * length);
        cmd[0] = NULL;
        strcpy(cmd, PREFIX);
        for (int i = 1; i < argc; i++)
        {
            strcat(cmd, " ");
            strcat(cmd, argv[i]);
        }
        strcat(cmd, SUFFIX);
        system(cmd);
    }
    return 0;
}
