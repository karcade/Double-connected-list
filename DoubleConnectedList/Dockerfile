# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM gcc:latest

RUN mkdir -p /usr/scr/app/
WORKDIR /usr/scr/app/
COPY . /usr/scr/app/

# These commands copy your files into the specified directory in the image
# and set that as the working location

# This command compiles your app using GCC, adjust for your source code
RUN g++ -c List.cpp
RUN g++ -c main.cpp
RUN g++ -o test List.o main.o

# This command runs your application, comment out this line to compile only
ENTRYPOINT ["./test"]

LABEL Name=dockertest Version=0.0.1
