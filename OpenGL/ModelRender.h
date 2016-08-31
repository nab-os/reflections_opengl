#pragma once

#include <vector>

#include "Model.h"


#ifndef BUFFER_OFFSET

	#define BUFFER_OFFSET(offset) ((char*)NULL + (offset))

#endif

class ModelRender :	public Model
{

	public:

		explicit ModelRender();
		explicit ModelRender(const ModelRender*);
		virtual ~ModelRender();

		void computeTangentBasis(
			// inputs
			std::vector<glm::vec3> & vertices,
			std::vector<glm::vec2> & uvs,
			std::vector<glm::vec3> & normals,

			// outputs
			std::vector<glm::vec3> & tangents,
			std::vector<glm::vec3> & bitangents);

		void load();
		void render(glm::mat4 &projection, glm::mat4 &view, glm::mat4 &model);

		GLuint& getVAO();
		GLuint& getVBO();

		int getUVCount();
		int getUVsSize();
		std::vector<glm::vec2> getUVs();
		float* getUVsFloat();

		int getNormalCount();
		int getNormalsSize();
		std::vector<glm::vec3> getNormals();
		float* getNormalsFloat();

	private :

		GLuint m__VAO;
		GLuint m__VBO;

		std::vector<glm::vec2> m__UVs;
		std::vector<glm::vec3> m__normals;

};

