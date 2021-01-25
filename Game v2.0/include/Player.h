#ifndef PLAYER_H
#define PLAYER_H
#include <User.h>

class Player : public User
{
public:

    // Methods

    void mainMenu();
    void newQuiz();
    void display_allStatisics();
    void display_scores();
    void display_lastTwo();
    friend bool operator == (Player const obj1, User const *obj2);

    // Constructors

    Player();
    Player(std::string userName, std::string password, std::string firstName, std::string lastName);

    // Destructor

    ~Player();
};

#endif // PLAYER_H
