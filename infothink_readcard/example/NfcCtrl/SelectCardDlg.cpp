// SelectCardDlg.cpp: implementation of the CSelectCardDlg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Resource.h"
#include "SelectCardDlg.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CSelectCardDlg::CSelectCardDlg()
{
	m_Rc = -1;
	m_Count = 3;
	m_CardID = NULL;
	m_phCtx = NULL;
}

CSelectCardDlg::~CSelectCardDlg()
{

}

LRESULT CSelectCardDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{	
	//除去 window 外框	
	LONG lStyle = GetWindowLong(GWL_STYLE);
	lStyle &= ~WS_CAPTION;
	lStyle = SetWindowLong(GWL_STYLE, lStyle);

	lStyle = GetWindowLong(GWL_EXSTYLE);
	lStyle &= ~WS_EX_DLGMODALFRAME;
	lStyle = SetWindowLong(GWL_EXSTYLE, lStyle);


	m_hBmp[0] = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_WAVE_1));
	m_hBmp[1] = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_WAVE_2));
	m_hBmp[2] = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_WAVE_3));
	m_hBmp[3] = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_WAVE_4));

	BITMAP bm; 
	GetObject(m_hBmp[0], sizeof(bm), &bm);

	//resize window
	int nScreenWidth = bm.bmWidth; /*rc.right - rc.left;*/
	int nScreenHeight = bm.bmHeight; /*rc.bottom - rc.top;*/
	
	SetWindowPos(NULL, 0, 0, nScreenWidth, nScreenHeight , SWP_NOMOVE); 

	//m_hBmp[1] = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_BG0 + 1));
	//m_hBmp[2] = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_BG0 + 2));
	//m_hBmp[3] = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_BG0 + 3));
	//m_hBmp[4] = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_BG0 + 4));
	//m_hBmp[5] = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_BG0 + 5));

    CenterWindow();
	
	SetTimer(1, 300);

    return TRUE;    // let the system set the focus
}


LRESULT CSelectCardDlg::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{

	return TRUE;  // we painted the background
}

LRESULT CSelectCardDlg::OnEraseBkgnd(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	BITMAP bm;
	CPaintDC dc(m_hWnd);

	int nIndex = m_Count % 4;

	CDC memDC;
	if (memDC.CreateCompatibleDC(dc.m_hDC))
	{
	//	CSize size;
		GetObject(m_hBmp[nIndex], sizeof(bm), &bm);
		HBITMAP hBmpOld = memDC.SelectBitmap(m_hBmp[nIndex]);
		if(hBmpOld) {
			dc.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);
			//dc.BitBlt(0, 0, SCALEX(bm.bmWidth), SCALEY(bm.bmHeight), memDC, 0, 0, SRCCOPY);
			//dc.StretchBlt(0, 0, SCALEX(bm.bmWidth), SCALEY(bm.bmHeight), memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
			memDC.SelectBitmap(hBmpOld);
		}
	}

	return TRUE;  // we painted the background
}

int CSelectCardDlg::ProcessCard()
{
	int nRetry = 0;

	DWORD dwCard = 1;
	m_Rc = NfcSelectCard(m_phCtx, NFC_CARDTYPE_MIFARE, NULL, 0);

	if (m_Rc == 0 && dwCard > 0) {
		
		nRetry ++;

		NfcBuzzerControl(m_phCtx, BUZZER_ON);

		m_Rc = Mifare_GetCardID(m_phCtx, m_CardID);
		if (m_Rc) {
			NfcDeSelectCard(m_phCtx);
			return 0;
		}

		Sleep(50);
		NfcBuzzerControl(m_phCtx, BUZZER_OFF);
		EndDialog(0);

		/*
		
		這裡可以加上資料讀寫的程式碼
		ex: 例如加值 或 扣款功能

		*/

	}

	return 0;	
}



LRESULT CSelectCardDlg::OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{

	//	m_hBmp = LoadBitmap(ModuleHelper::GetResourceInstance(), MAKEINTRESOURCE(IDB_BG0 + m_Count));

	KillTimer(1);
	RedrawWindow();

	ProcessCard();

	m_Count++;
	SetTimer(1, 400);
	return 0;
}

LRESULT CSelectCardDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{

	m_Rc = 0;
    EndDialog(wID);
	return 0;
}


LRESULT CSelectCardDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    EndDialog(wID);
	m_Rc = ERR_CANCEL_PAYMENT;
	return 0;
}

LRESULT CSelectCardDlg::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    EndDialog(IDCANCEL);
    return 0;
}
