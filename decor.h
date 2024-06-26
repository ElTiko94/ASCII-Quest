class ElementDecor
{
	public:

	virtual void affiche(int a) const =0;
	virtual int get_largeur() const = 0;
};

// classe derivee
class  Maison : public ElementDecor
{
	public:
	const int largeur =5;
	
	
	void affiche(int a) const;
	int get_largeur() const;
};

class  Arbre : public ElementDecor
{
	public:
	const int largeur =4;
	
	void affiche(int a) const;
	int get_largeur() const;
};

class Escargot : public ElementDecor
{
	public:
	const int largeur =4;
	
	void affiche(int a) const;
	int get_largeur() const;
};


class Moulin : public ElementDecor
{
	public:
	const int largeur =7;
	int get_largeur() const;
	
	void affiche(int a) const;
};


class Batiment : public ElementDecor
{
	public:
	const int largeur =19;
	
	int get_largeur() const;
	void affiche(int a) const;
};
