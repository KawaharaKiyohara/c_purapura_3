/*!
 *@brief	���_�J���[�A�@������̃v���~�e�B�u�B
 */

float4x4	g_mWVP;					//���[���h�r���[�v���W�F�N�V�����s��B
float4x4	g_worldRotationMatrix;	//���[���h�s��̉�]�����B
#define NUM_DIFFUSE_LIGHT	4					//�f�B�t���[�Y���C�g�̐��B

struct SLight{
	float3	diffuseLightDir[NUM_DIFFUSE_LIGHT];		//�f�B�t���[�Y���C�g�̌����B
	float4  diffuseLightColor[NUM_DIFFUSE_LIGHT];	//�f�B�t���[�Y���C�g�̃J���[�B
	float3  ambient;								//�A���r�G���g���C�g�B
};
SLight	g_light;		//���C�g

struct VS_INPUT{
	float4	pos		: POSITION;
	float3  normal	: NORMAL;
	float4	color 	: COLOR0;
};

struct VS_OUTPUT{
	float4 pos		: POSITION;
	float4 color	: COLOR0;
	float3 normal	: TEXCOORD0;
};

VS_OUTPUT VSMain( VS_INPUT In )
{
	VS_OUTPUT Out;
	Out.pos = mul(In.pos, g_mWVP);
	Out.color = In.color;
	Out.normal = mul(In.normal, g_worldRotationMatrix);
	//�@������]�B
	return Out;
}
/*!
 *@brief	�f�B�t���[�Y���C�g���v�Z�B
 */	
float4 DiffuseLight( VS_OUTPUT In )
{
	float4 color = 0.0f;
	color += max( 0, dot(In.normal, g_light.diffuseLightDir[0])) * g_light.diffuseLightColor[0];
	color += max( 0, dot(In.normal, g_light.diffuseLightDir[1])) * g_light.diffuseLightColor[1];
	color += max( 0, dot(In.normal, g_light.diffuseLightDir[2])) * g_light.diffuseLightColor[2];
	color += max( 0, dot(In.normal, g_light.diffuseLightDir[3])) * g_light.diffuseLightColor[3];
	color.a = 1.0f;
	return color;
}
float4 PSMain( VS_OUTPUT In ) : COLOR0
{
	float4 color = DiffuseLight(In);
	color.xyz += g_light.ambient;
	color.xyz *= In.color.xyz;
	//�g�D�[��
/*	float t = dot(In.normal, g_light.diffuseLightDir[0]);
	t = t * 0.5f + 0.5f;
	if(t < 0.3f){
		color = In.color * 0.8f;
	}else{
		color = In.color;
	}
	color.w = 1.0f;*/
	return color;
}

technique ColorNormalPrim
{
    pass P0
    {          
        VertexShader = compile vs_2_0 VSMain();
        PixelShader  = compile ps_2_0 PSMain();
    }
}