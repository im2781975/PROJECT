#include<stdio.h>
#include<string.h>

#define MAX_ALUMNI 100
#define MAX_ACHIEVEMENTS 5
#define MAX_STUDENTS 100
#define MAX_ADMINS 5

typedef struct {
    char title[50];
    char description[250];
}
Achievement;

typedef struct{
    char name[50];
    int graduationYear;
    Achievement achievements[MAX_ACHIEVEMENTS];
    int numAchievements;
}Alumni;

typedef struct{
    char name[50];
    char username[50];
    char password[50];
}Student;

typedef struct{
    char username[50];
    char password[50];
}Admin;

void uploadAchievement(Alumni *alumni);
void trackAlumniAchievements(const Alumni *alumni);
void alumniCommunication(const Alumni *alumni, const Student *students);
int studentLogin(const Student *students, int numStudents);
int adminLogin(const Admin *admins, int numAdmins);

int main(){
    Alumni alumni[MAX_ALUMNI]={0};
    Student students[MAX_STUDENTS]={
        {
            "Student1", "user1", "pass1"},{
            "Student2", "user2", "pass2"}
    };
    Admin admins[MAX_ADMINS]={
            {
                "admin1", "adminpass1"
            },
            {
                "admin2", "adminpass2"
            },
        };

        int numAlumni=0;
        int numStudents=2;
        int numAdmins=2;
        int choice;
        int loggedInStudentIndex = -1;
        int loggedInAdminIndex = -1;

        do{
            printf("\nAlumni Relations System\n");
            printf("1. Student Login\n");
            printf("2. Alumni Upload Achievements\n");
            printf("3. Track Alumni Achievements\n");
            printf("4. Alumni Communication\n");
            printf("5. Admin Login\n");
            printf("6. Exit\n");
            printf("Enter your Choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: loggedInStudentIndex = studentLogin(students, numStudents);
                if(loggedInStudentIndex!=-1){
                    printf("Student %s logged in successfully.\n", students[loggedInStudentIndex].name);
                }else{
                    printf("Login failed. Invalid username or password.\n");
                }
                break;
                case 2:
                if (loggedInStudentIndex !=-1){
                    printf("Only alumni can upload achievements.Please log out first.\n");
                }else{
                    uploadAchievement(&alumni[numAlumni]);
                    numAlumni++;
                }
                break;
                case 3:
                trackAlumniAchievements(alumni);
                break;
                case 4:
                if (loggedInStudentIndex==-1){
                    alumniCommunication(alumni, students);
                }else{
                    printf("Only alumni can send messages.Please log out first.\n");
                }
                break;
                case 5:
                if (loggedInStudentIndex == -1) {
                    loggedInAdminIndex = adminLogin(admins, numAdmins);
                    if (loggedInAdminIndex != -1){
                        printf("Admin %s logged in successfully.\n", admins[loggedInAdminIndex].username);
                    }else{
                        printf("Login failed. Invalid username or password.\n");
                    }
                }else{
                    printf("Please log out as a student before in as an admin.\n");
                }
                break;
                case 6:
                printf("Exiting program.\n");
                break;

                default:
                printf("Invalid Choice. Please enter a valid option.\n");

            }

        } while (choice!=6);
        return 0;
    }
    void uploadAchievement(Alumni *alumni){
        printf("Enter Alumni name: ");
        scanf("%s", alumni->name);

        printf("Enter graduation year: ");
        scanf("%d", alumni->graduationYear);

        printf("Enter the number of achievements (max %d): ", MAX_ACHIEVEMENTS);
        scanf("%d", &alumni->numAchievements);

        printf("Enter achievements: \n");
        for (int i= 0; i<alumni->numAchievements; i++){
            printf("Achievement %d:\n", i+1);
            printf("Title: ");
            scanf("%s", alumni->achievements[i].title);
            printf("Description: ");
             scanf("%s", alumni->achievements[i].description);
        }

    }
    void trackAlumniAchievements(const Alumni *alumni){
        char searchName[50];
         printf("Enter alumni name and track achievements: ");
         scanf("%s", searchName);

         int alumniFound=0;
         for(int i=0; i<MAX_ALUMNI; i++){
            if(strcmp(alumni[i].name, searchName) == 0){
                alumniFound = 1;
                printf("Alumni found: %s\n", alumni[i].name);
                printf("Achievement:\n");
                for(int j=0; j<alumni[i].numAchievements; j++){
                    printf("Achievements %d: %s - %s\n", j+1, alumni[i].achievements[j].title, alumni[i].achievements[j].description);
                }
                break;
            }
         }
         if(!alumniFound){
            printf("Alumni not found.\n");
         }
    }
    void alumniCommunication(const Alumni *alumni, const Student *students){
        char alumniName[50];
        printf("Enter alumni name :");
        scanf("%s", alumniName);

        char message[250];
        printf("Enter your message:");
        scanf("%s", message);

         printf("Message sent from %s:\n", alumniName);

         for (int i=0; i<MAX_STUDENTS; i++){
         if(strlen(students[i].name) > 0){
             printf("To student %s: %s\n", students[i].name, message);
         }
    }
}

int studentLogin(const Student *students, int numStudents){
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for(int i=0; i<numStudents; i++){
        if(strcmp(students[i].username, username) == 0 && strcmp(students[i].password, password) == 0){
            return i;
        }
    }
    return -1;
}
int adminLogin(const Admin *admins, int numAdmins){
    char username[50];
    char password[50];

    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    for(int i=0; i<numAdmins; i++){
        if (strcmp(admins[i].username, username) == 0 && strcmp(admins[i].password, password) == 0){
            return i;
        }
    }
    return -1;
}
