#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/glew.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <assert.h>
#undef _UNICODE
#include <FreeImage/FreeImage.h>

using namespace std;
class Texture
{
public:
	Texture();
	~Texture();
public:
	Texture(GLenum TextureTarget, const std::string& FileName);
	bool Load(const std::string& filename);
	void Bind(GLuint slot);
	void UnBind(GLuint slot);

	void Bind();
	void UnBind();

protected:
	bool SaveDIB(FIBITMAP *dib, char *lpszPath, int flag);
	bool SaveImage(const unsigned char* ptr, std::string& filename, int flag, int w = 640, int h = 480, int dpp = 24);
	void SaveImage(char *imgpath);
	void LoadData(GLenum target, GLubyte* ptr, unsigned int w, unsigned int h, unsigned int d);
	GLubyte* OpenImageDevIL(const std::string& filename, unsigned int& w, unsigned int& h, unsigned int& d);
private:
	std::string m_fileName;
	GLenum      m_textureTarget;
	GLuint      m_textureObj;
	GLuint      m_nHandle = 0;//
	unsigned char* m_PixData = nullptr;
	GLuint m_width = 0;
	GLuint m_height = 0;
	GLuint m_dis = 0;
};

#endif // !TEXTURE_H