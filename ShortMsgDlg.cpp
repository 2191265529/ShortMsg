
// ShortMsgDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ShortMsg.h"
#include "ShortMsgDlg.h"
#include "afxdialogex.h"
#include "Txtdeal.h"
#include "Encode.h"
#include "strCoding.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShortMsgDlg �Ի���



CShortMsgDlg::CShortMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShortMsgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShortMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_INDEX, m_lst);
}

BEGIN_MESSAGE_MAP(CShortMsgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CShortMsgDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &CShortMsgDlg::OnBnClickedButtonOpenfile)
END_MESSAGE_MAP()


// CShortMsgDlg ��Ϣ�������

BOOL CShortMsgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_lst.InsertColumn(0, _T("���"), LVCFMT_CENTER, 50);
	m_lst.InsertColumn(1, _T("�ֻ���"), LVCFMT_CENTER, 130);
	m_lst.InsertColumn(2, _T("״̬"), LVCFMT_CENTER, 130);
	this->SetDlgItemTextW(IDC_EDIT_THREAD, _T("1"));
	this->SetDlgItemTextW(IDC_EDIT_SUMTHREAD, _T("10"));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CShortMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CShortMsgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CShortMsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShortMsgDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	/*string tempstr = "�Ϻ�";
	CString t_Str;
	strCoding strCd;
	tempstr = strCd.UrlUTF8((char *)tempstr.c_str());
	t_Str = tempstr.c_str();
	MessageBox(t_Str);*/
	MessageBox(_T("�����£���"));
	//CDialogEx::OnOK();
}

void CShortMsgDlg::OnBnClickedButtonOpenfile()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog cfdlg(TRUE);
	CString csPathName;
	if (cfdlg.DoModal() == IDOK){
		csPathName = cfdlg.GetPathName();
	}

	CFile c_File;
	wchar_t w_str[1024];
	char r_str[1024];
	memset(r_str, '\0', 1024);
	if (!c_File.Open(csPathName, CFile::modeReadWrite)){
		MessageBox(_T("�ļ���ʧ�ܣ�"));
		return;
	}
	else{
		c_File.Read(r_str, 1024);
	}
	c_File.Close();
	C2W(r_str, w_str, 1024);
	CString c_Str = w_str;
	vector<CString> vecStr;
	vecStr = spiltcstring(c_Str, _T("\n"));
	int r_Index;
	CString s_Index;
	for (int i = 0; i < vecStr.size(); i++){
		s_Index.Format(_T("%d"), i+1);
		r_Index = m_lst.InsertItem(i, s_Index);
		m_lst.SetItemText(r_Index, 1, vecStr[i]);
		s_Index.Empty();
	}
}



