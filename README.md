# CS162_program4

gprovost@pdx.edu

Program 4
    
11/20/19
    
CS 162
  
    PURPOSE: main file which contains the main function and other helper functions that do not belong to classes. These include mostly helpers for getting things from the user and validation. The purpose of the program is to allow users to enter up to 10 questions and display them all or by subject.
  
    Algorithm:
    1. create global constants to use within all files:
        - int MAX_DATE_SIZE
        - int MAX_QUESTION_TEXT_SIZE
        - int MAX_NEW_QUESTIONS
        - int NUMBER_OF_SUBJECTS
        - subjectArray[] subjects
    2. as well as a struct used for subjects
       - subjectArray
    3. initalize variables within main
       - questionList myList
       - bool questionsAdded
       - int menuChoice
    4. create a class to manage the question
    5. create a class to manage a list of quesitons (questionList)
    6. wrap step 7 onwards in a do-while loop
        - the user will be able repeatedly go back to the main menu screen until they quit
     7. Ask the user what action they would like to preform, display those actions via getMainMenu(), and retrieve menuChoice.    Use a switch case to determine what to do based on that menuChoice
     8. questionList.createQuetions()
        - the user will be asked to enter question information with question.getQuestion()
        - the user will be asked with getResponse() if they would like to enter another question
     9. questionList.displayAllQuestions() displays all questions with question.display()
     10. questionList.displayQuestionsBySubject() gets user input with getSubject() and only displays based on a matched subject with question.display()
     11. if the user selects 0 with menuChoice, they will exit the program
