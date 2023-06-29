#include "CubeMeshComponent.h"
#include <GameGraphics/Vertex.h>
#include <GameGraphics/gl_core_4_4.h>

int GameGraphics::CubeMeshComponent::initializeVertices()
{
	//Create vertex array
	const int VERTEX_COUNT = 24;
	Vertex vertices[VERTEX_COUNT];
	vertices[0].position = { -0.5f, 0.5f, 0.5f }; //left top front
	vertices[1].position = { -0.5f, 0.5f, 0.5f }; //left top front
	vertices[2].position = { -0.5f, 0.5f, 0.5f }; //left top front
	vertices[3].position = { 0.5f, 0.5f, 0.5f }; //right top front
	vertices[4].position = { 0.5f, 0.5f, 0.5f }; //right top front
	vertices[5].position = { 0.5f, 0.5f, 0.5f }; //right top front
	vertices[6].position = { -0.5f, -0.5f, 0.5f }; //left bottom front
	vertices[7].position = { -0.5f, -0.5f, 0.5f }; //left bottom front
	vertices[8].position = { -0.5f, -0.5f, 0.5f }; //left bottom front
	vertices[9].position = { 0.5f, -0.5f, 0.5f }; //right bottom front
	vertices[10].position = { 0.5f, -0.5f, 0.5f }; //right bottom front
	vertices[11].position = { 0.5f, -0.5f, 0.5f }; //right bottom front
	vertices[12].position = { -0.5f, 0.5f, -0.5f }; //left top front
	vertices[13].position = { -0.5f, 0.5f, -0.5f }; //left top front
	vertices[14].position = { -0.5f, 0.5f, -0.5f }; //left top front
	vertices[15].position = { 0.5f, 0.5f, -0.5f }; //right top front
	vertices[16].position = { 0.5f, 0.5f, -0.5f }; //right top front
	vertices[17].position = { 0.5f, 0.5f, -0.5f }; //right top front
	vertices[18].position = { -0.5f, -0.5f, -0.5f }; //left bottom front
	vertices[19].position = { -0.5f, -0.5f, -0.5f }; //left bottom front
	vertices[20].position = { -0.5f, -0.5f, -0.5f }; //left bottom front
	vertices[21].position = { 0.5f, -0.5f, -0.5f }; //right bottom front
	vertices[22].position = { 0.5f, -0.5f, -0.5f }; //right bottom front
	vertices[23].position = { 0.5f, -0.5f, -0.5f }; //right bottom front

	vertices[0].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[1].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[2].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[3].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[4].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[5].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[6].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[7].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[8].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[9].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[10].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[11].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[12].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[13].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[14].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[15].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[16].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[17].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[18].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[19].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[20].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[21].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[22].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[23].color = { 1.0f, 0.0f, 0.0f, 1.0f };


	vertices[0].normal = { -1.0f, 0.0f, 0.0f }; // Left top front (left)
	vertices[1].normal = { 0.0f, 1.0f, 0.0f }; // Left top front (top)
	vertices[2].normal = { 0.0f, 0.0, 1.0f }; // Left top front (front)
	vertices[3].normal = { 1.0f, 0.0f, 0.0f }; // Right top front (right)
	vertices[4].normal = { 0.0f, 1.0f, 0.0f }; // Right top front (top)
	vertices[5].normal = { 0.0f, 0.0f, 1.0f }; // Right top front (front)
	vertices[6].normal = {-1.0f, 0.0f, 0.0f }; // Left bottom front (left)
	vertices[7].normal = { 0.0f, -1.0f, 0.0f }; // Left bottom front (bottom) 

	vertices[8].normal = { 0.0f, 0.0f, 1.0f }; // Left bottom front (front)
	vertices[9].normal = { 1.0f, 0.0f, 0.5f }; // Right bottom front (right)
	vertices[10].normal = { 0.0f, -1.0f, 0.0f }; // Right bottom front (bottom)
	vertices[11].normal = { 0.0f, 0.0f, 1.0f }; // Right bottom front (front)

	vertices[12].normal = { -1.0f, 0.0f, 0.0f }; // Left top back (back)
	vertices[13].normal = { 0.0f, 1.0f, 0.0f }; // Left top back (top)
	vertices[14].normal = { 0.0f, 0.0f, -1.0f }; // Left top back (top)
	vertices[15].normal = { 1.0f, 0.0f, 0.0f }; // Right top back

	vertices[16].normal = { 0.0f, 1.0f, 0.0f }; // Right top back (top)
	vertices[17].normal = { 0.0f, 0.0f, -1.0f }; // Right top back (back)
	vertices[18].normal = { -1.0f, 0.0f, 0.0f }; // Left bottom back (left)
	vertices[19].normal = { 0.0f, -1.0f, 0.0f }; // Left bottom back 

	vertices[20].normal = { 0.0f, 0.0f, -1.0f }; // Left bottom back (back)
	vertices[21].normal = { 1.0f, 0.0f, 0.0f }; // Right bottom back
	vertices[22].normal = { 0.0f, -1.0f, 0.0f }; // Left bottom back
	vertices[23].normal = { 0.0f, 0.0f, -1.0f }; // Right bottom back (back)

	// Create idex array
	unsigned int indices[] =
	{
		2,5,8,
		5,8,11,
		14,17,20,
		17,20,23,
		1,4,13,
		4,13,17,
		7,10,19,
		10,19,22,
		0,6,12,
		6,12,18,
		3,9,15,
		9,15,21
	};

	// Fill buffers
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	return 12;
}