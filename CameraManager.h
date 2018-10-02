#pragma once
#include "Camera.h"
#include "UnitSquareSampler.h"
#include "SimpleUnitSquareSampler.h"

class CameraManager
{
private:

	const int MAX_CAMERAS = 32;
	int cameraCount;
	Camera** cameras;
	UnitSquareSampler* sampler;

	void deleteCameras();

public:

	CameraManager();
	~CameraManager();

	void addCamera(Camera*);
	Camera* getCamera(int) const;
	void setupDefaultCameras();
};