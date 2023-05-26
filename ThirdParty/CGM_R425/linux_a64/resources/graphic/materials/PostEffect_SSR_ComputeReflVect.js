{
	"Effect" : "PostEffect_SSR_ComputeReflVect",
    "Technique" : "PostProcess",
    "InputParameters" :
    [
        { "Name": "pixelIndexBuffer", "Type": "UnorderedBuffer" },
        { "Name": "s_ZMap", "Type": "Texture" },
        { "Name": "s_NormalMap", "Type": "Texture" },
        { "Name": "F0RoughnessMap", "Type": "Texture" },
        { "Name": "positionsNormalMap", "Type": "Texture" }
    ]
}
