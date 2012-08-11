#include <stdio.h>
#include <pthread.h>
#define true 1
#define false 0
static inline unsigned int clp2(unsigned int x)
{
    x = x - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >>16);
    return x + 1;
}
int count=0 ;
pthread_mutex_t mutex ;
pthread_mutex_t wait_all_start;
pthread_cond_t condition ;

pthread_mutex_t thrd1_wait ;
pthread_cond_t thrd1_ready ;
pthread_mutex_t thrd2_wait ;
pthread_cond_t thrd2_ready ;

pthread_t thrd1 ;
pthread_t thrd2 ;
int all_threads_start=false ;
int b_thrd1_ready=false ;
int b_thrd2_ready=false ;
void *thread_fun1(void *param)
{
    b_thrd1_ready=true ;
    pthread_mutex_lock(&wait_all_start) ;
    while(!all_threads_start){/*avoid*/
        pthread_cond_wait(&condition,&wait_all_start) ;
    }
    pthread_mutex_unlock(&wait_all_start) ;
    int a=0 ;
    while(a++!=10)
    {
        pthread_mutex_lock(&mutex) ;
        printf("%s:count=%d\n",__func__,count++) ;
        pthread_mutex_unlock(&mutex) ;
        sleep(1);
    }
}
void *thread_fun2(void *param)
{
    b_thrd2_ready=true ;

    pthread_mutex_lock(&wait_all_start) ;
    while(!all_threads_start){
        pthread_cond_wait(&condition,&wait_all_start) ;
    }
    pthread_mutex_unlock(&wait_all_start) ;
    int a=0 ;
    while(a++!=10)
    {
        pthread_mutex_lock(&mutex) ;
        printf("%s:count=%d\n",__func__,count++) ;
        pthread_mutex_unlock(&mutex) ;
        sleep(1) ;
    }
}
int main()
{
    pthread_mutex_init(&mutex,NULL) ;
    pthread_mutex_init(&wait_all_start ,NULL) ;
    pthread_cond_init(&condition,NULL) ;

    b_thrd1_ready=false ;
    b_thrd2_ready=false ;
    all_threads_start=false ;

    if(pthread_create(&thrd1,NULL,thread_fun1,NULL)!=0){
        printf("Create Thread 1 Failed!\n") ;
        return -1 ;
    }
    if(pthread_create(&thrd2,NULL,thread_fun2,NULL)!=0){
        printf("Create Thread 2 Failed!\n") ;
        return -1 ;
    }
    printf("Create two thread done.....\n") ;

    while(true){
        pthread_mutex_lock(&wait_all_start) ;
        printf("main thread......\n") ;
        if(b_thrd1_ready&&b_thrd2_ready){
            printf("all threads ready......\n") ;
            all_threads_start=true ;
            pthread_cond_broadcast(&condition);
            //pthread_cond_signal(&condition) ;
	    pthread_mutex_unlock(&wait_all_start) ;
            break ;
        }
        sleep(100);
        pthread_mutex_unlock(&wait_all_start) ;
    }
    pthread_join(thrd1,NULL) ;
    pthread_join(thrd2,NULL) ;
    printf("\ncount=%d\n",count) ;
    return 0 ;
}
