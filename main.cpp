
/*  Grace Provost
  *  gprovost@pdx.edu
  *  Program 4
  *  11/20/19
  *  CS 162
  *
  *  PURPOSE: main file which contains the main function and other helper functions that do not belong to classes. These include mostly helpers for getting things from the user and validation. The purpose of the program is to allow users to enter up to 10 questions and display them all or by subject.
  *
  *  Algorithm:
  *  1. create global constants to use within all files:
   *     - int MAX_DATE_SIZE
   *     - int MAX_QUESTION_TEXT_SIZE
   *     - int MAX_NEW_QUESTIONS
   *     - int NUMBER_OF_SUBJECTS
   *     - subjectArray[] subjects
   * 2. as well as a struct used for subjects
   *    - subjectArray
   * 3. initalize variables within main
   *    - questionList myList
   *    - bool questionsAdded
   *    - int menuChoice
   * 4. create a class to manage the question
   * 5. create a class to manage a list of quesitons (questionList)
   * 6. wrap step 7 onwards in a do-while loop
   *     - the user will be able repeatedly go back to the main menu screen until they quit
   *  7. Ask the user what action they would like to preform, display those actions via getMainMenu(), and retrieve menuChoice.    Use a switch case to determine what to do based on that menuChoice
   *  8. questionList.createQuetions() 
   *     - the user will be asked to enter question information with question.getQuestion()
   *     - the user will be asked with getResponse() if they would like to enter another question
   *  9. questionList.displayAllQuestions() displays all questions with question.display()
   *  10. questionList.displayQuestionsBySubject() gets user input with getSubject() and only displays based on a matched subject with question.display()
   *  11. if the user selects 0 with menuChoice, they will exit the program
*/

#include "header.h"

using namespace std;

int main()
{
           // VARIABLES
        // instantiate a new list of questions
        questionList myList;
       // to keep track if new questions have been added
       bool questionsAdded = false;
       // to keep track of what option the user choses from the
       // main menu. If zero, will end program
       int menuChoice;
       // welcome the user and show main menu to begin
       cout << "Welcome. This program collects programming practice questions and displays them to you. Please select what you would like to do:" << endl;
       do
       {
           menuChoice = getMainMenu();
           cout << "________________________________" << endl;
           // switch case to interpret users selection
            menuSwitch( menuChoice, questionsAdded, myList);

       }
       while(menuChoice != 0);

       cout << "Goodbye!" << endl;
       return 0;
    return 0;
}

// FUNCTION IMPLEMENTATIONS

// switch case to interpret users selection
 void menuSwitch(int menuChoice, bool& questionsAdded, questionList& myList)
 {
     switch(menuChoice)
     {
         case 1:
             // dont let the user add more questions if they already have
             if (!questionsAdded)
             {
                 cout << "Let's create some new pratice questions!" << endl;
                 myList.createQuestions();
                 questionsAdded = true;
             }
             else cout << "You've already entered questions. Quit the program to enter more again." << endl;
             break;
        case 2:
             // if the user has not loaded, dont print
             if(questionsAdded) myList.displayAllQuestions();
             else cout << "You need to enter some questions first to display them!" << endl;
             break;
        case 3:
             // if the user has not loaded, dont print
             if(questionsAdded) myList.displayQuestionsBySubject();
             else cout << "You need to enter some questions first to display them!" << endl;
             break;
        default:
             break;
     }
 }



// displays the main menu and obtains the users
 // response to what they want to do
 int getMainMenu()
 {
     // an integer for the highest possible response
     int maxResponse = 3;
     // an integer for the lowest possible response
     int minResponse = 0;
     cout << "~~~~~~~~~~ Main Menu ~~~~~~~~~~" << endl;
     cout << "0. Quit program" << endl;
     cout << "1. Create new practice questions" << endl;
     cout << "2. Display all entered questions" << endl;
     cout << "3. Display all entered questions of a certain subject" << endl;
     cout << "Enter a corresponding number to preform a task: ";

     return getIntegerRangeResponse(maxResponse, minResponse);
 }


 // get subject
 int getSubject(void)
 {
     cout << "Subjects:" << endl;
     cout << "1. Condition Flow" << endl;
     cout << "2. Loops" << endl;
     cout << "3. Arrays" << endl;
     cout << "4. Functions" << endl;
     cout << "5. Structures" << endl;
     cout << "6. External Files" << endl;
     cout << "Select a subject for your question (1-6): ";
     // obtain the response offset by one to match the subject array
     return getIntegerRangeResponse(6,1) - 1;
 }



 // obtains an integer response
 // between a certain inclusive range
 int getIntegerRangeResponse(int max, int min)
 {
     int response;
     while(!(cin >> response)
             // if not greater than or equal to min
             || !(response >= min
             // or less than or equal to max
             && response <= max))
     {
         cout << "Invalid input, try again: ";
         clearBufferStream();
     }
     clearBufferStream();
     return response;
 }



 // a helper function for cleaning out the buffer
 // since we will be doing it multiple times
 void clearBufferStream(void)
 {
    // clear out the errorstate
    // just in case it exists
    cin.clear();
    // ignore the rest of what is in the stream
    // up to 200 characters or
    // until carriage return is hit '\n'
    // and we can flush out the carriage return
    cin.ignore(200,'\n');
    return;
 }

 // this helper takes in a char pointer
 // and creates a temp array to obtain user input up to the arraySize
 // then creates a new char array the exact size of the temp array
 // and places into the pointer
 void getString(char* &pointer, int arraySize)
 {
     // make a temp pointer so we can utilize this as a helper with possible different array sizes
    char *tempArray = new char[arraySize];
   // if the buffer stream is in error state
   while(!cin.get(tempArray, arraySize, '\n')
           // or the next character in the buffer is not a carriage return
           || cin.peek() != '\n')
   {
           // insert a break so we are not on the same line as "enter phrase number...:"
           cout << endl;
           if(cin.peek() != '\n') cout << "You entered too many characters, please try again: ";
           else cout << "Invalid input, please try again: ";
           // clear out that dirty stream
           clearBufferStream();
   }
   // clear out that dirty stream
   clearBufferStream();
   // create a new place in data for the char array
   pointer = new char[strlen(tempArray) + 1]; 

   // copy the temp array into the pointer;
   strcpy(pointer, tempArray);

   // clean up local memory
   delete [] tempArray;

   return;
 }



 // this helper takes in a char pointer
 // and creates a temp array to obtain user input up to the arraySize
 // then creates a new char array the exact size of the temp array
 // and places into the pointer
 // while providing validation specific to a date
 void getDate(char* &pointer, int arraySize)
 {
     // make a temp pointer so we can utilize this as a helper with possible different array sizes
    char *tempArray = new char[arraySize];
   // if the buffer stream is in error state
   while(!cin.get(tempArray, arraySize, '\n')
           // or the next character in the buffer is not a carriage return
           || cin.peek() != '\n'
           // if the date is less in size than it should be
           // not including the null terminator
           || strlen(tempArray) < arraySize - 1
           // if the dashes in the date dont exist
           || (tempArray[2] != '/' || tempArray[5] != '/')
           // if the date values are not numerical
           || !(isdigit(tempArray[0]) && isdigit(tempArray[1]) && isdigit(tempArray[3]) && isdigit(tempArray[4]) && isdigit(tempArray[6]) && isdigit(tempArray[7]) && isdigit(tempArray[8]) && isdigit(tempArray[9]))
           )
   {
           // insert a break so we are not on the same line as "enter phrase number...:"
           cout << endl;
           if(cin.peek() != '\n') cout << "You entered too many characters, please try again: ";
           else if(strlen(tempArray) < arraySize - 1) cout << "You entered too few characters, enter in xx/xx/xxxx format: ";
           else if(tempArray[2] != '/' || tempArray[5] != '/') cout << "You did not provide '/' at the expected positions, enter in xx/xx/xxxx format: ";
           else if(!(isdigit(tempArray[0]) && isdigit(tempArray[1]) && isdigit(tempArray[3]) && isdigit(tempArray[4]) && isdigit(tempArray[6]) && isdigit(tempArray[7]) && isdigit(tempArray[8]) && isdigit(tempArray[9]))) cout << "You did not enter digits for the day, month, or year. Enter in xx/xx/xxxx format: ";
           else cout << "Invalid input, please try again: ";
           // clear out that dirty stream
           clearBufferStream();
   }
   // clear out that dirty stream
   clearBufferStream();
   // create a new place in data for the char array
   pointer = new char[strlen(tempArray) + 1]; 

   // copy the temp array into the pointer;
   strcpy(pointer, tempArray);

   // clean up local memory
   delete [] tempArray;

   return;
 }



 // this helper obtains a single character
 // checks if it is a valid y / n response
 // and returns a boolean based on if the response
 // is yes = true, no = false
 bool getResponse(void)
 {
   char response = '\0';
   // if the buffer stream is in error state
   while(!cin.get(response)
           // if response is not equal to y
           || (tolower(response) != 'y'
               // if the response is not equal to n
               && tolower(response) != 'n')
           // or the next character in the buffer is not a carriage return
           || cin.peek() != '\n')
   {
           if(cin.peek() != '\n') cout << "You entered too many characters, please try again: ";
           else cout << "Invalid input, please try again: ";
           // clear out that dirty stream
           clearBufferStream();
   }
           // clear out that dirty stream
           clearBufferStream();
   // return a boolean
   return tolower(response) == 'y';
 }
