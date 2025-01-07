^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package ign_ros2_control
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

2.0.3 (2024-12-11)
------------------

2.0.2 (2024-10-28)
------------------
* use gz-physics`#283 <https://github.com/ros-controls/gz_ros2_control/issues/283>`_ to implement joint_states/effort feedback (`#186 <https://github.com/ros-controls/gz_ros2_control/issues/186>`_) (`#430 <https://github.com/ros-controls/gz_ros2_control/issues/430>`_)
  (cherry picked from commit cc66e7342c6954bd5c3950e12a45567e2ca1652c)
  Co-authored-by: Andreas Bihlmaier <andreas.bihlmaier@gmx.de>
* Contributors: mergify[bot]

2.0.1 (2024-08-26)
------------------
* Parse `position_proportional_gain` parameter from URDF and update docs (`#393 <https://github.com/ros-controls/gz_ros2_control/issues/393>`_)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
* propagate gazebo remapping and other arguments to the controller node (`#396 <https://github.com/ros-controls/gz_ros2_control/issues/396>`_)
* Contributors: Christoph Fröhlich, Sai Kishor Kothakota

2.0.0 (2024-07-09)
------------------
* Propagate the node clock and logging interface (`#368 <https://github.com/ros-controls/gz_ros2_control/issues/368>`_)
* Update docs and cleanup member of `GazeboSimROS2ControlPluginPrivate` (`#363 <https://github.com/ros-controls/gz_ros2_control/issues/363>`_)
* Contributors: Christoph Fröhlich, Sai Kishor Kothakota

1.3.1 (2024-07-02)
------------------
* Simplify access for robot description from CM by overriding RM. (`#265 <https://github.com/ros-controls/gz_ros2_control/issues/265>`_)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
  Co-authored-by: Sai Kishor Kothakota <saisastra3@gmail.com>
* Harden behavior if a joint is not found in the model (`#325 <https://github.com/ros-controls/gz_ros2_control/issues/325>`_)
  * Don't crash if a joint does not exist
* Don't crash if a wrong config was detected (`#324 <https://github.com/ros-controls/gz_ros2_control/issues/324>`_)
* Changed to use spin instead of spin_once to enable multithreading with MultiThreadedExecutor (`#315 <https://github.com/ros-controls/gz_ros2_control/issues/315>`_)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
* Contributors: Christoph Fröhlich, Dr. Denis, Takashi Sato

1.3.0 (2024-05-14)
------------------
* Use Gazebo ROS vendor packages (`#277 <https://github.com/ros-controls/gz_ros2_control/issues/277>`_)
* fixed target of ament_export_libraries (`#295 <https://github.com/ros-controls/gz_ros2_control/issues/295>`_)
* fixed install include (`#294 <https://github.com/ros-controls/gz_ros2_control/issues/294>`_)
* Added parameters robot_param and robot_param_node (`#275 <https://github.com/ros-controls/gz_ros2_control/issues/275>`_) (`#280 <https://github.com/ros-controls/gz_ros2_control/issues/280>`_)
  (cherry picked from commit 53b6c74b02bf85860854a37f429b6e2ecf22a4be)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
* Rewrite mimic joints (`#276 <https://github.com/ros-controls/gz_ros2_control/issues/276>`_)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
* Fixed linter (`#264 <https://github.com/ros-controls/gz_ros2_control/issues/264>`_)
* Fix `#259 <https://github.com/ros-controls/gz_ros2_control/issues/259>`_ - `ParameterAlreadyDeclaredException` for parameter `position_proportional_gain` (`#261 <https://github.com/ros-controls/gz_ros2_control/issues/261>`_)
* Contributors: Addisu Z. Taddese, Alejandro Hernández Cordero, Christoph Fröhlich, Patrick Roncagliolo, Takashi Sato, mergify[bot]

1.2.2 (2024-03-21)
------------------
* Fix typo (`#253 <https://github.com/ros-controls/gz_ros2_control/issues/253>`_)
* Fix `#247 <https://github.com/ros-controls/gz_ros2_control/issues/247>`_ (`#248 <https://github.com/ros-controls/gz_ros2_control/issues/248>`_)
* Reset Gazebo with initial joint positions and velocities (`#241 <https://github.com/ros-controls/gz_ros2_control/issues/241>`_)
* Use portable versio for usleep (`#237 <https://github.com/ros-controls/gz_ros2_control/issues/237>`_)
* Fix crashing due to an invalid parameter in the initial value (`#233 <https://github.com/ros-controls/gz_ros2_control/issues/233>`_)
* Contributors: Alejandro Hernández Cordero, Graziato Davide, Ruddick Lawrence, Stephanie Eng

1.2.1 (2024-01-24)
------------------
* Load the URDF to the resource_manager before parsing it to CM (`#222 <https://github.com/ros-controls/gz_ros2_control/issues/222>`_)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
* Use own implementation of `stod()` (`#220 <https://github.com/ros-controls/gz_ros2_control/issues/220>`_)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
* Contributors: Christoph Fröhlich, Sai Kishor Kothakota

1.2.0 (2024-01-04)
------------------
* Add controller name parameter (backport `#212 <https://github.com/ros-controls/gz_ros2_control/issues/212>`_) (`#216 <https://github.com/ros-controls/gz_ros2_control/issues/216>`_)
  Co-authored-by: Jakub Delicat <109142865+delihus@users.noreply.github.com>
  Co-authored-by: Alejandro Hernandez Cordero <ahcorde@gmail.com>
* Add hold_joints parameter (`#213 <https://github.com/ros-controls/gz_ros2_control/issues/213>`_)
* Fix stuck passive joints (`#184 <https://github.com/ros-controls/gz_ros2_control/issues/184>`_)
  * Fix stuck passive joints
  * Update comment
  * Fix variable naming
  ---------
  Co-authored-by: Christoph Fröhlich <christophfroehlich@users.noreply.github.com>
* Support Harmonic (`#185 <https://github.com/ros-controls/gz_ros2_control/issues/185>`_)
* Contributors: Alejandro Hernández Cordero, Johannes Huemer, mergify[bot]

1.1.2 (2023-08-23)
------------------
* Catch pluginlib exceptions (`#175 <https://github.com/ros-controls/gz_ros2_control/issues/175>`_)
* Contributors: Alejandro Hernández Cordero

1.1.1 (2023-07-13)
------------------
* Remove plugin export from ROS 1 (`#158 <https://github.com/ros-controls/gz_ros2_control//issues/158>`_)
* Fixed default gazebo version in CMakeLists.txt (`#156 <https://github.com/ros-controls/gz_ros2_control//issues/156>`_)
* Compile master with iron and rolling (`#142 <https://github.com/ros-controls/gz_ros2_control//issues/142>`_)
* Update package.xml (`#141 <https://github.com/ros-controls/gz_ros2_control//issues/141>`_)
* Contributors: Alejandro Hernández Cordero, Bence Magyar, Christoph Fröhlich

1.1.0 (2023-05-23)
------------------
* Fixed segmentation fault with logger (`#136 <https://github.com/ros-controls/gz_ros2_control/issues/136>`_)
* Disable ROS signal handlers (`#129 <https://github.com/ros-controls/gz_ros2_control/issues/129>`_)
* Contributors: Alejandro Hernández Cordero, Carlo Rizzardo

1.0.0 (2023-03-28)
------------------
* Context and Namespace Handling for Multi-Robot Sim (`#128 <https://github.com/ros-controls/gz_ros2_control/issues/128>`_)
* Install include directory since it is exported (`#127 <https://github.com/ros-controls/gz_ros2_control/issues/127>`_)
* Renamed ign to gz (`#67 <https://github.com/ros-controls/gz_ros2_control/issues/67>`_)
* Contributors: Alejandro Hernández Cordero, Roni Kreinin, Tim Clephas

0.6.1 (2023-02-07)
------------------
* Various bug fixes (`#114 <https://github.com/ros-controls/gz_ros2_control/issues/114>`_)
* Contributors: AndyZe

0.6.0 (2023-01-06)
------------------
* Fix API braking of hardware plugin name. (`#108 <https://github.com/ros-controls/gz_ros2_control/issues/108>`_)
* Galactic to master -- Merge pull request `#103 <https://github.com/ros-controls/gz_ros2_control/issues/103>`_ from ros-controls/ahcorde/galactic_to_main_25_11_2022
* Force setting use_sim_time parameter when using plugin. (`#100 <https://github.com/ros-controls/gz_ros2_control/issues/100>`_) (`#102 <https://github.com/ros-controls/gz_ros2_control/issues/102>`_)
* Force setting use_sim_time parameter when using plugin. (`#100 <https://github.com/ros-controls/gz_ros2_control/issues/100>`_)
* Enable loading params from multiple yaml files (`#94 <https://github.com/ros-controls/gz_ros2_control/issues/94>`_)
* Add support for mimic joints. (`#33 <https://github.com/ros-controls/gz_ros2_control/issues/33>`_)
* Set right initial velocity (`#81 <https://github.com/ros-controls/gz_ros2_control/issues/81>`_)
* Contributors: Alejandro Hernández Cordero, Denis Štogl, Lovro Ivanov

0.5.0 (2022-08-09)
------------------
* Fix setting initial values if command interfaces are not defined. (`#73 <https://github.com/ros-controls/gz_ros2_control/issues/73>`_)
* activated all hardware by default and improved variable naming (`#74 <https://github.com/ros-controls/gz_ros2_control/issues/74>`_)
* Implemented perform_command_mode_switch override in GazeboSystem (`#76 <https://github.com/ros-controls/gz_ros2_control/issues/76>`_)
* Remove warnings (`#72 <https://github.com/ros-controls/gz_ros2_control/issues/72>`_)
* change component name for ignition (`#69 <https://github.com/ros-controls/gz_ros2_control/issues/69>`_)
* Added logic for activating hardware interfaces (`#68 <https://github.com/ros-controls/gz_ros2_control/issues/68>`_)
* Merge branch 'foxy' into ahcorde/foxy_to_galactic_27_05_2022
* Adapt to ROS 2 Humble
* typo in citadel name (`#51 <https://github.com/ros-controls/gz_ros2_control/issues/51>`_)
* ros2_control is now having usings under its namespace. (`#43 <https://github.com/ros-controls/gz_ros2_control/issues/43>`_)
* Fix default ign gazebo version Rolling (`#45 <https://github.com/ros-controls/gz_ros2_control/issues/45>`_)
* Fix ignition version in package.xml - Rolling (`#41 <https://github.com/ros-controls/gz_ros2_control/issues/41>`_)
* Add support for initial_values for hardware interfaces when starting simulation. (`#27 <https://github.com/ros-controls/gz_ros2_control/issues/27>`_)
* Contributors: Alejandro Hernández Cordero, Denis Štogl, Guillaume Beuzeboc, Tianyu Li

0.4.1 (2022-06-06)
------------------
* Remove URDF dependency (`#56 <https://github.com/ignitionrobotics/ign_ros2_control/issues/56>`_)
* typo in citadel name (`#54 <https://github.com/ignitionrobotics/ign_ros2_control/issues/54>`_)
* Contributors: Alejandro Hernández Cordero, Guillaume Beuzeboc, ahcorde

0.4.0 (2022-03-18)
------------------
* Fix default ign gazebo version Galactic (`#44 <https://github.com/ignitionrobotics/ign_ros2_control/issues/44>`_)
* Contributors: Alejandro Hernández Cordero

0.3.0 (2022-03-16)
------------------
* Fix ignition version in package.xml (`#40 <https://github.com/ignitionrobotics/ign_ros2_control/issues/40>`_)
* Contributors: Alejandro Hernández Cordero

0.2.0 (2022-02-17)
------------------
* Merge pull request `#36 <https://github.com/ignitionrobotics/ign_ros2_control/issues/36>`_ from ignitionrobotics/ahcorde/foxy_to_galactic
  Foxy -> Galactic
* Merge remote-tracking branch 'origin/foxy' into ahcorde/foxy_to_galactic
* typo fix. (`#25 <https://github.com/ignitionrobotics/ign_ros2_control/issues/25>`_)
* Contributors: Alejandro Hernández Cordero, Tomoya Fujita

0.1.2 (2022-02-14)
------------------
* Fixed position control (`#29 <https://github.com/ignitionrobotics/ign_ros2_control/issues/29>`_) (`#34 <https://github.com/ignitionrobotics/ign_ros2_control/issues/34>`_)
* typo fix. (`#25 <https://github.com/ignitionrobotics/ign_ros2_control/issues/25>`_) (`#26 <https://github.com/ignitionrobotics/ign_ros2_control/issues/26>`_)
  Co-authored-by: Tomoya Fujita <Tomoya.Fujita@sony.com>
* Contributors: Alejandro Hernández Cordero

0.1.1 (2022-01-07)
------------------
* Change package names from ignition\_ to ign\_ (`#19 <https://github.com/ignitionrobotics/ign_ros2_control/pull/22>`_)
  * Change package names from ignition\_ to ign\_
* Contributors: Alejandro Hernández Cordero

0.1.0 (2022-01-07)
------------------
* Ignition ros2 control (`#1 <https://github.com/ignitionrobotics/ign_ros2_control/issues/1>`_)
  Co-authored-by: ahcorde <ahcorde@gmail.com>
  Co-authored-by: Louise Poubel <louise@openrobotics.org>
  Co-authored-by: Vatan Aksoy Tezer <vatan@picknik.ai>
* Contributors: Alejandro Hernández Cordero, Louise Poubel, Vatan Aksoy Tezer
