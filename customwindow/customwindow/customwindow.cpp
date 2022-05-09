#include "customwindow.h"
#ifdef UNICODE
int _control_ = 0;
HICON customicon(const wchar_t _filename[], int _width, int _hight)
{
    return (HICON)LoadImageW(NULL, _filename, IMAGE_ICON, _width, _hight, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_COMMAND:
    {
        _control_ = ((LOWORD(wParam)));
    }
    break;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
Window::Window()
    :hInstance(GetModuleHandle(nullptr))
{
    width = 854;
    height = 480;
    title = TEXT("");
    LPCWSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCWSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.lpfnWndProc = WindowProc;
    backcolor = RGB(255, 255, 255);
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, Basic_style, false);
    hWnd = CreateWindowEx(0, class_name, title, Basic_style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCWSTR _title, int _width, int _height)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCWSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCWSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.lpfnWndProc = WindowProc;
    backcolor = RGB(255, 255, 255);
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, Basic_style, false);
    hWnd = CreateWindowEx(0, class_name, title, Basic_style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCWSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCWSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, Basic_style, false);
    hWnd = CreateWindowEx(0, class_name, title, Basic_style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor, DWORD style, DWORD exstyle)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCWSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCWSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, style, false);
    hWnd = CreateWindowEx(exstyle, class_name, title, style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor, HICON icon, HCURSOR cursor)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCWSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCWSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = icon;
    wnd.hCursor = cursor;
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, false);
    hWnd = CreateWindowEx(0, class_name, title, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor, HICON icon, HCURSOR cursor, DWORD style, DWORD exstyle)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCWSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCWSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = icon;
    wnd.hCursor = cursor;
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, style, false);
    hWnd = CreateWindowEx(exstyle, class_name, title, style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCWSTR _title, int _width, int _height, COLORREF _backcolor, Window* _window, HICON icon, HCURSOR cursor, DWORD style, DWORD exstyle)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCWSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCWSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = icon;
    wnd.hCursor = cursor;
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, style, false);
    if (_window != nullptr)
        hWnd = CreateWindowEx(exstyle, class_name, title, style, rect.left, rect.top, width, height, _window->hWnd, NULL, hInstance, NULL);
    else
        hWnd = CreateWindowEx(exstyle, class_name, title, style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::~Window()
{
    LPCWSTR CLASS_NAME = TEXT("Window");
    UnregisterClass(CLASS_NAME, hInstance);
}

bool Window::window_running()
{
    MSG msg = {};
    if (!IsWindowEnabled(hWnd))
        return false;
    PeekMessage(&msg, hWnd, 0u, 0u, PM_REMOVE);
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    return true;
}
void Window::setwindowpos(RECT rect, UINT style, HWND hWnd2)
{
    SetWindowPos(hWnd, hWnd2, rect.left, rect.top, rect.right, rect.bottom, style);
    width = rect.right; height = rect.bottom;
}
void Window::setwindowpos(int x, int y, int _width, int _height, UINT style, HWND hWnd2)
{
    SetWindowPos(hWnd, hWnd2, x, y, _width, _height, style);
    width = _width; height = _height;
}
CREATE_TOOL::CREATE_TOOL(Window* _window, const char* _class_name, const char* class_text, int x, int y, int width, int higth, int _ID, DWORD style)
{
    window = _window;
    class_name = _class_name;
    if (style == NULL)
    {
        if (class_name == CLASSNAME::BUTTON)
        {
            style = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON;
        }
        if (class_name == CLASSNAME::TEXTBOX)
        {
            style = WS_CHILD | WS_VISIBLE | WS_BORDER;
        }
        if (class_name == CLASSNAME::COMBOBOX)
        {
            style = WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN;
        }
        if (class_name == CLASSNAME::LISTBOX)
        {
            style = WS_CHILD | WS_VISIBLE | WS_BORDER;
        }
        if (class_name == CLASSNAME::SCROLLBAR)
        {
            style = WS_CHILD | WS_VISIBLE | WS_BORDER;
        }
    }
    ID = _ID;
    hWnd = CreateWindowA(class_name, class_text, style, x, y, width, higth, window->hWnd, (HMENU)&ID, 0, 0);
}
CREATE_TOOL::~CREATE_TOOL()
{
    DestroyWindow(hWnd);
}
char* CREATE_TOOL::gettext(int buff)
{
    char* result = new char[buff];
    GetWindowTextA(hWnd, result, buff);
    return result;
}
void CREATE_TOOL::settext(LPCSTR _text)
{
    SetWindowTextA(hWnd, _text);
}
HBITMAP GetWindowBitmap(Window* _window)
{
    if (_window == NULL)
    {
        RECT desktop;
        const HWND hDesktop = GetDesktopWindow();
        GetWindowRect(hDesktop, &desktop);
        HDC hdc = GetDC(NULL);
        HDC hDC = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, desktop.right, desktop.bottom);
        HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
        BitBlt(hDC, 0, 0, desktop.right, desktop.bottom, hdc, 0, 0, SRCCOPY);
        SelectObject(hDC, old_obj);
        DeleteDC(hDC);
        ReleaseDC(NULL, hdc);
        return hBitmap;
    }
    else
    {
        HDC hdc = GetDC(_window->hWnd);
        HDC hDC = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, _window->width, _window->height);
        HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
        BitBlt(hDC, 0, 0, _window->width, _window->height, hdc, 0, 0, SRCCOPY);
        SelectObject(hDC, old_obj);
        DeleteDC(hDC);
        ReleaseDC(NULL, hdc);
        return hBitmap;
    }
}
namespace CLASSNAME
{
    const char BUTTON[7] = "BUTTON";
    const char TEXTBOX[5] = "EDIT";
    const char COMBOBOX[9] = "COMBOBOX";
    const char LISTBOX[8] = "LISTBOX";
    const char SCROLLBAR[10] = "SCROLLBAR";
}
DRAW_TOOL::DRAW_TOOL(Window* _window, bool tick_clear)
{
    window = _window;
    clear = tick_clear;
    if (window != NULL) {
        backcolor = window->backcolor;
    }
    else
    {
        clear = false;
    }
}
DRAW_TOOL::~DRAW_TOOL()
{
    DeleteObject(hdc);
    DeleteObject(bitmap);
}
void DRAW_TOOL::start()
{
    if (window == NULL) {
        int x = GetSystemMetrics(SM_CXSCREEN);
        int y = GetSystemMetrics(SM_CYSCREEN);

        HDC hdc2 = GetDC(NULL);
        hdc = ::CreateCompatibleDC(hdc2);
        int color = ::GetDeviceCaps(hdc2, BITSPIXEL);
        bitmap = ::CreateBitmap(x, y, 1, color, 0);
        ::SelectObject(hdc, bitmap);
        if (!clear) {
            ::BitBlt(hdc, 0, 0, x, y, hdc2, 0, 0, SRCCOPY);
        }
        ReleaseDC(NULL, hdc2);
    }
    else {
        HDC hdc2 = GetDC(window->hWnd);
        hdc = ::CreateCompatibleDC(hdc2);
        int color = ::GetDeviceCaps(hdc2, BITSPIXEL);
        bitmap = ::CreateBitmap(window->width, window->height, 1, color, 0);
        ::SelectObject(hdc, bitmap);
        if (!clear) {
            ::BitBlt(hdc, 0, 0, window->width, window->height, hdc2, 0, 0, SRCCOPY);
        }
        ReleaseDC(window->hWnd, hdc2);
        if (clear) {
            box(window->backcolor, 0, 0, window->width, window->height, window->backcolor);
        }
    }
}

void DRAW_TOOL::end()
{
    if (window == NULL) {
        int x = GetSystemMetrics(SM_CXSCREEN);
        int y = GetSystemMetrics(SM_CYSCREEN);
        HDC hdc2 = GetDC(NULL);
        ::BitBlt(hdc2, 0, 0, x, y, hdc, 0, 0, SRCCOPY);
        DeleteDC(hdc);
        DeleteObject(bitmap);
        ReleaseDC(NULL, hdc2);
    }
    else {
        HDC hdc2 = GetDC(window->hWnd);
        ::BitBlt(hdc2, 0, 0, window->width, window->height, hdc, 0, 0, SRCCOPY);
        DeleteDC(hdc);
        DeleteObject(bitmap);
        ReleaseDC(window->hWnd, hdc2);
    }
}
void DRAW_TOOL::nodrawend()
{
    if (window == NULL) {
        int x = GetSystemMetrics(SM_CXSCREEN);
        int y = GetSystemMetrics(SM_CYSCREEN);
        DeleteDC(hdc);
        DeleteObject(bitmap);
    }
    else {
        DeleteDC(hdc);
        DeleteObject(bitmap);
    }
}
void DRAW_TOOL::setbitmap(HBITMAP _bitmap)
{
    DeleteObject(bitmap);
    bitmap = _bitmap;
    ::SelectObject(hdc, bitmap);
}
void DRAW_TOOL::Line(COLORREF color, int x1, int y1, int x2, int y2, int width)
{
    HPEN pen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, pen);
    MoveToEx(hdc, x1, y1, 0);
    LineTo(hdc, x1 + x2, y1 + y2);
    MoveToEx(hdc, -x1, -y1, 0);
    DeleteObject(pen);
}

void DRAW_TOOL::box(COLORREF color, int x1, int y1, int x2, int y2, COLORREF filled, int width)
{
    HPEN pen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, pen);
    if (filled == (COLORREF)(-1)) {
        SelectObject(hdc, GetStockObject(NULL_BRUSH));
        Rectangle(hdc, x1, y1, x1 + x2, y1 + y2);
    }
    else
    {
        HBRUSH brush = CreateSolidBrush(filled);
        SelectObject(hdc, brush);
        Rectangle(hdc, x1, y1, x1 + x2, y1 + y2);
        DeleteObject(brush);
    }
    DeleteObject(pen);
}
void DRAW_TOOL::circle(COLORREF color, int x1, int y1, int x2, int y2, COLORREF filled, int width)
{
    HPEN pen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, pen);
    if (filled == (COLORREF)(-1)) {
        SelectObject(hdc, GetStockObject(NULL_BRUSH));
        Ellipse(hdc, x1, y1, x1 + x2, y1 + y2);
    }
    else
    {
        HBRUSH brush = CreateSolidBrush(filled);
        SelectObject(hdc, brush);
        Ellipse(hdc, x1, y1, x1 + x2, y1 + y2);
        DeleteObject(brush);
    }
    DeleteObject(pen);
}

void DRAW_TOOL::polygon(COLORREF color, POINT pos[],int cpt, COLORREF filled,int width)
{
    HPEN pen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, pen);
    if (filled == (COLORREF)(-1)) {
        SelectObject(hdc, GetStockObject(NULL_BRUSH));
        Polygon(hdc, pos, cpt);
    }
    else
    {
        HBRUSH brush = CreateSolidBrush(filled);
        SelectObject(hdc, brush);
        Polygon(hdc, pos, cpt);
        DeleteObject(brush);
    }
    DeleteObject(pen);
}
void DRAW_TOOL::text(COLORREF color, const char* text, int x, int y, COLORREF _backcolor, int width)
{
    SetTextColor(hdc, color);
    if (_backcolor == NULL)
    {
        SetBkMode(hdc, TRANSPARENT);
    }
    else {
        SetBkMode(hdc, OPAQUE);
        SetBkColor(hdc, _backcolor);
    }
    TextOutA(hdc, x, y, text, strlen(text));
}
bool getlastcontrolA(CREATE_TOOL* _button)
{
    if (_control_ == _button->ID) {
        _control_ = 0;
        return true;
    }
    return false;
}
bool getlastcontrolB(CREATE_TOOL* _button)
{
    if (_control_ == _button->ID) {
        return true;
    }
    return false;
}
namespace input {
    bool key(int _key, Window* window)
    {
        if (window == nullptr)
        {
            return (GetAsyncKeyState(_key) & 0x8000);
        }
        HWND hWnd = GetForegroundWindow();
        DWORD fromId = GetCurrentThreadId();
        DWORD toId = GetWindowThreadProcessId(hWnd, NULL);
        AttachThreadInput(fromId, toId, TRUE);
        HWND focus = GetFocus();
        if (focus == window->hWnd)
        {
            return (GetAsyncKeyState(_key) & 0x8000);
        }
        return false;
    }
    POINT mouse(Window* window)
    {
        if (window == nullptr)
        {
            POINT result;
            GetCursorPos(&result);
            return result;
        }
        POINT result;
        GetCursorPos(&result);
        ScreenToClient(window->hWnd, &result);
        return result;
    }
}
HWND GetFocusWindow()
{
    HWND hWnd = GetForegroundWindow();
    DWORD fromId = GetCurrentThreadId();
    DWORD toId = GetWindowThreadProcessId(hWnd, NULL);
    AttachThreadInput(fromId, toId, TRUE);
    return GetFocus();
}
#else
int _control_ = 0;
HICON customicon(const wchar_t _filename[], int _width, int _hight)
{
    return (HICON)LoadImageW(NULL, _filename, IMAGE_ICON, _width, _hight, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_COMMAND:
    {
        _control_ = ((LOWORD(wParam)));
    }
    break;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
Window::Window()
    :hInstance(GetModuleHandle(nullptr))
{
    width = 854;
    height = 480;
    title = TEXT("");
    LPCSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.lpfnWndProc = WindowProc;
    backcolor = RGB(255, 255, 255);
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, Basic_style, false);
    hWnd = CreateWindowEx(0, class_name, title, Basic_style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCSTR _title, int _width, int _height)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.lpfnWndProc = WindowProc;
    backcolor = RGB(255, 255, 255);
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, Basic_style, false);
    hWnd = CreateWindowEx(0, class_name, title, Basic_style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, Basic_style, false);
    hWnd = CreateWindowEx(0, class_name, title, Basic_style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor, DWORD style, DWORD exstyle)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, style, false);
    hWnd = CreateWindowEx(exstyle, class_name, title, style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor, HICON icon, HCURSOR cursor)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = icon;
    wnd.hCursor = cursor;
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, false);
    hWnd = CreateWindowEx(0, class_name, title, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor, HICON icon, HCURSOR cursor, DWORD style, DWORD exstyle)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = icon;
    wnd.hCursor = cursor;
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, style, false);
    hWnd = CreateWindowEx(exstyle, class_name, title, style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::Window(LPCSTR _title, int _width, int _height, COLORREF _backcolor, Window* _window, HICON icon, HCURSOR cursor, DWORD style, DWORD exstyle)
    :hInstance(GetModuleHandle(nullptr))
{
    width = _width;
    height = _height;
    title = _title;
    LPCSTR class_name = TEXT("Window");
    WNDCLASS wnd = {};
    wnd.lpszClassName = (LPCSTR)class_name;
    wnd.hInstance = hInstance;
    wnd.hIcon = icon;
    wnd.hCursor = cursor;
    wnd.lpfnWndProc = WindowProc;
    backcolor = _backcolor;
    HBRUSH brush = CreateSolidBrush(backcolor);
    wnd.hbrBackground = brush;
    DeleteObject(brush);
    RegisterClass(&wnd);

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
    AdjustWindowRect(&rect, style, false);
    if (_window != nullptr)
        hWnd = CreateWindowEx(exstyle, class_name, title, style, rect.left, rect.top, width, height, _window->hWnd, NULL, hInstance, NULL);
    else
        hWnd = CreateWindowEx(exstyle, class_name, title, style, rect.left, rect.top, width, height, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, SW_SHOW);
}
Window::~Window()
{
    LPCSTR CLASS_NAME = TEXT("Window");
    UnregisterClass(CLASS_NAME, hInstance);
}

bool Window::window_running()
{
    MSG msg = {};
    if (!IsWindowEnabled(hWnd))
        return false;
    PeekMessage(&msg, hWnd, 0u, 0u, PM_REMOVE);
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    return true;
}
void Window::setwindowpos(RECT rect, UINT style, HWND hWnd2)
{
    SetWindowPos(hWnd, hWnd2, rect.left, rect.top, rect.right, rect.bottom, style);
    width = rect.right; height = rect.bottom;
}
void Window::setwindowpos(int x, int y, int _width, int _height, UINT style, HWND hWnd2)
{
    SetWindowPos(hWnd, hWnd2, x, y, _width, _height, style);
    width = _width; height = _height;
}
CREATE_TOOL::CREATE_TOOL(Window* _window, const char* _class_name, const char* class_text, int x, int y, int width, int higth, int _ID, DWORD style)
{
    window = _window;
    class_name = _class_name;
    if (style == NULL)
    {
        if (class_name == CLASSNAME::BUTTON)
        {
            style = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON;
        }
        if (class_name == CLASSNAME::TEXTBOX)
        {
            style = WS_CHILD | WS_VISIBLE | WS_BORDER;
        }
        if (class_name == CLASSNAME::COMBOBOX)
        {
            style = WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN;
        }
        if (class_name == CLASSNAME::LISTBOX)
        {
            style = WS_CHILD | WS_VISIBLE | WS_BORDER;
        }
        if (class_name == CLASSNAME::SCROLLBAR)
        {
            style = WS_CHILD | WS_VISIBLE | WS_BORDER;
        }
    }
    ID = _ID;
    hWnd = CreateWindowA(class_name, class_text, style, x, y, width, higth, window->hWnd, (HMENU)&ID, 0, 0);
}
CREATE_TOOL::~CREATE_TOOL()
{
    DeleteObject(hWnd);
}
char* CREATE_TOOL::gettext(int buff)
{
    char* result = new char[buff];
    GetWindowTextA(hWnd, result, buff);
    return result;
}
void CREATE_TOOL::settext(LPCSTR _text)
{
    SetWindowTextA(hWnd, _text);
}
HBITMAP GetWindowBitmap(Window* _window)
{
    if (_window == NULL)
    {
        RECT desktop;
        const HWND hDesktop = GetDesktopWindow();
        GetWindowRect(hDesktop, &desktop);
        HDC hdc = GetDC(NULL);
        HDC hDC = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, desktop.right, desktop.bottom);
        HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
        BitBlt(hDC, 0, 0, desktop.right, desktop.bottom, hdc, 0, 0, SRCCOPY);
        SelectObject(hDC, old_obj);
        DeleteDC(hDC);
        ReleaseDC(NULL, hdc);
        return hBitmap;
    }
    else
    {
        HDC hdc = GetDC(_window->hWnd);
        HDC hDC = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, _window->width, _window->height);
        HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
        BitBlt(hDC, 0, 0, _window->width, _window->height, hdc, 0, 0, SRCCOPY);
        SelectObject(hDC, old_obj);
        DeleteDC(hDC);
        ReleaseDC(NULL, hdc);
        return hBitmap;
    }
}
namespace CLASSNAME
{
    const char BUTTON[7] = "BUTTON";
    const char TEXTBOX[5] = "EDIT";
    const char COMBOBOX[9] = "COMBOBOX";
    const char LISTBOX[8] = "LISTBOX";
    const char SCROLLBAR[10] = "SCROLLBAR";
}
DRAW_TOOL::DRAW_TOOL(Window* _window, bool tick_clear)
{
    window = _window;
    clear = tick_clear;
    if (window != NULL) {
        backcolor = window->backcolor;
    }
    else
    {
        clear = false;
    }
}
DRAW_TOOL::~DRAW_TOOL()
{
    DeleteObject(hdc);
    DeleteObject(bitmap);
}
void DRAW_TOOL::start()
{
    if (window == NULL) {
        int x = GetSystemMetrics(SM_CXSCREEN);
        int y = GetSystemMetrics(SM_CYSCREEN);

        HDC hdc2 = GetDC(NULL);
        hdc = ::CreateCompatibleDC(hdc2);
        int color = ::GetDeviceCaps(hdc2, BITSPIXEL);
        bitmap = ::CreateBitmap(x, y, 1, color, 0);
        ::SelectObject(hdc, bitmap);
        if (!clear) {
            ::BitBlt(hdc, 0, 0, x, y, hdc2, 0, 0, SRCCOPY);
        }
        ReleaseDC(NULL, hdc2);
    }
    else {
        HDC hdc2 = GetDC(window->hWnd);
        hdc = ::CreateCompatibleDC(hdc2);
        int color = ::GetDeviceCaps(hdc2, BITSPIXEL);
        bitmap = ::CreateBitmap(window->width, window->height, 1, color, 0);
        ::SelectObject(hdc, bitmap);
        if (!clear) {
            ::BitBlt(hdc, 0, 0, window->width, window->height, hdc2, 0, 0, SRCCOPY);
        }
        ReleaseDC(window->hWnd, hdc2);
        if (clear) {
            box(window->backcolor, 0, 0, window->width, window->height, window->backcolor);
        }
    }
}

void DRAW_TOOL::end()
{
    if (window == NULL) {
        int x = GetSystemMetrics(SM_CXSCREEN);
        int y = GetSystemMetrics(SM_CYSCREEN);
        HDC hdc2 = GetDC(NULL);
        ::BitBlt(hdc2, 0, 0, x, y, hdc, 0, 0, SRCCOPY);
        DeleteDC(hdc);
        DeleteObject(bitmap);
        ReleaseDC(NULL, hdc2);
    }
    else {
        HDC hdc2 = GetDC(window->hWnd);
        ::BitBlt(hdc2, 0, 0, window->width, window->height, hdc, 0, 0, SRCCOPY);
        DeleteDC(hdc);
        DeleteObject(bitmap);
        ReleaseDC(window->hWnd, hdc2);
    }
}
void DRAW_TOOL::nodrawend()
{
    if (window == NULL) {
        int x = GetSystemMetrics(SM_CXSCREEN);
        int y = GetSystemMetrics(SM_CYSCREEN);
        DeleteDC(hdc);
        DeleteObject(bitmap);
    }
    else {
        DeleteDC(hdc);
        DeleteObject(bitmap);
    }
}
void DRAW_TOOL::setbitmap(HBITMAP _bitmap)
{
    bitmap = _bitmap;
    ::SelectObject(hdc, bitmap);
}
void DRAW_TOOL::Line(COLORREF color, int x1, int y1, int x2, int y2, int width)
{
    HPEN pen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, pen);
    MoveToEx(hdc, x1, y1, 0);
    LineTo(hdc, x1 + x2, y1 + y2);
    MoveToEx(hdc, -x1, -y1, 0);
    DeleteObject(pen);
}

void DRAW_TOOL::box(COLORREF color, int x1, int y1, int x2, int y2, COLORREF filled, int width)
{
    HPEN pen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, pen);
    if (filled == (COLORREF)(-1)) {
        SelectObject(hdc, GetStockObject(NULL_BRUSH));
        Rectangle(hdc, x1, y1, x1 + x2, y1 + y2);
    }
    else
    {
        HBRUSH brush = CreateSolidBrush(filled);
        SelectObject(hdc, brush);
        Rectangle(hdc, x1, y1, x1 + x2, y1 + y2);
        DeleteObject(brush);
    }
    DeleteObject(pen);
}
void DRAW_TOOL::circle(COLORREF color, int x1, int y1, int x2, int y2, COLORREF filled, int width)
{
    HPEN pen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, pen);
    if (filled == (COLORREF)(-1)) {
        SelectObject(hdc, GetStockObject(NULL_BRUSH));
        Ellipse(hdc, x1, y1, x1 + x2, y1 + y2);
    }
    else
    {
        HBRUSH brush = CreateSolidBrush(filled);
        SelectObject(hdc, brush);
        Ellipse(hdc, x1, y1, x1 + x2, y1 + y2);
        DeleteObject(brush);
    }
    DeleteObject(pen);
}
void DRAW_TOOL::text(COLORREF color, const char* text, int x, int y, COLORREF _backcolor, int width)
{
    SetTextColor(hdc, color);
    if (_backcolor == NULL)
    {
        SetBkMode(hdc, TRANSPARENT);
    }
    else {
        SetBkMode(hdc, OPAQUE);
        SetBkColor(hdc, _backcolor);
    }
    TextOutA(hdc, x, y, text, strlen(text));
}
bool getlastcontrolA(CREATE_TOOL* _button)
{
    if (_control_ == _button->ID) {
        _control_ = 0;
        return true;
    }
    return false;
}
bool getlastcontrolB(CREATE_TOOL* _button)
{
    if (_control_ == _button->ID) {
        return true;
    }
    return false;
}
namespace input {
    bool key(int _key, Window* window)
    {
        if (window == nullptr)
        {
            return (GetAsyncKeyState(_key) & 0x8000);
        }
        HWND hWnd = GetForegroundWindow();
        DWORD fromId = GetCurrentThreadId();
        DWORD toId = GetWindowThreadProcessId(hWnd, NULL);
        AttachThreadInput(fromId, toId, TRUE);
        HWND focus = GetFocus();
        if (focus == window->hWnd)
        {
            return (GetAsyncKeyState(_key) & 0x8000);
        }
        return false;
    }
    POINT mouse(Window* window)
    {
        if (window == nullptr)
        {
            POINT result;
            GetCursorPos(&result);
            return result;
        }
        POINT result;
        GetCursorPos(&result);
        ScreenToClient(window->hWnd, &result);
        return result;
    }
}
HWND GetFocusWindow()
{
    HWND hWnd = GetForegroundWindow();
    DWORD fromId = GetCurrentThreadId();
    DWORD toId = GetWindowThreadProcessId(hWnd, NULL);
    AttachThreadInput(fromId, toId, TRUE);
    return GetFocus();
}
#endif