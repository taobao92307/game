//********************
//*	swordsman.h
//********************

#include "player.h"

class Swordsman:public Player	//��ʿ��
{
public:
	Swordsman(int i,char *cptr);//���캯��
	void isLevelUp();
	bool attack(Player &p);
	bool specialatt(Player &p);
	void AI(Player &p);//���� AI
};

Swordsman::Swordsman(int i,char *cptr)
{
	role=sw;
	for (int j=0;j<10;j++)
		name[j]=cptr[j];
	
	HP=150+8*(i-1);
	HPmax=150+8*(i-1);
	
	MP=75+2*(i-1);
	MPmax=75+2*(i-1);
	
	AP=25+4*(i-1);
	
	DP=25+4*(i-1);
	
	speed=25+2*(i-1);
	
	LV=i;
	
	death=0;
	
	EXP=LV*LV*75;
	
	bag.set(i*5,i*5);
}

void Swordsman::isLevelUp()
{
	if (EXP>=LV*LV*75)
	{
		LV++;
		AP += 4;
		DP += 4;
		HPmax += 8;
		MPmax += 2;
		speed += 2;
		
		cout << name << " �����ˣ�" << endl;
		cout << "����ֵ����" << 8 << "��" << endl;
		cout << "ħ��ֵ����" << 2 << "��" << endl;
		cout << " �ٶ� ����" << 2 << "��" << endl;
		cout << "����������" << 4 << "��" << endl;
		cout << "����������" << 4 << "��" << endl;
		
		isLevelUp();	//�ݹ���ã����һ�λ�þ���ֵ̫����ܷ������༶�Ŀ���
	}
}

bool Swordsman::attack(Player &p)
{
	double HPtemp=0,EXPtemp=0;//�з���Ѫ����Ҿ���ֵ
	double hit=1;//��������,���ܲ����ػ�
	srand((unsigned int)time(NULL));//�����������
	
	if ((speed>p.speed) && (rand()%100<(speed-p.speed)))//���ι���
	{
		HPtemp=(int)((1.0*AP/p.DP)*AP*5/(rand()%4+10));
		cout << name << "�ȷ�����,�ɽ�����,����" << p.name << "������," << p.name << " ����ֵ������" <<HPtemp << endl;
		p.HP=(int)(p.HP-HPtemp);
		
		EXPtemp=(int)(HPtemp*1.2);
	}
	
	if ((speed<=p.speed) && (rand()%50<1))	//�з����
	{
		cout << name << "�γ�����,һ���ҿ�," << p.name << "˳�ƶ㿪��" << endl;
		
		//system("pause");
		return 1;
	}
	
	if (rand()%100<=10)//10% ���ʷ����ػ�
	{
		hit=1.5;//�������ӱ�Ϊ1.5
		cout << name << "��������,��������һ��";
	}
	
	HPtemp=(int)(hit*(1.0*AP/p.DP)*AP*30/(rand()%8+32));
	
	cout << name << "��Ȼ�ӽ�,һ�������Թ���ǰ," << p.name << "��һ���������Ŷ���, ����ֵ������" << HPtemp << endl;
	
	EXPtemp=(int)(EXPtemp+HPtemp*1.2);//û�� int ���ܻ��о���
	p. HP=(int)(p.HP-HPtemp);
	
	cout << name<<"�����" <<EXPtemp<<"�㾭��ֵ" << endl;
	
	EXP=(int)(EXP+EXPtemp);
	//system("pause");
	
	return 1;//���������ɹ�
}

bool Swordsman::specialatt(Player &p)
{
	if (MP<40)
	{
		cout << "����ħ��ֵ������ " << endl;
		//system("pause");
		
		return 0;//ħ������,���⹥������ʧ��
	}
	
	else
	{
		MP -= 40;
		if (rand()%100<=10)//10% �з����
		{
			cout << name << "�ո�ʹ���ؽ�ն," << p.name << "�����˸����ӷ���,������" << endl;
			
			//system("pause");
			
			return 1;
		}
		
		double HPtemp=0,EXPtemp=0;
		double hit=1;
		
		srand((unsigned int)time(NULL));
		HPtemp=(int)(AP*1.2+20);
		EXPtemp=(int)(HPtemp*1.5);
		
		cout << name << "ʹ��������������һ������~��~ն~~�������𱦽�����" << p.name<< "��ȥ,��ʱ����Ѫ�Ľ�" << endl;
		cout << p.name << "����ֵ������ " <<HPtemp<<"," << name << "�����" <<EXPtemp << "�㾭��ֵ" << endl;
		p.HP=(int)(p.HP-HPtemp);
		EXP=(int)(EXP+EXPtemp);
		//system("pause");
	}
	return 1;//���⹥�������ɹ�
}


void Swordsman::AI(Player &p)//���� AI
{
	if ((HP<=(int)((1.0*p.AP/DP)*p.AP*1.5)) && (HP+100<=1.1*HPmax) && (bag.nOfHeal()>0) && (p.HP>int((1.0*p.AP/DP)*p.AP*0.6)))//������ҵ�����ֵ������������Ҵ����ʹ�ûظ�������̫�˷����лظ�������ʹ����������Ҳ����ܱ��������ֱ��ɱ��
	{
		useHeal();//ʹ�ûظ���
	}
	else
	{
		if (MP>=40 && HP>0.5*HPmax && rand()%10>7)//ħ��ֵ�㹻�ҵ��Ե� HP �㹻��30%����
		{
			specialatt(p);//ʹ�����⹥��
			p.isDead();//�ж���������Ƿ�������
		}
		else
		{
			if (MP<40 && HP>0.5*HPmax && !bag.nOfMW())//ħ��ֵ�����ҵ��Ե� HP �㹻��ȫ
			{
				useMW();//ʹ��ħ��ˮ
			}
			else//�������
			{
				attack(p);//ʹ����ͨ����
				p.isDead();//�ж���������Ƿ�������
			}
		}
	}
}
