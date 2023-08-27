#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>


char input_file[20][150];
char thread1_strings[20][150];
int thread1_index[20], th1_i = 0;
char thread2_strings[20][150];
int thread2_index[20], th2_i = 0;
char thread3_strings[20][150];
int thread3_index[20], th3_i = 0;
char thread4_strings[20][150];
int thread4_index[20], th4_i = 0;

char input_file_line[150];
int input_file_line_count = 0;

int search_input_count = 0;
char search_input[10][20];

pthread_mutex_t mutex;
sem_t semaphore;

clock_t start_timer;
clock_t check_timer;

FILE *result_file;

void* thf1() {
    for (int i = 0; i < th1_i; i++)
    {
        for(int j = 0; j < search_input_count; j++)
        {
            if(strcmp(search_input[j], thread1_strings[i]) == 0)
            {
                //pthread_mutex_lock(&mutex);
                sem_wait(&semaphore);
                result_file = fopen("result_file.txt", "a");
                check_timer = clock();
                double passed_timer = (double) (check_timer - start_timer) / CLOCKS_PER_SEC;
                fprintf(result_file, "you searched for %s and it was found in line %d by thread 1 at %f\n" , search_input[j], ++thread1_index[i], passed_timer);
                fclose(result_file);
                printf("%s\n", search_input[j]);
                printf("Founded in line %d\n",++thread1_index[i]);
                //pthread_mutex_unlock(&mutex);
                sem_post(&semaphore);
            }
        }
    }
}

void* thf2() {
    for (int i = 0; i < th2_i; i++)
    {
        for(int j = 0; j < search_input_count; j++)
        {
            if(strcmp(search_input[j], thread2_strings[i]) == 0)
            {
                //pthread_mutex_lock(&mutex);
                sem_wait(&semaphore);
                result_file = fopen("result_file.txt", "a");
                check_timer = clock();
                double passed_timer = (double) (check_timer - start_timer) / CLOCKS_PER_SEC;
                fprintf(result_file, "you searched for %s and it was found in line %d by thread 2 at %f\n" , search_input[j], ++thread2_index[i], passed_timer);
                fclose(result_file);
                printf("%s\n", search_input[j]);
                printf("Founded in line %d\n",++thread1_index[i]);
                //pthread_mutex_unlock(&mutex);
                sem_post(&semaphore);
            }
        }
    }
}

void* thf3() {
    for (int i = 0; i < th3_i; i++)
    {
        for(int j = 0; j < search_input_count; j++)
        {
            if(strcmp(search_input[j], thread3_strings[i]) == 0)
            {
                //pthread_mutex_lock(&mutex);
                sem_wait(&semaphore);
                result_file = fopen("result_file.txt", "a");
                check_timer = clock();
                double passed_timer = (double) (check_timer - start_timer) / CLOCKS_PER_SEC;
                fprintf(result_file, "you searched for %s and it was found in line %d by thread 3 at %f\n" , search_input[j], ++thread3_index[i], passed_timer);
                fclose(result_file);
                printf("%s\n", search_input[j]);
                printf("Founded in line %d\n",++thread3_index[i]);
                //pthread_mutex_unlock(&mutex);
                sem_post(&semaphore);
            }
        }
    }
}

void* thf4() {
    for (int i = 0; i < th4_i; i++)
    {
        for(int j = 0; j < search_input_count; j++)
        {
            if(strcmp(search_input[j], thread4_strings[i]) == 0)
            {
                //pthread_mutex_lock(&mutex);
                sem_wait(&semaphore);
                result_file = fopen("result_file.txt", "a");
                check_timer = clock();
                double passed_timer = (double) (check_timer - start_timer) / CLOCKS_PER_SEC;
                fprintf(result_file, "you searched for %s and it was found in line %d by thread 4 at %f\n" , search_input[j], ++thread4_index[i], passed_timer);
                fclose(result_file);
                printf("%s\n", search_input[j]);
                printf("Founded in line %d\n",++thread1_index[i]);
                //pthread_mutex_unlock(&mutex);
                sem_post(&semaphore);
            }
        }
    }
}

int main()
{
    start_timer = clock();
    FILE *test_case;

    test_case = fopen("test_case.txt", "r");

    while(fgets(input_file_line,150, test_case))
    {
        strcpy(input_file[input_file_line_count],input_file_line);
        input_file_line_count++;
    }

    printf("input file contains of:\n");

    for(int j = 0 ; j < input_file_line_count ; j++)
    {
        printf("%s", input_file[j]);
    }
    fclose(test_case);
    char newline[] = "\n";
    char dot[] = ".";
    char comma[] = ",";

    int found_newline, found_dot, found_comma;
    int which_thread = 1;
    for(int i = 0; i < input_file_line_count; i++)
    {
        char *token = strtok(input_file[i], " ");
        while(token != NULL)
        {
            found_newline = strcmp(token, newline);
            found_dot = strcmp(token, dot);
            found_comma = strcmp(token, comma);
            if(found_newline != 0 && found_dot != 0 && found_comma != 0)
            {
                if(which_thread == 1)
                {

                    strcpy(thread1_strings[th1_i], token);
                    token = strtok(NULL, " ");
                    thread1_index[th1_i] = i;
                    th1_i++;
                    which_thread = 2;
                }
                else if(which_thread == 2)
                {
                    strcpy(thread2_strings[th2_i], token);
                    token = strtok(NULL, " ");
                    thread2_index[th2_i] = i;
                    th2_i++;
                    which_thread = 3;
                }
                else if(which_thread == 3)
                {
                    strcpy(thread3_strings[th3_i], token);
                    token = strtok(NULL, " ");
                    thread3_index[th3_i] = i;
                    th3_i++;
                    which_thread = 4;
                }
                else if(which_thread == 4)
                {
                    strcpy(thread4_strings[th4_i], token);
                    token = strtok(NULL, " ");
                    thread4_index[th4_i] = i;
                    th4_i++;
                    which_thread = 1;
                }
            }
            else
            {
                    token = strtok(NULL, " ");
            }
        }
    }
    printf("printing thread1 stuff\n");
    for(int i = 0; i < th1_i;i++)
    {
        printf("%s, ",thread1_strings[i]);
    }
    printf("\n");
    printf("printing thread2 stuff\n");
    for(int i = 0; i < th2_i;i++)
    {
        printf("%s, ",thread2_strings[i]);
    }
    printf("\n");
    printf("printing thread3 stuff\n");
    for(int i = 0; i < th3_i;i++)
    {
        printf("%s, ",thread3_strings[i]);
    }
    printf("\n");
    printf("printing thread4 stuff\n");
    for(int i = 0; i < th4_i;i++)
    {
        printf("%s, ",thread4_strings[i]);
    }
    printf("\n");

    printf("how many input strings you wish to search? ");
    scanf("%d", &search_input_count);

    for (int i = 0; i < search_input_count ;i++){
        printf("write your exact instance of the search input: ");
        scanf("%s", search_input[i]);
    }

    pthread_t p1, p2, p3, p4;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&semaphore,0,1);

    result_file = fopen("result_file.txt", "w");
    fclose(result_file);

    if (pthread_create(&p1, NULL, &thf1, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&p2, NULL, &thf2, NULL) != 0) {
        return 2;
    }
    if (pthread_create(&p3, NULL, &thf3, NULL) != 0) {
        return 3;
    }
    if (pthread_create(&p4, NULL, &thf4, NULL) != 0) {
        return 4;
    }

    if (pthread_join(p1, NULL) != 0) {
        return 5;
    }
    if (pthread_join(p2, NULL) != 0) {
        return 6;
    }
    if (pthread_join(p3, NULL) != 0) {
        return 7;
    }
    if (pthread_join(p4, NULL) != 0) {
        return 8;
    }
    pthread_mutex_destroy(&mutex);



}
