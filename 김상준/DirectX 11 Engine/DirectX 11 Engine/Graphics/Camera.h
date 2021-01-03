#pragma once
#include <DirectXMath.h>
#include "GameObject.h"
using namespace DirectX;

class Camera: public GameObject
{
public:
	Camera();
	void SetProjectionValues(float fovDegrees, float aspectRatio, float nearZ, float farZ);
	void SetLookAtPos(XMFLOAT3 lookAtPos);

	const XMMATRIX& GetViewMatrix() const;
	const XMMATRIX& GetProjectionMatrix() const;

private:
	void UpdateMatrix() override;

	XMMATRIX viewMatrix;
	XMMATRIX projectionMatrix;
};