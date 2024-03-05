#include "stdafx.h"
#include "Collision2D.h"
//当たり判定の生成
void Collision2D::SquareDataSet(float  Wide , float Height , float PositionX , float PositionY , const char* ObjectName , const char* Tag)
{
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, "nullptr") == 0)
		{
			strcpy(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName , ObjectName);
			strcpy(Square[Count][static_cast<int>(SquareDirection::NON)].Tag        , Tag);
			Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX  = (PositionX - (Wide / 2));
			Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY  = (PositionY + (Height / 2));
			Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX = (PositionX + (Wide / 2));
			Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY = (PositionY - (Height / 2));
			Square[Count][static_cast<int>(SquareDirection::NON)].Wide                      = (Wide);
			Square[Count][static_cast<int>(SquareDirection::NON)].Height                    = (Height);
			BodyInSideDataSet(Count);
			return;
		}
	}
}
void Collision2D::CircleDataSet(float Radius , float CenterX , float CenterY , const char* ObjectName , const char* Tag)
{
	for (int Count = 0; Count < 256; Count++)
	{
		if (strcmp(Circle[Count].ObjectName , "nullptr") == 0)
		{
			strcpy(Circle[Count].ObjectName , ObjectName);
			strcpy(Circle[Count].Tag        , Tag);
			Circle[Count].CenterX = CenterX;
			Circle[Count].CenterY = CenterY;
			Circle[Count].Radius  = Radius;
			return;
		}
	}
}



void Collision2D::BodyInSideDataSet(int Count)
{
	for (int Direction = static_cast<int>(SquareDirection::UP) ; Direction <= static_cast<int>(SquareDirection::LEFT) ; Direction++)
	{
		strcpy(Square[Count][static_cast<int>(Direction)].ObjectName , Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName);
		strcpy(Square[Count][static_cast<int>(Direction)].Tag        , Square[Count][static_cast<int>(SquareDirection::NON)].Tag);
	}

	Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertexY  = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY);
	Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);

	Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertexX = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX);
	Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);

	Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertexY = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY);

	Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertexX  = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX);
	Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
}

//コピー
bool Collision2D::CopyBodyData(SquareData& Body , const char* ObjectName)
{
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, ObjectName) == 0)
		{
			strcpy(Body.ObjectName , Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName);
			strcpy(Body.Tag        , Square[Count][static_cast<int>(SquareDirection::NON)].Tag);
			Body.UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX;
			Body.UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY;
			Body.LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX;
			Body.LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY;
			return true;
		}
	}
	return false;
}
bool Collision2D::CopyBodysData(SquareData& Body , const char* Tag , int Count)
{
	if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].Tag, Tag) == 0)
	{
		strcpy(Body.ObjectName , Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName);
		strcpy(Body.Tag        , Square[Count][static_cast<int>(SquareDirection::NON)].Tag);
		Body.UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX;
		Body.UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY;
		Body.LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX;
		Body.LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY;
		return true;
	}
	return false;
}
bool Collision2D::CopyEmptyData(SquareData& Body , const char* ObjectName , SquareDirection Direction)
{
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, ObjectName) == 0)
		{
			Body.UpperLeftVertexX  = Square[Count][static_cast<int>(Direction)].UpperLeftVertexX;
			Body.UpperLeftVertexY  = Square[Count][static_cast<int>(Direction)].UpperLeftVertexY;
			Body.LowerRightVertexX = Square[Count][static_cast<int>(Direction)].LowerRightVertexX;
			Body.LowerRightVertexY = Square[Count][static_cast<int>(Direction)].LowerRightVertexY;
			return true;
		}
	}
	return false;
}
bool Collision2D::CopyEmptysData(SquareData& Body , const char* Tag , SquareDirection Direction, int Count)
{
	if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].Tag, Tag) == 0)
	{
		strcpy(Body.ObjectName , Square[Count][static_cast<int>(Direction)].ObjectName);
		strcpy(Body.Tag        , Square[Count][static_cast<int>(Direction)].Tag);
		Body.UpperLeftVertexX  = Square[Count][static_cast<int>(Direction)].UpperLeftVertexX;
		Body.UpperLeftVertexY  = Square[Count][static_cast<int>(Direction)].UpperLeftVertexY;
		Body.LowerRightVertexX = Square[Count][static_cast<int>(Direction)].LowerRightVertexX;
		Body.LowerRightVertexY = Square[Count][static_cast<int>(Direction)].LowerRightVertexY;
		return true;
	}
	return false;
}

//座標更新
void Collision2D::BodySetPosition(float PositionX , float PositionY , const char* ObjectName)
{
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (strcmp(Square[Count][static_cast<int>(SquareDirection::NON)].ObjectName, ObjectName) == 0)
		{
			Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX  = (PositionX - (Square[Count][static_cast<int>(SquareDirection::NON)].Wide / 2));
			Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY  = (PositionY + (Square[Count][static_cast<int>(SquareDirection::NON)].Height / 2));
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

void Collision2D::BodyUpSetPosition(int Count)
{
	Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::UP)].UpperLeftVertexY  = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY);
	Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::UP)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
}
void Collision2D::BodyRightSetPosition(int Count)
{
	Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::RIGHT)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertexX = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX);
	Square[Count][static_cast<int>(SquareDirection::RIGHT)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
}
void Collision2D::BodyDownSetPosition(int Count)
{
	Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertexX  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::DOWN)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexX + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::DOWN)].LowerRightVertexY = (Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY);
}
void Collision2D::BodyLeftSetPosition(int Count)
{
	Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertexX  = (Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX);
	Square[Count][static_cast<int>(SquareDirection::LEFT)].UpperLeftVertexY  = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexY + (-EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertexX = Square[Count][static_cast<int>(SquareDirection::NON)].UpperLeftVertexX + (EmptyWidth);
	Square[Count][static_cast<int>(SquareDirection::LEFT)].LowerRightVertexY = Square[Count][static_cast<int>(SquareDirection::NON)].LowerRightVertexY + (EmptyWidth);
}

//衝突判定
bool Collision2D::EmptyAndEmptyCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2 , SquareDirection Direction2)
{
	SquareData Body1;
	SquareData Body2;
	if (CopyEmptyData(Body1 , ObjectName1 , Direction1) && CopyEmptyData(Body2 , ObjectName2 , Direction2))
	{
		for (int X = Body1.UpperLeftVertexX ; X <= Body1.LowerRightVertexX ; X++)
		{
			for (int Y = Body1.LowerRightVertexY ; Y <= Body1.UpperLeftVertexY ; Y++)
			{
				if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool Collision2D::EmptyAndBodyCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2)
{
	SquareData Body1;
	SquareData Body2;
	if (CopyEmptyData(Body1 , ObjectName1 , Direction1) && CopyBodyData(Body2 , ObjectName2))
	{
		for (int X = Body1.UpperLeftVertexX ; X <= Body1.LowerRightVertexX ; X++)
		{
			for (int Y = Body1.LowerRightVertexY ; Y <= Body1.UpperLeftVertexY ; Y++)
			{
				if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Collision2D::EmptyAndBodysCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* Tag2)
{
	SquareData Body1;
	SquareData Body2;
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (CopyEmptyData(Body1 , ObjectName1 , Direction1) && CopyBodysData(Body2 , Tag2 , Count))
		{
			for (int X = Body1.UpperLeftVertexX ; X <= Body1.LowerRightVertexX ; X++)
			{
				for (int Y = Body1.LowerRightVertexY ; Y <= Body1.UpperLeftVertexY ; Y++)
				{
					if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
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
	SquareData Body1;
	SquareData Body2;
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (CopyBodyData(Body1 , ObjectName1) && CopyBodysData(Body2 , Tag2 , Count))
		{
			for (int X = Body1.UpperLeftVertexX ; X <= Body1.LowerRightVertexX ; X++)
			{
				for (int Y = Body1.LowerRightVertexY ; Y <= Body1.UpperLeftVertexY ; Y++)
				{
					if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
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
	SquareData Body1;
	SquareData Body2;
	if (CopyBodyData(Body1 , ObjectName1) && CopyBodyData(Body2 , ObjectName2))
	{
		for (int X = Body1.UpperLeftVertexX ; X <= Body1.LowerRightVertexX ; X++)
		{
			for (int Y = Body1.LowerRightVertexY ; Y <= Body1.UpperLeftVertexY ; Y++)
			{
				if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Collision2D::EmptyAndEmptysCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* Tag2 , SquareDirection Direction2)
{
	SquareData Body1;
	SquareData Body2;
	for (int Count = 0 ; Count < 256 ; Count++)
	{
		if (CopyEmptyData(Body1 , ObjectName1 , Direction1) && CopyEmptysData(Body2 , Tag2 , Direction2 , Count))
		{
			for (int X = Body1.UpperLeftVertexX ; X <= Body1.LowerRightVertexX ; X++)
			{
				for (int Y = Body1.LowerRightVertexY ; Y <= Body1.UpperLeftVertexY ; Y++)
				{
					if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool Collision2D::BodyAndEmptysCollision(const char* ObjectName1 , const char* Tag2 , SquareDirection Direction2)
{
	SquareData Body1;
	SquareData Body2;
	for (int Count = 0; Count < 256; Count++)
	{
		if (CopyBodyData(Body1 , ObjectName1) && CopyEmptysData(Body2 , Tag2 , Direction2 , Count))
		{
			for (int X = Body1.UpperLeftVertexX ; X <= Body1.LowerRightVertexX ; X++)
			{
				for (int Y = Body1.LowerRightVertexY ; Y <= Body1.UpperLeftVertexY ; Y++)
				{
					if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}