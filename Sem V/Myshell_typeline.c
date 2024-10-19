#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void typeline(char *t2, char *t3)
{
    int n, l;
    int fh = open(t3, O_RDONLY);
    char ch;
    l = 0;

    if (strcmp(t2, "a") == 0)
    {
        while (read(fh, &ch, 1) != 0)
        {
            printf("%c", ch);
        }
    }

    n = atoi(t2);
    if (n > 0)
    {
        while (read(fh, &ch, 1) != 0)
        {
            if (ch == '\n')
                l++;

            if (n == l)
                break;

            printf("%c", ch);
        }
    }
    if (n < 0)
    {
        int ln = 0;
        while (read(fh, &ch, 1) != 0)
        {
            if (ch == '\n')
                l++;
        }

        lseek(fh, 0, SEEK_SET);

        while (read(fh, &ch, 1) != 0)
        {
            if (ch == '\n')
                ln++;

            if (ln == l + n)
                break;
        }

        while (read(fh, &ch, 1) != 0)
            printf("%c", ch);
    }
    close(fh);
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
            if (strcmp(t1, "typeline") == 0)
                typeline(t2, t3);
            break;
        }
    }
    return 0;
}
