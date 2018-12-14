

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Apr 22 14:37:14 2011
 */
/* Compiler settings for .\NfcCtrl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __NfcCtrl_h__
#define __NfcCtrl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMifare_FWD_DEFINED__
#define __IMifare_FWD_DEFINED__
typedef interface IMifare IMifare;
#endif 	/* __IMifare_FWD_DEFINED__ */


#ifndef __Mifare_FWD_DEFINED__
#define __Mifare_FWD_DEFINED__

#ifdef __cplusplus
typedef class Mifare Mifare;
#else
typedef struct Mifare Mifare;
#endif /* __cplusplus */

#endif 	/* __Mifare_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMifare_INTERFACE_DEFINED__
#define __IMifare_INTERFACE_DEFINED__

/* interface IMifare */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMifare;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("013B1394-97CA-4646-AFD0-16467F1F0204")
    IMifare : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadCard( 
            /* [retval][out] */ LONG *Return) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CardID( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMifareVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMifare * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMifare * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMifare * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMifare * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMifare * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMifare * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMifare * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadCard )( 
            IMifare * This,
            /* [retval][out] */ LONG *Return);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CardID )( 
            IMifare * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IMifareVtbl;

    interface IMifare
    {
        CONST_VTBL struct IMifareVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMifare_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMifare_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMifare_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMifare_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMifare_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMifare_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMifare_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMifare_ReadCard(This,Return)	\
    ( (This)->lpVtbl -> ReadCard(This,Return) ) 

#define IMifare_get_CardID(This,pVal)	\
    ( (This)->lpVtbl -> get_CardID(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMifare_INTERFACE_DEFINED__ */



#ifndef __NfcCtrlLib_LIBRARY_DEFINED__
#define __NfcCtrlLib_LIBRARY_DEFINED__

/* library NfcCtrlLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_NfcCtrlLib;

EXTERN_C const CLSID CLSID_Mifare;

#ifdef __cplusplus

class DECLSPEC_UUID("A3E680E6-5D6F-460A-930A-D422A0F0379D")
Mifare;
#endif
#endif /* __NfcCtrlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


