#pragma once

#include "DrawScence.h"
#include "Header.h"

#include "Sprite.h"

class DrawLeftScence : public DrawScence
{
public:
	DrawLeftScence(HWND hWnd);
	~DrawLeftScence(void);

	HRESULT InitPlane();

	void Render();

	LPD3DXMESH m_teaportMesh;

private:
	LPDIRECT3DVERTEXBUFFER9    m_pBufferRec;
	ID3DXEffect *m_pEffect;
	LPDIRECT3DTEXTURE9         m_pTexture;

	PlaneData m_planeData;

	Sprite *m_sprite;

public:
	void SetPlaneData(PlaneData planData);

};

