#include <iostream>
using namespace std;
class Skill
{
    int skillid;
    string skillname;
    string discription;

public:
    Skill() : skillid(0), skillname(""), discription("") {}
    Skill(int id, string n1, string dis) : skillid(id), skillname(n1), discription(dis) {}

    void displayskill()
    {
        cout << "\n--------Skill Details-----------" << endl;
        cout << "Skill id: " << skillid << endl;
        cout << "Skill Name: " << skillname << endl;
        cout << "Discription: " << discription << endl;
    }
    void updateSkillDescription(string newDescription)
    {
        discription = newDescription;
    }

    string getskillname() { return skillname; }
};
class Sport
{
    int sportid;
    string sportname;
    string discription;
    Skill *requiredskill; //
    int skillcount;
    int capacity;

public:
    Sport() : sportid(0), sportname(""), discription(""), skillcount(0), capacity(3)
    {
        requiredskill = new Skill[capacity];
    }
    Sport(int id, string n1, string dis, int count, int cap) : sportid(id), sportname(n1), discription(dis), skillcount(count), capacity(cap)
    {
        requiredskill = new Skill[capacity];
    }
    void checklimit()
    {
        capacity *= 2;
        Skill *tempskill = new Skill[capacity];
        for (int i = 0; i < skillcount; i++)
        {
            tempskill[i] = requiredskill[i];
        }
        delete[] requiredskill;
        requiredskill = tempskill;
    }
    void addskill(Skill s)
    {
        for (int i = 0; i < skillcount; i++)
        {
            if (requiredskill[i].getskillname() == s.getskillname())
            {
                cout << "Already have this skill" << endl;
                return;
            }
        }
        if (skillcount >= capacity)
        {
            checklimit();
        }
        requiredskill[skillcount] = s;
        skillcount++;
        cout << "Skill has been added" << endl;
    }

    void removeSkill(Skill s)
    {
        bool found = false;
        for (int i = 0; i < skillcount; i++)
        {
            if (requiredskill[i].getskillname() == s.getskillname())
            {
                cout << s.getskillname() << " Skill has been removed" << endl;
                found = true;
                for (int j = i; j < skillcount - 1; j++)
                {
                    requiredskill[j] = requiredskill[j + 1];
                }
                skillcount--;
                break;
            }
        }
        if (!found)
        {
            cout << "Sorry this skill is not there" << endl;
        }
    }
    void displaySkills()
    {
        cout << "\nSkills for Sport: " << sportname << endl;
        for (int i = 0; i < skillcount; i++)
        {
            requiredskill[i].displayskill();
        }
    }
    ~Sport()
    {
        delete[] requiredskill;
    }
    string getSportName() { return sportname; }
};
class Student; // Forward declaration
class Mentor
{
    int mentorid;
    string mentorname;
    Sport *Expertise;
    int maxsport, sportcount;
    Student **assignedlearners;
    int maxlearners, learnercount;

public:
    Mentor() : mentorid(0), mentorname(""), maxsport(3), sportcount(0), maxlearners(2), learnercount(0)
    {
        Expertise = new Sport[maxsport];
        assignedlearners = new Student *[maxlearners];
    }
    Mentor(int mentorid, string mentorname, int maxsport, int sportcount, int maxlearners, int learnercount) : mentorid(mentorid), mentorname(mentorname), maxsport(maxsport), sportcount(sportcount), maxlearners(maxlearners),
                                                                                                               learnercount(learnercount)
    {
        Expertise = new Sport[maxsport];
        assignedlearners = new Student *[maxlearners];
    }

    void assignLearner(Student *s);
    void removeLearner(Student *s);
    void viewlearner();
    void displayMentorInfo()
    {
        cout << "\n-----------Mentor Details------------" << endl;
        cout << "ID: " << mentorid << endl;
        cout << "Name: " << mentorname << endl;
        cout << "Sports Expertise: ";
        for (int i = 0; i < sportcount; i++)
        {
            cout << Expertise[i].getSportName() << ",";
        }
        cout << endl;
    }

    void provideguidance()
    {
        cout << "MEntor is providing guidance" << endl;
    }
    ~Mentor()
    {
        delete[] Expertise;
        delete[] assignedlearners;
    }
    string getMentorName() { return mentorname; }
};
class Student
{
    int studentid, age;
    string name;
    Sport *sportsinterest;
    int maxsport, sportcount;
    Mentor *mentor;

public:
    Student() : studentid(0), age(0), name(""), maxsport(3), sportcount(0), mentor(nullptr)
    {
        sportsinterest = new Sport[maxsport];
    }

    Student(int id, string studentName, int studentAge, int maxSports)
        : studentid(id), age(studentAge), name(studentName), maxsport(maxSports), sportcount(0), mentor(nullptr)
    {
        sportsinterest = new Sport[maxsport];
    }

    void checkLimit()
    {
        if (sportcount >= maxsport)
        {
            maxsport *= 2;
            Sport *temp = new Sport[maxsport];
            for (int i = 0; i < sportcount; i++)
            {
                temp[i] = sportsinterest[i];
            }
            delete[] sportsinterest;
            sportsinterest = temp;
        }
    }
    void registerForMentorship(Mentor *m)
    {
        if (mentor != nullptr)
        {
            cout << "Student is already assigned to a mentor: " << mentor->getMentorName() << endl;
            return;
        }
        mentor = m;
        m->assignLearner(this);
        cout << name << " has been registered under mentor: " << mentor->getMentorName() << endl;
    }

    void viewMentorDetails()
    {
        if (mentor == nullptr)
        {
            cout << "No mentor assigned." << endl;
            return;
        }
        cout << "\n--- Mentor Details ---" << endl;
        mentor->displayMentorInfo();
    }
    void updateSportsInterest(Sport s)
    {
        for (int i = 0; i < sportcount; i++)
        {
            if (sportsinterest[i].getSportName() == s.getSportName())
            {
                cout << "Sport is already in the student's interests." << endl;
                return;
            }
        }
        if (sportcount >= maxsport)
        {
            checkLimit();
        }
        sportsinterest[sportcount] = s;
        sportcount++;
        cout << s.getSportName() << " has been added to sports interests." << endl;
    }

    ~Student()
    {
        delete[] sportsinterest;
    }

    string getstudname() { return name; }
};
void Mentor::assignLearner(Student *s)
{
    for (int i = 0; i < learnercount; i++)
    {
        if (assignedlearners[i]->getstudname() == s->getstudname())
        {
            cout << "Already have this student" << endl;
            return;
        }
    }
    if (learnercount >= maxlearners)
    {
        cout << "Sorry full: No more students can be added" << endl;
        return;
    }
    assignedlearners[learnercount] = s;
    learnercount++;
    cout << s->getstudname() << " has been added" << endl;
}
void Mentor::removeLearner(Student *s)
{
    bool found = false;
    for (int i = 0; i < learnercount; i++)
    {
        if (assignedlearners[i]->getstudname() == s->getstudname())
        {
            cout << s->getstudname() << " has been removed" << endl;
            found = true;
            for (int j = i; j < learnercount - 1; j++)
            {
                assignedlearners[j] = assignedlearners[j + 1];
            }
            learnercount--;
            assignedlearners[learnercount] = nullptr;
            break;
        }
    }
    if (!found)
    {
        cout << "Sorry this Student is not there" << endl;
    }
}
void Mentor::viewlearner()
{
    if (learnercount == 0)
    {
        cout << "No students assigned yet." << endl;
        return;
    }
    cout << "Assigned Students:" << endl;
    for (int i = 0; i < learnercount; i++)
    {
        if (assignedlearners[i] != nullptr)
        {
            cout << i + 1 << ". " << assignedlearners[i]->getstudname() << endl;
        }
    }
}
int main()
{
    cout<<"=============================="<<endl;
    cout<<"| MY Name:M Hasnain Siddiqui |"<<endl;
    cout<<"| Roll num: 24K-0516         |"<<endl;
    cout<<"=============================="<<endl;
    Skill skill1(101, "Dribbling", "Essential for basketball players");
    Skill skill2(102, "Passing", "Improves teamwork and ball movement");
    Sport basketball(201, "Basketball", "A team sport with five players", 0, 3);
    basketball.addskill(skill1);
    basketball.addskill(skill2);
    basketball.displaySkills();
    cout << endl;
    Mentor mentor1(301, "Coach Steve", 3, 1, 2, 0);
    Student student1(401, "Alice", 18, 3);
    Student student2(402, "Bob", 19, 3);
    student1.registerForMentorship(&mentor1);
    student2.registerForMentorship(&mentor1);
    student1.viewMentorDetails();
    student2.viewMentorDetails();
    mentor1.viewlearner();
    mentor1.removeLearner(&student1);
    mentor1.viewlearner();
    return 0;
}
