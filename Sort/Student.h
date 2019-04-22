//
// Created by none on 19-4-21.
//

#ifndef SORT_STUDENT_H
#define SORT_STUDENT_H

#include <system_error>

using namespace std;

struct Student : public error_code {

    Student(const char name[2], int score) {
        this->name = name;
        this->score = score;
    }

    string name;
    int score;

    bool operator<(const Student &otherStudent) {
        return score < otherStudent.score;
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};


#endif //SORT_STUDENT_H
