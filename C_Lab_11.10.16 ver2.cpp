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
	const int iSizeFildX=100, iSizeFildY=100;  // размер игрового поля
	const int iSizeTargetX=30, iSizeTargetY=15;	// размер мишени
	iSizeX=iSizeFildX-iSizeTargetX+1;
	iSizeY=iSizeFildY-iSizeTargetY+1;
	printf("\n \t *************  ИГРА \"ПОПАДИ В МИШЕНЬ\"  *************");
	do
	{
		iFildX=rand()%(iSizeX);
		iFildY=rand()%(iSizeY);
		printf("\n\n\t Введите координаты выстрела [X Y]: ");
		scanf("%u %u",&iShootX,&iShootY);
		CountShoot++;
		if ((iShootX>=iFildX)&(iShootX<=(iFildX+iSizeTargetX))&(iShootY>=iFildY)&(iShootY<=(iFildY+iSizeTargetY)))
		{
			printf("\n \t Поздравляю!!! Вы попали в мишень.");
			CountContact++;
		}
		else 
			printf("\n \t Увы... Промах.");	
		printf("\n \n \t Статистика: количество выстрелов -%u, количество попаданий-%u", CountShoot, CountContact);
		
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
	printf("\n\n\t 0-Выход 1-Угадываю");
	printf("\n\t Ваш выбор?");
	while(iLoop)
	{
		cCh=_getch();
		if ((cCh==cKey0)||(cCh==cKey1))
		iLoop--;
		return cCh!=cKey0;
	}
}
