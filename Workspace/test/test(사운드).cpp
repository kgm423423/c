#include <stdio.h>
#include <windows.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>;

#define C 1046.502
#define D 1108.731
#define E 1318.510
#define F 1396.913
#define G 1567.982
#define A 1760.000
#define B 1975.533

int main()
{
    /*
	Beep(G, 500);
	Sleep(200);
	Beep(G, 500);
	Sleep(200);
	Beep(A, 500);
	Sleep(200);
	Beep(A, 500);
	Sleep(200);
	Beep(G, 500);
	Sleep(200);
	Beep(G, 500);
	Sleep(200);
	Beep(E, 500);
	Sleep(400);
	Beep(G, 500);
	Sleep(200);
	Beep(G, 500);
	Sleep(200);
	Beep(E, 500);
	Sleep(200);
	Beep(E, 500);
	Sleep(200);
	Beep(D, 500);
	Sleep(500);

	Beep(G, 500);
	Sleep(200);
	Beep(G, 500);
	Sleep(200);
	Beep(A, 500);
	Sleep(200);
	Beep(A, 500);
	Sleep(200);
	Beep(G, 500);
	Sleep(200);
	Beep(G, 500);
	Sleep(200);
	Beep(E, 500);
	Sleep(400);
	Beep(G, 500);
	Sleep(200);
	Beep(E, 500);
	Sleep(200);
	Beep(D, 500);
	Sleep(200);
	Beep(E, 500);
	Sleep(200);
	Beep(C, 500);
	Sleep(500);

	*/
	PlaySound(TEXT("beep-2.wav"), NULL, SND_ASYNC | SND_LOOP);


	system("pause");
	return 0;
}
