#ifndef VERTEXDECLARATIONS_H_INCLUDED
#define VERTEXDECLARATIONS_H_INCLUDED


#include "VVDefine.h"
#include <glm/glm.hpp>



class VertexPos {
public:

	VertexPos() : position(0.0f, 0.0f, 0.0f) {
	}

	VertexPos(const glm::vec3& p) : position(p) {
	}
	glm::vec3 position;
};

class VertexPosTex {
public:

	VertexPosTex() : position(0.0f, 0.0f, 0.0f), texCoord(0.0f, 0.0f) {
	}

	VertexPosTex(const glm::vec3& p, const glm::vec2& t) : position(p), texCoord(t) {
	}
	glm::vec3 position;
	glm::vec2 texCoord;
};

class VertexPosNormTex {
public:

	VertexPosNormTex() : position(0.0f, 0.0f, 0.0f), normal(0.0f, 0.0f, 0.0f), texCoord(0.0f, 0.0f) {
	}

	VertexPosNormTex(const glm::vec3& p, const glm::vec3& n, const glm::vec2& t) : position(p), normal(n), texCoord(t) {
	}
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
};

class VertexPosNormTex3 {
public:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
	//glm::vec2 texCoord1; // Shane: 暂时用不到
	//glm::vec2 texCoord2;
};

class VertexPosColorTex {
public:

	VertexPosColorTex() : position(0.0f, 0.0f, 0.0f), color(0.0f, 0.0f, 0.0f, 1.0f), texCoord(0.0f, 0.0f), texCoord1(0.0f, 0.0f) {
	}

	VertexPosColorTex(const glm::vec3& p, const glm::vec4& c, const glm::vec2& t, const glm::vec2& t1) : position(p), color(c), texCoord(t), texCoord1(t1) {
	}
	glm::vec3 position;
	glm::vec4 color;
	glm::vec2 texCoord;
	glm::vec2 texCoord1;
};

class VertexPosNormColorTex {
public:

	VertexPosNormColorTex() : position(0.0f, 0.0f, 0.0f), normal(0, 0, 0), color(0.0f, 0.0f, 0.0f, 1.0f), texCoord(0.0f, 0.0f) {
	}

	VertexPosNormColorTex(const glm::vec3& p, const glm::vec3& n, const glm::vec4& c, const glm::vec2& t, const glm::vec2& t1) : position(p), color(c), texCoord(t), texCoord1(t1) {
	}
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec4 color;
	glm::vec2 texCoord;
	glm::vec2 texCoord1;
};

//点纹理

class VertexPosColor {
public:

	VertexPosColor(const glm::vec3& p, const glm::vec4& c)
		: position(p), color(c) {
	}
	glm::vec3 position;
	glm::vec4 color;
};

//动画顶点坐标

class VertexTexNormBone {
public:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
	glm::vec4 boneIndices; /** bone indices that affect this vertex ( for animated mesh only)*/
	glm::vec4 boneWeights; /** bone weights that affect this vertex for animated mes only)*/

	/** constructor*/
	VertexTexNormBone() :
		position(glm::vec3()), normal(glm::vec3()), texCoord(glm::vec2()), boneIndices(glm::vec4(0, 0, 0, 0)), boneWeights(glm::vec4(0, 0, 0, 0)) {
	}

	VertexTexNormBone(const glm::vec3& pos_, const glm::vec3& normal_, const glm::vec2& texCoord_, const glm::vec4& boneIndices_, const glm::vec4 & boneWeights_)
		:
		position(pos_), normal(normal_), texCoord(texCoord_), boneIndices(boneIndices_), boneWeights(boneWeights_) {
	}

	VertexTexNormBone(const VertexTexNormBone & v) {
		position = v.position;
		normal = v.normal;
		texCoord = v.texCoord;
		boneIndices = v.boneIndices;
		boneWeights = v.boneWeights;
	}

	VertexTexNormBone & operator=(VertexTexNormBone & v) {
		position = v.position;
		normal = v.normal;
		texCoord = v.texCoord;
		boneIndices = v.boneIndices;
		boneWeights = v.boneWeights;
		return *this;
	}
};

class VertexContainer {
public:

	VertexContainer() {
	}

	virtual ~VertexContainer() {
	}

	virtual size_t GetVertexSize() = 0;
	virtual void* GetData() = 0;
};


#endif //VERTEXDECLARATIONS_H_INCLUDED