#version 330 core

layout(points) in;
layout(points, max_vertices = 1) out;

in vec3 texCoords[];
out vec3 fragTexCoords;

void main() {
    fragTexCoords = texCoords[0];
    gl_Position = gl_in[0].gl_Position; // Pass through the position
    EmitVertex();
    EndPrimitive();
}