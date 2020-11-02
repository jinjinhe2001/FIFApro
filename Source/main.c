#include"main.h"

int main()
{
	int table = 0;
	int gd = VGA;
	int gm = VGAHI;
	USER u;
	memset(&u,'\0',sizeof(USER));
	initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
	mouseinit();
	while (1)
	{
		switch (table)
		{
		case -1:
			table = forget();
			break;
		case 0:
			table = signin(&u);
			break;
		case 1:
			table = registerup();
			break;
		case 2:
			table = choosemain(&u);
			break;
		case 21:
			table = mainsolo(&u);
			break;
		case 22:
			table = choose_main_double(&u);
			break;
		case 23:
			table = help();
			break;	
		case 24:
			table = about();
			break;	
		case 25:
			table = practice(&u);
			break;
		case 211:
			table = prepare(&u);
			break;
		case 212:
			table = Pstdio(&u);
			break;
		case 213:
			table = team(&u);
			break;
		case -2:
			closegraph();
			initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
			mouseinit();
			table = 2;
			break;
		default:
			break;

		}
	}
	getch();
	closegraph();
	return 0;
}
