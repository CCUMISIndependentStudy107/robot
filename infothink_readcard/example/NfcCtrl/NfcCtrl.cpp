// NfcCtrl.cpp : DLL �ץX����@�C


#include "stdafx.h"
#include "resource.h"
#include "NfcCtrl.h"


class CNfcCtrlModule : public CAtlDllModuleT< CNfcCtrlModule >
{
public :
	DECLARE_LIBID(LIBID_NfcCtrlLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_NFCCTRL, "{774507EC-695C-4373-829E-9D8ECC9C96C4}")
};

CNfcCtrlModule _AtlModule;


#ifdef _MANAGED
#pragma managed(push, off)
#endif

// DLL �i�J�I
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}

#ifdef _MANAGED
#pragma managed(pop)
#endif




// �ΨӧP�_ DLL �O�_�i�Q OLE ����
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// �Ǧ^ Class Factory �H�إߩҭn�D���O������
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - �N���إ[�J��t�εn��
STDAPI DllRegisterServer(void)
{
    // �n������BTypelib �M�Ҧ� Typelib ��������
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - �q�t�εn����������
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}

