/*
 Program Name: StudentUndergraduate.cpp
 Programmer: Moris Gomez
 Date: Saturday 02/27/2024
 Version Control: 3.0
 About: Week 3, CSCI 2, HW.
 Description:
 Write an abstract class for Student class with at least two pure virtual functions
 of your choice and a few private data members.
 Next, design a class named Undergraduate, which is derived from the Student class
 with a few private data members.
*/

#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
    string institution;
    string department;
    int idNumber; //6 digits
    
public:
    //pure virtual functions:
    virtual void studentCareer() = 0;
    virtual void studentMasters() = 0;
    
    //default constructor for parent class:
    Student()
    {
        institution = "none";
        department = "none";
        idNumber = 000000;
    }
    
    //constructor w/ 3 parameters:
    Student(string ins, string dep, int num)
    {
        institution = ins;
        department = dep;
        idNumber = num;
    }
    
    //getters:
    string getInstitution()
    {
        return institution;
    }
    string getDepartment()
    {
        return department;
    }
    int getIdNumber()
    {
        return idNumber;
    }
    
    //setters:
    void setInstitution(string i)
    {
        institution = i;
    }
    void setDepartment(string d)
    {
        department = d;
    }
    void setNumber(int n)
    {
        idNumber = n;
    }
    
    //other functions:
    void displayStudentObject()
    {
        cout << "institution is: " << institution << endl;
        cout << "department is: " << department << endl;
        cout << "student id number is: " << idNumber << endl;
    }
}; //end student parent class.

//create child class Undergraduate from Student parent class:
class Undergraduate : public Student
{
private:
    string major;
    string minor;
public:
    //default constructor:
    Undergraduate()
    {
        major = "none";
        minor = "none";
        //Student();
        /*
         QUESTION: why can I not use ^ to bring down default constructor from parent class 
         when making parent an abstract class? if i can do so with 2nd child constructor?
         */
    }
    
    //non-default constructor:
    Undergraduate(string ins, string dep, int num, string maj, string min):Student(ins, dep, num)
    {
        major = maj;
        minor = min;
    }
    
    //getters:
    string getMajor()
    {
        return major;
    }
    string getMinor()
    {
        return minor;
    }
    
    //setters:
    void setMajor(string ma)
    {
        major = ma;
    }
    void setMinor(string mi)
    {
        minor = mi;
    }
    
    //other functions:
    void displayUndergraduateObject()
    {
        cout << "institution is: " << institution << endl;
        cout << "department is: " << department << endl;
        cout << "student ID is: " << idNumber << endl;
        cout << "undergraduate major is: " << major << endl;
        cout << "undergraduate minor is: " << minor << endl;
    }
    
    //using pure virtual functions:
    void studentCareer()
    {
        cout << "you will probably be employed in the field of: " << major << endl;
    }
    void studentMasters()
    {
        cout << "you will probably seek a masters degree in the field of: " << major << endl;
    }
    
}; //end child Undergraduate class.

//create child class CommunityCollege from Student parent class:
class CommunityCollege : public Student
{
private:
    string major;
public:
    //default constructor:
    CommunityCollege()
    {
        major = "none";
        //CommunityCollege();
        /*
         QUESTION: why can I not use ^ to bring down default constructor from parent class
         when making parent an abstract class? if i can do so with 2nd child constructor?
         */
    }
    
    //non-default constructor:
    CommunityCollege(string ins, string dep, int num, string maj):Student(ins, dep, num)
    {
        major = maj;
    }
    
    //getters:
    string getMajor()
    {
        return major;
    }
    
    //setters:
    void setMajor(string ma)
    {
        major = ma;
    }
    
    //other functions:
    void displayCommunityCollegeObject()
    {
        cout << "institution is: " << institution << endl;
        cout << "department is: " << department << endl;
        cout << "student ID is: " << idNumber << endl;
        cout << "undergraduate major is: " << major << endl;
    }
    
    //using pure virtual functions:
    void studentCareer()
    {
        cout << "you will probably be employed in the field of: " << major << endl;
    }
    void studentMasters()
    {
        cout << "you will probably seek a masters degree in the field of: " << major << endl;
    }
};

//Driver function for program: main.
int main()
{
    //note: cannot create objects from parent function bc abstract class.
    //note: the following will produce error:
    //Student moris("ucla", "international institute", 123456);
    //moris.displayStudentObject();
    
    cout << "EXAMPLE 1: USING UNDERGRADUATE SUB CLASS:" << endl;
    //(1)create an object from child class Undergraduate including parent class members:
    Undergraduate ash("ucla", "international institute", 678916, "latin american studies", "philosophy");
    
    //(1)display object:
    cout << endl << "----your info----" << endl;
    ash.displayUndergraduateObject();
    
    //(1)call first pure virtual function on object:
    cout << endl << "----using 1st pure virtual function-----" << endl;
    ash.studentCareer();
    
    //(1)call second pure virtual function on object:
    cout << endl << "----using 2nd pure virtual function-----" << endl;
    ash.studentMasters();
    
    cout << endl << endl << endl << endl <<  "EXAMPLE 2: USING COMMUNITY COLLEGE SUB CLASS:" << endl;
    //(2)create an object from child class Community including parent class members:
    CommunityCollege moris("el camino college", "computer science", 955123, "computer science");
    
    //(2)display object:
    cout << endl << "----your info----" << endl;
    moris.displayCommunityCollegeObject();
    
    //(2)call first pure virtual function on object:
    cout << endl << "----using 1st pure virtual function-----" << endl;
    moris.studentCareer();
    
    //(2)call second pure virtual function on object:
    cout << endl << "----using 2nd pure virtual function-----" << endl;
    moris.studentMasters();
    
    return 0;
}

/*
 Explanation of pure virtual class:
 -
 A pure virtual class is created in the base class,
 but it is implemented only in the child derived classes.
 The parent class becomes an abstract class, so we cannot
 create objects from it - only from derived classes.
 Any subclasses which do not redefine that pure virtual function become abstract,
 and cannot create objects from that child class.
 All derived classes must redefine the pure virtual functions created in parent, or
 we get error in program.
 Use abstract class when we know all subclasses need function x but we are not sure
 how to implement in the base for all children.
 We can edit funnction x in each derived class as needed per individual case.
 -
 
 Example:
 1. we have a parent class Animal.
 2. we have function move() in Animal.
 3. not all animals move (e.g corals & sea squirts).
 4. but we know all animals must have a move attribute.
 4. so it's better to create it as pure virtual class.
*/
