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

void *calculatePow(void* arg) {
    int n = *((int *)arg);
    printf("%d hello\n", n);

    if (n) {
        return (void *)(n * n);
    }

    return NULL;
}

int main() {
    pthread_t pthread;

    int result = 0;
    int num = 5;

    pthread_create(&pthread, NULL, &calculatePow, &num);

    pthread_join(pthread, (void *)&result);

    printf ("Power of %d is %d\n", num, result);

    return 0;
}