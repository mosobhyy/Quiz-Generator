#include <iostream>

#include <fstream>

#include <vector>

#include <cstdlib>

#include <ctime>

using namespace std;

void Main_Menu();

void administration_Menu();

string update_Name();

void view_Questions();

void Delete_Question();

void Add_Question();

void Load_file();

void New_Quiz();

void Scores_Stats();

void Display_All_Scores();

// Global Variables

vector<string> questions(8);
vector<string> answers(32);
vector<string> correct(8);
vector<int> stats;
string name = "USER", file;
int num_Of_Quizzes = 0, high_Score = 0, Low_Score = 11;
float avg_score = 0;

// Main Function

int main()
{
    string choice, main_Options, administration_Options;
    int answerIterator = 0;
    ifstream questionsFile("exam_questions.txt");
    for (unsigned int i = 0 ; i < questions.size() ; i++)
    {
        getline(questionsFile, file);
        questions[i] = file;
        for (int x = 0 ; x < 4 ; x++)
        {
            getline(questionsFile, file);
            answers[answerIterator] = file;
            answerIterator ++;
            if(x == 0)
            {
                correct[i] = file;
            }
        }
    }
Main_Screen:
    cout << endl <<"Welcome " << name << " please choose from the following options:" << endl;
    Main_Menu();
    cout << endl << "My Choice : ";
    cin >> main_Options;
    if(main_Options == "1")
    {

administration_Screen:

        administration_Menu();
        cin >> administration_Options;
        if (administration_Options == "1")
        {

reView:

            view_Questions();

delete_re_Choice:

            cout << endl << "Press [d] if you want to delete a question" << endl;
            cout << endl << "Enter 'all' if you want to delete all questions" << endl;
            cout << endl << "Press [b] if you want to go back to the main menu or [e] to exit" << endl;
            cout << endl << "My Choice : ";
            cin >> choice;
            if (choice == "b")
            {
                goto Main_Screen;
            }
            else if(choice == "d")
            {
                Delete_Question();
                goto reView;
            }
            else if(choice == "all")
            {
                questions.clear();
                answers.clear();
                goto administration_Screen;
            }
            else if (choice == "e"){
                cout << endl << "Thank you for using our application ^_^" << endl;
            }
            else
            {
                cout << endl << "Please Enter a valid choice" << endl;
                goto delete_re_Choice;
            }
        }

        else if(administration_Options == "2")
        {
            Add_Question();
reChoice:
            cout << endl << "Press [b] if you want to go back to the main menu or [e] to exit" << endl;
            cin >> choice;
            if (choice == "b")
            {
                goto Main_Screen;
            }
            else if (choice == "e")
            {
                cout << endl << "Thank you for using our application ^_^" << endl;
            }
            else
            {
                cout << endl << "Please Enter a valid choice" << endl;
                goto reChoice;
            }
        }

        else if (administration_Options == "3")
        {
            Load_file();
            goto Main_Screen;
        }

        else if (administration_Options == "4")
        {
            goto Main_Screen;
        }
        else
        {
            cout << endl << "Please Enter a valid choice" << endl;
            goto administration_Screen;
        }
    }
    else if (main_Options == "2")
    {
        update_Name();
        goto Main_Screen;
    }

    else if (main_Options == "3")
    {
        New_Quiz();
        cout << endl << "Press [b] if you want to go back to the main menu or [e] to exit" << endl;
        cin >> choice;
        if (choice == "b")
        {
            goto Main_Screen;
        }
        else if (choice == "e"){
            cout << endl << "Thank you for using our application ^_^" << endl;
        }
        else
        {
            cout << endl << "Please Enter a valid choice" << endl;
            goto reChoice;
        }
    }

    else if (main_Options == "4")
    {
        Scores_Stats();
        cout << endl << "Press [b] if you want to go back to the main menu or [e] to exit" << endl;
        cin >> choice;
        if (choice == "b")
        {
            goto Main_Screen;
        }
        else if (choice == "e")
        {
            cout << endl << "Thank you for using our application ^_^" << endl;
        }
        else
        {
            cout << endl << "Please Enter a valid choice" << endl;
            goto reChoice;
        }
    }

    else if (main_Options == "5")
    {
        Display_All_Scores();
        cout << endl << "Press [b] if you want to go back to the main menu or [e] to exit" << endl;
        cin >> choice;
        if (choice == "b")
        {
            goto Main_Screen;
        }
        else if (choice == "e"){
            cout << endl << "Thank you for using our application ^_^" << endl;
        }
        else
        {
            cout << endl << "Please Enter a valid choice" << endl;
            goto reChoice;
        }
    }

    else if (main_Options == "6")
    {
        cout << endl << "Thank you for using our application ^_^" << endl;
    }

    else
    {
        cout << endl << "Please Enter a valid choice" << endl;
        goto Main_Screen;
    }
    return 0;
}

// Welcome Screen Function

void Main_Menu()
{
    cout << endl << "[1] Go to administration menu" << endl;
    cout << "[2] Update your name" << endl;
    cout << "[3] Start a new quiz" << endl;
    cout << "[4] Display your scores statistics" << endl;
    cout << "[5] Display all your scores" << endl;
    cout << "[6] Exit" << endl;
}

// Administration Menu Display Function

void administration_Menu()
{
    cout << endl << "Welcome to the administration menu, please choose from the following options:" << endl;
    cout << "[1] View all questions" << endl;
    cout << "[2] Add new question" << endl;
    cout << "[3] Load questions from file" << endl;
    cout << "[4] Go back to main menu" << endl;
    cout << endl << "My Choice : ";
}

// Update Name Function

string update_Name()
{
    cout << endl << "Enter your Name : ";
    cin >> name;
    return name;
}

// View All Questions Function

void view_Questions()
{
    if(questions.empty())
    {
        cout << endl << "Sorry " << name << ", No questions available right now !" << endl;
        cout << "You have to add questions or load it from a file !" << endl;
    }
    else
    {
        cout << endl << "Number of questions available: " << questions.size() << endl;
        cout << endl << "Questions list:" << endl;
        cout << "---------------" << endl;
        int answerIterator = 0;
        string str;
        for (unsigned int i = 0 ; i < questions.size() ; i++)
        {
            cout << "[" << i+1 << "]" << questions[i] << endl;
            for (int x = 0 ; x < 4 ; x++)
            {
                if (x == 0)
                    str = "      [a]";
                else if (x == 1)
                    str = "[b]";
                else if (x == 2)
                    str = "[c]";
                else if (x == 3)
                    str = "[d]";
                cout << str << answers[answerIterator] << "        ";
                answerIterator ++;
            }
            cout << endl;
        }
    }
}

// Delete a question Function

void Delete_Question()
{
    if(questions.empty())
    {
        cout << endl << "sorry " << name << ", No questions available right now !" << endl;
        cout << "You have to add questions or load it from a file !" << endl;
    }
    else
    {
        unsigned int num;
reChoice:
        cout << endl << "Enter number of question that you want to delete : ";
        cin >> num;
        int answ = (num-1) * 4;
        if (num < 1 || num > questions.size())
        {
            cout << endl << "Enter a valid question number" << endl;
            goto reChoice;
        }
        else
        {
            questions.erase(questions.begin() + num - 1);
            correct.erase(correct.begin() + num - 1);
            answers.erase(answers.begin() + answ, answers.begin()+ answ + 4);
        }
    }
}

// Add a new question Function

void Add_Question()
{
    int num;
    string str;
    cout << endl << "How many question do you want to add ? " << endl;
    cout << endl << "My Choice: ";
    cin >> num;
    cin.ignore();
    for (int i = 0 ; i < num ; i++)
    {
        cout << endl << "Enter your question: ";
        getline(cin, str);
        questions.push_back(str);
        for (int x = 0 ; x < 4 ; x++)
        {
            if (x == 0)
                cout << "Choice " << x + 1 << "[The right answer]: ";
            else
                cout << "Choice " << x + 1 << ": ";
            getline(cin, str);
            answers.push_back(str);
            if (x == 0)
                correct.push_back(str);
        }
    }
    view_Questions();
}

// Load questions from file Function

void Load_file()
{
    char fileName[20];
    string file;
Load:
    cout << "Enter File name followed by .txt : ";
    cin >> fileName;
    ifstream questionsFile(fileName);
    if(!questionsFile)
    {
        cout<<"Error in opening file..!!"<<endl;
        goto Load;
    }
    while (getline(questionsFile, file))
    {
        questions.push_back(file);
        for (int i = 0 ; i < 4 ; i++)
        {
            getline(questionsFile, file);
            answers.push_back(file);
        }
    }
    cout << endl << "File has been loaded successfully" << endl;
    questionsFile.close();
}

// New Quiz Function

void New_Quiz()
{
    int num_of_right = 0, num_of_wrong = 0;
    if(questions.size() < 5)
    {
        cout << endl << "Sorry, there are not enough questions to start the quiz" << endl;
    }
    else
    {
        num_Of_Quizzes ++;
        cout << endl << "Quiz " << num_Of_Quizzes << ":" << endl;
        cout << "-------" << endl;
        int score = 0, value, answersIterator = 0, checkIterator = 0;
        bool check, check_Answers;
        char str, right_ans;
        char choice;

        // Fill array by number won't reach for it to avoid similarity with numbers of the questions and answers

        int randOfQuestions[5] = {1000, 1000, 1000, 1000, 1000};
        int randOfAnswers[20];
        for (int i = 0 ; i < 20 ; i++)
        {
            randOfAnswers[i] = 1000;
        }

        srand(time(0));

        // Generate random questions

        for (int i = 0 ; i < 5 ; i++)
        {
            check = true;
            value = rand() % questions.size();

            // Check if this index of question is unique in array or not to not repeat question

            for (int x = 0 ; x < 5 ; x++)
            {
                if (value == randOfQuestions[x])
                {
                    check = false;
                    i--;
                    break;
                }
            }
            if (check == true)
            {
                randOfQuestions[i] = value;
            }
        }


        // Generate random Answers

        for (int i = 0 ; i < 5 ; i++)
        {
            for (int x = 0 ; x < 4 ; x++)
            {
                check_Answers = true;
                value = rand() % 4 +(4*randOfQuestions[i]);

                // Check if this index of answer is unique in array or not to not repeat answers


                for (int z = 0 ; z < 20 ; z++)
                {
                    if(value == randOfAnswers[z])
                    {
                        check_Answers = false;
                        x--;
                        break;
                    }
                }
                if (check_Answers == true)
                {
                    randOfAnswers[answersIterator] = value;
                    answersIterator++;
                }
            }
        }

        // Print questions and answers

        answersIterator = 0;

        for (int i = 0 ; i < 5 ; i++)
        {
            cout << endl << "[" << i+1 << "]" << questions[randOfQuestions[i]] << endl;
            for (int x = 0 ; x < 4 ; x++)
            {
                if (x == 0)
                {
                    cout << "       ";
                    str = 'a';
                }
                else if (x == 1)
                    str = 'b';
                else if (x == 2)
                    str = 'c';
                else if (x == 3)
                    str = 'd';
                cout << "[" << str << "]" << answers[randOfAnswers[answersIterator]] << "        ";
                if (answers[randOfAnswers[answersIterator]] == correct[randOfQuestions[i]])
                {
                    right_ans = str;
                    checkIterator++;
                }
                answersIterator++;
            }
reChoice:
            cout << endl << "My Choice : ";
            cin >> choice;
            if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd')
            {
                if (choice == right_ans)
                {
                    score += 2;
                    num_of_right++;
                }
                else
                    num_of_wrong++;
            }
            else
            {
                cout << endl << "Please Enter a valid choice" << endl;
                goto reChoice;
            }

        }
        if (num_Of_Quizzes == 1)
            Low_Score = score;
        avg_score += score;
        if (score > high_Score)
            high_Score = score;
        else if (score < Low_Score)
            Low_Score = score;
        stats.push_back(num_of_right);
        stats.push_back(num_of_wrong);
        stats.push_back(score);
        cout << endl << "Your score = " << score << "/10" << endl;
    }
}

// Display your scores statistics

void Scores_Stats()
{
    if (num_Of_Quizzes == 0)
    {
        cout << endl << "You don't have any scores yet !" << endl;
    }
    else
    {
        cout << "Your score statistics:" << endl;
        cout << "       - Number of Quizzes taken: " << num_Of_Quizzes << endl;
        cout << "       - Highest score: " << high_Score << endl;
        cout << "       - Lowest score: " << Low_Score << endl;
        cout << "       - Average score: " << avg_score/num_Of_Quizzes << endl;
    }
}

// Display all your scores Function

void Display_All_Scores()
{
    if (num_Of_Quizzes == 0)
    {
        cout << endl << "You don't have submitted any quizzes yet !" << endl;
    }
    else
    {
        int statsIterator = 0;
        cout << endl << "Number of Quizzes taken: " << num_Of_Quizzes << endl;
        for (int i = 0 ; i < num_Of_Quizzes; i++)
        {
            cout << endl << "Quiz " << i + 1 << " statistics:" << endl;
            cout << "------------------" << endl;
            for (int x = 0 ; x < 3 ; x++)
            {
                switch(x)
                {
                case 0:
                    cout << "Number of right answers: " << stats[statsIterator] << endl;
                    break;
                case 1:
                    cout << "Number of wrong answers: " << stats[statsIterator] << endl;
                    break;
                case 2:
                    cout << "Score: " << stats[statsIterator] << endl;
                    break;
                }
                statsIterator ++;
            }
        }
    }
}
