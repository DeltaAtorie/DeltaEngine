#include "stdafx.h"
#include "Collision2D.h"
//îªíËÇÃê∂ê¨
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
			Square[Count][static_cast<int>(SquareDirection::NON)].Wide              = (Wide);
			Square[Count][static_cast<int>(SquareDirection::NON)].Height            = (Height);
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

//îªíËÇÃï°êª
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
bool Collision2D::CopyBodyData(CircleData& Body , const char* ObjectName)
{
	for (int Count = 0; Count < 256; Count++)
	{
		if (strcmp(Circle[Count].ObjectName , ObjectName) == 0)
		{
			strcpy(Body.ObjectName , Circle[Count].ObjectName);
			strcpy(Body.Tag        , Circle[Count].Tag);
			Body.CenterX  = Circle[Count].CenterX;
			Body.CenterY  = Circle[Count].CenterY;
			Body.Radius   = Circle[Count].Radius;
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
bool Collision2D::CopyBodysData(CircleData& Body , const char* Tag , int Count)
{
	if (strcmp(Circle[Count].Tag , Tag) == 0)
	{
		strcpy(Body.ObjectName , Circle[Count].ObjectName);
		strcpy(Body.Tag        , Circle[Count].Tag);
		Body.CenterX = Circle[Count].CenterX;
		Body.CenterY = Circle[Count].CenterY;
		Body.Radius  = Circle[Count].Radius;
		return true;
	}
	return false;
}

bool Collision2D::CopyEmptyData(SquareData& Body  , const char* ObjectName , SquareDirection Direction)
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
bool Collision2D::CopyEmptysData(SquareData& Body , const char* Tag        , SquareDirection Direction , int Count)
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

//è’ìÀîªíË
bool Collision2D::SquareAndSquare(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2 , SquareDirection Direction2 , CrashType Type)
{
	SquareData Body1;
	SquareData Body2;

	if (Type != CrashType::EtoE)
	{return false;}

	CopyEmptyData(Body1, ObjectName1, Direction1);
	CopyEmptyData(Body2, ObjectName2, Direction2);

	for (int X = Body1.UpperLeftVertexX; X <= Body1.LowerRightVertexX; X++)
	{
		for (int Y = Body1.LowerRightVertexY; Y <= Body1.UpperLeftVertexY; Y++)
		{
			if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
			{
				return true;
			}
		}
	}
	return false;
}
bool Collision2D::SquareAndSquare(const char* ObjectName1, const char* ObjectName2, CrashType Type)
{
	SquareData Body1;
	SquareData Body2;

	if (Type != CrashType::BtoB)
	{return false;}

	CopyBodyData(Body1 , ObjectName1);
	CopyBodyData(Body2 , ObjectName2);

	for (int X = Body1.UpperLeftVertexX; X <= Body1.LowerRightVertexX; X++)
	{
		for (int Y = Body1.LowerRightVertexY; Y <= Body1.UpperLeftVertexY; Y++)
		{
			if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
			{
				return true;
			}
		}
	}
	return false;
}
bool Collision2D::SquareAndSquare(const char* ObjectName1, const char* ObjectName2, SquareDirection Direction2, CrashType Type)
{
	SquareData Body1;
	SquareData Body2;

	if (Type != CrashType::BtoE)
	{return false;}

	CopyBodyData(Body1  , ObjectName1);
	CopyEmptyData(Body2 , ObjectName2 , Direction2);

	for (int X = Body1.UpperLeftVertexX; X <= Body1.LowerRightVertexX; X++)
	{
		for (int Y = Body1.LowerRightVertexY; Y <= Body1.UpperLeftVertexY; Y++)
		{
			if ((X >= Body2.UpperLeftVertexX && X <= Body2.LowerRightVertexX) && (Y <= Body2.UpperLeftVertexY && Y >= Body2.LowerRightVertexY))
			{
				return true;
			}
		}
	}
	return false;
}

bool Collision2D::CircleAndCircle(const char* ObjectName1 , const char* ObjectName2 , CrashType Type)
{
	CircleData Body1;
	CircleData Body2;

	float Pi = 3.14159265358979323846f;

	if (Type != CrashType::BtoB)
	{return false;}

	CopyBodyData(Body1 , ObjectName1);
	CopyBodyData(Body2 , ObjectName2);

	for (Body1.Angle = 0.0f; Body1.Angle < 360.0f; Body1.Angle += 1.0f)
	{
		Body1.Radian = Body1.Angle * Pi / 180.0f;

		Body1.CircleX = cos(Body1.Radian) * Body1.Radius;
		Body1.CircleY = sin(Body1.Radian) * Body1.Radius;

		Body1.CircleX += Body1.CenterX;
		Body1.CircleY += Body1.CenterY;

		for (Body2.Angle = 0.0f; Body2.Angle < 360.0f; Body2.Angle += 1.0f)
		{
			Body2.Radian = Body2.Angle * Pi / 180.0f;

			Body2.CircleX = cos(Body2.Radian) * Body2.Radius;
			Body2.CircleY = sin(Body2.Radian) * Body2.Radius;

			Body2.CircleX += Body2.CenterX;
			Body2.CircleY += Body2.CenterY;

			//âEè„
			if (Body1.CircleX >= Body2.CenterX && Body1.CircleY >= Body2.CenterY)
			{
				if (Body1.CircleX <= Body2.CircleX && Body1.CircleY <= Body2.CircleY)
				{
					return true;
				}
			}

			//âEâ∫
			if (Body1.CircleX >= Body2.CenterX && Body1.CircleY <= Body2.CenterY)
			{
				if (Body1.CircleX <= Body2.CircleX && Body1.CircleY >= Body2.CircleY)
				{
					return true;
				}
			}

			//ç∂è„
			if (Body1.CircleX <= Body2.CenterX && Body1.CircleY >= Body2.CenterY)
			{
				if (Body1.CircleX >= Body2.CircleX && Body1.CircleY <= Body2.CircleY)
				{
					return true;
				}
			}

			//ç∂â∫
			if (Body1.CircleX <= Body2.CenterX && Body1.CircleY <= Body2.CenterY)
			{
				if (Body1.CircleX >= Body2.CircleX && Body1.CircleY >= Body2.CircleY)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool Collision2D::SquareAndCircle(CrashType Type)
{
	return false;
}