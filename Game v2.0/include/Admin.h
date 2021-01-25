#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "User.h"
#include <Player.h>

class Admin : public User
{
    public:

        // Methods

        void mainMenu();
        void viewAllUsers();
        void addNewUser();
        void viewQuestions();
        void deleteQuestion(int id);
        void addQuestion();
        void addMcq();
        void addTf();
        void addComplete();
        void loadFile(std::string file);
        void mcqPrint();
        void tfPrint();
        void completePrint();
        friend bool operator == (Admin const obj1, User const *obj2);

        // Constructors

        Admin();
        Admin(std::string userName, std::string password, std::string firstName, std::string lastName);

        // Destructor

        ~Admin();
};

#endif // ADMIN_H
