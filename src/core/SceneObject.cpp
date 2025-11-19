#include "SceneObject.h"
#include <algorithm>
#include <cstddef>

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

SceneObject SceneObject::*getparent() { return parent; }
