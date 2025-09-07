#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#define MAX_APPOINTMENTS 100

typedef struct {
    char patientName[50];
    char doctorName[50];
    char date[20];
    char time[10];
} Appointment;

extern Appointment appointments[MAX_APPOINTMENTS];
extern int appointmentCount;

void bookAppointment();
void cancelAppointment();
void viewAppointments();

#endif
