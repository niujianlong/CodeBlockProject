#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
//#pragma comment(lib, "pthreadVC2.lib")     //必须加上这句
sem_t empty;  //控制盘子里可放的水果数
sem_t cameraData;  //控制cameraData数
sem_t panoData; //控制panoData数
pthread_mutex_t work_mutex;                    //声明互斥量work_mutex
int my_index = 0;

void *procCamera(void *arg) //camera线程
          { 
             while(1){
                 sem_wait(&empty);     //占用一个盘子空间，可放水果数减1
                 pthread_mutex_lock(&work_mutex);     //加锁
                 printf("camera 输出第%d组数据!\n",my_index);
                 sem_post(&cameraData);     //释放一个cameraData信号了，可吃苹果数加1
                 pthread_mutex_unlock(&work_mutex);   //解锁
                 //sleep(3);
             }

           }
void *procPano(void *arg)  //Pano线程
          { 
            while(1){
				sem_wait(&cameraData);
                //sem_wait(&panoData);
                pthread_mutex_lock(&work_mutex);     //加锁
                printf("Pano 输出第%d组全景数据!\n",my_index);
                sem_post(&panoData);
                //sem_post(&empty);
                pthread_mutex_unlock(&work_mutex);   //解锁
                //sleep(4);
            }
           }
void *procRender(void *arg)  //Render线程
          { 
			
            while(1){
				double f = 0.123;
                //sem_wait(&cameraData);       //占用一个苹果信号量，可吃苹果数减1 
				sem_wait(&panoData);
                pthread_mutex_lock(&work_mutex);     //加锁
                printf("render 线程在渲染第%d组数据!\n",my_index);
				for(int i=0;i<0xffffff;i++)
				{
					f = f + (i);
					//printf("f=%f\n",f);
				}
				my_index++;
				//sem_post(&panoData);
                sem_post(&empty);       //吃了一个苹果，释放一个盘子空间，可放水果数加1
                pthread_mutex_unlock(&work_mutex);   //解锁
                //sleep(1);
            }
           }

void *procd(void *arg)  //daughter线程
          { 
            while(1){
                sem_wait(&panoData);
                pthread_mutex_lock(&work_mutex);     //加锁
                printf("女儿吃了一个橙子!\n");
                sem_post(&empty);
                pthread_mutex_unlock(&work_mutex);   //解锁
               // sleep(2);
            }

           }

void main()
{ 
    pthread_t camera;  //定义线程
    pthread_t pano;
    pthread_t Render;
    pthread_t daughter;

    sem_init(&empty, 0, 1);  //信号量初始化
    sem_init(&cameraData, 0, 0);
    sem_init(&panoData, 0, 0);
	pthread_mutex_init(&work_mutex, NULL);   //初始化互斥量

    pthread_create(&camera,NULL,procCamera,NULL);  //创建线程
    pthread_create(&pano,NULL,procPano,NULL);
    pthread_create(&Render,NULL,procRender,NULL);
    //pthread_create(&daughter,NULL,procd,NULL);

    //sleep(1000000000);
	while(1){}
}

