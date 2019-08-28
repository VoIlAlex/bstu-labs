#include <afxwin.h>
#include <fstream>

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nShowCmd)
{
	std::ofstream log("log.txt", std::ios::out | std::ios::trunc);
	int retVal = 0;
	do
	{
		retVal = MessageBox(NULL, "Press any button", "ButtonChecker v1.0", MB_ABORTRETRYIGNORE);
		switch(retVal)
		{
		case IDABORT:
			log << "The \"Abort\" button was pressed." << std::endl;
			break;
		case IDRETRY:
			log << "The \"Retry\" button was pressed." << std::endl;
			break;
		case IDIGNORE:
			log << "The \"Ignore\" button was pressed." << std::endl;
			break;
		default:
			break;
		}
	}while(retVal != IDIGNORE);
	log.close();
	return 0;
}

