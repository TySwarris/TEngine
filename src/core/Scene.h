#pragma once

#include "SceneObject.h"
#include <glm/glm.hpp>

class Scene {
public:
  // constructor and destructor
  Scene();
  virtual ~Scene() = default;

  void update(float dt);

  void draw(const glm::mat4 &mvpMatrix);

  SceneObject *getRoot() { return &root; };

private:
  SceneObject root;
};
