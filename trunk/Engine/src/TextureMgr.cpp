#include "TextureMgr.h"



void TextureMgr::Init(std::string folder)
{
	this->folder = folder;
}


void TextureMgr::UnLoadTexture(const std::string &fileName)
{
	auto iter = m_TexID.find(fileName);
	if (iter != m_TexID.end())
	{
		m_TexID.erase(fileName);
	}

}