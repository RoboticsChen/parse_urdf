import sys
import numpy as np
import xml.etree.ElementTree as ET


def parse_urdf(urdf_path):
    try:
        tree = ET.parse(urdf_path)
    except ET.ParseError:
        print('ERROR: Could not parse urdf file.')

    urdf_root = tree.getroot()
    urdf_joints = {}

    # Parse all joints and add to tree
    for child in urdf_root:
        if child.tag == 'joint':
            joint_name = child.get('name')
            for item in child:
                if item.tag == 'origin':
                    xyz = np.array(item.get('xyz').split(), dtype=float)
                    rpy = np.array(item.get('rpy').split(), dtype=float)
            urdf_joints[joint_name] = {'xyz': xyz, 'rpy': rpy}

    return urdf_joints


if __name__ == '__main__':
    if len(sys.argv) > 1:
        urdf_path = sys.argv[1]
    else:
        urdf_path = input("Please enter the URDF path: ")

    print("URDF Path:", urdf_path)

    urdf_param = parse_urdf(urdf_path)

    joint_index = 1
    for row in urdf_param:
        print(f"\nJoint Name: joint{joint_index}")
        print(f"  XYZ: {row[0]}, {row[1]}, {row[2]}")
        print(f"  RPY: {row[3]}, {row[4]}, {row[5]}")
        print()
        joint_index += 1
