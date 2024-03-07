#pragma once
struct SquareData
{
	char ObjectName[256]            = "nullptr";//オブジェクトの名前
	char Tag[256]                   = "nullptr";//オブジェクトのタグ
	float UpperLeftVertexX          = 0.0f;//矩形の左上X
	float UpperLeftVertexY          = 0.0f;//矩形の左上Y
	float LowerRightVertexX         = 0.0f;//矩形の右下X
	float LowerRightVertexY         = 0.0f;//矩形の右下Y
	float Wide                      = 0.0f;
	float Height                    = 0.0f;
};
struct CircleData
{
	char ObjectName[256] = "nullptr";//オブジェクトの名前
	char Tag[256]        = "nullptr";//オブジェクトのタグ
	float CircleX        = 0.0f;//単位円のX座標
	float CircleY        = 0.0f;//単位円のY座標
	float CenterX        = 0.0f;//円の中心のX座標
	float CenterY        = 0.0f;//円の中心のY座標
	float Radius         = 0.0f;//円の半径
	float Angle          = 0.0f;//角度
	float Radian         = 0.0f;//ラジアン角度
};
enum class SquareDirection
{
	NON   = 0,
	UP    = 1,
	RIGHT = 2,
	DOWN  = 3,
	LEFT  = 4
};
enum class CrashType
{
	EtoE,//空・空
	BtoB,//本体・本体
	BtoE//本体・空
};
class Collision2D : public IGameObject
{
public:
//判定の生成
	void SquareDataSet(float  Wide , float Height , float PositionX , float PositionY , const char* ObjectName , const char* Tag);
	void CircleDataSet(float Radius , float CenterX , float CenterY , const char* ObjectName , const char* Tag);
//判定の複製
	//本体
	bool CopyBodyData(SquareData& Decision   , const char* ObjectName);
	bool CopyBodyData(CircleData& Decision   , const char* ObjectName);

	//【タグが付いた複数の本体】のコピー
	bool CopyBodysData(SquareData& Decision , const char* Tag , int Count);
	bool CopyBodysData(CircleData& Decision , const char* Tag , int Count);

	//空
	bool CopyEmptyData(SquareData& Decision  , const char* ObjectName , SquareDirection Direction);

	//【タグが付いた複数の空】のコピー
	bool CopyEmptysData(SquareData& Decision , const char* Tag        , SquareDirection Direction , int Count);

//判定の更新
	void SquareSetPosition(float PositionX , float PositionY , const char* ObjectName)
	{
		for (int Count = 0 ; Count < 256 ; Count++)
		{
			if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, ObjectName) == 0)
			{
				Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX = (PositionX - (Square[Count][static_cast<int>(SquareDirection::NON)].Wide / 2));
				Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY = (PositionY + (Square[Count][static_cast<int>(SquareDirection::NON)].Height / 2));
				Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX = (PositionX + (Square[Count][static_cast<int>(SquareDirection::NON)].Wide / 2));
				Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY = (PositionY - (Square[Count][static_cast<int>(SquareDirection::NON)].Height / 2));

				BodyUpSetPosition(Count);
				BodyRightSetPosition(Count);
				BodyLeftSetPosition(Count);
				BodyDownSetPosition(Count);
				return;
			}
		}
	}
	void CircleSetPosition(float PositionX, float PositionY, const char* ObjectName)
	{
		for (int Count = 0; Count < 256; Count++)
		{
			if (strcmp(Circle[Count].ObjectName, ObjectName) == 0)
			{
				Circle[Count].CenterX = PositionX;
				Circle[Count].CenterY = PositionY;
				return;
			}
		}
	}

//判定の衝突
	bool SquareAndSquare(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2 , SquareDirection Direction2 , CrashType Type);
	bool SquareAndSquare(const char* ObjectName1 , const char* ObjectName2 , CrashType Type);
	bool SquareAndSquare(const char* ObjectName1 , const char* ObjectName2 , SquareDirection Direction2 , CrashType Type);

	bool CircleAndCircle(const char* ObjectName1 , const char* ObjectName2 , CrashType Type);

	bool SquareAndCircle(CrashType Type);
private:
	void BodyInSideDataSet(int Count)
	{
		for (int Direction = static_cast<int>(SquareDirection::UP) ; Direction <= static_cast<int>(SquareDirection::LEFT) ; Direction++)
		{
			strcpy(Square[Count][static_cast<int>(Direction)].ObjectName , Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName);
			strcpy(Square[Count][static_cast<int>(Direction)].Tag        , Square[Count][static_cast<int>(SquareDirection::NON)].Tag);
		}

		BodyUpSetPosition(Count);
		BodyRightSetPosition(Count);
		BodyDownSetPosition(Count);
		BodyLeftSetPosition(Count);
	}
	void BodyUpSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertexY  = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY);
		Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
	}
	void BodyRightSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertexX = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX);
		Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
	}
	void BodyDownSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertexY = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY);
	}
	void BodyLeftSetPosition(int Count)
	{
		Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertexX  = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX);
		Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
		Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
	}
private:
	SquareData Square[256][5];
	CircleData Circle[256];
	float EmptyWidth = 15.0f;
	float InitValue  = 50000.0f;
};
