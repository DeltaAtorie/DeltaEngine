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

Texture2D<float4> Count[10] : register(t0);
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
	float4 TexColor1;
	float4 TexFinal;

	switch(M_Time)
	{
		case 0:
		TexColor1 = Count[0].Sample(Sampler,In.uv);
		break;

		case 1:
		TexColor1 = Count[1].Sample(Sampler,In.uv);
		break;

		case 2:
		TexColor1 = Count[2].Sample(Sampler,In.uv);
		break;

		case 3:
		TexColor1 = Count[3].Sample(Sampler,In.uv);
		break;

		case 4:
		TexColor1 = Count[4].Sample(Sampler,In.uv);
		break;

		case 5:
		TexColor1 = Count[5].Sample(Sampler,In.uv);
		break;

		case 6:
		TexColor1 = Count[6].Sample(Sampler,In.uv);
		break;

		case 7:
		TexColor1 = Count[7].Sample(Sampler,In.uv);
		break;

		case 8:
		TexColor1 = Count[8].Sample(Sampler,In.uv);
		break;

		case 9:
		TexColor1 = Count[9].Sample(Sampler,In.uv);
		break;
	}

	if(TexColor1.a>0.0)
	{TexColor1 = Color.Sample(Sampler,In.uv);}
	TexColor1.rgb = pow(TexColor1.rgb, 1.0 / 2.2);
	TexFinal = TexColor1 * mulColor;
	return TexFinal;
}