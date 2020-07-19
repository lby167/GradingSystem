//
//  main.cpp
//  GradingSystem
//
//  Created by Bo Ying Liu on 10/27/19.
//  Copyright © 2019 Bo Ying Liu. All rights reserved.
//
#include<iostream>
#include<iomanip>

using namespace std;

struct student_data //student data structure
{
    string Student_name; //Student name
    int id; //Student ID
    int *tests;//Pointer to an array of test scores
    double average;// average test score variable
    char grade;//Course Grade variable
};
//The program should keep a list of test scores for a goup of students.
int main()
{
    int numStudents,testScores;//ask the user how many test scores and how many students
    
    //dynamically allocate an array of structures for each structure's test point to a dynamically allocated
    //array that will hold the test scores.
    cout <<"Enter number of students :";
    cin >> numStudents;
    cout <<"Enter number of test scores :";
    cin >> testScores;
    
    student_data *pointer_to_array = new student_data[numStudents];
    for(int i=0; i<numStudents; i++)
    {
        pointer_to_array[i].tests = new int[testScores];
    }
    //After the arrays have been dynamically allocated, the program should ask for the ID number and all the test scores for each student.
    for(int i=0; i<numStudents; i++)
    {
        cout <<"Enter Student Name. :";
        cin >> pointer_to_array[i].Student_name;
        cout <<"Enter Student ID. :";
        cin >> pointer_to_array[i].id;
        for(int j=0; j<testScores; j++)
        {
            cout <<"Enter Student " << (i+1) << " Test Score " << (j+1) << " : ";
            //Be sure all the data for each student are entered. Do no accept negative numbers for any test score.
            cin >> pointer_to_array[i].tests[j];
           
            
            //invalid score test while loop
            while(pointer_to_array[i].tests[j]<0 || pointer_to_array[i].tests[j]>100)
            {
                cout <<"Invalid value entered. Re-Enter Score :";
                cin >> pointer_to_array[i].tests[j];
               
            }
        }
    }
    
    
    for(int i=0; i<numStudents; i++)
    {
        double sum = 0;
        for(int j=0; j<testScores; j++)
            sum = sum + pointer_to_array[i].tests[j];
            pointer_to_array[i].average = sum/testScores;
        
        //The course grade should then be stored in the "grade" member of each structure.
        //Once all these data are calculated,
        
        if(pointer_to_array[i].average >=91 && pointer_to_array[i].average<=100)
            pointer_to_array[i].grade = 'A';
        else if(pointer_to_array[i].average >=81 && pointer_to_array[i].average<=90)
            pointer_to_array[i].grade = 'B';
        else if(pointer_to_array[i].average >=71 && pointer_to_array[i].average<=80)
            pointer_to_array[i].grade = 'C';
        else if(pointer_to_array[i].average >=61 && pointer_to_array[i].average<=70)
            pointer_to_array[i].grade = 'D';
        else if(pointer_to_array[i].average <60)
            pointer_to_array[i].grade = 'F';
    }
    //show listing each student's name, ID number, average test score, and course grade.
    cout <<"Student Name    Student ID   Averagae Test score   Grade " << endl;
    for(int i=0; i<numStudents; i++)
    {
        cout << setw(19) << left<< pointer_to_array[i].Student_name <<
        setw(19) << pointer_to_array[i].id <<
        setw(15) << pointer_to_array[i].average <<
        setw(15) << pointer_to_array[i].grade << endl;
    }
    
    return 0;
}
