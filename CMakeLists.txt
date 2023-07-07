cmake_minimum_required(VERSION 3.23)
project(Graphs)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphs main.cpp BinaryTree/BinaryTree.cpp BinaryTree/BinaryTree.h LinkedList/LinkedList.cpp LinkedList/LinkedList.h TwoBidirectionalLinkecList/TwoBidirectionalLinkedList.cpp TwoBidirectionalLinkecList/TwoBidirectionalLinkedList.h)
