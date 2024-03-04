#include "stdafx.h"
#include "Camera2D.h"
void Camera2D::SetObjectData(Vector3 TagPos)
{
	M_Position = TagPos;
}
void Camera2D::CenterObjectMove(Vector3 CenterPos)
{
	M_Position = CenterPos;

	M_MoveSpeed.x = M_Position.x - M_PrevPosition.x;
	M_MoveSpeed.y = M_Position.y - M_PrevPosition.y;

	M_PrevPosition.x = M_Position.x;
	M_PrevPosition.y = M_Position.y;
}
void Camera2D::CenterObjectMoveX(Vector3 CenterPos)
{
	M_Position = CenterPos;

	M_MoveSpeed.x    = M_Position.x - M_PrevPosition.x;
	M_PrevPosition.x = M_Position.x;
}
void Camera2D::CenterObjectMoveY(Vector3 CenterPos)
{
	M_Position = CenterPos;

	M_MoveSpeed.y    = M_Position.y - M_PrevPosition.y;
	M_PrevPosition.y = M_Position.y;
}
void Camera2D::CenterOffObjectMove(Vector3& CenterOffPos)
{
	CenterOffPos.x -= M_MoveSpeed.x;
	CenterOffPos.y += M_MoveSpeed.y;
}