
#include <stdio.h>
#include <string.h>

struct Student
{
    int id;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

// Function to add student
void addStudent()
{
    if (count >= 100)
    {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &s[count].id);

    // Check duplicate ID
    for (int i = 0; i < count; i++)
    {
        if (s[i].id == s[count].id)
        {
            printf("ID already exists!\n");
            return;
        }
    }

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s[count].name);

    printf("Enter Student Marks: ");
    scanf("%f", &s[count].marks);

    count++;

    printf("\nStudent added successfully!\n");
}

// Function to display students
void displayStudents()
{
    if (count == 0)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n----- STUDENT RECORDS -----\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nID: %d", s[i].id);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

// Function to search student
void searchStudent()
{
    int id, found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (s[i].id == id)
        {
            printf("\nStudent Found!");
            printf("\nID: %d", s[i].id);
            printf("\nName: %s", s[i].name);
            printf("\nMarks: %.2f\n", s[i].marks);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}

// Function to calculate average
void calculateAverage()
{
    float sum = 0;

    if (count == 0)
    {
        printf("\nNo student records available!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        sum = sum + s[i].marks;
    }

    printf("\nAverage Marks = %.2f\n", sum / count);
}

int main()
{
    int choice;

    do
    {
        printf("\n==============================");
        printf("\n    STUDENT MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Calculate Average Marks");
        printf("\n5. Exit");
        printf("\n==============================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                calculateAverage();
                break;

            case 5:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
