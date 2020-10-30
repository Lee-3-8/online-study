// auto01.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "auto01.h"
#include <stdio.h>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void Test(HWND);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_STRING104, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_AUTO01, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_AUTO01));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor        = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDR_MENU1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON2));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    RECT rect = { 0, 0, 150, 150 };
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_32771: // 열기 메뉴
                MessageBox(hWnd, "열기", "연습", MB_OK);
                break;
            case ID_32772: // 저장 메뉴
                MessageBox(hWnd, "저장", "연습", MB_OK);
                break;
            case ID_32773: // 종료 메뉴
                MessageBox(hWnd, "종료", "연습", MB_OK);
                break;
            default:
                return DefWindowProcW(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            char string[100];
            DWORD dwColor;
            for (int x = 0; x < 11; x++) {
                for (int y = 0; y < 11; y++) {
                SetPixel(hdc, 100 + x, 2 + y, RGB(255, 0, 0));
                }
            }
            dwColor = GetPixel(hdc, 100, 2);
            sprintf(string, "%d %d %d", GetRValue(dwColor), GetGValue(dwColor), GetBValue(dwColor));
            TextOut(hdc, 0, 0, string, strlen(string));

            for (int i = 0; i < 10000; i++) {
                SetPixel(hdc, (rand() % 300), (rand() % 300), RGB(127, 127, 127));
            }
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_SETCURSOR:
    {
        HCURSOR hCursor;
        hCursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1));
        SetCursor(hCursor);
        break;
    }
    case WM_LBUTTONDOWN:
        Test(hWnd);
        break;
    case WM_RBUTTONDOWN:
        InvalidateRect(hWnd, &rect, FALSE);
        break;
    case WM_KEYDOWN:
    {
        switch (wParam)
        {
        case VK_UP:
        {
            HDC hdc = GetDC(hWnd);
            HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
            HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
            MoveToEx(hdc, 300, 30, NULL);
            LineTo(hdc, 400, 30);
            DeleteObject(hPen);

            hPen = (HPEN)GetStockObject(BLACK_PEN);
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 300, 60, NULL);
            LineTo(hdc, 400, 60);

            hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            HBRUSH hBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
            HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
            Rectangle(hdc, 5, 405, 100, 500);
            DeleteObject(hPen);
            DeleteObject(hBrush);
            SelectObject(hdc, hOldBrush);

            hPen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            Ellipse(hdc, 5, 405, 100, 500);
            DeleteObject(hPen);

            SelectObject(hdc, hOldPen);
            ReleaseDC(hWnd, hdc);
            break;
        }
        case VK_DOWN:
        {
            HDC hdc = GetDC(hWnd);

            BITMAP FileBitmap; // 비트맵 정보(width, height)를 불러오기 위한 구조체
            // 비트맵 핸들 가져오기
            HBITMAP hFileLoadBitmap = (HBITMAP)LoadImage(hInst, "bitmap1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);
            // 메모리 DC 핸들 가져오기
            HDC hFileMemDC = CreateCompatibleDC(hdc);
            // 메모리 DC에 비트맵 적용
            SelectObject (hFileMemDC, hFileLoadBitmap);
            // 비트맵 구조체가져와서 저장
            GetObject(hFileLoadBitmap, sizeof(BITMAP), &FileBitmap);
            // 화면에 출력
            BitBlt(hdc, 10, 10, FileBitmap.bmWidth, FileBitmap.bmHeight, hFileMemDC, 0, 0, SRCCOPY);
            // 핸들 해제
            DeleteObject(hFileLoadBitmap);
            DeleteDC(hFileMemDC);

            ReleaseDC(hWnd, hdc);
            break;
        }
        default:
            DefWindowProcW(hWnd, message, wParam, lParam);
        }
        break;
    }
    default:
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void Test(HWND hWnd)
{
    char string[100];
    DWORD dwColor;
    HDC hdc = GetDC(hWnd);
    dwColor = RGB(100, 200, 150);
    sprintf(string, "%d %d %d", GetRValue(dwColor), GetGValue(dwColor), GetBValue(dwColor));
    SetTextColor(hdc, RGB(0, 255, 0));
    SetBkColor(hdc, RGB(0, 0, 255));
    TextOut(hdc, 0, 20, string, strlen(string));
    ReleaseDC(hWnd, hdc);
}