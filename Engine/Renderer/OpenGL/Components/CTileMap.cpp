#include "CTileMap.h"
#include "../Renderer/OpenGL/DataStructures/OGLDataStructures.h"

OGL::CTileMap::CTileMap()
	:pVertices(nullptr), pIndices(nullptr), m_vertexCount(0), m_indexCount(0), map(nullptr), m_numOfTiles(0)
{

}

OGL::CTileMap::~CTileMap()
{
	delete[] pVertices;
	delete[] pIndices;
	for (int i = 0; i < m_numOfTiles; i++)
		delete[] map[i];
	delete[] map;
	m_numOfTiles = 0;
	m_vertexCount = 0;
	m_indexCount = 0;
}

void OGL::CTileMap::CreateMap(int _xTilesCount, int _yTilesCount, float _xAspect, float _yAspect)
{
	this->m_numOfTiles = _xTilesCount * _yTilesCount;

	// ----- Determine length between points in the vertices
	const float xlen = (2.0f * _xAspect) / (float)_xTilesCount;
	const float ylen = (2.0f * _yAspect) / (float)_yTilesCount;
	float startPosx = -_xAspect;
	float startPosy = -_yAspect;

	// ----- Calculate the vertex and index array size needed
	int trianglesPerRow = (2 * this->m_numOfTiles);
	int xVerts = this->m_numOfTiles * 4;
	int yOffset = 2 * m_numOfTiles;
	int xOffset = 2 * yOffset;
	this->m_vertexCount = (size_t)yOffset * (size_t)yOffset;
	this->m_indexCount = (size_t)(this->m_numOfTiles * this->m_numOfTiles) * 2U;

	// ----- Cleanup to ensure no leakage. Not ideal but this method should never be called in a game loop
	delete[] pVertices;
	delete[] pIndices;

	// ----- Create the vertex, index, and map arrays
	this->pVertices = new OGL::Vertex[this->m_vertexCount];
	this->pIndices = new OGL::TriangleIndex[this->m_indexCount];
	this->map = new Tile*[this->m_numOfTiles];
	for (int i = 0; i < this->m_numOfTiles; i++)
	{
		this->map[i] = new Tile[this->m_numOfTiles];
	}

	// ----- Set the vertex, index, and map data
	for (int i = 0; i < _yTilesCount; i++)
	{
		float y0 = startPosy + ((float)i * ylen);
		float y1 = y0 + ylen;
		for (int j = 0; j < _xTilesCount; j++)
		{
			float x0 = startPosx + ((float)j * xlen);
			float x1 = x0 + xlen;
			unsigned int index = (unsigned int)(i * xVerts) + (unsigned int)(j * 4U);
			pVertices[index] =   { {  x0, y0, 0.0f, 1.0f}, {x0, y0, 0.0f, 1.0f}, {0.0f, 0.0f} };
			pVertices[index+1U] = { {  x0, y1, 0.0f, 1.0f}, {x0, y1, 0.0f, 1.0f}, {0.0f, 0.0f} };
			pVertices[index+2U] = { {  x1, y1, 0.0f, 1.0f }, { x1, y1, 0.0f, 1.0f }, { 1.0f, 0.0f } };
			pVertices[index+3U] = { {  x1, y0, 0.0f, 1.0f }, { x1, y0, 0.0f, 1.0f }, { 1.0f, 0.0f } };

			int t = (i * trianglesPerRow) + (j * 2);
			pIndices[t] = { index, index + 1U, index + 2U };
			pIndices[t + 1] = { index, index + 2U, index + 3U };

			this->map[j][i] = { index , index + 1 , index + 2 , index + 3 };
		}

	}

}

void OGL::CTileMap::SetTile(int _x, int _y, glm::vec4 _color)
{
	Tile t = this->map[_x][_y];
	pVertices[t.p0].m_Color = _color;
	pVertices[t.p1].m_Color = _color;
	pVertices[t.p2].m_Color = _color;
	pVertices[t.p3].m_Color = _color;
}
