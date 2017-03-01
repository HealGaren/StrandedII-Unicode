#include <string>
#define private public
#include "gxcanvas.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <d3d.h>
#include <gdiplus.h>
#include <vector>
#define BBDECL extern "C" _declspec(dllexport)
#define BBCALL _stdcall

using namespace Gdiplus;

VOID Render(const char* content);

const char *fontname;
Color color, outlineColor;
COLORREF colorref;
int centre_x, centre_y;
int height;
HFONT hFont, hOldFont;

ULONG gdiplusToken;


//returns a string and has one string parameter
BBDECL const char * BBCALL ShuffleString(const char *str) {
	static char *_buf;

	int sz = strlen(str);

	delete[] _buf;
	_buf = new char[sz + 1];
	strcpy(_buf, str);

	for (int k = 0; k<sz; ++k) {
		int n = rand() % sz;
		int t = _buf[k]; _buf[k] = _buf[n]; _buf[n] = t;
	}

	return _buf;
}

ddSurf* g_ddSurf;


BBDECL void BBCALL InitDD(gxCanvas* _ddSurf) {
	g_ddSurf = _ddSurf->surf;

	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &GdiplusStartupInput, NULL);
}

BBDECL void BBCALL SetFontA(const char *fontname, int height, int weight, int centre_x, int centre_y) {
	::fontname = fontname;
	::height = height;
	::centre_x = centre_x;
	::centre_y = centre_y;
	hFont = CreateFont(height, 0, 0, 0, weight, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, fontname);
}

BBDECL void BBCALL SetColorA(int a, int r, int g, int b) {
	color = Color(r, g, b);
	colorref = RGB(r, g, b);
}

BBDECL void BBCALL SetOutlineColorA(int a, int r, int g, int b) {
	outlineColor = Color(r, g, b);
}

void prepare(HDC hdc) {

	int nNumPts = GetPath(hdc, NULL, NULL, 0);
	LPPOINT lpPoints = NULL;
	LPBYTE lpTypes = NULL;

	lpPoints = new POINT[nNumPts];
	lpTypes = new BYTE[nNumPts];

	nNumPts = GetPath(hdc, lpPoints, lpTypes, nNumPts);

	Graphics g(hdc);

	g.SetTextRenderingHint(TextRenderingHintAntiAlias);
	g.SetSmoothingMode(SmoothingModeAntiAlias);

	GraphicsPath path;

	Point lastPoint;
	std::vector<Point> vecPoint;
	for (int i = 0; i < nNumPts; ++i)
	{
		Point point(lpPoints[i].x, lpPoints[i].y);

		switch (lpTypes[i])
		{
		case PT_MOVETO:
			lastPoint = point;
			if (i > 0)
				path.CloseFigure();
			path.StartFigure();
			break;
		case PT_LINETO:
			path.AddLine(lastPoint, point);
			lastPoint = point;
			break;
		case PT_BEZIERTO:
			if (vecPoint.empty())
			{
				vecPoint.push_back(lastPoint);
			}
			if (vecPoint.size() < 4)
			{
				vecPoint.push_back(point);
			}
			if (4 == vecPoint.size())
			{
				path.AddBezier(vecPoint[0], vecPoint[1], vecPoint[2], vecPoint[3]);

				vecPoint.clear();
				lastPoint = point;
			}
			break;
		case PT_CLOSEFIGURE:
			path.CloseFigure();
			break;
		}
	}
	path.CloseFigure();

	delete[] lpPoints;
	delete[] lpTypes;

	Pen pen(outlineColor, 5);
	g.DrawPath(&pen, &path);
	SolidBrush brush(color);
	g.FillPath(&brush, &path);
}

BBDECL void BBCALL TextA(int x, int y, const char *str) {

	RECT r = { 0, 0, 0, 0 };
	HDC hdc;

	//IDirectDrawSurface7* surf = t_canvas->getSurface();
	ddSurf* surf = g_ddSurf;
	if (!surf) return;
	HRESULT hr = surf->GetDC(&hdc);

	hOldFont = (HFONT)SelectObject(hdc, hFont);

	SetTextColor(hdc, colorref);
	SetBkMode(hdc, TRANSPARENT);

	DrawText(hdc, str, strlen(str), &r, DT_CALCRECT);


	int width = r.right - r.left;
	int height = r.bottom - r.top;


	//HDC hMemDC;
	//hMemDC = CreateCompatibleDC(hdc);

	//HBITMAP hbmMem = CreateCompatibleBitmap(hdc, width, height);
	//SelectObject(hMemDC, hbmMem);
	if (centre_x) {
		r.left += x - width / 2;
		r.right += x - width / 2;
	}
	else {
		r.left += x;
		r.right += x;
	}
	if (centre_y) {
		r.top += y - height / 2;
		r.bottom += y - height / 2;
	}
	else {
		r.top += y;
		r.bottom += y;
	}
	//DrawText(hMemDC, str, strlen(str), &r, DT_NOCLIP);
	//BeginPath(hdc);
	DrawText(hdc, str, strlen(str), &r, DT_NOCLIP);
	//EndPath(hdc);
	
	//prepare(hdc);


	//DeleteObject(hbmMem);
	//DeleteDC(hMemDC);

	surf->ReleaseDC(hdc);
}