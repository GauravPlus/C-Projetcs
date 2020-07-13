#include <iostream>
#include <string>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>
#include<fstream>
#include <dir.h>
#include <bits/stdc++.h>
using namespace std;


void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;


 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

vector<string> split(string str, char ch){
    vector<string> v;

    stringstream ss(str);

    while (ss.good()) {
        string sub;
        getline(ss, sub, ch);
        v.push_back(sub);
    }
    return v;
}

vector<string> readFileQuestions(string filepath){
    ifstream file;
    file.open(filepath,ios::in);
    vector<string> s;
    if (file.is_open()){

        string a;
        while(getline(file,a)){
            s.push_back(a);
        }
        file.close();
    }
    return s;
}


void showScore(int x){
    SetColor(10);
    cout<<"\n\n\tYour final score is "<<x;
    SetColor(11);
    if(x==100)
        cout<<"\n\tNo cheating...... You have done this earlier also.\n";

	else if(x==90)
        cout<<"\n\tYou are extremely intelligent.\n";

	else if(x==80)
        cout<<"\n\tYou are intelligent.\n";

	else if(x==50||x==70||x==60)
        cout<<"\n\tYou are average."<<" Better luck next time\n";

	else if(x<=40)
        cout<<"\n\tNo use..... Not even 5 questions right\n";

    SetColor(15);
    cout<<"\n\tPress any key to exit...\n\n";
    getch();
    //Program ends here
}

void toQuestions(string file, string quiz){
    system("CLS");

    vector<string> Questions = readFileQuestions(file);
    int score = 0;
    for(int i = 0; i < Questions.size(); ++i){
        system("CLS");
        SetColor(11);
        cout<<"\n\t\t\t"<<quiz<<" Quiz";
        SetColor(15);
        vector<string> ques = split(Questions[i],'@');
        char ch;
        cout<<"\n\n\t"<<i+1<<". "<<ques[0]<<endl;
        cout<<"\n\ta. "<<ques[1]<<endl;
        cout<<"\n\tb. "<<ques[2]<<endl;
        cout<<"\n\tc. "<<ques[3]<<endl;

        cout<<"\n\tEnter your answer (a/b/c) : ";
        cin>>ch;

        if(ch  == char(ques[4][0])){
            score+=10;
        }
    }
    showScore(score);

}


void welcomeToQuiz(){
    string quiz1 =  "1. Programming";
    string quiz2 =  "2. Cities";
    string quiz3 =  "3. Sports";
    string quiz4 =  "4. Aptitude";

    SetColor(11);
    cout<<"\n\n\n\t\t\t\t\tWelcome to Quiz Game\n\n\n";

    string name;
    SetColor(15);
    cout<<"\tEnter your Name:  ";
    cin>>name;
    cout<<"\n\tHi, "<<name<<"!";

    SetColor(11);
    cout<<"\n\n\tChoose Your Quiz:\n\n";

    SetColor(15);
    cout<<"\t"<<quiz1<<endl;
    cout<<"\t"<<quiz2<<endl;
    cout<<"\t"<<quiz3<<endl;
    cout<<"\t"<<quiz4<<endl;
    

    int c;


    string ch;
    string filename;

    do{
        cout<<"\n\tEnter your choice (Quiz number): ";
        cin>>c;
        switch(c){
            case 1:
                ch = quiz1;
                filename = "prog.txt";
                break;
            case 2:
                ch = quiz2;
                filename = "gk.txt";
                break;
            case 3:
                ch = quiz3;
                filename = "sports.txt";
                break;
            case 4:
                ch = quiz4;
                filename = "aptitude.txt";
                break;
           
            default:
                SetColor(4);
                cout<<"\n\tYou have entered an invalid choice.\n\n";
                SetColor(15);
        }
    }while(!(c>0 && c<=5));

    SetColor(10);
    cout<<"\n\tYou have chosen "<<ch.substr(3)<<".\n";
    SetColor(15);a
    cout<<"\n\tPress any key to proceed...\n";
    getch();

    toQuestions(filename, ch.substr(3));
}



int main()
{
    welcomeToQuiz();
    getch();
    return 0;
}
