#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int id;
    char contact[20];
    char status[20];
    char achive[79];
};

void display(struct student s) {
    printf("-----------------------\n");
    printf("Name of student is : %s", s.name);
    printf("\nId of student is : %d:", s.id);
    printf("\nContact of student is : %s ", s.contact);
    printf("\nStatus of student is: %s", s.status);
    printf("\nAchive of student is: %s ", s.achive);
}

int main() {
    int flag=0;
    char ch;
    int n, id;
    char Username[30];
    char pass[50];
    int choice;

    do {
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\nEnter username: ");
        scanf("%s", Username);
        printf("\nEnter password: ");
        scanf("%s", pass);

        switch (choice) {
            case 1: {
                if (strcmp(Username, "Admin") == 0 && strcmp(pass, "1234") == 0) {
                    printf("Enter number of students: ");
                    scanf("%d", &n);
                    struct student s[n];

                    printf("Information of students: \n");
                    for (int i = 0; i < n; i++) {
                        printf("\nEnter Name of no.%d: ", i + 1);
                        scanf("%s", s[i].name);
                        printf("Enter contact of no.%d: ", i + 1);
                        scanf("%s", s[i].contact);
                        printf("Enter status of no.%d: ", i + 1);
                        scanf("%s", s[i].status);
                        printf("Enter achive of no.%d: ", i + 1);
                        scanf("%s", s[i].achive);
                        s[i].id = 112310092 + i;
                    }

                    printf("Enter id: ");
                    scanf("%d", &id);

                    for (int i = 0; i < n; i++) {
                        if (id == s[i].id) {
                            display(s[i]);
                            flag=1;
                            break;
                            
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                } else {
                   // printf("\nPlease enter valid username & password");
                    flag=2;
                }
                break;
            }
            default: {
                if (strcmp(Username, "Student") == 0 && strcmp(pass, "2345") == 0) {
                    printf("Enter id: ");
                    scanf("%d", &id);
                    struct student s; // Declare a single student outside the loop

                    for (int i = 0; i < n; i++) {
                        if (id == s.id) {
                            display(s);
                            flag=1;
                            break;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                } else {
                    //printf("\nPlease enter valid username & password");
                    flag=2;
                }
                break;
            }
        }
        if(flag==0)
        {
            printf("Sortage of information");
        }
        if(flag==2)
        {
            printf("\nplease enter valid username & password");
        }
        printf("\nEnter('1' for continue) : ");
        scanf(" %c", &ch); // Corrected format specifier for char input
    } while (ch == '1');

    return 0;
}
