#include<stdio.h>
#include<string.h>
#include<math.h>

struct student {
    char name[50];
    int roll;
    int bengali;
    int english;
    int math;
    int psc; //physical science
    int lsc; //life science
    int history;
    int geo; //geography
    int total;
    float percentage;
    float total_percentile;
    char grade[20];
    char comment[20];
};

float pcentile(int mark, const int marks[], int n);

const char *sumgrade(int total);

const char *comm(const char *grade);

float percentage(int total);

int main()
{

    char filename[50];
    int n;
    char psign = '%'; //percentage sign

    printf("Enter the number of student: ");
    scanf("%d", &n);

    int bengalimarks[n], englishmarks[n], mathmarks[n], pscmarks[n], lscmarks[n], historymarks[n], geomarks[n], totalmarks[n];

    float percentile[n][7];
    float total_percentile[n];

    struct student students[n];

    printf("Input correct values to make Mark Sheets\n");
    printf("\n");

    if(n > 0) {
        for(int i = 0; i < n; i++) {
            printf("Student Number-%d\n", i + 1);
            printf("\n");

            //taking inputs

            getchar();
            printf("Name: ");
            if(fgets(students[i].name, 50, stdin) == NULL) {
                printf("No Input\n");
                return 1;
            }

            printf("Roll: ");
            if(scanf("%d", &students[i].roll) != 1) {
                printf("No Input\n");
                return 0;
            }

            printf("Marks of Bengali: ");
            if(scanf("%d", &students[i].bengali) != 1) {
                printf("No Input\n");
                return 0;
            }
            if(students[i].bengali < 0 || students[i].bengali > 100) {
                printf("Invalid input\n");
                return 1;
            }

            printf("Marks of English: ");
            if(scanf("%d", &students[i].english) != 1) {
                printf("No Input\n");
                return 0;
            }
            if(students[i].english < 0 || students[i].english > 100) {
                printf("Invalid input\n");
                return 1;
            }

            printf("Marks of Math: ");
            if(scanf("%d", &students[i].math) != 1) {
                printf("No Input\n");
                return 0;
            }
            if(students[i].math < 0 || students[i].math > 100) {
                printf("Invalid input\n");
                return 1;
            }

            printf("Marks of Physical Science: ");
            if(scanf("%d", &students[i].psc) != 1) {
                printf("No Input\n");
                return 0;
            }
            if(students[i].psc < 0 || students[i].psc > 100) {
                printf("Invalid input\n");
                return 1;
            }

            printf("Marks of Life Science: ");
            if(scanf("%d", &students[i].lsc) != 1) {
                printf("No Input\n");
                return 0;
            }
            if(students[i].lsc < 0 || students[i].lsc > 100) {
                printf("Invalid input\n");
                return 1;
            }

            printf("Marks of History: ");
            if(scanf("%d", &students[i].history) != 1) {
                printf("No Input\n");
                return 0;
            }
            if(students[i].history < 0 || students[i].history > 100) {
                printf("Invalid input\n");
                return 1;
            }

            printf("Marks of Geography: ");
            if(scanf("%d", &students[i].geo) != 1) {
                printf("No Input\n");
                return 0;
            }
            if(students[i].geo < 0 || students[i].geo > 100) {
                printf("Invalid input\n");
                return 1;
            }

            printf("\n");

            //storing numbers of each subject of all students
            for(int i = 0; i < n; i++) {
                bengalimarks[i] = students[i].bengali;
                englishmarks[i] = students[i].english;
                mathmarks[i] = students[i].math;
                pscmarks[i] = students[i].psc;
                lscmarks[i] = students[i].lsc;
                historymarks[i] = students[i].history;
                geomarks[i] = students[i].geo;
            }

            //storing total obtained marks by every student in one array
            for(int i = 0; i < n; i++) {
                totalmarks[i] = students[i].total;
            }

            //calculating percentiles
            for(int i = 0; i < n; i++) {
                percentile[i][0] = pcentile(students[i].bengali, bengalimarks, n);
                percentile[i][1] = pcentile(students[i].english, englishmarks, n);
                percentile[i][2] = pcentile(students[i].math, mathmarks, n);
                percentile[i][3] = pcentile(students[i].psc, pscmarks, n);
                percentile[i][4] = pcentile(students[i].lsc, lscmarks, n);
                percentile[i][5] = pcentile(students[i].history, historymarks, n);
                percentile[i][6] = pcentile(students[i].geo, geomarks, n);
            }

            //calculating total percentiles
            for(int i = 0; i < n; i++) {
                total_percentile[i] = pcentile(students[i].total, totalmarks, n);
            }


            //calculating the sum of the marks
            students[i].total = students[i].bengali + students[i].english + students[i].math + students[i].psc + students[i].lsc + students[i].history + students[i].geo;

            //calculating percentage
            students[i].percentage = percentage(students[i].total);

            //calculating the grade
            strcpy(students[i].grade, sumgrade(students[i].total));

            //comments
            strcpy(students[i].comment, comm(students[i].grade));

        }

        for(int i = 0; i < n; i++) {

            snprintf(filename, sizeof filename, "ROLL NO-%d.txt", students[i].roll);

            FILE *file = fopen(filename, "w");
            if(file == NULL) {
                perror(filename);
                return 1;
            }

            //printing the all variables with marks

            fprintf(file, "MARKS SHEET\n");
            fprintf(file, "\n");

            fprintf(file, "NAME: %s", students[i].name);
            fprintf(file, "ROLL NUMBER: %d\n", students[i].roll);
            fprintf(file, "\n");
            fprintf(file, "#                          PERCENTILE\n");
            fprintf(file, "\n");
            fprintf(file, "BENGALI: %d                   %.2f\n", students[i].bengali, percentile[i][0]);
            fprintf(file, "ENGLISH: %d                   %.2f\n", students[i].english, percentile[i][1]);
            fprintf(file, "MATHEMATICS: %d               %.2f\n", students[i].math, percentile[i][2]);
            fprintf(file, "PHYSICAL SCIENCE: %d          %.2f\n", students[i].psc, percentile[i][3]);
            fprintf(file, "LIFE SCIENCE: %d              %.2f\n", students[i].lsc, percentile[i][4]);
            fprintf(file, "HISTORY: %d                   %.2f\n", students[i].history, percentile[i][5]);
            fprintf(file, "GEOGRAPHY: %d                 %.2f\n", students[i].geo, percentile[i][6]);
            fprintf(file, "\n");
            fprintf(file, "TOTAL MARKS: %d              %.2f\n", students[i].total, total_percentile[i]);
            fprintf(file, "\n");
            fprintf(file, "YOU OBTAINED %.2f%c IN THE EXAMINATION\n", students[i].percentage, psign);
            fprintf(file, "GARDE: %s\n", students[i].grade);
            fprintf(file, "RESULT: %s\n", students[i].comment);
            fprintf(file, "\n\n\n");
            fprintf(file, "(WISHING FOR YOUR BETTER FUTURE)");
            fprintf(file, "\t\t");
            fprintf(file, "[PARENT'S SIGNATURE]");
            fprintf(file, "\n");

            fclose(file);
        }

    }
    else {
        printf("Invalid input\n");
    }

    return 0;

}

//making logic for grades
const char *sumgrade(int total) {

    if(total < 0 || total > 700) {
        return "Invalid Marks\n";
    }
    else if(total >= 630) {
        //90%
        return "A+";
    }
    else if(total >= 560) {
        //80%
        return "A";
    }
    else if(total >= 490) {
        //70%
        return "B+";
    }
    else if(total >= 420) {
        //60%
        return "B";
    }
    else if(total >= 350) {
        //50%
        return "C";
    }
    else if(total >= 280) {
        return "D";
    }
    else {
        //less than 40%
        return "F";
    }
}

const char *comm(const char *grade) {
    if(strcmp(grade, "A+") == 0) {
        return "OUTSTANDING";
    }
    else if(strcmp(grade, "A") == 0) {
        return "EXCELLENT";
    }
    else if(strcmp(grade, "B+") == 0) {
        return "VERY GOOD";
    }
    else if(strcmp(grade, "B") == 0) {
        return "GOOD";
    }
    else if(strcmp(grade, "C") == 0) {
        return "SATISFACTORY";
    }
    else if(strcmp(grade, "D") == 0) {
        return "PASS";
    }
    else if(strcmp(grade, "F") == 0) {
        return "FAIL";
    }
    else {
        return "ERROR";
    }
}

float percentage(int total) {

    float a = 700.00; //full marks
    float b = 100.00;

    float result = (total / a) * b;
    return result;
}

float pcentile(int mark, const int marks[], int n) {

    //mark = mark of the particular student in a particular subjects
    //marks[] = marks of all students in a particular subject
    //n = total number of students
    
    int students_below = 0; //indicates how many students have lesser number than the selected student
    float result, a = 100.00;

    for(int i = 0; i < n; i++) {
        if(mark > marks[i]) {
            students_below++;
        }
    }

    result = ((float)students_below / (float)n) * a;

    return result;
}