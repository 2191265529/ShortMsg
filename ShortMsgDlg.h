
// ShortMsgDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CShortMsgDlg �Ի���
class CShortMsgDlg : public CDialogEx
{
// ����
public:
	CShortMsgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ShortMsg_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CListCtrl m_lst;
	afx_msg void OnBnClickedButtonOpenfile();
};
