

#ifndef GLINFO_H
#define GLINFO_H

#include <string>
#include <vector>
#include "Singleton.h"
// struct variable to store OpenGL info
SINGLETON_BEGIN( glInfo )
public:
    std::string vendor;
    std::string renderer;
    std::string version;
    std::vector <std::string> extensions;
    int redBits;
    int greenBits;
    int blueBits;
    int alphaBits;
    int depthBits;
    int stencilBits;
    int maxTextureSize;
    int maxLights;
    int maxAttribStacks;
    int maxModelViewStacks;
    int maxProjectionStacks;
    int maxClipPlanes;
    int maxTextureStacks;

    // ctor, init all members
    glInfo() : redBits(0), greenBits(0), blueBits(0), alphaBits(0), depthBits(0),
               stencilBits(0), maxTextureSize(0), maxLights(0), maxAttribStacks(0),
               maxModelViewStacks(0), maxClipPlanes(0), maxTextureStacks(0) {}

	bool Init();
    bool ExtractInfo();
    void PrintInfo();
	bool isExtensionSupported(const std::string& ext);
	void CheckErrors();
SINGLETON_END()

#endif
