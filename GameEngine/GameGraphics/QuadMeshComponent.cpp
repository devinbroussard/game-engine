#include "QuadMeshComponent.h"
#include "Vertex.h"
#include "gl_core_4_4.h"


int GameGraphics::QuadMeshComponent::initializeVertices()
{
		//Create vertex array
	const int VERTEX_COUNT = 4;
	Vertex vertices[VERTEX_COUNT];
	vertices[0].position = { -0.5f, -0.5f, 0.0f };
	vertices[0].color = { 0.2f, 0.2f, 0.3f, 1.0f };
	vertices[1].position = { 0.5f, 0.5f, 0.0f };
	vertices[1].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[2].position = { 0.5f, -0.5f, 0.0f };
	vertices[2].color = { 0.0f, 1.0f, 0.0f, 1.0f };
	vertices[3].position = {-.5f, 0.5f, 0.0f };
	vertices[3].color = { 0.0f, 0.0f, 1.0f, 1.0f };

	// Create idex array
	unsigned int indices[] = 
	{ 
		0, 1, 2,
		3, 0, 1
	};

	// Fill buffers
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	return 2;
}
