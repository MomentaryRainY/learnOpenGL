#ifndef _TEXTURE_H_
#define _TEXTURE_H_


#include <glad/glad.h>
#include "stb_image.h"
#include <iostream>

class texture {
public:
	unsigned int ID;
	texture(const char* filename, unsigned int RGB) {
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);/*u*/
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);/*v*/
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);/*interpolate uv > liner*/
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);/*mipmap interpolate*/

        int width, height, nrChannels;
        unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, RGB, width, height, 0, RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);/*the second para assigned 0 mipmap level*/
        }
        else
        {
            std::cout << "Failed to load " << filename << std::endl;
        }
        stbi_image_free(data);
	}
};
#endif 