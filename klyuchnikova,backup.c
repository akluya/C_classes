#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

void compress(char path[1024])
{
    DIR *dir;
    pid_t pid;
    struct dirent *rsd;
    int i = 0, l, stat;
    char tmp[1024], files[1024][1024];

    dir = opendir(path);
    while((rsd = readdir(dir)))
    {
        if(!strcmp(rsd->d_name, ".") || !strcmp(rsd->d_name, ".."))
            continue;
        strcpy(tmp, path); strcat(tmp, rsd->d_name);
        if(rsd->d_type == 4)
        {
            strcat(tmp, "/");
            compress(tmp);
        }
        else
        {
            strcpy(files[i++], tmp);
        }
    }
    closedir(dir);

    for(l = i, i = 0 ; i < l ; i++)
    {
        if(!(pid = fork()))
        {
            execl("/bin/gzip", "/bin/gzip", "-q", files[i], (char *) NULL);
            exit(0);
        }
        waitpid(pid, &stat, 0);
    }
}

void decompress(char path[1024])
{
    DIR *dir;
    struct dirent *rsd;
    int i = 0, l, stat;
    char tmp[1024], files[1024][1024];

    dir = opendir(path);
    while((rsd = readdir(dir)))
    {
        if(!strcmp(rsd->d_name, ".") || !strcmp(rsd->d_name, ".."))
            continue;
        strcpy(tmp, path);
        strcat(tmp, rsd->d_name);
        if(rsd->d_type == 4)
        {
            strcat(tmp, "/");
            decompress(tmp);
        }
        else
        {
            if(!strcmp(&tmp[strlen(tmp) - 3], ".gz"))
                strcpy(files[i++], tmp);
        }
    }
    closedir(dir);

    for(l = i, i = 0 ; i < l ; i++)
    {
        if(!fork())
        {
            execl("/bin/gzip", "/bin/gzip", "-d", "-q", "-f", files[i], (char *) NULL);
            exit(0);
        }
    }
}

int intcpy(char *srcfilename, char *destfilename)
{
    FILE *fsrc, *fdest;
    struct stat st;
    __time_t srcmod, destmod;
    char strsrc[1024];

    stat(srcfilename, &st);
    srcmod = st.st_mtime;
    stat(destfilename, &st);
    destmod = st.st_mtime;

    if((long)srcmod < (long)destmod)
    {
        return 0;
    }

    if( !(fsrc = fopen(srcfilename, "r")) )
    {
        printf("Cant read src file\n");
        return 1;
    }

    if( !(fdest = fopen(destfilename, "w")) ){
        printf("Cant read dest file\n");
        return 1;
    }

    while(fgets(strsrc, 1024, fsrc))
    {
        fputs(strsrc, fdest);
    }

    fclose(fdest);
    fclose(fsrc);
    return 0;
}

int backupdir(char *srcdirname, char *destdirname)
{
    DIR *srcdir;
    struct dirent *rsd;
    int i;
    char tmpsrc[1024], tmpdest[1024];

    srcdir = opendir(srcdirname);
    while((rsd = readdir(srcdir)))
    {
        if(!strcmp(rsd->d_name, ".") || !strcmp(rsd->d_name, ".."))
            continue;


        strcpy(tmpsrc, srcdirname); strcat(tmpsrc, rsd->d_name);
        strcpy(tmpdest, destdirname); strcat(tmpdest, rsd->d_name);
        if(rsd->d_type == 4)
        {
            strcat(tmpsrc, "/");
            strcat(tmpdest, "/");
            mkdir(tmpdest, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            backupdir(tmpsrc, tmpdest, n+1);
        }
        else
        {
            intcpy(tmpsrc, tmpdest);
        }
    }
    closedir(srcdir);
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Use: backup [source_file] [destination_file]\n");
        return 0;
    }

    decompress(argv[2]);
    backupdir(argv[1], argv[2]);
    compress(argv[2]);

    return 0;
}

