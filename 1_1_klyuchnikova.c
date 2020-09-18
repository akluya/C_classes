#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])//1-й - имя программы, 2-й - имя файла
{
    pid_t pid;
    double a;
    char name[50], str[50];
    FILE *file;


    if( !(file = fopen(argv[1], "r")) ) //"r" - на чтение
    {
        perror("error");//ошибка
        exit(1);
    }
    while(fgets(str, 50, file))
    {
        sscanf(str, "%lf %s", &a, name);//обраюатывает строку из файла
        if((pid = fork()) == 0)
        {
            sleep(a);
            execl(name, name, (char *) NULL);
            exit(0);
        }
        else if(pid == -1)
        {
            perror("error");
            exit(1);
        }
    }

    fclose(file);
    return 0;
}
