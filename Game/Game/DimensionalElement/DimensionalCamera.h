#pragma once

struct ObjData
{
	Vector3 M_TagPos = { 0.0f,0.0f,0.0f };
	Vector3 M_TagPrevPos = { 0.0f,0.0f,0.0f };
	Vector3 M_tagMoveSpeed = { 0.0f,0.0f,0.0f };
};

class DimensionalCamera : public IGameObject
{
public:
	void SetObjectData(Vector3 TagPos);
	void CenterObjectMove(Vector3 CenterPos);
	void CenterObjectMoveX(Vector3 CenterPos);
	void CenterObjectMoveY(Vector3 CenterPos);
	void CenterOffObjectMove(Vector3& CenterOffPos);
private:
	ObjData S_ObjData;
};