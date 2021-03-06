#include "utilities.h"
#include "xorstr.h"
#include "lazy_importer.hpp"
using namespace std;

int main()
{
	SetConsoleTitleA(_xor_("external").c_str());

	g_Utils.erase_pe();
	g_Utils.set_debug(true);

	ULONG processId = g_Utils.get_pid("ac_client.exe");
	uintptr_t baseAddr = g_Utils.get_base(processId, _T("ac_client.exe"));
	HANDLE hGame = g_Utils.get_handle(processId, PROCESS_ALL_ACCESS, true);
	HWND hWindow = g_Utils.get_window("AssaultCube");

	cout << "PID at: " << processId << endl;
	cout << "Base Address at: 0x" << hex << uppercase << baseAddr << endl;
	cout << "Handle at: 0x" << hex << hGame << endl;
	cout << "Window at: 0x" << hex << hWindow << endl;

	getchar();
    return 0;
}

