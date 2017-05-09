
# What version  of CMake  i s  needed?

cmake_minimum_required(VERSION 2.8.3)


# Name of  t h i s  package .

project (publisher)


# Find  the  catkin  build  system ,  and any  other  packages  on

# which we depend .

find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs)

 #add_message_files(DIRECTORY msg FILES Num.msg)
 #add_service_files(DIRECTORY srv FILES AddTwoInts.srv)
 #generate_messages(DEPENDENCIES std_msgs)
# Declare  our  catkin  package .

catkin_package ()


# Specify  l o c a t i o n s  of  header  f i l e s .

include_directories(include ${catkin_INCLUDE_DIRS})


# Declare  the  executable ,  along  with  i t s  source  f i l e s .   I f

# there  are  multiple  executables ,  use  multiple  copies  of

# t h i s  l i n e .

add_executable (pubvel pubvel.cpp )


# Specify  l i b r a r i e s  against  which  to  l i n k .   Again ,  t h i s

# l i n e  should  be  copied  f o r  each  d i s t i n c t  executable  in

# the  package .

target_link_libraries(pubvel ${catkin_LIBRARIES})

add_executable (subpos subpos.cpp )

target_link_libraries(subpos ${catkin_LIBRARIES})
