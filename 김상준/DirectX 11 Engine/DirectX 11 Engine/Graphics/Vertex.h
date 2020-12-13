#pragma once
#include <DirectXMath.h>

struct Vertex
{
	Vertex(float x, float y, float z, float u, float v)
	: pos(x, y, z), texCoord(u, v) {}

	Vertex() 
	: pos(0, 0, 0), texCoord(0, 0) {}

	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;
};