InfoThink IT-100MU Contactless Reader SDK V1.7.5 版 目錄說明 2014/12/16

-doc
 - InfoThink WinNfc API v1.7x.pdf: InfoThink NFC 讀卡機 軟體介面開發 API 說明文件
 - InfoThink WinNfc API v1.7x: InfoThink NFC 讀卡機軟體介面開發文件
 - MIFARE Classic 1K/4K:    Mifare 1K/4K 卡片規格文件
 - MIFARE Ultralight:       MIFARE Ultralight 卡片規格文件
 - ISOIEC 14443-4:          ISO14443-4規格文件


-driver 請確定讀卡機背後銀色貼紙上的型號, 根據型號來安裝驅動程式。

 - Model: IT-100MU
   setup32.bat: Windows 32 位元 driver: 適用 WIN2000/WINXP/WIN2003/Vista/WIN 7/WIN 8 32 位元作業系統。
   setup64.bat: Windows 64 位元 driver: 適用 WINXP/WIN2003/Vista/WIN 7 64 位元作業系統。
   

 - Model: IT-100MU(R) / IT-101MU
   setup.exe:  適用 WIN2000/WINXP/WIN2003/Vista/WIN 7/WIN 8 32,64 位元作業系統。

 -SAM reader: 若要使用內部SAM 卡插槽可安裝此dirver, 安裝後可看到兩台 PCSC 讀卡機, 讀卡機名稱如下:
  Generic Usb Dual-Slot SmartCard Reader 0: 大卡插槽的讀卡機
  Generic Usb Dual-Slot SmartCard Reader 1: SAM卡插槽的讀卡機

-example
 - vbWinNfc.vs2008.zip: VB 整合範例 (VS2008)
 - vbWinNfc.vs2010.zip: VB 整合範例 (VS2010)
 - vsWinNfc.vs2010.zip: C# 整合範例 (VS2010)
 - WinNfcTest.zip: VC範例 (VS2008), 裡面有三個測試範例:
   - test_LEDAndBuzzer(): IT-100MU讀卡機 LED燈和 Buzzer測試範例
   - Test_Mifare(): Mifare卡測試範例, SDK附三張
   - Test_ISO1443(): ISO1443卡片測試範例, 可使用 ETC卡來測試
 - NfcCtrl.zip: ActiveX 範例 (VS2008), 需搭配 WTL開發,  ZIP檔解開後 cab目錄下有網頁範例 Mifare.htm

-tool
 -NfcCode: NfcCode 感應卡應用程式, 嗶一下! 自動讀取悠遊卡卡號(Mifare卡通用), 可取代條碼方式之會員卡機制。

-library
 -dll: WinNfc Library, IT-100MU 讀卡機 非接觸介面軟體整合模組
 -vb: Virual Basic 模組檔, 內容為 WinNfc.dll 函式宣告方式
 -c#: Virual CSharp 模組檔, 內容為 WinNfc.dll 函式宣告方式
 -vc: Virual C/C++ header file(*.h); Dynamic link library(*.lib)
 