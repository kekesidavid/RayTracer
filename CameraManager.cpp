#include "Camera.h"
#include "CameraManager.h"
#include "SimpleUnitSquareSampler.h"
#include "JitteredUnitSquareSampler.h"

CameraManager::CameraManager()
{
	cameraCount = 0;
	cameras = new Camera*[MAX_CAMERAS];
}

CameraManager::~CameraManager()
{
	deleteCameras();
	delete sampler;
}

void CameraManager::addCamera(Camera* cam)
{
	if (cameraCount < MAX_CAMERAS)
	{
		cameras[cameraCount] = cam;
		cameraCount++;
	}
}

Camera* CameraManager::getCamera(int n) const
{
	if (n < cameraCount)
	{
		return cameras[n];
	}
	else
	{
		return nullptr;
	}
}

void CameraManager::setupDefaultCameras()
{
	//sampler = new SimpleUnitSquareSampler;
	sampler = new JitteredUnitSquareSampler;

	//setting up cam1
	Camera* cam1 = new Camera(600, 600);
	cam1->setPosition(Point3D(0, 0, 100));
	cam1->setDirection(Vector3D(0, 0, -1));
	cam1->setLength(3000.0f);
	cam1->setSampler(sampler);
	addCamera(cam1);

	//setting up cam2
	Camera* cam2 = new Camera(600, 600);
	cam2->setPosition(Point3D(7, -150, 70));
	cam2->setDirection(Vector3D(7, 100, -27));
	cam2->setLength(1000.0f);
	cam2->setSampler(sampler);
	addCamera(cam2);

	//setting up cam3
	//...
}

void CameraManager::deleteCameras()
{
	for (int i = 0; i < cameraCount; i++)
	{
		delete cameras[i];
	}
	delete[] cameras;
}