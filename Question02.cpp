#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Ball 
{
public:
    int x, y;
    Ball() : x(0), y(0) {}
    void move(int ax, int ay) 
    { 
        x += ax; 
        y += ay; 
    }
    pair<int, int> getPosition() 
    {
        return {x, y}; 
    }
};

class Goal 
{
public:
    const int x = 3, y = 3;
    bool destiny(int xBall, int yBall) 
    { 
        return xBall == x && yBall == y; 
    }
};

class Robot 
{
public:
    string name;
    int numberOfHits;
    Robot(string n) : name(n), numberOfHits(0) {}
    void hitTheBall(Ball &ball, string direction) 
    {
        numberOfHits++;
        if (direction == "up") 
        {
            ball.move(0, 1);
        }
        else if (direction == "down") 
        {
            ball.move(0, -1);
        }
        else if (direction == "left") 
        {
            ball.move(-1, 0);
        }
        else if (direction == "right") 
        {
            ball.move(1, 0);
        }    
    }
};

class Team 
{
public:
    string teamName;
    Robot* player;
    Team(string name, string rName) : teamName(name) 
    {
         player = new Robot(rName); 
    }
    
    ~Team() 
    {
        delete player;
    }
};

class Game 
{
public:
    Team* team1;
    Team* team2;
    Ball ball;
    Goal goal;

    Game(string team1Name, string robot1Name, string team2Name, string robot2Name) 
    {
        team1 = new Team(team1Name, robot1Name);
        team2 = new Team(team2Name, robot2Name);
    }

    ~Game() 
    {
        delete team1; 
        delete team2;
    }

    void play(Team* team) 
    {
        ball = Ball();
        while (!goal.destiny(ball.x, ball.y)) 
        {
            string commands[] = {"up", "down", "left", "right"};
            string movement = commands[rand() % 4];
            team->player->hitTheBall(ball, movement);
        }
    }

    void startGame() 
    {
        srand(static_cast<unsigned int>(time(0)));
        play(team1);
        int hits_1 = team1->player->numberOfHits;
        play(team2);
        int hits_2 = team2->player->numberOfHits;
        winner(hits_1, hits_2);
    }

    void winner(int hits1, int hits2) 
    {
        if (hits1 < hits2) 
        {
            cout << team1->teamName << " wins with " << hits1 << " hits" << endl;
        }
        else if (hits2 < hits1) 
        {
            cout << team2->teamName << " wins with " << hits2 << " hits" << endl;
        }
        else 
        {
            cout << "It's a tie Match!" << endl;
        }
    }
};

int main() 
{
    Game game("Karachi Kings", "Peshawar Zalmi", "Multan Sultan", "Islamabad Uniteds");
    game.startGame();
    return 0;
}
