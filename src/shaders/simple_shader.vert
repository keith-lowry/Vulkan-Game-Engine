#version 450 
// ^ glsl version 4.50
// glsl: open gl shader language thingy

// .vert --> vertex shader

// array of three points to form our triangle
vec2 positions[3] = vec2[3](
    vec2(0.0, -0.5),
    vec2(0.5, 0.5),
    vec2(-0.5, 0.5)
);

// executed once for each vertex
void main() {
    // NW Corner = (-1, -1), SW = (-1, 1), NE = (1, -1), SE = (1, 1), Center = (0, 0)
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0); // assign a value as output
    // 4 dimensional vector that maps to output frame buffer image
    // divide everything by last value (1.0 in this case) in gl_Position vec to normalize
    // gl_VertexIndex --> built in variable of current vertex for this call to main()
}

