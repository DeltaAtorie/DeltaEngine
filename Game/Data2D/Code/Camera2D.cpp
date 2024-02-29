#include "stdafx.h"
#include "Camera2D.h"
void Camera2D::SetObjectData(Vector3 TagPos)
{
	M_TagPosition = TagPos;
}

void Camera2D::CenterObjectMove(Vector3 CenterPos)
{
	M_TagPosition = CenterPos;

	M_TagMoveSpeed.x = M_TagPosition.x - M_TagPrevPosition.x;
	M_TagMoveSpeed.y = M_TagPosition.y - M_TagPrevPosition.y;

	M_TagPrevPosition.x = M_TagPosition.x;
	M_TagPrevPosition.y = M_TagPosition.y;
}
void Camera2D::CenterObjectMoveX(Vector3 CenterPos)
{
	M_TagPosition = CenterPos;

	M_TagMoveSpeed.x    = M_TagPosition.x - M_TagPrevPosition.x;
	M_TagPrevPosition.x = M_TagPosition.x;
}
void Camera2D::CenterObjectMoveY(Vector3 CenterPos)
{
	M_TagPosition = CenterPos;

	M_TagMoveSpeed.y    = M_TagPosition.y - M_TagPrevPosition.y;
	M_TagPrevPosition.y = M_TagPosition.y;
}
void Camera2D::CenterOffObjectMove(Vector3& CenterOffPos)
{
	CenterOffPos.x -= M_TagMoveSpeed.x;
	CenterOffPos.y += M_TagMoveSpeed.y;
}