#include <Windows.h>
#include <iostream>

struct Key
{
	DWORD VK;
	DWORD SC;
};

Key* KEY_A = new Key();
Key* KEY_D = new Key();
Key* KEY_SPACE = new Key();

void Display();
void DoDashes(int times);
void KeyDown(Key* key);
void KeyUp(Key* key);
void SetupKeys();

int main()
{
	Display();
	SetupKeys();
	while (true)
	{
		if (GetAsyncKeyState(VK_INSERT))
		{
			DoDashes(1000);
			std::cout << "Complete..." << std::endl;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			exit(1);
		}
	}
	return 0;
}

void Display()
{
	std::cout << ".______________________________________________________." << std::endl;
	std::cout << "|......................................................|" << std::endl;
	std::cout << "|...Please keep the Hyper Light Drifter window focused.|" << std::endl;
	std::cout << "|......................................................|" << std::endl;
	std::cout << "|...Press ESCAPE to exit...............................|" << std::endl;
	std::cout << "|...Press INSERT to start dashing......................|" << std::endl;
	std::cout << "|......................................................|" << std::endl;
	std::cout << "|______________________________________________________|" << std::endl;
}

void SetupKeys()
{
	KEY_A->VK = 0x41;
	KEY_A->SC = 0x1E;
	KEY_D->VK = 0x44;
	KEY_D->SC = 0x20;
	KEY_SPACE->VK = 0x20;
	KEY_SPACE->SC = 0x39;
}

void DoDashes(int times)
{
	std::cout << "\nDashing..." << std::endl;
	bool MoveDir = TRUE; // Use this to alternate between left and right. TRUE = Right / FALSE = Left

	for (int i = 0; i <= times; i++)
	{
		if (MoveDir)
			KeyDown(KEY_D);
		else
			KeyDown(KEY_A);

		KeyDown(KEY_SPACE);
		Sleep(16);
		KeyUp(KEY_SPACE);
		Sleep(250);

		if (MoveDir)
			KeyUp(KEY_D);
		else
			KeyUp(KEY_A);

		MoveDir = !MoveDir; // Change directions
	}
}

void KeyDown(Key* key) { keybd_event(key->VK, key->SC, 0, 0); }
void KeyUp(Key* key)   { keybd_event(key->VK, key->SC, KEYEVENTF_KEYUP, 0); }