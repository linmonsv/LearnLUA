
// PcscApduTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PcscApduTest.h"
#include "PcscApduTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPcscApduTestDlg dialog



CPcscApduTestDlg::CPcscApduTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PCSCAPDUTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPcscApduTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPcscApduTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, &CPcscApduTestDlg::OnBnClickedButtonRefresh)
	ON_BN_CLICKED(IDC_BUTTON_RUN, &CPcscApduTestDlg::OnBnClickedButtonRun)
END_MESSAGE_MAP()


// CPcscApduTestDlg message handlers

BOOL CPcscApduTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPcscApduTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPcscApduTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPcscApduTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPcscApduTestDlg::OnBnClickedButtonRefresh()
{
	// TODO: Add your control notification handler code here
	LONG result;
	//char str[1024];
	LPTSTR pmszReaders = NULL;
	DWORD cch = SCARD_AUTOALLOCATE;
	LPTSTR pReader;

	result = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, &g_sc);
	//d_printf("SCardEstablishContext result : %d\n", result);

	result = SCardListReaders(g_sc, NULL, (LPTSTR)&pmszReaders, &cch);
	//d_printf("SCardListReaders result : %d\n", result);

	pReader = pmszReaders;
	while (*pReader != 0)
	{
		//d_printf("pReader : %s\n", pReader);
		((CComboBox *)GetDlgItem(IDC_COMBO_READER_LIST))->AddString(pReader);
		((CComboBox *)GetDlgItem(IDC_COMBO_READER_LIST))->SetCurSel(0);

		pReader = pReader + wcslen(pReader) + 1;
	}
	SCardFreeMemory(g_sc, pmszReaders);
}

#include <lua.hpp>

int l_ConnectCard(lua_State* luaVM)
{
	//const char* pText = luaL_checkstring(luaVM, 1);

	
	return 0;
}

void CPcscApduTestDlg::OnBnClickedButtonRun()
{
	// TODO: Add your control notification handler code here
	LONG result;
	CString str;
	DWORD dwActiveProtocol;

	((CComboBox *)GetDlgItem(IDC_COMBO_READER_LIST))->GetLBText(((CComboBox *)GetDlgItem(IDC_COMBO_READER_LIST))->GetCurSel(), str);

	result = SCardConnect(g_sc, str, SCARD_SHARE_SHARED, SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1, &g_sh, &dwActiveProtocol);
	//d_printf("SCardConnect result : %d\n", result);
	if (result)
	{
		return ;
	}

	//LONG result;
	LPBYTE pbAttr = NULL;
	DWORD cByte = SCARD_AUTOALLOCATE;

	result = SCardGetAttrib(g_sh, SCARD_ATTR_ATR_STRING, (LPBYTE)&pbAttr, &cByte);
	//d_printf("SCardConnect result : %d\n", result);
	if (result)
	{
		return;
	}

	//LONG result;
	ULONG slen;
	UCHAR sdat[1024] = "\0";
	ULONG rlen;
	UCHAR rdat[1024] = "\0";

	slen = 20;
	memcpy(sdat, "\x00\xA4\x04\x00\x0E\x32\x50\x41\x59\x2E\x53\x59\x53\x2E\x44\x44\x46\x30\x31\x00", slen);
	rlen = 1024;
	result = SCardTransmit(g_sh, SCARD_PCI_T1, sdat, slen, NULL, rdat, &rlen);

	result = SCardDisconnect(g_sh, SCARD_LEAVE_CARD);

	return;
}
