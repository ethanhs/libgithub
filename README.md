#libgithub

libgithub is a C++ library that wraps a portion of the Github API. It uses [CPR](https://github.com/whoshuu/cpr/) to make the requests to Github.
This is developed for the GitSip project, but welcomes contributions that expand its capabilities.

###Building:

First, install CURL:
```
$ git clone https://github.com/curl/curl.git
$ cd curl
$ mkdir build && cd build
$ cmake ..
```
Build the generated SLN
Add the installed CURL to your cmake prefix


Then install libgithub:
```
$ git clone https://github.com/ethanhs/libgithub.git
$ cd libgithub
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```

This should generate an example.exe somewhere in the build folder.
