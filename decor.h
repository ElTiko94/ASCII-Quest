class ElementDecor
{
	public:

	virtual void affiche(int a) const =0;
	
};

// classe derivee
class  Maison : public ElementDecor
{
	public:

	
	void affiche(int a) const;
};

class  Arbre : public ElementDecor
{
	public:

	
	void affiche(int a) const;
};

class Escargot : public ElementDecor
{
	public:
	
	void affiche(int a) const;
};


class Moulin : public ElementDecor
{
	public:
	
	void affiche(int a) const;
};


class Batiment : public ElementDecor
{
	public:
	
	void affiche(int a) const;
};
