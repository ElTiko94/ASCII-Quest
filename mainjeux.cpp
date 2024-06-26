#include<conio.h>
#include"decor.h"
#include"personage.h"
#include<Windows.h>

int random(int );
void affichage_decor(int n,int deb);
void affichage_entete(personnage &ennemi,personnage &perso);
void affichage_des_perso (personnage &ennemi,personnage &perso,int mode);
void affichage_combat(personnage &ennemi,personnage &perso);
void affichage_ennemie_attaque(personnage &ennemi,personnage &perso);
void affichage_perso_attaque(personnage &ennemi,personnage &perso);
void affichage_promo(personnage &perso, int n, int deb);
void affichage_commande();
void affich_fight();
void affich_win();
void affich_tete_de_mort();

const int M =290;
ElementDecor *pt[M];

int main()
{
	system("mode con: cols=128 lines=128");
	int i,type,j,debut;
	int N=10;

	guerrier mimu;
	personnage* monstre;
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

	int perdu =0;

	while(perdu  == 0)
	{
		system("cls");


		affichage_promo(mimu, N, debut);

		bool avance = 0;
		do
		{
			c = _getch();
			if (c == 'd' && debut + N<M)
			{
				debut++;
				avance = 1;
			}
			else if (c == 'q' && debut>0)
			{
				debut--;
				avance = 1;
			}
		}while(avance == 0);
		
		if (random(14) == 1)
		{
			int win = 0;
			char nom[100];
			Serpent enm1(30+debut,10+debut/4,0,15+debut/2 , 0, nom);
			personnage enm2(50+debut,25+debut/3,0,25+debut/3 , 2, nom);
			Robot enm3(55+debut,22+debut/3,0,25+debut/4 , 0, nom);
			
			int A = random(6);
			switch(A)
			{
				case 0 :
					monstre = &enm1;
					
					break;
				case 1 :
					monstre = &enm2;
					break;
				case 2:
					monstre = &enm1;
					break;
				case 3:
					monstre = &enm2;
					
					break;
				case 4:
					monstre = &enm1;
					
					break;
				case 5:
					monstre = &enm3;
					
					break;
			}
			affich_fight();
			bool fuite = 0;
			while (win == 0 && perdu == 0 && fuite == 0)
			{
				system("cls");
				affichage_entete(*monstre, mimu);

				affichage_decor(N, debut);

				cout << endl;

				// affichage des personnage 
				affichage_combat(*monstre, mimu);
				c = 'g';
				bool soin = 0;
				
				do
				{
					c = _getch();
					if (c == 't')
					{
						mimu.donner_coup(*monstre);
	
	
						system("cls");
						affichage_entete(*monstre, mimu);
	
						affichage_decor(N, debut);
	
						cout << endl;
	
						affichage_perso_attaque(*monstre, mimu);
						Sleep(400);
	
					}
	
					else if ( c == 's' && mimu.get_nb_potion() > 0 )
					{
						mimu.soin();
						soin = 1;
					}
					else if ( c == 'f')
					{
						if(mimu.fuite(*monstre) == 1)
						{
							fuite = 1;
						}
					}
				}while(soin == 0  && c!='t' && c!= 'f');
				
				if (monstre->get_PV() <= 0 )
				{
					mimu.win(*monstre, debut);
					win = 1;
					affich_win();
				}
				else if(fuite == 1)
				{
					
				}
				else
				{
					system("cls");
					affichage_entete(*monstre, mimu);

					affichage_decor(N, debut);

					cout << endl;

					// affichage des personnage 
					affichage_combat(*monstre, mimu);
					Sleep(100);
								
				monstre->donner_coup(mimu);

				system("cls");
				affichage_entete(*monstre, mimu);

				affichage_decor(N, debut);

				cout << endl;

				// affichage des personnage 
				affichage_ennemie_attaque(*monstre, mimu);
				Sleep(400);
				}

				if (mimu.get_PV() <= 0)
				{
					perdu = 1;
					
					system("cls");
					affichage_entete(*monstre, mimu);
				
					affichage_decor(N, debut);
				
				
					// affichage des personnage
					for(int a=0;a<10;a++)
					{
						mimu.affiche_Mort(a);
						cout<<endl;
					}
					Sleep(400);
					affich_tete_de_mort();
					
				}

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
		int largeur = 0;
		for (i=deb;(largeur<109 && i<M);i++)	
		{
			largeur = largeur+pt[i]->get_largeur();	
			pt[i]->affiche(j+1);
		}
		cout<<endl;
	}

}


void affichage_entete(personnage &ennemi,personnage &perso)
{
	int i;
	
		cout<<"Niveau \t";
		cout<<perso.get_Niv();
		//cout<<"/";
		//cout<<perso.get_PVmax();
		cout<<endl;
		
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
		cout<<ennemi.get_PVmax();
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

		cout<<"Vitesse\t";
		cout<<perso.get_VIT();
		for(i=0;i<10;i++)
		{
			cout<<"\t";		
		}
		cout<<"Vitesse\t";
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
		
		cout<<"EXP \t";
		cout<<perso.get_EXP();
		cout<<"/";
		cout<<perso.get_Niv()*perso.get_Niv()*9+1;
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
// affichage en mode promenade
void affichage_promo(personnage &perso, int n, int deb)
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	int j;

	affichage_decor(n,deb);
	cout << endl;

	for (j = 0; j<9; j++)
	{
		perso.affiche(j + 1);
		cout << endl;
	}
	
	affichage_commande();
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
		ennemi.affiche_ennemi(j + 1);
		cout<<endl;
	}
}

void affichage_commande()
{
		cout<<endl;
		cout<<"<-q";
		for(int i=0;i<12;i++)
		{
			cout<<"\t";		
		}
		cout<<"d->";
		cout<<endl;
}

void affich_fight()
{
	for(int i = 0;i<5;i++)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"\t\t\t\t _____   _   _____   _   _   _____ "<<endl;
		cout<<"\t\t\t\t|  ___| | | /  ___| | | | | |_   _|"<<endl;
		cout<<"\t\t\t\t| |__   | | | |     | |_| |   | |  "<<endl;
		cout<<"\t\t\t\t|  __|  | | | |  _  |  _  |   | |  "<<endl;
		cout<<"\t\t\t\t| |     | | | |_| | | | | |   | |  "<<endl;
		cout<<"\t\t\t\t|_|     |_| \\_____/ |_| |_|   |_|  "<<endl;
		Sleep(100);
		system("cls");
		Sleep(100);
	}
}

void affich_win()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t__    __  _____   _   _        _          __  _   __   _  "<<endl;
	cout<<"\t\t\t\t\\ \\  / / /  _  \\ | | | |      | |        / / | | |  \\ | | "<<endl;
	cout<<"\t\t\t\t \\ \\/ /  | | | | | | | |      | |  __   / /  | | |   \\| | "<<endl;
	cout<<"\t\t\t\t  \\  /   | | | | | | | |      | | /  | / /   | | | |\\   | "<<endl;
	cout<<"\t\t\t\t  / /    | |_| | | |_| |      | |/   |/ /    | | | | \\  | "<<endl;
	cout<<"\t\t\t\t /_/     \\_____/ \\_____/      |___/|___/     |_| |_|  \_| "<<endl;
	Sleep(400);
}

void affich_tete_de_mort()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t            ZZZZZZZZZZZZZZZZZZZZZ"<<endl;
	cout<<"\t\t\t\t          ZZZZZ              ZZZZZZ"<<endl;
	cout<<"\t\t\t\t        ZZZZZ                    ZZZZ"<<endl;
	cout<<"\t\t\t\t      ZZZZZ                       ZZZZZ"<<endl;
	cout<<"\t\t\t\t    ZZZZZ                           ZZZZ"<<endl;
	cout<<"\t\t\t\t   ZZZZ                              ZZZZ"<<endl;
	cout<<"\t\t\t\t  ZZZ                                  ZZZ"<<endl;
	cout<<"\t\t\t\t ZZZ                                    ZZZ"<<endl;
	cout<<"\t\t\t\tZZZZ                                    ZZZ"<<endl;
	cout<<"\t\t\t\tZZZ                                     ZZZ"<<endl;
	cout<<"\t\t\t\tZZZ                                     ZZZ"<<endl;
	cout<<"\t\t\t\tZZZ                                     ZZZ"<<endl;
	cout<<"\t\t\t\tZZZ                             ZZ      ZZZ"<<endl;
	cout<<"\t\t\t\tZZZ                           ZZZZZ     ZZZ"<<endl;
	cout<<"\t\t\t\tZZZ                        ZZZZZZZZZ  ZZZZZ"<<endl;
	cout<<"\t\t\t\tZZZZ    ZZZ              ZZZZZZZZZZZZ ZZZZ"<<endl;
	cout<<"\t\t\t\tZZZZ   ZZZZZZ           ZZZZZZZZZZZZZ ZZZ"<<endl;
	cout<<"\t\t\t\tZZZZ  ZZZZZZZZZZ       ZZZZZZZZZZZZZ  ZZ"<<endl;
	cout<<"\t\t\t\tZZZZ  ZZZZZZZZZZZ      ZZZZZZZZZZZZ   ZZ"<<endl;
	cout<<"\t\t\t\t ZZZ   ZZZZZZZZZZZ      ZZZZZZZZZZ    ZZ"<<endl;
	cout<<"\t\t\t\t ZZZ    ZZZZZZZZZ ZZZZZ   ZZZZZZ    ZZZZ"<<endl;
	cout<<"\t\t\t\t  ZZZ    ZZZZZZZ  ZZZZZZ           ZZZZ"<<endl;
	cout<<"\t\t\t\t   ZZZZZ          Z  ZZZ     ZZZZZZZZZ"<<endl;
	cout<<"\t\t\t\t    ZZZZZZZZ          ZZ    ZZZZZZZZ"<<endl;
	cout<<"\t\t\t\t     ZZZZZZZZ             ZZZZZ"<<endl;
	cout<<"\t\t\t\t          ZZZ  Z   Z   Z  ZZZ"<<endl;
	cout<<"\t\t\t\t          ZZZ ZZZ ZZZ ZZZ ZZZ"<<endl;
	cout<<"\t\t\t\t          ZZZ ZZZ ZZZ ZZZ ZZZ"<<endl;
	cout<<"\t\t\t\t          ZZZ ZZZ ZZZ ZZZ ZZZ"<<endl;
	cout<<"\t\t\t\t           ZZZZZZZZZZZZZZZZZ"<<endl;
	cout<<"\t\t\t\t              ZZZZZZZZZZZ"<<endl;
	Sleep(400);
}
