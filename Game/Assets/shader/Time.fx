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
	float4 TexColor;

	switch(M_Time)
	{
		case 0:
		TexColor = Count0.Sample(Sampler,In.uv);
		break;

		case 1:
		TexColor = Count1.Sample(Sampler,In.uv);
		break;

		case 2:
		TexColor = Count2.Sample(Sampler,In.uv);
		break;

		case 3:
		TexColor = Count3.Sample(Sampler,In.uv);
		break;

		case 4:
		TexColor = Count4.Sample(Sampler,In.uv);
		break;

		case 5:
		TexColor = Count5.Sample(Sampler,In.uv);
		break;

		case 6:
		TexColor = Count6.Sample(Sampler,In.uv);
		break;

		case 7:
		TexColor = Count7.Sample(Sampler,In.uv);
		break;

		case 8:
		TexColor = Count8.Sample(Sampler,In.uv);
		break;

		case 9:
		TexColor = Count9.Sample(Sampler,In.uv);
		break;
	}

	TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);

	float4 TexFinal = TexColor;
	return TexFinal;
}