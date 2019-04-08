#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


void *sleepy_storyteller(void *vargp) {
    char *original_story = (char *)vargp;
    size_t buffsize = strlen(original_story);

    char *buffer = (char *)malloc(sizeof(char)*buffsize + 1);
    strcpy(buffer, original_story);

    char *token = strtok(buffer, " ");
    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " ");

        sleep(1);
    }

    free(buffer);
    return NULL;
}

int main(int arg, char *argv) {
    pthread_t sleepy_thread;

    // "Rain", by Edward Thomas
    char story[] = "Rain, midnight rain, nothing but the wild rain On this bleak hut, and solitude, and me Remembering again that I shall die And neither hear the rain nor give it thanks For washing me cleaner than I have been Since I was born into this solitude. Blessed are the dead that the rain rains upon: But here I pray that none whom once I loved Is dying to-night or lying still awake Solitary, listening to the rain, Either in pain or thus in sympathy Helpless among the living and the dead, Like a cold water among broken reeds, Myriads of broken reeds all still and stiff, Like me who have no love which this wild rain Has not dissolved except the love of death, If love it be towards what is perfect and Cannot, the tempest tells me, disappoint.";
  
    pthread_create(&sleepy_thread, NULL, sleepy_storyteller, (void *)story);

    pthread_join(sleepy_thread, NULL);

    return 0;
}
