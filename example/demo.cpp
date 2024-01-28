#include "parse_urdf.hpp"

int main(int argc, char *argv[]) {
  std::string urdfPath;

  if (argc > 1) {
    urdfPath = argv[1];
  } else {
    std::cout << "Please enter the URDF path: ";
    std::cin >> urdfPath;
  }

  std::cout << "URDF Path: " << urdfPath << std::endl;
  std::vector<std::vector<double>> urdfParam = parse_urdf(urdfPath);

  int jointIndex = 1;
  for (const auto &row : urdfParam) {
    std::cout << "Joint Name: joint" << jointIndex << std::endl;
    std::cout << "  XYZ: " << row[0] << ", " << row[1] << ", " << row[2]
              << std::endl;
    std::cout << "  RPY: " << row[3] << ", " << row[4] << ", " << row[5]
              << std::endl;
    std::cout << std::endl;

    jointIndex++;
  }

  return 0;
}