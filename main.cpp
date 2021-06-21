#include <iomanip>
#include <conio.h>
#include <windows.h>
#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdio.h>

using namespace std;
#include"vinyles.h"


void welcome();
void ccolor(int clr);


class product:public virtual gain{
public:
           int quan;
           char name[20];
           char id[20];
           double percost;
           double persell;
           double cost;
           double sell;
           void cal()
		   {
		    cost=percost*quan;
        	sell=persell*quan;
            profit=profit +(sell-cost)*365;
			}
           void fichier();
           void get();

};
void product::get()
{
 int s;
cout<<"\nNombre des vinyles produits?\n";
cin>>s;
for(int i=0;i<s;i++)
{
  cout<<"\n Nom d'album: \n";
  cin>>name;
  cout<<"\n ID du vinyle : \n";
  cin>>id;
  cout<<"\n Prix de production: \n";
  cin>>percost;
  cout<<"\n Prix de vente: \n";
  cin>>persell;
  cout<<"\n Quantite du produit: \n";
  cin>>quan;
    cal();
    fichier();
  }

}
void product::fichier()
{
char fichier[20];
strcpy(fichier,id);
strcat(fichier,".txt");
ofstream f(fichier);
f<< "\nNom d'album: "<<name<< "\nID du vinyle : "<<id<<"\nPrix de production: " <<percost<<"\nPrix de vente: "<<persell<<"\nQuantite: "<<quan<<"\nPrix total: "<<cost<<"\nVente: "<<sell;
f.close();
}

class staff:public virtual gain{
         protected:
         double salary;
         char post[12];
         char empid[10];
         int postquan;
         void cal()
         {
		 profit=(profit-salary*postquan)*12;
         }
         void getstaff();
         void fichier();
};
void staff::getstaff()
{
  cout<<"\nEntrer le salaire: \n";
  cin>>salary;
  cout<<"\nEntrer le nombre d employees \n";
  cin>>postquan;
  for(int i=0;i<postquan;i++)
  {
  	cout<<"Entrer le nom d employee\n";
  	cin>>post;
  cout<<"\nEntrer ID d employee\n";
  cin>>empid;
  cal();
  fichier();
}
}
 void staff::fichier()
{  char fichier[20];
strcpy(fichier,empid);
strcat(fichier,".txt");
ofstream f(fichier);
f<< "\nnombre employees: "<<postquan<< "\nsalaire d employee : "<<salary<< "\nnom d employee :"<<post<<"\nID d employee: "<<empid;
f.close();
}

class amount:public staff, public product
{

 public:
    void add();
    void update_item();
    void update_emp();

};
void amount::add()
{
	int ch;
	char name[20];
	while(1)
	{
		cout<<"1.)Espace Vinyles\n2.)Espace Employees\n3.)Quitter\n";
		cout<<"Entrez votre choix\n";
		cin>>ch;
		if(ch==1){
				get();
				ofstream x("ooo.txt");
 				x<<profit;
 				x.close();
			}
			else if(ch==2){
				getstaff();
				ofstream x("ooo.txt");
 				x<<profit;
 				x.close();
				}
			else if(ch==3)
				break;
			else
				cout<<"Option invalide. Reessayer !!\n";
			}
		}


	void amount::update_item()
	{
	char id[20];
	char pid[20];
    char c;
    cout<<"\nID du produit a modifier\n";
    cin>>id;
    char fichier[20];
    char fichier2[20];
    strcpy(fichier,id);
    strcat(fichier,".txt");
    fstream fout(fichier, ios::in|ios::out);
    if(!fout)
    {
    	cout<<" ID introuvable . \n";
	}
	else {
	cout<<"fichier trouve! \n";
    cout<<"\n nom du vinyle mis a jour: \n";
  	cin>>name;
 	cout<<"\nprix de production mis a jour : \n";
  	cin>>percost;
 	cout<<"\nprix de vente mis a jour: \n";
  	cin>>persell;
 	cout<<"\nquantite des vinyles mis a jour: \n";
 	cin>>quan;
    cost=percost*quan;
    sell=persell*quan;
	profit=profit +(sell-cost)*365;
  	fout<<"\nnom du vinyle: "<<name<< "\nID du vinyle: "<<id<<"\nprix de production: " <<percost<<"\nprix de vente: "<<persell<<"\nquantite: "<<quan<<"\nprix total: "<<cost<<"\nvente: "<<sell;
	fout.close();
}
}
   void amount::update_emp()
	{
	char id[20];
    char c;
    cout<<"\nID d employee a modifie : ";
    cin>>id;
    char fichier[20];
    strcpy(fichier,id);
    strcat(fichier,".txt");
    fstream fout(fichier, ios::in|ios::out);
     if(!fout)
    {
    	cout<<" ID du vinyle est introuvable . \n";
	}
	cout<<"modifiez le nom d employee : \n";
  	cin>>post;
  	fout<< "\nnombre employees: "<<postquan<< "\nsalaire d employee : "<<salary<< "\nnom d employee :"<<post<<"\nID d employee: "<<empid;
 	fout.close();
}

void admin()
{
  while(1)
  {
 	cout<<"\n\t\t\t==============================\n";
	cout<<"\n\t\t\t     BIENVENUE   \n";
	cout<<"\n\t\t\t==============================\n\n";
	cout<<"\n\t\t\t* * * * * * * * * * * * * * * *\n";
 	cout<<"\n\t\t\t1. AJOUTER DES DETAILS\n\n\t\t\t2. AFFICHER LES GAINS\n\n\t\t\t3. AFFICHER LES INFOS SUR DES VINYLES\n\n\t\t\t4. AFFICHER LES INFOS D EMPLOYEE\n\n\t\t\t5. MODIFIER LES DETAILS DES VINYLES\n\n\t\t\t6. MODIFIER LES INFO D EMPLOYEE\n\n\t\t\t7. QUITTER\n";
  cout<<"\n\n\t\t\tEntrez votre choix !\n";
  int u;
  cin>>u;
if(u==1)
  {
  amount a;
  a.show();
  a.add();
}
  else if(u==2)
  {
  amount d;
  d.show();
}
  else if(u==3)
  {
   char id[20];
   char c;
    cout<<"\nID a chercher \n";
    cin>>id;
    char fichier[20];
    strcpy(fichier,id);
    strcat(fichier,".txt");
    ifstream x(fichier);
    if(!x)
    {
    	cout<<" ID introuvable . \n";
	}
    while(x)
    {x.get(c);
     cout<<c;
    }


    x.close();
}
   else if(u==4)
   {
   	char eid[20];
   	char d;
   	cout<<"\nID d employee a cherche\n";
    cin>>eid;
   	char fichier[20];
   	strcpy(fichier,eid);
   	strcat(fichier,".txt");
   	ifstream y(fichier);
   	 if(!y)
    {
    	cout<<" ID introuvable . \n";
	}
   	while(y)
   	{
   	y.get(d);
   	cout<<d;
   }

   y.close();
}
else if(u==5)
{
	amount u;
	u.update_item();
}
 else if(u==6)
 {
 	amount v;
 	v.update_emp();
 }
  else if(u==7)
  {
  break;
}
  else cout<<"Option invalide. Choisissez une option valide\n";
 }

}

int main(){

    int ch;
    welcome();
    char  username[20];
    char password[20];
    char pwd[20];
    while(1){
        cout<<"\n \t\t\t ";
        cout<<"\n \t\t\t";
        cout<<"\n \t\t\t";
        cout<<"\n \t\t\t* * * * * * * * * * * * ";
        cout<<"\n\t\t\t  1. ACCEDER AU SYSTEME";
        cout<<"\n\t\t\t  2. QUITTER";
        cout<<"\n\t\t\t* * * * * * * * * * * *\n";
        cout<<"\n\t\t\t Entrer Votre Choix: ";
        cin>>ch;
        switch(ch){
            case 1:
                admin();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<<"Entrer un choix valide\n";
                break;
        }
    }
    return 0;
}


void ccolor(int clr){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, clr);

//the above code displays colorful background. if you want colorful then you can remove the above comment but not the code, only comment//
}
void welcome()
{
	ccolor(26);

	char welcome[50]="BIENVENUE";
	char welcome2[50]=" SUR";
	char welcome3[50]=" LE SYSTEME DE GESTION DU ";
	char welcome4[50]=" MAGASIN DES VINYLES ";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		printf(" %c",welcome[wlc]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		printf(" %c",welcome2[wlc2]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			printf(" %c",welcome3[wlc3]);
		}
		else{

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			printf(" %c",welcome4[wlc3]);
		}
		else{

			printf(" %c",welcome4[wlc3]);
		}
		Sleep(100);
	}
	ccolor(26);

}
