#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include"decor.h"
#include"personage.h"
#include<Windows.h>

using namespace std;
int random(int );
void affichage_decor(int n,int deb);
void affichage_entete(personnage &ennemi,personnage &perso);
void affichage_des_perso (personnage &ennemi,personnage &perso,int mode);
void affichage_combat(personnage &ennemi,personnage &perso);
void affichage_ennemie_attaque(personnage &ennemi,personnage &perso);
void affichage_perso_attaque(personnage &ennemi,personnage &perso);


const int M =190;
ElementDecor *pt[M];

int main()
{
	system("mode con: cols=128 lines=128");
	int i,type,j,debut;
	int N=10;
	bool role=1;

	personnage mimu;
	personnage monstre;
	char c;


	debut =0;
	for(i=0;i<M;i++)
	{
		type = random(5);
		if(type==0)
		{
			pt[i] = new Arbre;
		}
		else if(type==1)
		{
			pt[i] = new Maison;
		}
		else if(type==2)
		{
			pt[i] = new Escargot;
		}
		if(type==3)
		{
			pt[i] = new Moulin;
		}
		if(type==4)

		{
			pt[i] = new Batiment;
		}
	}
	while(1)
	{
		system("cls");
		affichage_entete(monstre, mimu);

		affichage_decor(N, debut);
		
		cout<<endl;
		
		// affichage des personnage 
		affichage_combat(monstre, mimu);
		
		c = getch();
		if ( c =='d' && debut+N<M)
		{
			debut++;
		}
		else if( c=='q' && debut>0)
		{
			debut--;
		}
		
		if ( c =='t')
		{
			if(role == 1)
			{
				mimu.donner_coup(monstre);
				role = 0;

				system("cls");
				affichage_entete(monstre, mimu);

				affichage_decor(N, debut);
		
				cout<<endl;
		
				affichage_perso_attaque(monstre, mimu);
				Sleep(400) ;
			}
			else
			{
				monstre.donner_coup(mimu);
				role = 1;
				
				system("cls");
				affichage_entete(monstre, mimu);

				affichage_decor(N, debut);
		
				cout<<endl;
		
				// affichage des personnage 
				affichage_ennemie_attaque(monstre, mimu);
				Sleep(400) ;
		
			}
		}
		else if( c=='s' )
		{
			if(role == 1)
			{
				mimu.soin();
				role = 0;
			}
			else
			{
				monstre.soin();
				role = 1;
			}
		}
	}

	for (i=0;i<M;i++)
	{
		delete pt[i];
	}
return(0);
}

int random(int a)
{
	int Indice;
	Indice = rand()%a;
	
	return Indice;

}


void affichage_decor(int n,int deb)
{
	int j,i;
	
	for(j=0;j<7;j++)
	{
		for (i=deb;i<deb+n;i++)	
		{
			pt[i]->affiche(j+1);
		}
		cout<<endl;
	}

}


void affichage_entete(personnage &ennemi,personnage &perso)
{
	int i;
		cout<<"PV \t";
		cout<<perso.get_PV();
		cout<<"/";
		cout<<perso.get_PVmax();
		for(i=0;i<10;i++)
		{
			cout<<"\t";		
		}
		cout<<"PV \t";
		cout<<ennemi.get_PV();
		cout<<"/";
		cout<<perso.get_PVmax();
		cout<<endl;

		cout<<"Force \t";
		cout<<perso.get_Force();
		for(i=0;i<10;i++)
		{
			cout<<"\t";		
		}
		cout<<"Force \t";
		cout<<ennemi.get_Force();
		cout<<endl;

		cout<<"Vita \t";
		cout<<perso.get_VIT();
		for(i=0;i<10;i++)
		{
			cout<<"\t";		
		}
		cout<<"Vita \t";
		cout<<ennemi.get_VIT();
		cout<<endl;

		cout<<"Potion \t";
		cout<<perso.get_nb_potion();
		for(i=0;i<10;i++)
		{
			cout<<"\t";		
		}
		cout<<"Potion \t";
		cout<<ennemi.get_nb_potion();
		cout<<endl;
		cout<<"===========================================================================================================";
		cout<<endl;

}

void affichage_combat(personnage &ennemi,personnage &perso)
{
	affichage_des_perso (ennemi,perso,0);
}

void affichage_ennemie_attaque(personnage &ennemi,personnage &perso)
{
	affichage_des_perso (ennemi,perso,1);
}

void affichage_perso_attaque(personnage &ennemi,personnage &perso)
{
	affichage_des_perso (ennemi,perso,2);
}

void affichage_des_perso (personnage &ennemi,personnage &perso,int mode)
{
	int i,j,m1,m2;

	// mode attack ennemi
	if(mode == 1)
	{
		m1 = 0;
		m2 = 5;
	}

	//mode combat
	else if ( mode == 0)
	{
		m1 = 0;
		m2 = 10;
	}

	// mode attack perso
	else if ( mode == 2)
	{
		m1 = 5;
		m2 = 5;
	}

	for(j=0;j<9;j++)
	{
		for(i=0;i<m1;i++)
		{
			cout<<"\t";		
		}
		perso.affiche(j+1);
		for(i=0;i<m2;i++)
		{
			cout<<"\t";		
		}
		ennemi.affiche(j+1);
		cout<<endl;
	}
}