#ifndef RECORDS_H
#define RECORDS_H

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50

typedef struct {
    char name[50];
    int age;
} Patient;

typedef struct {
    char name[50];
    char specialization[50];
} Doctor;

extern Patient patients[MAX_PATIENTS];
extern Doctor doctors[MAX_DOCTORS];
extern int patientCount;
extern int doctorCount;

void manageRecords();

#endif
