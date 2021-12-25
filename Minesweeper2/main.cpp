#include "main.h"
#include "Console.h"
#include "functions.h"

// Trang, Vi tri dang chon, Tong muc
short STrang, SViTriChon, STongMuc;

int main()
{
	/*resizeConsole(ConsoleWidth, ConsoleHeight); //Kich thuoc man hinh console
	SetConsoleTitle(TEXT("Minesweeper")); // Tieu de game

	veTieuDeGame();


	Cursor(false);
	veMenuChinh(0);
	STrang = 1;
	xuLySuKien();*/

	taoMang2ChieuDong();
	loadGame();
	xuatBom();
	std::cout << std::endl;
	system("pause");
}