#include "Scene.h"

Scene::Scene() {
  // spawn objects here later
  //
}

void Scene::update(float dt) {
  // for updating objects
}

void Scene::draw(const glm::mat4 &mvpMatrix) { root.draw(mvpMatrix); }
