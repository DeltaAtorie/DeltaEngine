#pragma once
namespace nsK2EngineLow
{
	class RenderingEngine;
	class SpriteRender : public IRender
	{
	public:
		//初期化
		//引数：（ファイルパス、画像の横幅、画像の縦幅、半透明合成）
		void Init
		(
			const char* Sprite,
			const float w,
			const float h,
			AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		void WeatherInit
		(
			const char* Sprite,
			const float w = 1920.0f,
			const float h = 1080.0f,
			AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		

		struct SpriteCurrentTime
		{
			int Time =0;
		};
		void CurrentTimeInit
		(
			const char* Sprite,
			const float w = 1920.0f,
			const float h = 1080.0f,
			AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		struct SpriteSymbol
		{
			int State = 0;
		};
		void SymbolInit
		(
			const char* Sprite,
			int State,
			const float w = 1920.0f,
			const float h = 1080.0f,
			AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		struct SpriteAnimation
		{
			int AnimationFrame      = 0;
			int AnimationFrameLimit = 0;
		};
		void AnimationInit
		(
			const char* Sprite[],
			int FrameLimit,
			const float w = 1920.0f,
			const float h = 1080.0f,
			AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		struct SpritePercent
		{
			int State = 0;
			float Percent = 0.0f;
		};
		void PercentInit
		(
			const char* Sprite1,
			const char* Sprite2,
			int State,
			const float w = 1920.0f,
			const float h = 1080.0f,
			AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		//更新
		void Update()
		{
			m_sprite.Update
			(
				m_position,
				m_rotation,
				m_scale,
				m_pivot
			);
		}

		//描画
		void Draw(RenderContext& rc);

	//座標・回転・拡大

		//座標の設定
		void SetPosition(const Vector3& pos)
		{m_position = pos;}
		void SetPositionX(const Vector3& pos)
		{m_position.x = pos.x;}
		void SetPositionY(const Vector3& pos)
		{m_position.y = pos.y;}
		void SetPositionZ(const Vector3& pos)
		{m_position.z = pos.z;}

		//座標の取得
		const Vector3& GetPosition() const
		{return m_position;}

		const Vector2& GetWideAndHeight() const
		{return M_WideAndHeight;}

		//回転の設定
		void SetRotation(const Quaternion& rot)
		{m_rotation = rot;}

		//回転の取得
		const Quaternion& GetRotation() const
		{return m_rotation;}

		//拡大率の設定
		void SetScale(const Vector3 scale)
		{m_scale = scale;}

		//座標の取得
		const Vector3& GetScale() const
		{return m_scale;}

		//ピボットの設定
		void SetPivot(const Vector2& pivot)
		{m_pivot = pivot;}

		//ピボットの取得
		const Vector2& GetPivot() const
		{return m_pivot;}

		//乗算カラーの設定
		void SetMulColor(const Vector4& mulColor)
		{m_sprite.SetMulColor(mulColor);}

		//乗算カラーの取得
		const Vector4& GetMulColor() const
		{return m_sprite.GetMulColor();}

		void CurrentTimeSet(int Time)
		{
			S_CurrentTime.Time  = Time;
		}
		void AnimationSet(int Frame)
		{
			S_Animation.AnimationFrame = Frame;
		}
		void PercentSet(float Percent)
		{
			S_Percent.Percent = Percent;
		}

		void OnRender2D(RenderContext& rc) override;
	private:
		//スプライト
		Texture M_Texture;
		const wchar_t* M_TextureFilePath;
		Sprite m_sprite;
		SpriteInitData InitData;
		//座標
		Vector3 m_position = Vector3::Zero;

		//回転
		Quaternion m_rotation = Quaternion::Identity;

		//拡大率
		Vector3 m_scale = Vector3::One;

		//ピボット
		Vector2 m_pivot = Sprite::DEFAULT_PIVOT;

		Vector2 M_WideAndHeight;

		SpriteCurrentTime S_CurrentTime;
		SpriteAnimation S_Animation;
		SpritePercent S_Percent;
		SpriteSymbol S_Symbol;
	};
}


