// auto02.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//
#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "lecture3.h"
#include <stdio.h>
#include <commdlg.h>
#include <map>

INT_PTR CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR    lpCmdLine,
                      _In_ int       nCmdShow)
{
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
    return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    int nRadio[3] = { IDC_RADIO1, IDC_RADIO2, IDC_RADIO3 };
    char radio_string[100] = { 0, };
    char radio_index[5] = { 0, };
    static std::map<int, bool> radio_checked = { {IDC_RADIO1, FALSE}, {IDC_RADIO2, FALSE}, {IDC_RADIO3, FALSE} };
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDC_BUTTON1:
            MessageBox(hDlg, "��ư ����", "Ǫ�� �˸�", MB_OK);
            return (INT_PTR)TRUE;
        case IDC_BUTTON2:
            for (int i = 0; i < 3; i++) 
            {
                if (IsDlgButtonChecked(hDlg, nRadio[i]) == BST_CHECKED)
                {   
                    if (radio_string[0] == '\0') sprintf(radio_index, "%d", i + 1);
                    else sprintf(radio_index, ", %d", i + 1);
                    strcat(radio_string, radio_index);
                }
            }
            strcat(radio_string, "��° ���� ��ư Ŭ��");
            MessageBox(hDlg, radio_string, "üũ", MB_OK);
            return (INT_PTR)TRUE;
        case IDC_RADIO1:
        case IDC_RADIO2:
        case IDC_RADIO3:
            if (radio_checked[wmId] == FALSE)
            {
                radio_checked[wmId] = TRUE;
            }
            else
            {
                radio_checked[wmId] = FALSE;
                CheckDlgButton(hDlg, wmId, BST_UNCHECKED);
            }
            return (INT_PTR)TRUE;
        case IDOK:
        case IDCANCEL:
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        return (INT_PTR)TRUE;
    }
    case WM_CLOSE:
        EndDialog(hDlg, 0);
        return (INT_PTR)TRUE;
    }
    return (INT_PTR)FALSE;
}