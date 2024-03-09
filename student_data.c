/* Write a program to enter information of N number of students (Rollno, Name, marks of three subjects). Display following using user defined functions.
a. All students whose average marks are greater than or equal to 60.
b. All students who are PASS (i.e. to obtain marks greater than or equal to 35 in all subjects).
c. To display information of the student whose Roll number is R. If R is not found, display the appropriate message.*/


# include<stdio.h> 

int main()
{

    int n;
    printf("\nEnter number of students : ");
    scanf("%d", &n);

    char name[n][10];
    int rollNum[n], marks[n][3], i, j, sum=0, R, flag=0;
    float average[n];

    for(i=0; i<n; i++)
    {
        printf("\nEnter Details for student %d : \n", i+1);
        printf("\nName : ");
        scanf("%s", name[i]);
        printf("\nRoll Number : ");
        scanf("%d", &rollNum[i]);

        printf("\nEnter marks : \n");
        sum = 0;
        for(j=0; j<3; j++)
        {
            printf("Subject %d : ", j+1);
            scanf("%d", &marks[i][j]);
            sum += marks[i][j];
        }
        average[i] = (float) sum/3;
    }
    for(i=0; i<n; i++)
    {
        if(average[i]>=60)
        {
            printf("\nAverage marks >= 60 : \n");
            printf("\nName : %s \n", name[i]);
            printf("\nRoll number : %d \n", rollNum[i]);
        }
        else
        {
            printf("\nAverage marks < 60 : \n");
            printf("\nName : %s \n", name[i]);
            printf("\nRoll number : %d \n", rollNum[i]);
        }
        for(j=0; j<3; j++)
        {
            if(marks[i][0]>=35 && marks[i][1]>=35 && marks[i][2]>=35)
            {
                printf("\nStudent %s is PASS !! \n", name[i]);
                break;
            }
            else
            {
                printf("\nStudent %s is Fail !! \n", name[i]);
                break;
            }
        }
    }

    printf("\nEnter Roll number of student for Details : ");
    scanf("%d", &R);

    for(i=0; i<n; i++)
    {
        if(rollNum[i] == R)
        {
            printf("\nName : %s \n", name[i]);
            printf("\nRoll number : %d \n", rollNum[i]);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nNo details found !\n");
    }
    return 0;
}