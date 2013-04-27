#include "stdafx.h"
#include "DrawScence.h"


DrawScence::DrawScence()
{
}

DrawScence::DrawScence(HWND hWnd)
{
	m_hWnd = hWnd;

	CreateD3DDevice();
}


void DrawScence::CreateD3DDevice(){
	D3DInit *d3dInit = new D3DInit(m_hWnd);
	d3dInit->InitD3D();
	m_pD3DDevice = d3dInit->GetD3DDevice();

}

DrawScence::~DrawScence(void)
{
}

void DrawScence::SetWorldMatrix()
{
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);

	m_pD3DDevice->SetTransform(D3DTS_WORLD,&matWorld);
}

void DrawScence::SetViewProjectionMatrix()
{
	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView,
					   &m_Camera.g_vPos,
					   &m_Camera.g_vViewAt,
					   &m_Camera.g_vUp);
	m_pD3DDevice->SetTransform(D3DTS_VIEW,&matView);

	CRect rect;
	GetWindowRect(m_hWnd,&rect);

	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH(&matProj,
							   D3DX_PI * 0.5,
							   1.0f * rect.Width() / rect.Height(),
							   1.0f,
							   10000.0f);
	m_pD3DDevice->SetTransform(D3DTS_PROJECTION,&matProj);

}