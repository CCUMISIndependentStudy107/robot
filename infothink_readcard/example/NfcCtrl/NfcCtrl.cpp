// NfcCtrl.cpp : DLL 匯出的實作。


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

// DLL 進入點
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}

#ifdef _MANAGED
#pragma managed(pop)
#endif




// 用來判斷 DLL 是否可被 OLE 卸載
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// 傳回 Class Factory 以建立所要求型別的物件
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - 將項目加入到系統登錄
STDAPI DllRegisterServer(void)
{
    // 登錄物件、Typelib 和所有 Typelib 中的介面
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - 從系統登錄移除項目
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}

