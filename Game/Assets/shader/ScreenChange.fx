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

cbuffer AlfhaCb : register(b1)
{
    int State;
	float2 Alpha;
};

Texture2D<float4> Texture1 : register(t0);
Texture2D<float4> Texture2 : register(t1);
Texture2D<float4> Texture3 : register(t2);

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
	float4 TexColor3;
	float4 TexFinal;

	TexColor1 = Texture1.Sample(Sampler,In.uv);
	TexColor2 = Texture2.Sample(Sampler,In.uv);
	TexColor3 = Texture3.Sample(Sampler,In.uv);

	TexColor1.rgb = pow(TexColor1.rgb, 1.0 / 2.2);
	TexColor2.rgb = pow(TexColor2.rgb, 1.0 / 2.2);
	TexColor3.rgb = pow(TexColor3.rgb, 1.0 / 2.2);
		
	if(State == 4)
	{
		TexFinal = TexColor2 * Alpha.y + TexColor3 * Alpha.x;
		return TexFinal;
	}

	if(State == 3)
	{
		TexFinal = TexColor1 * Alpha.x + TexColor2 * Alpha.y;
		return TexFinal;
	}
	
	TexFinal = TexColor1;
	return TexFinal;
}