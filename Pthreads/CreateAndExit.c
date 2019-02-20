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
	pthread_t threads_pool[MAX_THREADS];
	int i, rv;
	arg targ[MAX_THREADS];

	for (i = 0; i < MAX_THREADS; i++)
	{
		targ[i].id = i;
		targ[i].value = i * (i + 1);
	}

	for (i = 0; i < MAX_THREADS; i++)
	{
		printf("Main: Creating Thread %d\n", i);
		rv = pthread_create(&threads_pool[i], NULL, PrintValue, (void *)&targ[i]);
		if (rv)
		{
			printf("ERROR: Return value from pthread_create is %d\n", rv);
			exit(-1);
		}
	}
	pthread_exit(NULL);
	return 0;
}
