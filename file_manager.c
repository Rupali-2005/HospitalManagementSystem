#include <stdio.h>
#include <string.h>
#include "records.h"
#include "appointment.h"

// Load data from text files
void loadData() {
    FILE *fp;
    char line[200];

    // Load patients
    fp = fopen("patients.txt", "r");
    if (fp) {
        patientCount = 0;
        while (fgets(line, sizeof(line), fp) && patientCount < MAX_PATIENTS) {
            line[strcspn(line, "\n")] = 0; // remove newline
            sscanf(line, "%49[^|]|%d", patients[patientCount].name, &patients[patientCount].age);
            patientCount++;
        }
        fclose(fp);
    }

    // Load doctors
    fp = fopen("doctors.txt", "r");
    if (fp) {
        doctorCount = 0;
        while (fgets(line, sizeof(line), fp) && doctorCount < MAX_DOCTORS) {
            line[strcspn(line, "\n")] = 0;
            sscanf(line, "%49[^|]|%49[^\n]", doctors[doctorCount].name, doctors[doctorCount].specialization);
            doctorCount++;
        }
        fclose(fp);
    }

    // Load appointments
    fp = fopen("appointments.txt", "r");
    if (fp) {
        appointmentCount = 0;
        while (fgets(line, sizeof(line), fp) && appointmentCount < MAX_APPOINTMENTS) {
            line[strcspn(line, "\n")] = 0;
            sscanf(line, "%49[^|]|%49[^|]|%19[^|]|%9[^\n]",
                   appointments[appointmentCount].patientName,
                   appointments[appointmentCount].doctorName,
                   appointments[appointmentCount].date,
                   appointments[appointmentCount].time);
            appointmentCount++;
        }
        fclose(fp);
    }

    printf("Data loaded successfully.\n");
}

// Save data to text files
void saveData() {
    FILE *fp;

    // Save patients
    fp = fopen("patients.txt", "w");
    if (fp) {
        for (int i = 0; i < patientCount; i++) {
            fprintf(fp, "%s|%d\n", patients[i].name, patients[i].age);
        }
        fclose(fp);
    }

    // Save doctors
    fp = fopen("doctors.txt", "w");
    if (fp) {
        for (int i = 0; i < doctorCount; i++) {
            fprintf(fp, "%s|%s\n", doctors[i].name, doctors[i].specialization);
        }
        fclose(fp);
    }

    // Save appointments
    fp = fopen("appointments.txt", "w");
    if (fp) {
        for (int i = 0; i < appointmentCount; i++) {
            fprintf(fp, "%s|%s|%s|%s\n",
                    appointments[i].patientName,
                    appointments[i].doctorName,
                    appointments[i].date,
                    appointments[i].time);
        }
        fclose(fp);
    }

    printf("Data saved successfully.\n");
}
