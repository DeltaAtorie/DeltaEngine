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
	float CenterX        = 0.0f;// 円の中心のX座標
	float CenterY        = 0.0f;// 円の中心のY座標
	float Radius         = 0.0f;// 円の半径
};
enum class CollisionType
{
	NON    = 0,
	SQUARE = 1,
	CIRCLE = 2,
};
enum class SquareDirection
{
	NON   = 0,
	UP    = 1,
	RIGHT = 2,
	DOWN  = 3,
	LEFT  = 4
};
class Collision2D : public IGameObject
{
public:
	//当たり判定の生成
	void SquareDataSet(float  Wide , float Height , float PositionX , float PositionY , const char* ObjectName , const char* Tag);
	void CircleDataSet(float Radius , float CenterX , float CenterY , const char* ObjectName , const char* Tag);

	//コピー
	bool CopyBodyData(SquareData& Decision   , const char* ObjectName);//【本体】のコピー
	bool CopyBodysData(SquareData& Decision  , const char* Tag        , int Count);//【タグが付いた複数の本体】のコピー
	bool CopyEmptyData(SquareData& Decision  , const char* ObjectName , SquareDirection Direction);//【空】のコピー
	bool CopyEmptysData(SquareData& Decision , const char* Tag        , SquareDirection Direction , int Count);//【タグが付いた複数の空】のコピー

	//座標更新
	void BodySetPosition(float PositionX , float PositionY , const char* ObjectName);

	//衝突判定
	bool EmptyAndEmptyCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2 , SquareDirection Direction2);//【空同士】の衝突
	bool BodyAndBodyCollision(const char* ObjectName1   , const char* ObjectName2);//【本体同士】の衝突

	bool EmptyAndBodyCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2);//【空】と【本体】の衝突

	bool EmptyAndBodysCollision(const char* ObjectName1  , SquareDirection Direction1 , const char* Tag2);//【空】と【タグが付いた複数の本体】の衝突
	bool EmptyAndEmptysCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* Tag2 , SquareDirection Direction2);//【空】と【タグが付いた複数の空】の衝突

	bool BodyAndBodysCollision(const char* ObjectName1  , const char* Tag2);//【本体】と【タグが付いた複数の本体】の衝突
	bool BodyAndEmptysCollision(const char* ObjectName1 , const char* Tag2 , SquareDirection Direction1);//【本体】と【タグが付いた複数の空】の衝突
private:
	void BodyInSideDataSet(int Count);
	void BodyUpSetPosition(int Count);
	void BodyRightSetPosition(int Count);
	void BodyDownSetPosition(int Count);
	void BodyLeftSetPosition(int Count);
private:
	SquareData Square[256][5];
	CircleData Circle[256];
	float EmptyWidth = 15.0f;
	float InitValue  = 50000.0f;
};
