#ifndef QUIZ_H
#define QUIZ_H

class Quiz
{
    public:
        int score;
        void generateQuiz();
        void generateMCQ();
        void generateTF();
        void generateComplete();
        Quiz();
        ~Quiz();
};

#endif // QUIZ_H
