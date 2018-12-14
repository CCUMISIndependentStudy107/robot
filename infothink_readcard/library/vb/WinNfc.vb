Module WinNfc

    Public Enum ErrorEnum
        內部錯誤 = &H80100001
        傳入的Handle值錯誤 = &H80100003
        傳入參數錯誤 = &H80100004
        記憶體不足 = &H80100006
        無法辨識的讀卡機 = &H80100009
        函式逾時 = &H8010000A
        讀卡機已被占用 = &H8010000B
        找不到卡片 = &H8010000C
        無法辨識的卡片 = &H8010000D
        傳入參數值錯誤 = &H80100011
        未知型錯誤 = &H80100014
        目前無法存取讀卡機 = &H80100017
        不支援的讀卡機 = &H8010001A
        不支援的卡片 = &H8010001C
        找不到讀卡機 = &H8010002E
        Mifare金鑰驗證失敗 = &H80000014
    End Enum


    Public Enum CardTypeEnum
        ACTIVE_106 = &H1
        ACTIVE_212 = &H2
        ACTIVE_424 = &H4
        PASSIVE_106 = &H8
        PASSIVE_212 = &H10
        PASSIVE_424 = &H20
        MIFARE = &H40
        ISO14443_4A = &H80
        FELICA_212 = &H100
        FELICA_424 = &H200
        ISO14443_4B = &H400
        JEWEL = &H800
    End Enum


    Public Enum LEDEnum
        全暗 = &H0
        紅燈 = &H1
        藍燈 = &H2
        全亮 = &H3
    End Enum

    Public Enum BuzzerEnum
        開啟 = &H0
        關閉 = &H8
    End Enum

    '*************************************************************************************************************
    '	Basic functions
    '**************************************************************************************************************
    Declare Ansi Function NfcEstablishContext Lib "WinNfc.dll" Alias "NfcEstablishContext" ( _
    ByVal Scope As Integer, _
    ByVal Rev1 As Integer, _
    ByVal Rev2 As Integer, _
    ByRef Context As Integer) _
    As Integer

    Declare Ansi Function NfcReleaseContext Lib "WinNfc.dll" Alias "NfcReleaseContext" ( _
    ByVal Context As Integer) _
    As Integer


    Declare Ansi Function NfcConnect Lib "WinNfc.dll" Alias "NfcConnect" ( _
    ByVal Context As Integer, _
    ByVal ReaderName As String, _
    ByVal ShareMode As Integer) _
    As Integer

    Declare Ansi Function NfcDisconnect Lib "WinNfc.dll" Alias "NfcDisconnect" ( _
    ByVal Context As Integer, _
    ByVal Disposition As Integer) _
    As Integer


    Declare Ansi Function NfcSelectCard Lib "WinNfc.dll" Alias "NfcSelectCard" ( _
    ByVal Context As Integer, _
    ByVal CardType As Integer, _
    ByVal InitData As String, _
    ByVal InitDataLen As Integer) _
    As Integer

    Declare Ansi Function NfcDeSelectCard Lib "WinNfc.dll" Alias "NfcDeSelectCard" ( _
    ByVal Context As Integer) _
    As Integer

    '*************************************************************************************************************
    '	LED And Buzzer Control functions
    '**************************************************************************************************************
    Declare Ansi Function NfcLEDControl Lib "WinNfc.dll" Alias "NfcLEDControl" ( _
    ByVal Context As Integer, _
    ByVal State As LEDEnum) _
    As Integer

    Declare Ansi Function NfcBuzzerControl Lib "WinNfc.dll" Alias "NfcBuzzerControl" ( _
    ByVal Context As Integer, _
    ByVal State As BuzzerEnum) _
    As Integer


    Declare Ansi Function NfcGetParameter Lib "WinNfc.dll" Alias "NfcGetParameter" ( _
    ByVal Context As Integer, _
    ByVal Type As Integer, _
    ByVal Value As String, _
    ByRef Length As Integer _
    ) _
    As Integer

    Public NFC_PARAMETER_READER_NAME As Integer = &H1


    '*************************************************************************************************************
    '	ShowError
    '**************************************************************************************************************
    Public Sub ShowError(ByVal nRc As Integer)
        Dim nError As ErrorEnum = nRc
        Dim sMsg As String = nError.ToString

        If sMsg = CStr(nRc) Then
            sMsg = "內部錯誤:" + String.Format("0x{0:X}", nRc)
        End If

        MsgBox(sMsg, MsgBoxStyle.Critical)

    End Sub

End Module

'*************************************************************************************************************
'	ISO14443-4 A/B functions 
'**************************************************************************************************************
Module ISO14443

    Declare Ansi Function SendAPDU Lib "WinNfc.dll" Alias "ISO14443_SendAPDU" ( _
    ByVal Context As Integer, _
    ByVal InData As Byte(), _
    ByVal InLen As Integer, _
    ByVal OutData As Byte(), _
    ByRef OutLen As Integer) _
    As Integer

End Module


'*************************************************************************************************************
'	Mifare functions 
'**************************************************************************************************************
Module Mifare

    Public Enum KeyEnum
        KeyA = &H1
        KeyB = &H2
    End Enum

    Declare Ansi Function GetCardID Lib "WinNfc.dll" Alias "Mifare_GetCardID" ( _
    ByVal Context As Integer, _
    ByVal ID As String) _
    As Integer

    Declare Ansi Function KeyAuthority Lib "WinNfc.dll" Alias "Mifare_KeyAuthority" ( _
    ByVal Context As Integer, _
    ByVal Block As Integer, _
    ByVal KeyType As KeyEnum, _
    ByVal Key As Byte()) _
    As Integer

    Declare Ansi Function ReadBlock Lib "WinNfc.dll" Alias "Mifare_ReadBlock" ( _
    ByVal Context As Integer, _
    ByVal Block As Integer, _
    ByVal Data As Byte(), _
    ByRef DataLen As Integer) _
    As Integer

    Declare Ansi Function WriteBlock Lib "WinNfc.dll" Alias "Mifare_WriteBlock" ( _
    ByVal Context As Integer, _
    ByVal Block As Integer, _
    ByVal Data As Byte(), _
    ByVal DataLen As Integer) _
    As Integer

    Declare Ansi Function ReadValue Lib "WinNfc.dll" Alias "Mifare_ReadValue" ( _
    ByVal Context As Integer, _
    ByVal Block As Integer, _
    ByRef Value As Integer) _
    As Integer

    Declare Ansi Function WriteValue Lib "WinNfc.dll" Alias "Mifare_WriteValue" ( _
    ByVal Context As Integer, _
    ByVal Block As Integer, _
    ByVal Value As Integer) _
    As Integer

    Declare Ansi Function IncreaseValue Lib "WinNfc.dll" Alias "Mifare_IncreaseValue" ( _
    ByVal Context As Integer, _
    ByVal Block As Integer, _
    ByVal Value As Integer) _
    As Integer

    Declare Ansi Function DecreaseValue Lib "WinNfc.dll" Alias "Mifare_DecreaseValue" ( _
    ByVal Context As Integer, _
    ByVal Block As Integer, _
    ByVal Value As Integer) _
    As Integer

    Declare Ansi Function TransferValue Lib "WinNfc.dll" Alias "Mifare_TransferValue" ( _
    ByVal Context As Integer, _
    ByVal Block As Integer) _
    As Integer

    Declare Ansi Function RestoreValue Lib "WinNfc.dll" Alias "Mifare_RestoreValue" ( _
    ByVal Context As Integer, _
    ByVal Block As Integer) _
    As Integer

End Module
