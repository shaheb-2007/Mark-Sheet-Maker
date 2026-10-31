# Mark-Sheet-Maker
# Marksheet Maker

Marksheet Maker is a command-line application written in C that creates text-based marksheets for students. Enter student details and marks in seven subjects to calculate totals, percentages, grades, and result comments. The program saves a separate marksheet file for each student.

## Features

- Records each student’s name and roll number.
- Collects marks for seven subjects: Bengali, English, Mathematics, Physical Science, Life Science, History, and Geography.
- Checks that subject marks are between 0 and 100.
- Calculates total marks out of 700 and the overall percentage.
- Assigns a grade and result comment based on the total.
- Creates a text file for each student, named `ROLL NO-<roll>.txt`.

## Requirements

- GCC or another C compiler that supports C99 or later.
- A terminal or command prompt.

## Build and run

Save `marksheetmaker.c` in a folder, open a terminal in that folder, and compile the program.

### Linux or macOS

```bash
gcc -std=c99 -Wall -Wextra marksheetmaker.c -o marksheetmaker
./marksheetmaker
```

### Windows with MinGW-w64 GCC

```powershell
gcc -std=c99 -Wall -Wextra marksheetmaker.c -o marksheetmaker.exe
.\marksheetmaker.exe
```

## How to use

1. Enter the number of students.
2. For each student, enter their name, roll number, and marks for all seven subjects.
3. After the program finishes, find the generated marksheet files in the folder where you ran it.

Example: a student with roll number `12` will have a file named `ROLL NO-12.txt`.

## Grade scale

| Total marks | Grade | Result |
|---:|:---:|---|
| 630–700 | A+ | Outstanding |
| 560–629 | A | Excellent |
| 490–559 | B+ | Very Good |
| 420–489 | B | Good |
| 350–419 | C | Satisfactory |
| 280–349 | D | Pass |
| 0–279 | F | Fail |

## Current limitation

The current program calculates totals and percentiles before all student records have been entered. This can cause incorrect totals or percentile values in the output, especially when processing multiple students.
