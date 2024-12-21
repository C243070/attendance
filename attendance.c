#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold attendance records
struct AttendanceRecord {
    char name[50];
    char date[15];
    char status[10]; // e.g., Present or Absent
};

// Function prototypes
void addRecord();
void displayRecords();

int main() {
    int choice;

    while (1) {
        printf("\nAttendance Monitoring System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new attendance record
void addRecord() {
    struct AttendanceRecord record;
    FILE *file = fopen("attendance.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Name: ");
    getchar(); // To consume the newline left by the previous input
    fgets(record.name, sizeof(record.name), stdin);
    record.name[strcspn(record.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Date (DD-MM-YYYY): ");
    fgets(record.date, sizeof(record.date), stdin);
    record.date[strcspn(record.date, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Status (Present/Absent): ");
    fgets(record.status, sizeof(record.status), stdin);
    record.status[strcspn(record.status, "\n")] = '\0'; // Remove trailing newline

    fprintf(file, "%s,%s,%s\n", record.name, record.date, record.status);
    fclose(file);

    printf("Record added successfully!\n");
}

// Function to display all attendance records
void displayRecords() {
    struct AttendanceRecord record;
    FILE *file = fopen("attendance.txt", "r");

    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nAttendance Records:\n");
    printf("-----------------------------\n");
    printf("Name               Date          Status\n");
    printf("-----------------------------\n");

    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", record.name, record.date, record.status) != EOF) {
        printf("%-18s %-12s %-10s\n", record.name, record.date, record.status);
    }

    fclose(file);
}