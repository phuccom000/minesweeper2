#include "functions.h"
#include "main.h"
#include "Console.h"
#include <iostream>
#include <fstream>

CauTrucBang CTBang;
CauTrucO **CTO;

// Vi tri con tro hien tai
COORD CViTriConTro;

// Su dung phim
bool BSuDungPhim = false;

//Toa do x, y ve bang
short SToaDoX;
short SToaDoY;

//Cap nhat trang thai choi game
bool BTrangThaiChoiGame = false;


void taoMang2ChieuDong()
{
	CTO = new CauTrucO * [CTBang.SDong];
	for (int i = 0; i < CTBang.SDong; ++i)
		CTO[i] = new CauTrucO[CTBang.SCot];
}

void xoaMang2ChieuDong()
{
	for (int i = 0; i < CTBang.SDong; ++i)
		delete[] CTO[i];
	delete[] CTO;
}

void luuToaDoBang()
{
	SToaDoX = ((ConsoleWidth / 2) - (CTBang.SCot));
	SToaDoY = (ConsoleHeight - CTBang.SDong) / 2 + 3;
}

void khoiTao(short SDong, short SCot, short SSoBom)
{
	CTBang.SDong = SDong;
	CTBang.SCot = SCot;
	CTBang.SSoBom = SSoBom;
	CTBang.SSoODaMo = 0;
	CTBang.SSoCo = 0;


	taoMang2ChieuDong();
	taoBomNgauNhien();
	luuToaDoBang();
	CViTriConTro = { 0,0 };
	BTrangThaiChoiGame = true;
	veBang();
	veTrangThaiChoiGame(1, 0, 0);


}

void khoiTaoTuFile()
{

}

void xuatBom()
{
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			std::cout << CTO[i][j].BCoBom;
		}
		std::cout << std::endl;
	}
}

void xuatKichCoChoiRaFile()
{
	std::ofstream fout("Save.txt");
	fout << CTBang.SDong << std::endl;
	fout << CTBang.SCot << std::endl;
	fout.close();
}

void xuatBomRaFile()
{
	std::ofstream fout ("Save.txt", std::ios_base::app);
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			fout << CTO[i][j].BCoBom;
		}
		fout << std::endl;
	}
	fout.close();
}

void xuatCoRaFile() //output flag to file
{
	std::ofstream fout("Save.txt", std::ios_base::app);
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			fout << CTO[i][j].BCamCo;
		}
		fout << std::endl;
	}
	fout.close();
}

void xuatODaMoRaFile()
{
	std::ofstream fout("Save.txt", std::ios_base::app);
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			fout << CTO[i][j].BDaMo;
		}
		fout << std::endl;
	}
	fout.close();
}

void saveFile()
{
	xuatKichCoChoiRaFile();
	xuatBomRaFile();
	xuatCoRaFile();
	xuatODaMoRaFile();
}

void loadGame()
{
	std::ifstream fin("Save.txt");
	if (!fin.is_open())
	{
		std::cerr << "Sorry!  Unable to open file!\n";
		
	}
	int SDong;
	fin >> SDong;
	CTBang.SDong = SDong;
	int SCot;
	fin >> SCot;
	CTBang.SCot = SCot;
	int** Bom = nullptr;
	Bom = new int* [SDong];
	for (int i = 0; i < CTBang.SDong; ++i)
		Bom[i] = new int [CTBang.SCot];
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			fin >> Bom[i][j];
			if (Bom[i][j]) CTO[i][j].BCoBom = true;
			else CTO[i][j].BCoBom = false;
		}
	}
	fin.close();
}


short toaDoX(short SX)//Toa do x ve bang
{
	return (SX * 2) + SToaDoX;
}

short toaDoY(short SY)//Toa do x ve bang
{
	return (SY+ SToaDoY);
}

/*
* Black 0
* Blue 1
* Green 2
* Cyan 3
* Red 4
* Magenta 5
* Yellow 6
* White 7
* Gray 8
* Light Blue 9
* Light Green 10
* Light Cyan 11
* Light Red 12
* Light Magenta 13
* Light Yellow 14
* Bright White 15
*/
void veO(short SX, short SY, short SKieu)
{
	switch (SKieu)
	{
	case 0: // O ko co gi: bg mau trang
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 15, (char*)"  ");
		break;
	case 1: // So 1 chu mau xanh duong, bg mau trang
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 15, (char*)" 1");
		break;
	case 2: // So 2 chu mau xanh duong, bg mau trang
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 1, 15, (char*)" 2");
		break;
	case 3: // So 3 chu mau xanh duong, bg mau trang
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 2, 15, (char*)" 3");
		break;
	case 4: // So 4 chu mau xanh duong, bg mau trang
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 3, 15, (char*)" 4");
		break;
	case 5: // So 5 chu mau xanh duong, bg mau trang
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 4, 15, (char*)" 5");
		break;
	case 6: // So 6 chu mau xanh duong, bg mau trang
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 5, 15, (char*)" 6");
		break;
	case 7: // So 7 chu mau xanh duong, bg mau trang
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 6, 15, (char*)" 7");
		break;
	case 8: // So 8 chu mau xanh duong, bg mau trang
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 13, 15, (char*)" 8");
		break;
	case 9: // Bom
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 12, (char*)" #");
		break;
	case 10: // O chan
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 8, (char*)"  ");
		break;
	case 11: // O le
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 7, (char*)"  ");
		break;
	case 12: // theo doi con tro
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 15, 13, (char*)" ");
		break;
	case 13: // cam co
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 1, 14, (char*)" P");
		break;
	case 14: // cam o ko co bom
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 15, 12, (char*)"Px");
		break;
	case 15: // cam o co bom
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 15, 10, (char*)"PB");
		break;

	}
}

void clickPhai(short SX, short SY) // cam co
{
	if (!CTO[SX][SY].BDaMo)
	{
		if (CTO[SX][SY].BCamCo)
		{
			CTO[SX][SY].BCamCo = false;
			CTBang.SSoCo--;
		}
		else
		{
			CTO[SX][SY].BCamCo = true;
			CTBang.SSoCo++;
		}
	}
	veBang();
}

short demBomLanCan(short SX, short SY)
{
	short SDem = 0;
	for (int i = SX - 1; i <= SX + 1; ++i)
	{
		for (int j = SY - 1; j <= SY + 1; ++j)
		{
			//Xet nhung vi tri khong hop le => tiep tuc lap
			if (i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY))
				continue;
			
			//Xet xem o nay co bom hay ko, neu co tang len 1
			if (CTO[i][j].BCoBom)
				++SDem;
		}
	}
	return SDem;
}

void moO(short SX, short SY) // Mo o
{
	if (!CTO[SX][SY].BDaMo)
	{
		CTO[SX][SY].BDaMo = true;
		if (CTO[SX][SY].BCoBom) //O co bom
			thua(); //thua
		else
		{
			CTBang.SSoODaMo++;
			short SSoBomLanCan = demBomLanCan(SX, SY);
			if (SSoBomLanCan) //Co bom lan can
				CTO[SX][SY].SBomLanCan = SSoBomLanCan;
			else // O rong
			{
				// Duyet cac o lan can va goi de quy.
				for (int i = SX - 1; i <= SX + 1; ++i)
				{
					for (int j = SY - 1; j <= SY + 1; ++j)
					{
						//Xet nhung vi tri khong hop le => tiep tuc lap
						if (i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY))
							continue;

						//goi de quy.
						moO(i, j);
					}
				}
			}
		}
	}
}



void veBang()
{
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{			
			if (CTO[i][j].BCamCo)
				veO(j, i, 13);
			else if (CTO[i][j].SBomLanCan)
				veO(j, i, CTO[i][j].SBomLanCan);
			else if (CTO[i][j].BDaMo) // O rong
				veO(j, i, 0);
			else if ((i + j) % 2)
				veO(j, i, 10);
			else 
				veO(j, i, 11);

			if (BSuDungPhim)
			{
				veO(CViTriConTro.X, CViTriConTro.Y, 12);
			}
		}
	}
}

void taoBomNgauNhien()
{
	short SSoBom = CTBang.SSoBom;
	short SI, SJ; // SI vi tri dong, SJ vi tri cot ta se random.
	srand(time(NULL)); // Reset time.
	while (SSoBom)
	{
		/* CT: muon random trong khoang x,y thi ta se rand() % (y-x+1) + x
		* vd: random trong khoang tu 0->8 => CT: rand()% (8-0+1)+0 = rand() % 9 = rand() % CTBang.SDong
		*/
		SI = rand() % CTBang.SDong;
		SJ = rand() % CTBang.SCot;
		if (CTO[SI][SJ].BCoBom) continue;

		CTO[SI][SJ].BCoBom = true;
		--SSoBom; //Cap nhat lai so luong bom
	}
}

bool thongKeCo()
{
	if ((CTBang.SSoODaMo + CTBang.SSoBom) == (CTBang.SDong * CTBang.SCot))
		return true;
	return false;
}

void clickTrai(short SX, short SY) // Mo o
{
	if (!CTO[SX][SY].BDaMo)
	{
		moO(SX, SY);
		if (BTrangThaiChoiGame)
		{
			veBang();
			if (thongKeCo())
				thang();
		}
	}

}

void thang()
{
	BTrangThaiChoiGame = false;
	xoaMang2ChieuDong(); // Giai phong con tro
	STrang = 5;
	deleteRow(5, 1);
	veTrangThaiChoiGame(2,2,0); //Cap nhat trang thai thang
}
void thua() 
{
	// Hien bom an va kiem tra cam co dung hay sai
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			if (CTO[i][j].BCamCo) // Co cam co
			{
				if (CTO[i][j].BCoBom)
					veO(j, i, 15);//Cam co dung
				else
					veO(j, i, 14);//Cam co sai
			}
			else //ko cam co
			{
				if (CTO[i][j].BCoBom) // Co bom -> Hien bom an
					veO(j, i, 9);
				//else moO(i,j);
			}
		}
	}

	BTrangThaiChoiGame = false;
	xoaMang2ChieuDong(); // Giai phong con tro
	STrang = 4;
	deleteRow(5, 1);
	veTrangThaiChoiGame(3,3,0); //Cap nhat trang thai thua
}

/* Xu ly menu
* 1. menu chinh
* 2. menu chon cap do
* 3. trang choi game
* 4. win
* 5. lose
* leaderboard
* save
* load
*/

void xuLyPhim(KEY_EVENT_RECORD key)
{
	if (key.bKeyDown) // Co nhan phim
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_UP: // mui ten len
			//std::cout << "Up" << std::endl;
			switch (STrang)
			{
			case 1: //menu chinh
				if (STongMuc == 5)
				{
					if (SViTriChon == 0)
						SViTriChon = STongMuc - 1;
					else
						SViTriChon -= 1;
					veMenuChinh(SViTriChon);
				}
				break;
			case 2: // difficulty
				if (STongMuc == 4)
				{
					if (SViTriChon == 0)
						SViTriChon = STongMuc - 1;
					else
						SViTriChon -= 1;
					veMenuCapDo(SViTriChon);
				}
				break;
			case 3: //game
				if (BTrangThaiChoiGame)
				{
					BSuDungPhim = true;
					CViTriConTro.Y = ((CViTriConTro.Y == 0) ? CTBang.SDong - 1 : CViTriConTro.Y - 1);
					veBang();
				}
				break;
			case 4: //lose
				veTrangThaiChoiGame(3, 3, (SViTriChon == 0) ? 1 : 0);
				break;
			case 5: //win
				veTrangThaiChoiGame(2, 2, (SViTriChon == 0) ? 1 : 0);
				break;
			case 6: // save
				veTrangThaiChoiGame(1, 1, (SViTriChon == 0) ? 1 : 0);
				break;
			}

			break;
		case VK_DOWN: // mui ten xuong
			//std::cout << "Down" << std::endl;
			switch (STrang)
			{
			case 1: //menu chinh
				if (STongMuc == 5)
				{
					if (SViTriChon == STongMuc - 1)
						SViTriChon = 0;
					else
						SViTriChon += 1;
					veMenuChinh(SViTriChon);
				}

				break;
			case 2: // difficulty
				if (STongMuc == 4)
				{
					if (SViTriChon == STongMuc - 1)
						SViTriChon = 0;
					else
						SViTriChon += 1;
					veMenuCapDo(SViTriChon);
				}

				break;
			case 3: //game
				if (BTrangThaiChoiGame)
				{
					BSuDungPhim = true;
					CViTriConTro.Y = ((CViTriConTro.Y == CTBang.SDong - 1) ? 0 : CViTriConTro.Y + 1);
					veBang();
				}
				break;
			case 4: //lose
				veTrangThaiChoiGame(3, 3, (SViTriChon == 0) ? 1 : 0);
				break;
			case 5: //win
				veTrangThaiChoiGame(2, 2, (SViTriChon == 0) ? 1 : 0);
				break;
			case 6: // save
				veTrangThaiChoiGame(1, 1, (SViTriChon == 0) ? 1 : 0);
				break;
			}

			break;
		case VK_LEFT: //mui ten trai
			//std::cout << "Left" << std::endl;
			if (BTrangThaiChoiGame)
			{
				BSuDungPhim = true;
				CViTriConTro.X = ((CViTriConTro.X == 0) ? CTBang.SCot - 1 : CViTriConTro.X - 1);
				veBang();
			}
			break;
		case VK_RIGHT: // mui ten phai
			//std::cout << "Right" << std::endl;
			if (BTrangThaiChoiGame)
			{
				BSuDungPhim = true;
				CViTriConTro.X = ((CViTriConTro.X == CTBang.SCot - 1) ? 0 : CViTriConTro.X + 1);
				veBang();
			}
			break;
		case VK_RETURN: // phim enter
			//std::cout << "Enter" << std::endl;
			switch (STrang)
			{
			case 1: //menu chinh
				switch (SViTriChon)
				{
				case 0: // New Game
					STrang = 2;
					deleteRow(8, 6);
					veMenuCapDo(0);
					break;
				case 1: //How to play
					break;
				case 2: //Load file
					STrang = 3;
					deleteRow(8, 6);
					loadGame;
					break;
				case 3: //Leaderboard
					break;
				case 4: //Exit
					exit(0);
				}
				break;
			case 2: // difficulty
				switch (SViTriChon)
				{
				case 0: // Easy 9 x 9, 10 bombs
					STrang = 3; //Cap nhat la dang choi game
					deleteRow(5, 8);
					khoiTao(9, 9, 10);
					break;
				case 1: //Medium
					STrang = 3; //Cap nhat la dang choi game
					deleteRow(5, 8);
					khoiTao(12, 12, 20);
					break;
				case 2: //Hard
					STrang = 3; //Cap nhat la dang choi game
					deleteRow(5, 8);
					khoiTao(16, 16, 50);
					break;
				case 3: //Return
					STrang = 1; //Cap nhat lai la menu chinh
					deleteRow(5, 8);
					veMenuChinh(0);

				}
				break;
			case 4: //lose
				if (SViTriChon)
				{
					STrang = 1; //tro ve menu chinh
					deleteRow(4, ConsoleHeight - 4);
					veMenuChinh(0);
				}
				else
				{
					STrang = 3; // Trang choi game
					deleteRow(4, ConsoleHeight - 4);
					khoiTao(CTBang.SDong, CTBang.SCot, CTBang.SSoBom);
				}
				break;
			case 5: //win
				if (SViTriChon)
				{
					STrang = 1; //tro ve menu chinh
					deleteRow(4, ConsoleHeight - 3);
					veMenuChinh(0);
				}
				else
				{
					//luu ten
				}
				break;
			case 6: //save
				if (SViTriChon)
				{
					STrang = 1; //tro ve menu chinh
					deleteRow(4, ConsoleHeight - 3);
					veMenuChinh(0);
				}
				else
				{
					STrang = 3;
					saveFile();
					deleteRow(4, 3);
					veTrangThaiChoiGame(1, 0, 0);
					//luu game -> xu ly file
				}
				break;
			}

			break;
		case VK_ESCAPE: //phim ESC
			//std::cout << "Esc" << std::endl;
			switch (STrang)
			{
			case 1: //menu chinh
				exit(0);
				break;
			case 2: // difficulty
				STrang = 1;
				deleteRow(5, 8);
				veMenuChinh(0);
				break;
			case 3: // save
				STrang = 6;
				veTrangThaiChoiGame(1, 1, 0);
				break;
			case 4: //win
				break;
			case 5: //lose
				STrang = 2;
				deleteRow(4, ConsoleHeight - 4);
				veMenuCapDo(0);
				break;
			case 6:
				break;
			}

			break;
		case ClickTrai: //Phim Z - Mo o
			//std::cout << "Z" << std::endl;
			if (BTrangThaiChoiGame)
				clickTrai(CViTriConTro.Y, CViTriConTro.X);
		case ClickPhai: //Phim X - Cam co
			//std::cout << "X" << std::endl;
			if (BTrangThaiChoiGame)
				clickPhai(CViTriConTro.Y, CViTriConTro.X);
		}
	}
}


void xuLySuKien()
{
	while (1)
	{
		DWORD DWNumberOfEvents = 0; //Luu lai su kien tai
		DWORD DWNumberOfEventsRead = 0; //Luu lai so luong su kien da duoc loc

		HANDLE HConsoleInput = GetStdHandle(STD_INPUT_HANDLE); //Thiet bi dau vao
		GetNumberOfConsoleInputEvents(HConsoleInput, &DWNumberOfEvents); // Dat su kien dau vao cua giao dien cho bien DWNumberOfEvents

		if (DWNumberOfEvents)
		{
			INPUT_RECORD* IREventBuffer = new INPUT_RECORD[DWNumberOfEvents];//Con tro EventBuffer
			ReadConsoleInput(HConsoleInput, IREventBuffer, DWNumberOfEvents, &DWNumberOfEventsRead); //Dat cac su kien duoc luu tru vao con tro

			//chay vong lap de doc su kien
			for (DWORD i = 0; i < DWNumberOfEvents; ++i)
			{
				if (IREventBuffer[i].EventType == KEY_EVENT) //Neu la su kien phim
				{
					xuLyPhim(IREventBuffer[i].Event.KeyEvent);
				}
				//else if (IREventBuffer[i].EventType == MOUSE_EVENT) // Su kien chuot
			}
		}
	}

}

//Design
void veTieuDeGame()
{
	short i;
	for (i = 0; i < ConsoleWidth; ++i) 
	{
		printf("%c", 95);
	}

	setColorBGTextXY((ConsoleWidth / 2)-6, 1, 14, 0, "Minesweeper\n");
	setColorBGTextXY((ConsoleWidth / 2)-13, 2, 14, 0, "Made by Nguyen Hoang Phuc\n");
	setColor(7);
	for (i = 0; i < ConsoleWidth; ++i)
	{
		printf("%c", 95);
	}
}

void veTrangThaiChoiGame(short STrangThai, short SCheDo, short SIndex)
{
	SViTriChon = SIndex;
	STongMuc = 2;
	setColorBGTextXY(3, 5, 15, 0, "Game Size: %d x %d", CTBang.SDong, CTBang.SCot);
	setColorBGTextXY(3, 6, 15, 0, "Number of Bombs: %d", CTBang.SSoBom);

	//Ve menu thang thua
	const char* STRState;
	switch (SCheDo)
	{
	case 1:
		STRState = "  Save  ";
		setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRState) / 2), 5, 15, ((SIndex == 0) ? 2 : 0), STRState);
		break;
	case 2:
		STRState = "  Save Name  ";
		setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRState) / 2), 5, 15, ((SIndex == 0) ? 2 : 0), STRState);
		break;
	case 3:
		STRState = "  Play Again  ";
		setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRState) / 2), 5, 15, ((SIndex == 0) ? 2 : 0), STRState);
		break;
	}
	if (SCheDo >= 1)
	{
		STRState = "  Exit  ";
		setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRState) / 2), 6, 15, ((SIndex == 1) ? 2 : 0), STRState);
	}
	

	// Draw text status of game
	switch (STrangThai)
	{
	case 1: //Playing
		setColorBGTextXY(ConsoleWidth - 17, 6, 15, 0, "Status: %s", "Playing");
		break;
	case 2: //Win
		setColorBGTextXY(ConsoleWidth - 17, 6, 15, 0, "Status:");
		setColorBGTextXY(ConsoleWidth - 9, 6, 14, 0, "Win    ");
		break;
	case 3: //Lose
		setColorBGTextXY(ConsoleWidth - 17, 6, 15, 0, "Status:");
		setColorBGTextXY(ConsoleWidth - 9, 6, 12, 0, "Lose   ");
		break;
	}
	
}

void veMenuChinh(short SIndex)
{
	//Cap nhat lai vi tri dang chon va tong muc cua menu
	SViTriChon = SIndex;
	STongMuc = 5;

	//Ve menu
	const char* STRNewGame = "New Game";
	setColorBGTextXY(5, 8, 15, ((SIndex == 0) ? 2 : 0), STRNewGame);
	STRNewGame = "How to play";
	setColorBGTextXY(5, 9, 15, ((SIndex == 1) ? 2 : 0), STRNewGame);
	STRNewGame = "Load File";
	setColorBGTextXY(5, 10, 15, ((SIndex == 2) ? 2 : 0), STRNewGame);
	STRNewGame = "Leaderboard";
	setColorBGTextXY(5, 11, 15, ((SIndex == 3) ? 2 : 0), STRNewGame);
	STRNewGame = "Exit";
	setColorBGTextXY(5, 12, 15, ((SIndex == 4) ? 2 : 0), STRNewGame);


}

void veMenuCapDo(short SIndex)
{
	//Cap nhat lai vi tri dang chon va tong muc cua menu
	SViTriChon = SIndex;
	STongMuc = 4;
	setColorBGTextXY(5, 6, 15, 0, "Choose the difficulty");

	//Ve menu
	const char* STRNewGame = "Easy (9 x 9)";
	setColorBGTextXY(5, 8, 15, ((SIndex == 0) ? 2 : 0), STRNewGame);
	STRNewGame = "Normal (12 x 12)";
	setColorBGTextXY(5, 9, 15, ((SIndex == 1) ? 2 : 0), STRNewGame);
	STRNewGame = "Hard (16 x 16)";
	setColorBGTextXY(5, 10, 15, ((SIndex == 2) ? 2 : 0), STRNewGame);
	STRNewGame = "Go Back";
	setColorBGTextXY(5, 12, 15, ((SIndex == 3) ? 2 : 0), STRNewGame);
}
