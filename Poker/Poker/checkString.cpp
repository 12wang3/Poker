#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

class pokerStringType//������һ���������Ϣ����
{
	public:
		struct pokerType//������һ���Ƶ���Ϣ�Ľṹ��
		{	
			int color;/*�Ƶ���ɫ���	SPADES   0
									HEARTS   1
									CLUBS    2
									DIAMONDS 3*/
			int point;//�Ƶĵ���2��14
		};

		pokerStringType();
		~pokerStringType();
		
		void addPoker(char *colorString,int point);//���һ����,����֤�������Ϊ����
		void addPoker(int color,int point);//ͬΪ��ӣ����ǻ�ɫֱ��Ϊ���
		double calcValue();//��������������ɵ���õ��Ƶļ�ֵ
		void display();//�������
	private:
		int tot;//������
		pokerType poker[8];//����
};

pokerStringType::pokerStringType()
{
	tot=0;
}
pokerStringType::~pokerStringType()
{

}
void pokerStringType::addPoker(int color,int point)
{
	tot++;
	poker[tot].point=point;
	poker[tot].color=color;
	pokerType tmp;
	for (int i=tot;i>=2&&((poker[i].point<poker[i-1].point)||(poker[i].point==poker[i-1].point&&poker[i].color<poker[i-1].color));i--) {
		tmp=poker[i];
		poker[i]=poker[i-1];
		poker[i-1]=tmp;
	}
}
void pokerStringType::addPoker(char *colorString,int point)
{
	int color;
	switch(colorString[0]) {
		case 'S':color=0;break;
		case 'H':color=1;break;
		case 'C':color=2;break;
		case 'D':color=3;break;
	}
	addPoker(color,point);
}
double pokerStringType::calcValue()
{

	return 0.0;
}
void pokerStringType::display()
{
	for (int i=1;i<=tot;i++) {
		printf ("[%d,%d] ",poker[i].color,poker[i].point);
	}
	printf ("\n");
}


int main(void)
{
	pokerStringType pst;
	pst.addPoker(0,10);
	pst.addPoker(3,2);
	pst.addPoker(3,13);
	pst.addPoker(3,4);
	pst.addPoker(1,2);
	pst.display();
	return 0;
}