#include <iostream>
#include "Vector3D.h"
#include "Point3D.h"
#include "Ray.h"
#include "Color.h"
#include "Camera.h"
#include "CameraManager.h"
#include "Picture.h"
#include "Triangle.h"
#include "Scene.h"
#include "SimpleTracer.h"
#include "RecursiveRayTracer.h"
#include "Sphere.h"
#include "Triangle.h"

void renderPicture(Picture& picture, Camera* camera, Tracer& tracer, int samplesPerPixel)
{
	for (int h = 0; h < picture.getHeight(); h++)
	{
		for (int w = 0; w < picture.getWidth(); w++)
		{
			for (int s = 0; s < samplesPerPixel; s++)
			{
				Ray sampleRay = camera->getSampleRayThroughPixel(w, h);
				Color color = tracer.traceSingleRay(sampleRay);
				picture.addPixelColor(w, h, color);
			}
		}
	}
}

void savePictureAndExit(Picture& picture, const char* filename)
{
	picture.printToFile(filename);
	std::cout << "Rendering into " << filename << " finished" << std::endl;
	std::cout << "Press enter to exit program!" << std::endl;
	std::cin.get();
}

int main()
{
	
	const int PIC_WIDTH = 600;
	const int PIC_HEIGHT = 600;
	const int SAMPLES_PER_PIXEL = 1;

	Picture picture(PIC_WIDTH, PIC_HEIGHT);

	CameraManager cameraManager;
	cameraManager.setupDefaultCameras();
	Camera* camera = cameraManager.getCamera(1);

	Scene scene;
	scene.buildTestScene02();

	//SimpleTracer tracer;
	RecursiveRayTracer tracer;
	tracer.setScene(scene);
	
	renderPicture(picture, camera, tracer, SAMPLES_PER_PIXEL);
	const char* fileName = "render01.ppm";
	savePictureAndExit(picture, fileName);
		
    return 0;
}