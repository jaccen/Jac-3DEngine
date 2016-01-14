#ifndef RENDERABLE_H
#define	RENDERABLE_H


#include "VVDefine.h"
#include "VertexDeclear.h"


#include "Shader.h"


class Renderable
{
public:
	Renderable();
	~Renderable();
public:
	virtual void Init() = 0;

public:
	void BeginToGPU(glm::u32 vboId, void* vbo, glm::vec4* extColor, VerTexType type);
	void EndToGPU(VerTexType type, glm::vec4* extColor);
	void mapAttribLocation(glm::u32 index, glm::u32 componentsPerElement, DATA_TYPE type, glm::u32 stride, const void* ptr);
	// 更新顶点
	void updateVertex();
	void updateIndexBuffer();
	public:
	RenderMode m_eMode = RM_POINTS; //绘制方式
// 	ShaderMaterial* mMaterial = null;
// 	ArrayList<Texture*> mTextrues;
	//Color color = Color::white;
	VerTexType m_vertexType = RM_P; //顶点组织方式
	union {
		void* mVersData = null;
		VertexTexNormBone* mVersPosNorBone;
		VertexPos* mVersPos;
		VertexPosTex* mVersPosTex;
		VertexPosNormTex* mVersPosNorTex;
		VertexPosNormColorTex* mVersPosNorColorTex;
		VertexPosColorTex* mVersPosColorTex;
		VertexPosColor* mVersPointTex;
		VertexPosNormTex3* mVersPosNorTex3;
	};
	glm::vec4* extColor = nullptr;
	glm::u16* mInds = nullptr;//索引
	glm::u32 mVersLen = 0;//长度
	glm::u32 mIndsLen = 0;//索引长度
	glm::u32 mVBO = 0; //
	glm::u32 mIBO = 0;
	const glm::mat4* modelMatrix = nullptr;
	GL_BUFFER_USAGE_HINT m_eBufferUsage;
	bool isInitVertex = false;
	bool isNeedUpdateIndexBuffer = true;
	bool isInitVertexOK = false;
};

#endif