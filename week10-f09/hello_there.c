#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    char *string = data;
    while (1) {
        printf("%s\n", string);
    }
    return NULL;
}

int main(void) {
    // TODO: create a thread
    char *message = "Hello\n";
    pthread_t hello_thread;
    pthread_create(&hello_thread, NULL, thread_run, message);
    
    while (1) {
        printf("there!\n");
    }

    return 0;
}
