#include "rapidxml.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief parse urdf parameters from the urdf file
 * @return `vector<vector<double>>`: The first dim is joint_index - 1, and 
 * the second dim containing the corresponding x,y,z,r,p,y of the joint
 */
std::vector<std::vector<double>> parse_urdf(const std::string &urdfPath);