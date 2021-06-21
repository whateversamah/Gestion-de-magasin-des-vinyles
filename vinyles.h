#include <iomanip>
#include <conio.h>
#include <windows.h>
#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdio.h>
#ifndef VINYLES_H
#define VINYLES_H
using namespace std;

void welcome();
void ccolor(int clr);

class fichier{
public:
    fichier(){
        ofstream fout;
        fout.open("ensem.txt");
        fout<<"ensem";
        fout.close();
    }
};
class gain{
        public:
        double profit;
        void show()
		{
		ifstream x("ooo.txt");
        if(!x)
        cout<<"PROFIT = 0 ";
        else{
        x>>profit;
        cout<<"\nTOTAL DES PROFITS:  "<<profit<<endl;
        x.close();
        }

        }

};

#endif
