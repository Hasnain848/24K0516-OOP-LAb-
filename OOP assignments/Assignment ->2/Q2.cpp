#include <iostream>
using namespace std;
class Hauntedhouse;
class Ghost;
class Visitor;

class Ghost
{
protected:
    string actorname;
    int scarlevel;
    int numactor;

public:
    Ghost(string name = "", int scarlevel = 1) : actorname(name), scarlevel(scarlevel), numactor(1) {}
    virtual void haunting() = 0;
    virtual string gettype() const = 0;
    // operator overloading for <<
    friend ostream &operator<<(ostream &out, const Ghost &ghost)
    {
        out << ghost.gettype() << " (Played by: " << ghost.actorname;
        if (ghost.numactor > 1)
        {
            out << " and " << ghost.numactor - 1 << " others";
        }
        out << ", Scare Level: " << ghost.scarlevel << ")";
        return out;
    }
    // operator overloading for +
    virtual Ghost *operator+(const Ghost &g2) = 0;

    // getter and setter
    string getname() const { return actorname; }
    int getscarlevel() const { return scarlevel; }
    void setname(string name) { actorname = name; }
    void setscarlevel(int level) { scarlevel = level; }
    friend void Visit(Visitor* visitors, int visitorCount, Hauntedhouse& hauntedHouse);
};
class Poltergeists : virtual public Ghost
{
public:
    Poltergeists(string name = "", int scarelevel = 1) : Ghost(name, scarelevel) {}
    void haunting() override
    {
        cout << "The poltergeist moves objects around the room!" << endl;
    }
    string gettype() const override
    {
        return "Poltergeists";
    }
    Ghost *operator+(const Ghost &g2) override
    {
        Poltergeists *tempghost = new Poltergeists(*this);
        tempghost->numactor = this->numactor + 1;
        tempghost->scarlevel = this->scarlevel + g2.getscarlevel();
        return tempghost;
    }
};
class Banshees : public Ghost
{
public:
    Banshees(string name = "", int scarelevel = 1) : Ghost(name, scarelevel) {}
    void haunting() override
    {
        cout << "The banshee screams loudly, making visitors' ears ring!" << endl;
    }
    string gettype() const override
    {
        return "Banshees";
    }
    Ghost *operator+(const Ghost &g2) override
    {
        Banshees *tempghost = new Banshees(*this);
        tempghost->numactor = this->numactor + 1;
        tempghost->scarlevel = this->scarlevel + g2.getscarlevel();
        return tempghost;
    }
};
class ShadowGhosts : virtual public Ghost
{
public:
    ShadowGhosts(string name = "", int scarelevel = 1) : Ghost(name, scarelevel) {}
    void haunting() override
    {
        cout << "The shadow ghost whispers creepily in visitors' ears!" << endl;
    }
    string gettype() const override
    {
        return "ShadowGhosts";
    }
    Ghost *operator+(const Ghost &g2) override
    {
        ShadowGhosts *tempghost = new ShadowGhosts(*this);
        tempghost->numactor = this->numactor + 1;
        tempghost->scarlevel = this->scarlevel + g2.getscarlevel();
        return tempghost;
    }
};
class ShadowPoltergeist : public ShadowGhosts, public Poltergeists
{
public:
    ShadowPoltergeist(string name = "", int scarelevel = 1) : ShadowGhosts(name, scarelevel), Poltergeists(name, scarelevel) {}
    void haunting() override
    {
        cout << "The shadow poltergeist whispers creepily AND moves objects around the room!" << endl;
    }
    string gettype() const override
    {
        return "ShadowPoltergeist";
    }
    Ghost *operator+(const Ghost &g2) override
    {
        ShadowPoltergeist *tempghost = new ShadowPoltergeist(*this);
        tempghost->numactor = this->numactor + 1;
        tempghost->scarlevel = this->scarlevel + g2.getscarlevel();
        return tempghost;
    }
};
class Hauntedhouse
{private:
    string name;
    Ghost **ghosts;
    int ghostcount;
    int maxghost;

public:
    Hauntedhouse(string name = "", int maxghost = 10) : name(name), maxghost(maxghost), ghostcount(0)
    {
        ghosts = new Ghost *[maxghost];
    }
    void addghost(Ghost *g1)
    {
        if (ghostcount < maxghost)
        {
            cout << "ghost type: " << g1->gettype() << " Has been added:)" << endl;
            ghosts[ghostcount] = g1;
            ghostcount++;
            return;
        }
        else
            cout << "Sorry No more ghost can be added" << endl;
    }

    Ghost *getghost(int index)
    {
        if (index >= 0 && index <= maxghost)
        {
            return ghosts[index];
        }
        return nullptr;
    }

    // getter and setter
    void setname(string n) { name = n; }
    string gethousename() { return name; }
    int getmaxghost() { return maxghost; }
    int getghostcount() { return ghostcount; }
    friend void Visit(Visitor* visitors, int visitorCount, Hauntedhouse& hauntedHouse);


    ~Hauntedhouse()
    {
        delete[] ghosts;
    }
};
class Visitor
{private:
    string name;
    int bravery;

public:
    Visitor(string name, int bravery) : name(name), bravery(bravery) {}
    string getvisitorname(){return name;}
    int getbraverylevel(){return bravery;}
    string getbravery(){
        if(bravery>=1&&bravery<=4){
            return "Cowardly";
        }
        else if(bravery>=5&&bravery<=7){
            return "Average";
        }
        else if(bravery>=8&&bravery<=10){
            return "Fearless";
        }
    }
    void reacttoghost(Ghost *g1)
    {
        if (bravery >= 1 && bravery <= 4 && g1->getscarlevel() <= 4 || bravery >= 5 && bravery <= 7 && g1->getscarlevel() <= 7 || bravery >= 8 && bravery <= 10 && g1->getscarlevel() <= 10)
        {

            if (bravery >= 8)
            {
                cout << "laughs at the " << g1->gettype() << " saying 'Is that all you've got?'" << endl;
            }
            else if (bravery >= 5)
            {
                cout << "taunt the " << g1->gettype() << " nerviously" << endl;
            }
            else
                cout << "get  a bit scare but recover" << endl;
        }
        else
        {
            if (bravery >= 8)
            {
                cout << "is impressed by the " << g1->gettype() << " but keeps their cool." << endl;
            }
            else if (bravery >= 5)
            {
                cout << "speaks with a shaky voice: 'T-t-that was s-scary!'" << endl;
            }
            else
            {
                cout << "SCREAMS and RUNS AWAY from the " << g1->gettype() << "!" << endl;
            }
        }
    }
    friend void Visit(Visitor* visitors, int visitorCount, Hauntedhouse& hauntedHouse);
};
void Visit(Visitor* visitors, int visitorCount, Hauntedhouse& hauntedHouse) {
    cout << "\n===== Group Visit to " << hauntedHouse.gethousename() << " =====" << endl;
    
    for (int i = 0; i < visitorCount; i++) {
        cout << "\n" << visitors[i].getvisitorname() << " enters " << hauntedHouse.gethousename() << "..." << endl;
        
        for (int j = 0; j < hauntedHouse.ghostcount; j++) {
            Ghost* ghost = hauntedHouse.ghosts[j];
            cout << "- Encountering: " << *ghost << endl;
            ghost->haunting();
            visitors[i].reacttoghost(ghost);
        }
    }
    
    cout << "\n===== End of Visit to " << hauntedHouse.gethousename() << " =====" << endl;
}

int main(){

    Hauntedhouse house1("Shadowy Manor",5);
    Hauntedhouse house2("Creaking Mansion",5);
    Hauntedhouse house3("Whispering Woods Cabin",5);

    house1.addghost(new Poltergeists("Mike",5));
    house1.addghost(new Banshees("Lisa", 6));
    house1.addghost(new ShadowGhosts("Tom", 7));
    house1.addghost(new ShadowPoltergeist("Sarah",8 ));
    
   
    house2.addghost(new Poltergeists("Jake",2 ));
    house2.addghost(new Banshees("Emma", 3));
    house2.addghost(new ShadowGhosts("Alex",4 ));
    
   
    house3.addghost(new ShadowGhosts("Chris",5 ));
    house3.addghost(new Poltergeists("Mia", 8));
    house3.addghost(new ShadowPoltergeist("Ryan",1 ));

    house1.addghost(*house1.getghost(0)+*house1.getghost(1));

    Visitor visitors[5] = {
        Visitor("Hasnain", 2),      // Cowardly
        Visitor("Obaid", 3),     // Cowardly
        Visitor("Ibrahim", 6),     // Average
        Visitor("Jawad", 7),   // Average
        Visitor("Yousha", 9)    // Fearless
    };
   
Visit(visitors, 5, house1);
Visit(visitors, 5, house2);
Visit(visitors, 5, house3);
    


    
}