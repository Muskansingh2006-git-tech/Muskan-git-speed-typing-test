#include <iostream>
#include <vector>
#include <cstdlib>
#include<string>
#include<chrono>
using namespace std;

int main() {
string a=("\n**********************************\n");
string b=("Welcome to speed typing test...");
string c=("\n**********************************\n");
cout<<a<<b<<c<<endl;
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
for(auto i=0; i<original.size() && i<typed.size(); i++) {
    if(original[i]==typed[i]) {
      correct++;
        cout<<" ";
   } else {
        cout<<"^";
    

}
}

cout<<endl;
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
return 0;
}
