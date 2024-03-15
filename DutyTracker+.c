#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
//update 1.3
// prototypes
int getTime();
int randomNumberGenerator(int max, int min);
void randomInspiration();
void mainLogo();
void selective_menu(int *options, char *items[], int numItems, char *menuName);
void homePage(int *option);
void studyTracker();
void studyTrackerData();
void resetTrackerData();
void TrackerDataHistory();
void studyTrackerMenu(int *option);
void allTasks();
void addTasks();
void resetTasks();
void completedTasks();
void Tasks(int *option);
void addEvent();
void showEvent();
void clearEvents();
int GetStartingDay(int year);
void Calender(int *option);
void mindTwisterQuestions(int maxValue, int minValue);
void progress();
void MindTwister(int *option);

// main function
int main()
{
    // for random number generator
    srand(time(NULL));

    // logo
    mainLogo();
    randomInspiration();
    printf("Press Enter To start (any other key to exit)...");
    char inputMainLogo;
    inputMainLogo = getch();

    int Option; // For selecting in the main menu
    if (inputMainLogo == 'q')
    {
        printf("\nExit...");
        return 0;
    }
    if (inputMainLogo == '\r')
    {
        // Main Menu
        homePage(&Option);
    }

    // Option Page
    while (1)
    {

        switch (Option)
        {
        case 0:
            studyTrackerMenu(&Option);
            break;

        case 1:
            Tasks(&Option);
            break;

        case 2:
            Calender(&Option);
            break;

        case 3:
            MindTwister(&Option);
            break;

        default:
            break;
        }

        if (Option == 3)
        {
            homePage(&Option);
        }
    }

    return 0;
}

// Time Function
int getTime()
{
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    return localTime->tm_year + 1900;
}

// random number generator
int randomNumberGenerator(int max, int min)
{
    return (rand() % (max - min + 1)) + min;
}

void randomInspiration()
{
    int select = randomNumberGenerator(9, 0);

    char *quotes[] = {
        "\"Success is not the key to happiness. Happiness is the key to success. If you love what you are doing, you will be successful. - Albert Schweitzer\"",
        "\"Believe you can and you're halfway there. - Theodore Roosevelt\"",
        "\"In the middle of every difficulty lies opportunity. - Albert Einstein\"",
        "\"Success is not final, failure is not fatal: It is the courage to continue that counts. - Winston Churchill\"",
        "\"The future belongs to those who believe in the beauty of their dreams. - Eleanor Roosevelt\"",
        "\"The only limit to our realization of tomorrow will be our doubts of today. - Franklin D. Roosevelt\"",
        "\"You miss 100% of the shots you don't take. - Wayne Gretzky\"",
        "\"It does not matter how slowly you go as long as you do not stop. - Confucius\"",
        "\"The only person you should try to be better than is the person you were yesterday. - Anonymous\"",
        "\"The greatest glory in living lies not in never falling, but in rising every time we fall. - Nelson Mandela\""};

    printf("%s\n\n", quotes[select]);
}

// logo function
void mainLogo()
{
    system("cls");
    printf("\n");
    printf("----- Welcome To -----");
    printf("\n");
    printf("\n");
    printf("  _____    _    _  _____  __   __    _____  _____      __       _______    _   _     _____   _____        _\n");
    printf(" |  __ \\  | |  | ||_   _| \\ \\ / /   |_   _||  __ \\    /  \\    /  _______\\ | | / /   | ____| |  __ \\      | |\n");
    printf(" | |  | | | |  | |  | |    \\ V /      | |  | |__) |  / /\\ \\  /  /         | |/ /    | |__   | |__) | ____| |____\n");
    printf(" | |  | | | |  | |  | |     | |       | |  |  _  /  / /__\\ \\ \\  \\         | |\\ \\    |  __|  |  _  / |____   ____|\n");
    printf(" | |__| | | |__| |  | |     | |       | |  | | \\ \\ / /____\\ \\ \\  \\_____/\\ | | \\ \\   | |___  | | \\ \\      | |\n");
    printf(" |_____/   \\____/   |_|     |_|       |_|  |_|  \\_\\\\/      \\/   \\_______/ |_|  \\_\\  |_____| |_|  \\_\\     |_|\n");
    printf("\n");
}

// selective code base
void selective_menu(int *options, char *items[], int numItems, char *menuName)
{
    char designBar[] = "***********************************";

    char input;
    int select = 0;

    while (1)
    {
        system("cls");
        system("color 30");

        printf("\n|  ---- %s -----  |\n\nUse UP, DOWN & ENTER key to select.\n\n", menuName);
        printf("************************************\n");

        for (int i = 0; i < numItems; i++)
        {
            if (i == select)
            {
                printf(" -> ");
            }
            else
            {
                printf("    ");
            }
            printf("%s\n", items[i]);
        }
        printf("************************************\n");

        input = getch();
        if (input == 'q' || input == 27)
        {
            printf("Program Exit.");
            break;
        }
        else if (input == 72 && select > 0)
        {
            select--;
        }
        else if (input == 80 && select < numItems - 1)
        {
            select++;
        }
        else if (input == '\r')
        {
            system("cls");

            *options = select;
            break;
        }
    }
}

// This section is for selecting main menu

void homePage(int *option)
{
    char menuName[] = "Home Page";
    int numItems = 5;
    char *mainMenuItems[5] = {"1. StudyTracker", "2. Tasks", "3. Calendar", "4. MindTwister", "5. Exit"};

    int selectedOption;

    selective_menu(&selectedOption, mainMenuItems, numItems, menuName);

    *option = selectedOption;
    if (*option == 4)
    {
        exit(0);
    }
}
//-------------------------- Study Tracker Part----------------------------------

void studyTracker()
{
    system("cls");
    system("color 4F");
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    printf("------------- Study tracker is selected -------------\n");

    int hr = 0, min = 0, sec = 0;
    int defaultHr = 0, defaultMin = 0, defaultSec = 0;

    char LabelName[100];

    printf("Enter Hour: ");
    scanf("%d", &hr);

    printf("Enter Minute: ");
    scanf("%d", &min);

    printf("Enter Seconds: ");
    scanf("%d", &sec);
    getchar();

    if (sec >= 5)
    {
        printf("Enter Label: ");
        gets(LabelName);

        while (1)
        {
            system("cls");

            printf("%d : %d : %d", defaultHr, defaultMin, defaultSec);
            defaultSec++;
            if (defaultSec == 60)
            {
                defaultMin++;
                defaultSec = 0;

                if (defaultMin == 60)
                {
                    defaultHr++;
                    defaultMin = 0;
                    if (defaultHr == 60)
                    {
                        defaultHr = 0;
                    }
                }
            }
            sleep(1);
            if (hr == defaultHr && min == defaultMin && sec == defaultSec)
            {
                system("cls");
                printf("Tracking Complete.\a\n"); // \a for a beep sound while executing

                FILE *trackerData, *trackerHistory;

                trackerData = fopen("studyTracker.txt", "a");
                trackerHistory = fopen("trackerHistory.txt", "a");

                fprintf(trackerData, "Subject: %s -> Time: %02d:%02d:%02d, Date: %02d/%02d/%d | %02d:%02d:%02d \n", LabelName, hr, min, sec, localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900, localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

                fprintf(trackerHistory, "Subject: %s -> Time: %02d:%02d:%02d, Date: %02d/%02d/%d | %02d:%02d:%02d \n", LabelName, hr, min, sec, localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900, localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

                fclose(trackerData);
                fclose(trackerHistory);

                printf("Press any key to continue...");
                getch();
                break;
            }
        }
    }
    else
    {
        printf("Too short time. (at least 5 sec needed.)\n");
        printf("Press any key for return...\n");
        getch();
        studyTracker();
    }
}
void studyTrackerData()
{
    system("cls");
    printf(" |  ----     History      -----  |\n\n");

    char trackerData;
    FILE *timeTracker;
    timeTracker = fopen("studyTracker.txt", "r");

    while ((trackerData = fgetc(timeTracker)) != EOF)
    {
        printf("%c", trackerData);
    }
    fclose(timeTracker);
    printf("\nPress any key to continue...");
    getch();
}
void resetTrackerData()
{
    FILE *clearData = fopen("studyTracker.txt", "w");

    fclose(clearData);

    printf("Cleared Successfully\n");
    printf("Press any key...");
    getch();
}
void TrackerDataHistory()
{
    FILE *dataHistory = fopen("trackerHistory.txt", "r");

    char data;

    while ((data = fgetc(dataHistory)) != EOF)
    {
        printf("%c", data);
    }
    fclose(dataHistory);

    printf("Press any key...");
    getch();
}

void studyTrackerMenu(int *option)
{
    char menuName[] = "Study Tracker";
    int numItems = 5;
    char *mainMenuItems[5] = {"1. Track Study", "2. Tracking Data", "3. Reset Tracking Data", "4. History", "5. Home Page"};

    int optionValue;
    selective_menu(&optionValue, mainMenuItems, numItems, menuName);

    *option = optionValue;
    if (*option == 4)
    {
        *option = 3;
    }
    else
    {
        switch (*option)
        {
        case 0:
            studyTracker();
            studyTrackerMenu(option);
            break;
        case 1:
            studyTrackerData();
            studyTrackerMenu(option);
            break;
        case 2:
            resetTrackerData();
            studyTrackerMenu(option);
            break;
        case 3:
            TrackerDataHistory();
            studyTrackerMenu(option);
            break;

        default:
            break;
        }
    }
}
// ------------------------ Task Part ----------------------

void allTasks()
{
    system("cls");
    printf(" |  ----     All Tasks      -----  |\n\n");

    char tasksData;
    FILE *tasks;
    tasks = fopen("tasksData.txt", "r");

    while ((tasksData = fgetc(tasks)) != EOF)
    {
        printf("%c", tasksData);
    }
    fclose(tasks);

    printf("\nPress any key to continue...");
    getch();
}

void addTasks()
{
    system("cls");
    printf(" |  ----     Add Task      -----  |\n");

    char addTasks[200];
    printf("Add Task: ");
    scanf(" %[^\n]", addTasks);

    FILE *taskData, *completed_task;
    taskData = fopen("tasksData.txt", "a");
    completed_task = fopen("completedTask.txt", "a");
    fprintf(taskData, "=-> %s\n", addTasks);
    fprintf(completed_task, "=-> %s\n", addTasks);
    fclose(taskData);
    fclose(completed_task);
}

void resetTasks()
{
    FILE *resetAllTasks = fopen("tasksData.txt", "w");
    fclose(resetAllTasks);

    printf("Tasks cleared successfully.\n");
    printf("Press any key to continue...");
    getch();
}

void completedTasks()
{
    system("cls");
    printf(" |  ----     Completed Tasks      -----  |\n\n");

    char tasksData;
    FILE *tasks;
    tasks = fopen("completedTask.txt", "r");

    while ((tasksData = fgetc(tasks)) != EOF)
    {
        printf("%c", tasksData);
    }
    fclose(tasks);

    printf("\nPress any key to continue...");
    getch();
}

// main task functions
void Tasks(int *option)
{
    system("cls");
    char menuName[] = "Tasks";
    int numItems = 5;
    char *mainMenuItems[5] = {"1. View All Tasks", "2. Add Task", "3. Reset Tasks", "4. Completed Tasks", "5. Home Page"};

    int optionValue;
    selective_menu(&optionValue, mainMenuItems, numItems, menuName);

    *option = optionValue;

    switch (*option)
    {
    case 0:
        allTasks();
        Tasks(option);
        break;
    case 1:
        addTasks();
        Tasks(option);
        break;
    case 2:
        resetTasks();
        Tasks(option);
        break;
    case 3:
        completedTasks();
        Tasks(option);
        break;
    default:
        break;
    }
    if (*option == 4)
    {
        *option = 3;
    }
}

// ------------------ Even & calander --------------------------
void addEvent()
{
    system("cls");

    printf(" |  ----     Add Events      -----  |\n");
    char eventName[50];
    int eventDate = 0, eventYear = 0, eventMonth = 0;

    printf("Event Name: ");
    scanf(" %[^\n]", eventName);

    printf("Event Date: ");
    scanf("%d", &eventDate);
    printf("Event Month: ");
    scanf("%d", &eventMonth);
    printf("Event Year: ");
    scanf("%d", &eventYear);

    fflush(stdin);

    FILE *eventData;
    eventData = fopen("eventData.txt", "a");

    fprintf(eventData, "Name: %s, %d/%d/%d\n", eventName, eventDate, eventMonth, eventYear);
    fclose(eventData);

    printf("Data saved successfully!\n");
    getchar();
}
void showEvent()
{
    system("cls");
    printf(" |  ----     Events      -----  |\n");
    char dataFromEvent;
    FILE *showEvents;
    showEvents = fopen("eventData.txt", "r");

    while ((dataFromEvent = fgetc(showEvents)) != EOF)
    {
        printf("%c", dataFromEvent);
    }

    fclose(showEvents);
}

void clearEvents()
{
    FILE *clearEvents = fopen("eventData.txt", "w");

    fclose(clearEvents);

    printf("Cleared Successfully\n");
    printf("Press any key...");
    getch();
}

int GetStartingDay(int year)
{
    int firatDay;
    firatDay = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return firatDay;
}
void Calender(int *option)
{
    system("cls");
    char menuName[] = "Calender";
    int numItems = 5;
    char *mainMenuItems[5] = {"1. Calender Map", "2. All Events", "3. Add Events", "4. Clear Events", "5. Home Page"};

    int optionValue;
    selective_menu(&optionValue, mainMenuItems, numItems, menuName);

    *option = optionValue;

    int year, day, month, weekDay = 0, startingDay;

    switch (*option)
    {
    case 0:

        year = getTime();
        char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            monthDays[1] = 29;
        }

        startingDay = GetStartingDay(year);
        printf(" |  ----     Calender      -----  |\n");
        printf("|-------[Current Year: %d]-------|\n", year);

        for (int month = 0; month < 12; month++)
        {
            printf("\n\n---------- %s, %d----------\n", months[month], year);
            printf("  Sun  Mon  Tue  Wed Thurs Fri Sat \n");

            for (weekDay = 0; weekDay < startingDay; weekDay++)
            {
                printf("     ");
            }

            for (int day = 1; day <= monthDays[month]; day++)
            {
                printf("%5d", day);
                if (++weekDay > 6)
                {
                    printf("\n");
                    weekDay = 0;
                }
                startingDay = weekDay;
            }
        }

        printf("\n\nPress any key to continue...\n");
        getch();
        Calender(option);
        break;

    case 1:
        showEvent();
        printf("\nAny key to continue...");
        getch();
        Calender(option);
        break;

    case 2:
        addEvent();
        Calender(option);
        break;

    case 3:
        clearEvents();
        Calender(option);
        break;

    default:
        break;
    }
    if (*option == 4)
    {
        *option = 3;
    }
}

// ----------------- Mind Twister ------------------------

void mindTwisterQuestions(int maxValue, int minValue)
{
    int number_1, number_2, ans, optionvalue;
    int mark = 0;

    for (int i = 1; i <= 5; i++)
    {
        optionvalue = randomNumberGenerator(3, 1);
        number_1 = randomNumberGenerator(maxValue, minValue);
        number_2 = randomNumberGenerator(maxValue, minValue);

        switch (optionvalue)
        {
        case 1:
            printf("%d. %d + %d = ?\n", i, number_1, number_2);
            printf("=> ");
            scanf("%d", &ans);
            if (ans == number_1 + number_2)
            {
                mark++;
            }
            break;
        case 2:
            printf("%d. %d - %d = ?\n", i, number_1, number_2);
            printf("=> ");
            scanf("%d", &ans);
            if (ans == number_1 - number_2)
            {
                mark++;
            }
            break;
        case 3:
            printf("%d. %d x %d = ?\n", i, number_1, number_2);
            printf("=> ");
            scanf("%d", &ans);
            if (ans == number_1 * number_2)
            {
                mark++;
            }
            break;
        default:
            break;
        }
    }

    FILE *progression = fopen("progress.txt", "a");
    fprintf(progression, "Total Mark: %d/5\n", mark);
    fclose(progression);

    printf("Total Mark: %d/5\n", mark);
    printf("Press any key to continue...");
    getch();
}

void progress()
{
    system("cls");
    printf(" |  ----     Progress      -----  |\n");
    char progressData;
    FILE *progressDataFile = fopen("progress.txt", "r");

    while ((progressData = fgetc(progressDataFile)) != EOF)
    {
        printf("%c", progressData);
    }
    fclose(progressDataFile);

    printf("\nPress any key to continue...");
    getch();
}

void MindTwister(int *option)
{
    char menuName[] = "MindTwister";
    int numItems = 5;
    char *mainMenuItems[5] = {"1. Easy", "2. Hard", "3. Champion", "4. Progress", "5. Home Page"};

    int optionValue;
    selective_menu(&optionValue, mainMenuItems, numItems, menuName);
    *option = optionValue;

    switch (*option)
    {
    case 0:
        mindTwisterQuestions(100, 1);
        MindTwister(option);
        break;
    case 1:
        mindTwisterQuestions(1000, 50);
        MindTwister(option);
        break;
    case 2:
        mindTwisterQuestions(1000000, 1000);
        MindTwister(option);
        break;
    case 3:
        progress();
        MindTwister(option);
        break;
    default:
        break;
    }
    if (*option == 4)
    {
        *option = 3;
    }
}
// complete
