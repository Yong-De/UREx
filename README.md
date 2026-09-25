# Embedded system component

## Installation and usage

TBD

## Justification

### Why ROS 2?

I have identified 3 middleware frameworks implemented by NASA in
robotics sent into space: Core Flight System(cFS), F Prime(F') and
ROS 2.

Listed examples of usage:

- cFS: [James Webb Space Telescope](https://etd.gsfc.nasa.gov/capabilities/capabilities-listing/cfs/)
- F': [NASA's Ingenuity Mars Helicopter](https://www.jpl.nasa.gov/news/meet-the-open-source-software-powering-nasas-ingenuity-mars-helicopter/)
- ROS: [Astrobee](https://nasa.github.io/astrobee/v/develop/index.html)

#### Ecosystem Advantage

Compared to cFS and F', ROS has a massive open-source ecosystem.
This includes community tested bridges for software other teams
might choose to use such as MATLAB, Unity and Gazebo.
In addition, most robotic arms on the market  actively support ROS 2
integration including [Elephant Robotics](https://github.com/elephantrobotics/mycobot_ros2)
and [Seedstudio](https://github.com/Seeed-Projects/reBot-DevArm)
which gives the other groups the flexibility to select the best arm
for their use case. Similarly, Intel's RealSense depth-camera is on
ROS 2 by default.

#### What cFS and F' are used for

cFS and F' on the other hand, are flight-software frameworks for
single onboard flight computers, and not general-purpose robotics
middleware. A quick comparison finds that F' is better suited
for smaller scale projects while cFS are for larger missions.

#### Custom implementation

Custom implementation is another alternative that could offer the
biggest efficiency benefits, but due to the time constraints of this
project, it is not feasible to consider proper implementation
without halting the progress of the project as a whole.

| Middleware Framework | Uses | Deciding factor |
| --- | --- | --- |
| ROS 2 | Most commercial robotics | Existing drivers for common arm/camera hardware and simulation tools. |
| F' (F Prime) | Small low budget flight missions | Better suited for single computer command and data handling |
| cFS (Core Flight System) | Larger flight missions | Better suited for single computer command and data handling |
| Custom | When high efficiency and precision matters | Time constraints of the project |

## Current progress

- Architecture decided (ROS 2 + DDS)
- `CameraTarget.msg` defined and wired up

## Project timeline (October to November)

| Month | Objective |
| --- | --- |
| Sept | Architecture decided |
| Oct | Message set + QoS |
| Nov | Integration demo |

## Final objective

A working, documented ROS 2/DDS middleware layer with defined
messaging types for robot state, demonstrated by at least 1 real
integration with another team's project.

## References

1. S. L. Peet, S. M. Gilliland, and J. S. Young, "The Framework Makes the
Mission - An Analytical Comparison of Two Popular NASA Open Source Flight Software
Framework Offerings," in Proceedings of the 38th Annual AIAA/USU Conference on
Small Satellites, Logan, UT, 2024, Paper SSC24-P4-02. [Online].
Available: <https://digitalcommons.usu.edu/cgi/viewcontent.cgi?article=6013&context=smallsat>
