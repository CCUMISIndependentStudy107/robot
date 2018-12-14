// Mifare.h : CMifare ���ŧi

#pragma once
#include "resource.h"       // �D�n�Ÿ�
#include "NfcCtrl.h"
#include <atlctl.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ���x�W�����T�䴩��@����� COM ����A�Ҧp Windows Mobile ���x�S���]�t���㪺 DCOM �䴩�C�Щw�q _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA �ӱj�� ATL �䴩�إ߳�@����� COM ���󪺹�@�A�H�Τ��\�ϥΨ��@����� COM �����@�C�z�� rgs �ɤ���������ҫ��w�]�w�� 'Free'�A�]���o�O�D DCOM Windows CE ���x���ߤ@�䴩��������ҫ��C"
#endif



// CMifare

class ATL_NO_VTABLE CMifare :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMifare, &CLSID_Mifare>,
	public IDispatchImpl<IMifare, &IID_IMifare, &LIBID_NfcCtrlLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<CMifare, INTERFACESAFE_FOR_UNTRUSTED_CALLER|INTERFACESAFE_FOR_UNTRUSTED_DATA> // ATL's version of IObjectSafety
{
public:
	CMifare()
	{
		m_CardID = "";

	}

DECLARE_REGISTRY_RESOURCEID(IDR_MIFARE)


BEGIN_COM_MAP(CMifare)
	COM_INTERFACE_ENTRY(IMifare)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectSafety) // Tie IObjectSafety to this COM map
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(GetInterfaceSafetyOptions)(REFIID riid,
									  DWORD *pdwSupportedOptions,
									  DWORD *pdwEnabledOptions)
	{
		ATLTRACE(_T("CObjectSafetyImpl::GetInterfaceSafetyOptions\n"));
		if (!pdwSupportedOptions || !pdwEnabledOptions)
		   return E_FAIL;

		LPUNKNOWN pUnk;
		if (_InternalQueryInterface (riid, (void**)&pUnk) == E_NOINTERFACE) {
		   // Our object doesn't even support this interface.
		   return E_NOINTERFACE;
		}else{
		   // Cleanup after ourselves.
		   pUnk->Release();
		   pUnk = NULL;
		}

		if (riid == IID_IDispatch) {
		   // IDispatch is an interface used for scripting. If your
		   // control supports other IDispatch or Dual interfaces, you
		   // may decide to add them here as well. Client wants to know
		   // if object is safe for scripting. Only indicate safe for
		   // scripting when the interface is safe.
		   *pdwSupportedOptions = INTERFACESAFE_FOR_UNTRUSTED_CALLER;
		   *pdwEnabledOptions = m_dwCurrentSafety &
								INTERFACESAFE_FOR_UNTRUSTED_CALLER;
		   return S_OK;
		}else if ((riid == IID_IPersistStreamInit) ||
				  (riid == IID_IPersistStorage)) {
		   // IID_IPersistStreamInit and IID_IPersistStorage are
		   // interfaces used for Initialization. If your control
		   // supports other Persistence interfaces, you may decide to
		   // add them here as well. Client wants to know if object is
		   // safe for initializing. Only indicate safe for initializing
		   // when the interface is safe.
		   *pdwSupportedOptions = INTERFACESAFE_FOR_UNTRUSTED_DATA;
		   *pdwEnabledOptions = m_dwCurrentSafety &
								INTERFACESAFE_FOR_UNTRUSTED_DATA;
		   return S_OK;
		}else{
		   // We are saying that no other interfaces in this control are
		   // safe for initializing or scripting.
		   *pdwSupportedOptions = 0;
		   *pdwEnabledOptions = 0;
		   return E_FAIL;
		}
	}

	STDMETHOD(SetInterfaceSafetyOptions)(REFIID riid,
									  DWORD dwOptionSetMask,
									  DWORD dwEnabledOptions)
	{
		ATLTRACE(_T("CObjectSafetyImpl::SetInterfaceSafetyOptions\n"));

		if (!dwOptionSetMask && !dwEnabledOptions) return E_FAIL;
		LPUNKNOWN pUnk;

		if (_InternalQueryInterface (riid, (void**)&pUnk) == E_NOINTERFACE) {
		   // Our object doesn't even support this interface.
		   return E_NOINTERFACE;
		}else{
		   // Cleanup after ourselves.
		   pUnk->Release();
		   pUnk = NULL;
		}

		// Store our current safety level to return in
		// GetInterfaceSafetyOptions
		m_dwCurrentSafety |= dwEnabledOptions & dwOptionSetMask;
		if ((riid == IID_IDispatch) &&
			(m_dwCurrentSafety & INTERFACESAFE_FOR_UNTRUSTED_CALLER)) {
		   // Client wants us to disable any functionality that would
		   // make the control unsafe for scripting. The same applies to
		   // any other IDispatch or Dual interfaces your control may
		   // support. Because our control is safe for scripting by
		   // default we just return S_OK.
		   return S_OK;
		}else if (((riid == IID_IPersistStreamInit) ||
				   (riid == IID_IPersistStorage)) &&
				  (m_dwCurrentSafety & INTERFACESAFE_FOR_UNTRUSTED_DATA)) {
		   // Client wants us to make the control safe for initializing
		   // from persistent data. For these interfaces, this control
		   // is safe so we return S_OK. For Any interfaces that are not
		   // safe, we would return E_FAIL.
		   return S_OK;
		}else{
		   // This control doesn't allow Initialization or Scripting
		   // from any other interfaces so return E_FAIL.
		   return E_FAIL;
		}
	}

	BOOL IsInvokeAllowed(DISPID dispid)
	{
		return TRUE;
	}

private:
	CComBSTR m_CardID;
public:
	STDMETHOD(ReadCard)(LONG* Return);
	STDMETHOD(get_CardID)(BSTR* pVal);
};

OBJECT_ENTRY_AUTO(__uuidof(Mifare), CMifare)
