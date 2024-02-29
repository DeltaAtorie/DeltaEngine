#pragma once
class Camera2D : public IGameObject
{
public:
	void SetObjectData(Vector3 TagPos);
	void CenterObjectMove(Vector3 CenterPos);
	void CenterObjectMoveX(Vector3 CenterPos);
	void CenterObjectMoveY(Vector3 CenterPos);
	void CenterOffObjectMove(Vector3& CenterOffPos);
private:
	Vector3 M_TagPosition     = { 0.0f , 0.0f , 0.0f };
	Vector3 M_TagPrevPosition = { 0.0f , 0.0f , 0.0f };
	Vector3 M_TagMoveSpeed    = { 0.0f , 0.0f , 0.0f };
};
