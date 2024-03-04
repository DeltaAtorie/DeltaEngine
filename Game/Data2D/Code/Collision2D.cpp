#include "stdafx.h"
#include "Collision2D.h"
Collision2D::Collision2D()
{
	for (int A = 0 ; A < 256 ; A++)
	{
		for (int B = DIRECTION_NON ; B <= DIRECTION_LEFT ; B++)
		{
			strcpy(BodyData[A][B].ObjectName , "nullptr");
			strcpy(BodyData[A][B].Tag        , "nullptr");
			BodyData[A][B].UpperLeftVertexPositionX  = (InitValue);
			BodyData[A][B].UpperLeftVertexPositionY  = (InitValue);
			BodyData[A][B].LowerRightVertexPositionX = (InitValue);
			BodyData[A][B].LowerRightVertexPositionY = (InitValue);
			BodyData[A][B].Wide                      = (int)(InitValue);
			BodyData[A][B].Height                    = (int)(InitValue);
		}
	}
}

void Collision2D::Reset()
{
	for (int A = 0 ; A < 256 ; A++)
	{
		for (int B = DIRECTION_NON ; B <= DIRECTION_LEFT ; B++)
		{
			strcpy(BodyData[A][B].ObjectName , "nullptr");
			strcpy(BodyData[A][B].Tag        , "nullptr");
			BodyData[A][B].UpperLeftVertexPositionX  = (InitValue);
			BodyData[A][B].UpperLeftVertexPositionY  = (InitValue);
			BodyData[A][B].LowerRightVertexPositionX = (InitValue);
			BodyData[A][B].LowerRightVertexPositionY = (InitValue);
			BodyData[A][B].Wide                      = (int)(InitValue);
			BodyData[A][B].Height                    = (int)(InitValue);
		}
	}
}

//当たり判定の生成
void Collision2D::BodyDataSet(float  Wide , float Height , float PositionX , float PositionY , const char* ObjectName , const char* Tag)
{
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (strcmp(BodyData[Count][DIRECTION_NON].ObjectName, "nullptr") == 0)
		{
			strcpy(BodyData[Count][DIRECTION_NON].ObjectName , ObjectName);
			strcpy(BodyData[Count][DIRECTION_NON].Tag        , Tag);
			BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX  = (PositionX - (Wide / 2));
			BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY  = (PositionY + (Height / 2));
			BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX = (PositionX + (Wide / 2));
			BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY = (PositionY - (Height / 2));
			BodyData[Count][DIRECTION_NON].Wide                      = (Wide);
			BodyData[Count][DIRECTION_NON].Height                    = (Height);
			BodyInSideDataSet(Count);
			return;
		}
	}
}
void Collision2D::BodyInSideDataSet(int Count)
{
	for (int Direction = DIRECTION_UP ; Direction <= DIRECTION_LEFT ; Direction++)
	{
		strcpy(BodyData[Count][Direction].ObjectName , BodyData[Count][DIRECTION_NON].ObjectName);
		strcpy(BodyData[Count][Direction].Tag        , BodyData[Count][DIRECTION_NON].Tag);
	}

	BodyData[Count][DIRECTION_UP].UpperLeftVertexPositionX  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	BodyData[Count][DIRECTION_UP].UpperLeftVertexPositionY  = (BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY);
	BodyData[Count][DIRECTION_UP].LowerRightVertexPositionX = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	BodyData[Count][DIRECTION_UP].LowerRightVertexPositionY = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);

	BodyData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionX  = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	BodyData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionY  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
	BodyData[Count][DIRECTION_RIGHT].LowerRightVertexPositionX = (BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX);
	BodyData[Count][DIRECTION_RIGHT].LowerRightVertexPositionY = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);

	BodyData[Count][DIRECTION_DOWN].UpperLeftVertexPositionX  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	BodyData[Count][DIRECTION_DOWN].UpperLeftVertexPositionY  = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
	BodyData[Count][DIRECTION_DOWN].LowerRightVertexPositionX = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	BodyData[Count][DIRECTION_DOWN].LowerRightVertexPositionY = (BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY);

	BodyData[Count][DIRECTION_LEFT].UpperLeftVertexPositionX  = (BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX);
	BodyData[Count][DIRECTION_LEFT].UpperLeftVertexPositionY  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
	BodyData[Count][DIRECTION_LEFT].LowerRightVertexPositionX = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	BodyData[Count][DIRECTION_LEFT].LowerRightVertexPositionY = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
}

//コピー
bool Collision2D::CopyBodyData(ObjectData& Body , const char* ObjectName)
{
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (strcmp(BodyData[Count][DIRECTION_NON].ObjectName, ObjectName) == 0)
		{
			strcpy(Body.ObjectName , BodyData[Count][DIRECTION_NON].ObjectName);
			strcpy(Body.Tag        , BodyData[Count][DIRECTION_NON].Tag);
			Body.UpperLeftVertexPositionX  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX;
			Body.UpperLeftVertexPositionY  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY;
			Body.LowerRightVertexPositionX = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX;
			Body.LowerRightVertexPositionY = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY;
			return true;
		}
	}
	return false;
}
bool Collision2D::CopyBodysData(ObjectData& Body , const char* Tag , int Count)
{
	if (strcmp(BodyData[Count][DIRECTION_NON].Tag, Tag) == 0)
	{
		strcpy(Body.ObjectName , BodyData[Count][DIRECTION_NON].ObjectName);
		strcpy(Body.Tag        , BodyData[Count][DIRECTION_NON].Tag);
		Body.UpperLeftVertexPositionX  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX;
		Body.UpperLeftVertexPositionY  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY;
		Body.LowerRightVertexPositionX = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX;
		Body.LowerRightVertexPositionY = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY;
		return true;
	}
	return false;
}
bool Collision2D::CopyEmptyData(ObjectData& Body , const char* ObjectName , int Direction)
{
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (strcmp(BodyData[Count][DIRECTION_NON].ObjectName, ObjectName) == 0)
		{
			Body.UpperLeftVertexPositionX  = BodyData[Count][Direction].UpperLeftVertexPositionX;
			Body.UpperLeftVertexPositionY  = BodyData[Count][Direction].UpperLeftVertexPositionY;
			Body.LowerRightVertexPositionX = BodyData[Count][Direction].LowerRightVertexPositionX;
			Body.LowerRightVertexPositionY = BodyData[Count][Direction].LowerRightVertexPositionY;
			return true;
		}
	}
	return false;
}
bool Collision2D::CopyEmptysData(ObjectData& Body , const char* Tag , int Direction , int Count)
{
	if (strcmp(BodyData[Count][DIRECTION_NON].Tag, Tag) == 0)
	{
		strcpy(Body.ObjectName , BodyData[Count][Direction].ObjectName);
		strcpy(Body.Tag        , BodyData[Count][Direction].Tag);
		Body.UpperLeftVertexPositionX  = BodyData[Count][Direction].UpperLeftVertexPositionX;
		Body.UpperLeftVertexPositionY  = BodyData[Count][Direction].UpperLeftVertexPositionY;
		Body.LowerRightVertexPositionX = BodyData[Count][Direction].LowerRightVertexPositionX;
		Body.LowerRightVertexPositionY = BodyData[Count][Direction].LowerRightVertexPositionY;
		return true;
	}
	return false;
}

//座標更新
void Collision2D::BodySetPosition(float PositionX , float PositionY , const char* ObjectName)
{
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (strcmp(BodyData[Count][DIRECTION_NON].ObjectName, ObjectName) == 0)
		{
			BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX  = (PositionX - (BodyData[Count][DIRECTION_NON].Wide / 2));
			BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY  = (PositionY + (BodyData[Count][DIRECTION_NON].Height / 2));
			BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX = (PositionX + (BodyData[Count][DIRECTION_NON].Wide / 2));
			BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY = (PositionY - (BodyData[Count][DIRECTION_NON].Height / 2));

			BodyUpSetPosition(Count);
			BodyRightSetPosition(Count);
			BodyLeftSetPosition(Count);
			BodyDownSetPosition(Count);
			return;
		}
	}
}

void Collision2D::BodyUpSetPosition(int Count)
{
	BodyData[Count][DIRECTION_UP].UpperLeftVertexPositionX  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	BodyData[Count][DIRECTION_UP].UpperLeftVertexPositionY  = (BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY);
	BodyData[Count][DIRECTION_UP].LowerRightVertexPositionX = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	BodyData[Count][DIRECTION_UP].LowerRightVertexPositionY = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
}
void Collision2D::BodyRightSetPosition(int Count)
{
	BodyData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionX  = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	BodyData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionY  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
	BodyData[Count][DIRECTION_RIGHT].LowerRightVertexPositionX = (BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX);
	BodyData[Count][DIRECTION_RIGHT].LowerRightVertexPositionY = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
}
void Collision2D::BodyDownSetPosition(int Count)
{
	BodyData[Count][DIRECTION_DOWN].UpperLeftVertexPositionX  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	BodyData[Count][DIRECTION_DOWN].UpperLeftVertexPositionY  = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
	BodyData[Count][DIRECTION_DOWN].LowerRightVertexPositionX = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	BodyData[Count][DIRECTION_DOWN].LowerRightVertexPositionY = (BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY);
}
void Collision2D::BodyLeftSetPosition(int Count)
{
	BodyData[Count][DIRECTION_LEFT].UpperLeftVertexPositionX  = (BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX);
	BodyData[Count][DIRECTION_LEFT].UpperLeftVertexPositionY  = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
	BodyData[Count][DIRECTION_LEFT].LowerRightVertexPositionX = BodyData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	BodyData[Count][DIRECTION_LEFT].LowerRightVertexPositionY = BodyData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
}

//衝突判定
bool Collision2D::EmptyAndEmptyCollision(const char* ObjectName1 , int Direction1 , const char* ObjectName2 , int Direction2)
{
	ObjectData Body1;
	ObjectData Body2;
	if (CopyEmptyData(Body1 , ObjectName1 , Direction1) && CopyEmptyData(Body2 , ObjectName2 , Direction2))
	{
		for (int X = Body1.UpperLeftVertexPositionX ; X <= Body1.LowerRightVertexPositionX ; X++)
		{
			for (int Y = Body1.LowerRightVertexPositionY ; Y <= Body1.UpperLeftVertexPositionY ; Y++)
			{
				if ((X >= Body2.UpperLeftVertexPositionX && X <= Body2.LowerRightVertexPositionX) && (Y <= Body2.UpperLeftVertexPositionY && Y >= Body2.LowerRightVertexPositionY))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool Collision2D::EmptyAndBodyCollision(const char* ObjectName1 , int Direction1 , const char* ObjectName2)
{
	ObjectData Body1;
	ObjectData Body2;
	if (CopyEmptyData(Body1 , ObjectName1 , Direction1) && CopyBodyData(Body2 , ObjectName2))
	{
		for (int X = Body1.UpperLeftVertexPositionX ; X <= Body1.LowerRightVertexPositionX ; X++)
		{
			for (int Y = Body1.LowerRightVertexPositionY ; Y <= Body1.UpperLeftVertexPositionY ; Y++)
			{
				if ((X >= Body2.UpperLeftVertexPositionX && X <= Body2.LowerRightVertexPositionX) && (Y <= Body2.UpperLeftVertexPositionY && Y >= Body2.LowerRightVertexPositionY))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Collision2D::EmptyAndBodysCollision(const char* ObjectName1 , int Direction1 , const char* Tag2)
{
	ObjectData Body1;
	ObjectData Body2;
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (CopyEmptyData(Body1 , ObjectName1 , Direction1) && CopyBodysData(Body2 , Tag2 , Count))
		{
			for (int X = Body1.UpperLeftVertexPositionX ; X <= Body1.LowerRightVertexPositionX ; X++)
			{
				for (int Y = Body1.LowerRightVertexPositionY ; Y <= Body1.UpperLeftVertexPositionY ; Y++)
				{
					if ((X >= Body2.UpperLeftVertexPositionX && X <= Body2.LowerRightVertexPositionX) && (Y <= Body2.UpperLeftVertexPositionY && Y >= Body2.LowerRightVertexPositionY))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool Collision2D::BodyAndBodysCollision(const char* ObjectName1 , const char* Tag2)
{
	ObjectData Body1;
	ObjectData Body2;
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (CopyBodyData(Body1 , ObjectName1) && CopyBodysData(Body2 , Tag2 , Count))
		{
			for (int X = Body1.UpperLeftVertexPositionX ; X <= Body1.LowerRightVertexPositionX ; X++)
			{
				for (int Y = Body1.LowerRightVertexPositionY ; Y <= Body1.UpperLeftVertexPositionY ; Y++)
				{
					if ((X >= Body2.UpperLeftVertexPositionX && X <= Body2.LowerRightVertexPositionX) && (Y <= Body2.UpperLeftVertexPositionY && Y >= Body2.LowerRightVertexPositionY))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Collision2D::BodyAndBodyCollision(const char* ObjectName1 , const char* ObjectName2)
{
	ObjectData Body1;
	ObjectData Body2;
	if (CopyBodyData(Body1 , ObjectName1) && CopyBodyData(Body2 , ObjectName2))
	{
		for (int X = Body1.UpperLeftVertexPositionX ; X <= Body1.LowerRightVertexPositionX ; X++)
		{
			for (int Y = Body1.LowerRightVertexPositionY ; Y <= Body1.UpperLeftVertexPositionY ; Y++)
			{
				if ((X >= Body2.UpperLeftVertexPositionX && X <= Body2.LowerRightVertexPositionX) && (Y <= Body2.UpperLeftVertexPositionY && Y >= Body2.LowerRightVertexPositionY))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Collision2D::EmptyAndEmptysCollision(const char* ObjectName1 , int Direction1 , const char* Tag2 , int Direction2)
{
	ObjectData Body1;
	ObjectData Body2;
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (CopyEmptyData(Body1 , ObjectName1 , Direction1) && CopyEmptysData(Body2 , Tag2 , Direction2 , Count))
		{
			for (int X = Body1.UpperLeftVertexPositionX ; X <= Body1.LowerRightVertexPositionX ; X++)
			{
				for (int Y = Body1.LowerRightVertexPositionY ; Y <= Body1.UpperLeftVertexPositionY ; Y++)
				{
					if ((X >= Body2.UpperLeftVertexPositionX && X <= Body2.LowerRightVertexPositionX) && (Y <= Body2.UpperLeftVertexPositionY && Y >= Body2.LowerRightVertexPositionY))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool Collision2D::BodyAndEmptysCollision(const char* ObjectName1 , const char* Tag2 , int Direction2)
{
	ObjectData Body1;
	ObjectData Body2;
	for (int Count = 0; Count < 256; Count++)
	{
		if (CopyBodyData(Body1 , ObjectName1) && CopyEmptysData(Body2 , Tag2 , Direction2 , Count))
		{
			for (int X = Body1.UpperLeftVertexPositionX ; X <= Body1.LowerRightVertexPositionX ; X++)
			{
				for (int Y = Body1.LowerRightVertexPositionY ; Y <= Body1.UpperLeftVertexPositionY ; Y++)
				{
					if ((X >= Body2.UpperLeftVertexPositionX && X <= Body2.LowerRightVertexPositionX) && (Y <= Body2.UpperLeftVertexPositionY && Y >= Body2.LowerRightVertexPositionY))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}