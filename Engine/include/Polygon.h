#ifndef Polygon_H
#define Polygon_H

#include <vector>
#include <glm/glm.hpp>
#include <gl/glew.h>
struct Vertex
{
	Vertex() = default;
	Vertex(const glm::vec3 &pos, const glm::vec3 &normal, const glm::vec2 &tc, const glm::vec3 &ta)
		: Pos(pos), Normal(normal), Tex(tc), Tangent(ta) {}

	Vertex(float px, float py, float pz,
		float nx, float ny, float nz,
		float u, float v,
		float ta, float tb, float tc)
		: Pos(px, py, pz), Normal(nx, ny, nz), Tex(u, v), Tangent(ta, tb, tc) {}

	glm::vec3 Pos;
	glm::vec3 Normal;
	glm::vec2 Tex;
	glm::vec3 Tangent;
};

struct MeshData
{
	std::vector<Vertex> VertexData;
	std::vector<GLuint> IndexData;
};

class PolygonA
{
public:
	void CreatePlane(float width, float height, MeshData &mesh);
	void CreateCube(float width, float height, float depth, MeshData &mesh);

	void CreateGrid();
	void CreateSphere();
	//void CreateCylinder();
	//void CreateTorus();
	//void CreatePipe();
	//void CreateCone();


};
#endif

