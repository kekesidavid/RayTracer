#pragma once
#include <vector>
#include "GeometricObject.h"
#include "Point3D.h"
#include "Ray.h"
#include "Hit.h"
#include "Light.h"

class Scene
{
private:

	std::vector<const GeometricObject*> objects;
	std::vector<const Light*> lights;

	void deleteScene();
	void deleteLights();

public:

	Scene();
	~Scene();

	void addObject(const GeometricObject*);
	void addLight(const Light*);
	Hit getNearestIntersect(const Ray&) const;
	float distanceOfNearestIntersect(const Ray&) const;
	const Light* getLight() const;
	const std::vector<const Light*> getLights() const;

	void buildTestScene01();
	void buildTestScene02();
};