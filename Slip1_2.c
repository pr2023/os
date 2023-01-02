// To print 1st n lines and to print all lines
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

char comm[100],*ptr;
char *args[10];
int tot_arg;
int typeline( char *option, char *fname) 
{
	FILE *fp;
	int tot_lines,ch,n,cnt;
	fp= fopen(fname,"r");
	if( fp == NULL )
	{
		printf("\nUnable to open file");
		exit(0);
	}
	tot_lines = 0;
	ch = fgetc(fp);
	while ( ch != EOF )
	{
		if( ch == 10 ) 
		tot_lines++;
		ch = fgetc(fp);
	}
	fclose(fp);
	
	if( strcmp(option,"a")== 0 ) 
	{
		fp= fopen(fname,"r");
		ch = fgetc(fp);
		while ( ch != EOF )
		{
			printf("%c",ch);
			ch = fgetc(fp);
		}
		fclose(fp);
	}
	else
	if( option[0] =='+')
	{
		n = atoi(option+1);
		if( n > tot_lines)
		{	
			printf("\nInvalid  option");
			exit(0);
		}
		fp= fopen(fname,"r");
		cnt = 0;
		while( cnt < n )
		{
			ch = fgetc(fp);
			printf("%c",ch);
			if( ch == 10)
				cnt++;
		}
		fclose(fp);
	}
	else
	if( option[0] =='-') 
	{
		n = atoi(option+1);
		if( n > tot_lines)
		{	
			printf("\nInvalid  option");
			exit(0);
		}
		fp= fopen(fname,"r");
		cnt = 0;
		while( cnt < tot_lines -n )
		{
			ch = fgetc(fp);
			if( ch == 10)
				cnt++;
		}
		while( (ch=fgetc(fp)) != EOF )
			printf("%c",ch);
		fclose(fp);
	}
	else
	{
		printf("\nInvalid option");
		exit(0);
	}
	
	return(0);
} 
main()
{
	do
	{
		printf("myshell $ ");
		getcomm();
		sep_arg();
		take_action();
	}while(1);
} 

sep_arg()
{
	int i,j;
	i = j = tot_arg = 0;

	args[tot_arg] = (char*)malloc(sizeof(char) * 20);
	for(i=0; comm[i] !='\0' ; i++)
	{
		if( comm[i] == ' ')
		{
			args[tot_arg][j] = '\0';
			tot_arg++;
			args[tot_arg] = (char*)malloc(sizeof(char) * 20);	
			j=0;
		}
		else
		{
			args[tot_arg][j] =comm[i];
			j++;
		}
	} 
	
	args[tot_arg][j] = '\0';
 	return;
}



getcomm()
{
	int len;
	ptr = fgets(comm,80,stdin);
	len = strlen(comm);
	comm[len-1] = '\0';
	return;
} 

take_action()
{
	char str[100];
	pid_t   pid;
	int status;

	
	if(strcmp(args[0],"typeline") == 0 )
		typeline(args[1],args[2]);
	else
	if(strcmp(args[0],"quit") == 0 )
exit(0);
			
}
