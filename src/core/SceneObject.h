#pragma once

#include <glm/ext/matrix_float4x4.hpp>
#include <glm/mat4x4.hpp>
#include <vector>

class SceneObject {
public:
  // Constructor and destructor
  SceneObject();
  virtual ~SceneObject() = default;

  // Parent/Child relations
  void setParent(SceneObject *Parent);
  // get parent method, returns a pointer to the objects parent
  SceneObject *getParent() const;

  void addChild(SceneObject *child);
  void removeChild(SceneObject *child);

  // transform access
  glm::mat4 &getLocalMatrix();
  glm::mat4 getWorldMatrix() const;

  // drawing
  void draw(const glm::mat4 &parentMatrix);
  virtual void drawSelf(const glm::mat4 &worldMatrix);

protected:
  glm::mat4 localMatrix; // nidek -> parent transform

private:
  SceneObject *parent;                 // parent pointer (nullable)
  std::vector<SceneObject *> children; // child nodes
};
