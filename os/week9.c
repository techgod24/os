#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>

void * Func1();
void * Func2();
int shared = 1;
sem_t s;
int main() {
  sem_init( & s, 0, 1);
  pthread_t thread1, thread2;
  pthread_create( & thread1, NULL, Func1, NULL);
  pthread_create( & thread2, NULL, Func2, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  printf("Final value of shared is %d\n", shared);
}
void * Func1() {
    int x;
    sem_wait( & s);
    x = shared;
    printf("Thread1 reads the value as %d\n", x);
    x++;
    printf("Local updation by Thread1 is : %d\n", x);
    sleep(10);
    shared = x;
    printf("Value of shared variable updated by Thread1 is: % d\n ",shared);
    sem_post( & s);
    }
    void * Func2() {
    int y;
    sem_wait( & s);
    y = shared;
    printf("Thread2 reads the value as %d\n", y);
    y--;
    printf("Local updation by Thread2 is: %d\n", y);
    sleep(10);
    shared = y;
    printf("Value of shared variable updated by Thread2 is: % d\n ",shared);
    sem_post( & s);
    }

// Thread1 reads the value as 1
// Local updation by Thread1 is : 2
// Value of shared variable updated by Thread1 is: 2
// Thread2 reads the value as 2
// Local updation by Thread2 is: 1
// Value of shared variable updated by Thread2 is: 1
// Final value of shared is 1