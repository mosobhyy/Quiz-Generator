#ifndef MCQ_H
#define MCQ_H
#include <Question.h>
#include <string>

class MCQ : public Question
{

public:

    // Attributes

    std::string answers[4];

    // Constructor

    MCQ();

    // Destructor

    ~MCQ();
};

#endif // MCQ_H

