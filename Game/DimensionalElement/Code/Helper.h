#pragma once
#include "DimensionalStorage/HeaderStorage.h"
class Helper : public IGameObject
{
public:
//////���l�̍X�V//////
	//����
	void ForwardAlphaUpdate(Vector2& Alpha, float Speed)
		{
			Alpha.x += Speed * g_gameTime->GetFrameDeltaTime();
			Alpha.y -= Speed * g_gameTime->GetFrameDeltaTime();
		}
	void ForwardAlphaUpdate(float& Alpha, float Speed)
		{
			Alpha += Speed * g_gameTime->GetFrameDeltaTime();
		}
	//����
	void ReverseAlphaUpdate(Vector2& Alpha, float Speed)
		{
			Alpha.x -= Speed * g_gameTime->GetFrameDeltaTime();
			Alpha.y += Speed * g_gameTime->GetFrameDeltaTime();
		}
	void ReverseAlphaUpdate(float& Alpha, float Speed)
		{
			Alpha -= Speed * g_gameTime->GetFrameDeltaTime();
		}

//////�摜�̍X�V�E�`��ꊇ����//////
	//�S����
	void SpriteUpdate(SpriteRender* Sprite , Vector4* Color, Vector3* Position, Vector3* Scale, Vector2* Pivot , int Size = 1 , bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->SetMulColor(*Color);
			Sprite->SetPosition(*Position);
			Sprite->SetScale(*Scale);
			Sprite->SetPivot(*Pivot);
			Sprite->Update();
		}else {
			for (int i = 0; i < Size; i++)
			{
				if (!Common)
				{
					Sprite[i].SetMulColor(Color[i]);
					Sprite[i].SetPosition(Position[i]);
					Sprite[i].SetScale(Scale[i]);
					Sprite[i].SetPivot(Pivot[i]);
					Sprite[i].Update();
				}else {
					if (Common)
					{
						Sprite[i].SetMulColor(*Color);
						Sprite[i].SetPosition(*Position);
						Sprite[i].SetScale(*Scale);
						Sprite[i].SetPivot(*Pivot);
						Sprite[i].Update();
					}
				}
			}
		}
	}
	//�F����
	void SpriteUpdate(SpriteRender* Sprite , Vector4* Color , int Size = 1 , bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->SetMulColor(*Color);
			Sprite->Update();
		}else {
			for (int i = 0; i < Size; i++)
			{
				if (!Common)
				{
					Sprite[i].SetMulColor(Color[i]);
					Sprite[i].Update();
				}else {
					if (Common)
					{
						Sprite[i].SetMulColor(*Color);
						Sprite[i].Update();
					}
				}
			}
		}
	}
	//���W�E�䗦����
	void SpriteUpdate(SpriteRender* Sprite , Vector3* Position , Vector3* Scale = nullptr , int Size = 1 , bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->SetPosition(*Position);
			if (Scale != nullptr)
			{Sprite->SetScale(*Scale);}
			Sprite->Update();
		}else {
			for (int i = 0; i < Size; i++)
			{
				if (!Common)
				{
					Sprite[i].SetPosition(Position[i]);
					if (Scale != nullptr)
					{Sprite->SetScale(*Scale); }
					Sprite[i].Update();
				}else {
					if (Common)
					{
						Sprite[i].SetPosition(*Position);
						if (Scale != nullptr)
						{Sprite->SetScale(*Scale);}
						Sprite[i].Update();
					}
				}
			}
		}
	}
	//������
	void SpriteUpdate(SpriteRender* Sprite  , Vector2* Pivot , int Size = 1 , bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->SetPivot(*Pivot);
			Sprite->Update();
		}else {
			for (int i = 0; i < Size; i++)
			{
				if (!Common)
				{
					Sprite[i].SetPivot(Pivot[i]);
					Sprite[i].Update();
				}else {
					if (Common)
					{
						Sprite[i].SetPivot(*Pivot);
						Sprite[i].Update();
					}
				}
				
			}
		}
	}
	//�`�揈��
	void SpriteDraw(SpriteRender* Sprite , RenderContext& rc , int Size = 1 , bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->Draw(rc);
		}else {
			for (int i = 0; i < Size; i++)
			{
				Sprite[i].Draw(rc);
			}
		}
	}

//////���W�̐ݒ�//////
	//����l
	void PositionOverflowUp(float& Position, float LimitPosition)
	{
		if (Position > LimitPosition)
		{
			Position = LimitPosition;
		}
	}
	void PositionOverflowUp(Vector2& Position, Vector2 LimitPosition)
	{
		if (Position.x > LimitPosition.x && Position.y > LimitPosition.y)
		{
			Position = LimitPosition;
		}
	}
	void PositionOverflowUp(Vector3& Position, Vector3 LimitPosition)
	{
		if (Position.x > LimitPosition.x && Position.y > LimitPosition.y && Position.z > LimitPosition.z)
		{
			Position = LimitPosition;
		}
	}
	//�����l
	void PositionOverflowDown(float& Position, float LimitPosition)
	{
		if (Position < LimitPosition)
		{
			Position = LimitPosition;
		}
	}
	void PositionOverflowDown(Vector2& Position, Vector2 LimitPosition)
	{
		if (Position.x < LimitPosition.x && Position.y < LimitPosition.y)
		{
			Position = LimitPosition;
		}
	}
	void PositionOverflowDown(Vector3& Position, Vector3 LimitPosition)
	{
		if (Position.x < LimitPosition.x && Position.y < LimitPosition.y && Position.z < LimitPosition.z)
		{
			Position = LimitPosition;
		}
	}

//////�摜�l�̐ݒ�//////
	//���l
	void CurrentTimeUpdate(SpriteRender* Sprite , int* Time , int Size = 1 , bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->CurrentTimeSet(*Time);
		}else {
			for (int i = 0; i < Size; i++)
			{
				if (!Common)
				{
					Sprite[i].CurrentTimeSet(Time[i]);
				}else {
					if (Common)
					{
						Sprite[i].CurrentTimeSet(*Time);
					}
				}
			}
		}
	}
	void AnimationUpdate(SpriteRender* Sprite , int* Frame , int Size = 1, bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->AnimationSet(*Frame);
		}else {
			for (int i = 0; i < Size; i++)
			{
				if (!Common)
				{
					Sprite[i].AnimationSet(*Frame);
				}else {
					if (Common)
					{
						Sprite[i].AnimationSet(*Frame);
					}
				}
			}
		}
	}
	void PercentUpdate(SpriteRender* Sprite , Vector2* Percent, int Size = 1, bool Common = false)
	{
		if (Size == 1)
		{
			Sprite->PercentSet(*Percent);
		}else {
			for (int i = 0; i < Size; i++)
			{
				if (!Common)
				{
					Sprite[i].PercentSet(Percent[i]);
				}else {
					if (Common)
					{
						Sprite[i].PercentSet(*Percent);
					}
				}
			}
		}
	}

//////�����蔻��̐ݒ�//////
	void CollisionSet(DimensionalCollision* Collision , Vector2* Aspect, Vector2* Position , int* ObjectName , int* Tag , int Size = 1)
	{
		if (Size == 1)
		{
			Collision->DecisionDataSet(Aspect->x , Aspect->y , Position->x , Position->y , *ObjectName , *Tag);
		}else {
			for (int i = 0; i < Size; i++)
			{
				Collision->DecisionDataSet(Aspect[i].x, Aspect[i].y, Position[i].x, Position[i].y, ObjectName[i], Tag[i]);
			}
		}
	}
	void CollisionUpdate(DimensionalCollision* Collision , Vector2* Position , int* ObjectName ,int Size = 1)
	{
		if (Size == 1)
		{
			Collision->DecisionSetPosition(Position->x , Position->y , *ObjectName);
		}else {
			for (int i = 0; i < Size; i++)
			{
				Collision->DecisionSetPosition(Position[i].x , Position[i].y , ObjectName[i]);
			}
		}
	}
};

