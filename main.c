
#include<stdio.h>
#include<string.h>
void welcomeMsg();
int choice,i=0;
char name[100];
int completeTaskInitial=0;
struct task
{
    char taskName[100];
    char taskDate[100];
}taskInfo[100];

struct taskComplete
{
    char taskName[100];
    char taskDate[100];
}completedTaskStructure[100];

void commonMessage(char *message)
{
    system("cls");
    printf("\n");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t**        Personal Assistant Project         **");
    printf("\n\t\t\t**                                           **");
    printf("\n\t\t\t***********************************************");
    //printf("\n\t\t\t-----------------------------------------------\n");
    printf("\n\t\t\t\t\t%s",message);
    printf("\n\t\t\t-----------------------------------------------");
}
void developer()
{
    system("color 4e");
    commonMessage("Developer Menu");
    printf("\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =      Developers Information   =");
    printf("\n\t\t\t        =*******************************=");
    printf("\n\t\t\t        =          Name      ID         =");
    printf("\n\t\t\t        =*******************************=");
    printf("\n\t\t\t        =    1. Name:Irfan Fouzan  ID: 212-15-714   =DIU CSE");
    printf("\n\t\t\t        =    2. Name:  ID: 212-15-714   =");
    printf("\n\t\t\t        =    3. Name:  ID: 212-15-714   =");
    printf("\n\t\t\t        =    4. Name:  ID: 212-15-714   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
void addTasks()
{
    commonMessage("ADD TASK PAGE");
    //printf("\n\n\tEnter book name(start with dot(.))\n\n");
    FILE *fptr = fopen("task.txt","a");
    char dot = '.';
    char comma = ',';

    if(fptr != NULL)
    {
        printf("\n\tEnter task name:  ");
        getchar();
        gets(taskInfo[i].taskName);
        fprintf(fptr,"%c",dot);
        fprintf(fptr,"%s",taskInfo[i].taskName);
        fprintf(fptr,"%c",comma);

        printf("\n\tEnter deadline of the task:  ");
        gets(taskInfo[i].taskDate);
        fprintf(fptr,"%s",taskInfo[i].taskDate);
        i++;
        fclose(fptr);
        printf("\n\tSuccessfully added to file/database...\n ");

        getch();
    }
    else
    {
        printf("Error!");
    }
    getch();
}
void checkUpcomingTask()
{
    commonMessage("TASK LIST PAGE");
    int j;
    for(j=0;j<i;j++){
        printf("\n\t%d. %s  %s\n",j+1,taskInfo[j].taskName,taskInfo[j].taskDate);
    }
    getch();
}
int taskSearch(char name[])
{
    int j,temp[100];
    for(j=0;j<i;j++)
    {
        if(!strcmp(taskInfo[j].taskName,name)){
            printf("\n\tThis task is found in your database...\n\tSo, now enter new task name to be updated:  ");
            gets(taskInfo[j].taskName);
            return 0;
        }
        //else return 1;
    }
}
void updateTasks()
{
    commonMessage("UPDATE TASK PAGE");
    printf("\n\tEnter the task name u want to update:   ");
    getchar();
    gets(name);
    int key = taskSearch(name);
    if(key==0){
        printf("\n\t Task name updated successfully\n");
//        gets(taskInfo[]]);
    }
    else{
        printf("\n\t Task name is not found in the database. So, not possible to update.!!!\n");
    }
    getch();
}
int  checkTaskList(char name[])
{
    int j,temp[100];
    for(j=0;j<i;j++)
    {
        if(!strcmp(taskInfo[j].taskName,name)){
            printf("\n\tThis task is found in your database... \n");
            return 0;
        }
        //else return 1;
    }
}
//void enlistToCompleteTask(cTaskName)
//{
//    strcpy(completedTaskStructure[completeTaskInitial++].taskName,cTaskName);
//}
int findIndexForCompletedTaskNameFromTaskList(char name[])
{
    int j,temp[100];
    for(j=0;j<i;j++)
    {
        if(!strcmp(taskInfo[j].taskName,name)){
            return j;
        }
    }
}
void taskList()
{
    int j;
    printf("\n\t...TASK.....DATE....\n");
    for(j=0;j<i;j++){
        printf("\n\t%d. %s  %s\n",j+1,taskInfo[j].taskName,taskInfo[j].taskDate);
    }
    getch();
}
void completeTasks()
{
    commonMessage("COMPLETE TASKS");
    char cTaskName[100];
    printf("\n\tHere is your tasks list:\n");
    taskList();
    printf("\n\tNow type your completed task name here...:\n");
    getchar();
    gets(cTaskName);
    int key = checkTaskList(cTaskName);
    if(key==0){
        //enlistToCompleteTask(cTaskName);
        strcpy(completedTaskStructure[completeTaskInitial].taskName,cTaskName); ///selected/typed task k completed task e add korlam
        int completeTaskDateIndex = findIndexForCompletedTaskNameFromTaskList(cTaskName);  ///jei task k complete korlam tar index get korlam
        strcpy(completedTaskStructure[completeTaskInitial++].taskDate,taskInfo[completeTaskDateIndex].taskDate); ///jei task name k complete korechi tar date k completed task er structure e save korlam
        printf("\n\tWelcome..This task and corresponding date have been listed to completed task list\n");
    }
    else{
        printf("\n\t Task name is not found in the database. So, not possible to enlisted this task into completed task list.!!!\n");
    }


    getch();
}
void viewCompletedTasks()
{
    int j;
    printf("\n\t...TASK.....DATE....\n");
    for(j=0;j<completeTaskInitial;j++){
        printf("\n\t%d. %s  %s\n",j+1,completedTaskStructure[j].taskName,completedTaskStructure[j].taskDate);
    }
    getch();
}
int findDateFromTaskList(char date[])
{
    int j,temp[100];
    for(j=0;j<i;j++)
    {
        if(!strcmp(taskInfo[j].taskDate,date)){
            printf("\n\tSpecific task of %s date : %s\n",taskInfo[j].taskDate,taskInfo[j].taskName);
            return 0;
        }
    }
}
void viewTasksOfSpecificDate()
{
    char date[20];
    commonMessage("CHECK TASK OF SPECIFIC DATE PAGE");
    printf("\n\tEnter a Date: ");
    getchar();
    gets(date);
    int key = findDateFromTaskList(date);
    if(key!=0) {
        printf("\n\t..Hurrah !!! No, task on this date...\n");
    }

    getch();
}
int findIndexForCancellingTaskFromTaskList(char name[])
{
    int j,temp[100];
    for(j=0;j<i;j++)
    {
        if(!strcmp(taskInfo[j].taskName,name)){
            //printf("\n\tSpecific task of %s date : %s\n",taskInfo[j].taskDate,taskInfo[j].taskName);
            return j;
        }
    }
}
void cancelTask()
{
    commonMessage("CANCEL TASK PAGE");
    char taskTemp[20];
    printf("\n\tEnter a Task Name to cancel it: ");
    getchar();
    gets(taskTemp);
    int key = checkTaskList(taskTemp);
    if(key==0){
        int index = findIndexForCancellingTaskFromTaskList(taskTemp);
        strcpy(taskInfo[index].taskName," ");
        strcpy(taskInfo[index].taskDate," ");
        printf("\n\tHurrah!!!.. Task canceled successfully\n");
    }
    else{
        printf("\n\tThis task is not found !!!.\n\tSo, not possible to cancel from task list\n");
    }
    getch();
}
void main()
{
    system("color 9e");
    do
    {
        commonMessage("ASSIGNED TASKS");
        printf("\n\n\n\t\t\t1.Developer Information");
        printf("\n\t\t\t2.Add tasks  ");
        printf("\n\t\t\t3.Update Tasks ");
        printf("\n\t\t\t4.Complete Task ");
        printf("\n\t\t\t5.Cancel Task  ");
        printf("\n\t\t\t6.Check Upcoming task  ");
        printf("\n\t\t\t7.Check tasks of specific date   ");
        printf("\n\t\t\t8.Check Completed tasks  ");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            developer();
            break;
        case 2:
            addTasks();
            break;
        case 3:
            updateTasks();
            break;
        case 4:
            completeTasks();
            break;
        case 5:
            cancelTask();
            break;
        case 6:
            checkUpcomingTask();
            break;
        case 7:
             viewTasksOfSpecificDate();
            break;
        case 8:
            viewCompletedTasks();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
            getch();
            break;
        }
    }
    while(choice!=0);
}
