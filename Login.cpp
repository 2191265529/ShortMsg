// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ShortMsg.h"
#include "Login.h"
#include "afxdialogex.h"


// CLogin �Ի���

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogin::IDD, pParent)
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(ID_LOGIN, &CLogin::OnBnClickedLogin)
END_MESSAGE_MAP()


// CLogin ��Ϣ�������

void CLogin::OnBnClickedLogin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	/*CString username,password;
	this->GetDlgItemTextW(IDC_EDIT_USER, username);
	this->GetDlgItemTextW(IDC_EDIT_PWD, password);
	if (username == _T("tianlu") && password == _T("123!!")){
		OnOK();
	}
	else
	{
		MessageBox(_T("username or password false!!"));
	}*/
	OnOK();
}
