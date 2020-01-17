   /*  Grace Provost
      *  gprovost@pdx.edu
      *  Program 4
      *  11/20/19
      *  CS 162
      *
      *  PURPOSE: contains the implementation of the class functions for question and questionList.
   */

#include "header.h"

using namespace std;

// QUESTION IMPLEMENTATION

// constructor that sets initial values within a question
question::question()
{
    number = 0;
    subject = 0;
    text = NULL;
    date = NULL;
        
    return;
}

// constructor that sets initial values within a question
// accepts a questionNumber (which comes from questionList)
question::question(int questionNumber)
{
    number = questionNumber;
    subject = 0;
    text = NULL;
    date = NULL;
        
    return;
}


// deletes the pointer links
question::~question()
{
    if(date) delete [] date;
    if(text) delete [] text;
}

 // promps the user to enter in a responses for the question contents
 void question::getQuestion(int count)
 {
     subject = getSubject();
     cout << "Enter question text: ";
     // obtain question text.
     getString(text, MAX_QUESTION_TEXT_SIZE);
     cout << "Enter today's date (xx/xx/xxxx): ";
     // obtain the date from the user and set the size with the return value
     getDate(date, MAX_DATE_SIZE);
     number = count;
     return;
 }

 // displays question in terminal
 void question::display()
 {
     cout << "Number: " << number << endl;
     cout << "Date Added: " << date << endl;
     cout << "Subject: " << subjects[subject].name << endl;
     cout << "Text: " << text << endl;
     cout << "_________________________" << endl;
     cout << endl;
     return;
 }

// checks if the subject of the question matches the one given
// takes in an integer that represents the subject
// returns a bool
bool question::compareSubject(int subject)
{
    // compare the subject on the question with this
    // to the subject passed in
    return this->subject == subject;
}

// QUESTIONLIST IMPLEMENTATION

// constructor to set the default data values
questionList::questionList()
{
     questions = new question[MAX_NEW_QUESTIONS];
    size = 0;
}

// deletes the pointer links
questionList::~questionList()
{
    if (questions) delete [] questions;
}
// creates a new question within a loop
// and utilizes that question's getQuestion() 
// and then adds it to a dynamic array
// until the user is finished adding questions
// or the max is reached
void questionList::createQuestions(void)
{
     // count for the questions
     int count = 0;
     // while condition
     bool addQuestion = true;
     // create an array of the max possible values
     do
     {
         // pass in count + 1 since we start at zero for the array
         questions[count].getQuestion(count + 1);
         count++;
         cout << "You've entered " << count << "/10 new questions" << endl;
         if(count < MAX_NEW_QUESTIONS)
         {
             cout << "Would you like to enter another question? (y/n): ";
             addQuestion = getResponse();
             if(addQuestion) cout << endl;
         }
         else cout << "You've entered the max amount of questions!" << endl;
     // while the user wants to add a question and the total amount is less than the max of 10
     } while(addQuestion && count < MAX_NEW_QUESTIONS + 1);
     size = count;
     return;
}
// displays all questions in the list
// utilizes question's display()
void questionList::displayAllQuestions(void)
{
    // because we have to
     int i;
     for(i = 0; i < size; ++i) questions[i].display();
     cout << i << " questions displayed!" << endl;
     return;
}
// displays questions based on the retreived subject
// utilizes question's compareSubject() and display()
void questionList::displayQuestionsBySubject(void)
{
     // because we have to
     int i;
     // keep track of what is actuallyed displayed
     int questionsDisplayed = 0;
     // subject selected by user to display
     int subject;

     cout << "Select a subject you would like to see from loaded questions" << endl;
     subject = getSubject();
     cout << "Showing loaded questions of the subject " << subjects[subject].name << ": " << endl << endl;
     // loop over questions and only show those that are the selected subject
     for(i = 0; i < size; ++i)
     {
         if (questions[i].compareSubject(subject))
         {
             questions[i].display();
            questionsDisplayed++;
         }
     }
     // tell the user how many questions were displayed
     if(questionsDisplayed > 0) cout << questionsDisplayed << " question(s) displayed!" << endl;
     // or if none were found of that type
     else cout << "No questions exist of that subject!" << endl;
     return;
}
