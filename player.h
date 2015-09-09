//********************
//*	player.h
//********************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "container.h"

enum property{sw,ar,mg};	//��������ְҵ����,ö������

class Player	//������
{
	friend void showinfo(Player &p1, Player &p2);
	friend class Swordsman;
	friend class Archer;
	friend class Mage;

protected:
	int HP,HPmax,MP,MPmax,AP,DP,speed,EXP,LV;//��������
	
	char name[10];//��������
	
	property role;//����ְҵ(��ɫ)
	
	container bag;//��Ʒ��

public:

//	virtual bool attack(Player &p) = 0; //��ͨ����

//	virtual bool specialatt(Player &p) = 0; //���⹥��

//	virtual bool isLevelUp(Player &p) = 0; //�����趨

	bool attack(Player &p); //��ͨ����

	bool specialatt(Player &p); //���⹥��

	bool isLevelUp(Player &p); //�����趨
	

	void ReFill();//ÿ������������������ֵħ��ֵ�ָ�

	bool Death();//��֪�Ƿ������Ѿ�����

	void isDead();//�ж������Ƿ�����

	bool useHeal();//ʹ�ûظ���,��ְҵ�޹�

	bool useMW();//ʹ��ħ��ˮ,��ְҵ�޹�

	void transfer(Player &p);//����ɱ����,������һ�öԷ���Ʒ

	char showRole();//��ʾ�����ְҵ

protected:
	
	bool death;//�Ƿ�����
};


void Player::ReFill()
{
	HP=HPmax;
	MP=MPmax;
}


bool Player::Death()
{
	return death;
}

void Player::isDead()
{
	if (HP<=0)
	{
		cout << name << "������." << endl;
		//system("pause");
		death=1;
	}
}

bool Player::useHeal()
{
	if (bag.nOfHeal()>0)
	{
		HP += 100;
		if (HP>HPmax)
			HP=HPmax;
		
		cout << name << "ʹ���˻ظ���,����ֵ���� 100" << endl;
		
		bag.useHeal();
		
		//system("pause");
		
		return 1;//ʹ�ûظ��������ɹ�
	}
	
	cout <<"�Բ���,��û�лظ�������ʹ��" << endl;
	
	//system("pause");
	
	return 0;//ʹ�ûظ�������ʧ��
}

bool Player::useMW()
{
	if (bag.nOfMW()>0)
	{
		MP += 80;
		if (MP>MPmax)
			MP=MPmax;
		cout << name << "ʹ����ħ��ˮ,ħ��ֵ���� 80" << endl;
		
		bag.useMW();
		
		//system("pause");
		
		return 1;
	}

	cout << "�Բ���,��û��ħ��ˮ����ʹ��" << endl;
	
	//system("pause");
	
	return 0;
}

void Player::transfer(Player &p)
{
	cout << name << "�����" <<p.bag.nOfHeal() << "���ظ�����" <<p.bag.nOfMW() << "��ħ ��ˮ." << endl;
	
	//system("pause");
	
	bag.set(bag.nOfHeal()+p.bag.nOfHeal(),bag.nOfMW()+p.bag.nOfMW());
}

char Player::showRole()
{
	switch(role)
	{
	case sw:
		cout <<setw(6) << "��ʿ";
		break;
	case ar:
		cout <<setw(6) << "������";
		break;
	case mg:
		cout <<setw(6) << "��ʦ";
		break;
	default:
		break;
	}
	return ' ';
}

void showinfo(Player &p1,Player &p2)//������������
{
	cout << "###################################################" << endl;
	
	cout << "# ���" <<setw(11) <<p1.name << " LV."<<setw(3) <<p1.LV << " # ����" <<setw(11) <<p2.name<< "LV." <<setw(3) <<p2.LV<<'#' << endl;
	
	cout << "# HP "	<<setw(3)	<<(p1.HP<=999?p1.HP:999)	<<'/'	<<setw(3) <<(p1.HPmax<=999?p1.HPmax:999) <<" MP " <<setw(3) <<(p1.MP<=999?p1.MP:999) <<'/' <<setw(3) <<(p1.MPmax<=999?p1.MPmax:999)	<<"	 # HP " <<setw(3) <<(p2.HP<=999?p2.HP:999) <<'/' <<setw(3) <<(p2.HPmax<=999?p2.HPmax:999) <<" MP " <<setw(3) <<(p2.MP<=999?p2.MP:999) <<'/' <<setw(3) <<(p2.MPmax<=999?p2.MPmax:999) << " #" << endl;
	
	cout << "# AP " <<setw(3) <<(p1.AP<=999?p1.AP:999) << " DP " <<setw(3) <<(p1.DP<=999?p1.DP:999) << " Speed " <<setw(3) <<(p1.speed<=999?p1.speed:999) << "# AP " <<setw(3) <<(p2.AP<=999?p2.AP:999) << " DP " <<setw(3) <<(p2.DP<=999?p2.DP:999)<< " Speed " <<setw(3) <<(p2.speed<=999?p2.speed:999) <<' #' << endl;
	
	cout << "# EXP" <<setw(7) <<p1.EXP<< " ְҵ";
	
	cout <<p1.showRole();
	
	cout << " # EXP" <<setw(7) <<p2.EXP<< " ְҵ";
	
	cout <<p2.showRole() <<' #' << endl;
	
	cout << "###################################################" << endl;
	
	p1.bag.display();
}

