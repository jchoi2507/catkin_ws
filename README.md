My ROS1 Noetic catkin workspace mainly for [this project](https://github.com/jchoi2507/Robotic_Quadruped)
# Environment Setup

1. Because my setup was headless (monitorless) and the server image (desktopless) of Ubuntu was flashed onto the Raspberry Pi, opening multiple terminals for different nodes was done with a terminal multiplexer, [tmux](https://github.com/tmux/tmux/wiki):

    <code>sudo apt install tmux</code>

2. Source environment (or add to <code>~/.bashrc</code>):

    <code>source /opt/ros/noetic/setup.bash</code> </br>
    <code>source ~/catkin_ws/devel/setup.bash</code> </br>
    <code>export PATH="$HOME/bin:$PATH"</code>
    

3. Run the bash script in <code>~/bin/dev</code> to automatically bring up this screen layout:

<img src="https://github.com/jchoi2507/catkin_ws/blob/main/bin/Screenshot%202023-04-26%20at%203.11.01%20PM.png" width="750" height="500">

# Catkin Workspace File Tree
```bash
├── build
├── devel
└── src
    ├── CMakeLists.txt
    └── robotic_quadruped_pkg
        ├── CMakeLists.txt
        ├── launch
        ├── include
        ├── package.xml
        └── src
            ├── test_files
            ├── Nicla_node.cpp
            ├── RP2040_node1.cpp
            ├── RP2040_node2.cpp
            ├── camera_servo_node.cpp
            ├── keyboard_node.cpp
```
