Shader "Custom/쉐이더공부" {
	Properties {
		_Color ("Color", Color) = (1,1,1,1) 			//_Color("Inspector에서 표시될 이름", 자료형) = (R,G,B,A)
		_MainTex ("Albedo (RGB)", 2D) = "white" {}
		_Normal ("NormalMap", 2D) = "white" {}			//노멀맵
		_Glossiness ("Smoothness", Range(0,1)) = 0.5	//자료형= Range(0,1) //0~1 사이의 값을 가짐
		_Metallic ("Metallic", Range(0,1)) = 0.0		//소수를 표현하는 데에는 float, half, fixed 등이 있다. 모바일 환경에서는 fixed를 사용하는 것이 효율이 좋음.
		_foo("bar",Range(0,100)) = 0.0
	}
	SubShader {
		Tags { "RenderType"="Opaque" } 					//Opaque, Transparent, Cut Off...
		LOD 200											//Level of Depth, 이 서브쉐이더는 LOD 200 기준이다.

		CGPROGRAM										//여기서부터 C for Graphic을 위한 구역. CG 문법을 사용할 수 있는 부분
		// Physically based Standard lighting model, and enable shadows on all light types
		#pragma surface surf Standard fullforwardshadows//선언부, #pragma surface <Lighting 함수> <Option> <forward or deffered>

		// Use shader model 3.0 target, to get nicer looking lighting
		#pragma target 3.0								//그래픽 수준을 지정해줄 수 있음. ex. 만약 디바이스가 3.0이 되지 않는 기기라면 
														//다른 subshader 또는 FallBack에서 지정된 방식으로 쉐이딩 됨

		sampler2D _MainTex;								//Properties에서 선언해준 _MainTex
		sampler2D _Normal;

		struct Input {
			float2 uv_MainTex;							//해당 _MainTex에서 uv 좌표계를 가져옴
			float2 uv_Normal;							//변수명은 "uv"+(sampler2D 변수명)이어야 함(_Normal, uv_Normal 같이)
		};

		half _Glossiness;
		half _Metallic;
		fixed4 _Color;

		// Add instancing support for this shader. You need to check 'Enable Instancing' on materials that use the shader.
		// See https://docs.unity3d.com/Manual/GPUInstancing.html for more information about instancing.
		// #pragma instancing_options assumeuniformscaling
		UNITY_INSTANCING_BUFFER_START(Props)			//GPU Instancing, GPU에 인스턴스를 직접 올리지 않고 포인터만 전달, 가볍지만 GPU가 할 일이 많아짐
			// put more per-instance properties here
		UNITY_INSTANCING_BUFFER_END(Props)

		void surf (Input IN, inout SurfaceOutputStandard o) {
			// Albedo comes from a texture tinted by color
			fixed4 c = tex2D (_MainTex, IN.uv_MainTex) * _Color; //fixed4 = 고정소수점 실수형이 4개 (R,G,B,A)
			o.Normal = UnpackNormal(tex2D(_Normal, IN.uv_Normal));
			o.Albedo = c.rgb;
			// Metallic and smoothness come from slider variables
			o.Metallic = _Metallic;						//Properties에서 선언해준 _Metallic, _Glossiness
			o.Smoothness = _Glossiness;
			o.Alpha = c.a;
		}
		ENDCG											//여기까지 C for Graphic을 위한 구역. CG 문법을 사용할 수 있는 부분
	}
	FallBack "Diffuse"
}
