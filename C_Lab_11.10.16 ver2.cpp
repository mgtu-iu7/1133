#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

bool next_try();

int main(int argc, char** argv)
{
	setlocale(LC_ALL,"RUS");
	int iFildX,iFildY, iShootX,iShootY,iSizeX, iSizeY;
	int CountShoot(0), CountContact(0);
	const int iSizeFildX=100, iSizeFildY=100;  // ������ �������� ����
	const int iSizeTargetX=30, iSizeTargetY=15;	// ������ ������
	iSizeX=iSizeFildX-iSizeTargetX+1;
	iSizeY=iSizeFildY-iSizeTargetY+1;
	printf("\n \t *************  ���� \"������ � ������\"  *************");
	do
	{
		iFildX=rand()%(iSizeX);
		iFildY=rand()%(iSizeY);
		printf("\n\n\t ������� ���������� �������� [X Y]: ");
		scanf("%u %u",&iShootX,&iShootY);
		CountShoot++;
		if ((iShootX>=iFildX)&(iShootX<=(iFildX+iSizeTargetX))&(iShootY>=iFildY)&(iShootY<=(iFildY+iSizeTargetY)))
		{
			printf("\n \t ����������!!! �� ������ � ������.");
			CountContact++;
		}
		else 
			printf("\n \t ���... ������.");	
		printf("\n \n \t ����������: ���������� ��������� -%u, ���������� ���������-%u", CountShoot, CountContact);
		
	}
	while(next_try());
	
	_getch();
	return 0;	
}
bool next_try()
{
	const char cKey0='0', cKey1='1';
	int iLoop(1);
	char cCh('\0');
	printf("\n\n\t 0-����� 1-��������");
	printf("\n\t ��� �����?");
	while(iLoop)
	{
		cCh=_getch();
		if ((cCh==cKey0)||(cCh==cKey1))
		iLoop--;
		return cCh!=cKey0;
	}
}
