
#ifndef COOT_CYLINDER_WITH_ROTATION_TRANSLATION_HH
#define COOT_CYLINDER_WITH_ROTATION_TRANSLATION_HH

#include <vector>
#include "generic-vertex.hh"

// this is not the right way, I think. Perhaps use inheritance?
// But then we have to worry about the layout of the memory...
//
class cylinder_with_rotation_translation {
public:
   std::vector<vertex_with_rotation_translation> vertices;
   std::vector<g_triangle> triangle_indices_vec;
   cylinder_with_rotation_translation() {} // needs to be filled
   cylinder_with_rotation_translation(const std::pair<glm::vec3, glm::vec3> &cart_pair,
                                      float base_radius, float top_radius, float height,
                                      unsigned int n_slices, unsigned int n_stacks);
};

#endif
