#include <stdio.h>
#include <string.h>
#include "../include/file_manager.h"
#include "../include/records.h"
#include "../include/appointment.h"

// File paths
#define PATIENTS_FILE "C:/Users/rupal/OneDrive/Hospital Management System/Document/patients.txt"
#define DOCTORS_FILE "C:/Users/rupal/OneDrive/Hospital Management System/Document/doctors.txt"
#define APPOINTMENTS_FILE "C:/Users/rupal/OneDrive/Hospital Management System/Document/appointments.txt"

// ---- Save all data ----
void saveData() {
    FILE *fp;

    // Save patients
    fp = fopen(PATIENTS_FILE, "w");
    if (fp) {
        for (int i = 0; i < patientCount; i++)
            fprintf(fp, "%s,%d\n", patients[i].name, patients[i].age);
        fclose(fp);
    } else {
        printf("Error saving patients data.\n");
    }

    // Save doctors
    fp = fopen(DOCTORS_FILE, "w");
    if (fp) {
        for (int i = 0; i < doctorCount; i++)
            fprintf(fp, "%s,%s\n", doctors[i].name, doctors[i].specialization);
        fclose(fp);
    } else {
        printf("Error saving doctors data.\n");
    }

    // Save appointments
    fp = fopen(APPOINTMENTS_FILE, "w");
    if (fp) {
        for (int i = 0; i < appointmentCount; i++)
            fprintf(fp, "%s,%s,%s,%s\n",
                    appointments[i].patientName,
                    appointments[i].doctorName,
                    appointments[i].date,
                    appointments[i].time);
        fclose(fp);
    } else {
        printf("Error saving appointments data.\n");
    }
}

// ---- Load all data ----
void loadData() {
    char line[200];

    // ---- Load patients ----
    FILE *fp = fopen(PATIENTS_FILE, "r");
    if (fp) {
        patientCount = 0;
        while (patientCount < MAX_PATIENTS && fgets(line, sizeof(line), fp)) {
            if (strlen(line) < 3) continue; // skip empty lines
            sscanf(line, "%49[^,],%d", patients[patientCount].name, &patients[patientCount].age);
            patientCount++;
        }
        fclose(fp);
    }

    // ---- Load doctors ----
    fp = fopen(DOCTORS_FILE, "r");
    if (fp) {
        doctorCount = 0;
        while (doctorCount < MAX_DOCTORS && fgets(line, sizeof(line), fp)) {
            if (strlen(line) < 3) continue; // skip empty lines
            sscanf(line, "%49[^,],%49[^\n]", doctors[doctorCount].name, doctors[doctorCount].specialization);
            doctorCount++;
        }
        fclose(fp);
    }

    // ---- Load appointments ----
    fp = fopen(APPOINTMENTS_FILE, "r");
    if (fp) {
        appointmentCount = 0;
        while (appointmentCount < MAX_APPOINTMENTS && fgets(line, sizeof(line), fp)) {
            if (strlen(line) < 5) continue; // skip empty lines
            sscanf(line, "%49[^,],%49[^,],%19[^,],%9[^\n]",
                   appointments[appointmentCount].patientName,
                   appointments[appointmentCount].doctorName,
                   appointments[appointmentCount].date,
                   appointments[appointmentCount].time);
            appointmentCount++;
        }
        fclose(fp);
    }
}
