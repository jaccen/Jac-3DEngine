

#include <gl/glew.h>
#include "Renderable.h"


Renderable::Renderable()
{
}


Renderable::~Renderable()
{
}

void Renderable::BeginToGPU(glm::u32 vboId, void* vbo, glm::vec4* extColor, VerTexType type)
{
	if (extColor) {
		mapAttribLocation(ATTRIB_COLOR, 4, kDATA_TYPE_FLOAT, sizeof(glm::vec4), (const GLvoid*)(extColor));
	}
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	if (vboId != 0) {
		vbo = NULL;
	}
	switch (type) {
	case RM_P:
		mapAttribLocation(ATTRIB_VERTEX, 3, kDATA_TYPE_FLOAT, sizeof (VertexPos), vbo);
		break;
	case RM_P_N:
		//            mapAttribLocation(ATTRIB_VERTEX, 3, kDATA_TYPE_FLOAT, sizeof (Ver), 0);
		//            mapAttribLocation(ATTRIB_TEXTURE0, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex), (const GLvoid*) 12);
		//            mapAttribLocation(ATTRIB_NORMAL, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex), (const GLvoid*) 20);
		break;
	case RM_P_T:
		mapAttribLocation(ATTRIB_VERTEX, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosTex), vbo);
		mapAttribLocation(ATTRIB_TEXTURE0, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosTex), (const GLvoid*)(sizeof (glm::vec3) + (__ptr)vbo));
		break;
	case RM_P_N_T:
		mapAttribLocation(ATTRIB_VERTEX, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex), vbo);
		mapAttribLocation(ATTRIB_NORMAL, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex), (const GLvoid*)(sizeof (glm::vec3) + (__ptr)vbo));
		mapAttribLocation(ATTRIB_TEXTURE0, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex), (const GLvoid*)(sizeof (glm::vec3) * 2 + (__ptr)vbo));

		break;

	case RM_P_C_T:
		mapAttribLocation(ATTRIB_VERTEX, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosColorTex), vbo);
		mapAttribLocation(ATTRIB_COLOR, 4, kDATA_TYPE_FLOAT, sizeof (VertexPosColorTex), (const GLvoid*)(sizeof (glm::vec3) + (__ptr)vbo));
		mapAttribLocation(ATTRIB_TEXTURE0, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosColorTex), (const GLvoid*)(sizeof (glm::vec3) + sizeof (glm::vec4) + (__ptr)vbo));
		mapAttribLocation(ATTRIB_TEXTURE1, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosColorTex), (const GLvoid*)(sizeof (glm::vec3) + sizeof (glm::vec4) + sizeof (glm::vec2) + (__ptr)vbo));
		break;
	case RM_P_N_C_T:
		mapAttribLocation(ATTRIB_VERTEX, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosNormColorTex), vbo);
		mapAttribLocation(ATTRIB_NORMAL, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosNormColorTex), (const GLvoid*)(sizeof (glm::vec3) + (__ptr)vbo));
		mapAttribLocation(ATTRIB_COLOR, 4, kDATA_TYPE_FLOAT, sizeof (VertexPosNormColorTex), (const GLvoid*)(sizeof (glm::vec3) * 2 + (__ptr)vbo));
		mapAttribLocation(ATTRIB_TEXTURE0, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosNormColorTex), (const GLvoid*)(sizeof (glm::vec3) * 2 + sizeof (glm::vec4) + (__ptr)vbo));
		mapAttribLocation(ATTRIB_TEXTURE1, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosNormColorTex), (const GLvoid*)(sizeof (glm::vec3) * 2 + sizeof (glm::vec4) + sizeof (glm::vec2) + (__ptr)vbo));
		break;
	case RM_P_C:
		mapAttribLocation(ATTRIB_VERTEX, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosColor), vbo);
		mapAttribLocation(ATTRIB_COLOR, 4, kDATA_TYPE_FLOAT, sizeof (VertexPosColor), (const GLvoid*)(sizeof (glm::vec3) + (__ptr)vbo));
		break;
	case RM_P_N_T_B:
		mapAttribLocation(ATTRIB_VERTEX, 3, kDATA_TYPE_FLOAT, sizeof (VertexTexNormBone), vbo);
		mapAttribLocation(ATTRIB_NORMAL, 3, kDATA_TYPE_FLOAT, sizeof (VertexTexNormBone), (const GLvoid*)(sizeof (glm::vec3)+(__ptr)vbo));
		mapAttribLocation(ATTRIB_TEXTURE0, 2, kDATA_TYPE_FLOAT, sizeof (VertexTexNormBone), (const GLvoid*)(sizeof (glm::vec3) * 2 + (__ptr)vbo));
		mapAttribLocation(ATTRIB_BONES_INDICES, 4, kDATA_TYPE_FLOAT, sizeof (VertexTexNormBone), (const GLvoid*)(sizeof (glm::vec3) * 2 + sizeof (glm::vec2) + (__ptr)vbo));
		mapAttribLocation(ATTRIB_BONES_WEIGHTS, 4, kDATA_TYPE_FLOAT, sizeof (VertexTexNormBone), (const GLvoid*)(sizeof (glm::vec3) * 2 + sizeof (glm::vec2) + sizeof (glm::vec4) + (__ptr)vbo));
		break;
	case RM_P_N_T3:
		mapAttribLocation(ATTRIB_VERTEX, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex3), vbo);
		mapAttribLocation(ATTRIB_NORMAL, 3, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex3), (const GLvoid*)(sizeof (glm::vec3) + (__ptr)vbo));
		mapAttribLocation(ATTRIB_TEXTURE0, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex3), (const GLvoid*)(sizeof (glm::vec3) * 2 + (__ptr)vbo));
		//mapAttribLocation(ATTRIB_TEXTURE1, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex3), (const GLvoid*)(sizeof (vec3)*2+sizeof (vec2)+(__ptr)vbo));
		//mapAttribLocation(ATTRIB_TEXTURE2, 2, kDATA_TYPE_FLOAT, sizeof (VertexPosNormTex3), (const GLvoid*)(sizeof (vec3)*2+sizeof (vec2)*2+(__ptr)vbo));
		break;
	default:
		break;
	}
}

void Renderable::EndToGPU(VerTexType type, glm::vec4* extColor)
{
	switch (type) {
	case RM_P:
		glDisableVertexAttribArray(ATTRIB_VERTEX);
		break;
	case RM_P_N:
		break;
	case RM_P_T:
		glDisableVertexAttribArray(ATTRIB_VERTEX);
		glDisableVertexAttribArray(ATTRIB_TEXTURE0);
		break;
	case RM_P_N_T:
		glDisableVertexAttribArray(ATTRIB_VERTEX);
		glDisableVertexAttribArray(ATTRIB_NORMAL);
		glDisableVertexAttribArray(ATTRIB_TEXTURE0);
		break;
	case RM_P_C_T:
		glDisableVertexAttribArray(ATTRIB_VERTEX);
		glDisableVertexAttribArray(ATTRIB_COLOR);
		glDisableVertexAttribArray(ATTRIB_TEXTURE0);
		glDisableVertexAttribArray(ATTRIB_TEXTURE1);
		break;
	case RM_P_N_C_T:
		glDisableVertexAttribArray(ATTRIB_VERTEX);
		glDisableVertexAttribArray(ATTRIB_NORMAL);
		glDisableVertexAttribArray(ATTRIB_COLOR);
		glDisableVertexAttribArray(ATTRIB_TEXTURE0);
		glDisableVertexAttribArray(ATTRIB_TEXTURE1);
		break;
	case RM_P_C:
		glDisableVertexAttribArray(ATTRIB_VERTEX);
		glDisableVertexAttribArray(ATTRIB_COLOR);
		break;
	case RM_P_N_T_B:
		glDisableVertexAttribArray(ATTRIB_VERTEX);
		glDisableVertexAttribArray(ATTRIB_TEXTURE0);
		glDisableVertexAttribArray(ATTRIB_NORMAL);
		glDisableVertexAttribArray(ATTRIB_BONES_INDICES);
		glDisableVertexAttribArray(ATTRIB_BONES_WEIGHTS);
		break;
	default:
		break;
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	if (extColor) {
		glDisableVertexAttribArray(ATTRIB_COLOR);
	}
}

void Renderable::mapAttribLocation(glm::u32 index, glm::u32 componentsPerElement, DATA_TYPE type, glm::u32 stride, const void* ptr)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, componentsPerElement, type, GL_FALSE, stride, ptr);
}
