//********************
//* 	container.h   
//********************

class container
{
protected:
	int numOfHeal;	// number of heal
	int numOfMagicWater;
public:
	container();
	void set(int i, int j);
	int nOfHeal();
	int nOfMW();
	void display();
	bool useHeal();
	bool useMW();
};

container::container()
{
	set(0,0);
}

void container::set(int i, int j)
{
	numOfHeal = i;
	numOfMagicWater = j;
}

int container::nOfHeal()
{
	return numOfHeal;
}

int container::nOfMW()
{
	return numOfMagicWater;
}


using namespace std;


void container::display()
{
	cout << "【生命药水】（生命值 + 100） 还有 " << numOfHeal << " 个" << endl;
	cout << "【魔法药水】（魔法值 + 100） 还有 " << numOfMagicWater << " 个" << endl;
}

bool container::useHeal()
{
	numOfHeal--;
	return 1;
}

bool container::useMW()
{
	numOfMagicWater--;
	return 1;
}


