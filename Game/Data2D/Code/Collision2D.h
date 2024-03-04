#pragma once
struct ObjectData
{
	char ObjectName[256]            = "nullptr";//オブジェクトの名前
	char Tag[256]                   = "nullptr";//オブジェクトのタグ
	int Direction                   = 0;//オブジェクトの空方向
	float UpperLeftVertexPositionX  = 0;//矩形の左上X
	float UpperLeftVertexPositionY  = 0;//矩形の左上Y
	float LowerRightVertexPositionX = 0;//矩形の右下X
	float LowerRightVertexPositionY = 0;//矩形の右下Y
	float Wide                      = 0;
	float Height                    = 0;
};
enum
{
	DIRECTION_NON   = 0,
	DIRECTION_UP    = 1,
	DIRECTION_RIGHT = 2,
	DIRECTION_DOWN  = 3,
	DIRECTION_LEFT  = 4
};
class Collision2D : public IGameObject
{
public:

	Collision2D();
	void Reset();

	//当たり判定の生成
	void BodyDataSet(float  Wide , float Height , float PositionX , float PositionY , const char* ObjectName , const char* Tag);

	//コピー
	bool CopyBodyData(ObjectData& Decision   , const char* ObjectName);//【本体】のコピー
	bool CopyBodysData(ObjectData& Decision  , const char* Tag        , int Count);//【タグが付いた複数の本体】のコピー
	bool CopyEmptyData(ObjectData& Decision  , const char* ObjectName , int Direction);//【空】のコピー
	bool CopyEmptysData(ObjectData& Decision , const char* Tag        , int Direction , int Count);//【タグが付いた複数の空】のコピー

	//座標更新
	void BodySetPosition(float PositionX , float PositionY , const char* ObjectName);

	//衝突判定
	bool EmptyAndEmptyCollision(const char* ObjectName1 , int Direction1 , const char* ObjectName2 , int Direction2);//【空同士】の衝突
	bool BodyAndBodyCollision(const char* ObjectName1   , const char* ObjectName2);//【本体同士】の衝突

	bool EmptyAndBodyCollision(const char* ObjectName1 , int Direction1 , const char* ObjectName2);//【空】と【本体】の衝突

	bool EmptyAndBodysCollision(const char* ObjectName1  , int Direction1 , const char* Tag2);//【空】と【タグが付いた複数の本体】の衝突
	bool EmptyAndEmptysCollision(const char* ObjectName1 , int Direction1 , const char* Tag2 , int Direction2);//【空】と【タグが付いた複数の空】の衝突

	bool BodyAndBodysCollision(const char* ObjectName1  , const char* Tag2);//【本体】と【タグが付いた複数の本体】の衝突
	bool BodyAndEmptysCollision(const char* ObjectName1 , const char* Tag2 , int Direction2);//【本体】と【タグが付いた複数の空】の衝突
private:
	void BodyInSideDataSet(int Count);
	void BodyUpSetPosition(int Count);
	void BodyRightSetPosition(int Count);
	void BodyDownSetPosition(int Count);
	void BodyLeftSetPosition(int Count);
private:
	ObjectData BodyData[256][5];
	float EmptyWidth = 15.0f;
	float InitValue  = 50000.0f;
};
