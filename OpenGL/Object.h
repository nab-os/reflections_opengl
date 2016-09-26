#pragma once

#include <string>
#include <vector>

#include <GL/glew.h>

// Includes GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <bullet/btBulletDynamicsCommon.h>

#include "ModelBullet.h"
#include "ModelRender.h"
#include "Material.h"

class Object
{

	public:

		Object();
		~Object();

		void load(btDiscreteDynamicsWorld* world = nullptr);
		void render(glm::mat4 &projection, glm::mat4 &view, glm::mat4 &model);

		void setRenderModel(Model* model);
		void setBulletModel(Model* model);

		Object* addObject(std::string path = "default");
		void addObject(Object* obj);
		std::vector<Object*> getObjects();

	private:

		ModelRender* m__renderModel;
		ModelBullet* m__bulletModel;

		std::vector<Object*> m__childs;

};
