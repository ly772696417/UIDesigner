//==============================================================
// File: texShader.fx
// Desc: ʹ��3������Ч����Ч���ļ�
//==============================================================



matrix matWorld;                    // ����任����
matrix matWorldViewProj;            // ��Ͼ���=World*View*Projection

texture Texture0;                   // �����������
sampler Sampler0 = sampler_state    // ����������
{
    Texture   = <Texture0>;
    MagFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

// ������ɫ������ṹ
struct VS_INPUT 
{
    float4 Position : POSITION;    
    float2 TexCoord : TEXCOORD0;
};

// ������ɫ������ṹ
struct VS_OUTPUT
{
    float4 Position : POSITION;  
    float2 TexCoord : TEXCOORD0;
};

// ������ɫ����ں���
VS_OUTPUT vs_main(VS_INPUT input) 
{
    VS_OUTPUT Output = (VS_OUTPUT) 0;
    Output.Position = mul(input.Position, matWorldViewProj);    // �����任��Ķ���λ��
    Output.TexCoord = input.TexCoord;                           // �������������

    // ������������ܵ�nNumLights�����պ����ɫֵ
   
    return Output;
}

// ������ɫ������ṹ
struct PS_OUTPUT
{
    float4 PixelColor : COLOR0;
};

// ������ɫ����ں���
PS_OUTPUT ps_main( VS_OUTPUT input ) 
{ 
	
    PS_OUTPUT Output  = (PS_OUTPUT) 0;

	//Output.PixelColor=float4(1.0,0.0,0.0,1.0);

	
	if(input.TexCoord[0]>0.5 && input.TexCoord[1]>0.2)
	{
		Output.PixelColor = tex2D(Sampler0, input.TexCoord) ;
	}
	else 
	{
		Output.PixelColor=float4(0.0,0.0,1.0,1.0);
	}
	

    return Output;
}

// ��1���ַ�: ʹ��1����Դ
Technique RenderScene1
{
    Pass P0
    {
        VertexShader = compile vs_3_0 vs_main();
        PixelShader  = compile ps_3_0 ps_main();
    }
}

