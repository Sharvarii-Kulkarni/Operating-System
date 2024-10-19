#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void search(char t2, char *t3, char *t4)
{
    int l, j, i, count;
    int fh = open(t4, O_RDONLY);
    char buff[80];
    char ch, *q;
    l = 1;
    j = 0;
    i = 0;
    count = 0;

    if (t2 == 'f')
    {
        while (read(fh, &ch, 1) != 0)
        {
            buff[j++] = ch;
            if (ch == '\n')
            {
                q = strstr(buff, t3);
                if (q != NULL)
                {
                    printf("%d\n", l);
                    printf("%s\n", buff);
                    break;
                }
                l++;
                for (i = 0; i < 80; i++)
                    buff[i] = '';
                j = 0;
            }
        }
    }
    else if (t2 == 'a')
    {
        while (read(fh, &ch, 1) != 0)
        {
            buff[j++] = ch;
            if (ch == '\n')
            {
                buff[j] = '\0';
                j = 0;
                q = buff;
                while (q = strstr(q, t3))
                {
                    if (q != NULL)
                    {
                        printf("%d\n", l);
                        printf("%s\n", buff);
                    }
                }
                l++;
                for (i = 0; i < 80; i++)
                    buff[i] = ' ';
                j = 0;
            }
        }
    }
    else if (t2 == 'c')
    {
        while (read(fh, &ch, 1))
        {
            if (ch == '\n')
            {
                buff[j] = '\0';
                j = 0;
                q = buff;
                while (q = strstr(q, t3))
                {
                    count++;
                    q++;
                }
            }
            else
            {
                buff[j++] = ch;
            }
        }
        printf("Total occurrences=%d\n", count);
        printf("%s\n", buff);
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
        case 4:
            if (strcmp(t1, "search") == 0)
                search(t2[0], t3, t4);
            break;
        }
    }
    return 0;
}
