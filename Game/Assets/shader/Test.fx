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

cbuffer TestCb : register(b1)
{
	float Test;
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
	float4 TexColor;
	float4 TexFinal;

	float Upper = Test - 0.1f;
	float Lower = Test + 0.1f;

	if(In.uv.y > Upper  && In.uv.y < Lower)
	{
		TexColor = Texture.Sample(Sampler,In.uv);
		TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
	}else{
		TexColor = Texture.Sample(Sampler,In.uv);
		TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
		TexColor.a =0.0f;
	}
	TexFinal = TexColor;
	return TexFinal * mulColor;
}