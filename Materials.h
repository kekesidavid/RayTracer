#pragma once
#include "Color.h"
#include "Colors.h"
#include "Material.h"
#include "DiffuseMaterial.h"
#include "ReflectiveMaterial.h"
#include "RefractiveMaterial.h"
#include "TexturedMaterial.h"
#include "Texture.h"
#include "Textures.h"

namespace materials
{
	const DiffuseMaterial DIFFUSE_RED(colors::RED);
	const DiffuseMaterial DIFFUSE_GREEN(colors::GREEN);
	const DiffuseMaterial DIFFUSE_BLUE(colors::BLUE);

	const DiffuseMaterial DIFFUSE_MAGENTA(colors::MAGENTA);
	const DiffuseMaterial DIFFUSE_CYAN(colors::CYAN);
	const DiffuseMaterial DIFFUSE_YELLOW(colors::YELLOW);

	const DiffuseMaterial DIFFUSE_BLACK(colors::BLACK);
	const DiffuseMaterial DIFFUSE_WHITE(colors::WHITE);

	const DiffuseMaterial DIFFUSE_CORAL(colors::CORAL);
	const DiffuseMaterial DIFFUSE_SUN(colors::SUN);
	const DiffuseMaterial DIFFUSE_GRASS(colors::GRASS);
	const DiffuseMaterial DIFFUSE_EARTH(colors::EARTH);
	const DiffuseMaterial DIFFUSE_GRAY(colors::GRAY);
	const DiffuseMaterial DIFFUSE_LIGHTGRAY(colors::LIGHT_GRAY);

	const ReflectiveMaterial REFLECTIVE_GOLD(colors::GOLD);
	const RefractiveMaterial REFRACTIVE_GLASS(colors::GLASS, 1.5f);

	const TexturedMaterial TEXTURED_WOOD(&textures::WOOD);
	const TexturedMaterial TEXTURED_CONCRETE(&textures::CONCRETE);
	const TexturedMaterial TEXTURED_BW_CHECKER(&textures::BW_CHECKER);
	const TexturedMaterial TEXTURED_UV_CHECKER(&textures::UV_CHECKER);
	const TexturedMaterial TEXTURED_RAINBOW_CHECKER(&textures::RAINBOW_CHECKER);
}