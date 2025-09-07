#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "appointment.h"
#include "records.h"
#include "file_manager.h"

int main() {
    int choice;
    loadData();

    printf("Welcome to Hospital Management System\n");
    if (!login()) {
        printf("Login failed!\n");
        return 1;
    }

    do {
        printf("\n1. Book Appointment\n2. Cancel Appointment\n3. View Appointments\n4. Manage Records\n5. Save & Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); // clear newline
        switch (choice) {
            case 1: bookAppointment(); break;
            case 2: cancelAppointment(); break;
            case 3: viewAppointments(); break;
            case 4: manageRecords(); break;
            case 5: saveData(); printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
