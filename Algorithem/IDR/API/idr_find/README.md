idr_find [中文教程](https://biscuitos.github.io/blog/IDR_idr_find/)
----------------------------------

Find pointer by ID on IDR.

Context:

* Driver Files: idr.c

## Usage

Copy Driver Files into `/drivers/xxx/`, and modify Makefile on current 
directory, as follow:

```
obj-$(CONFIG_IDR_XX) += idr.o
```

Then, compile driver or dts. Details :

```
make
```

## Running

Packing image and runing on the target board.
