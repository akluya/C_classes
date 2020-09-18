#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int ph[2], pn[2], num, i, j, n;
	pid_t pid;
	char a[1024], b[1024], tmp;
	FILE *queue;


	if(argc != 4)
	{
		printf("no input files\n");
		exit(1);
	}
	scanf("%d", &n);
	if(pipe(ph) == -1)
	{
		perror("pipe");
		exit(1);
	}
	if(pipe(pn) == -1)
	{
		perror("pipe");
		exit(1);
	}
	if((pid = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}
	j = 1;
	if(pid == 0)
	{
		close(ph[0]);
		close(pn[1]);
		if( !(queue = fopen(argv[3], "r")) )
		{
       		perror("file");
        	exit(1);
    	}
    	while(fgets(b, 1024, queue) != NULL)
    	{
    		sscanf(b, "%s : %d\n", a, &num);
    		strcat(a, "\n");
    		for(i = 0 ; i < num ; i ++)
			{
				printf("%d: Washing... %s", j, a);
				sleep(getTime(a, argv[1]));
				printf("%d: \t%s\tis washed!\n", j, a);

				read(pn[0], &tmp, 1);
				printf("%d: \t\t%s\t\tis put!\n", j++, a);
				write(ph[1], a, strlen(a));
			}
		}
		write(ph[1], "\0", 1);
		fclose(queue);
	}
	else
	{
		close(ph[1]);
		close(pn[0]);
		for(i = 0 ; i < n ; i ++)
			write(pn[1], "\1", 1);
        while(read(ph[0], a, 1) > 0)
        {
        	while(read(ph[0], &tmp, 1), tmp != '\n')
        		strcat(a, &tmp);
			if(!strcmp(a,"\0"))
				return;
			strcat(a, "\n");
			printf("%d: Cleaning... %s", j, a);
			write(pn[1], "\1", 1);
			sleep(getTime(a, argv[2]));
        	printf("%d: \t%s\ready!\n", j++, a);

        	a[1] = '\0';
        }
	}

	return 0;
}

int getTime(char *a, char *file)
{
	FILE *f;
	char str[1024], tmp[1024];
	int time;

	if( !(f = fopen(file, "r")) )
	{
       	perror("file");
        exit(1);
    }
	while(fgets(str, 1024, f) != NULL)
	{
		sscanf(str, "%s : %d\n", tmp, &time);
		strcat(tmp, "\n");
		if(!strcmp(a, tmp))
			return time;
	}
	fclose(f);
	return 0;
}
