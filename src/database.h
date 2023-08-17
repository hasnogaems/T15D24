#ifndef DATABASE_H
#define DATABASE_H
#include <stdio.h>
typedef struct {
    int moduleID;
    char moduleName[30];
    int memoryLevel;
    int cellNumber;
    int deletionFlag;
} MODULES;

typedef struct {
    int memoryLevel;
    int numberOfCells;
    int securityFlag;
} LEVELS;

typedef struct {
    int eventID;
    int moduleID;
    int newModuleStatus;
    char statusChangeDate[11];  // "dd.mm.yyyy\0"
    char statusChangeTime[9];   // "hh:mm:ss\0"
} STATUS_EVENTS;

void select();
void update();
void delete ();
void insert();
MODULES read_record_from_MODULES(FILE *pfile, int index);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);

#endif

/*
ENTITY *select(FILE *db, int id);
int delete(FILE *db, int id);
int insert(FILE *db, ENTITY *entity);
int update(FILE *db, int id, ENTITY *entity);
*/
