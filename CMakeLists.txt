cmake_minimum_required(VERSION 3.24)
project(SocialNetworkPolarization)

set(CMAKE_CXX_STANDARD 17)

add_executable(SocialNetworkPolarization main.cpp BeliefObjects/Interval.h BeliefObjects/Interval.cpp Model.h Model.cpp BeliefObjects/FirstOrderDiscreteBelief.h BeliefObjects/FirstOrderDiscreteBelief.cpp BeliefObjects/Belief.h BeliefObjects/Belief.cpp)
