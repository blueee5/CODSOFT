#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <tchar.h>  // Include tchar.h for _T macro

#define ID_EDIT 1
#define ID_BUTTON 2

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR pCmdLine, int nCmdShow)
{
    const TCHAR CLASS_NAME[] = _T("Number Guessing Game");

    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        _T("Number Guessing Game"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 200,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    if (hwnd == nullptr)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

int targetNumber = 0;
HWND hEdit;
HWND hButton;
HWND hLabel;

void InitializeGame(HWND hwnd)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    targetNumber = rand() % 100 + 1;

    hLabel = CreateWindow(
        _T("STATIC"), _T("Guess a number between 1 and 100:"),
        WS_VISIBLE | WS_CHILD,
        10, 10, 250, 20,
        hwnd, nullptr, nullptr, nullptr
    );

    hEdit = CreateWindow(
        _T("EDIT"), _T(""),
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER,
        10, 40, 100, 20,
        hwnd, (HMENU)ID_EDIT, nullptr, nullptr
    );

    hButton = CreateWindow(
        _T("BUTTON"), _T("Guess"),
        WS_VISIBLE | WS_CHILD,
        120, 40, 80, 20,
        hwnd, (HMENU)ID_BUTTON, nullptr, nullptr
    );
}

void CheckGuess(HWND hwnd)
{
    TCHAR buffer[256];
    GetWindowText(hEdit, buffer, 256);
    int guess = _ttoi(buffer);

    if (guess < targetNumber)
    {
        SetWindowText(hLabel, _T("Too low! Try again:"));
    }
    else if (guess > targetNumber)
    {
        SetWindowText(hLabel, _T("Too high! Try again:"));
    }
    else
    {
        SetWindowText(hLabel, _T("Congratulations! You guessed it!"));
    }
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        InitializeGame(hwnd);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == ID_BUTTON)
        {
            CheckGuess(hwnd);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}
