#include <stdio.h>
#include <string.h>
#include "../include/appointment.h"
#include "../include/file_manager.h"

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void bookAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list full!\n");
        return;
    }

    Appointment a;
    printf("Enter Patient Name: ");
    fgets(a.patientName, sizeof(a.patientName), stdin);
    a.patientName[strcspn(a.patientName, "\n")] = 0;

    printf("Enter Doctor Name: ");
    fgets(a.doctorName, sizeof(a.doctorName), stdin);
    a.doctorName[strcspn(a.doctorName, "\n")] = 0;

    printf("Enter Date (dd-mm-yyyy): ");
    fgets(a.date, sizeof(a.date), stdin);
    a.date[strcspn(a.date, "\n")] = 0;

    printf("Enter Time (hh:mm): ");
    fgets(a.time, sizeof(a.time), stdin);
    a.time[strcspn(a.time, "\n")] = 0;

    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].doctorName, a.doctorName) == 0 &&
            strcmp(appointments[i].date, a.date) == 0 &&
            strcmp(appointments[i].time, a.time) == 0) {
            printf("Dr. %s is already booked on %s at %s.\n", a.doctorName, a.date, a.time);
            return;
        }
    }

    appointments[appointmentCount++] = a;
    saveData(); // Save automatically after booking
    printf("Appointment booked successfully.\n");
}

void cancelAppointment() {
    char name[50];
    printf("Enter Patient Name to cancel appointment: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].patientName, name) == 0) {
            for (int j = i; j < appointmentCount - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            appointmentCount--;
            saveData(); // Save automatically after canceling
            printf("Appointment cancelled.\n");
            return;
        }
    }
    printf("No appointment found for that patient.\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    for (int i = 0; i < appointmentCount; i++) {
        printf("Patient: %s | Doctor: %s | Date: %s | Time: %s\n",
               appointments[i].patientName,
               appointments[i].doctorName,
               appointments[i].date,
               appointments[i].time);
    }
}
