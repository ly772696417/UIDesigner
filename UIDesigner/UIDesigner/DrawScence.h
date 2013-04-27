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

	void SetWorldMatrix();//�����������
	void SetViewProjectionMatrix();//����ͶӰ����

protected:
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	Camera m_Camera;

	HWND m_hWnd;
};

