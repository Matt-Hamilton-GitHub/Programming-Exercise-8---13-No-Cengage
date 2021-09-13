
 //                                            ********* Writer: Matt Hamilton    *********
 //                                             ******** Class: CS 136            ******** 
 //                                              ******* Professor: Brian Dauzat  *******
 //                                                ***** Programming Exercise 8-13*****
 //                                                 **** ======================== ****
 //                                                   **  *** *** *** *** *** *** **


/*Write a program to calculate students' average test scores and their grades. You may assume the following input data:


Use three arrays: a one-dimensional array to store the student's names, a paralel) two-dimensional array to store the test scores, and a parallel one-dimensional array to store grades. Your program must contain at least the following functions: a function to read and store data into two arrays, a function to calculate the average test score and grade, and a function to output the results. Have your program also output the class average. */


#include <iostream>
#include <array>
#include <string>
#include <iomanip>
#include <fstream> // the library helkps us to read data from a file

using namespace std;

//the function below reads and stores data into two arrays from a file named "grade book"
void setData(string names[10], unsigned int scores[10][5]);

// the function below calculates the average test score and grade. It uses function gradeIt to estimate a letter grade. I have decided to divide this function into two functions to simplify my code and make it easier to read and manage. Hope it is okay.
float calculateAverage(unsigned int scores[10][5], char grades[10], int index);
char gradeIt(unsigned int averageGrade);

// the function below displays all the data
void display_results( string names[10], unsigned int scores[10][5], char grades[10]);



int main() {
//a one-dimensional  (paralel) array to store the student's names. contains 10 names
string st_names[10] = {};
 
 //two-dimensional array that stores the test scores
 //data is copied from the exercise 
 unsigned int scores[10][5] = {{}};
 // a parallel one-dimensional array that stores the grades
 char grades[10] = {};
 

setData(st_names, scores);//set all the data from the file 

display_results(st_names, scores, grades); // diplay results 


system("pause");
  return 0;
}


void setData(string names[10], unsigned int scores[10][5]){
  
  //the command below enters the file and reads data from it 

  ifstream students("grade book.txt");

  // now we set the data from the file to our arrays
if(students){

  for (int i {0}; i <= 9; i++){
    students >> names[i]; // copy the names to the names array

     for(int x {0}; x <= 4; x++){
          students >> scores[i][x]; // copy the grades for each student from the file
     }

  }
// we must close the file after we are done copying it
  students.close(); 
}else{
  cout << "The program was unable to find the file called 'grade book.txt'  Please, Try Again!" << endl;
  exit(0);
}
}



float calculateAverage(unsigned int scores[10][5], char grades[10], int index){
         
 float average = 0.0;//average grade stores here
 unsigned int sum = 0; // sum for evry student stores here

        for(int j{0}; j <5; j++){
          sum+=scores[index][j];
      }

average = sum / 5.0;
grades[index] = gradeIt(average);

 return average;  
};

char gradeIt(unsigned int everageGrade){

  if(everageGrade >= 90 ){
    return  'A';
  }else if (everageGrade >= 80){
    return  'B';
  }else if (everageGrade >= 70){
    return  'C';
  }else if (everageGrade >= 60){
    return  'D';
  }else if (everageGrade >= 50){
    return  'E';
  }else{
     return 'F';
  }
}

void display_results( string names[10], unsigned int scores[10][5], char grades[10]){
  
  cout << "--------------------------------------------------------------------------------" << endl;
  cout << setw(28) << left << "Student: " 
  << setw(20) << left << "Scores" 
  << setw(20) << left << "Average" 
  <<  setw(15) << "Final Grade" << endl; 
cout << "--------------------------------------------------------------------------------" << endl;
  for (int i{0}; i < 10; i++){
    cout << setw(10) << left << names[i] << "              ";
    
     for(int student {0}; student < 5; student++){
         cout << scores[i][student] <<  " ";
    }
      cout <<  setw(10) << left  << "    "<< fixed << setprecision(1) << calculateAverage(scores, grades, i);
      cout <<  setw(20) << left  << "    " << grades[i] << endl;

  }
  cout << "--------------------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------" << endl;
  
}