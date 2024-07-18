
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string gender;
    string address;
    string phone;

public:
    Person() : name(""), age(0), gender(""), address(""), phone("") {}

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGender(string g) { gender = g; }
    void setAddress(string addr) { address = addr; }
    void setPhone(string p) { phone = p; }

    string getName() { return name; }
    int getAge() { return age; }
    string getGender() { return gender; }
    string getAddress() { return address; }
    string getPhone() { return phone; }

    virtual void Save_Information() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Phone: ";
        cin >> phone;
    }

    virtual void Display_Information() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Teacher : public Person {
private:
    string qualification;
    double salary;

public:
    Teacher() : qualification(""), salary(0.0) {}

    void setQualification(string q) { qualification = q; }
    void setSalary(double s) { salary = s; }

    string getQualification() { return qualification; }
    double getSalary() { return salary; }

    void Save_Information() override {
        Person::Save_Information();
        cout << "Enter Qualification: ";
        cin.ignore();
        getline(cin, qualification);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void Display_Information() override {
        Person::Display_Information();
        cout << "Qualification: " << qualification << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Student : public Person {
private:
    string previousEducation;
    int obtainedMarks;
    int totalMarks;

public:
    Student() : previousEducation(""), obtainedMarks(0), totalMarks(0) {}

    void setPreviousEducation(string pe) { previousEducation = pe; }
    void setObtainedMarks(int om) { obtainedMarks = om; }
    void setTotalMarks(int tm) { totalMarks = tm; }

    string getPreviousEducation() { return previousEducation; }
    int getObtainedMarks() { return obtainedMarks; }
    int getTotalMarks() { return totalMarks; }

    void Save_Information() override {
        Person::Save_Information();
        cout << "Enter Previous Education: ";
        cin.ignore();
        getline(cin, previousEducation);
        cout << "Enter Obtained Marks: ";
        cin >> obtainedMarks;
        cout << "Enter Total Marks: ";
        cin >> totalMarks;
    }

    void Display_Information() override {
        Person::Display_Information();
        cout << "Previous Education: " << previousEducation << endl;
        cout << "Obtained Marks: " << obtainedMarks << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }
};

int main() {
    char choice;
    char moreInfo;
    do {
        cout << "Enter a choice... s for student and t for teacher: ";
        cin >> choice;
        if (choice == 's' || choice == 'S') {
            Student student;
            student.Save_Information();
            student.Display_Information();
        } else if (choice == 't' || choice == 'T') {
            Teacher teacher;
            teacher.Save_Information();
            teacher.Display_Information();
        } else {
            cout << "Invalid choice. Please enter 's' for student or 't' for teacher." << endl;
        }
        cout << "Do you want to enter more information? (y for yes and n for no): ";
        cin >> moreInfo;
    } while (moreInfo == 'y' || moreInfo == 'Y');

    return 0;
}

