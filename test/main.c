#include <stdio.h>
#include <sys/select.h>
#include <fcntl.h>
#define BUF_SIZE 16 
int main()
{
	printf("hello world!\n") ;
	int fd ;
	char buf[BUF_SIZE] ;
	int count =-1 ;
	fd_set rfds,wfds ;
	if((fd=open("/dev/globalfifo",O_RDONLY | O_NONBLOCK))<0){
		printf("%s:open globalfifo failed!\n",__func__) ;
		return -1 ;
	}
	while(1){
		FD_ZERO(&rfds) ;
		FD_ZERO(&wfds) ;
		FD_SET(fd,&rfds) ;
		//FD_SET(fd,&wfds) ;
		
		select(fd+1,&rfds,&wfds,NULL,NULL) ;
//		select(fd,&rfds,NULL,NULL,NULL) ;
		if(FD_ISSET(fd,&rfds)){
			printf("%s:globalfifo have data to read!\n",__func__) ;
			printf("read.......\n") ;
			if((count=read(fd,buf,BUF_SIZE))>0){
				printf("read:%s:\n",buf) ;
			}
		}
/*	
		if(FD_ISSET(fd,&wfds)){
			printf("%s:globalfifo have space to write!\n",__func__) ;
		}
*/
	}
	return 0 ;
}
