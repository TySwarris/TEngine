#include "SceneObject.h"
#include <algorithm>
#include <glm/ext/matrix_float4x4.hpp>

SceneObject::SceneObject() {
  localMatrix = glm::mat4(1.0f);
  parent = nullptr;
}

void SceneObject::setParent(SceneObject *newParent) {
  if (parent != nullptr) {
    parent->children.erase(
        std::remove(parent->children.begin(), parent->children.end(), this),
        parent->children.end());
  }
  this->parent = newParent;
  if (newParent != nullptr) {
    parent->children.push_back(this);
  }
}

SceneObject *SceneObject::getParent() const { return parent; }

glm::mat4 &SceneObject::getLocalMatrix() { return localMatrix; }

glm::mat4 SceneObject::getWorldMatrix() const {
  glm::mat4 result(1.0f);
  const SceneObject *o = this;

  while (o != nullptr) {
    result = o->localMatrix * result;
    o = o->parent;
  }
  return result;
}
