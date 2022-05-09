#include <stdio.h>
#include <fstream>
#include <customwindow.h>

using namespace std;

int winmain()
{
    Window* window = new Window(L"Custom Window Header Install Progream",1000,270,RGB(255,255,255),customicon(L"icon.ico",64,64),Basic_cursor,Basic_style, WS_EX_APPWINDOW);
    DRAW_TOOL* draw = new DRAW_TOOL(window);
    CREATE_TOOL* textbox = new CREATE_TOOL(window, CLASSNAME::TEXTBOX, "C:\\Program Files (x86)\\Windows Kits\\NETFXSDK\\4.8\\Include\\um\\customwindow.h", 10, 40, 965, 20,0, WS_CHILD | WS_VISIBLE | WS_BORDER);
    CREATE_TOOL* textbox2 = new CREATE_TOOL(window, CLASSNAME::TEXTBOX, "C:\\Program Files (x86)\\Windows Kits\\NETFXSDK\\4.8\\Lib\\um\\x86\\customwindow_debug.lib", 10, 70, 965, 20, 0, WS_CHILD | WS_VISIBLE | WS_BORDER);
    CREATE_TOOL* textbox3 = new CREATE_TOOL(window, CLASSNAME::TEXTBOX, "C:\\Program Files (x86)\\Windows Kits\\NETFXSDK\\4.8\\Lib\\um\\x86\\customwindow_release.lib", 10, 100, 965, 20, 0, WS_CHILD | WS_VISIBLE | WS_BORDER);
    CREATE_TOOL* textbox4 = new CREATE_TOOL(window, CLASSNAME::TEXTBOX, "C:\\Program Files (x86)\\Windows Kits\\NETFXSDK\\4.8\\Lib\\um\\x64\\customwindow_debug.lib", 10, 130, 965, 20, 0, WS_CHILD | WS_VISIBLE | WS_BORDER);
    CREATE_TOOL* textbox5 = new CREATE_TOOL(window, CLASSNAME::TEXTBOX, "C:\\Program Files (x86)\\Windows Kits\\NETFXSDK\\4.8\\Lib\\um\\x64\\customwindow_release.lib", 10, 160, 965, 20, 0, WS_CHILD | WS_VISIBLE | WS_BORDER);
    draw->start();
    draw->text(RGB(0, 0, 0), "설치 위치:", 10, 10);
    draw->end();
    CREATE_TOOL* button = new CREATE_TOOL(window, CLASSNAME::BUTTON, "설치", 10, 190, 965, 30,5, WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
    while (window->window_running())
    {
        if (getcontrol(button))
        {
            FILE *out,*in;
            fopen_s(&out, textbox->gettext(GetWindowTextLength(textbox->hWnd) + 2), "w");
            fopen_s(&in, "customwindow.h", "r");
            if (out != NULL && in != 0) {
                char a;
                while (fscanf_s(in, "%c", &a,1) != EOF)
                    fprintf(out, "%c", a);
                fclose(in);
                fclose(out);
            }
            else
            {
                MessageBox(window->hWnd, L"설치 실패", 0, 0);
            }
            //fopen_s(&out, textbox2->gettext(GetWindowTextLength(textbox2->hWnd) + 2), "w");
            //fopen_s(&in, "customwindow.lib", "r");
            delete in;
            delete out;
            fstream fout;
            fstream fin;
            fout.open(textbox2->gettext(GetWindowTextLength(textbox2->hWnd) + 2),ios::binary | ios::out);
            fin.open("Debug\\customwindow.lib",ios::binary | ios::in);
            char ch;
            while (!fin.eof())
            {
                fin.get(ch);
                fout << ch;
            }
            fout.close();
            fin.close();
            fout.open(textbox3->gettext(GetWindowTextLength(textbox3->hWnd) + 2), ios::binary | ios::out);
            fin.open("Release\\customwindow.lib", ios::binary | ios::in);
            while (!fin.eof())
            {
                fin.get(ch);
                fout << ch;
            }
            fout.close();
            fin.close();
            fout.open(textbox4->gettext(GetWindowTextLength(textbox4->hWnd) + 2), ios::binary | ios::out);
            fin.open("x64\\Debug\\customwindow.lib", ios::binary | ios::in);
            while (!fin.eof())
            {
                fin.get(ch);
                fout << ch;
            }
            fout.close();
            fin.close();
            fout.open(textbox5->gettext(GetWindowTextLength(textbox5->hWnd) + 2), ios::binary | ios::out);
            fin.open("x64\\Release\\customwindow.lib", ios::binary | ios::in);
            while (!fin.eof())
            {
                fin.get(ch);
                fout << ch;
            }
            fout.close();
            fin.close();
            MessageBox(window->hWnd, L"설치 완료", L"성공", 0);
            break;
        }
    }
    delete draw;
    delete textbox;
    delete textbox2;
    delete textbox3;
    delete textbox4;
    delete textbox5;
    delete button;
    delete window;
}