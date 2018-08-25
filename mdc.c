#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int fd,i,j,flag=0,count;
	char *ma=NULL;
	ma=(char*)realloc(ma,sizeof(char)*1);
	if(!ma)
	{
		perror("realloc");
		return -1;
	}
	char ch;
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
	 perror("open");
	 return -1;	
	}
	count=1;
	i=0;
	while(count)
	{
	 count=read(fd,&ch,1);
	 if(ch==10)
	 {
	  break;	
	 }
	 else
	 {
	  for(j=0;j<=i;j++)
	  {
		if(ch == *(ma+j))
		{
			flag=1;
			break;
		}
	  }
	 if(flag==0)
	  {	ma = (char *) realloc(ma,sizeof(char)*(i+1));
		if(!ma)
		{
			perror("realloc");
			return -1;
		}
	  	*(ma+i)=ch;
	  	i++;
	  	flag=0;
	  }
	 }
	flag=0;
	}
	*(ma+i)='\0';
	printf("%s\n",ma);
return 0;
}
