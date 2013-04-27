#pragma once

#include "Header.h"
#include "DrawScence.h"

class D3DInit
{
public:
	D3DInit(HWND hWnd);
	~D3DInit(void);

	HRESULT InitD3D();

	inline LPDIRECT3DDEVICE9 GetD3DDevice() const{
		return m_pD3DDevice;
	}


private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;

	HWND m_hWnd;
};

