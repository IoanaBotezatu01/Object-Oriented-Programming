#include "ui.h"
#include "Tests.h"
#include <crtdbg.h>
#include <windows.h>

/*int main()
{
	{
		Tests tests;
		tests.testAll();
		std::string user_file_option;
		while (true)
		{
			std::cout << "Please input the type of file you want to take and save the data in: ";
			getline(std::cin, user_file_option, '\n');
			if (stricmp(user_file_option.c_str(), "html") == 0 || stricmp(user_file_option.c_str(), "csv") == 0)
				break;
			else
				std::cout << "The input file type is not a valid one! The only available options are <html> and <csv>.\n";
		}
		UI ui("file.txt", user_file_option);
		ui.start();
	}
	_CrtDumpMemoryLeaks();
}
*/
