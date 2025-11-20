#pragma once

#include <glm/glm.hpp>
#include <vector>

class SceneObject {
public:
  // constructor and destructor
  SceneObject();
  virtual ~SceneObject() = default;

  /// Set a new parent of this object, if a parent already exits it
  /// also removes this object from the parents children vector
  /// @param *newParent: pointer to the new parent SceneObject
  void setParent(SceneObject *newParent);
  /// get parent method, returns a pointer to the objects parent
  SceneObject *getParent() const;

  // transform access
  glm::mat4 &getLocalMatrix();

  /// Gets the model->world matrix
  /// Returns the matrix.
  glm::mat4 getWorldMatrix() const;
  // drawing

  /// Draw this object and all its children in the subgraph
  /// Usually used on the root object with an identity matrix glm::mat4
  /// m(1.0f);.
  /// \param parentMatrix the model->world matrix of the parent.
  void draw(const glm::mat4 &parentMatrix);

  /// Draw this object and all its children in the subgraph
  /// Usually used on the root object with an identity matrix glm::mat4
  /// m(1.0f);.
  /// \param parentMatrix the mode->world matrix of the parent.
  /// \param pass : Render pass index (0 = normal) subclasses can override
  /// drawSelf to support additional passes
  void draw(const glm::mat4 &parentMatrix, int pass);

  /// Draw this object. Override in subclasses to draw specific objects.
  /// Can also override to impliment multipass rendering
  ///
  /// Default it calls drawslef on pass 0 and does nothing on later passes.
  ///
  /// \param matrix: is the accumulated model-world transform.
  /// \param pass: use for multipass rendering by overriding method.
  virtual void drawSelf(const glm::mat4 &worldMatrix, int pass);

  /// Draw this object. Override in subclasses to draw specific objects.
  /// \param matrix: is the accumulated model-world transform.
  virtual void drawSelf(const glm::mat4 &worldMatrix);

protected:
  glm::mat4 localMatrix; // model -> parent transform

private:
  SceneObject *parent;                 // parent pointer (nullable)
  std::vector<SceneObject *> children; // child nodes
};
