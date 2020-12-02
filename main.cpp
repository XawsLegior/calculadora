#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include <math.h>


HINSTANCE hInst;

/* *============= PONTEIROS *============= */
char valores1[100], valores2[100], ARM[100], INS[10];
int V = 0, OP = 0, virgula = 0;
int dividir = 0, multiplicar = 0, subtrair = 0, adicionar = 0, raiz_q = 0, porcentagem = 0;

int botoes[] = {IDC_BUTTON14, IDC_BUTTON11, IDC_BUTTON12, IDC_BUTTON13, IDC_BUTTON8, IDC_BUTTON9, IDC_BUTTON10, IDC_BUTTON5, IDC_BUTTON6, IDC_BUTTON7};
int num_c = 9;
char num[2];

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HWND J_RESULTADO = GetDlgItem(hwndDlg, IDC_EDIT1);
    HWND J_RESULTADO2 = GetDlgItem(hwndDlg, IDC_EDIT2);
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {

    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_CREATE:
        {
            case WM_CTLCOLORBTN:
            {
                   for(int x = 1; x < 10; x++)
                   {
                       if(botoes[x] == GetDlgCtrlID((HWND) lParam))
                       {
                           sprintf(num, "%d", x);

                           HDC hdc = (HDC)wParam;
                           RECT rect = {11,5,100,100};

                            HBRUSH x = CreateSolidBrush (RGB (255,0,0));
                            SelectObject(hdc, x);

                            RoundRect(hdc, 1, 1, 32, 25, 10, 10);

                            SetTextColor(hdc,RGB(255,255,255));
                            SetBkMode(hdc, TRANSPARENT);

                            DrawText(hdc, num, -1, &rect, DT_LEFT);
                             HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                            //DeleteObject(x);
                        }
                   }

                   if(IDC_BUTTON14 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {32,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 70, 25, 10, 10);
                       DrawText(hdc, "0", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON15 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {11,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 32, 25, 10, 10);
                       DrawText(hdc, ",", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON20 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {11,10,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 104, 35, 10, 10);
                       DrawText(hdc, "RESULTADO", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON1 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {13,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 80, 25, 10, 10);
                       DrawText(hdc, "APAGAR", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON2== GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {13,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 80, 25, 10, 10);
                       DrawText(hdc, "LIMPAR", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON3 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {15,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 72, 25, 5, 5);
                       DrawText(hdc, "Dividir", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON17 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {2,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 72, 25, 5, 5);
                       DrawText(hdc, "Multiplicar", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON18 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {10,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 72, 25, 5, 5);
                       DrawText(hdc, "Subtrair", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON19 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {5,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 72, 25, 5, 5);
                       DrawText(hdc, "Adicionar", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON4 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {15,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 72, 25, 5, 5);
                       DrawText(hdc, "Raiz.Q", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }

                   if(IDC_BUTTON16 == GetDlgCtrlID((HWND)lParam))
                   {
                       HDC hdc = (HDC)wParam;
                       RECT rect = {32,5,100,100};

                       HBRUSH fundo = CreateSolidBrush(RGB(255, 0, 0));
                       SelectObject(hdc, fundo);
                       SetTextColor(hdc,RGB(255,255,255));
                       SetBkMode(hdc, TRANSPARENT);

                       RoundRect(hdc, 1, 1, 72, 23, 5, 5);
                       DrawText(hdc, "%", -1, &rect, DT_LEFT);
                        HBRUSH brushRet = (HBRUSH)GetStockObject(NULL_BRUSH);
                   }




             // ---------------------- //
            }

            case WM_CTLCOLORSTATIC:
            {
                HDC hdc = (HDC)wParam;
                SetTextColor(hdc, RGB(0, 0, 0));
                SetBkColor(hdc, RGB(192,217,217));

                if(IDC_EDIT2 == GetDlgCtrlID((HWND)lParam))
                {
                    HDC hdc = (HDC)wParam;
                    SetTextColor(hdc, RGB(0,0,255));
                }
            }

            case WM_CTLCOLORDLG :
            {
                HBRUSH hb = CreateSolidBrush(RGB(192,217,217));
                return (LRESULT) hb;
            }

            //-----------------------
        }
        return TRUE;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            // =================================== [ BOTÃO APAGAR ]  ===================================
            case IDC_BUTTON1:
            {
                GetWindowText(J_RESULTADO, ARM, sizeof(ARM));
                char CON[10];
                int tam = strlen(ARM) - 1;
                ARM[tam] = ARM[tam+1];

                if(OP == 0)
                {
                    valores1[tam] = ARM[tam];
                }
                else
                {
                    valores2[tam] = ARM[tam];
                }
                SetWindowText(J_RESULTADO, ARM);
                break;
            }
            // =================================== [ BOTÃO LIMPAR ]  ===================================
            case IDC_BUTTON2:
                {
                    OP = 0;
                    V = 0;
                    dividir = 0;
                    memset(valores1, 0, sizeof(valores1));
                    memset(valores2, 0, sizeof(valores2));
                    memset(ARM, 0, sizeof(ARM));
                    SetWindowText(J_RESULTADO, 0);
                    SetWindowText(J_RESULTADO2, 0);
                    break;
                }
            // =================================== [ BOTÃO DOS NÚMEROS ]  ===================================
            case IDC_BUTTON5: // NÚMERO 7
                {
                    V = 7;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }

            case IDC_BUTTON6: // NÚMERO 8
                {
                    V = 8;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }

            case IDC_BUTTON7: // NÚMERO 9
                {
                    V = 9;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }
//-----------------------------------------------------------------------------------------------
            case IDC_BUTTON8: //NÚMERO 4
                {
                    V = 4;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }

            case IDC_BUTTON9: //NÚMERO 5
                {
                    V = 5;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }

            case IDC_BUTTON10: //NÚMERO 6
                {
                    V = 6;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }
//-----------------------------------------------------------------------------------------------
            case IDC_BUTTON11: //NÚMERO 1
                {
                    V = 1;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }

             case IDC_BUTTON12: //NÚMERO 2
                {
                    V = 2;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }

             case IDC_BUTTON13: //NÚMERO 3
                {
                    V = 3;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }

             case IDC_BUTTON14: // NÚMERO 0
                {
                    V = 0;
                    SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                    if(strlen(valores1) < 1 && OP == 0)
                    {
                        sprintf(valores1, "%d", V);
                    }
                    else if(strlen(valores1) >= 1 && OP == 0)
                    {
                        sprintf(valores1, "%s%d", ARM, V);
                    }

                    if(strlen(valores2) < 1 && OP == 1)
                    {
                        sprintf(valores2, "%d", V);
                    }
                    else if(strlen(valores2) >= 1 && OP == 1)
                    {
                        sprintf(valores2, "%s%d", ARM, V);
                    }

                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores1);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)valores2);
                    }

                    break;
                }
            // =================================== [ BOTÃO VÍRGULA ]  ===================================
             case IDC_BUTTON15:
                {
                    virgula = 1;
                    if(OP == 0)
                    {
                        SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                        sprintf(ARM, "%s.", ARM);
                        memset(valores1, 0, sizeof(valores1));
                        sprintf(valores1, "%s", ARM);
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)ARM);
                    }
                    else
                    {
                        SendMessage(J_RESULTADO, WM_GETTEXT, (WPARAM)sizeof(ARM), (LPARAM)ARM);
                        sprintf(ARM, "%s.", ARM);
                        memset(valores2, 0, sizeof(valores2));
                        sprintf(valores2, "%s", ARM);
                        SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)ARM);
                    }

                    break;
                }
            // =================================== [ BOTÃO OPERAÇÕES MATEMATICAS ]  ===================================
             case IDC_BUTTON3: //DIVIDIR
                {
                    OP = 1;
                    dividir = 1;

                    sprintf(INS, "%s /", valores1);
                    SetWindowText(J_RESULTADO2, INS);
                    break;
                }

             case IDC_BUTTON17: //MULTIPLICAR
                {
                     OP = 1;
                     multiplicar = 1;
                     sprintf(INS, "%s *", valores1);
                     SetWindowText(J_RESULTADO2, INS);
                    break;
                }

             case IDC_BUTTON18: //SUBSTRAIR
                {
                     OP = 1;
                     subtrair = 1;

                     sprintf(INS, "%s -", valores1);
                     SetWindowText(J_RESULTADO2, INS);
                    break;
                }

             case IDC_BUTTON19: //ADICIONAR
                {
                     OP = 1;
                     adicionar = 1;

                     sprintf(INS, "%s +", valores1);
                     SetWindowText(J_RESULTADO2, INS);
                    break;
                }

             case IDC_BUTTON4: //RAIZ QUADRADA
                {
                    OP = 0;
                    char raiz[10];
                    double convert;
                    convert = atof(valores1);
                    convert = sqrt(convert);
                    sprintf(raiz, "%f", convert);

                    int convert_I = atoi(raiz);
                    char comp[10];
                    sprintf(comp, "%d.000000", convert_I);
                    if(strcmp(comp, raiz) == 0)
                    {
                        sprintf(raiz, "%d", convert_I);
                    }
                    SetWindowText(J_RESULTADO, raiz);

                    char raiz_[10];
                    sprintf(raiz_, "Raiz Quadrada (%s)", valores1);
                    SetWindowText(J_RESULTADO2, raiz_);

                    memset(INS, 0, sizeof(INS));
                    memset(valores1, 0, sizeof(valores1));
                    memset(valores2, 0, sizeof(valores2));
                    break;
                }

             case IDC_BUTTON16: //PORCENTAGEM
                {
                     OP = 1;
                     porcentagem = 1;
                     char raiz_[10];
                     sprintf(raiz_, "Porcentagem(%s)", valores1);
                     SetWindowText(J_RESULTADO2, raiz_);
                    break;
                }
            // =================================== [ BOTÃO RESULTADO ]  ===================================
           case IDC_BUTTON20:
            {
                OP = 0;
                double op1 = 0, op2  = 0, res  = 0;
                op1 =  atof(valores1);
                op2 = atof(valores2);
                char RESULT[50];

                if(dividir == 1)
                {
                    dividir = 0;
                    res = op1 / op2;
                    sprintf(RESULT, "%f", res);
                }
                else if(multiplicar == 1)
                {
                    multiplicar = 0;
                    res = op1 * op2;
                    sprintf(RESULT, "%f", res);
                }
                else if(subtrair == 1)
                {
                    subtrair = 0;
                    res = op1 - op2;
                    sprintf(RESULT, "%f", res);
                }
                else if(adicionar == 1)
                {
                    adicionar = 0;
                    res = op1 + op2;
                    sprintf(RESULT, "%f", res);
                }
                 else if(porcentagem == 1)
                {
                    porcentagem = 0;
                    int raiz_int = op2;
                    double raiz;
                    char convert[10];
                    sprintf(convert, "0.%d", raiz_int);
                    raiz = atof(convert);
                    res = op1 * raiz;
                    sprintf(RESULT, "%f", res);
                }

                memset(valores1, 0, sizeof(valores1));
                memset(valores2, 0, sizeof(valores2));

                int prep = atoi(RESULT);
                char comp[10];
                sprintf(comp, "%d.000000", prep);
                if(strcmp(RESULT, comp) == 0)
                {
                     memset(RESULT, 0, sizeof(RESULT));
                     sprintf(RESULT, "%d", prep);
                }
                SendMessage(J_RESULTADO, WM_SETTEXT, 0, (LPARAM)RESULT);
                SetWindowText(J_RESULTADO2, 0);
                break;
            }

    // ****************************************************** FIM ******************************************************
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
