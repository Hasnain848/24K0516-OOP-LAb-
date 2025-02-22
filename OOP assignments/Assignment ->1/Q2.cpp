#include<iostream>
#include <tuple>
using namespace std;
class Goal{
    private:
    int x=3,y=3;
    public:
    bool isgoalreached(int BallX,int BallY){
        return (BallX==x&&BallY==y);
    }

};
class Ball{
    private:
    int x,y;
    public:
    Ball() : x(0), y(0) {} 
    int getx(){return x; }
    int gety(){   return y;}
    void move(int dx,int dy){
        x+=dx;
        y+=dy;
    }
    tuple<int, int> getPosition() {  
        return {x, y};
    }

};
class Robot{
    private:
    string name;
    int hits;//static int hits;
    public:
    Robot(string n) : name(n), hits(0) {}
    
    void hitBall(Ball &ball,const string &direction){
        hits++;
        if(direction == "up") ball.move(0,1);
        else if(direction == "down") ball.move(0,-1);
        else if(direction == "left") ball.move(-1,0);
        else if(direction == "right") ball.move(1,0);
    }
    int getHits(){return hits; }
    string getName() { return name; }

};
class Team{
    private:
    string teamname;
    Robot *robot;
    public:
    Team(string name, string robotName) : teamname(name) {
        robot = new Robot(robotName);
    }
    ~Team() { delete robot; }

    string getTeamname() { return teamname; }
    Robot* getrobot() { return robot; }

};
class Game{
    private:
    Team team1;
    Team team2;
    Ball ball;
    Goal goal;
    public:
    Game(string t1, string r1, string t2, string r2) : team1(t1, r1), team2(t2, r2) {}
    void startgame(){
        cout << "Game started!\n";
        Play(&team1);
        ball = Ball();
        Play(&team2);
        declareWinner();
    }
    void Play(Team *team){
        cout << team->getTeamname() << "'s turn...\n";
        Robot *robot = team->getrobot();

        while (!goal.isgoalreached(ball.getx(), ball.gety())) {
            string moveDirection="";
            //Firsty I made it random but then i take input from user
           // string directions[] = {"up", "down", "left", "right"};
           // string moveDirection = directions[rand() % 4];  // Random move
           cout<<"Enter direction like(up, down, left, right): ";
           cin>>moveDirection;
            robot->hitBall(ball, moveDirection);

            cout << robot->getName() << " moved the ball " << moveDirection 
                 << " to (" << ball.getx() << ", " << ball.gety() << ")\n";
        }
        cout << team->getTeamname()<< " scored in " << robot->getHits() << " hits!\n\n";
    }


    void declareWinner() {
        cout << "Declaring the winner...\n";
        int hits1 = team1.getrobot()->getHits();
        int hits2 = team2.getrobot()->getHits();

        if (hits1 < hits2) cout << team1.getTeamname() << " wins!\n";
        else if (hits1 > hits2) cout << team2.getTeamname() << " wins!\n";
        else cout << "It's a tie!\n";
    }

};
int main(){
    //srand(time(0));  
    cout<<"=============================="<<endl;
    cout<<"| MY Name:M Hasnain Siddiqui |"<<endl;
    cout<<"| Roll num: 24K-0516         |"<<endl;
    cout<<"=============================="<<endl;
    Game game("Team A", "Robot Alpha", "Team B", "Robot Beta");
    game.startgame();

    return 0;
}
