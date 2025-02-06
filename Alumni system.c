#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int ID;
    char name[30];
    int age;
    float CGPA;
    char address[50];
    char contact_number[20];
};

// Add students
void addstudents(struct student students[], int *count) {
    int addstudents;
    printf("\nNumbers of Students want to Add: ");
    scanf("%d", &addstudents);
    printf("Enter Students Details : \n");

    for (int i = 0; i < addstudents; i++) {
        printf("%d.\n", i + 1);
        printf("Enter Student ID : ");
        scanf("%d", &students[*count].ID);
        printf("Enter Student Name : ");
        scanf("%s", students[*count].name);
        printf("Enter Student Age : ");
        scanf("%d", &students[*count].age);
        printf("Enter Obtaing CGPA : ");
        scanf("%f", &students[*count].CGPA);
        printf("Enter Student Address : ");
        scanf("%s", students[*count].address);
        printf("Enter Contact Number : ");
        scanf("%s", students[*count].contact_number);
        printf("\n \n");
        (*count)++;
    }
}

// Display Students step -1
void showstudents(struct student students) {
    printf("Student ID: %d\n", students.ID);
    printf("Student Name: %s\t Age: %d\n", students.name, students.age);
    printf("Student CGPA: %.2f\n", students.CGPA);
    printf("Student Address: %s\t Student Contact Number: %s\n", students.address, students.contact_number);
    printf("********************************************************** ********************************************\n\n");
}

// Display Students by calling the SHOW STUDENTS function
void displayStudents(struct student students[], int count) {
    printf("\nStudents Details:\n");

    for (int i = 0; i < count; i++) {
        showstudents(students[i]);
    }
}

// Search Students
int searchStudentsByID(struct student students[], int count, int StudentId) {
    for (int i = 0; i < count; i++) {
        if (students[i].ID == StudentId) {
            return i;
            break;
        }
    }
    return -1;
}

// Update Students
void updateStudents(struct student *students) {
    printf("\nUpdate Students Details:\n");
    printf("Enter ID:");
    scanf("%d", &students->ID);
    printf("Enter Name:");
    scanf("%s", students->name);
    printf("Enter Age:");
    scanf("%d", &students->age);
    printf("Enter CGPA:");
    scanf("%f", &students->CGPA);
    printf("Enter Address:");
    scanf("%s", students->address);
    printf("Enter Contact Number:");
    scanf("%s", students->contact_number);
}

// Generate a Result sheet
void generateResultSheet(struct student students[], int count) {
    printf("\nResult sheet:\n");

    for (int i = 0; i < count; i++) {
        printf("[%d]\n", i + 1);
        printf("****\n");
        printf("Student ID : %d\t", students[i].ID);
        printf("\tStudent Name: %s\t", students[i].name);
        printf("\tStudent CGPA: %.2f\n", students[i].CGPA);
        printf("******************************************************** *********************************************************\n\n");
    }
}

int main() {
    struct student students[30];
    int count = 0;
    int searchId;
    int toUpdate;

    while (1) {
        printf("Start:\n1.Main Manu:\n2.exit\n\nClick:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while (1) {
                    printf("\nMenu\n\n");
                    printf("1. Add Student\n");
                    printf("2. Display Student\n");
                    printf("3. Search Student\n");
                    printf("4. Update Students Details\n");
                    printf("5. Students Result Sheet\n");
                    printf("6. Back\n");
                    int press;
                    printf("\npress:");
                    scanf("%d", &press);

                    switch (press) {
                        case 1:
                            addstudents(students, &count);
                            break;
                        case 2:
                            displayStudents(students, count);
                            break;
                        case 3:
                            printf("Enter the Student ID:");
                            scanf("%d", &searchId);
                            int FoundID = searchStudentsByID(students, count, searchId);
                            if (FoundID != -1) {
                                showstudents(students[FoundID]);
                                break;
                            } else {
                                printf("\nStudent not Found\n");
                            }
                            break;
                        case 4:
                            printf("Enter the Student ID(For Update):");
                            scanf("%d", &toUpdate);
                            for (int i = 0; i < count; i++) {
                                if (students[i].ID == toUpdate) {
                                    updateStudents(&students[i]);
                                }
                            }
                            break;
                        case 5:
                            generateResultSheet(students, count);
                            break;
                        case 6:
                            printf("Back");
                            exit(0);
                        default:
                            printf("Back page");
                            break;
                    }
                    break;
                }
                break;
            case 2:
                printf("Exiting The Program");
                exit(0);
            default:
                printf("Individual Choice");
                break;
        }
    }

    return 0;
}
