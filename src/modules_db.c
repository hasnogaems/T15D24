#include <stdio.h>

typedef struct {
    int moduleID;
    char moduleName[20];
    int memoryLevel;
    int cellNumber;
    int deletionFlag;
} MODULES;

// Function prototype for the operations
void select(char *filename);

int main() {
    int choice;

    while (1) {
        printf("-----MENU-----\n");
        printf("1. SELECT from master_levels.db\n");
        printf("2. SELECT from master_modules.db\n");
        printf("3. SELECT from master_status_events.db\n");
        printf("4. EXIT\n");
        printf("Choose a menu option: \n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                select("master_levels.db");  // Call the SELECT function for master_levels.db
                break;
            case 2:
                select("master_modules.db");  // Call the SELECT function for master_modules.db
                break;
            case 3:
                select("master_status_events.db");  // Call the SELECT function for master_status_events.db
                break;
            case 4:
                printf("Exiting...\n");
                return 0;  // Terminate the program
            default:
                printf("Invalid choice, please enter again.\n");
                break;
        }
    }

    return 0;
}