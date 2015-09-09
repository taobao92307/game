//********************
//*		main.cc       
//********************
#include <iostream>
#include "swordsman.h"
#include "archer.h"
#include "mage.h"

int main()
{
	char temp[10];
	bool success=0;//�����Ƿ�ɹ�
	cout << "�������������:";
	cin >> temp;

	Player *human;	//����ʵ�ֶ�̬
	
	int instemp;//���ָ����
	int role;
	
	do
	{
		cout <<"��ѡ��ְҵ��1-��ʿ 2-������ 3-��ʦ" << endl;
		
		cin >>instemp;
		role = instemp;
		
		//system("clear");
		
		switch (instemp)//ѡ��ְҵ
		{
		case 1://ѡ���˽�ʿ
			
			human = new Swordsman(1, temp);
			success=1;//�����ɹ�
			break;
		case 2:
			human = new Archer(1, temp);
			success=1;
			break;
		case 3:
			human = new Mage(1, temp);
			success=1;
			break;
		default:
			break;
		}
	}while(success != 1);	//ѭ��ѡ��ֱ�������ɹ�
	
	int j=0;//�ڼ���
	
	for (int i=1; j<5; i=i+2)
	{
		j++;
		//system("clear");
		
		cout <<"STAGE " <<j <<endl;
		
		cout <<"�з����ܣ�һ��"<< i <<"���Ľ�ʿ��"<<endl;
		
		//system("pause");
		
		Swordsman enemy(i,"�з�ʿ��");	//����һ��i���Ľ�ʿ��Ϊ����
		human->ReFill();				//�������ÿ��һ������ħ��ֵ�ָ�
		
		while(!human->Death() && !enemy.Death())//�����˶�û�������ս��
		{
			success=0;
			while (success!=1)//ֱ�������ɹ�
			{
				//system("clear");
				showinfo(*human,enemy);//��ʾ���������Ϣ
				
				cout <<"���´�ָ�"<<endl;
				
				cout <<"1-���� 2-���⹥�� 3-ʹ�ûظ��� 4-ʹ��ħ��ˮ 0-�˳���Ϸ" << endl;
				
				cin >>instemp;
				
				switch(instemp)
				{
				case 0:
					cout <<"�Ƿ�Ҫ�˳���Ϸ�� Y/N" <<endl;
					char temp;
					cin >>temp;
					
					if (temp=='Y' || temp=='y')
					{
						return 0;
					}
					else
						break;
				case 1:
				{
					switch (role)
					{
					case 1:
						success = ((Swordsman *)human)->attack(enemy);
						((Swordsman *)human)->isLevelUp();
						enemy.isDead();
						break;
					case 2:
						success = ((Archer *)human)->attack(enemy);
						((Archer *)human)->isLevelUp();
						enemy.isDead();
						break;
					case 3:
						success = ((Mage *)human)->attack(enemy);
						((Mage *)human)->isLevelUp();
						enemy.isDead();
						break;
					}
				}
				case 2:
				{
					switch (role)
					{
					case 1:
						success = ((Swordsman *)human)->specialatt(enemy);
						((Swordsman *)human)->isLevelUp();
						enemy.isDead();
						break;
					case 2:
						success = ((Archer *)human)->specialatt(enemy);
						((Archer *)human)->isLevelUp();
						enemy.isDead();
						break;
					case 3:
						success = ((Mage *)human)->specialatt(enemy);
						((Mage *)human)->isLevelUp();
						enemy.isDead();
						break;
					}
				}
				case 3:
					success=human->useHeal();
					break;
				case 4:
					success=human->useMW();
					break;
				default:
					break;
				}
				
				if (!enemy.Death())//����������û������
				{
					enemy.AI(*human);//�������ս
				}
				else
				{
					human->transfer(enemy);//����Ʒ���������
				}
				
				if (human->Death())//��������������
				{
					//system("clear");
					cout<<endl<<endl <<endl <<endl<<endl <<setw(50)<<"ʤ���˱��ҳ��£� ���ж�������������"<<endl;
					
					delete human;
					
					//system("pause");
					
					return 0;
				}
			}
		}
		
		//system("clear");
		
		cout <<endl<<endl <<endl<<endl <<endl<<setw(60) <<"���еĵ��˶��Ѿ����������ˣ� �����ָֻ������յĺ�ƽ��"<<endl <<endl <<endl <<setw(35) <<"��"<<endl <<endl <<endl <<endl <<endl;
		
		delete human;
		
		//system("pause");
		return 0;
	}
}


