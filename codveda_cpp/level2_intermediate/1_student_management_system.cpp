#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const string DATA_FILE = "students.txt";

class Student {
public:
    int id;
    string name;
    float grade;

    Student() : id(0), grade(0.0f) {}
    Student(int id, const string &name, float grade)
        : id(id), name(name), grade(grade) {}
};

class StudentManager {
private:
    vector<Student> students;

    // Finds a student by ID; returns an iterator (== end() if not found)
    vector<Student>::iterator findStudent(int id) {
        return std::find_if(students.begin(), students.end(),
                             [id](const Student &s) { return s.id == id; });
    }

public:
    void loadRecords() {
        ifstream fin(DATA_FILE);
        if (!fin.is_open()) return; // no file yet - start fresh

        int id;
        float grade;
        string name;
        while (fin >> id) {
            fin.ignore(); // skip delimiter
            getline(fin, name, '|');
            fin >> grade;
            fin.ignore();
            students.emplace_back(id, name, grade);
        }
        fin.close();
    }

    void saveRecords() const {
        ofstream fout(DATA_FILE, std::ios::trunc);
        if (!fout.is_open()) {
            cout << "Error: could not save records to disk.\n";
            return;
        }
        for (const auto &s : students) {
            fout << s.id << " " << s.name << "|" << s.grade << "\n";
        }
        fout.close();
    }

    void addStudent() {
        int id;
        string name;
        float grade;

        cout << "Enter student ID: ";
        cin >> id;

        if (findStudent(id) != students.end()) {
            cout << "Error: a student with ID " << id << " already exists.\n";
            return;
        }

        cin.ignore();
        cout << "Enter student name: ";
        getline(std::cin, name);

        cout << "Enter student grade: ";
        cin >> grade;

        students.emplace_back(id, name, grade);
        saveRecords();
        cout << "Student added successfully.\n";
    }

    void displayStudents() const {
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }

        cout << "\n" << std::left;
        cout.width(6);  std::cout << "ID";
        cout.width(20); std::cout << "Name";
        cout.width(6);  std::cout << "Grade" << "\n";
        cout << "---------------------------------\n";

        for (const auto &s : students) {
            cout.width(6);  std::cout << s.id;
            cout.width(20); std::cout << s.name;
            cout.width(6);  std::cout << s.grade << "\n";
        }
    }

    void updateStudent() {
        int id;
        cout << "Enter ID of student to update: ";
        cin >> id;

        auto it = findStudent(id);
        if (it == students.end()) {
            cout << "Student with ID " << id << " not found.\n";
            return;
        }

        cin.ignore(); cout << "Enter new name: ";
        getline( cin, it->name);
        cout << "Enter new grade: ";
        cin >> it->grade;

        saveRecords();
        cout << "Student updated successfully.\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter ID of student to delete: ";
        cin >> id;

        auto it = findStudent(id);
        if (it == students.end()) {
            cout << "Student with ID " << id << " not found.\n";
            return;
        }

        students.erase(it);
        saveRecords();
        std::cout << "Student deleted successfully.\n";
    }
};

void printMenu() {
    std::cout << "\n===== Student Management System =====\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Display All Students\n";
    std::cout << "3. Update Student\n";
    std::cout << "4. Delete Student\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    StudentManager manager;
    manager.loadRecords();

    int choice;
    do {
        printMenu();
        if (!(std::cin >> choice)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.displayStudents(); break;
            case 3: manager.updateStudent(); break;
            case 4: manager.deleteStudent(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);

    return 0;
}
