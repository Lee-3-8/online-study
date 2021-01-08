#pragma once
#include <DirectXMath.h>

struct Vertex
{
	Vertex(float x, float y, float z, float u, float v, float nx, float ny, float nz)
	: pos(x, y, z), texCoord(u, v), normal(nx, ny, nz) {}

	Vertex() 
	: pos(0, 0, 0), texCoord(0, 0), normal(0, 0, 0) {}

	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;
	DirectX::XMFLOAT3 normal;
};