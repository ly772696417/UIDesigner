//==============================================================
// File: texShader.fx
// Desc: 使用3个光照效果的效果文件
//==============================================================



matrix matWorld;                    // 世界变换矩阵
matrix matWorldViewProj;            // 组合矩阵=World*View*Projection

texture Texture0;                   // 几何体的纹理
sampler Sampler0 = sampler_state    // 采样器对象
{
    Texture   = <Texture0>;
    MagFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

// 顶点着色器输入结构
struct VS_INPUT 
{
    float4 Position : POSITION;    
    float2 TexCoord : TEXCOORD0;
};

// 顶点着色器输出结构
struct VS_OUTPUT
{
    float4 Position : POSITION;  
    float2 TexCoord : TEXCOORD0;
};

// 顶点着色器入口函数
VS_OUTPUT vs_main(VS_INPUT input) 
{
    VS_OUTPUT Output = (VS_OUTPUT) 0;
    Output.Position = mul(input.Position, matWorldViewProj);    // 经过变换后的顶点位置
    Output.TexCoord = input.TexCoord;                           // 顶点的纹理坐标

    // 计算出顶点在受到nNumLights个光照后的颜色值
   
    return Output;
}

// 像素着色器输出结构
struct PS_OUTPUT
{
    float4 PixelColor : COLOR0;
};

// 像素着色器入口函数
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

// 第1种手法: 使用1个光源
Technique RenderScene1
{
    Pass P0
    {
        VertexShader = compile vs_3_0 vs_main();
        PixelShader  = compile ps_3_0 ps_main();
    }
}

