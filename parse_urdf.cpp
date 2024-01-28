#include "parse_urdf.hpp"

std::vector<std::vector<double>> parse_urdf(const std::string &urdfPath) {
  std::vector<std::vector<double>> urdfParam(6, std::vector<double>(6, 0.0));
  int index = 0;
  try {
    std::ifstream file(urdfPath);
    std::vector<char> buffer((std::istreambuf_iterator<char>(file)),
                             std::istreambuf_iterator<char>());
    buffer.push_back('\0');

    rapidxml::xml_document<> doc;
    doc.parse<0>(&buffer[0]);

    rapidxml::xml_node<> *urdfRoot = doc.first_node();
    if (!urdfRoot) {
      std::cerr << "ERROR: Could not parse urdf file." << std::endl;
      return urdfParam;
    }

    for (rapidxml::xml_node<> *child = urdfRoot->first_node(); child;
         child = child->next_sibling()) {
      if (std::string(child->name()) == "joint") {
        std::string jointName = child->first_attribute("name")->value();
        index = std::stoi(std::string(1, jointName.back())) - 1;

        for (rapidxml::xml_node<> *item = child->first_node(); item;
             item = item->next_sibling()) {
          if (std::string(item->name()) == "origin") {
            std::string xyzStr = item->first_attribute("xyz")->value();
            std::string rpyStr = item->first_attribute("rpy")->value();

            // Parse xyz values
            size_t pos = 0;
            size_t endPos = 0;
            for (int i = 0; i < 3; ++i) {
              endPos = xyzStr.find(' ', pos);
              urdfParam[index][i] = std::stod(xyzStr.substr(pos, endPos - pos));
              pos = endPos + 1;
            }

            // Parse rpy values
            pos = 0;
            for (int i = 3; i < 6; ++i) {
              endPos = rpyStr.find(' ', pos);
              urdfParam[index][i] = std::stod(rpyStr.substr(pos, endPos - pos));
              pos = endPos + 1;
            }
          }
        }

      }
    }
  } catch (const rapidxml::parse_error &e) {
    std::cerr << "ERROR: Could not parse urdf file. " << e.what() << std::endl;
  }
  return urdfParam;
}



