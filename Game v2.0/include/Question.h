#ifndef QUESTION_H
#define QUESTION_H
#include <string>

class Question
{
    public:
        static int counter;
        std::string question, answer;

        int questionId;
        Question();
        ~Question();
};

#endif // QUESTION_H
