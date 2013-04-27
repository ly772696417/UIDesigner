#pragma once

#include "DrawScence.h"
#include "Header.h"
#include "Camera.h"
#include "Plane.h"

#include "Sprite.h"

#include <cstdlib>

typedef struct PointToProj
{
	float x;
	float y;
	float z;
}PointToProj;

class DrawRightScence :
	public DrawScence
{
public:
	DrawRightScence(HWND hWnd);
	~DrawRightScence(void);

	void ProjCoorTransform();
	bool IsPointInPlan(PlaneData planData);
	bool UpdateUVData();
	void ScreenPointToProjPoint(CPoint point);

	void Render(CPoint movePoint,CPoint clickPoint);

	PlaneData GetPlaneData();

private:
	CPoint m_movePoint,m_clickPoint;
	PointToProj m_movePointProj,m_clickPointProj;

	Plane *m_backgrTexPlan;

	PlaneData sudokuPlanData;

	Sprite *m_sprite;

	CPoint m_lastPoint;
	bool m_DragFlag;
};


