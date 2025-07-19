#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double getGradePoint(string grade) {
    if (grade == "A" || grade == "a") return 4.0;
    else if (grade == "A-") return 3.7;
    else if (grade == "B+") return 3.3;
    else if (grade == "B" || grade == "b") return 3.0;
    else if (grade == "B-") return 2.7;
    else if (grade == "C+") return 2.3;
    else if (grade == "C" || grade == "c") return 2.0;
    else if (grade == "C-") return 1.7;
    else if (grade == "D") return 1.0;
    else return 0.0; 
}

int main() {
    int numCourses;
    double totalGradePoints = 0.0, totalCreditHours = 0.0;

    cout << "Enter number of courses taken this semester: " << endl;
    cin >> numCourses;

    vector<string> grades(numCourses);
    vector<double> creditHours(numCourses);
    vector<double> gradePoints(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        cout << endl << "Enter grade for course " << i + 1 << " (e.g., A, B+, C-): " << endl;
        cin >> grades[i];

        cout << "Enter credit hours for course " << i + 1 << ": " << endl;
        cin >> creditHours[i];

        gradePoints[i] = getGradePoint(grades[i]);

        totalGradePoints += gradePoints[i] * creditHours[i];
        totalCreditHours += creditHours[i];
    }

    double semesterGPA = totalGradePoints / totalCreditHours;

    double previousCGPA, previousCreditHours;
    cout << endl << "Do you want to calculate CGPA? (y/n): " << endl;
    char ch;
    cin >> ch;

    double cgpa = semesterGPA;
    if (ch == 'y' || ch == 'Y') {
        cout << "Enter previous CGPA: " << endl;
        cin >> previousCGPA;
        cout << "Enter total previous credit hours: " << endl;
        cin >> previousCreditHours;

        double totalCumulativeGradePoints = (previousCGPA * previousCreditHours) + totalGradePoints;
        double totalCumulativeCreditHours = previousCreditHours + totalCreditHours;

        cgpa = totalCumulativeGradePoints / totalCumulativeCreditHours;
    }

    cout << fixed << setprecision(2);
    cout << endl << "--- Individual Course Grades ---" << endl;
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << ": Grade = " << grades[i]
             << ", Credit Hours = " << creditHours[i]
             << ", Grade Points = " << gradePoints[i] << endl;
    }

    cout << endl << "Semester GPA: " << semesterGPA << endl;
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}
