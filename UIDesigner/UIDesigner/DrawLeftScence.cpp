#include "stdafx.h"
#include "DrawLeftScence.h"


DrawLeftScence::DrawLeftScence(HWND hWnd): DrawScence(hWnd)
{
	m_teaportMesh = NULL;
	D3DXCreateTeapot(m_pD3DDevice,&m_teaportMesh,NULL);

	//文字精灵对象的创建
	m_sprite = new Sprite(m_pD3DDevice,"pic\\back.bmp",D3DCOLOR_XRGB(255,255,255));

	InitPlane();
}


DrawLeftScence::~DrawLeftScence(void)
{
}

HRESULT DrawLeftScence::InitPlane()
{
	
	//创建定点、索引缓冲
	PLANEVERTEX Vertices[] = 
	{
		{-1.0f,-1.0f,0.0f,D3DXCOLOR(0.0f,1.0f,0.0f,0.5),0.0f,1.0f},
		{-1.0f,1.0f ,0.0f,D3DXCOLOR(0.0f,1.0f,0.0f,0.5),0.0f,0.0f},
		{1.0f,-1.0f,0.0f, D3DXCOLOR(0.0f,1.0f,0.0f,0.5),1.0f,1.0f},
		{1.0f,1.0f ,0.0f, D3DXCOLOR(0.0f,1.0f,0.0f,0.5),1.0f,0.0f}
	};

	if(FAILED(m_pD3DDevice->CreateVertexBuffer(sizeof(Vertices)
		,0
		,D3DFVF_PLANEVERTEX
		,D3DPOOL_DEFAULT
		,&m_pBufferRec
		,NULL)))
	{
		return E_FAIL;
	}

	VOID*  pVertices;
	if(FAILED(m_pBufferRec->Lock(0, 
		sizeof(Vertices),
		(void**)&pVertices,
		0)))
	{
		return E_FAIL;
	}

	memcpy(pVertices,Vertices,sizeof(Vertices));
	m_pBufferRec->Unlock();



	//创建效果对象
	ID3DXBuffer *pErrors = NULL;
	D3DXCreateEffectFromFile(m_pD3DDevice,"res\\texShader.fx",NULL,NULL,
							 D3DXSHADER_DEBUG,NULL,&m_pEffect,&pErrors);

	if(pErrors != NULL){
		::MessageBox(NULL,(char *)pErrors->GetBufferPointer(),0,0);
		pErrors->Release();
		pErrors = NULL;
	}

	//创建并设置纹理
	D3DXCreateTextureFromFile(m_pD3DDevice,"pic\\back.bmp",&m_pTexture);
	m_pEffect->SetTexture("Texture0",m_pTexture);

	return S_OK;
}

void DrawLeftScence::Render()
{
	if (NULL == m_pD3DDevice)
	{
		return;
	}

	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING,false);
	
	m_pD3DDevice->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);

	m_pD3DDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
	m_pD3DDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
	m_pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG1,D3DTA_DIFFUSE);

	m_pD3DDevice->Clear(0,NULL,D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(25,25,0),1.0f,0);
	m_pD3DDevice->BeginScene();

	//设置世界变换
	SetWorldMatrix();
	SetViewProjectionMatrix();

	D3DXMATRIX matWorld,matView,matProj;
	D3DXMatrixTranslation(&matWorld,0,0,0);
	m_pEffect->SetMatrix("matWorld",&matWorld);

	m_pD3DDevice->GetTransform(D3DTS_VIEW,&matView);
	m_pD3DDevice->GetTransform(D3DTS_PROJECTION,&matProj);
	D3DXMATRIX matWorldViewProj = matWorld * matView * matProj;
	m_pEffect->SetMatrix("matWorldViewProj",&matWorldViewProj);

	m_pEffect->SetTechnique("RenderScene1");

	//m_teaportMesh->DrawSubset(0);
	//绘制图形
	m_pD3DDevice->SetStreamSource(0,m_pBufferRec,0,sizeof(PLANEVERTEX));
	m_pD3DDevice->SetFVF(D3DFVF_PLANEVERTEX);
	m_pD3DDevice->SetTexture(0,m_pTexture);
	
	UINT iNumPasses = 0;
	m_pEffect->Begin(&iNumPasses,0);
	for (UINT i = 0;i<iNumPasses;i++)
	{
		m_pEffect->BeginPass(i);
		m_pD3DDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);
		m_pEffect->EndPass();
	}
	m_pEffect->End();

	CString str;
	str.AppendFormat("%f\n %f\n %f\n %f\n",m_planeData.uLUX,m_planeData.uLUY,m_planeData.vRDX,m_planeData.vRDY);
	m_sprite->PrintText(str.GetString(),10,10);

	m_pD3DDevice->EndScene();
	m_pD3DDevice->Present(NULL,NULL,NULL,NULL);
}

void DrawLeftScence::SetPlaneData(PlaneData planData){
	m_planeData = planData;
}
