#ifndef RENDERFBO_H
#define	RENDERFBO_H
#include "VVDefine.h"
#include "Colour.h"
class RenderFBO {
public:
// 	friend class RenderManager;
 	RenderFBO();
 	virtual ~RenderFBO();
	void create(glm::u16 w, glm::u16 h, const Color& color, bool isCreateDepthTex, bool isEnableLinear, bool resetTexture = false);
 	void begin(bool isClearDepth = true, bool isClearColor = true);
 	void end();
// 	Texture* getRenderTexture() const;
// 	Texture* getDepthTexture() const;
 	const Color& getCleanColor() const;
 	void setCleanColor(const Color& value);
 	static void reload();
private:
// 	static ArrayList<RenderFBO*> fbos;
 	glm::u16 fboWidth;
 	glm::u16 fboHeight;
// 	Texture* tex = null;
// 	Texture* depthBufferTexure = null;
// 	u32 depthBufferIndex = 0;
	glm::u32 fboIndex = 0;
// 	s32 oldfboIndex = 0;
 	Color cleanColor;
// 	bool isCreateDepthTexture = true;
// 	bool isLinear = false;
};

#endif