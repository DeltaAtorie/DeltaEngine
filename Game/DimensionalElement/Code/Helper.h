#pragma once
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
	void SpriteAllUpdate(SpriteRender* Sprite, Vector4 Color, Vector3 Position, Vector3 Scale, Vector2 Pivot, int Size = 0)
		{
			if (Size == 0)
			{
				Sprite->SetMulColor(Color);
				Sprite->SetPosition(Position);
				Sprite->SetScale(Scale);
				Sprite->SetPivot(Pivot);
				Sprite->Update();
			}
			else {
				for (int i = 0; i < Size; i++)
				{
					Sprite[i].SetMulColor(Color);
					Sprite[i].SetPosition(Position);
					Sprite[i].SetScale(Scale);
					Sprite[i].SetPivot(Pivot);
					Sprite[i].Update();
				}
			}
		}
	//�F����
	void SpriteColorUpdate(SpriteRender* Sprite, Vector4 Color, int Size = 0)
		{
			if (Size == 0)
			{
				Sprite->SetMulColor(Color);
				Sprite->Update();
			}
			else {
				for (int i = 0; i < Size; i++)
				{
					Sprite[i].SetMulColor(Color);
					Sprite[i].Update();
				}
			}
		}
	//���W����
	void SpritePositionUpdate(SpriteRender* Sprite, Vector3 Position, int Size = 0)
		{
			if (Size == 0)
			{
				Sprite->SetPosition(Position);
				Sprite->Update();
			}
			else {
				for (int i = 0; i < Size; i++)
				{
					Sprite[i].SetPosition(Position);
					Sprite[i].Update();
				}
			}
		}
	//�䗦����
	void SpriteScaleUpdate(SpriteRender* Sprite, Vector3 Scale, int Size = 0)
		{
			if (Size == 0)
			{
				Sprite->SetScale(Scale);
				Sprite->Update();
			}
			else {
				for (int i = 0; i < Size; i++)
				{
					Sprite[i].SetScale(Scale);
					Sprite[i].Update();
				}
			}
		}
	//������
	void SpritePivotUpdate(SpriteRender* Sprite, Vector2 Pivot, int Size = 0)
		{
			if (Size == 0)
			{
				Sprite->SetPivot(Pivot);
				Sprite->Update();
			}
			else {
				for (int i = 0; i < Size; i++)
				{
					Sprite[i].SetPivot(Pivot);
					Sprite[i].Update();
				}
			}
		}
	//�`�揈��
	void SpriteRender(SpriteRender* Sprite, RenderContext& rc, int Size = 0)
		{
			if (Size == 0)
			{
				Sprite->Draw(rc);
			}
			else {
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
public:
};

