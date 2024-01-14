
#version 450

// .frag --> fragment shader

layout (location = 0) out vec4 outColor;
// layout: takes location value: output to location 0
// out: variable should be used as output
// outColor: name 
// unlike vertex shader we have to make our own output variable

// runs on per fragment basis (pixels contained by our geometry determined in
// rasterization stage)
void main() {
    outColor = vec4(1.0, 0.0, 0.0, 1.0); // (r,g,b,a)
}
