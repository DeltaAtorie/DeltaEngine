/*!
 * @brief	�X�v���C�g�p�̃V�F�[�_�[�B
 */

cbuffer cb : register(b0)
{
	float4x4 mvp;
	float4 mulColor;
};

struct VSInput
{
	float4 pos : POSITION;
	float2 uv  : TEXCOORD0;
};

struct PSInput
{
	float4 pos : SV_POSITION;
	float2 uv  : TEXCOORD0;
};

cbuffer PercentCb : register(b1)
{
    int State;
	float2 Percent;
};

Texture2D<float4> PlayerTexture : register(t0);
Texture2D<float4> EnemyTexture : register(t1);
sampler Sampler : register(s0);

PSInput VSMain(VSInput In) 
{
	PSInput psIn;
	psIn.pos = mul( mvp, In.pos );
	psIn.uv = In.uv;
	return psIn;
}
float4 PSMain( PSInput In ) : SV_Target0
{
	float4 TexColor1;
	float4 TexColor2;
	float4 TexFinal;

	float UpperLeftX;
	float UpperLeftY;
	float LowerRightX;
	float LowerRightY;

	TexColor1 = PlayerTexture.Sample(Sampler,In.uv);
	TexColor2 = EnemyTexture.Sample(Sampler,In.uv);

	TexColor1.rgb = pow(TexColor1.rgb, 1.0 / 2.2);
	TexColor2.rgb = pow(TexColor2.rgb, 1.0 / 2.2);
		
	if(State == 0)
	{
		if(In.uv.x <= Percent.x)
		{
			TexFinal = TexColor1;
		}else{
			TexFinal = TexColor2;
		}
	}
	
	if(State == 1)
	{
		UpperLeftX  = 0.5 - Percent.x;
		UpperLeftY  = 0.5 - Percent.x;
		LowerRightX = 0.5 + Percent.x;
		LowerRightY = 0.5 + Percent.x;
		if(In.uv.x >= UpperLeftX && In.uv.x <= LowerRightX && In.uv.y >= UpperLeftY && In.uv.y <= LowerRightY)
		{
			TexFinal = TexColor1;
		}else{
			TexFinal = TexColor2;
		}
	}

	if(State == 2)
	{
		UpperLeftX  = 0.5 - Percent.x;
		LowerRightX = 0.5 + Percent.x;
		if(In.uv.x >= UpperLeftX && In.uv.x <= LowerRightX)
		{
			TexFinal = TexColor1;
		}else{
			TexFinal = TexColor2;
		}
	}

	if(State == 3)
	{
		UpperLeftY  = 1.0 - Percent.y;
		LowerRightY = 1.0;
		if(In.uv.y >= UpperLeftY && In.uv.y <= LowerRightY)
		{
			TexFinal = TexColor2;
		}else{
			TexFinal = TexColor1;
		}
	}
	return TexFinal * mulColor;
}