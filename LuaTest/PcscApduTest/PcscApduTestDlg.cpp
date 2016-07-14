
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
CPcscApduTestDlg *g_dlg;
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
	g_dlg = this;

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

void
__stdcall
MyHexA(unsigned char* hex, unsigned char* a, int length)
{
	unsigned char hLowbit, hHighbit;
	int i;
	for (i = 0; i < length * 2; i += 2)
	{
		hLowbit = hex[i / 2] & 0x0f;
		hHighbit = hex[i / 2] / 16;
		if (hHighbit >= 10)
			a[i] = hHighbit + '7';
		else
			a[i] = hHighbit + '0';
		if (hLowbit >= 10)
			a[i + 1] = hLowbit + '7';
		else
			a[i + 1] = hLowbit + '0';
	}
	a[length * 2] = '\0';
}

int
__stdcall
MyAHex(unsigned char* a, unsigned char* hex, int len)
{
	int i;
	unsigned char aLowbit, aHighbit;
	unsigned char hconval, lconval;
	for (i = 0; i < len; i += 2)
	{
		aHighbit = toupper(a[i]);
		if ((aHighbit >= 'A') && (aHighbit <= 'F'))
			hconval = '7';
		else if ((aHighbit >= '0') && (aHighbit <= '9'))
			hconval = '0';
		else
			return  -1;
		aLowbit = toupper(a[i + 1]);
		if ((aLowbit >= 'A') && (aLowbit <= 'F'))
			lconval = '7';
		else if ((aLowbit >= '0') && (aLowbit <= '9'))
			lconval = '0';
		else
			return  -1;
		hex[(i / 2)] = ((aHighbit - hconval) * 16 + (aLowbit - lconval));
	}
	return 0;
}
void Printf_Edit(LPVOID lpParam, int controlId, CString AddString)
{
	CPcscApduTestDlg *p_dlg;
	p_dlg = (CPcscApduTestDlg *)lpParam;
	((CEdit *)p_dlg->GetDlgItem(controlId))->SetSel(p_dlg->GetDlgItem(controlId)->GetWindowTextLength(), p_dlg->GetDlgItem(controlId)->GetWindowTextLength());
	//((CEdit*)p_dlg->GetDlgItem(controlId))->ReplaceSel(AddString + "\r\n"); 
	((CEdit*)p_dlg->GetDlgItem(controlId))->ReplaceSel(AddString);
}

void
__stdcall
d_printf_edit(const char* format, ...)
{
#ifdef _DEBUG
	FILE* fp;
#endif
	va_list args;
	char tmp_buffer[4096] = "\0";
#ifdef _DEBUG
	fp = fopen("dc.log", "a+");
#endif
	va_start(args, format);
	vsprintf(tmp_buffer, format, args);
#ifdef _WINDOWS
	//printf("%s", tmp_buffer);
	Printf_Edit(g_dlg, IDC_EDIT_RESULT, (CString)tmp_buffer);
#endif
#ifdef _DEBUG
	(void)vfprintf(fp, format, args);
#endif
	va_end(args);
#ifdef _DEBUG
	fclose(fp);
#endif
}

void
__stdcall
d_printf_hex_note_edit(const char* note, const char* dat, int len)
{
	char log_name[20] = "\0";
	char log_time[20] = "\0";
	char tmp_buffer[4096] = "\0";
	char tmp_buffer2[4096] = "\0";

	MyHexA((unsigned char*)dat, (unsigned char*)tmp_buffer2, len);
	d_printf_edit("%s(%d):%s\n", note, len, tmp_buffer2);
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

int l_CardApdu(lua_State* luaVM)
{
	const char *pApdu = luaL_checkstring(luaVM, 1);

	
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
	d_printf_edit("SCardConnect result : %d\n", result);
	if (result)
	{
		return ;
	}

	//LONG result;
	LPBYTE pbAttr = NULL;
	DWORD cByte = SCARD_AUTOALLOCATE;

	result = SCardGetAttrib(g_sh, SCARD_ATTR_ATR_STRING, (LPBYTE)&pbAttr, &cByte);
	d_printf_edit("SCardGetAttrib result : %d\n", result);
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
	d_printf_hex_note_edit("--->", (char *)sdat, slen);
	result = SCardTransmit(g_sh, SCARD_PCI_T1, sdat, slen, NULL, rdat, &rlen);
	d_printf_hex_note_edit("<---", (char *)rdat, rlen);

	result = SCardDisconnect(g_sh, SCARD_LEAVE_CARD);

	return;
}
