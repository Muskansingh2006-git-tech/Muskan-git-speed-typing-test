#include <iostream>
#include <vector>
#include <cstdlib>
#include<string>
#include<chrono>
using namespace std;
void showMenu();
void startTest();
void showInstructions();

int main() {

 showMenu();
return 0;
}
void showMenu(){
    while(true){
    int choice;
 cout << "1. Start Test\n";
    cout << "2. Instructions\n";
    cout << "3. Exit\n";
    cout << "\nEnter your choice: ";

    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        startTest();
        break;
    case 2:
        showInstructions();
        break;

    case 3:
        cout << "Thank you for playing!\n";
        return;

    default:
        cout << "Invalid Choice!\n";
    
    }
}
}   
void startTest()

{
    cout << "\nStarting Test...\n";
    
vector <string> para={ "The quick brown fox jumps over the lazy dog.",
    "Practice makes a person better every day.",
    "Programming is fun when you understand the basics.",
    "Never stop learning new things.",
    "Typing speed improves with regular practice."};
srand(time(0));              
int index = rand() % para.size();

string typed;
int correct=0;
cout<<"\n"<<"This type line exactly as shown"<<"\n\n";
cout<< para[index];
string original=para[index];
cout<<"please enter the press botton to start...";
cin.get();

// calculate time
auto start = chrono::high_resolution_clock::now();
getline(cin,typed);
auto end = chrono::high_resolution_clock::now();

double time_taken =
chrono::duration<double>(end-start).count();

//accuracy
cout<<"\noriginal:\n"<<original<<endl;
int mistake=0;
for(auto i=0; i<original.size() && i<typed.size(); i++) {
    if(original[i]==typed[i]) {
      correct++;
        cout<<" ";
   } else {
        cout<<"^"<<endl;
        mistake++;
}
}
mistake+= abs((int)original.size() - (int)typed.size());

double accuracy=( (double) correct / original.size() * 100);

// Word per minute
int word=1;
for(auto ch:typed) {
    if(ch == ' ') word++;

}

double wpm=(double (word) /int (time_taken))*60;
cout<<endl;
cout<<"time taken"<<time_taken<<"sec"<<endl;
cout<<"accuracy"<<accuracy<<"%"<<endl;
cout<<"wpm"<<int (wpm)<<endl;
}
void showInstructions(){
cout << "\nInstructions\n";
    cout << "1. Type exactly as shown.\n";
    cout << "2. Press Enter when finished.\n";
    cout << "3. Your WPM and Accuracy will be calculated.\n";
}

