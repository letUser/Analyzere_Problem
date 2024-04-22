# syntax=docker/dockerfile:1

FROM ubuntu:latest
COPY ./compute.cpp compute.cpp
RUN apt-get update && apt-get install -y g++
RUN g++ -o /usr/local/bin/compute compute.cpp