//********************
//*	archer.h
//********************

class Archer:public Player	//��������ͽ�ʿ����,������ֵ�趨��ͬ
{
public:
	Archer(int i, char *cptr);
	void isLevelUp();
	bool attack(Player &p);
	bool specialatt(Player &p);
};

Archer::Archer(int i,char *cptr)
{
	role=ar;
	for (int j=0;j<10;j++)
		name[j]=cptr[j];
	
	HP=180+6*(i-1);
	HPmax=180+6*(i-1);
	MP=75+8*(i-1);
	MPmax=75+8*(i-1);
	
	AP=30+3*(i-1);
	DP=24+3*(i-1);
	speed=30+10 * (i-1);
	
	LV=i;
	
	death=0;
	
	EXP=(LV-1)*(LV-1)*70;
	
	bag.set(i*8,i*8);
}

void Archer::isLevelUp()
{
	if (EXP>=LV*LV*70)
	{
		LV++;
		AP += 3;
		DP += 3;
		HPmax += 6;
		MPmax += 8;
		speed += 10;
		
		cout << name << "�����ˣ�" << endl;
		cout << "����������" <<  6 << "��" << endl;
		cout << "ħ��������" <<  8 << "��" << endl;
		cout << "�ٶ�������" << 10 << "��" << endl;
		cout << "����������" <<  3 << "��" << endl;
		cout << "����������" <<  3 << "��" << endl;
		
		isLevelUp();
	}
}

bool Archer::attack(Player &p)
{
	double HPtemp=0,EXPtemp=0;
	double hit=1;
	
	srand((unsigned int)time(NULL));
	
	if ((speed>p.speed) && (rand()%100<(speed-p.speed)))
	{
		HPtemp=(int)((1.0*AP/p.DP)*AP*2/(rand()%4+10));
		
		cout << name << "�Ȱ���һ��,��ƫ�������ô���" << p.name << "���ؿ�," << p.name <<"����ֵ������" <<HPtemp << endl;
		
		p.HP=(int)(p.HP-HPtemp);
		
		EXPtemp=(int)(HPtemp*1.2);
	}
	
	if (rand()%100<1)
	{
		cout << name << "���һ֧����ŤŤ�ļ�," << p.name << "�����ɵرܿ���" << endl;
		//system("pause");
		
		return 1;
	}
	
	if (rand()%100<=10)
	{
		hit=1.5;
		cout << name << "�����˹�,��������һ��";
	}
	
	HPtemp=(int)(hit*(1.0*AP/p.DP)*AP*30/(rand()%8+32));

	cout << name << "���һ֧����,��ಡ���һ��,������" << p.name<< "��" <<(rand()%2==1?"����,":"����,")<< p.name << "����ֵ������" <<HPtemp << endl;
	
	EXPtemp=(int)(EXPtemp+HPtemp*1.2);
	p. HP=(int)(p.HP-HPtemp);
	
	cout << name<<"�����" <<EXPtemp<<"�㾭��ֵ" << endl;
	
	EXP=(int)(EXP+EXPtemp);
	
	//system("pause");
	return 1;
}

bool Archer::specialatt(Player &p)
{
	if (MP<40)
	{
		cout << "����ħ��ֵ������ " << endl;
		
		//system("pause");
		return 0;
	}
	
	else
	{
		MP -= 40;
		double HPtemp=0,EXPtemp=0;
		
		srand((unsigned int)time(NULL));
		HPtemp=(int)(AP*1.4+18);
		EXPtemp=(int)(HPtemp*1.5);
		
		cout << name << "�ó� 3 �ѳ���,���һ������~��~��~~��, 3 �ѳ�����ֱ��" << p.name << "��ȥ," << p.name << "�޴����㡭��" << endl;
		cout << p.name << "����ֵ������ " << HPtemp << "," << name << "�����" << EXPtemp << "�㾭��ֵ." << endl;
		
		p.HP=(int)(p.HP-HPtemp);
		
		EXP=(int)(EXP+EXPtemp);
		
		//system("pause");
	}
	
	return 1;
}

