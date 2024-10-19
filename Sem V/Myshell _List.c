#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void list(char t2, char *t3)
{
    int dc = 0, fc = 0, n, i, f;
    DIR *dp = opendir(t3);
    struct dirent *dep;

    while ((dep = readdir(dp)) != NULL)
    {
        if (t2 == 'f')
        {
            if (dep->d_type == DT_REG)
                printf("%s\n", dep->d_name);
        }
        else if (t2 == 'i')
        {
            if (dep->d_type == DT_REG)
                printf("%s\t%ld\n", dep->d_name, dep->d_fileno);
        }
        else if (t2 == 'n')
        {
            if (dep->d_type == DT_DIR)
                dc++;
            if (dep->d_type == DT_REG)
                fc++;
        }
    }

    if (t2 == 'n')
        printf("%d File(s) %d Dir(s)\n", fc, dc);

    closedir(dp);
}

int main()
{
    char cmd[80], t1[10], t2[10], t3[10], t4[10];
    int n, fh;
    while (1)
    {
        printf("Myshell$:");
        fflush(stdin);
        fgets(cmd, 80, stdin);
        n = sscanf(cmd, "%s%s%s%s", &t1, &t2, &t3, &t4);
        switch (n)
        {
        case 3:
            if (strcmp(t1, "list") == 0)
                list(t2[0], t3);
            break;
        }
    }
    return 0;
}
