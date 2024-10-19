#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void count(char t2, char *t3)
{
    int c, w, l, fh = open(t3, 'R');
    char ch;
    c = 0;
    w = 0;
    l = 0;

    if (fh < 0)
        printf("error in opening the file");
    else
    {
        while (read(fh, &ch, 1) != 0)
        {
            c++;
            if (ch == '\n' || ch == ' ' || ch == '\t')
                w++;
            if (ch == '\n')
                l++;
        }

        if (t2 == 'c')
            printf("Character count:%d\n", c);
        if (t2 == 'w')
            printf("Word count:%d\n", w);
        if (t2 == 'l')
            printf("Line count:%d\n", l);
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
            if (strcmp(t1, "count") == 0)
                count(t2[0], t3);
            break;
        }
    }
    return 0;
}
