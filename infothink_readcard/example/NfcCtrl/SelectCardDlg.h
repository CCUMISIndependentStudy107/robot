// SelectCardDlg.h: interface for the CSelectCardDlg class.
//
//////////////////////////////////////////////////////////////////////
#include <atlapp.h>
#include <atlctrls.h>
#include <atlmisc.h>
#include "WinNfc.h"

#if !defined(AFX_SelectCardDlg_H__024166AB_9B78_4515_85CD_19181F6E38AC__INCLUDED_)
#define AFX_SelectCardDlg_H__024166AB_9B78_4515_85CD_19181F6E38AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSelectCardDlg : public CDialogImpl<CSelectCardDlg>
 
{
public:
	LONG m_Rc;
	int m_Count;
	HBITMAP m_hBmp[6];

	NFCCONTEXT m_phCtx;
	char* m_CardID;

	CSelectCardDlg();
	virtual ~CSelectCardDlg();
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnEraseBkgnd(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	//LRESULT OnClickedDview(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	//LRESULT OnDblclkList(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	int ProcessCard();

	enum { IDD = IDD_SELECT };
 
    BEGIN_MSG_MAP(CSelectCardDlg)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
		MESSAGE_HANDLER(WM_TIMER, OnTimer)
//        COMMAND_ID_HANDLER(IDOK, OnOKCancel)
  //      COMMAND_ID_HANDLER(IDCANCEL, OnOKCancel)
//        COMMAND_HANDLER(IDVIEW, BN_CLICKED, OnClickedDview)
        COMMAND_HANDLER(IDOK, BN_CLICKED, OnOK)
        COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnCancel)


  //      NOTIFY_HANDLER(IDC_LIST, NM_DBLCLK, OnDblclkList)
    END_MSG_MAP()

};

#endif // !defined(AFX_SelectCardDlg_H__024166AB_9B78_4515_85CD_19181F6E38AC__INCLUDED_)
