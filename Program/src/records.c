#include <stdio.h>
#include <string.h>
#include "../include/records.h"
#include "../include/file_manager.h"

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0, doctorCount = 0;

void manageRecords() {
    int choice;
    printf("1. Add Patient\n2. Add Doctor\n3. View Patients\n4. View Doctors\nEnter your choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }
    getchar(); // clear newline from buffer

    switch (choice) {
        case 1: // Add Patient
            if (patientCount >= MAX_PATIENTS) {
                printf("Cannot add more patients. Max limit reached.\n");
                break;
            }
            {
                Patient p;
                printf("Enter patient name: ");
                fgets(p.name, sizeof(p.name), stdin);
                p.name[strcspn(p.name, "\n")] = 0;

                printf("Enter age: ");
                if (scanf("%d", &p.age) != 1) {
                    printf("Invalid age!\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar(); // clear newline
                patients[patientCount++] = p;
                printf("Patient added.\n");
                saveData(); // Save after adding
            }
            break;

        case 2: // Add Doctor
            if (doctorCount >= MAX_DOCTORS) {
                printf("Cannot add more doctors. Max limit reached.\n");
                break;
            }
            {
                Doctor d;
                printf("Enter doctor name: ");
                fgets(d.name, sizeof(d.name), stdin);
                d.name[strcspn(d.name, "\n")] = 0;

                printf("Enter specialization: ");
                fgets(d.specialization, sizeof(d.specialization), stdin);
                d.specialization[strcspn(d.specialization, "\n")] = 0;

                doctors[doctorCount++] = d;
                printf("Doctor added.\n");
                saveData(); // Save after adding
            }
            break;

        case 3: // View Patients
            if (patientCount == 0) {
                printf("No patients found.\n");
            } else {
                for (int i = 0; i < patientCount; i++) {
                    printf("Patient: %s | Age: %d\n", patients[i].name, patients[i].age);
                }
            }
            break;

        case 4: // View Doctors
            if (doctorCount == 0) {
                printf("No doctors found.\n");
            } else {
                for (int i = 0; i < doctorCount; i++) {
                    printf("Doctor: %s | Specialization: %s\n", doctors[i].name, doctors[i].specialization);
                }
            }
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }
}
