#pragma once

#include <glm/glm.hpp>
#include <vector>

class SceneObject {
public:
  // constructor and destructor
  SceneObject();
  virtual ~SceneObject() = default;

  // parent/child relations
  void setParent(SceneObject *newParent);
  // get parent method, returns a pointer to the objects parent
  SceneObject *getParent() const;

  // transform access
  glm::mat4 &getLocalMatrix();
  glm::mat4 getWorldMatrix() const;

  // drawing
  void draw(const glm::mat4 &parentMatrix);
  virtual void drawSelf(const glm::mat4 &worldMatrix);

protected:
  glm::mat4 localMatrix; // model -> parent transform

private:
  SceneObject *parent;                 // parent pointer (nullable)
  std::vector<SceneObject *> children; // child nodes
};
