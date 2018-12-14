using System;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Text;

class WinNfc
{
    [DllImport("WinNfc.dll")]
    public static extern int NfcEstablishContext(int Scope, int Rev1, int Rev2, ref int Context);

    [DllImport("WinNfc.dll")]
    public static extern int NfcConnect(int Context, [MarshalAs(UnmanagedType.LPStr)] StringBuilder ReaderName, int ShareMode);

    [DllImport("WinNfc.dll")]
    public static extern int NfcReleaseContext(int Context);

    [DllImport("WinNfc.dll")]
    public static extern int NfcDisconnect(int Context, int Disposition);

    [DllImport("WinNfc.dll")]
    public static extern int NfcSelectCard(int Context, CardTypeEnum CardType, ref byte InitData, int InitDataLen);

    [DllImport("WinNfc.dll")]
    public static extern int NfcDeSelectCard(int Context);


    [DllImport("WinNfc.dll")]
    public static extern int NfcLEDControl(int Context, LEDEnum State);

    [DllImport("WinNfc.dll")]
    public static extern int NfcBuzzerControl(int Context, BuzzerEnum State);

    [DllImport("WinNfc.dll")]
    public static extern int NfcGetParameter(int Context, int Type, [MarshalAs(UnmanagedType.LPStr)] StringBuilder Value, ref int Length);

    public static int NFC_PARAMETER_READER_NAME = 0x00000001;

    //[Flags]
    public enum ErrorEnum: uint
    {
        內部錯誤 = 0x80100001,
        傳入的Handle值錯誤 = 0x80100003,
        傳入參數錯誤 = 0x80100004,
        記憶體不足 = 0x80100006,
        無法辨識的讀卡機 = 0x80100009,
        函式逾時 = 0x8010000A,
        讀卡機已被占用 = 0x8010000B,
        找不到卡片 = 0x8010000C,
        無法辨識的卡片 = 0x8010000D,
        傳入參數值錯誤 = 0x80100011,
        未知型錯誤 = 0x80100014,
        目前無法存取讀卡機 = 0x80100017,
        不支援的讀卡機 = 0x8010001A,
        不支援的卡片 = 0x8010001C,
        找不到讀卡機 = 0x8010002E,
        Mifare金鑰驗證失敗 = 0x80000014
    };


    public enum CardTypeEnum
    {
        ACTIVE_106 = 0x1,
        ACTIVE_212 = 0x2,
        ACTIVE_424 = 0x4,
        PASSIVE_106 = 0x8,
        PASSIVE_212 = 0x10,
        PASSIVE_424 = 0x20,
        MIFARE = 0x40,
        ISO14443_4A = 0x80,
        FELICA_212 = 0x100,
        FELICA_424 = 0x200,
        ISO14443_4B = 0x400,
        JEWEL = 0x800
    }

    public enum LEDEnum
    {
        全暗 = 0x00,
        紅燈 = 0x01,
        藍燈 = 0x02,
        全亮 = 0x03
    }

    public enum BuzzerEnum
    {
        開啟 = 0x00,
        關閉 = 0x08
    }


    public static void ShowError(int rc)
    {
       string sMsg = System.Enum.GetName(typeof(ErrorEnum), (uint)rc);
       if (sMsg == null)
           sMsg = "內部錯誤:" + String.Format("0x{0:X}", rc);
       MessageBox.Show(sMsg, "WinNfc Error" , MessageBoxButtons.OK, MessageBoxIcon.Error);
    }
}

class ISO14443
{
    [DllImport("WinNfc.dll", EntryPoint = "ISO14443_SendAPDU")]
    public static extern int SendAPDU(int Context, byte[] InData, int InLen, byte[] OutData, ref int OutLen);
}

class Mifare
{

    public enum KeyEnum
    {
        KeyA = 0x01,
        KeyB = 0x02
    }

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_GetCardID")]
    public static extern int GetCardID(int Context, [MarshalAs(UnmanagedType.LPStr)] StringBuilder ID);

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_KeyAuthority")]
    public static extern int KeyAuthority(int Context, int Block, KeyEnum KeyType, byte[] Key);

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_ReadBlock")]
    public static extern int ReadBlock(int Context, int Block, byte[] Data, ref int DataLen);

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_WriteBlock")]
    public static extern int WriteBlock(int Context, int Block, byte[] Data, int DataLen);

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_ReadValue")]
    public static extern int ReadValue(int Context, int Block, ref int Value);

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_WriteValue")]
    public static extern int WriteValue(int Context, int Block, int Value);

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_IncreaseValue")]
    public static extern int IncreaseValue(int Context, int Block, int Value);

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_DecreaseValue")]
    public static extern int DecreaseValue(int Context, int Block, int Value);

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_TransferValue")]
    public static extern int TransferValue(int Context, int Block);

    [DllImport("WinNfc.dll", EntryPoint = "Mifare_RestoreValue")]
    public static extern int RestoreValue(int Context, int Block);

}


