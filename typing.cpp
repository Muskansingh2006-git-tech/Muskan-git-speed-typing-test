#include <iostream>
#include<string>
#include<ctime>
using namespace std;

int main() {
string a=("\n**********************************\n");
string b=("Welcome to speed typing test...");
string c=("\n**********************************\n");
cout<<a<<b<<c<<endl;
string para=("The red fox brown under the dog you save your time.");
string typed;
int correct=0;
cout<<"\n"<<"This type line exactly as shown"<<"\n\n";
cout<<para<<endl;
cout<<"please enter the press botton to start...";
cin.get();

// calculate time
time_t start=time(NULL);
getline(cin,typed);
time_t end=time(NULL);
double time_taken=difftime(end,start);

//accuracy
cout<<"\noriginal:\n"<<para<<endl;
for(auto i=0; i<para.size() && i<typed.size(); i++) {
    if(para[i]==typed[i]) {
      correct++;
        cout<<" ";
   } else {
        cout<<"^";
    

}
}
cout<<endl;
double accuracy=( (double) correct / para.size() * 100);

// Word per minute
int word=1;
for(auto ch:typed) {
    if(ch == ' ') word++;

}
double wpm=((double) word / time_taken)*60;
cout<<endl;
cout<<"time taken"<<(int) time_taken<<"sec"<<endl;
cout<<"accuracy"<<accuracy<<endl;
cout<<"wpm"<<wpm<<endl;
return 0;
}
