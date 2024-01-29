#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>


int main()
{
    const char* git_branch = "unknown";
    const char* git_short_hash = "unknown";
    std::string title = "CLBRepairer [" + std::string(git_branch) + "/" + std::string(git_short_hash) + "]";
    SetConsoleTitle(title.c_str());
    printf("GitHub: https://github.com/xyz8848/CLB-Repairer");
    DEVMODE dm;
    ZeroMemory(&dm, sizeof(dm));
    dm.dmSize = sizeof(dm);
    dm.dmPelsWidth = 1920;
    dm.dmPelsHeight = 1080;
    dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    LONG result = ChangeDisplaySettings(&dm, CDS_UPDATEREGISTRY);
    if (result == DISP_CHANGE_SUCCESSFUL)
    {
        MessageBox(NULL, "The resolution has been set to 1920x1080, and the scaling has been set to 100%.", "Success", MB_OK);    }
    else
    {
        MessageBox(NULL, "Unable to change the resolution.", "Error", MB_OK | MB_ICONERROR);
    }
    return 0;
}
