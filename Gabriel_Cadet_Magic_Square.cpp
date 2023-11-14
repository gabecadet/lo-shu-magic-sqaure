
/*
* Description: Create a Lo Shu Magic sqaure using one dimensional parallel arrays.
  Print your Name here: Gabriel Cadet
*/

#include <iostream>
#include <string>
using namespace std;

// Global constants
const int ROWS = 3; // The number of rows in the array
const int COLS = 3; // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

// added custom function prototype as needed
int arraySum(int array[], int size);

int main()
{

    /* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
    const string programmerName = "Gabriel Cadet", dueDate = "5/5/2021";
       const int assignNum = 5;
    
    int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
    // Your code goes here
    int repeat = 1;

    while (repeat == 1) {
        
        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, ROWS);
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);


        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, ROWS) == true) {
            cout << endl << "This is a Lo Shu magic square.";
        }
        else {
            cout << endl << "This is not a Lo Shu magic square.";
        }
        cout << endl << "Would you like to try again? Enter 1 for yes or 0  for no: ";
        cin >> repeat;
    } while (repeat);
    
    cout << "\n\nName: " << programmerName << endl
             << "Project #: " << assignNum << endl
             << "Due Date: " << dueDate << endl
                << "Thank you for testing my project!!\n";
        return 0;
    }


bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    bool trueFalse = false;
    if (checkRange(arrayRow1, arrayRow2, arrayRow3, ROWS, MIN, MAX) == true && checkUnique(arrayRow1, arrayRow2, arrayRow3, ROWS) == true) {
        if (checkRowSum(arrayRow1, arrayRow2, arrayRow3, ROWS) == true && checkColSum(arrayRow1, arrayRow2, arrayRow3, ROWS) == true) {
            if (checkDiagSum(arrayRow1, arrayRow2, arrayRow3, ROWS) == true) {
                trueFalse = true;
            }
        }
    }

    return trueFalse;
}
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{

    for (int i = 0; i < size; i++)
    {
        if (arrayRow1[i] < min || arrayRow1[i] > max || arrayRow2[i] < min || arrayRow2[i] > max || arrayRow3[i] < min || arrayRow3[i] > max)
        {
            cout << "A number is out of range" << endl;
            return false;
        }
    }
    return true;
}
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arrayRow1[i] == arrayRow1[j])
            {
                cout << "Non unique in ArrayRow1" << endl;
                return false;
            }
        }
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arrayRow2[i] == arrayRow2[j])
            {
                cout << "Non unique in ArrayRow2" << endl;
                return false;
            }
        }
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arrayRow3[i] == arrayRow3[j])
            {
                cout << "Non unique in ArrayRow3" << endl;
                return false;
            }
        }
    }

    for (int j = 0; j < size; j++)
    {
        for (int k = 0; k < size; k++)
        {
            for (int l = 0; l < size; l++)
            {
              
                if (arrayRow1[j] == arrayRow2[k] || arrayRow1[j] == arrayRow3[l] || arrayRow2[k] == arrayRow3[l])
                {
                    cout << "non unique value found" << endl;
                    return false;
                }
            }
        }
    }
    return true;
}


void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int userInput;

    
    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 1, column " << i+1 << ": ";
        cin >> userInput;
        arrayRow1[i] = userInput;
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 2, column " << i+1 << ": ";
        cin >> userInput;
        arrayRow2[i] = userInput;
        cout << endl;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number for row 3, column " << i+1 << ": ";
        cin >> userInput;
        arrayRow3[i] = userInput;
        cout << endl;
    }
}
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arrayrow1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << arrayrow2[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << arrayrow3[i] << " ";
    }
    cout << endl;
}

bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    bool magicSquare = true;
    int sumRow1 = 0;
    int sumRow2 = 0;
    int sumRow3 = 0;

    for (int i = 0; i < size; i++) {
        sumRow1 += arrayrow1[i];
    }

    for (int i = 0; i < size; i++) {
        sumRow2 += arrayrow2[i];
    }

    for (int i = 0; i < size; i++) {
        sumRow3 += arrayrow3[i];
    }

    if (sumRow1 == 15 && sumRow2 == 15 && sumRow3 == 15) {
        magicSquare = true;
    }
    else {
        magicSquare = false;
    }

    return magicSquare;
}
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{

    int totalSum[size];

    for (int i = 0; i < size; i++)
    {
        int colArray[3] = {arrayrow1[i], arrayrow2[i], arrayrow3[i]};
        totalSum[i] = arraySum(colArray, size);
    }

    return totalSum[0] == totalSum[1] &&
           totalSum[1] == totalSum[2];
}
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
   
    int diagonalOne[3] = {arrayrow1[2], arrayrow2[1], arrayrow3[0]}, diagonalTwo[3] = {arrayrow1[0], arrayrow2[1], arrayrow3[2]};

    return arraySum(diagonalOne, size) == arraySum(diagonalTwo, size);
}


int arraySum(int array[], int size)
{
   
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

