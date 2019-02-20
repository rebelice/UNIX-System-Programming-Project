/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct arg{
	int id, value;
}arg;

void *PrintValue(void *v)
{
	arg *p = (arg *)v;
	printf("Thread %d: Hello World! Value: %d\n", p->id, p->value);
	pthread_exit(NULL);
}

int main()
{
	pthread_attr_t attr;
	pthread_t threads_pool[MAX_THREADS];
	int i, rv;
	void *status;
	arg targ[MAX_THREADS];

	/* Initialize and Joinable */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < MAX_THREADS; i++)
	{
		targ[i].id = i;
		targ[i].value = i * (i + 1);
	}

	for (i = 0; i < MAX_THREADS; i++)
	{
		if (i) 		
		{
			rv = pthread_join(threads_pool[i - 1], &status);
			if (rv)
			{
				printf("ERROR: Return value from pthread_join is %d\n", rv);
				exit(-1);
			}
			printf("Main: Completed join with thread %d\n", i - 1);
		}
		printf("Main: Creating Thread %d\n", i);
		rv = pthread_create(&threads_pool[i], &attr, PrintValue, (void *)&targ[i]);
		if (rv)
		{
			printf("ERROR: Return value from pthread_create is %d\n", rv);
			exit(-1);
		}
	}

	rv = pthread_join(threads_pool[MAX_THREADS - 1], &status);
	if (rv)
	{
		printf("ERROR: Return value from pthread_join is %d\n", rv);
		exit(-1);
	}
	printf("Main: Completed join with thread %d\n", MAX_THREADS - 1);
	pthread_exit(NULL);
	return 0;
}
