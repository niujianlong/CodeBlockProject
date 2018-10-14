/*
 * CS360: preempt1.c
 * Jim Plank
 */

#include <stdio.h>
#include <pthread.h>
 #include <unistd.h>

int cameraData = 0;
int panoData = 0;


void *cameraloop(void *x)
{
  double f;
  int i, j, *id;
 
  id = (int *) x;

  for (i = 0; i >= 0; i++) {
    printf("thread %d.  i = %10d\n", *id, i);
    f = 1;
	  #if 0
    for (j = 0; j < 90000; j++) {
      f = f*.99;
    }
	  #endif
	  //usleep(500000);
  }
  return NULL;
}


void *panoloop(void *x)
{
  double f;
  int i, j, *id;
 
  id = (int *) x;

  for (i = 0; i >= 0; i++) {
    printf("thread %d.  i = %10d\n", *id, i);
    f = 1;
	  #if 0
    for (j = 0; j < 90000; j++) {
      f = f*.99;
    }
	  #endif
	  //usleep(500000);
  }
  return NULL;
}

void *mainloop(void *x)
{
  while(1)
	{
		printf("main mthread---------------***************************-----------------run !\n");
		double a = 0.02345673;
	  #if 1
		for(int i =0;i<0xfffffff;i++)
		{
			a= a*i;
		}
	  #endif
	}
  return NULL;
}

main()
{
  pthread_t t[3];
  int i[3];
  void *retval;

  i[0] = 0;
  i[1] = 1;
  i[2] = 2;

  pthread_create(t, NULL, infloop, i);
  pthread_create(t+1, NULL, infloop, i+1);
  pthread_create(t+2, NULL, mainloop, i+3);
	
	
  pthread_join(t[0], &retval);
  pthread_join(t[1], &retval);
}
