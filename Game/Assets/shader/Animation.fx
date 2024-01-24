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

cbuffer Animationcb : register(b1)
{
	int AnimationFrame;
	int AnimationFrameLimit;
};

Texture2D<float4> Texture[256] : register(t0);
sampler Sampler : register(s0);
float4 SetTexture(int Frame,PSInput In);
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
	TexColor = SetTexture(AnimationFrame,In);
	TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
	return TexColor;
}
float4 SetTexture(int Frame,PSInput In)
{
	switch(Frame)
	{
		case 0:
            return Texture[0].Sample(Sampler, In.uv);
        case 1:
            return Texture[1].Sample(Sampler, In.uv);
        case 2:
            return Texture[2].Sample(Sampler, In.uv);
        case 3:
            return Texture[3].Sample(Sampler, In.uv);
        case 4:
            return Texture[4].Sample(Sampler, In.uv);
        case 5:
            return Texture[5].Sample(Sampler, In.uv);
        case 6:
            return Texture[6].Sample(Sampler, In.uv);
        case 7:
            return Texture[7].Sample(Sampler, In.uv);
        case 8:
            return Texture[8].Sample(Sampler, In.uv);
        case 9:
            return Texture[9].Sample(Sampler, In.uv);
        case 10:
            return Texture[10].Sample(Sampler, In.uv);
        case 11:
            return Texture[11].Sample(Sampler, In.uv);
        case 12:
            return Texture[12].Sample(Sampler, In.uv);
        case 13:
            return Texture[13].Sample(Sampler, In.uv);
        case 14:
            return Texture[14].Sample(Sampler, In.uv);
        case 15:
            return Texture[15].Sample(Sampler, In.uv);
	}
	return Texture[0].Sample(Sampler,In.uv);
}