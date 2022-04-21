#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "dyn_array.h"
#include "processing_scheduling.h"


// You might find this handy.  I put it around unused parameters, but you should
// remove it before you submit. Just allows things to compile initially.
#define UNUSED(x) (void)(x)

// private function
void virtual_cpu(ProcessControlBlock_t *process_control_block) 
{
    // decrement the burst time of the pcb
    --process_control_block->remaining_burst_time;
}

int32_t compare(const void* pcb1, const void* pcb2) /* function is a simple compare() function for the PCBs. Required for the dynamic array sorting function */
{
    if(((ProcessControlBlock_t*)pcb1)->arrival > ((ProcessControlBlock_t*)pcb2)->arrival)
    {
        return 1;
    }
    else if(((ProcessControlBlock_t*)pcb1)->arrival < ((ProcessControlBlock_t*)pcb2)->arrival)
    {
        return -1;
    }
    return 0;
}

bool first_come_first_serve(dyn_array_t *ready_queue, ScheduleResult_t *result) /* function checks if the PCBs in the input parameter dynamic array ready_queue are properly executed following First Come First Serve scheduling. The input parameter result keeps track of the stats. This function returns true if executed properly or false otherwise */
{
    if(ready_queue && result) // NULL check to prevent seg faults when calling other functions using these input parameters
    {
        uint32_t burst = 0, wait = 0, turn = 0, totalWait = 0, totalTime = 0;
        int32_t blockCount = (int32_t) dyn_array_size(ready_queue); // function included in the provided dyn_array.h header that returns the size of the dynamic array and initializes this to a count variable
        ProcessControlBlock_t pcb, nullPCB; // temporary/control variables that will come in handy later (I had to make 2, one being a "NULL" PCB as simply setting the first variable to NULL raised an error
        if(blockCount <= 0) // checks to see if the array is empty and sets values appropriately if so
        {
            result->average_turnaround_time = 0;
            result->average_waiting_time = 0;
            result->total_run_time = 0;
        }
        else // executes if the array is not empty
        {
            for(int32_t i = 0; i < blockCount; i++)
            {
                wait += burst; // increases the next wait time by the burst time, as the next PCB will have to wait before executing
                dyn_array_extract_back(ready_queue, (void*) &pcb); // function included in the provided dyn_array.h header to extract the object from the back and store it in pcb
                burst = pcb.remaining_burst_time; // sets the burst time according to the burst time provided by the current PCB
                totalTime += burst; // increases the total time for the FCFS execution of the PCBS
                turn += (wait + pcb.remaining_burst_time); // calculates the time of the turn based on the wait and burst times
                if(i > 0) // checks to make sure there is more than one PCB in the array before incrementing the total wait time
                {
                    totalWait += wait;
                }
                while(pcb.remaining_burst_time) // loop to ensure that the current PCB is still executing (burst time != 0). Notice how we have been using pcb.remaining_burst_time as opposed to the burst variable. Originally, I used the burst variable and got caught in an infinite loop, as virtual_cpu() changes the pcb.remaining_burst_time
                {
                    virtual_cpu(&pcb); // function provided in this file to decrement the burst time
                }
                pcb =  nullPCB; // sets the temporary PCB variable to the NULL temporary variable so it does not get misused somehow by the system
            }
            result->average_waiting_time = (float) totalWait/blockCount; // sets values accordingly
            result->average_turnaround_time = (float) turn/blockCount;
            result->total_run_time = (float) totalTime;
        }
        return true; // successful return
    }
    return false; // default return: false
}

bool shortest_job_first(dyn_array_t *ready_queue, ScheduleResult_t *result) /* function checks if the PCBs in the input parameter dyanmic array ready_queue are properly executed following the non-preemptive Shortest Job First Scheduling. The input parameter result keeps track of the stats. This function returns true if executed properly or false otherwise */
{
    if(ready_queue && result) // NULL checks to prevent seg faults when attempting to call functions using ready_queue or result
    {
        uint32_t burst = 0, wait = 0, turn = 0, totalWait = 0, totalTime = 0;
        int32_t blockCount = (int32_t) dyn_array_size(ready_queue); // function included in the provided dyn_array.h header that returns the size of the dynamic array and initializes this to a count variable
        ProcessControlBlock_t pcb, nextPCB, nullPCB; // temporary/control variables that will come in handy later (I had to make 3, one being a "NULL" PCB)
        nullPCB.priority = 999999; // the priority of nullPCB has to be initialized as I use it for comparisons later
        if(blockCount <= 0) // checks to see if the array is empty and sets values appropriately if so
        {
            result->average_turnaround_time = 0;
            result->average_waiting_time = 0;
            result->total_run_time = 0;
        }
        else // executes if the array is not empty
        {
            for(int32_t i = 0; i < blockCount; i++)
            {
                int32_t dynamicCount = (int32_t) dyn_array_size(ready_queue); // function included in the provided dyn_array.h header that returns the size of the dynamic array and initializes this to a dynamic count variable
                pcb = nullPCB; // sets both pcb and nextPCB to 'null'/nullPCB
                nextPCB = nullPCB;
                for(int32_t j = 0; j < dynamicCount; j++) // loops through all of the PCBs still accounted for in ready_queue
                {
                    dyn_array_extract_back(ready_queue, (void*) &nextPCB); // function included in the provided dyn_array.h header that removes the back object from the array and returns the object to the desired location (in this case, nextPCB)
                    if(pcb.priority == nullPCB.priority && nextPCB.arrival <= totalTime) // checks if no PCB has been saved to pcb yet and nextPCB has arrived according to the totalTime
                    {
                        pcb = nextPCB; // sets pcb to nextPCB
                    }
                    if(pcb.priority != nullPCB.priority && nextPCB.arrival <= totalTime && nextPCB.remaining_burst_time < pcb.remaining_burst_time) // checks if a PCB has been saved to pcb and nextPCB has arrived according to the totalTime and the remaining time of nextPCB is less than that of pcb
                    {
                        dyn_array_push_front(ready_queue, (void*) &pcb); // function included in the provided dyn_array.h header that pushes pcb back to the front of the array
                        pcb = nextPCB; // sets pcb to nextPCB
                    }
                    else // else should cover all other scenarios
                    {
                        dyn_array_push_front(ready_queue, (void*) &nextPCB); // function included in the provided dyn_array.h header that pushes nextPCB back to the front of the array
                    }
                    nextPCB = nullPCB; // sets nextPCB to nullPCB to prevent future issues
                }
                wait += burst; // increases the next wait time by the burst time, as the next PCB will have to wait before executing
                burst = pcb.remaining_burst_time; // sets the burst time according to the burst time provided by the current PCB, pcb
                totalTime += burst; // increases the total time for the SJF execution of the PCBs
                turn += (wait + pcb.remaining_burst_time - pcb.arrival); // calculates the time of the turn based on the wait, burst, and arrival times
                if(i > 0) // checks to make sure this is not the first PCB executed before incrementing the total wait time
                {
                    totalWait += wait - pcb.arrival;
                }
                while(pcb.remaining_burst_time) // loop to ensure that the current PCB is still executing
                {
                    virtual_cpu(&pcb); // function provided in this file to decrement the burst time
                }
                pcb = nullPCB; // sets the temporary PCB variable to the NULL temporary variable so it does not get misused somehow by the system
            }
            result->average_waiting_time = (float) totalWait/blockCount; // sets values accordingly
            result->average_turnaround_time = (float) turn/blockCount;
            result->total_run_time = (float) totalTime;
        }
        return true; // successful return
    }
    return false; // default return: false 
}

bool priority(dyn_array_t *ready_queue, ScheduleResult_t *result) /* We were never instructed to implement or complete a priority() function. However, I thought it was best to leave the function here as it was instead of completely commenting it out or deleting it */
{
    UNUSED(ready_queue);
    UNUSED(result);
    return false;   
}

bool round_robin(dyn_array_t *ready_queue, ScheduleResult_t *result, size_t quantum) /* function checks if the PCBS in the input parameter dynamic array ready_queue are properly executed following Round Robin scheduling. The input parameter result keeps track of the stats. This function returns true if executed properly or false otherwise */
{
    if(ready_queue && result && (((int32_t) quantum) > 0)) // NULL checks and size check to prevent seg faults when attepmting to call functions using ready_queue, result, or quantum
    {
       uint32_t turn = 0, timeTracker = 0;
       int32_t blockCount = (int32_t) dyn_array_size(ready_queue); // function included in the provided dyn_array.h header that returns the size of the dynamic array and initialized this to a count variable   
       ProcessControlBlock_t pcb, nullPCB; // temporary/control variables that will come in handy later (I had to make 2, one being a "NULL" PCB)
       if(blockCount <= 0) // checks to see if the array is empty and sets values appropriately if so
       {
            result->average_turnaround_time = 0;
            result->average_waiting_time = 0;
            result->total_run_time = 0;
       }
       else // executes if the array is not empty
       {
            while(!dyn_array_empty(ready_queue)) // loop to ensure that the array of PCBs is not empty, which is checked using a function provided in the dyn_array.h header
            {
                dyn_array_extract_back(ready_queue, (void*) &pcb); // function included in the provided dyn_array.h header that removes the back object from the array and returns the object to the desired location (in this case, pcb)
                for(int32_t i = 0; i < ((int32_t) quantum); i++) // loops through the timespan of the quantum
                {
                    if(pcb.remaining_burst_time > 0) // checks if the pcb still has time to execute for the current quantum
                    {
                        virtual_cpu(&pcb); // function provided in this file to decrement the burst time
                        ++timeTracker;
                    }
                    else // breaks out of the quantum loop if the current pcb does not have any more time remaining
                    {
                        break;
                    }
                }
                if(pcb.remaining_burst_time != 0) // checks to see if the pcb still has time to execute after completion of a quantum
                {
                    dyn_array_push_front(ready_queue, (void*) &pcb); // function included in the provided dyn_array.h header that pushes the desired object(in this case, pcb) back onto the front of the dynamic array
                }
                else
                {
                    turn += timeTracker;
                    if(pcb.arrival > 0) // checks to see if the arrival time of the current pcb is greater than 0, as the arrival time has to be subtracted away when calculating the turnaround time
                    {
                        turn -= (pcb.arrival - pcb.priority); 
                    }
                }
                pcb = nullPCB; // sets the temporary PCB variable to the NULL temporary variable so it does not get misused somehow by the system
            }
            result->average_waiting_time = (float) (turn - timeTracker)/blockCount; // sets values accordingly
            result->average_turnaround_time = (float) turn/blockCount;
            result->total_run_time = (float) timeTracker;
       }
       return true; // successful return
    }
    return false; // default return: false
}

dyn_array_t *load_process_control_blocks(const char *input_file) /* function checks if the burst time values for the N number of PCBs stored in 
the input parameter file input_file are correctly read into a dynamic array*/
{
    if(input_file) // NULL check to prevent seg fault when attempting to call functions using input_file
    {
        uint32_t index = 0;
        uint32_t filename_size = strlen(input_file); // built-in function to check the length of the given filename
        if(filename_size > 0 && filename_size < 101) //size check to prevent illegal filenames from being used in function calls
        {
            while(index < filename_size)
            {
                uint8_t file_char = *(input_file+index); // obtains the next character in sequence in the filename "string"
                if(file_char < 40 || (file_char > 41 && file_char < 44) || (file_char > 46 && file_char < 48) || (file_char > 57 && file_char < 65) || (file_char > 90 && file_char < 95) || file_char == 96 || file_char > 122) // checks to see if any invalid filename characters are present using ASCII values
                {
                    return NULL;
                }
                if((filename_size==(index+4) && file_char != 46) || (filename_size==(index+3) && file_char != 98) || (filename_size==(index+2) && file_char != 105) || (filename_size==(index+1) && file_char != 110)) // checks to see if the given file is a ".bin" file, as a binary file is specifically requested in the homework document
                {
                    return NULL;
                }
                index += 1;
            }
            int32_t  fd = open(input_file, O_RDONLY); // uses a file descriptor to open the provided file for "read-only" (must be signed)
            if(fd && fd >= 0) // NULL check and value check to ensure a file descriptor to the file exists
            {
                uint32_t blockCount = 0;
                read(fd, &blockCount, sizeof(uint32_t)); // built-in function to move the read sizeof(uint32_t) bytes into blockCount from the file descriptor fd
                ProcessControlBlock_t* pcbs = (ProcessControlBlock_t*) malloc(blockCount*sizeof(ProcessControlBlock_t)); // allocate memory for blockCount number of type ProcessControlBlock_t
                dyn_array_t* pcbArray = dyn_array_create(0, sizeof(ProcessControlBlock_t), NULL); // function called using the provided dyn_array.h header to allocate a new dynamic array
                if(pcbArray) // NULL check to ensure a dynamic array was created
                {
                    for(uint32_t i = 0; i < blockCount; i++)
                    {
                        read(fd, &pcbs[i].remaining_burst_time, sizeof(uint32_t)); // reads in the remaining_burst_time value from the file
                        read(fd, &pcbs[i].priority, sizeof(uint32_t)); // reads in the priority value from the file
                        read(fd, &pcbs[i].arrival, sizeof(uint32_t)); // reads in the arrival value from the file
                        dyn_array_push_back(pcbArray, &pcbs[i]); // function called using the provided dyn_array.h header to copy the object and put it in the array, dynamically increasing it
                    }
                    free(pcbs); // must free all allocated memory, which in this case were the "ProcessControlBlock_t"s
                    close(fd); // must close the file descriptor if it was opened properly to begin with
                    return pcbArray; // successful return
                }
            }
        }
    }
    return NULL; // default return: NULL
}

bool shortest_remaining_time_first(dyn_array_t *ready_queue, ScheduleResult_t *result) /* function checks if the PCBs in the input parameter dynamic array ready_queue are properly executed following the preemptive Shortest Remaining Time First scheduling. The input parameter result keeps track of the stats. This function returns true if executed properly or false otherwise */
{
    // like SJF but instead of looping through the entire block at once, you'll just check at each time (aka ready_queue is empty)
    if(ready_queue && result) // NULL checks to prevent seg faults when attempting to call functions using ready_queue or result
    {
        uint32_t turn = 0, timeTracker = 0;
        int32_t blockCount = (int32_t) dyn_array_size(ready_queue); // function included in the provided dyn_array.h header that returns the size of the dynamic array and initializes this to a count variable
        ProcessControlBlock_t pcb, nextPCB, nullPCB; // temporary/control variables that will come in handy later (I had to make 3, one being a "NULL" PCB)
        nullPCB.priority = 999999; // the priority and arrival of nullPCB has to be initialized as I use it for comparisons later
        nullPCB.arrival = 999999;
        if(blockCount <= 0) // checks to see if the array is empty and sets values appropriately if so
        {
            result->average_turnaround_time = 0;
            result->average_waiting_time = 0;
            result->total_run_time = 0;
        }
        else // executes if the array is not empty
        {
            int32_t controlCount = blockCount;
            while(controlCount > 0) // originally, I used dyn_array_empty() as a loop control, however this gave me an infinite loop and I could not figure out why. Instead, I added yet another count variable, controlCount, which is initially set equal to the blockCount, and I conditioned off of while this was greater than 0, i.e. PCBs still needed to be executed
            {
                int32_t dynamicCount = (int32_t) dyn_array_size(ready_queue); // function included in the provided dyn_array.h header that returns the size of the dynamic array and initializes this to a dynamic count variable
                pcb = nullPCB; // sets both pcb and nextPCB to 'null'/nullPCB
                nextPCB = nullPCB;
                for(int32_t i = 0; i < dynamicCount; i++) // loop through all of the PCBs still accounted for in ready_queue
                {
                    dyn_array_extract_back(ready_queue, (void*) &nextPCB); // function included in the provided dyn_array.h header that removes the back object from the array and returns this to a dynamic count variable
                    if(nextPCB.remaining_burst_time == 0)
                    {
                        nextPCB = nullPCB;
                    }
                    if(pcb.priority == nullPCB.priority && nextPCB.arrival <= timeTracker) // checks if no PCB has been saved to pcb yet and nextPCB has arrived according to the time tracker
                    {
                        pcb = nextPCB; // sets pcb to nextPCB
                    }
                    if(pcb.priority != nullPCB.priority && nextPCB.arrival <= timeTracker && nextPCB.remaining_burst_time < pcb.remaining_burst_time) // checks if a PCB has been saved to pcb and nextPCB has arrived according to the time tracker and the remaining time of nextPCB is less than that of pcb
                    {
                        dyn_array_push_front(ready_queue, (void*) &pcb); // function included in the provided dyn_array.h header that pushes pcb back to the front of the array
                        pcb = nextPCB; // sets pcb to nextPCB
                    }
                    else // else should cover all other scenarios
                    {
                        dyn_array_push_front(ready_queue, (void*) &nextPCB); // function included in the provided dyn_array.h header that pushes nextPCB back to the front of the array
                    }
                    nextPCB = nullPCB; // sets nextPCB to nullPCB to prevent future issues
                }
                if(pcb.remaining_burst_time > 0) // checks if the pcb still has time to execute
                {
                    virtual_cpu(&pcb); // function provided in this file to decrement the burst time
                    ++timeTracker;
                }
                if(pcb.remaining_burst_time != 0) // checks to see if the pcb still has time to execute after having its burst time decremented
                {
                    dyn_array_push_front(ready_queue, (void*) &pcb); // function included in the provided dyn_array.h header that pushes pcb back to the front of the array
                }
                else 
                {
                    turn += timeTracker - pcb.arrival;
                    --controlCount; // decrements controlCount loop control variable, as this PCB will no longer be used or returned back to the dynamic array
                }
                pcb = nullPCB; // sets the temporary PCB variable to the NULL temporary variable so it does not get misused somehow by the system
            }
            result->average_waiting_time = (float) (turn - timeTracker)/blockCount; // sets values accordingly
            result->average_turnaround_time = (float) turn/blockCount;
            result->total_run_time = (float) timeTracker;
        }
        return true; // successful return
    }
    return false; // default return: false
}
