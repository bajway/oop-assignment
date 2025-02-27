#include <iostream>
#include <string>
using namespace std;

class Skill 
{
public:
    int skillID;
    string skillName, desc;
    Skill(int id, string name, string desc) : skillID(id), skillName(name), desc(desc) {}
    void details_about_skills() 
    { 
        cout << "Skill: " << skillName << " - " << desc << endl; 
    }
    void updateSkilldesc(string newDesc) 
    { 
        desc = newDesc; 
    }
};

class Sport 
{
public:
    int sportsID;
    string name, desc;
    string reqSkills[10];
    int skillCounter;
    Sport(int id, string n, string desc) : sportsID(id), name(n), desc(desc), skillCounter(0) {}
    void addSkill(string skill) 
    { 
        if (skillCounter < 10) 
        reqSkills[skillCounter++] = skill; 
    }
    void removeSkill(string skill) 
    {
        for (int i = 0; i < skillCounter; i++) 
        {
            if (reqSkills[i] == skill) 
            {
                for (int j = i; j < skillCounter - 1; j++)
                {
                    reqSkills[j] = reqSkills[j + 1];
                }
                skillCounter--;
                break;
            }
        }
    }
};

class Mentor;

class Student 
{
public:
    int stID, age;
    string name;
    string interest[5];
    int count;
    Mentor* appointedMentor;
    Student(int id, string n, int a) : stID(id), name(n), age(a), appointedMentor(NULL), count(0) {}
    void applyForMentorship(Mentor* m);
    void viewMentorDetails();
    void updateSportsInterest(string sport) 
    { 
        if (count < 5) 
        {
            interest[count++] = sport; 
        }
    }
};

class Mentor {
public:
    int mentorID, maxLearners, learnerCount;
    string name;
    string sportsInExpert[5];
    Student* appointedLearners[3]; 
    Mentor(int ID, string n, int mLearner) : mentorID(ID), name(n), maxLearners(mLearner), learnerCount(0) {}
    void assigningLearner(Student* s) 
    {
        if (learnerCount < maxLearners) 
        {
            appointedLearners[learnerCount++] = s;
        }
    }
    void withdrawLearner(Student* s) 
    {
        for (int i = 0; i < learnerCount; i++) 
        {
            if (appointedLearners[i] == s) 
            {
                for (int j = i; j < learnerCount - 1; j++) 
                {
                    appointedLearners[j] = appointedLearners[j + 1];
                }
                learnerCount--;
                s->appointedMentor = NULL;
                break;
            }
        }
    }
    void view_learners() 
    {
        for (int i = 0; i < learnerCount; i++) 
        {
            cout << appointedLearners[i]->name << " is assigned to " << name << endl;
        }
    }
    void guidance() 
    { 
        cout << name << " is guiding students." << endl; 
    }
};

void Student::applyForMentorship(Mentor* m) 
{
    if (m->learnerCount < m->maxLearners) 
    {
        appointedMentor = m;
        m->assigningLearner(this);
    }
}

void Student::viewMentorDetails() 
{
    if (appointedMentor)
        cout << "Mentor: " << appointedMentor->name << endl;
    else
        cout << "No mentor assigned." << endl;
}

int main() {
    Mentor ahmed(0022, "Omer", 4);
    Student safi(2539, "Kashif", 19);
    
    safi.applyForMentorship(&ahmed);
    ahmed.view_learners();
    
    return 0;
}
