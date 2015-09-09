//********************
//*	mage.h
//********************

class Mage:public Player	//��ʦ��ͽ�ʿ����,������ֵ�趨��ͬ
{
public:
	Mage(int i,char *cptr);
	void isLevelUp();
	bool attack(Player &p);
	bool specialatt(Player &p);
};

Mage::Mage(int i,char *cptr)
{
	role=mg;
	for(int j=0; j<10; j++)
		name[j] = cptr[j];
	
	HP=120+4*(i-1);
	HPmax=120+4*(i-1);
	MP=200+20*(i-1);
	MPmax=200+20*(i-1);
	AP=50+2*(i-1);
	DP=20+2*(i-1);
	speed=25+3*(i-1);
	LV=i;
	death=0;
	EXP=(LV-1)*(LV-1)*65;
	bag.set(i*5,i*30);
}

void Mage::isLevelUp()
{
	if (EXP>=LV*LV*65)
	{
		LV++;
		
		AP += 2;
		DP += 2;
		HPmax += 4;
		MPmax += 20;
		speed += 3;
		
		cout << name << "�����ˣ�" << endl;
		cout << "����������" <<  4 << "��" << endl;
		cout << "ħ��������" << 20 << "��" << endl;
		cout << "�ٶ�������" <<  3 << "��" << endl;
		cout << "����������" <<  2 << "��" << endl;
		cout << "����������" <<  2 << "��" << endl;
		
		isLevelUp();
	}
}

bool Mage::attack(Player &p)
{
	double HPtemp=0, EXPtemp=0;
	double hit=1;
	
	srand((unsigned int)time(NULL));
	
	if ( (speed>p.speed) && (rand()%100<(speed-p.speed)) )
	{
		HPtemp=(int)((1.0*AP/p.DP)*AP*3/(rand()%4+10));
		cout << name << "����һ�Ƿ�������" << p.name << "��С��," << p.name << "����ֵ������" << HPtemp << endl;
		p.HP=(int)(p.HP-HPtemp);
		EXPtemp=(int)(HPtemp*1.2);
	}
	
	if (rand()%100<1)
	{
		cout << name << "Ĭ������," << p.name << "�����ɵرܿ���"<< endl;
		//system("pause");
		return 1;
	}
	
	if (rand()%100<=10)
	{
		hit=1.5;
		cout << name << "��������,��������һ��";
	}
	
	HPtemp=(int)( hit * (1.0*AP/p.DP) * AP * 25 / (rand()%8+35) );
	
	cout << name << "������,����" << p.name << "��" << ( rand()%2==1?"�Դ�,":"���,") << p.name << "����ֵ������" <<HPtemp << endl;
	
	EXPtemp=(int)(EXPtemp+HPtemp*1.2);
	p.HP=(int)(p.HP-HPtemp);
	
	cout << name<< "�����" << EXPtemp << "�㾭��ֵ" << endl;
	
	EXP=(int)(EXP+EXPtemp);
	
	//system("pause");
	
	return 1;
}

bool Mage::specialatt(Player &p)
{
	if (MP<20)
	{
		cout << "����ħ��ֵ������" << endl;
		
		//system("pause");
		
		return 0;
	}
	else
	{
		MP -= 20;
		if (rand()%100<=20)
		{
			cout << name << "Ĭ�&^��@#$*�����������һ���̹�" << p.name << "�ӵ�ԶԶ��" << endl;
			//system("pause");
			return 1;
		}
		
		double HPtemp=0,EXPtemp=0;
		srand((unsigned int)time(NULL));
		
		HPtemp=(int)(AP*1.1);
		
		EXPtemp=(int)(HPtemp*1.3);
		
		cout << name << "Ĭ�&^��@#$*��������һ���̹�����" << p.name <<"," << name << "��ȡ��" << p.name << "��" <<HPtemp << "������ֵ" << endl;
		cout << name << "�����" <<EXPtemp<<"�㾭��ֵ" << endl;
		p.HP=(int)(p.HP-HPtemp);
		
		EXP=(int)(EXP+EXPtemp);
		
		if (HP + HPtemp <= HPmax)
			HP=(int)(HP+HPtemp);
		else
			HP=HPmax;
		//system("pause");
	}
	
	return 1;
}
