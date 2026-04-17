#include <iostream>
#include <string>

using namespace std;

typedef string Name;
typedef unsigned short CourseNum;
typedef unsigned char SemesterNum;
typedef unsigned short LecturesCount;

struct Discipline {
    Name name;
    CourseNum course;
    SemesterNum start_semester;
    SemesterNum end_semester;
    LecturesCount lectures_per_semester;

    bool operator == (Discipline& other) {
        return course == other.course && name == other.name;
    }

    bool operator < (Discipline& other) {
        if (course != other.course)
            return course < other.course;
        return name < other.name;
    }

    bool operator > (Discipline& other) {
        return !(*this < other) && !(*this == other);
    }

    void print(){
        cout << "Дисциплина: " << name << ", курс: " << course << ", семестры: " << to_string(start_semester) << "-" + to_string(end_semester)
            << ", лекций в семестре: " << lectures_per_semester << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    Discipline math;
    math.name = "Высшая математика";
    math.course = 1;
    math.start_semester = 1;
    math.end_semester = 2;
    math.lectures_per_semester = 64;

    Discipline physics;
    physics.name = "Физика";
    physics.course = 1;
    physics.start_semester = 1;
    physics.end_semester = 1;
    physics.lectures_per_semester = 48;

    Discipline discrete_math;
    discrete_math.name = "Дискретная математика";
    discrete_math.course = 2;
    discrete_math.start_semester = 3;
    discrete_math.end_semester = 3;
    discrete_math.lectures_per_semester = 32;

    Discipline math2;
    math2.name = "Высшая математика";
    math2.course = 1;
    math2.start_semester = 1;
    math2.end_semester = 2;
    math2.lectures_per_semester = 64;

    math.print();
    physics.print();
    discrete_math.print();
    math2.print();

    cout << "\nРезультаты сравнений:\n";
    cout << "math < physics: " << (math < physics) << endl;
    cout << "math > physics: " << (math > physics) << endl;
    cout << "math == physics: " << (math == physics) << endl;
    cout << "math == math2: " << (math == math2) << endl;
    cout << "math < discrete_math: " << (math < discrete_math) << endl;

    return 0;
}