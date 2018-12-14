// Mifare.cpp : CMifare ªº¹ê§@

#include "stdafx.h"
#include "Mifare.h"
#include "SelectCardDlg.h"
#include "WinNfc.h"


LONG TransfereError(LONG err)
{
	//NFCSTATUS_NO_DEVICE_FOUND
	if (err == NFC_E_NO_READERS_AVAILABLE)
		return ERR_READER_NOT_FOUND;

	return err;
}

STDMETHODIMP CMifare::ReadCard(LONG* Return)
{
	LONG rc = 0;

	NFCCONTEXT phCtx = NULL;

	rc = NfcEstablishContext(0, 0, 0, &phCtx);
	if (rc)
	{
		 NfcReleaseContext(phCtx);
		*Return = rc;
		return S_OK;
	}

	rc = NfcConnect(phCtx, NULL, 0);
	if (rc)
	{
		 NfcReleaseContext(phCtx);
		*Return = rc;
		return S_OK;
	}

	NfcLEDControl(phCtx, LED_OFF);

	CSelectCardDlg dlg;
	dlg.m_phCtx = phCtx;
	char szCardID[32] = {0};

	dlg.m_CardID = szCardID;

	dlg.DoModal();

	rc = dlg.m_Rc;

	if (rc)
	{
		NfcLEDControl(phCtx, LED_BLUE);
		*Return = rc;
	} else {
		*Return = 0;
		NfcLEDControl(phCtx, LED_RED);
	}

	m_CardID  = szCardID;
	//::MessageBox(NULL, szCardID, "test", MB_OK);

	NfcDisconnect(phCtx, 0);
	NfcReleaseContext(phCtx);

	return S_OK;
}

STDMETHODIMP CMifare::get_CardID(BSTR* pVal)
{
	m_CardID.CopyTo(pVal);

	return S_OK;
}