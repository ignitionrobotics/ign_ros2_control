^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package ign_ros2_control_demos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

2.0.2 (2024-10-28)
------------------

2.0.1 (2024-08-26)
------------------
* Use spawner with `--params-file` argument instead of cli verbs (`#399 <https://github.com/ros-controls/gz_ros2_control/issues/399>`_)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
* Contributors: Christoph Fröhlich

2.0.0 (2024-07-09)
------------------
* fixed robot name (`#358 <https://github.com/ros-controls/gz_ros2_control/issues/358>`_)
* Contributors: huzaifa

1.3.1 (2024-07-02)
------------------
* Ackermann steering example (`#349 <https://github.com/ros-controls/gz_ros2_control/issues/349>`_)
* Rename variable in launch file (`#327 <https://github.com/ros-controls/gz_ros2_control/issues/327>`_)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
* added color definitions (`#310 <https://github.com/ros-controls/gz_ros2_control/issues/310>`_)
* Remove stamped twist parameter (`#308 <https://github.com/ros-controls/gz_ros2_control/issues/308>`_)
* Contributors: Christoph Fröhlich, Reza Kermani, huzaifa

1.3.0 (2024-05-14)
------------------
* Update pendulum-example  (`#301 <https://github.com/ros-controls/gz_ros2_control/issues/301>`_)
  * Change initial pose of pendulum
  * Make position and effort version of pendulum equal
* Use Gazebo ROS vendor packages (`#277 <https://github.com/ros-controls/gz_ros2_control/issues/277>`_)
* Add cart-pole demo (`#289 <https://github.com/ros-controls/gz_ros2_control/issues/289>`_)
* Rewrite mimic joints (`#276 <https://github.com/ros-controls/gz_ros2_control/issues/276>`_)
  Co-authored-by: Alejandro Hernández Cordero <ahcorde@gmail.com>
* Fix flake8 (`#269 <https://github.com/ros-controls/gz_ros2_control/issues/269>`_)
* Cleanup launch files and add example for .xml launch file. (`#266 <https://github.com/ros-controls/gz_ros2_control/issues/266>`_)
* Contributors: Addisu Z. Taddese, Christoph Fröhlich, Dr. Denis

1.2.2 (2024-03-21)
------------------
* Add dep (`#256 <https://github.com/ros-controls/gz_ros2_control/issues/256>`_)
* Contributors: Christoph Fröhlich

1.2.1 (2024-01-24)
------------------
* Use parameters with ros_gz_sim::Create (`#211 <https://github.com/ros-controls/gz_ros2_control/issues/211>`_)
  Co-authored-by: Christoph Fröhlich <christophfroehlich@users.noreply.github.com>
* Contributors: Alejandro Hernández Cordero

1.2.0 (2024-01-04)
------------------
* Rename cartpole with cart (`#214 <https://github.com/ros-controls/gz_ros2_control/issues/214>`_)
  Co-authored-by: Christoph Fröhlich <christophfroehlich@users.noreply.github.com>
* Replace Twist with TwistStamped (`#210 <https://github.com/ros-controls/gz_ros2_control/issues/210>`_)
* Update diff_drive_example.launch.py (`#207 <https://github.com/ros-controls/gz_ros2_control/issues/207>`_) (`#209 <https://github.com/ros-controls/gz_ros2_control/issues/209>`_)
  (cherry picked from commit e20382adc627e609e277c45e74b21f603e629675)
  Co-authored-by: Jakub Delicat <109142865+delihus@users.noreply.github.com>
* Support Harmonic (`#185 <https://github.com/ros-controls/gz_ros2_control/issues/185>`_)
* Cleanup controller config (`#180 <https://github.com/ros-controls/gz_ros2_control/issues/180>`_)
* Contributors: Alejandro Hernández Cordero, mergify[bot]

1.1.2 (2023-08-23)
------------------
* Set C++ version to 17 (`#171 <https://github.com/ros-controls/gz_ros2_control/issues/171>`_)
* Update diff_drive_controller_velocity.yaml (`#172 <https://github.com/ros-controls/gz_ros2_control/issues/172>`_)
* Contributors: Alejandro Hernández Cordero

1.1.1 (2023-07-13)
------------------
* typo fix (`#143 <https://github.com/ros-controls/gz_ros2_control//issues/143>`_)
* Contributors: Reza Kermani

1.1.0 (2023-05-23)
------------------
* Clean shutdown example position (`#135 <https://github.com/ros-controls/gz_ros2_control/issues/135>`_)
* Fixed /clock with gz_ros2_bridge (`#137 <https://github.com/ros-controls/gz_ros2_control/issues/137>`_)
* Removed tricycle publish rate (`#133 <https://github.com/ros-controls/gz_ros2_control/issues/133>`_)
* Contributors: Alejandro Hernández Cordero

1.0.0 (2023-03-28)
------------------
* Renamed ign to gz (`#67 <https://github.com/ros-controls/gz_ros2_control/issues/67>`_)
* Contributors: Alejandro Hernández Cordero

0.6.1 (2023-02-07)
------------------

0.6.0 (2023-01-06)
------------------
* Merge pull request -- Galactic to master `#103 <https://github.com/ros-controls/gz_ros2_control/issues/103>`_ from ros-controls/ahcorde/galactic_to_main_25_11_2022
* Fixed URIS (`#93 <https://github.com/ros-controls/gz_ros2_control/issues/93>`_)
* Fix Docker entrypoint and add launch CLI to dependencites (`#84 <https://github.com/ros-controls/gz_ros2_control/issues/84>`_)
* Add support for mimic joints. (`#33 <https://github.com/ros-controls/gz_ros2_control/issues/33>`_)
* Add tricycle demo (`#80 <https://github.com/ros-controls/gz_ros2_control/issues/80>`_)
* Contributors: Alejandro Hernández Cordero, Andrej Orsula, Denis Štogl, Krzysztof Wojciechowski, Tony Najjar

0.5.0 (2022-08-09)
------------------
* Fix setting initial values if command interfaces are not defined. (`#73 <https://github.com/ros-controls/gz_ros2_control/issues/73>`_)
* fix demo launch (`#75 <https://github.com/ros-controls/gz_ros2_control/issues/75>`_)
* Adjust URLs (`#65 <https://github.com/ros-controls/gz_ros2_control/issues/65>`_)
* Use Ubuntu Jammy in CI (`#47 <https://github.com/ros-controls/gz_ros2_control/issues/47>`_)
* Add support for initial_values for hardware interfaces when starting simulation. (`#27 <https://github.com/ros-controls/gz_ros2_control/issues/27>`_)
* Contributors: Alejandro Hernández Cordero, Andrej Orsula, Bence Magyar, Denis Štogl, Maciej Bednarczyk, ahcorde

0.4.1 (2022-06-06)
------------------
* ign_ros2_control_demos: Install urdf dir (`#61 <https://github.com/ignitionrobotics/ign_ros2_control/issues/61>`_)
* Remove URDF dependency (`#56 <https://github.com/ignitionrobotics/ign_ros2_control/issues/56>`_)
* Contributors: Alejandro Hernández Cordero, Andrej Orsula


0.4.0 (2022-03-18)
------------------

0.3.0 (2022-03-16)
------------------

0.2.0 (2022-02-17)
------------------
* Merge pull request `#36 <https://github.com/ignitionrobotics/ign_ros2_control/issues/36>`_ from ignitionrobotics/ahcorde/foxy_to_galactic
  Foxy -> Galactic
* Fixed galactic dependency
* Merge remote-tracking branch 'origin/foxy' into ahcorde/foxy_to_galactic
* Contributors: Alejandro Hernández Cordero

0.1.2 (2022-02-14)
------------------
* Updated docs and renamed diff drive launch file (`#32 <https://github.com/ignitionrobotics/ign_ros2_control/issues/32>`_)
  Co-authored-by: Denis Štogl <denis@stogl.de>
* Added Diff drive example (`#28 <https://github.com/ignitionrobotics/ign_ros2_control/issues/28>`_)
* Contributors: Alejandro Hernández Cordero

0.1.1 (2022-01-07)
------------------
* Change package names from ignition\_ to ign\_ (`#19 <https://github.com/ignitionrobotics/ign_ros2_control/issues/19>`_)
  * Change package names from ignition\_ to ign\_
* Added missing dependencies to package.xml (`#18 <https://github.com/ignitionrobotics/ign_ros2_control/pull/21>`_)
* Contributors: Alejandro Hernández Cordero

0.1.0 (2022-01-05)
------------------
* Ignition ros2 control (`#1 <https://github.com/ignitionrobotics/ign_ros2_control/issues/1>`_)
  Co-authored-by: ahcorde <ahcorde@gmail.com>
  Co-authored-by: Louise Poubel <louise@openrobotics.org>
  Co-authored-by: Vatan Aksoy Tezer <vatan@picknik.ai>
* Contributors: Alejandro Hernández Cordero, Louise Poubel, Vatan Aksoy Tezer
