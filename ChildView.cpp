
// ChildView.cpp: CChildView 类的实现
//

#include "pch.h"
#include "framework.h"
#include "72singleDocument.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
//	ON_WM_NCLBUTTONUP()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	
	// 不要为绘制消息而调用 CWnd::OnPaint()
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	m_pOrigin = point;
	int a = 100;
	CWnd::OnLButtonDown(nFlags, point);
}




void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*CDC* dc = GetDC();
	CPen pen(PS_DOT,1,RGB(0,255,0));
	CPen* oldPen=dc->SelectObject(&pen);
	dc->MoveTo(m_pOrigin);
	dc->LineTo(point);
	dc->SelectObject(oldPen);
	ReleaseDC(dc);*/

	CClientDC  dc(this);
	CBrush* brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush* oldBrush = dc.SelectObject(brush);

	dc.Rectangle(CRect(m_pOrigin, point));
	dc.SelectObject(oldBrush);

	CWnd::OnLButtonUp(nFlags, point);
}
