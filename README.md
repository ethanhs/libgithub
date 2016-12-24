#libgithub

# __NOTE__ THIS PROJECT IS NOT COMPLETE AND NOT TESTED. USE AT YOUR OWN RISK.

libgithub is a C++ library that wraps a portion of the Github API. It uses [CPR](https://github.com/whoshuu/cpr/) to make the requests to Github.
Pull requests that extend it's capabilites are welcome!

###Building:

First, install CURL:
```
$ git clone https://github.com/curl/curl.git
$ cd curl
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```
You may need to add the installed CURL to your cmake prefix (Windows).


Then install libgithub:
```
$ git clone https://github.com/ethanhs/libgithub.git
$ cd libgithub
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```

This should generate an example.exe somewhere in the build folder.
