### just put the hpp file and cpp files into your project, then you can parse the urdf file by just calling the function parse_urdf()

## Usage
```cpp
/**
 * @brief parse urdf parameters from the urdf file
 * @return `vector<vector<double>>`: The first dim is joint_index - 1, and 
 * the second dim containing the corresponding x,y,z,r,p,y of the joint
 */
std::vector<std::vector<double>> parse_urdf(const std::string &urdfPath);
```
