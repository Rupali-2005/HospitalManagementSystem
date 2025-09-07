# Hospital Management System

A simple **C-based console application** that manages a hospital's patients, doctors, and appointments. Data persists across runs using text files, allowing the system to retain all records between sessions.

## Features

- **User Authentication**: Simple login system (username: `admin`, password: `admin`).  
- **Patient Management**: Add and view patient records.  
- **Doctor Management**: Add and view doctor records.  
- **Appointment Management**: Book, cancel, and view appointments.  
- **Persistent Storage**: Data is saved to text files (`patients.txt`, `doctors.txt`, `appointments.txt`) and loaded automatically on program start.  
- **Safe Input Handling**: Prevents buffer overflow using fixed-length input and proper parsing.

## File Structure
```text
├── Program/
│ ├── include/
│ │ ├── appointment.h
│ │ ├── file_manager.h
│ │ ├── login.h
│ │ └── records.h
│ └── src/
│ ├── appointment.c
│ ├── file_manager.c
│ ├── login.c
│ ├── main.c
│ └── records.c
├── Document/
│ ├── patients.txt # Generated automatically
│ ├── doctors.txt # Generated automatically
│ └── appointments.txt # Generated automatically
└── README.md
```

## How to Compile and Run

1. **Compile the project** using GCC:

```bash
gcc Program/src/*.c -IProgram/include -o hospita
./hospital      # Linux/macOS
hospital.exe    # Windows
```
## Usage Notes

## Login Credentials:
- **Username:** admin
- **Password:** admin

## Data Persistence:
- All patients, doctors, and appointments are saved automatically when you choose Save & Exit.
- Files are human-readable (.txt) and located in the project directory.

## Future Improvements
- Implement role-based access (admin, doctor, receptionist).
- Add search functionality for patients/doctors/appointments.
- Integrate a GUI or web interface.
- Encrypt sensitive data like passwords.

**Author: Rupali Rana**
https://github.com/Rupali-2005/HospitalManagementSystem


