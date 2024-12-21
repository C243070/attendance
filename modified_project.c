#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records and length of names
#define MAX_RECORDS 100
#define MAX_NAME_LEN 50

// Define the structure to store attendance records
struct AttendanceRecord {
    int id;
    char name[MAX_NAME_LEN];
    char section;
    int isPresent;
};

// Declare an array to store the attendance records
struct AttendanceRecord records[MAX_RECORDS];
int recordCount = 0;

// Function to add a new record
void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Cannot add more records. The list is full.\n");
        return;
    }
    struct AttendanceRecord newRecord;
    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    printf("Enter Name: ");
    scanf("%s", newRecord.name);
    getchar(); // we use this to consume the leftover newline character from the previous input 
    printf("Enter Section: ");
    scanf("%c", &newRecord.section);
    printf("Enter 1 for Present or 0 for Absent: ");
    scanf("%d", &newRecord.isPresent);
    records[recordCount++] = newRecord;
    printf("Record added successfully!\n");
}

// Function to display all records
void displayRecords() {
    if (recordCount == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("ID\tName \t\t Section \t\tStatus\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%d\t%s\t\t %c\t\t%s\n", records[i].id, records[i].name,records[i].section, records[i].isPresent ? "Present" : "Absent");
    }
}

// Function to sort records by name (bubble sort)
void sortByName() {
    for (int i = 0; i < recordCount - 1; i++) {
        for (int j = 0; j < recordCount - i - 1; j++) {
            if (strcmp(records[j].name, records[j + 1].name) > 0) {
                struct AttendanceRecord temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

// Function to calculate attendance statistics
void attendenceCounter() {
    int presentCount = 0, absentCount = 0;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isPresent) {
            presentCount++;
        } else {
            absentCount++;
        }
    }
    printf("Attendance Statistics:\n");
    printf("  Present: %d\n", presentCount);
    printf("  Absent: %d\n", absentCount);
}


// Function to search for a record by ID
void searchRecord() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == id) {
            printf("Record found:\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Section: %s\n", records[i].section);
            printf("Status: %s\n", records[i].isPresent ? "Present" : "Absent");
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}
// Function to delete a record by ID

void updateRecord() {
    int id;
    int isPresent;
    
    printf("Enter ID to search: ");
    scanf("%d", &id);
 
    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == id) {
            printf("Record found:\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Name: %c\n", records[i].section);
            printf("Status: %s\n", records[i].isPresent ? "Present" : "Absent");

            printf("Update Student's Status:\n ");
            printf("Enter 1 for Present or 0 for Absent: ");
            scanf("%d", &isPresent);

            records[i].isPresent=isPresent;
            printf("Record updated successfully!\n");
        }
        else
            printf("Record with ID %d not found.\n", id);
    }
}
// Function to delete a record by ID
void deleteRecord() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == id) {
            for (int j = i; j < recordCount - 1; j++) {
                records[j] = records[j + 1];
            }
            recordCount--;
            printf("Record with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

int main() {
    int choice;
    while (1) {
        printf("\nAttendance Monitoring System\n");
        printf("1. Add Record\n");
        printf("2. Update Record\n");
        printf("3. Display Records\n");
        printf("4. Search Record\n");
        printf("5. Delete Record\n");
        printf("6. Sort Records by Name\n");
        printf("7. Calculate Attendance Statistics\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                updateRecord();
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                sortByName();
                displayRecords();
                break;
            case 7:
                attendenceCounter();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

    }
    return 0;
}