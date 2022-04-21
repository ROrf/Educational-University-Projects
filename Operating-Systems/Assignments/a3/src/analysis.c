#include <stdio.h>
#include <stdlib.h>

#include "dyn_array.h"
#include "processing_scheduling.h"

#define FCFS "FCFS"
#define P "P" // use this for Shortest Remaining Time First? We didn't implement the priority() function
#define RR "RR"
#define SJF "SJF"

int main(int argc, char **argv) 
{
    if (argc < 3 || !strstr(argv[1], "PCBs.bin")) // strstr() is a function that finds the substring specified in the first argument. This if checks if less than the sufficient number of arguments were provided or if a file other than PCBs.bin was input
    {
        printf("%s <pcb file> <schedule algorithm> [quantum]\n", argv[0]);
        return EXIT_FAILURE;
    }

    dyn_array_t* ready_queue = load_process_control_blocks(argv[1]);
    ScheduleResult_t result = {0,0,0};
    // char *schedule = argv[2]; I originally used this when trying to write to the file "readme.md" but I couldn't figure out a correct implementation
    if(strstr(argv[2], FCFS))
    {
        first_come_first_serve(ready_queue, &result);
        printf("These are the results for First Come First Serve Scheduling:: \n");
    }

    else if(strstr(argv[2], SJF))
    {
        shortest_job_first(ready_queue, &result);
        printf("These are the results for Shortest Job First Scheduling:: \n");
    }

    else if(strstr(argv[2], P))
    {
        shortest_remaining_time_first(ready_queue, &result);
        printf("These are the results for Shortest Remaining Time First Scheduling:: \n");
    }

    else if(strstr(argv[2], RR) && argc == 4) // this if additionally checks to see if there were 4 arguments provided, which there would be for Round Robin
    {
        char* quantum;
        round_robin(ready_queue, &result, (size_t) strtoul(argv[3], &quantum, 10)); // strtoul() is a function that converts the first argument (argv[3]) into an integer of base argument 3 (10, or decimal in this case), and stores it in the second argument
        printf("These are the results for Round Robin Scheduling:: \n");
    }
    else // covers all other cases for error checking
    {
        printf("Error: You encountered an error somewhere when typing your time execution command. Please try again!\n");
        return EXIT_FAILURE;
    }

    printf("Average Turnaround Time:: %f \n", result.average_turnaround_time);
    printf("Average Waiting Time:: %f \n", result.average_waiting_time);
    printf("Total Run Time:: %f \n", (float) result.total_run_time); // total run time had to be casted as a float, the others did not

    /* This is code I used to try to implement writing the stats to the file "readme.md". Needless to say, it did not write as I intended so, while less effective, I will be copying over the values from the terminal, as that is permitted
     *
     * FILE* fp;
    fp = fopen("../readme.md", "ab");
    if(fp)
    {
        fwrite(schedule, 1, sizeof(schedule), fp);
        fwrite(&result, sizeof(result), 1, fp);
    }
    else
    {
        printf("Error: readme.md failed to open!\n");
    }
    fclose(fp);*/
    free(ready_queue);

    return EXIT_SUCCESS;
}
