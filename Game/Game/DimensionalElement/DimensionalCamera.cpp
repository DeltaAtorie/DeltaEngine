#include "stdafx.h"
#include "DimensionalCamera.h"

void DimensionalCamera::SetObjectData(Vector3 TagPos)
{
	S_ObjData.M_TagPos = TagPos;
}

void DimensionalCamera::CenterObjectMove(Vector3 CenterPos)
{
	S_ObjData.M_TagPos = CenterPos;

	S_ObjData.M_tagMoveSpeed.x = S_ObjData.M_TagPos.x - S_ObjData.M_TagPrevPos.x;
	S_ObjData.M_tagMoveSpeed.y = S_ObjData.M_TagPos.y - S_ObjData.M_TagPrevPos.y;

	S_ObjData.M_TagPrevPos.x = S_ObjData.M_TagPos.x;
	S_ObjData.M_TagPrevPos.y = S_ObjData.M_TagPos.y;
}
void DimensionalCamera::CenterObjectMoveX(Vector3 CenterPos)
{
	S_ObjData.M_TagPos = CenterPos;

	S_ObjData.M_tagMoveSpeed.x = S_ObjData.M_TagPos.x - S_ObjData.M_TagPrevPos.x;
	S_ObjData.M_TagPrevPos.x = S_ObjData.M_TagPos.x;
}
void DimensionalCamera::CenterObjectMoveY(Vector3 CenterPos)
{
	S_ObjData.M_TagPos = CenterPos;

	S_ObjData.M_tagMoveSpeed.y = S_ObjData.M_TagPos.y - S_ObjData.M_TagPrevPos.y;
	S_ObjData.M_TagPrevPos.y = S_ObjData.M_TagPos.y;
}
void DimensionalCamera::CenterOffObjectMove(Vector3& CenterOffPos)
{
	CenterOffPos.x -= S_ObjData.M_tagMoveSpeed.x;
	CenterOffPos.y += S_ObjData.M_tagMoveSpeed.y;
}