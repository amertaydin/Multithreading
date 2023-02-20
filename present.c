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

    printf("I am here\n");

    info.name = "mert";
    info.age = 24;
    pthread_create(&pthread, NULL, &printInfo, &info);

    printf("I am here again\n");

    info1.name = "busra";
    info1.age = 27;
    pthread_create(&pthread1, NULL, &printInfo, &info1);

    printf("I am not here\n");

    pthread_join(pthread, NULL);
    pthread_join(pthread1, NULL);
    
    printf("I am finished\n");

    //pthread_exit(0);

    return 0;
}