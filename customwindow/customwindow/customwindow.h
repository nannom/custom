#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED
/*
#ifdef _DEBUG
#pragma comment(lib, "customwindow_debug.lib")
#else
#pragma comment(lib, "customwindow_release.lib")
#endif
*/
#include <Windows.h>
#define getcontrol getcontrolA
#define getcontrolA getlastcontrolA
#define getcontrolB getlastcontrolB
#define Basic_style WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU
#define Basic_cursor LoadCursor(NULL, IDC_ARROW)
#define Basic_icon LoadIcon(NULL, IDI_WINLOGO)
#define Screen_x GetSystemMetrics(SM_CXVIRTUALSCREEN)
#define Screen_y GetSystemMetrics(SM_CYSCREEN)
#ifdef UNICODE
#define winmain() __stdcall wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,_In_ int nCmdShow)
//이 변수는 읽기용입니다 바꾸지 말아주세요.
extern int _control_;
HICON customicon(const wchar_t _filename[], int _width, int _hight);
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
class Window
{
public:
    //이 변수는 보기전용 입니다.
    //바꾸면 오류가 생길 수 있습니다.
    HINSTANCE hInstance;

    //이 변수는 보기전용 입니다.
    //바꾸면 오류가 생길 수 있습니다.
    HWND hWnd;

    //이 변수는 보기전용 입니다.
    //만약 바꾸고 싶다면 setwindowpos를 사용해 주세요.
    //바꾸면 오류가 날 수 있습니다.
    int width;

    //이 변수는 보기전용 입니다.
    //만약 바꾸고 싶다면 setwindowpos를 사용해 주세요.
    //바꾸면 오류가 날 수 있습니다.
    int height;

    //이 변수는 보기전용 입니다.
    //만약 바꾸고 싶다면 SetBackGround를 사용해 주세요.
    //바꾸면 오류가 날 수 있습니다.
    COLORREF backcolor;

    //이 변수는 보기전용 입니다.
    //만약 바꾸고 싶다면 SetWindowTitle를 사용해 주세요.
    //그냥 바꾸면 오류가 날 수 있습니다.
    LPCWSTR title;
    Window();
    Window(LPCWSTR _title, int _width, int _height);
    Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor);
    Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor, DWORD style, DWORD exstyle);
    Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor, HICON icon, HCURSOR cursor);
    Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor, Window* _window, HICON icon, HCURSOR cursor, DWORD style, DWORD exstyle);
    Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor, HICON icon, HCURSOR cursor, DWORD style, DWORD exstyle);
    ~Window();

    //창이 작동하게 합니다
    //while문에 넣어놓는걸 추천합니다
    bool window_running();
    void setwindowpos(RECT rect, UINT style = SWP_NOZORDER, HWND hWnd2 = nullptr);
    void setwindowpos(int x, int y, int _width, int _height, UINT style = SWP_NOZORDER, HWND hWnd2 = nullptr);
};
class CREATE_TOOL
{
public:
    Window* window;
    HWND hWnd;
    const char* class_name;
    int ID;
    CREATE_TOOL(Window* _window, const char* _class_name, const char* class_text, int x, int y, int width, int higth, int _ID = 0, DWORD style = NULL);
    ~CREATE_TOOL();
    char* gettext(int buff);
    void settext(LPCSTR _text);
};
HBITMAP GetWindowBitmap(Window* _window = NULL);
namespace CLASSNAME
{
    extern const char BUTTON[7];
    extern const char TEXTBOX[5];
    extern const char COMBOBOX[9];
    extern const char LISTBOX[8];
    extern const char SCROLLBAR[10];
}
class DRAW_TOOL
{
public:
    Window* window;
    HDC hdc;
    HBITMAP bitmap;
    COLORREF backcolor;
    //화면이 바뀔때마다 이전 화면을 유지할지 유지하지 않을지 정합니다.
    bool clear;
    DRAW_TOOL(Window* _window, bool tick_clear = true);
    ~DRAW_TOOL();
    //꼭 end를 해야 그려집니다.
    void start();

    //꼭 start를 해야 그려집니다.
    void end();
    void nodrawend();
    void setbitmap(HBITMAP _bitmap);
    void Line(COLORREF color, int x1, int y1, int x2, int y2, int width = 1);

    void box(COLORREF color, int x1, int y1, int x2, int y2,COLORREF filled = (COLORREF)(-1), int width = 1);
    void circle(COLORREF color, int x1, int y1, int x2, int y2,COLORREF filled = (COLORREF)(-1), int width = 1);
    void polygon(COLORREF color, POINT pos[],int cpt, COLORREF filled = (COLORREF)(-1),int width = 1);

    void text(COLORREF color, const char* text, int x, int y, COLORREF _backcolor = NULL, int width = 1);
};
bool getlastcontrolA(CREATE_TOOL* _button);
bool getlastcontrolB(CREATE_TOOL* _button);
namespace input
{
    bool key(int _key, Window* window = nullptr);
    POINT mouse(Window* window = nullptr);
}
HWND GetFocusWindow();

#else

#define winmain() __stdcall wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,_In_ int nCmdShow)
//이 변수는 읽기용입니다 바꾸지 말아주세요.
extern int _control_;
HICON customicon(const wchar_t _filename[], int _width, int _hight);
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
class Window
{
public:
    //이 변수는 보기전용 입니다.
    //바꾸면 오류가 생길 수 있습니다.
    HINSTANCE hInstance;

    //이 변수는 보기전용 입니다.
    //바꾸면 오류가 생길 수 있습니다.
    HWND hWnd;

    //이 변수는 보기전용 입니다.
    //만약 바꾸고 싶다면 setwindowpos를 사용해 주세요.
    //바꾸면 오류가 날 수 있습니다.
    int width;

    //이 변수는 보기전용 입니다.
    //만약 바꾸고 싶다면 setwindowpos를 사용해 주세요.
    //바꾸면 오류가 날 수 있습니다.
    int height;

    //이 변수는 보기전용 입니다.
    //만약 바꾸고 싶다면 SetBackGround를 사용해 주세요.
    //바꾸면 오류가 날 수 있습니다.
    COLORREF backcolor;

    //이 변수는 보기전용 입니다.
    //만약 바꾸고 싶다면 SetWindowTitle를 사용해 주세요.
    //그냥 바꾸면 오류가 날 수 있습니다.
    LPCSTR title;
    Window();
    Window(LPCSTR _title, int _width, int _height);
    Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor);
    Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor, DWORD style, DWORD exstyle);
    Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor, HICON icon, HCURSOR cursor);
    Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor, Window* _window, HICON icon, HCURSOR cursor, DWORD style, DWORD exstyle);
    Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor, HICON icon, HCURSOR cursor, DWORD style, DWORD exstyle);
    ~Window();

    //창이 작동하게 합니다
    //while문에 넣어놓는걸 추천합니다
    bool window_running();
    void setwindowpos(RECT rect, UINT style = SWP_NOZORDER, HWND hWnd2 = nullptr);
    void setwindowpos(int x, int y, int _width, int _height, UINT style = SWP_NOZORDER, HWND hWnd2 = nullptr);
};
class CREATE_TOOL
{
public:
    Window* window;
    HWND hWnd;
    const char* class_name;
    int ID;
    CREATE_TOOL(Window* _window, const char* _class_name, const char* class_text, int x, int y, int width, int higth, int _ID = 0, DWORD style = NULL);
    ~CREATE_TOOL();
    char* gettext(int buff);
    void settext(LPCSTR _text);
};
HBITMAP GetWindowBitmap(Window* _window = NULL);
namespace CLASSNAME
{
    extern const char BUTTON[7];
    extern const char TEXTBOX[5];
    extern const char COMBOBOX[9];
    extern const char LISTBOX[8];
    extern const char SCROLLBAR[10];
}
class DRAW_TOOL
{
public:
    Window* window;
    HDC hdc;
    HBITMAP bitmap;
    COLORREF backcolor;
    //화면이 바뀔때마다 이전 화면을 유지할지 유지하지 않을지 정합니다.
    bool clear;
    DRAW_TOOL(Window* _window, bool tick_clear = true);
    ~DRAW_TOOL();
    //꼭 end를 해야 그려집니다.
    void start();

    //꼭 start를 해야 그려집니다.
    void end();
    void nodrawend();
    void setbitmap(HBITMAP _bitmap);
    void Line(COLORREF color, int x1, int y1, int x2, int y2, int width = 1);

    void box(COLORREF color, int x1, int y1, int x2, int y2, COLORREF filled = (COLORREF)(-1), int width = 1);
    void circle(COLORREF color, int x1, int y1, int x2, int y2, COLORREF filled = (COLORREF)(-1), int width = 1);
    void polygon(COLORREF color, POINT pos[], COLORREF filled = (COLORREF)(-1), int width = 1);

    void text(COLORREF color, const char* text, int x, int y, COLORREF _backcolor = NULL, int width = 1);

};
bool getlastcontrolA(CREATE_TOOL* _button);
bool getlastcontrolB(CREATE_TOOL* _button);
namespace input
{
    bool key(int _key, Window* window = nullptr);
    POINT mouse(Window* window = nullptr);
}
HWND GetFocusWindow();

#endif

#endif