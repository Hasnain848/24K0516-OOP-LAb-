#include<iostream>
using namespace std;
unsigned long generateHash(string password){
    unsigned long hash = 5381;
    for(int i=0;i<password.length();i++){
        hash = hash * 33 + password[i];
    }
    return hash;
}

class User{
    protected:
    string name,id,email;
    string *permissions;
    long hashed;
    int permcount;
    public:
    User(string name,string id,string password,string email,string perm[],int size ){
        this->name=name;
        this->id= id;
        this->email=email;
        hashed= generateHash(password);
        permcount=size;
        permissions = new string [permcount];
        for(int i=0;i<permcount;i++){
            permissions[i]=perm[i];
        }
    }
    bool authenticate(string pass){
        return generateHash(pass)== hashed;
    }
    virtual void display(){
        cout << "Name: " << name << ", ID: " << id << ", Email: " << email << endl;
        cout << "Permissions: ";
        for (int i = 0; i < permcount; i++) {cout << permissions[i] << ", ";}
        cout << endl;
    }
    bool haspermission(string action){
        for(int i=0;i<permcount;i++){
            if(permissions[i]==action)return true;
        }
        return false;
    }
    ~User(){
        delete[] permissions;
    }
};
class Student : public User{
    protected:
    int *assignments;
    int noOfassign;
    public:
    Student(string n, string id, string e, string password, int nAssignments)
    : User(n, id, password,e , new string[1]{"submit_assignment"}, 1){
        noOfassign=nAssignments;
        assignments = new int [noOfassign];
        for(int i=0;i<noOfassign;i++){
            assignments[i]=0;
        }
    }
    void display()override{
        User ::display();
        cout<<"Assignment Status"<<endl;
        for(int i=0;i<noOfassign;i++){
            cout<<"Assignment "<<i+1<<" : Status -> "<<(assignments[i]?"Submitted":"Pending")<<" "<<endl;
        }
    }

    void submitAssignment(int index){
        if(index>0 &&index<=noOfassign){
            assignments[index]=1;
            cout<<"Assignment "<<index<<" Submitted"<<endl;
        }
        else cout<<"Invalid Assignment number"<<endl;
    }
    ~Student() { delete[] assignments; }
};
class TA : public Student{
    Student** students;   
    int studentCount;
    string* projects;
    int projectCount;
    const int maxProjects = 2;
    const int maxStudents = 10;

    public:
    TA(string n, string id, string e, string password, int nAssignments)
    : Student(n,id,e,password,nAssignments){
        delete[] permissions; 
        permissions = new string[2]{"view_projects", "manage_students"};
        permcount = 2;
        students = new Student*[maxStudents];
        studentCount = 0;
        projects = new string[maxProjects];
        projectCount = 0;
    }
    void display()override{
        User::display();
        cout << "TA Students List: " << studentCount << " students.\n";
        cout << "TA Projects: ";
        for (int i = 0; i < projectCount; i++) cout << projects[i] << ", ";
        cout << endl;
    }
    void addStudent(Student *s){
        if(studentCount<maxStudents){
            students[studentCount]=s;
            studentCount++;
            cout<<"Student added"<<endl;
        }
        else cout << "Cannot add more students."<<endl;
    }
    void Addproject(string p){
        if(projectCount<maxProjects){
            projects[projectCount] = p;
            projectCount++;
            cout<<"Project added"<<endl;
        }
        else cout<<"Project limit exceed"<<endl;
    }
    ~TA() {
        delete[] students;
        delete[] projects;
    }

};
class Professor : public User{
    public:
    Professor(string n, string id, string e, string password):
    User(n, id, password,e , new string[2]{"assign projects","full_lab_access"}, 2){}

    void display()override{
        User ::display();
        cout<<"Professor Role"<<endl;
    }
    void assignProjectoTA(TA *t,string pro){

        if(haspermission("assign projects")){
            t->Addproject(pro);
            //cout<<"Project assigned to TA"<<endl;
        }
        else cout<<"No permission to assign projecct"<<endl;
    }
};
void authenticateAndPerformAction(User* user, string action) {
    if (user->haspermission(action)) {
        cout << "Action " << action << " allowed.\n";
    } else {
        cout << "Action " << action << " denied.\n";
    }
}
int main(){
    cout << "===============================" << endl;
    cout << "| MY Name: M Hasnain Siddiqui |" << endl;
    cout << "| Roll num: 24K-0516          |" << endl;
    cout << "===============================" << endl;
    Professor prof("Dr. Ali", "P001", "pass123", "ali@uni.edu");
    TA ta("Imran", "T001", "ta123", "imran@uni.edu", 5);
    Student stu("Ahmed", "S001", "stu123", "ahmed@uni.edu", 5);
    prof.display();
    cout<<"-----------------------------------"<<endl;
    ta.display();
    cout<<"-----------------------------------"<<endl;
    stu.display();
    cout<<"===================================================="<<endl;
    authenticateAndPerformAction(&prof, "full_lab_access");
    authenticateAndPerformAction(&ta, "manage_students");
    authenticateAndPerformAction(&stu, "assign_projects");
    cout << endl;
    cout<<"===================================================="<<endl;
    prof.assignProjectoTA(&ta, "AI Project");
    prof.assignProjectoTA(&ta, "DB Project");
    prof.assignProjectoTA(&ta, "Extra Project"); 
    cout<<"===================================================="<<endl;
    ta.addStudent(&stu);
    ta.display();

    return 0;
}