#pragma once

#include<iostream>

//D3D头文件
#include<d3d9.h>
#include<d3dx9.h>

//D3D lib库
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

struct PLANEVERTEX
{
	FLOAT  x,y,z;
	DWORD  color;
	FLOAT  tu,tv;
};

#define D3DFVF_PLANEVERTEX  (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

struct CUSTOMVERTEX
{
	FLOAT _x,_y,_z;
	FLOAT _nx,_ny,_nz;
	FLOAT _u,_v;
	CUSTOMVERTEX(FLOAT x,FLOAT y,FLOAT z,
				 FLOAT nx,FLOAT ny,FLOAT nz,
				 FLOAT u,FLOAT v)
	{
		_x = x,_y = y,_z = z;
		_nx = nx,_ny = ny,_nz = nz;
		_u = u,_v = v;
	}
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1)

typedef struct PlaneData
{
	CPoint anchorPoint;
	float width;
	float height;
	float alpha;
	float offsetX;
	float offsetY;

	float uLUX,uLUY;//左上角点的uv
	float vRDX,vRDY;//右下角点的uv

	PlaneData& operator=(const PlaneData& rhs)
	{
		//anchorPoint = rhs.anchorPoint;
		anchorPoint.x = rhs.anchorPoint.x;
		anchorPoint.y = rhs.anchorPoint.y;
		width = rhs.width;
		height = rhs.height;
		alpha = rhs.alpha;

		uLUX = rhs.uLUX;
		uLUY = rhs.uLUY;

		vRDX = rhs.vRDX;
		vRDY = rhs.vRDY;

		return *this;
	}
};