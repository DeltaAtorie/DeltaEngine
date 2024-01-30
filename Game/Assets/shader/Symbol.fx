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

cbuffer SymbolCb : register(b1)
{
    int Symbol;  
};

Texture2D<float4> SymbolTexture[2] : register(t0);
Texture2D<float4> Color : register(t2);

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
	int M_Symbol = Symbol;
	float4 TexColor1;
	float4 TexFinal;

	switch(M_Symbol)
	{
		case 0:
		TexColor1 = SymbolTexture[0].Sample(Sampler,In.uv);
		break;

		case 1:
		TexColor1 = SymbolTexture[1].Sample(Sampler,In.uv);
		break;
	}
	if(TexColor1.a>0.0)
	{TexColor1 = Color.Sample(Sampler,In.uv);}
	TexColor1.rgb = pow(TexColor1.rgb, 1.0 / 2.2);
	TexFinal = TexColor1 * mulColor;
	return TexFinal;
}