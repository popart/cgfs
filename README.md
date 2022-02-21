# Basic C stuff

This shows you where the external library files are:
```
sudo apt-get install libcairo2-dev
dpkg -L libcairo2-dev
```

gcc options:
```
-I<search path to include files>
-L<search path to the lib file>
-l<libname>
```

compile:
`gcc -Wall -g main.c -I/usr/include/cairo -L/usr/lib/ -lcairo -o out`
Notice that `/usr/lib/` ends with a slash.
`-Wall -g` adds debugging info.


