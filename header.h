/*  Grace Provost
   *  gprovost@pdx.edu
   *  Program 4
   *  11/20/19
   *  CS 162
   *  
   *  PURPOSE: header file containing function prototypes, constants, structs, and classes. all in one place for convenience to bring into the .cpp files.
*/

 #include <iostream>
 #include <cctype>
 #include <cstring>

 // CONSTANTS AND GLOBALS
 
// the max character size for a question subject
 const int MAX_SUBJECT_SIZE = 15;
 // max date size xx/xx/xxxx and includes space for '\n'
 const int MAX_DATE_SIZE = 11;
 // number of characters for the question text
 const int MAX_QUESTION_TEXT_SIZE = 130;
 // max size for new questions array
 const int MAX_NEW_QUESTIONS = 10;
 // the current number of subjects
 // must be increased if any more are added
    const int NUMBER_OF_SUBJECTS = 6;
 // a struct to pair size with the question subject
 struct subjectArray {
     char name[MAX_SUBJECT_SIZE];
     int size;
 };
 // an array to contain subjects so any function can access
 // new subjects can be created here
 // order does matter
 const subjectArray subjects[NUMBER_OF_SUBJECTS]  = {
     {
         "condition flow",
         14
     },
     {
         "loops",
         5
     },
     {
         "arrays",
         6
     },
     {
         "functions",
         9
     },
     {
         "structures",
         10
     },
     {
         "external files",
         14
     },
 };

// CLASS INTERFACES 


class question
{
    public:
        // constructor that sets initial values within a question
        question();
        // constructor that sets initial values within a question
        // accepts a questionNumber (which comes from questionList)
        question(int number);
        // deletes the pointer links
        ~question();
         // promps the user to enter in a responses for the question contents
        void getQuestion(int count);
         // displays question in terminal
        void display();
        // checks if the subject of the question matches the one given
        // takes in an integer that represents the subject
        // returns a bool
        bool compareSubject(int subject);

    private:
        // question number, purely for internal use
        int number;
        // subject is an integer since the string will be retrived from the constant 'subjects'
        int subject;
        // question text
        char* text;
        // question date
        char* date;
};

class questionList
{
    public:
        // constructor that sets initial values in a questionList
        questionList(void);
        // deletes the pointer links
        ~questionList(void);
        // creates a new question within a loop
        // and utilizes that question's getQuestion() 
        // and then adds it to a dynamic array
        // until the user is finished adding questions
        // or the max is reached
        void createQuestions(void);
        // displays all questions in the list
        // utilizes question's display()
        void displayAllQuestions(void);
        // displays questions based on the retreived subject
        // utilizes question's compareSubject() and display()
        void displayQuestionsBySubject(void);

    private:
        // the list of questions as a pointer
        question* questions;
        // the size of the questions array
        int size;
};

// FUNCTION PROTOTYPES

// displays the main menu and obtains the users
 // response to what they want to do
 int getMainMenu(void);

 // switch case to interpret users selection
 void menuSwitch(int menuChoice, bool& questionsAdded, questionList& myList);

 // a helper function for cleaning out the buffer
 // since we will be doing it multiple times
 void clearBufferStream(void);

 // this helper takes in a char pointer
 // and creates a temp array to obtain user input up to the arraySize
 // then creates a new char array the exact size of the temp array
 // and places into the pointer
 void getString(char* &pointer, int arraySize);

 // this helper obtains a single character
 // checks if it is a valid y / n response
 // and returns a boolean based on if the response
 // is yes = true, no = false
 bool getResponse(void);

 // obtains an integer response
 // between a certain inclusive range
 int getIntegerRangeResponse(int max, int min);

  // get subject
 int getSubject(void);

 // switch case to interpret users selection
 void menuSwitch(int menuChoice, questionList& questionList);

 // this helper takes in a char pointer
 // and creates a temp array to obtain user input up to the arraySize
 // then creates a new char array the exact size of the temp array
 // and places into the pointer
 // while providing validation specific to a date
 void getDate(char* &pointer, int arraySize);
