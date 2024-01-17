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

cbuffer TimeCb : register(b1)
{
    int Time;  
	float2 Alpha;
};

Texture2D<float4> Count0 : register(t0);
Texture2D<float4> Count1 : register(t1);
Texture2D<float4> Count2 : register(t2);
Texture2D<float4> Count3 : register(t3);
Texture2D<float4> Count4 : register(t4);
Texture2D<float4> Count5 : register(t5);
Texture2D<float4> Count6 : register(t6);
Texture2D<float4> Count7 : register(t7);
Texture2D<float4> Count8 : register(t8);
Texture2D<float4> Count9 : register(t9);
Texture2D<float4> Color : register(t10);


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
	int M_Time = Time;
	float2 alpha = Alpha;
	float4 TexColor1;
	float4 TexColor2;
	float4 TexFinal;

	switch(M_Time)
	{
		case 0:
		TexColor1 = Count0.Sample(Sampler,In.uv);
		break;

		case 1:
		TexColor1 = Count1.Sample(Sampler,In.uv);
		break;

		case 2:
		TexColor1 = Count2.Sample(Sampler,In.uv);
		break;

		case 3:
		TexColor1 = Count3.Sample(Sampler,In.uv);
		break;

		case 4:
		TexColor1 = Count4.Sample(Sampler,In.uv);
		break;

		case 5:
		TexColor1 = Count5.Sample(Sampler,In.uv);
		break;

		case 6:
		TexColor1 = Count6.Sample(Sampler,In.uv);
		break;

		case 7:
		TexColor1 = Count7.Sample(Sampler,In.uv);
		break;

		case 8:
		TexColor1 = Count8.Sample(Sampler,In.uv);
		break;

		case 9:
		TexColor1 = Count9.Sample(Sampler,In.uv);
		break;
	}

	if(TexColor1.a>0.1)
	{TexColor2 = Color.Sample(Sampler,In.uv);}

	TexColor1.rgb = pow(TexColor1.rgb, 1.0 / 2.2);
	TexColor2.rgb = pow(TexColor2.rgb, 1.0 / 2.2);

	if(TexColor1.a>0.1)
	{
		TexFinal = TexColor1 * alpha.x + TexColor2 * alpha.y;
		return TexFinal;
	}
	TexFinal = TexColor1;
	return TexFinal;
}