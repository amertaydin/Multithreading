#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct Info {
    char *name;
    int age;
};

void *printInfo(void* arg) {
    struct Info *info = (struct Info *)arg;

    printf("%d %s\n", info->age, info->name);

    return NULL;
}

int main() {
    pthread_t pthread;
    pthread_t pthread1;

    struct Info info;
    struct Info info1;

    info.name = "mert";
    info.age = 24;

    /*
    * 1. Pass address of thread handler
    * 2. If thread's attributes are not going to set, pass NULL
    * 3. Pass callback function
    * 4. Pass data
    */
    pthread_create(&pthread, NULL, &printInfo, &info);

    info1.name = "busra";
    info1.age = 27;
    pthread_create(&pthread1, NULL, &printInfo, &info1);

    /*
    * Join main thread with passed thread_id, main thread stops until joined thread finishes its execution.
    */
    pthread_join(pthread, NULL);
    pthread_join(pthread1, NULL);
    
    return 0;
}