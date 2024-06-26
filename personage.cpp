#include"personage.h"


personnage::personnage()
{
	PV = 100;            // repr ́esente les points de vie du personnage
	PVmax = 100;         // repr ́esente les points de vie max du personnage
	Force = 50;         // repr ́esente la force du personnage
	VIT = 50;           // repr ́esente la vitesse du personnage
	nb_potion = 3;     // repr ́esente le nombre de potions du personnage
	
	strcpy(message, "bonjour");
	
	strcpy(nom, "Tiko");
}


personnage::personnage(int nPV, int nForce, int nEXP, int nVIT, int nnb_potion, char * nnom)
{
	PV = nPV;            // repr ́esente les points de vie du personnage
	PVmax = nPV;         // repr ́esente les points de vie max du personnage
	Force = nForce;         // repr ́esente la force du personnage
	VIT = nVIT;           // repr ́esente la vitesse du personnage
	nb_potion = nnb_potion;     // repr ́esente le nombre de potions du personnage

	strcpy(nom, nnom);

	strcpy(message, "bonjour");

}

// ~personnage();  // si n ́ecessaire
//char* personnage::get_message() const
//{
//	return(&message);
//}

//virtual  char*  personnage::get_name() const
//{
//	return(nom);
//}

int personnage::get_EXP() const
{
	
}

int personnage::get_Niv() const
{
	
}

int  personnage::get_PV() const
{
	return(PV);
}

int  personnage::get_PVmax() const
{
	return(PVmax);
}

int  personnage::get_VIT() const
{
	return(VIT);
}

int personnage::get_Force() const
{
	return(Force);
}

int personnage::get_nb_potion() const
{
	return(nb_potion);
}

//virtual void personnage::set_message(char * newmess)
//{
//	int i;
//}


void personnage:: donner_coup(personnage &ennemi)  // calcule en comparant la force d'ennemi des points de deg�ts (par exemple degats = 10*Force/ennemi.Force) qui
// seront retires � PV d'ennemi. On pourra  ́ecrire un message sp�cial dans chaque personnage ("attaque" pour le personnage et "ouille" pour l'ennemi.)
{
	ennemi.PV = ennemi.PV - 10*Force/ennemi.Force;
	if(ennemi.PV<0)
	{
		ennemi.PV = 0;
	}
}
void personnage:: prendre_coup(int valeur)  // PV = PV-valeur
{
	PV = PV-valeur;
}
void personnage::soin()   // remonte les PV du personnage d'un certain pourcentage des PVmax. D�ecr�emente le nombre de potions.
{
	if (nb_potion>0)
	{
		int valsoin;
		valsoin = 15 * PVmax / 100;
		PV = PV + valsoin;
		if (PV > PVmax)
		{
			PV = PVmax;
		}
		nb_potion--;
	}
}
	
bool personnage:: fuite(const personnage &ennemi) //permet de quitter un combat selon une certaine probabilit�e en comparant la VIT de l'ennemi. 
{
	float chance = (float)VIT/ennemi.get_VIT()*50;
	int r = rand()%100;
	if (r<chance)
	{
		return(1);
	} 
	else
	{
		return(0);
	}		
}
void personnage:: win(personnage &ennemi) // Lors de la victoire du personnage, 
	//cette fonction permet de voler les potions de l'ennemi. La force et la vitesse augmentent d'un certain pourcentage.
{
	Force=Force+(ennemi.Force/Force)*Force/100;
	VIT=VIT+ (ennemi.VIT/VIT)*VIT/100;
	nb_potion = nb_potion+ennemi.get_nb_potion(); 
}

void personnage:: affiche(int a) const //affiche l'avatar du personnage, de la meme fa�on que les decors.
{
	if(a==1)
	{cout<<"           .   ";}
	else if(a==2)
	{cout<<"          / \\  ";}
	else if(a==3)
	{cout<<"          |.|  ";}
	else if(a==4)
	{cout<<"     _    |:|  ";}
	else if(a==5)
	{cout<<"   _(_)_`--8--'";}
	else if(a==6)
	{cout<<"  /\\   /\\  8   ";}
	else if(a==7)
	{cout<<" 0  \\_/  \\ O   ";}
	else if(a==8)
	{cout<<"    / \\        ";}
	else if(a==9)
	{cout<<"  _/   \\_      ";}
}

void personnage ::affiche_ennemi(int a)const
{
	if (a == 1)
	{
		cout << "   .           ";
	}
	else if (a == 2)
	{
		cout << "  / \\          ";
	}
	else if (a == 3)
	{
		cout << "  |.|          ";
	}
	else if (a == 4)
	{
		cout << "  |:|    _     ";
	}
	else if (a == 5)
	{
		cout << "`--8--'_(_)_   ";
	}
	else if (a == 6)
	{
		cout << "   8  /\\   /\\  ";
	}
	else if (a == 7)
	{
		cout << "   O /  \\_/  0 ";
	}
	else if (a == 8)
	{
		cout << "        / \\    ";
	}
	else if (a == 9)
	{
		cout << "      _/   \\_  ";
	}
}

void personnage::affiche_Mort(int a) const
{
	if(a==1)
	{cout<<"           .   ";}
	else if(a==2)
	{cout<<"          / \\  ";}
	else if(a==3)
	{cout<<"          |.|  ";}
	else if(a==4)
	{cout<<"          |:|  ";}
	else if(a==5)
	{cout<<"   _ X _`--8--'";}
	else if(a==6)
	{cout<<"  /\\   /\\  8   ";}
	else if(a==7)
	{cout<<" 0  \\_/  \\ O   ";}
	else if(a==8)
	{cout<<"    / \\        ";}
	else if(a==9)
	{cout<<"  _/   \\_      ";}
}

guerrier::guerrier()
{
	PV = 100;            // repr ́esente les points de vie du personnage
	PVmax = 100;         // repr ́esente les points de vie max du personnage
	Force = 50;         // repr ́esente la force du personnage
	VIT = 50;           // repr ́esente la vitesse du personnage
	nb_potion = 3;     // repr ́esente le nombre de potions du personnage
	EXP = 0;
	Niv = 1;
	
	strcpy(message, "bonjour");
	
	strcpy(nom, "Tiko");
}

void guerrier:: win(personnage &ennemi,int N) // Lors de la victoire du personnage, 
	//cette fonction permet de voler les potions de l'ennemi. La force et la vitesse augmentent d'un certain pourcentage.
{
	Force=Force+(ennemi.Force/Force)*Force/100;
	VIT=VIT+ (ennemi.VIT/VIT)*VIT/100;
	nb_potion = nb_potion+ennemi.get_nb_potion();
	EXP = EXP + (ennemi.Force+ennemi.PVmax)*10/(Force+PVmax) + N/4; 
	int tmp = sqrt(EXP-1);
	int Nivsup = tmp/3 + 1;
	if(Nivsup> Niv)
	{
		Niv++;
		PVmax = PVmax + 2*Niv*Niv+1;
		PV = PVmax;
		Force = Force + Niv;
		VIT = VIT + Niv;
	}
}

int guerrier::get_EXP() const // return (EXP)
{
	return (EXP); 
}

int guerrier::get_Niv() const // return (EXP)
{
	return (Niv); 
}

/*

guerrier::guerrier(int nPV, int nForce, int nEXP, int nVIT, int nnb_potion, char * nnom)
{
	PV = nPV;            // repr ́esente les points de vie du personnage
	PVmax = nPV;         // repr ́esente les points de vie max du personnage
	Force = nForce;         // repr ́esente la force du personnage
	VIT = nVIT;           // repr ́esente la vitesse du personnage
	nb_potion = nnb_potion;    // repr ́esente le nombre de potions du personnage
	

	strcpy(nom, nnom);

	strcpy(message, "bonjour");

}
*/


Serpent::Serpent()
{
	PV = 100;            // repr ́esente les points de vie du personnage
	PVmax = 100;         // repr ́esente les points de vie max du personnage
	Force = 50;         // repr ́esente la force du personnage
	VIT = 50;           // repr ́esente la vitesse du personnage
	nb_potion = 3;     // repr ́esente le nombre de potions du personnage
	
	strcpy(message, "bonjour");
	
	strcpy(nom, "Tiko");
}


Serpent::Serpent(int nPV, int nForce, int nEXP, int nVIT, int nnb_potion, char * nnom)
{
	PV = nPV;            // repr ́esente les points de vie du personnage
	PVmax = nPV;         // repr ́esente les points de vie max du personnage
	Force = nForce;         // repr ́esente la force du personnage
	VIT = nVIT;           // repr ́esente la vitesse du personnage
	nb_potion = nnb_potion;     // repr ́esente le nombre de potions du personnage

	strcpy(nom, nnom);

	strcpy(message, "bonjour");

}


void Serpent:: affiche_ennemi(int a) const //affiche l'avatar du personnage, de la meme fa�on que les decors.
{
	if(a==1)
	{cout<<"     ";}
	else if(a==2)
	{cout<<"     ";}
	else if(a==3)
	{cout<<"     ";}
	else if(a==4)
	{cout<<"     ";}
	else if(a==5)
	{cout<<"   _ ";}
	else if(a==6)
	{cout<<" /j \\";}
	else if(a==7)
	{cout<<"  __/";}
	else if(a==8)
	{cout<<" /__/";}
	else if(a==9)
	{cout<<" \\__/";}
}

Robot::Robot()
{
	PV = 100;            // repr ́esente les points de vie du personnage
	PVmax = 100;         // repr ́esente les points de vie max du personnage
	Force = 50;         // repr ́esente la force du personnage
	VIT = 50;           // repr ́esente la vitesse du personnage
	nb_potion = 3;     // repr ́esente le nombre de potions du personnage
	
	strcpy(message, "bonjour");
	
	strcpy(nom, "Tiko");
}


Robot::Robot(int nPV, int nForce, int nEXP, int nVIT, int nnb_potion, char * nnom)
{
	PV = nPV;            // repr ́esente les points de vie du personnage
	PVmax = nPV;         // repr ́esente les points de vie max du personnage
	Force = nForce;         // repr ́esente la force du personnage
	VIT = nVIT;           // repr ́esente la vitesse du personnage
	nb_potion = nnb_potion;     // repr ́esente le nombre de potions du personnage

	strcpy(nom, nnom);

	strcpy(message, "bonjour");

}

void Robot:: affiche_ennemi(int a) const //affiche l'avatar du personnage, de la meme fa�on que les decors.
{
	switch(a)
	{
		case 1 :
			cout<<"     ,     ,     ";
			break;
		case 2 :
			cout<<"    (\\____/)     ";
			break;
		case 3 :
			cout<<"     (_oo_)       ";
			break;
		case 4 :
			cout<<"       (O)       ";
			break;
		case 5 :
			cout<<"     __||__    \\)";
			break;
		case 6 :
			cout<<"  []/______\\[] / ";
			break;
		case 7 :
			cout<<"  / \\______/ \\/  ";
			break;
		case 8 :
			cout<<" /    /__\\       ";
			break;
		case 9 :
			cout<<"(\\   /____\\      ";
			break;
	}
}

