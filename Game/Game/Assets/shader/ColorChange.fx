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

Texture2D<float4> Texture : register(t0);
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
	float4 TexColor = Texture.Sample(Sampler,In.uv);
	if(TexColor.r == 1.0f && TexColor.g == 1.0f && TexColor.b == 1.0f)
	{
		TexColor.r = 0.5f;
		TexColor.g = 0.5f;
		TexColor.b = 0.5f;
	}
	TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
	return TexColor * mulColor;
}