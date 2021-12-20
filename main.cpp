#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <chrono>
#include <cmath>
#include <fstream>
using namespace std;
using namespace std::chrono;

bool lwr=false, upr=false, spcl=false, nums=false, exprt=false;
int length;
string characters="";
ofstream f;
char lower_case_letters[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char upper_case_letters[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char special_characters[]={'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '-', '*', '/', '\\',
'[', ']', '{', '}', '|', '?'};
char numbers[]={'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
int random_nums[]={86, 46, 94, 48, 42, 2, 19, 82, 92, 81, 12, 13, 41, 18, 47, 70, 98, 26, 56, 39, 80, 49, 15, 35, 85, 55, 74, 58, 31, 66};

void GeneratePassword_console(){
    for (int i=0;i<length;i++){
        cout<<characters[rand()%characters.length()];
    }
}
void GeneratePassword_file(){
    for (int i=0;i<length;i++){
        f<<characters[rand()%characters.length()];
    }
}

int main()
{
    char c;int n;
    while (true){
    cout<<"==========What to include==========\n";
    cout<<"Password length? - ";cin>>length;
    cout<<"Lower case letters?(Y/N) - ";cin>>c; (c=='Y' || c=='y') ? lwr=true : lwr=false;
    if (lwr) characters+=lower_case_letters;
    cout<<"Upper case letters?(Y/N) - ";cin>>c; (c=='Y' || c=='y') ? upr=true : upr=false;
    if (upr) characters+=upper_case_letters;
    cout<<"Numbers?(Y/N) - ";cin>>c; (c=='Y' || c=='y') ? nums=true : nums=false;
    if (nums) characters+=numbers;
    cout<<"Special character?(Y/N) - ";cin>>c; (c=='Y' || c=='y') ? spcl=true : spcl=false;
    if (spcl) characters+=special_characters;
    cout<<"Export to file?(Y/N) - ";cin>>c; (c=='Y' || c=='y') ? exprt=true : exprt=false;
    cout<<"Number of generations? - ";cin>>n;
    auto temp=high_resolution_clock::now();
    if (exprt){
        f.open("passwords.txt");
        for (int i=0;i<n;i++){
            auto duration=duration_cast<nanoseconds>(temp-high_resolution_clock::now())/1000;
            int aux=abs(duration.count());
            srand(aux);Sleep(1);
            GeneratePassword_file();
            f<<'\n';
        }
        f.close();
        system("pause");
    }else{
        cout<<"===================================\n";
        for (int i=0;i<n;i++){
            auto duration=duration_cast<nanoseconds>(temp-high_resolution_clock::now())/1000;
            int aux=abs(duration.count());
            srand(aux);Sleep(1);
            GeneratePassword_console();
            cout<<'\n';
        }
        cout<<"===================================";
        system("pause>0");
    }
    system("cls");
    characters="";
    }
}