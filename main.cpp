#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "menu.h"
#include <commctrl.h>
#include <wchar.h>
#include <string.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>




HWND hBut1;
HWND hBut2;
HWND hBut3;
HWND hBut4;
HWND hBut5;
HWND hBut6;
HWND hBut7;
HWND hBut8;
HWND hBut9;
HWND hBut10;
HWND hBut11;
HWND hBut12;
HWND hBut13;
HWND hBut14;
HWND hBut15;
HWND hBut16;
HWND hBut17;
HWND hBut18;
HWND hBut19;
HWND hBut20;
HWND hBut21;
HWND hBut22;
HWND hBut23;
HWND hBut24;
HWND hBut25;
HWND hBut26;
HWND hBut27;

HANDLE hhBmp1;
HANDLE hhBmp2;
HANDLE hhBmp3;
HANDLE hhBmp4;
HANDLE hhBmp5;
HANDLE hhBmp6;
HANDLE hhBmp7;
HANDLE hhBmp8;
HANDLE hhBmp9;
HANDLE hhBmp10;
HANDLE hhBmp11;
HANDLE hhBmp12;
HANDLE hhBmp13;
HANDLE hhBmp14;
HANDLE hhBmp15;
HANDLE hhBmp16;
HANDLE hhBmp17;
HANDLE hhBmp18;
HANDLE hhBmp19;
HANDLE hhBmp20;
HANDLE hhBmp21;
HANDLE hhBmp22;
HANDLE hhBmp23;
HANDLE hhBmp24;
HANDLE hhBmp25;
HANDLE hhBmp26;
HANDLE hhBmp27;


HWND tempButton;

extern RECT g_rcImage;
extern int g_nImage;
extern POINT g_ptHotSpot;
extern int g_cxBorder;
extern int g_cyBorder;
extern int g_cyCaption;
extern int g_cyMenu;

typedef wchar_t WCHAR;
typedef const TCHAR* LPCTSTR;
typedef void (__cdecl *MYPROC)(LPCSTR);


int previousNumber = 0;
int faultCounter = 0;


void gameButtons(HWND);
void checkSequence(HWND, int);
void test(HWND);
void paint(HWND, int, int, int);





/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DialogProciadura(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK TimerProc(HWND, UINT, UINT, DWORD);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

BOOL LoadBMP(HWND hwnd){ //ignoruoti


    //LPCTSTR kk = "kkkk";
    //LPCTSTR k1 = "a";
    //LPCTSTR l = concat(kk,k1);
    //LPCTSTR name = lstrcat("Employee_","ssssssss");

    /*
    char *ptr = NULL;
	char	szStr[80] = "This is the first part. ";
	LPCTSTR	str1 = "This is the second part.";
	ptr = lstrcat(szStr, k1);
    MessageBox(hwnd, ptr, "info", MB_OK);
    */
    /*
    int t =2;
    char buffer [33];
  printf ("Enter a number: ");
    itoa (t,buffer,10);
  MessageBox(hwnd, buffer, "info", MB_OK);
  */
    int a=450; int b=50;
    for(int i=1;i<26;i++){


        char *image_n = NULL;
        char *image_name= NULL;
        char szStr[80] = "images/image_part_";
        char number [10];
        itoa(i,number,10);
        image_n = lstrcat(szStr, number);
        image_name = lstrcat(image_n, ".bmp");
        //MessageBox(hwnd, image_name, "info", MB_OK);

        //LPCTSTR kk = "images/lp.bmp";
        //MessageBox(hwnd, kk, "info", MB_OK);

        HDC hDC = GetDC(hwnd);
    if(hDC == NULL){
        MessageBox(hwnd, "Nera DC", "Klaida", MB_OK | MB_ICONERROR);
        return false;
    }
    HANDLE hBmp = LoadImage(NULL, image_name, IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
    if(hBmp == NULL){
        MessageBox(hwnd, "Nera paveikslelio", "Klaida", MB_OK | MB_ICONERROR);
        return false;
    }

    HDC dcmem = CreateCompatibleDC(NULL);
    if(dcmem == NULL){
        MessageBox(hwnd, "Nera darbinio DC ", "Klaida", MB_OK | MB_ICONERROR);
        return false;
    }
    BITMAP bm;
    GetObject(hBmp, sizeof(bm), &bm);
    SelectObject(dcmem, hBmp);

    BitBlt(hDC,a,b,bm.bmWidth,bm.bmHeight, dcmem,0,0,SRCCOPY);
    DeleteDC(dcmem);

    b+=80;

    if(i==5 ||i==10||i==15||i==20){
        a+=80;
        b=50;
    }

    }
    return true;


    //MessageBox(hwnd, "Pradedam pav. piesima", "info", MB_OK);
    /*
    HDC hDC = GetDC(hwnd);
    if(hDC == NULL){
        MessageBox(hwnd, "Nera DC", "Klaida", MB_OK | MB_ICONERROR);
        return false;
    }
    HANDLE hBmp = LoadImage(NULL, "images/FLAG_B24.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
    if(hBmp == NULL){
        MessageBox(hwnd, "Nera paveikslelio", "Klaida", MB_OK | MB_ICONERROR);
        return false;
    }

    HDC dcmem = CreateCompatibleDC(NULL);
    if(dcmem == NULL){
        MessageBox(hwnd, "Nera darbinio DC ", "Klaida", MB_OK | MB_ICONERROR);
        return false;
    }
    BITMAP bm;
    GetObject(hBmp, sizeof(bm), &bm);
    SelectObject(dcmem, hBmp);

    BitBlt(hDC,0,100,bm.bmWidth,bm.bmHeight, dcmem,0,0,SRCCOPY);
    DeleteDC(dcmem);
    return true;
    */

}




int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_ICON));
    wincl.hIconSm = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_ICON));
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(120, 120, 191)); /*200, 65, 708*/

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Puzzle game"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           950,                 /* The programs width */
           550,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           LoadMenu(hThisInstance, MAKEINTRESOURCE(IDR_MENU)),                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HANDLE file;
    BOOL rez;
    DWORD b_written, b_read;

    switch (message)                  /* handle the messages */
    {
        case WM_PAINT:
        {
        HDC hDC;
        PAINTSTRUCT ps;
        hDC = BeginPaint(hwnd, &ps);

        HBRUSH blueBrush = CreateSolidBrush(RGB(0,0,255));
        HPEN newPen = CreatePen(PS_DASH, 3, RGB(255,255,0));

        HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, blueBrush);
        HPEN oldPen = (HPEN)SelectObject(hDC, newPen);



        //horizantalios linijos
        int a = 50; int b = 50;
        for(int i=0; i<6;i++){
            MoveToEx(hDC, a, b, NULL);
            LineTo(hDC, a+400, b);
            b+=80;
        }

        //vertikalios linijos
        a = 50; b = 50;
        for(int i=0; i<6;i++){
            MoveToEx(hDC, a, b, NULL);
            LineTo(hDC, a, b+400);
            a+=80;
        }


        //MoveToEx(hDC, 20, 350, NULL);
        //LineTo(hDC, 300, 350);

        SelectObject(hDC, oldBrush);
        SelectObject(hDC, oldPen);
        DeleteObject(blueBrush);
        DeleteObject(newPen);

        EndPaint(hwnd, &ps);
        }
        break;

        case WM_CREATE:
            CreateWindow(
            "BUTTON",
            TEXT("Pradeti zaidima"),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //stiliai
            50, //x pozicija
            10, //y
            150,//plotis
            30,//aukstis
            hwnd, //tevinis langas
            (HMENU) BUTTON1,
            (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),
            NULL
             );

            CreateWindow(
            "BUTTON",
            TEXT("Rezultatai"),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //stiliai
            755, //x pozicija
            455, //y
            100,//plotis
            30,//aukstis
            hwnd, //tevinis langas
            (HMENU) BUTTON2,
            (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),
            NULL
             );

             CreateWindow(
            "BUTTON",
            TEXT("Taisykles"),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //stiliai
            650, //x pozicija
            455, //y
            100,//plotis
            30,//aukstis
            hwnd, //tevinis langas
            (HMENU) BUTTON28,
            (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),
            NULL
             );


            CreateWindow(
            "static", "Zaidejo vardas:", WS_VISIBLE | WS_CHILD | SS_CENTER,
            220, 15, 110, 20, hwnd, (HMENU) ID_TEXT,
            (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),
            NULL
             );

            CreateWindow("EDIT", TEXT(""),
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_GROUP,
            335, 15, 150, 20,
            hwnd, (HMENU) ID_EDITTEXT, GetModuleHandle(NULL), NULL);


            break;



        case WM_TIMER:
            switch(LOWORD(wParam)){
            case TIMER_2:
            KillTimer(hwnd, TIMER_2);
            MessageBox(hwnd, "Window Procedure killed timer", "Timer", MB_OK);
            break;
            }
            break;


        case WM_COMMAND:
            switch(LOWORD(wParam)){
            case ID_FILE_EXIT:
            //SendMessage(hwnd, WM_CLOSE, 0, 0);
            PostQuitMessage(0);
            break;



            case BUTTON1:
            RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
            gameButtons(hwnd);
            checkSequence(hwnd, 0);


            /*HINSTANCE hLib = LoadLibrary("first_dll.dll");
            if(hLib != NULL){
                MYPROC SomeFunction = (MYPROC) GetProcAddress(hLib, "SomeFunction");
                if(SomeFunction != 0){
                    SomeFunction("DLL rules");
                }else{
                MessageBox(hwnd, "Kazkas blogai su DLL", "DLL Error", MB_OK);
                }
                FreeLibrary(hLib);
            }else{
                MessageBox(hwnd, "Kazkas blogai su DLL", "DLL Error", MB_OK);
            }*/
            //DialogBox(NULL, MAKEINTRESOURCE(ID_DIALOG), hwnd, (DLGPROC)DialogProciadura);
            //MessageBox(hwnd,"Yo Yo", "Title", MB_OK);
            //PostQuitMessage(0);
            //SetTimer(hwnd, TIMER_1, 2000, (TIMERPROC) TimerProc);
            //SetTimer(hwnd, TIMER_2, 5000, NULL);
            break;


            case BUTTON2:

            file = CreateFile("Test_file.txt", GENERIC_READ, 0, NULL,
                   OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if(file != INVALID_HANDLE_VALUE){
                CHAR text2[2048] = {0};
                b_read = 0;
                rez = ReadFile(file, text2, 2048, &b_read, NULL);
                if(rez){
                    MessageBox(hwnd, text2, "Rezultatai", MB_OK);
                }else{
                     MessageBox(hwnd, "text was not read", "Write", MB_OK);
                }
            CloseHandle(file);
            }
            break;

            case BUTTON28:
            MessageBox(hwnd, "Delione turi buti sudeta is eiles. Po eilute is kaires i desine\n(pirma reikia sudeti pirma eilute, po to antra ir t.t)\n Jei per sunku, pilna nuotrauka yra /images aplankale", "Taisykles", MB_OK);
            break;

            case BUTTON3:
            ShowWindow (hBut1, SW_HIDE);
            paint(hwnd, 52, 52, 1);
            checkSequence(hwnd, 1);
            break;

            case BUTTON4:
            ShowWindow (hBut2, SW_HIDE);
            paint(hwnd, 132, 52, 2);
            checkSequence(hwnd, 2);
            break;

            case BUTTON5:
            ShowWindow (hBut3, SW_HIDE);
            paint(hwnd, 212, 52, 3);
            checkSequence(hwnd, 3);
            break;

            case BUTTON6:
            ShowWindow (hBut4, SW_HIDE);
            paint(hwnd, 292, 52, 4);
            checkSequence(hwnd, 4);
            break;

            case BUTTON7:
            ShowWindow (hBut5, SW_HIDE);
            paint(hwnd, 372, 52, 5);
            checkSequence(hwnd, 5);
            break;
            //
            case BUTTON8:
            ShowWindow (hBut6, SW_HIDE);
            paint(hwnd, 52, 132, 6);
            checkSequence(hwnd, 6);
            break;

            case BUTTON9:
            ShowWindow (hBut7, SW_HIDE);
            paint(hwnd, 132, 132, 7);
            checkSequence(hwnd, 7);
            break;

            case BUTTON10:
            ShowWindow (hBut8, SW_HIDE);
            paint(hwnd, 212, 132, 8);
            checkSequence(hwnd, 8);
            break;

            case BUTTON11:
            ShowWindow (hBut9, SW_HIDE);
            paint(hwnd, 292, 132, 9);
            checkSequence(hwnd, 9);
            break;

            case BUTTON12:
            ShowWindow (hBut10, SW_HIDE);
            paint(hwnd, 372, 132, 10);
            checkSequence(hwnd, 10);
            break;
            //
            case BUTTON13:
            ShowWindow (hBut11, SW_HIDE);
            paint(hwnd, 52, 212, 11);
            checkSequence(hwnd, 11);
            break;

            case BUTTON14:
            ShowWindow (hBut12, SW_HIDE);
            paint(hwnd, 132, 212, 12);
            checkSequence(hwnd, 12);
            break;

            case BUTTON15:
            ShowWindow (hBut13, SW_HIDE);
            paint(hwnd, 212, 212, 13);
            checkSequence(hwnd, 13);
            break;

            case BUTTON16:
            ShowWindow (hBut14, SW_HIDE);
            paint(hwnd, 292, 212, 14);
            checkSequence(hwnd, 14);
            break;

            case BUTTON17:
            ShowWindow (hBut15, SW_HIDE);
            paint(hwnd, 372, 212, 15);
            checkSequence(hwnd, 15);
            break;
            //
            case BUTTON18:
            ShowWindow (hBut16, SW_HIDE);
            paint(hwnd, 52, 292, 16);
            checkSequence(hwnd, 16);
            break;

            case BUTTON19:
            ShowWindow (hBut17, SW_HIDE);
            paint(hwnd, 132, 292, 17);
            checkSequence(hwnd, 17);
            break;

            case BUTTON20:
            ShowWindow (hBut18, SW_HIDE);
            paint(hwnd, 212, 292, 18);
            checkSequence(hwnd, 18);
            break;

            case BUTTON21:
            ShowWindow (hBut19, SW_HIDE);
            paint(hwnd, 292, 292, 19);
            checkSequence(hwnd, 19);
            break;

            case BUTTON22:
            ShowWindow (hBut20, SW_HIDE);
            paint(hwnd, 372, 292, 20);
            checkSequence(hwnd, 20);
            break;
            //
            case BUTTON23:
            ShowWindow (hBut21, SW_HIDE);
            paint(hwnd, 52, 372, 21);
            checkSequence(hwnd, 21);
            break;

            case BUTTON24:
            ShowWindow (hBut22, SW_HIDE);
            paint(hwnd, 132, 372, 22);
            checkSequence(hwnd, 22);
            break;

            case BUTTON25:
            ShowWindow (hBut23, SW_HIDE);
            paint(hwnd, 212, 372, 23);
            checkSequence(hwnd, 23);
            break;

            case BUTTON26:
            ShowWindow (hBut24, SW_HIDE);
            paint(hwnd, 292, 372, 24);
            checkSequence(hwnd, 24);
            break;

            case BUTTON27:
            ShowWindow (hBut25, SW_HIDE);
            paint(hwnd, 372, 372, 25);
            checkSequence(hwnd, 25);
            break;


            }
            break;


        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}


 void gameButtons(HWND hwnd){



        hhBmp1 = LoadImage(NULL, "images/image_part_1.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut1 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            455,290,78,78,hwnd, (HMENU) BUTTON3,
            (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut1,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp1);

        hhBmp2 = LoadImage(NULL, "images/image_part_2.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut2 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            615,290,78,78,hwnd, (HMENU) BUTTON4,
            (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut2,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp2);

        hhBmp3 = LoadImage(NULL, "images/image_part_3.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut3 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            455,370,78,78,hwnd, (HMENU) BUTTON5,
            (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut3,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp3);

        hhBmp4 = LoadImage(NULL, "images/image_part_4.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut4 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            455,50,78,78,hwnd, (HMENU) BUTTON6,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut4,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp4);

        hhBmp5 = LoadImage(NULL, "images/image_part_5.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut5 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            455,210,78,78,hwnd, (HMENU) BUTTON7,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut5,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp5);
        //
        hhBmp6 = LoadImage(NULL, "images/image_part_6.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut6 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            615,130,78,78,hwnd, (HMENU) BUTTON8,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut6,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp6);

        hhBmp7 = LoadImage(NULL, "images/image_part_7.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut7 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            695,290,78,78,hwnd, (HMENU) BUTTON9,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut7,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp7);

        hhBmp8 = LoadImage(NULL, "images/image_part_8.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut8 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            695,130,78,78,hwnd, (HMENU) BUTTON10,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut8,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp8);

        hhBmp9 = LoadImage(NULL, "images/image_part_9.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut9 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            535,290,78,78,hwnd, (HMENU) BUTTON11,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut9,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp9);

        hhBmp10 = LoadImage(NULL, "images/image_part_10.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut10 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            695,50,78,78,hwnd, (HMENU) BUTTON12,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut10,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp10);
        //
        hhBmp11 = LoadImage(NULL, "images/image_part_11.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut11 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            615,50,78,78,hwnd, (HMENU) BUTTON13,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut11,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp11);

        hhBmp12 = LoadImage(NULL, "images/image_part_12.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut12 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            535,50,78,78,hwnd, (HMENU) BUTTON14,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut12,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp12);

        hhBmp13 = LoadImage(NULL, "images/image_part_13.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut13 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            775,210,78,78,hwnd, (HMENU) BUTTON15,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut13,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp13);

        hhBmp14 = LoadImage(NULL, "images/image_part_14.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut14 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            455,130,78,78,hwnd, (HMENU) BUTTON16,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut14,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp14);

        hhBmp15 = LoadImage(NULL, "images/image_part_15.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut15 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            615,370,78,78,hwnd, (HMENU) BUTTON17,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut15,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp15);
        //
        hhBmp16 = LoadImage(NULL, "images/image_part_16.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut16 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            535,370,78,78,hwnd, (HMENU) BUTTON18,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut16,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp16);

        hhBmp17 = LoadImage(NULL, "images/image_part_17.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut17 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            535,210,78,78,hwnd, (HMENU) BUTTON19,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut17,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp17);

        hhBmp18 = LoadImage(NULL, "images/image_part_18.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut18 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            695,210,78,78,hwnd, (HMENU) BUTTON20,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut18,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp18);

        hhBmp19 = LoadImage(NULL, "images/image_part_19.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut19 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            535,130,78,78,hwnd, (HMENU) BUTTON21,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut19,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp19);

        hhBmp20 = LoadImage(NULL, "images/image_part_20.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut20 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            775,370,78,78,hwnd, (HMENU) BUTTON22,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut20,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp20);
        //
        hhBmp21 = LoadImage(NULL, "images/image_part_21.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut21 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            775,50,78,78,hwnd, (HMENU) BUTTON23,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut21,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp21);

        hhBmp22 = LoadImage(NULL, "images/image_part_22.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut22 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            775,130,78,78,hwnd, (HMENU) BUTTON24,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut22,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp22);

        hhBmp23 = LoadImage(NULL, "images/image_part_23.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut23 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            615,210,78,78,hwnd, (HMENU) BUTTON25,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut23,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp23);

        hhBmp24 = LoadImage(NULL, "images/image_part_24.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut24 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            775,290,78,78,hwnd, (HMENU) BUTTON26,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut24,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp24);

        hhBmp25 = LoadImage(NULL, "images/image_part_25.bmp", IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
        hBut25 = CreateWindow("BUTTON", TEXT("Test"),WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
            695,370,78,78,hwnd, (HMENU) BUTTON27,
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);
        SendMessageW(hBut25,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hhBmp25);


}

 void test(HWND hwnd){
    MessageBox(hwnd, "444", "Write", MB_OK);
    ShowWindow (hBut4, SW_HIDE);
 }

 void paint(HWND hwnd,int a,int b,int image_id){

    HDC hDC = GetDC(hwnd);

    char *image_n = NULL;
    char *image_name= NULL;
    char szStr[80] = "images/image_part_";
    char number [10];
    itoa(image_id,number,10);
    image_n = lstrcat(szStr, number);
    image_name = lstrcat(image_n, ".bmp");

    HANDLE hBmp = LoadImage(NULL, image_name, IMAGE_BITMAP,0,0, LR_LOADFROMFILE);
    HDC dcmem = CreateCompatibleDC(NULL);
    BITMAP bm;
    GetObject(hBmp, sizeof(bm), &bm);
    SelectObject(dcmem, hBmp);

    BitBlt(hDC,a,b,bm.bmWidth,bm.bmHeight, dcmem,0,0,SRCCOPY);
    DeleteDC(dcmem);

 }



void checkSequence(HWND hwnd, int a){

    HANDLE file;
    BOOL rez;
    DWORD b_written, b_read;

    int difference =0;
    difference = a - previousNumber;

    if(a == 0){
        previousNumber=0;
        faultCounter=0;
    }else{
        faultCounter+=1;

        if(difference != 1){
            RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);

            ShowWindow (hBut1, SW_HIDE);
            ShowWindow (hBut2, SW_HIDE);
            ShowWindow (hBut3, SW_HIDE);
            ShowWindow (hBut4, SW_HIDE);
            ShowWindow (hBut5, SW_HIDE);
            ShowWindow (hBut6, SW_HIDE);
            ShowWindow (hBut7, SW_HIDE);
            ShowWindow (hBut8, SW_HIDE);
            ShowWindow (hBut9, SW_HIDE);
            ShowWindow (hBut10, SW_HIDE);
            ShowWindow (hBut11, SW_HIDE);
            ShowWindow (hBut12, SW_HIDE);
            ShowWindow (hBut13, SW_HIDE);
            ShowWindow (hBut14, SW_HIDE);
            ShowWindow (hBut15, SW_HIDE);
            ShowWindow (hBut16, SW_HIDE);
            ShowWindow (hBut17, SW_HIDE);
            ShowWindow (hBut18, SW_HIDE);
            ShowWindow (hBut19, SW_HIDE);
            ShowWindow (hBut20, SW_HIDE);
            ShowWindow (hBut21, SW_HIDE);
            ShowWindow (hBut22, SW_HIDE);
            ShowWindow (hBut23, SW_HIDE);
            ShowWindow (hBut24, SW_HIDE);
            ShowWindow (hBut25, SW_HIDE);


            char *image_n = NULL;
            char *image_name= NULL;
            char szStr[80] = "Jus suklydote ";
            char number [10];
            itoa(faultCounter,number,10);
            image_n = lstrcat(szStr, number);
            image_name = lstrcat(image_n, " zingsnyje!");
            MessageBox(hwnd, image_n, "Zaidimo pabaiga", MB_OK);
            faultCounter=0;

            //write file
            char szTemp[128];
            char *space = NULL;
            char *player= NULL;
            GetDlgItemText (hwnd, ID_EDITTEXT, szTemp, 128);


            if(szTemp[0] == 0){
                char nameless[80] = "Bevardis ";
                player = lstrcat(nameless, number);
                player = lstrcat(player, "/25");

            }else{
                space = lstrcat(szTemp, " ");
                player = lstrcat(szTemp, number);
                player = lstrcat(player, "/25");
            }



            file = CreateFile("Test_file.txt", FILE_APPEND_DATA, 0, NULL,
                   OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if(file != INVALID_HANDLE_VALUE){
               // LPCSTR text = "Some text written to file ";
                b_written = 0;
                rez = WriteFile(file, player, strlen(player), &b_written, NULL);
                rez = WriteFile(file, "\r\n", strlen("\r\n"), &b_written, NULL);
                //rez = WriteFile(file, text, strlen(text), &b_written, NULL);
                if(rez){
                    //MessageBox(hwnd, "text written", "Write", MB_OK);
                }else{
                     MessageBox(hwnd, "text is not written or written async", "Write", MB_OK);
                }
            CloseHandle(file);
            }

        }


        previousNumber = a;
    }

    if(a == 25){
        MessageBox(hwnd, "Sveikiname, jus laimejote!!", "Pergale", MB_OK);
        previousNumber=0;
        faultCounter=0;

        char szTemp[128];
            char *space = NULL;
            char *player= NULL;
            char number [10];
            GetDlgItemText (hwnd, ID_EDITTEXT, szTemp, 128);


            if(szTemp[0] == 0){
                char nameless[80] = "Bevardis ";
                player = lstrcat(nameless, number);
                player = lstrcat(player, "Laimetojas");

            }else{
                space = lstrcat(szTemp, " ");
                player = lstrcat(szTemp, number);
                player = lstrcat(player, "Laimetojas");
            }



            file = CreateFile("Test_file.txt", FILE_APPEND_DATA, 0, NULL,
                   OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if(file != INVALID_HANDLE_VALUE){
                //LPCSTR text = "Some text written to file ";
                b_written = 0;
                rez = WriteFile(file, player, strlen(player), &b_written, NULL);
                rez = WriteFile(file, "\r\n", strlen("\r\n"), &b_written, NULL);
                //rez = WriteFile(file, text, strlen(text), &b_written, NULL);
                if(rez){
                    //MessageBox(hwnd, "text written", "Write", MB_OK);
                }else{
                     MessageBox(hwnd, "text is not written or written async", "Write", MB_OK);
                }
            CloseHandle(file);
            }


    }


}


BOOL CALLBACK DialogProciadura(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        switch(LOWORD(wParam)){
        case ID_BUTTON:
        HWND hTxt = GetDlgItem(hDlg, ID_EDITTEXT);
        int length = GetWindowTextLength(hTxt);
        LPTSTR buffer = new TCHAR[length+1];
        GetWindowText(hTxt, buffer, length+1);
        SetWindowText(GetParent(hDlg), buffer);
        EndDialog(hDlg, 0);
        return TRUE;
        }

        return TRUE;
    case WM_CLOSE:
        EndDialog(hDlg, 0);
        return TRUE;
    case WM_DESTROY:
        EndDialog(hDlg, 0);
        return TRUE;
    }
    return FALSE;
}

VOID CALLBACK TimerProc(HWND hwnd, UINT msg, UINT id, DWORD cur_time){
    switch(msg){
    case WM_TIMER:
    if (id == TIMER_1){
        KillTimer(hwnd, TIMER_1);
        MessageBox(hwnd, "Timer Procedure killed timer", "Timer", MB_OK);
    }
    break;
    }
}
