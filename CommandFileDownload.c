// CommandFileDownload.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <Windows.h>
#include <tchar.h>
#include <sys/stat.h>

#pragma comment(lib,"urlmon.lib")
int _tmain(int argc,_TCHAR* argv[])
{
	
	if (argv[1] != NULL && argv[2] != NULL) {

		if (S_OK == URLDownloadToFile(NULL, argv[1], argv[2], 0, NULL)) {
			struct _stat w;
			wprintf_s(L"\nFile has been downloaded\n");
			_tstat(argv[2], &w);
			long i = (long)w.st_size;
			
			
			wprintf_s(L"\n File Size: %li", i);
			
		} // Download file
		else {

			wprintf_s(L"\n Could not download file\n");
			
		}
	 }

	else {
		wprintf_s(L"\n Usage: CommandFileDownload <url><dest>\n");
		
	}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
