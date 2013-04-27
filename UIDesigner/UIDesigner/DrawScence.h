#pragma once

#include "Header.h"
#include "Camera.h"
#include "D3DInit.h"

#include "stdafx.h"

class DrawScence
{
private:

	void CreateD3DDevice();

public:
	DrawScence();
	DrawScence(HWND hWnd);
	~DrawScence(void);

	void SetWorldMatrix();//设置世界矩阵
	void SetViewProjectionMatrix();//设置投影矩阵

protected:
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	Camera m_Camera;

	HWND m_hWnd;
};

