// stdafx.h : �i�b�����Y�ɤ��]�t�зǪ��t�� Include �ɡA
// �άO�g�`�ϥΫo�ܤ��ܧ�
// �M�ױM�� Include �ɮ�

#pragma once

#ifndef STRICT
#define STRICT
#endif

// �p�G�z�������u����������x�A�Эק�U�C�w�q�C
// �Ѧ� MSDN ���o���P���x�����Ȫ��̷s��T�C
#ifndef WINVER				// ���\�ϥ� Windows XP (�t) �H�᪩�����S�w�\��C
#define WINVER 0x0501		// �N���ܧ󬰰w�� Windows ��L�������A��ȡC
#endif

#ifndef _WIN32_WINNT		// ���\�ϥ� Windows XP (�t) �H�᪩�����S�w�\��C
#define _WIN32_WINNT 0x0501	// �N���ܧ󬰰w�� Windows ��L�������A��ȡC
#endif						

#ifndef _WIN32_WINDOWS		// ���\�ϥ� Windows 98 (�t) �H�᪩�����S�w�\��C
#define _WIN32_WINDOWS 0x0410 // �N���ܧ󬰰w�� Windows Me (�t) �H�᪩�����A��ȡC
#endif

#ifndef _WIN32_IE			// ���\�ϥ� IE 6.0 (�t) �H�᪩�����S�w�\��C
#define _WIN32_IE 0x0600	// �N���ܧ󬰰w�� IE ��L�������A��ȡC
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ���T�w�q������ CString �غc�禡


#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>

using namespace ATL;