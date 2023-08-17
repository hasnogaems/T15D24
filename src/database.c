#include "database.h"

#include <stdio.h>
// Select function
void select(char *filename) {
    FILE *fp;
    MODULES mod;

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    while (fread(&mod, sizeof(MODULES), 1, fp))
        printf("ID: %d, Name: %s, Memory Level: %d, Cell Number: %d, Deletion Flag: %d\n", mod.moduleID,
               mod.moduleName, mod.memoryLevel, mod.cellNumber, mod.deletionFlag);

    fclose(fp);
}
void insert(const char *filename) {
    FILE *fp;
    MODULES mod;

    printf("Enter the module details:\n");

    printf("ID: ");
    scanf("%d", &mod.moduleID);

    printf("Name: ");
    scanf("%10000s", mod.moduleName);

    printf("Memory Level: ");
    scanf("%d", &mod.memoryLevel);

    printf("Cell Number: ");
    scanf("%d", &mod.cellNumber);

    printf("Deletion Flag (1 for true, 0 for false): ");
    scanf("%d", &mod.deletionFlag);

    fp = fopen(filename, "ab");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    fwrite(&mod, sizeof(MODULES), 1, fp);
    printf("Data inserted successfully into %s.\n", filename);
    fclose(fp);
}

void update(const char *filename) {
    FILE *fp;
    MODULES mod;
    int id, isFound = 0;

    printf("Enter the ID of the module you want to update:\n");
    scanf("%d", &id);

    fp = fopen(filename, "rb+");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    while (fread(&mod, sizeof(MODULES), 1, fp)) {
        if (mod.moduleID == id) {
            printf("Enter new ID:\n");
            scanf("%d", &mod.moduleID);

            printf("Enter new Name (up to 20 characters):\n");
            scanf("%1000s", mod.moduleName);

            printf("Enter new Memory Level:\n");
            scanf("%d", &mod.memoryLevel);

            printf("Enter new Cell Number:\n");
            scanf("%d", &mod.cellNumber);

            printf("Enter new Deletion Flag:\n");
            scanf("%d", &mod.deletionFlag);

            fseek(fp, -sizeof(MODULES), SEEK_CUR);
            fwrite(&mod, sizeof(MODULES), 1, fp);
            isFound = 1;
            break;
        }
    }

    if (!isFound) {
        printf("Module not found.\n");
    }

    fclose(fp);
}

/*void delete () {
    FILE *fp;
    MODULES mod;
    int id, isFound = 0;

    printf("Enter the ID of the module you want to delete:\n");
    scanf("%d", &id);

    fp = fopen("modules.bin", "rb+");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    while (fread(&mod, sizeof(MODULES), 1, fp)) {
        if (mod.moduleID == id) {
            mod.deletionFlag = 1;
            fseek(fp, -sizeof(MODULES), SEEK_CUR);
            fwrite(&mod, sizeof(MODULES), 1, fp);
            isFound = 1;
            break;
        }
    }

    if (!isFound) {
        printf("Module not found.\n");
    }

    fclose(fp);
}*/

/*MODULES read_record_from_MODULES(FILE *pfile, int index) {
    // Calculation of the offset at which desired entry should be located from the beginning of the file.
    int offset = index * sizeof(MODULES);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Reading a record of the specified type from a file.
    MODULES record;
    fread(&record, sizeof(MODULES), 1, pfile);

    // For safety reasons, we return the file position pointer to the beginning of the file.
    rewind(pfile);

    // Return read record
    return record;
}*/
// Function to get file size in bytes.
/*int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Move the position pointer to the end of the file.
    size = ftell(
        pfile);  // Read the number of bytes from the beginning of the file to the current position pointer.
    rewind(pfile);  // For safety reasons, move the position pointer back to the beginning of the file.
    return size;
}*/

// int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(MODULES); }
