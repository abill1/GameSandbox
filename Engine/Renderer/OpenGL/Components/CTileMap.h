
#ifndef RENDERER_OPENGL_COMPONENTS_CTILEMAP_H
#define RENDERER_OPENGL_COMPONENTS_CTILEMAP_H

#include "../Vendor/glm/glm.hpp"
#include "../Vendor/glm/ext.hpp"

namespace OGL
{
	// TODO: Redo to work as an array of TRS matrices to work with the SSBO
	struct Tile
	{
		unsigned int p0;
		unsigned int p1;
		unsigned int p2;
		unsigned int p3;
	};

	class CTileMap
	{
	public:
		CTileMap();
		~CTileMap();

		void CreateMap(int _xTilesCount, int _yTilesCount, float _xAspect, float _yAspect);
		void SetTile(int _x, int _y, glm::vec4 _color);

	public:
		struct Vertex* pVertices;
		struct TriangleIndex* pIndices;
		size_t m_vertexCount;
		size_t m_indexCount;
		Tile** map;
		int m_numOfTiles;


	};
}

#endif // !RENDERER_OPENGL_COMPONENTS_CTILEMAP_H

