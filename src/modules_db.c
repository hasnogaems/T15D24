#include <stdio.h>

#include "database.h"
int main() {
    int choice;
    char* filename;

    while (1) {
        printf("-----MENU-----\n");
        printf("1. SELECT from master_levels.db\n");
        printf("2. SELECT from master_modules.db\n");
        printf("3. SELECT from master_status_events.db\n");
        printf("4. INSERT into master_levels.db\n");
        printf("5. INSERT into master_modules.db\n");
        printf("6. INSERT into master_status_events.db\n");
        printf("7. UPDATE module in master_levels.db\n");
        printf("8. UPDATE module in master_modules.db\n");
        printf("9. UPDATE module in master_status_events.db\n");
        printf("10. EXIT\n");
        printf("Choose a menu option: \n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                filename = "master_levels.db";
                select(filename);
                break;
            case 2:
                filename = "master_modules.db";
                select(filename);
                break;
            case 3:
                filename = "master_status_events.db";
                select(filename);
                break;
            case 4:
                filename = "master_levels.db";
                insert(filename);
                break;
            case 5:
                filename = "master_modules.db";
                insert(filename);
                break;
            case 6:
                filename = "master_status_events.db";
                insert(filename);
                break;
            case 7:
                filename = "master_levels.db";
                update(filename);
                break;
            case 8:
                filename = "master_modules.db";
                update(filename);
                break;
            case 9:
                filename = "master_status_events.db";
                update(filename);
                break;
            case 10:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please enter again.\n");
                break;
        }
    }

    return 0;
}