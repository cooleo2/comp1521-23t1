#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *data) {
    while (1) {
        printf("feed me input!\n");
        sleep(1);
    }

}

int main(void) {


    // TODO: create a thread
    pthread_t new_thread;
    pthread_create(&new_thread, NULL, thread_run, NULL);

    
    char line[1024];

    // TODO: print out lines
    while (fgets(line, 1024, stdin)) {
        printf("you entered: %s\n", line);
    }


    // TODO: cancel the thread upon completion
    pthread_cancel(new_thread);
    return 0;
}
