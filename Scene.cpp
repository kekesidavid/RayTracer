#include <vector>
#include "Scene.h"
#include "GeometricObject.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Sphere.h"
#include "Ray.h"
#include "Hit.h"
#include "AppConstants.h"
#include "Materials.h"
#include "Colors.h"
#include "Light.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	deleteScene();
	deleteLights();
}

void Scene::addObject(const GeometricObject* object)
{
	objects.push_back(object);
}

void Scene::addLight(const Light* light)
{
	lights.push_back(light);
}

Hit Scene::getNearestIntersect(const Ray& ray) const
{
	Hit hit;
	float minDist = appconst::MAX_DIST;

	for (const GeometricObject* object : objects)
	{
		float distance = object->intersect(ray);
		if ((distance < minDist) && (distance > appconst::MIN_DIST))
		{
			minDist = distance;
			hit = Hit(object, ray, distance);
		}
	}
	return hit;
}

float Scene::distanceOfNearestIntersect(const Ray& ray) const
{
	float minDist = appconst::MAX_DIST;

	for (const GeometricObject* object : objects)
	{
		float distance = object->intersect(ray);
		if ((distance < minDist) && (distance > appconst::MIN_DIST))
		{
			minDist = distance;
		}
	}
	return minDist;
}

const Light* Scene::getLight() const
{
	return lights[0];
}

const std::vector<const Light*> Scene::getLights() const
{
	return lights;
}

void Scene::buildTestScene01()
{
	Light* light = new Light();
	light->setPosition(Point3D (-5, 3, 10));
	light->setColor(colors::WHITE);
	addLight(light);

	Triangle* t1 = new Triangle(Point3D(-10, 10, 0), Point3D(-10, 8, 0), Point3D(-8, 10, 0));
	t1->setMaterial(&materials::DIFFUSE_MAGENTA);
	addObject(t1);

	Triangle* t2 = new Triangle(Point3D(10, 10, 0), Point3D(8, 10, 0), Point3D(10, 8, 0));
	t2->setMaterial(&materials::DIFFUSE_YELLOW);
	addObject(t2);

	Triangle* t3 = new Triangle(Point3D(10, -10, 0), Point3D(10, -8, 0), Point3D(8, -10, 0));
	t3->setMaterial(&materials::DIFFUSE_CYAN);
	addObject(t3);

	Triangle* t4 = new Triangle(Point3D(-10, -10, 0), Point3D(-8, -10, 0), Point3D(-10, -8, 0));
	t4->setMaterial(&materials::DIFFUSE_WHITE);
	addObject(t4);

	Sphere* s1 = new Sphere(Point3D(0, 0, 0), 2.0f);
	s1->setMaterial(&materials::DIFFUSE_BLUE);
	addObject(s1);
}

void Scene::buildTestScene02()
{
	//array of lights (soft shadows)
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Light* light = new Light();
			light->setPosition(Point3D(-40 + j * (-2), -40 + i * (-2), 100));
			light->setColor(colors::WHITE);
			light->setIntensity(1000.0f);
			addLight(light);
		}
	}
	
	//adding objects
	Rectangle* r1 = new Rectangle(180, 140, Point3D(-90, -88, 0), Vector3D(0, 0, 1));
	r1->setMaterial(&materials::TEXTURED_RAINBOW_CHECKER);
	addObject(r1);

	Rectangle* r2 = new Rectangle(400, 200, Point3D(-200, 50, 0), Vector3D(0, -1, 0));
	r2->setMaterial(&materials::TEXTURED_CONCRETE);
	addObject(r2);
	
	Sphere* s1 = new Sphere(Point3D(27, 10, 5), 5);
	s1->setMaterial(&materials::DIFFUSE_CORAL);
	addObject(s1);

	Sphere* s2 = new Sphere(Point3D(-7, 10, 10), 10);
	s2->setMaterial(&materials::DIFFUSE_EARTH);
	addObject(s2);

	Sphere* s3 = new Sphere(Point3D(6, 0, 13), 13);
	s3->setMaterial(&materials::REFRACTIVE_GLASS);
	addObject(s3);

	Sphere* s4 = new Sphere(Point3D(40, 30, 19), 19);
	s4->setMaterial(&materials::REFLECTIVE_GOLD);
	addObject(s4);

	Sphere* s5 = new Sphere(Point3D(35, -23, 8), 8);
	s5->setMaterial(&materials::DIFFUSE_GRASS);
	addObject(s5);
}

void Scene::deleteScene()
{
	for (const GeometricObject* object : objects)
	{
		delete object;
	}
}

void Scene::deleteLights()
{
	for (const Light* light : lights)
	{
		delete light;
	}
}