========================================================================
    ACTIVE TEMPLATE LIBRARY：NfcCtrl 專案概觀
========================================================================

AppWizard 已為您建立了這個 NfcCtrl 專案，
做為您撰寫動態連結程式庫 (DLL) 的起點。


這個檔案包含一份摘要，
簡要說明構成您的專案的所有檔案，它們個別的內容。

NfcCtrl.vcproj
    這是使用應用程式精靈所產生之 VC++ 專案的主要專案檔。 
    它含有產生該檔案之 Visual C++ 的版本資訊，以及有關使
    用應用程式精靈所選取之平台、組態和專案功能的資訊。

NfcCtrl.idl
    這個檔案會包含您專案中所定義之型別程式庫、介面
    和 co-classes 的 IDL 定義。
    這個檔案將會由 MIDL 編譯器處理以產生：
	C++ 介面定義和 GUID 宣告 (NfcCtrl.h)
	GUID 定義                (NfcCtrl_i.c)
	型別程式庫               (NfcCtrl.tlb)
	封送處理程式碼           (NfcCtrl_p.c 和 dlldata.c)

NfcCtrl.h
    這個檔案含有在 NfcCtrl.idl 中所定義項目的
    C++ 介面定義和 GUID 宣告。它將會由 MIDL 在編譯期間重新產生。

NfcCtrl.cpp
    這個檔案含有您 DLL 匯出的物件對應和實作。

NfcCtrl.rc
    這是程式所用的所有 Microsoft Windows 
    資源的列表。

NfcCtrl.def
    這個模組定義檔為連結器提供了有關您 DLL 所需之
    匯出的資訊。它包含下列項目的匯出：
        DllGetClassObject  
        DllCanUnloadNow    
        GetProxyDllInfo    
        DllRegisterServer	
        DllUnregisterServer

/////////////////////////////////////////////////////////////////////////////
其他標準檔案:

StdAfx.h、StdAfx.cpp
    這些檔案是用來建置名為 NfcCtrl.pch 的先行編譯標頭 (PCH) 檔，
    以及名為 StdAfx.obj 的先行編譯型別檔。

Resource.h
    這是定義資源 ID 的標準標頭檔。

/////////////////////////////////////////////////////////////////////////////
Proxy/Stub DLL 專案和模組定義檔：

NfcCtrlps.vcproj
    這個檔案是在必要時用來建置 Proxy/Stub DLL 的專案檔。
	主要專案中的 IDL 檔必須至少包含一個介面，而且您必須
	先編譯 IDL 檔才能建置 Proxy/Stub DLL。	這個處理序會產生
	建置 Proxy/Stub DLL 所需的 dlldata.c、NfcCtrl_i.c 和
	NfcCtrl_p.c。

NfcCtrlps.def
    這個模組定義檔為連結器提供了有關 Proxy/Stub 所需之
    匯出的資訊。

/////////////////////////////////////////////////////////////////////////////
