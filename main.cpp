// This program allow the user to enter three numbers and it will determine what type of triangle the three side lengths would form, if any.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
const int W = 7;

// Prototypes
void GetData(float & N1, float & N2, float & N3);
void Validate(float a, float b, float c, bool & ErrInvalid);
void TriangleType(float a, float b, float c, char & Type, bool & RightTriangle);
void Print(float a, float b, float c, char Type, bool RightTriangle, bool ErrInvalid, bool & Repeat);
void RNG();

int main() {
  // Variable Declaration
  float N1, N2, N3;
  char Type;
  bool Repeat, ErrInvalid, RightTriangle;
  Repeat = ErrInvalid = RightTriangle = false;
  int random;

  // User Prompt
  cout << "---Welcome User---\n\n";
  
  // Function Call
  do{
    GetData(N1, N2, N3);
    Validate(N1, N2, N3, ErrInvalid);
    if(!ErrInvalid){
      TriangleType(N1, N2, N3, Type, RightTriangle);
    }
    Print(N1, N2, N3, Type, RightTriangle, ErrInvalid, Repeat);
  } while(Repeat);

  // Programming Ending
  RNG();
  cout << "*Sad computer noises*\n";
  cout << "Goodbye... Zzz Zzz Zzz" << endl;
  
  return 0;
}
// Function Definitions
void GetData(float & N1, float & N2, float & N3){
  cout << "Enter the first length:\n";
  cin >> N1;
  cout << endl;
  while(N1 <= 0){
    cout << "ERROR: The number you entered is invalid\n";
    cout << "Please enter a positive number:\n";
    cin >> N1;
    cout << endl;
  }
  cout << "Enter the second length:\n";
  cin >> N2;
  cout << endl;
  while(N2 <= 0){
    cout << "ERROR: The number you entered is invalid\n";
    cout << "Please enter a positive number\n";
    cin >> N2;
    cout << endl;
  }
  cout << "Enter the third length:\n";
  cin >> N3;
  cout << endl;
  while(N3 <= 0){
    cout << "ERROR: The number you entered is invalid\n";
    cout << "Please enter a positive number\n";
    cin >> N3;
    cout << endl; 
  }
}

void Validate(float a, float b, float c, bool & ErrInvalid){
  // Check for Valid Triangle Lengths
  if( (a > (b + c)) || (b > (a + c)) || (c > (a + b)) ){
    ErrInvalid = true;
  }
}

void TriangleType(float a, float b, float c, char & Type, bool & RightTriangle){
  // Determine Triangle Type
  if( ((a * a) + (b * b) == (c * c)) || ((b * b) + (c * c) == (a * a)) || ((c * c) + (a * a) == (b * b)) ){
    RightTriangle = true; // Right Triangle
  }
  if( a == b && a == c && b == c){
    Type = 'E'; // Equilateral Triangle
  }
  else if( (a != b) && (a != c) && (b !=c) ){
    Type = 'S'; // Scalene Triangle
  }
  else{
    Type = 'I'; // Isosceles Triangle
  }
}

void Print(float a, float b, float c, char Type, bool RightTriangle, bool ErrInvalid, bool & Repeat){
  // Local Variable Declaration
  char Ans;
  // User Output to console
  cout << "First length:  " << setw(W) << a << endl;
  cout << "Second length: " << setw(W) << b << endl;
  cout << "Third length:  " << setw(W) << c << endl << endl;

  // Print invalid triangle if invalid
  if(ErrInvalid){
    cout << "These side lengths can't form a valid triangle\n\n";
  }
  else if(Type == 'S'){
    cout << "This is a Scalene ";
    if(RightTriangle){
      cout << "Right ";
    }
  }
  else if(Type == 'I'){
    cout << "This is an Isosceles ";
    if(RightTriangle){
      cout << "Right \n\n";
    }
  }
  else if(Type == 'E'){
    cout << "This is an Equilateral ";
  }
  cout << "Triangle \n\n";
  // Determine if the user wants to run the program again
  cout << "Would you like to run the program again?\n";
  cout << "Enter 'Y' for yes, or 'N' for no\n";
  cin >> Ans;
  Ans = toupper(Ans);
  while(Ans != 'Y' && Ans != 'N'){
    cout << "ERROR Invalid Entry\n";
    cout << "Enter 'Y' for yes, or 'N' for no\n";
    cin >> Ans;
    Ans = toupper(Ans);
  }
  if(Ans == 'Y'){
    Repeat = true;
  }
  else{
    Repeat = false;
  }
  cout << endl;
}

void RNG(){//prints random emoji
  srand(time(NULL));
  int random = (rand() % 6) + 1;
  
  switch(random){
    case 1:
      cout << ";-;";
      break;
    case 2:
      cout << "*~*";
      break;
    case 3:
      cout << "D:";
      break;
    case 4:
      cout << "T.T";
      break;
    case 5:
      cout << ">.<";
      break;
    default:
      cout << ":(";
  }
  cout << endl;
  
}