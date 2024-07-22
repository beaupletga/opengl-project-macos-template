#version 330 core
out vec4 FragColor;

in vec3 fragTexCoords;

void main() {
    FragColor = vec4(fragTexCoords.xyz, 1.0);
}