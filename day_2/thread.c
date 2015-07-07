#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2
//commen
struct index{
	long t;
	long i;
};


void *print_index(void *ind) {
	long time;
	struct index *inde;
	inde = (struct index *)ind;
	long t = inde-> t; 
	for (time = 0; time < 10; time ++){
	if (t) {
		printf("I'm %ld    ", t);
		inde->i -= 2;
	}
	else {
		printf("I'm %ld    ", t);
		inde->i += 1;
	}
	//index = (long) pthread_self();
	
	
	printf("Index = %ld\n", inde->i);
	//	printf("Current thread's index = %d\n", (int)index);
	
	sleep(1);	
	}	

	//rintf("Hello World! Thread num: %ld\n", t_num);
}

int main (int argc, char *argv[]) {
	pthread_t threads[NUM_THREADS];
	int rc;
	struct index ind;
	ind.t = 0;
	ind.i = 0;
	long t;
	for (ind.t = 0; ind.t < NUM_THREADS; ind.t++) {
		t = ind.t;
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, print_index, (void *)&ind);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d/n", rc);
			exit(-1);
		}
	}


	for (ind.t = 0; ind.t < NUM_THREADS; ind.t++) {
		pthread_join(threads[ind.t], NULL);
		printf("THREAD #%ld finished\n", ind.t);
	}
	return 0;
}