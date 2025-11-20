#include "SceneObject.h"
#include <algorithm>

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

void SceneObject::draw(const glm::mat4 &parentMatrix, int pass) {
  glm::mat4 tempMatrix(1.0f);
  tempMatrix = parentMatrix * localMatrix;

  drawSelf(tempMatrix, pass);
  for (SceneObject *child : children) {
    child->draw(tempMatrix, pass);
  }
}

void SceneObject::draw(const glm::mat4 &parentMatrix) { draw(parentMatrix, 0); }

void SceneObject::drawSelf(const glm::mat4 &matrix) {
  // do nothing, for overriding.
}

void SceneObject::drawSelf(const glm::mat4 &matrix, int pass) {
  if (pass == 0) {
    drawSelf(matrix);
  }
}
