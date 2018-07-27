#version 430

layout( location = 0 ) in vec2 vModelSpaceCenterToPos;
layout( location = 1 ) in vec2 vScreenSpaceVelocityVector;
layout( location = 2 ) in float vSpeed;
layout( location = 3 ) in vec2 vTexCoord;

layout( set = 0, binding = 1, std140 ) uniform FragData
{
  uniform vec4 uColor;

  uniform vec2 uObjectFadeStart;
  uniform vec2 uObjectFadeEnd;
  uniform float uAlphaScale;
  uniform float uBlurTexCoordScale;
};

layout( set = 0, binding = 2 ) uniform sampler2D sTexture;

layout( location = 0 ) out vec4 fragColor;


void main()
{
  // calculate an alpha value that will fade the object towards its
  // extremities, we need this to avoid an unsightly hard edge between
  // color values of the stretched object and the background. Use
  // smoothstep also to hide any hard edges (discontinuities) in rate
  // of change of this alpha gradient

 vec2 centerToPixel = abs( vModelSpaceCenterToPos );
 vec2 fadeToEdges = smoothstep(0.0, 1.0, 1.0 - ((centerToPixel - uObjectFadeStart) / (uObjectFadeEnd - uObjectFadeStart)));
 float fadeToEdgesScale = fadeToEdges.x * fadeToEdges.y * uAlphaScale; // apply global scaler
 fadeToEdgesScale = mix(1.0, fadeToEdgesScale, vSpeed); // fade proportional to speed, so opaque when at rest

// standard actor texel
 vec4 colActor = texture(sTexture, vTexCoord);
 fragColor = colActor;
 fragColor.a *= fadeToEdgesScale; // fade actor to its edges based on speed of motion
 fragColor *= uColor;
}
