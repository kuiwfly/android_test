#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#define DEVICE_NAME "/dev/globalfifo"
#define BUF_SIZE 64

#ifndef BOOLEAN
#define BOOLEAN
#define true 1
#define false 0 
#endif

char buf[BUF_SIZE] ;

pthread_mutex_t mutex_buf ;
pthread_cond_t signal_print ;

pthread_t fd_thrd1 ;
pthread_t fd_thrd2 ;
pthread_t fd_thrd3 ;
pthread_t fd_thrd4 ;
pthread_t fd_thrd5 ;
int b_thread1_ready = false ;
int b_thread2_ready = false ;
int b_thread3_ready = false ;
int b_thread4_ready = false ;
int b_thread5_ready = false ;
void *thrd1_fun(void *param) ;
void *thrd2_fun(void *param) ;
void *thrd3_fun(void *param) ;
void *thrd4_fun(void *param) ;
void *thrd5_fun(void *param) ;
int b_print_ready = false ;

void run_parent_process() ;
void run_child_process() ;
int main()
{
	pid_t pid=fork() ;
	if(pid==0){
		run_child_process() ;
	}else if(pid>0){
		printf("Create child process successfully!\n") ;
		run_parent_process() ;
	}else{
		printf("Create child process failed!\n") ;
		return -1 ;
	}
	return 0 ;
}
void run_child_process()
{
	int fd=-1 ;
	pthread_mutex_init(&mutex_buf,NULL) ;
	pthread_cond_init(&signal_print,NULL) ;
	if(pthread_create(&fd_thrd1,NULL,thrd1_fun,NULL)!=0){
		printf("%s:create thread 1 failed!\n",__func__) ;
		return ;
	}
	if(pthread_create(&fd_thrd2,NULL,thrd2_fun,NULL)!=0){
		printf("%s:create thread 2 failed!\n",__func__) ;
		return ;
	}
	if(pthread_create(&fd_thrd3,NULL,thrd3_fun,NULL)!=0){
		printf("%s:create thread 3 failed!\n",__func__) ;
		return ;
	}
	if(pthread_create(&fd_thrd4,NULL,thrd4_fun,NULL)!=0){
		printf("%s:create thread 4 failed!\n",__func__) ;
		return ;
	}
	if(pthread_create(&fd_thrd5,NULL,thrd5_fun,NULL)!=0){
		printf("%s:create thread 5 failed!\n",__func__) ;
		return ;
	}
	
	if((fd=open(DEVICE_NAME,O_RDONLY))<0){
		printf("%s:open device failed!\n",__func__) ;
		return ;
	}
	while(true){
		while(true){
			if(b_thread1_ready && b_thread2_ready &&
				b_thread3_ready && b_thread4_ready &&
				b_thread5_ready)	{

				pthread_mutex_lock(&mutex_buf) ;
				memset(buf,0,BUF_SIZE) ;
				read(fd,buf,BUF_SIZE) ;
				printf("%s:read ready!\n",__func__) ;
				b_thread1_ready = false ;
				b_thread2_ready = false ;
				b_thread3_ready = false ;
				b_thread4_ready = false ;
				b_thread5_ready = false ;				
				pthread_cond_broadcast(&signal_print) ;
				pthread_mutex_unlock(&mutex_buf) ;
				break ;
			}	
			usleep(10) ;
		}
	}
	close(fd) ;
	pthread_join(&fd_thrd1,NULL) ;
	pthread_join(&fd_thrd2,NULL) ;
	pthread_join(&fd_thrd3,NULL) ;
	pthread_join(&fd_thrd4,NULL) ;
	pthread_join(&fd_thrd5,NULL) ;
}
void run_parent_process()
{
	int fd=-1 ;
	int count=0 ;
	if((fd=open(DEVICE_NAME,O_WRONLY))<0){
		printf("%s:open device failed!\n",__func__) ;
		return ;
	}
	while(true){
		sprintf(buf,"count=%d\n",count++) ;
		write(fd,buf,BUF_SIZE) ;
		//sleep(1) ;
	}
	close(fd) ;
}
void *thrd1_fun(void *param) 
{
	b_thread1_ready = true ;
	while(true){
		pthread_mutex_lock(&mutex_buf) ;
		while(b_thread1_ready){
			pthread_cond_wait(&signal_print,&mutex_buf) ;
		}
		printf("%s:%s\n",__func__,buf) ;
		b_thread1_ready = true ;
		pthread_mutex_unlock(&mutex_buf) ;
	}	
}
void *thrd2_fun(void *param)
{
	b_thread2_ready = true ;
	while(true){
		pthread_mutex_lock(&mutex_buf) ;
		while(b_thread2_ready){
			pthread_cond_wait(&signal_print,&mutex_buf) ;
		}
		printf("%s:%s\n",__func__,buf) ;
		b_thread2_ready = true ;
		pthread_mutex_unlock(&mutex_buf) ;
	}	
}
void *thrd3_fun(void *param)
{
	b_thread3_ready = true ;
	while(true){
		pthread_mutex_lock(&mutex_buf) ;
		while(b_thread3_ready){
			pthread_cond_wait(&signal_print,&mutex_buf) ;
		}
		printf("%s:%s\n",__func__,buf) ;
		b_thread3_ready = true ;
		pthread_mutex_unlock(&mutex_buf) ;
	}	
}
void *thrd4_fun(void *param) 
{
	b_thread4_ready = true ;
	while(true){
		pthread_mutex_lock(&mutex_buf) ;
		while(b_thread4_ready){
			pthread_cond_wait(&signal_print,&mutex_buf) ;
		}
		printf("%s:%s\n",__func__,buf) ;
		b_thread4_ready = true ;
		sleep(1) ;
		pthread_mutex_unlock(&mutex_buf) ;
	}	
}
void *thrd5_fun(void *param) 
{
	b_thread5_ready = true ;
	while(true){
		pthread_mutex_lock(&mutex_buf) ;
		while(b_thread5_ready){
			pthread_cond_wait(&signal_print,&mutex_buf) ;
		}
		printf("%s:%s\n",__func__,buf) ;
		b_thread5_ready = true ;
		pthread_mutex_unlock(&mutex_buf) ;
	}	
}
