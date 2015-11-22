#include "Polygon.h"


void PolygonA::CreatePlane(float width, float height, MeshData &mesh)
{
	auto w2 = width / 2.0f;
	auto h2 = height / 2.0f;

	//Vertex Data
	Vertex vertex[4];
	//Pos           Normal              TexCoord      Tangent
	vertex[0] = Vertex(-w2, -h2, 0.0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0);
	vertex[1] = Vertex(+w2, -h2, 0.0, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0);
	vertex[2] = Vertex(-w2, +h2, 0.0, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0);
	vertex[3] = Vertex(+w2, +h2, 0.0, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0);

	mesh.VertexData.assign(vertex, vertex + 4);


	//Index Data
	GLuint index[6] = { 0, 1, 2, 1, 3, 2 };
	mesh.IndexData.assign(index, index + 6);

}

void PolygonA::CreateCube(float width, float height, float depth, MeshData &mesh)
{
	auto w2 = width / 2.0f;
	auto h2 = height / 2.0f;
	auto d2 = depth / 2.0f;

	Vertex vertex[24];

	vertex[0] = Vertex(-w2, -h2, -d2, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f);
	vertex[1] = Vertex(-w2, -h2, +d2, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, +1.0f, 0.0f, 0.0f);
	vertex[2] = Vertex(+w2, -h2, +d2, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f, +1.0f, 0.0f, 0.0f);
	vertex[3] = Vertex(+w2, -h2, -d2, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, +1.0f, 0.0f, 0.0f);

	vertex[4] = Vertex(-w2, +h2, -d2, 0.0f, +1.0f, 0.0f, 0.0f, 1.0f, +1.0f, 0.0f, 0.0f);
	vertex[5] = Vertex(-w2, +h2, +d2, 0.0f, +1.0f, 0.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f);
	vertex[6] = Vertex(+w2, +h2, +d2, 0.0f, +1.0f, 0.0f, 1.0f, 0.0f, +1.0f, 0.0f, 0.0f);
	vertex[7] = Vertex(+w2, +h2, -d2, 0.0f, +1.0f, 0.0f, 1.0f, 1.0f, +1.0f, 0.0f, 0.0f);

	vertex[8] = Vertex(-w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	vertex[9] = Vertex(-w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f);
	vertex[10] = Vertex(+w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f);
	vertex[11] = Vertex(+w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);

	vertex[12] = Vertex(-w2, -h2, +d2, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f);
	vertex[13] = Vertex(-w2, +h2, +d2, 0.0f, 0.0f, +1.0f, 0.0f, 1.0f, +1.0f, 0.0f, 0.0f);
	vertex[14] = Vertex(+w2, +h2, +d2, 0.0f, 0.0f, +1.0f, 1.0f, 1.0f, +1.0f, 0.0f, 0.0f);
	vertex[15] = Vertex(+w2, -h2, +d2, 0.0f, 0.0f, +1.0f, 1.0f, 0.0f, +1.0f, 0.0f, 0.0f);

	vertex[16] = Vertex(-w2, -h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, +1.0f);
	vertex[17] = Vertex(-w2, -h2, +d2, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, +1.0f);
	vertex[18] = Vertex(-w2, +h2, +d2, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, +1.0f);
	vertex[19] = Vertex(-w2, +h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, +1.0f);

	vertex[20] = Vertex(+w2, -h2, -d2, +1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f);
	vertex[21] = Vertex(+w2, -h2, +d2, +1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f);
	vertex[22] = Vertex(+w2, +h2, +d2, +1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f);
	vertex[23] = Vertex(+w2, +h2, -d2, +1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f);

	mesh.VertexData.assign(vertex, vertex + 24);

	GLuint index[] =
	{
		0, 2, 1, 0,
		3, 2, 4, 5,
		6, 4, 6, 7,
		8, 9, 10, 8,
		10, 11, 12, 15,
		14, 12, 14, 13,
		16, 17, 18, 16,
		18, 19, 20, 23,
		22, 20, 22, 21
	};
	mesh.IndexData.assign(index, index + 32);
}
