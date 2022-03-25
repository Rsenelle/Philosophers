cmake_minimum_required(VERSION 3.20)
project(philo C)

set(CMAKE_C_STANDARD 99)

add_executable(philo main.c philo_without_time_of_eating.c philo.h utils.c init_struct.c)
