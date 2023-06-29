#include "MeshComponent.h"
#include "gl_core_4_4.h"
#include "Vertex.h"

GameGraphics::MeshComponent::~MeshComponent()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
	glDeleteBuffers(1, &m_vertexBufferObject);
	glDeleteBuffers(1, &m_indexBufferObject);
}

void GameGraphics::MeshComponent::onStart()
{
	glGenBuffers(1, &m_vertexBufferObject);
	glGenBuffers(1, &m_indexBufferObject);
	glGenVertexArrays(1, &m_vertexArrayObject);

	glBindVertexArray(m_vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferObject);

	initializeVertices();


	m_triCount = initializeVertices();

	// Assign position to location 3
	int location = 3;
	glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(location);

	// Assign color to location 4
	location = 4;
	glVertexAttribPointer(location, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(GameMath::Vector3));
	glEnableVertexAttribArray(location);

	// Assign normal to location 5
	location = 5;
	glVertexAttribPointer(location, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)(sizeof(GameMath::Vector3) + sizeof(GameMath::Vector4)));
	glEnableVertexAttribArray(location);

	// Assign surface ambient to location 6
	location = 6;
	glVertexAttribPointer(location, 3, GL_FLOAT, GL_TRUE, sizeof(GameMath::Vector3), (void*)sizeof(float));
	glEnableVertexAttribArray(location);


	// Unbind vertices
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int GameGraphics::MeshComponent::initializeVertices()
{

	//Create vertex array
	const int VERTEX_COUNT = 3;
	Vertex vertices[VERTEX_COUNT];
	vertices[0].position = { -0.5f, -0.5f, 0.0f };
	vertices[0].color = { 1.0f, 0.0f, 0.0f, 1.0f };
	vertices[1].position = { 0.5f, -0.5f, 0.0f };
	vertices[1].color = { 0.0f, 1.0f, 0.0f, 1.0f };
	vertices[2].position = { 0.0f, 0.5f, 0.0f };
	vertices[2].color = { 0.0f, 0.0f, 1.0f, 1.0f };

	unsigned int indices[] = { 0, 1, 2 };

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	return 1;
}

void GameGraphics::MeshComponent::onDraw()
{
	// Sets the surface ambient.
	glUniform3f(6, m_material.ambient.x, m_material.ambient.y, m_material.ambient.z);
	glUniform3f(7, m_material.diffuse.x, m_material.diffuse.y, m_material.diffuse.z);
	glUniform3f(8, m_material.specular.x, m_material.specular.y, m_material.specular.z);

	// Sets the u_Model to the global matrix.
	GameMath::Matrix4 modelMatrix = getGlobalMatrix();
	glUniformMatrix4fv(0, 1, GL_TRUE, &(modelMatrix.m00));

	glBindVertexArray(m_vertexArrayObject);
	glDrawElements(GL_TRIANGLES, m_triCount * 3, GL_UNSIGNED_INT, 0);
}
