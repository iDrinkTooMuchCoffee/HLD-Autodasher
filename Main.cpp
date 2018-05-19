#include <Windows.h>
#include <iostream>

#define VK_KEY_A 0x41
#define VK_KEY_D 0x44
#define SC_KEY_A 0x1E
#define SC_KEY_D 0x20
#define SC_SPACE 0x39

void Display();
void DoDashes(int times);

int main()
{
	Display();
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

void DoDashes(int times)
{
	std::cout << "\nDashing..." << std::endl;

	bool MoveDir = TRUE; // Use this to alternate between left and right. TRUE = Right / FALSE = Left

	int i = 0;
	while (i <= times)
	{
		if (MoveDir)
			keybd_event(VK_KEY_D, SC_KEY_D, 0, 0);
		else
			keybd_event(VK_KEY_A, SC_KEY_A, 0, 0);

		keybd_event(VK_SPACE, SC_SPACE, 0, 0);
		Sleep(16);
		keybd_event(VK_SPACE, SC_SPACE, KEYEVENTF_KEYUP, 0);
		Sleep(250);
		i++;

		if (MoveDir)
			keybd_event(VK_KEY_D, SC_KEY_D, KEYEVENTF_KEYUP, 0);
		else
			keybd_event(VK_KEY_A, SC_KEY_A, KEYEVENTF_KEYUP, 0);

		MoveDir = !MoveDir;
	}
}