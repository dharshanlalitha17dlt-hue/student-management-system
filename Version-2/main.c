
#include <stdio.h>

struct Student
{
    int id;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

// 1. Add Student
void addStudent()
{
    int id;

    if (count >= 100)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (s[i].id == id)
        {
            printf("\nID already exists!\n");
            return;
        }
    }

    s[count].id = id;

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s[count].name);

    printf("Enter Student Marks: ");
    scanf("%f", &s[count].marks);

    if (s[count].marks < 0 || s[count].marks > 100)
    {
        printf("\nInvalid marks! Enter 0 to 100.\n");
        return;
    }

    count++;

    printf("\nStudent added successfully!\n");
}

// 2. Display Students
void displayStudents()
{
    if (count == 0)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nID: %d", s[i].id);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

// 3. Search Student
void searchStudent()
{
    int id, found = 0;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (s[i].id == id)
        {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", s[i].id);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nStudent not found!\n");
}

// 4. Calculate Average
void calculateAverage()
{
    float sum = 0;

    if (count == 0)
    {
        printf("\nNo records available!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        sum += s[i].marks;
    }

    printf("\nAverage Marks = %.2f\n", sum / count);
}

// 5. Update Student Marks
void updateMarks()
{
    int id, found = 0;
    float newMarks;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (s[i].id == id)
        {
            printf("Current Marks: %.2f\n", s[i].marks);

            printf("Enter New Marks: ");
            scanf("%f", &newMarks);

            if (newMarks < 0 || newMarks > 100)
            {
                printf("\nInvalid marks!\n");
                return;
            }

            s[i].marks = newMarks;

            printf("\nMarks updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nStudent not found!\n");
}

// 6. Delete Student
void deleteStudent()
{
    int id, found = 0;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (s[i].id == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                s[j] = s[j + 1];
            }

            count--;
            found = 1;

            printf("\nStudent deleted successfully!\n");
            break;
        }
    }

    if (found == 0)
        printf("\nStudent not found!\n");
}

// 7. Count Students
void countStudents()
{
    printf("\nTotal Students: %d\n", count);
}

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n=================================");
        printf("\n    STUDENT MANAGEMENT SYSTEM");
        printf("\n             VERSION 2.0");
        printf("\n=================================");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Calculate Average Marks");
        printf("\n5. Update Student Marks");
        printf("\n6. Delete Student");
        printf("\n7. Count Total Students");
        printf("\n8. Exit");
        printf("\n=================================");

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
                updateMarks();
                break;

            case 6:
                deleteStudent();
                break;

            case 7:
                countStudents();
                break;

            case 8:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 8);

    return 0;
}
